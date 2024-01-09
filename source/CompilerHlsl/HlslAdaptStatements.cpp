/*
See LICENSE file in root folder
*/
#include "HlslAdaptStatements.hpp"

#include "HlslCombinedImageAccessFunctions.hpp"
#include "HlslExprAdapter.hpp"
#include "HlslHelpers.hpp"
#include "HlslIntrinsicFunctions.hpp"

#include <ShaderAST/Shader.hpp>
#include <ShaderAST/Type/TypeCombinedImage.hpp>
#include <ShaderAST/Type/TypeImage.hpp>
#include <ShaderAST/Visitors/CloneStmt.hpp>

#include <unordered_set>

namespace hlsl
{
	namespace adapt
	{
		class StmtAdapter
			: public ast::StmtCloner
		{
		public:
			static ast::stmt::ContainerPtr submit( ast::stmt::StmtCache & stmtCache
				, ast::expr::ExprCache & exprCache
				, HlslShader & shader
				, ast::stmt::Container const & container
				, IntrinsicsConfig const & intrinsicsConfig
				, HlslConfig const & writerConfig
				, AdaptationData & adaptationData )
			{
				auto result = stmtCache.makeContainer();
				StmtAdapter vis{ stmtCache, exprCache, shader, intrinsicsConfig, writerConfig, adaptationData, result };
				container.accept( &vis );
				return result;
			}

		private:
			StmtAdapter( ast::stmt::StmtCache & stmtCache
				, ast::expr::ExprCache & exprCache
				, HlslShader & shader
				, IntrinsicsConfig const & intrinsicsConfig
				, HlslConfig const & writerConfig
				, AdaptationData & adaptationData
				, ast::stmt::ContainerPtr & result )
				: StmtCloner{ stmtCache, exprCache, result }
				, m_intrinsicsConfig{ intrinsicsConfig }
				, m_writerConfig{ writerConfig }
				, m_adaptationData{ adaptationData }
				, m_shader{ shader }
				, m_typesCache{ shader.getTypesCache() }
			{
				m_declaredStructs.emplace( "RayDesc" );
				auto cont = m_stmtCache.makeContainer();
				compileHlslIntrinsicFunctions( cont.get(), m_intrinsicsConfig );
				compileHlslTextureAccessFunctions( cont.get(), m_intrinsicsConfig );
				m_intrinsics = cont.get();
				m_current->addStmt( std::move( cont ) );

				cont = m_stmtCache.makeContainer();
				m_inOutDeclarations = cont.get();
				m_current->addStmt( std::move( cont ) );
			}

			using ast::StmtCloner::doSubmit;

			ast::expr::ExprPtr doSubmit( ast::expr::Expr const & expr )override
			{
				return ExprAdapter::submit( m_stmtCache
					, m_exprCache
					, m_typesCache
					, expr
					, m_current
					, m_intrinsicsConfig
					, m_writerConfig
					, m_adaptationData
					, m_intrinsics
					, false );
			}

			void linkVars( ast::var::VariablePtr textureSampler
				, ast::var::VariablePtr texture
				, ast::var::VariablePtr sampler )
			{
				m_adaptationData.linkedVars.try_emplace( std::move( textureSampler )
					, std::move( texture ), std::move( sampler ) );
			}

			void visitBufferReferenceDeclStmt( ast::stmt::BufferReferenceDecl const * stmt )override
			{
				declareType( stmt->getType() );
			}

			void visitFunctionDeclStmt( ast::stmt::FunctionDecl const * stmt )override
			{
				auto funcType = stmt->getType();
				declareType( funcType->getReturnType() );

				for ( auto param : *funcType )
				{
					declareType( param->getType() );
				}

				if ( stmt->getFlags() )
				{
					if ( isRayTraceStage( m_shader.getType() ) )
					{
						auto save = m_current;
						ast::var::VariableList params;
						// Skip first parameter, since it only contains the builtins.
						auto it = std::next( funcType->begin() );

						// Push the other parameters like any other function.
						while ( it != funcType->end() )
						{
							if ( auto type = ( *it )->getType();
								type->getRawKind() == ast::type::Kind::eHitAttribute && !isStructType( type ) )
							{
								auto & hitAttrType = static_cast< ast::type::HitAttribute const & >( *type );
								// HLSL HitAttribute must be a structure
								auto structType = m_rtCache.getStruct( ast::type::MemoryLayout::eC
									, std::string{ "SDW_HLSL_InHitAttribute" } );

								if ( !structType->hasMember( "d" ) )
								{
									structType->declMember( "d", hitAttrType.getDataType() );
									m_inOutDeclarations->addStmt( m_stmtCache.makeStructureDecl( structType ) );
								}

								auto newType = m_rtCache.getHitAttribute( structType );
								m_adaptationData.setHlslType( type, newType );
								auto var = ast::var::makeVariable( m_adaptationData.getNextVarId()
									, newType
									, ( *it )->getName()
									, ast::var::Flag::eShaderInput | ast::var::Flag::eInputParam | ( *it )->getFlags() );
								params.push_back( var );
								m_adaptationData.replacedVars.try_emplace( *it
									, m_exprCache.makeMbrSelect( m_exprCache.makeIdentifier( m_typesCache, var )
										, 0u
										, var->getFlags() ) );
							}
							else
							{
								params.push_back( *it );
							}

							++it;
						}

						auto funcVar = stmt->getFuncVar();
						auto cont = m_stmtCache.makeFunctionDecl( ast::var::makeVariable( stmt->getFuncVar()->getId()
								, m_typesCache.getFunction( stmt->getType()->getReturnType(), params )
								, stmt->getName()
								, stmt->getFuncVar()->getFlags() )
							, stmt->getFlags() );
						m_current = cont.get();
						visitContainerStmt( stmt );
						m_current = save;
						m_current->addStmt( std::move( cont ) );
					}
					else
					{
						// Skip first parameter, since it only contains the builtins.
						auto it = std::next( funcType->begin() );

						while ( it != funcType->end() )
						{
							if ( auto type = ( *it )->getType();
								type->getRawKind() == ast::type::Kind::eTaskPayload || type->getRawKind() == ast::type::Kind::eTaskPayloadNV )
							{
								// HLSL Amplification payload must be declared as a global.
								declareType( type );
								m_inOutDeclarations->addStmt( m_stmtCache.makeVariableDecl( *it ) );
							}

							++it;
						}

						m_adaptationData.updateCurrentEntryPoint( stmt );

						auto & typesCache = stmt->getType()->getTypesCache();
						// Write function content into a temporary container, registering I/O.
						auto cont = m_stmtCache.makeContainer();
						auto save = m_current;
						m_current = cont.get();
						visitContainerStmt( stmt );
						m_current = save;
						// Write main function, with only used parameters.
						m_inOutDeclarations->addStmt( m_adaptationData.writeGlobals( m_stmtCache, m_declaredStructs ) );
						ast::var::VariableList parameters;
						auto retType = m_adaptationData.fillParameters( parameters, *m_current );
						auto funcVar = stmt->getFuncVar();
						auto mainCont = m_stmtCache.makeFunctionDecl( ast::var::makeVariable( stmt->getFuncVar()->getId()
								, typesCache.getFunction( ( retType ? retType : stmt->getType()->getReturnType() ), parameters )
								, stmt->getName()
								, stmt->getFuncVar()->getFlags() )
							, stmt->getFlags() );
						mainCont->addStmt( m_adaptationData.writeLocalesBegin( m_stmtCache ) );
						mainCont->addStmt( std::move( cont ) );
						mainCont->addStmt( m_adaptationData.writeLocalesEnd( m_stmtCache ) );
						m_current->addStmt( std::move( mainCont ) );
						m_adaptationData.updateCurrentEntryPoint( nullptr );
					}
				}
				else
				{
					auto save = m_current;
					auto cont = rewriteFuncHeader( *stmt );
					m_current = cont.get();
					visitContainerStmt( stmt );
					m_current = save;
					m_current->addStmt( std::move( cont ) );
				}
			}

			void visitHitAttributeVariableDeclStmt( ast::stmt::HitAttributeVariableDecl const * stmt )override
			{
				auto var = stmt->getVariable();
				declareType( var->getType() );
				auto type = var->getType();
				assert( type->getRawKind() == ast::type::Kind::eHitAttribute );

				if ( !isStructType( type ) )
				{
					auto & hitAttrType = static_cast< ast::type::HitAttribute const & >( *type );
					// HLSL HitAttribute must be a structure
					auto structType = m_rtCache.getStruct( ast::type::MemoryLayout::eC
						, std::string{ "SDW_HLSL_HitAttribute" } );

					if ( !structType->hasMember( "d" ) )
					{
						structType->declMember( "d", hitAttrType.getDataType() );
						m_inOutDeclarations->addStmt( m_stmtCache.makeStructureDecl( structType ) );
					}

					auto newType = m_rtCache.getHitAttribute( structType );
					m_adaptationData.setHlslType( type, newType );
					auto replVar = ast::var::makeVariable( m_adaptationData.getNextVarId()
						, newType
						, var->getName()
						, var->getFlags() );
					m_adaptationData.replacedVars.try_emplace( var
						, m_exprCache.makeMbrSelect( m_exprCache.makeIdentifier( m_typesCache, replVar )
							, 0u
							, replVar->getFlags() ) );
					var = replVar;
				}

				if ( m_writerConfig.shaderStage == ast::ShaderStage::eRayIntersection )
				{
					m_current->addStmt( m_stmtCache.makeHitAttributeVariableDecl( var ) );
				}
			}

			void visitInOutCallableDataVariableDeclStmt( ast::stmt::InOutCallableDataVariableDecl const * stmt )override
			{
				auto var = stmt->getVariable();
				declareType( var->getType() );
				auto type = var->getType();
				assert( type->getRawKind() == ast::type::Kind::eCallableData );

				if ( !isStructType( type ) )
				{
					auto & callDataType = static_cast< ast::type::CallableData const & >( *type );
					// HLSL CallableData must be a structure
					auto structType = m_rtCache.getStruct( ast::type::MemoryLayout::eC
						, var->isCallableData() ? std::string{ "SDW_HLSL_CallableData" } : std::string{ "SDW_HLSL_CallableDataIn" } );

					if ( !structType->hasMember( "d" ) )
					{
						structType->declMember( "d", callDataType.getDataType() );
						m_inOutDeclarations->addStmt( m_stmtCache.makeStructureDecl( structType ) );
					}

					auto newType = m_rtCache.getCallableData( structType
						, callDataType.getLocation() );
					m_adaptationData.setHlslType( type, newType );
					auto replVar = ast::var::makeVariable( m_adaptationData.getNextVarId()
						, newType
						, var->getName()
						, var->getFlags() );
					m_adaptationData.replacedVars.try_emplace( var
						, m_exprCache.makeMbrSelect( m_exprCache.makeIdentifier( m_typesCache, replVar )
							, 0u
							, replVar->getFlags() ) );
					var = replVar;
				}

				if ( stmt->getVariable()->isCallableData() )
				{
					m_current->addStmt( m_stmtCache.makeInOutCallableDataVariableDecl( var
						, stmt->getLocation() ) );
				}
			}

			void visitInOutRayPayloadVariableDeclStmt( ast::stmt::InOutRayPayloadVariableDecl const * stmt )override
			{
				auto var = stmt->getVariable();
				declareType( var->getType() );
				auto type = var->getType();
				assert( type->getRawKind() == ast::type::Kind::eRayPayload );

				if ( !isStructType( type ) )
				{
					auto & rayPayloadType = static_cast< ast::type::RayPayload const & >( *type );
					// HLSL RayPayload must be a structure
					auto structType = m_rtCache.getStruct( ast::type::MemoryLayout::eC
						, var->isRayPayload() ? std::string{ "SDW_HLSL_RayPayload" } : std::string{ "SDW_HLSL_RayPayloadIn" } );

					if ( !structType->hasMember( "d" ) )
					{
						structType->declMember( "d", rayPayloadType.getDataType() );
						m_inOutDeclarations->addStmt( m_stmtCache.makeStructureDecl( structType ) );
					}

					auto newType = m_rtCache.getRayPayload( structType
						, rayPayloadType.getLocation() );
					m_adaptationData.setHlslType( type, newType );
					auto replVar = ast::var::makeVariable( m_adaptationData.getNextVarId()
						, newType
						, var->getName()
						, var->getFlags() );
					m_adaptationData.replacedVars.try_emplace( var
						, m_exprCache.makeMbrSelect( m_exprCache.makeIdentifier( m_typesCache, replVar )
							, 0u
							, replVar->getFlags() ) );
					var = replVar;
				}

				if ( var->isRayPayload() )
				{
					m_current->addStmt( m_stmtCache.makeInOutRayPayloadVariableDecl( var
						, stmt->getLocation() ) );
				}
			}

			void visitInOutVariableDeclStmt( ast::stmt::InOutVariableDecl const * stmt )override
			{
				declareType( stmt->getVariable()->getType() );
			}

			void visitInputComputeLayoutStmt( ast::stmt::InputComputeLayout const * stmt )override
			{
				declareType( stmt->getType() );
			}

			void visitInputGeometryLayoutStmt( ast::stmt::InputGeometryLayout const * stmt )override
			{
				declareType( stmt->getType() );
			}

			void visitPerPrimitiveDeclStmt( ast::stmt::PerPrimitiveDecl const * stmt )override
			{
				declareType( stmt->getType() );
			}

			void visitPerVertexDeclStmt( ast::stmt::PerVertexDecl const * stmt )override
			{
				declareType( stmt->getType() );
			}

			void visitOutputGeometryLayoutStmt( ast::stmt::OutputGeometryLayout const * stmt )override
			{
				declareType( stmt->getType() );
			}

			void visitOutputMeshLayoutStmt( ast::stmt::OutputMeshLayout const * stmt )override
			{
				declareType( stmt->getType() );
			}

			void visitCombinedImageDeclStmt( ast::stmt::CombinedImageDecl const * stmt )override
			{
				auto originalVar = stmt->getVariable();
				ast::type::TypePtr sampledType;
				ast::type::TypePtr samplerType;
				ast::type::TypePtr imageType;
				ast::type::ImageConfiguration config;

				if ( originalVar->getType()->getKind() == ast::type::Kind::eArray )
				{
					auto arrayType = std::static_pointer_cast< ast::type::Array >( originalVar->getType() );
					auto realSampledType = std::static_pointer_cast< ast::type::CombinedImage >( arrayType->getType() );
					imageType = m_typesCache.getArray( realSampledType->getImageType(), arrayType->getArraySize() );
					config = realSampledType->getConfig();

					if ( !m_intrinsicsConfig.requiresShadowSampler )
					{
						samplerType = m_typesCache.getArray( m_typesCache.getSampler( false ), arrayType->getArraySize() );
					}
					else
					{
						samplerType = m_typesCache.getArray( realSampledType->getSamplerType(), arrayType->getArraySize() );
					}
				}
				else
				{
					auto realSampledType = std::static_pointer_cast< ast::type::CombinedImage >( originalVar->getType() );
					imageType = realSampledType->getImageType();
					config = realSampledType->getConfig();

					if ( !m_intrinsicsConfig.requiresShadowSampler )
					{
						samplerType = m_typesCache.getSampler( false );
					}
					else
					{
						samplerType = realSampledType->getSamplerType();
					}
				}

				if ( config.dimension == ast::type::ImageDim::eBuffer )
				{
					// Create Image
					auto textureVar = m_shader.registerImage( originalVar->getName()
						, imageType
						, stmt->getBindingPoint()
						, stmt->getDescriptorSet() );
					textureVar->updateFlag( ast::var::Flag::eImplicit );
					m_current->addStmt( m_stmtCache.makeImageDecl( textureVar
						, stmt->getBindingPoint()
						, stmt->getDescriptorSet() ) );
				}
				else
				{
					// Create Image
					auto textureVar = m_shader.registerImage( originalVar->getName() + "_texture"
						, imageType
						, stmt->getBindingPoint()
						, stmt->getDescriptorSet() );
					textureVar->updateFlag( ast::var::Flag::eImplicit );
					m_current->addStmt( m_stmtCache.makeImageDecl( textureVar
						, stmt->getBindingPoint()
						, stmt->getDescriptorSet() ) );

					// Create Sampler
					auto samplerVar = m_shader.registerSampler( originalVar->getName() + "_sampler"
						, samplerType
						, stmt->getBindingPoint()
						, stmt->getDescriptorSet() );
					samplerVar->updateFlag( ast::var::Flag::eImplicit );
					m_current->addStmt( m_stmtCache.makeSamplerDecl( samplerVar
						, stmt->getBindingPoint()
						, stmt->getDescriptorSet() ) );

					// Link them
					linkVars( originalVar, textureVar, samplerVar );
				}
			}

			void visitShaderBufferDeclStmt( ast::stmt::ShaderBufferDecl const * stmt )override
			{
				auto ssboVar = stmt->getVariable();
				declareType( ssboVar->getType() );
				m_adaptationData.ssboList.push_back( ssboVar );
				m_current->addStmt( m_stmtCache.makeShaderStructBufferDecl( stmt->getSsboName()
					, ast::var::makeVariable( m_adaptationData.getNextVarId()
						, ssboVar->getType()
						, ssboVar->getName() + "Inst" )
					, ssboVar
					, stmt->getBindingPoint()
					, stmt->getDescriptorSet() ) );
				uint32_t mbrIndex = 0u;

				for ( auto & curStmt : *stmt )
				{
					assert( curStmt->getKind() == ast::stmt::Kind::eVariableDecl );
					auto var = static_cast< ast::stmt::VariableDecl const & >( *curStmt ).getVariable();
					m_adaptationData.replacedVars.try_emplace( var
						, m_exprCache.makeMbrSelect( m_exprCache.makeArrayAccess( ssboVar->getType()
							, m_exprCache.makeIdentifier( m_typesCache
								, ast::var::makeVariable( m_adaptationData.getNextVarId()
									, m_typesCache.getArray( ssboVar->getType(), 1u )
									, ssboVar->getName() ) )
							, m_exprCache.makeLiteral( m_typesCache, 0 ) )
							, mbrIndex
							, uint64_t( ast::var::Flag::eUniform ) ) );
					++mbrIndex;
				}
			}

			void visitShaderStructBufferDeclStmt( ast::stmt::ShaderStructBufferDecl const * stmt )override
			{
				declareType( stmt->getData()->getType() );
				m_adaptationData.ssboList.push_back( stmt->getSsboInstance() );
				m_current->addStmt( m_stmtCache.makeShaderStructBufferDecl( stmt->getSsboName()
					, stmt->getSsboInstance()
					, stmt->getData()
					, stmt->getBindingPoint()
					, stmt->getDescriptorSet() ) );
			}

			void visitStructureDeclStmt( ast::stmt::StructureDecl const * stmt )override
			{
				declareType( stmt->getType() );
			}

			void visitVariableDeclStmt( ast::stmt::VariableDecl const * stmt )override
			{
				auto var = stmt->getVariable();
				declareType( var->getType() );
				m_current->addStmt( m_stmtCache.makeVariableDecl( var ) );
			}

			void visitPreprocExtension( ast::stmt::PreprocExtension const * preproc )override
			{
			}

			void visitPreprocVersion( ast::stmt::PreprocVersion const * preproc )override
			{
			}

			ast::stmt::FunctionDeclPtr rewriteFuncHeader( ast::stmt::FunctionDecl const & stmt )
			{
				ast::var::VariableList params;
				// Split sampled textures in sampler + texture in parameters list.
				for ( auto & param : *stmt.getType() )
				{
					auto it = updateLinkedVars( param
						, m_adaptationData.linkedVars
						, m_adaptationData.nextVarId );

					if ( it != m_adaptationData.linkedVars.end() )
					{
						params.push_back( it->second.first );
						params.push_back( it->second.second );
					}
					else
					{
						params.push_back( param );
					}
				}

				auto funcVar = stmt.getFuncVar();

				if ( params.size() != stmt.getType()->size() )
				{
					funcVar = ast::var::makeVariable( stmt.getFuncVar()->getId()
						, m_typesCache.getFunction( stmt.getType()->getReturnType(), params )
						, stmt.getName()
						, stmt.getFuncVar()->getFlags() );
					m_adaptationData.replacedFuncVars.try_emplace( funcVar->getId(), funcVar );
				}

				return m_stmtCache.makeFunctionDecl( std::move( funcVar ), stmt.getFlags() );
			}

			void declareType( ast::type::TypePtr type )
			{
				if ( auto structType = getStructType( getNonArrayType( type ) ) )
				{
					if ( m_declaredStructs.insert( structType->getName() ).second )
					{
						for ( auto & member : *structType )
						{
							declareType( member.type );
						}

						m_inOutDeclarations->addStmt( m_stmtCache.makeStructureDecl( structType ) );
					}
				}
			}

		private:
			IntrinsicsConfig const & m_intrinsicsConfig;
			HlslConfig const & m_writerConfig;
			AdaptationData & m_adaptationData;
			HlslShader & m_shader;
			ast::type::TypesCache & m_typesCache;
			ast::type::TypesCache m_rtCache;
			ast::stmt::Container * m_intrinsics;
			ast::stmt::Container * m_inOutDeclarations;
			ast::UnorderedStringSet m_declaredStructs;
		};
	}

	ast::stmt::ContainerPtr adaptStatements( ast::stmt::StmtCache & stmtCache
		, ast::expr::ExprCache & exprCache
		, HlslShader & shader
		, ast::stmt::Container const & container
		, IntrinsicsConfig const & intrinsicsConfig
		, HlslConfig const & writerConfig
		, AdaptationData & adaptationData )
	{
		return adapt::StmtAdapter::submit( stmtCache
			, exprCache
			, shader
			, container
			, intrinsicsConfig
			, writerConfig
			, adaptationData );
	}
}
