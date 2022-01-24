/*
See LICENSE file in root folder
*/
#include "HlslStmtAdapter.hpp"

#include "HlslExprAdapter.hpp"
#include "HlslHelpers.hpp"
#include "HlslImageAccessFunctions.hpp"
#include "HlslIntrinsicFunctions.hpp"
#include "HlslTextureAccessFunctions.hpp"

#include <ShaderAST/Shader.hpp>

#include <ShaderAST/Type/TypeSampledImage.hpp>
#include <ShaderAST/Type/TypeImage.hpp>

namespace hlsl
{
	ast::stmt::ContainerPtr StmtAdapter::submit( HlslShader & shader
		, ast::stmt::Container * container
		, IntrinsicsConfig const & intrinsicsConfig
		, HlslConfig const & writerConfig
		, AdaptationData & adaptationData )
	{
		auto result = ast::stmt::makeContainer();
		StmtAdapter vis{ shader, intrinsicsConfig, writerConfig, adaptationData, result };
		container->accept( &vis );
		return result;
	}

	StmtAdapter::StmtAdapter( HlslShader & shader
		, IntrinsicsConfig const & intrinsicsConfig
		, HlslConfig const & writerConfig
		, AdaptationData & adaptationData
		, ast::stmt::ContainerPtr & result )
		: StmtCloner{ result }
		, m_intrinsicsConfig{ intrinsicsConfig }
		, m_writerConfig{ writerConfig }
		, m_adaptationData{ adaptationData }
		, m_shader{ shader }
		, m_cache{ shader.getTypesCache() }
	{
		m_declaredStructs.insert( "RayDesc" );
		auto cont = ast::stmt::makeContainer();
		compileHlslIntrinsicFunctions( cont.get(), m_intrinsicsConfig );
		compileHlslTextureAccessFunctions( cont.get(), m_intrinsicsConfig );
		compileHlslImageAccessFunctions( cont.get(), m_intrinsicsConfig );
		m_intrinsics = cont.get();
		m_current->addStmt( std::move( cont ) );

		cont = ast::stmt::makeContainer();
		m_inOutDeclarations = cont.get();
		m_current->addStmt( std::move( cont ) );
	}

	ast::expr::ExprPtr StmtAdapter::doSubmit( ast::expr::Expr * expr )
	{
		return ExprAdapter::submit( m_cache
			, expr
			, m_current
			, m_intrinsicsConfig
			, m_writerConfig
			, m_adaptationData
			, m_intrinsics
			, false );
	}

	void StmtAdapter::linkVars( ast::var::VariablePtr textureSampler
		, ast::var::VariablePtr texture
		, ast::var::VariablePtr sampler )
	{
		m_adaptationData.linkedVars.emplace( std::move( textureSampler )
			, std::make_pair( std::move( texture )
				, std::move( sampler ) ) );
	}

	void StmtAdapter::visitBufferReferenceDeclStmt( ast::stmt::BufferReferenceDecl * stmt )
	{
		declareType( stmt->getType() );
	}

	void StmtAdapter::visitFunctionDeclStmt( ast::stmt::FunctionDecl * stmt )
	{
		if ( stmt->getFlags() )
		{
			if ( isRayTraceStage( m_shader.getType() ) )
			{
				auto funcType = stmt->getType();
				auto save = m_current;
				ast::var::VariableList params;
				// Skip first parameter, since it only contains the builtins.
				auto it = std::next( funcType->begin() );

				// Push the other parameters like any other function.
				while ( it != funcType->end() )
				{
					params.push_back( *it );
					++it;
				}

				auto cont = ast::stmt::makeFunctionDecl( m_cache.getFunction( stmt->getType()->getReturnType(), params )
					, stmt->getName()
					, stmt->getFlags() );
				m_current = cont.get();
				visitContainerStmt( stmt );
				m_current = save;
				m_current->addStmt( std::move( cont ) );
			}
			else
			{
				m_adaptationData.updateCurrentEntryPoint( stmt );

				auto & cache = stmt->getType()->getCache();
				// Write function content into a temporary container, registering I/O.
				auto cont = ast::stmt::makeContainer();
				auto save = m_current;
				m_current = cont.get();
				visitContainerStmt( stmt );
				m_current = save;
				// Write main function, with only used parameters.
				m_inOutDeclarations->addStmt( m_adaptationData.writeGlobals( m_declaredStructs ) );
				ast::var::VariableList parameters;
				auto retType = m_adaptationData.fillParameters( parameters, *m_current );
				auto mainCont = ast::stmt::makeFunctionDecl( cache.getFunction( ( retType ? retType : stmt->getType()->getReturnType() )
					, parameters )
					, stmt->getName()
					, stmt->getFlags() );
				mainCont->addStmt( m_adaptationData.writeLocalesBegin() );
				mainCont->addStmt( std::move( cont ) );
				mainCont->addStmt( m_adaptationData.writeLocalesEnd() );
				m_current->addStmt( std::move( mainCont ) );
				m_adaptationData.updateCurrentEntryPoint( nullptr );
			}
		}
		else
		{
			auto save = m_current;
			auto cont = rewriteFuncHeader( stmt );
			m_current = cont.get();
			visitContainerStmt( stmt );
			m_current = save;
			m_current->addStmt( std::move( cont ) );
		}
	}

	void StmtAdapter::visitHitAttributeVariableDeclStmt( ast::stmt::HitAttributeVariableDecl * stmt )
	{
		auto var = stmt->getVariable();
		declareType( var->getType() );
		auto type = var->getType();
		assert( type->getRawKind() == ast::type::Kind::eHitAttribute );

		if ( !isStructType( type ) )
		{
			auto & hitAttrType = static_cast< ast::type::HitAttribute const & >( *type );
			// HLSL HitAttribute must be a structure
			auto structType = m_cache.getStruct( ast::type::MemoryLayout::eC
				, std::string{ "SDW_HLSL_HitAttribute" } );
			structType->declMember( "d", hitAttrType.getDataType() );
			m_inOutDeclarations->addStmt( ast::stmt::makeStructureDecl( structType ) );
			auto newType = m_cache.getHitAttribute( structType );
			m_adaptationData.setHlslType( type, newType );
			var->updateType( newType );
		}

		if ( m_writerConfig.shaderStage == ast::ShaderStage::eRayIntersection )
		{
			StmtCloner::visitHitAttributeVariableDeclStmt( stmt );
		}
	}

	void StmtAdapter::visitInOutCallableDataVariableDeclStmt( ast::stmt::InOutCallableDataVariableDecl * stmt )
	{
		auto var = stmt->getVariable();
		declareType( var->getType() );
		auto type = var->getType();
		assert( type->getRawKind() == ast::type::Kind::eCallableData );

		if ( !isStructType( type ) )
		{
			auto & callDataType = static_cast< ast::type::CallableData const & >( *type );
			// HLSL CallableData must be a structure
			auto structType = m_cache.getStruct( ast::type::MemoryLayout::eC
				, var->isCallableData() ? std::string{ "SDW_HLSL_CallableData" } : std::string{ "SDW_HLSL_CallableDataIn" } );
			structType->declMember( "d", callDataType.getDataType() );
			m_inOutDeclarations->addStmt( ast::stmt::makeStructureDecl( structType ) );
			auto newType = m_cache.getCallableData( structType
				, callDataType.getLocation() );
			m_adaptationData.setHlslType( type, newType );
			var->updateType( newType );
		}

		if ( stmt->getVariable()->isCallableData() )
		{
			StmtCloner::visitInOutCallableDataVariableDeclStmt( stmt );
		}
	}

	void StmtAdapter::visitInOutRayPayloadVariableDeclStmt( ast::stmt::InOutRayPayloadVariableDecl * stmt )
	{
		auto var = stmt->getVariable();
		declareType( var->getType() );
		auto type = var->getType();
		assert( type->getRawKind() == ast::type::Kind::eRayPayload );

		if ( !isStructType( type ) )
		{
			auto & rayPayloadType = static_cast< ast::type::RayPayload const & >( *type );
			// HLSL RayPayload must be a structure
			auto structType = m_cache.getStruct( ast::type::MemoryLayout::eC
				, var->isRayPayload() ? std::string{ "SDW_HLSL_RayPayload" } : std::string{ "SDW_HLSL_RayPayloadIn" } );
			structType->declMember( "d", rayPayloadType.getDataType() );
			m_inOutDeclarations->addStmt( ast::stmt::makeStructureDecl( structType ) );
			auto newType = m_cache.getRayPayload( structType
				, rayPayloadType.getLocation() );
			m_adaptationData.setHlslType( type, newType );
			var->updateType( newType );
		}

		if ( var->isRayPayload() )
		{
			StmtCloner::visitInOutRayPayloadVariableDeclStmt( stmt );
		}
	}

	void StmtAdapter::visitInOutVariableDeclStmt( ast::stmt::InOutVariableDecl * stmt )
	{
		declareType( stmt->getVariable()->getType() );
	}

	void StmtAdapter::visitInputComputeLayoutStmt( ast::stmt::InputComputeLayout * stmt )
	{
		declareType( stmt->getType() );
	}

	void StmtAdapter::visitInputGeometryLayoutStmt( ast::stmt::InputGeometryLayout * stmt )
	{
		declareType( stmt->getType() );
	}

	void StmtAdapter::visitPerPrimitiveDeclStmt( ast::stmt::PerPrimitiveDecl * stmt )
	{
		declareType( stmt->getType() );
	}

	void StmtAdapter::visitPerVertexDeclStmt( ast::stmt::PerVertexDecl * stmt )
	{
		declareType( stmt->getType() );
	}

	void StmtAdapter::visitOutputGeometryLayoutStmt( ast::stmt::OutputGeometryLayout * stmt )
	{
		declareType( stmt->getType() );
	}

	void StmtAdapter::visitOutputMeshLayoutStmt( ast::stmt::OutputMeshLayout * stmt )
	{
		declareType( stmt->getType() );
	}

	void StmtAdapter::visitSampledImageDeclStmt( ast::stmt::SampledImageDecl * stmt )
	{
		auto originalVar = stmt->getVariable();
		ast::type::TypePtr sampledType;
		ast::type::TypePtr samplerType;
		ast::type::TypePtr imageType;
		ast::type::ImageConfiguration config;

		if ( originalVar->getType()->getKind() == ast::type::Kind::eArray )
		{
			auto arrayType = std::static_pointer_cast< ast::type::Array >( originalVar->getType() );
			auto realSampledType = std::static_pointer_cast< ast::type::SampledImage >( arrayType->getType() );
			imageType = m_cache.getArray( realSampledType->getImageType(), arrayType->getArraySize() );
			sampledType = m_cache.getArray( realSampledType, arrayType->getArraySize() );
			config = realSampledType->getConfig();

			if ( !m_intrinsicsConfig.requiresShadowSampler )
			{
				samplerType = m_cache.getArray( m_cache.getSampler( false ), arrayType->getArraySize() );
			}
			else
			{
				samplerType = m_cache.getArray( realSampledType->getSamplerType(), arrayType->getArraySize() );
			}
		}
		else
		{
			auto realSampledType = std::static_pointer_cast< ast::type::SampledImage >( originalVar->getType() );
			imageType = realSampledType->getImageType();
			sampledType = realSampledType;
			config = realSampledType->getConfig();

			if ( !m_intrinsicsConfig.requiresShadowSampler )
			{
				samplerType = m_cache.getSampler( false );
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
			m_current->addStmt( ast::stmt::makeImageDecl( textureVar
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
			m_current->addStmt( ast::stmt::makeImageDecl( textureVar
				, stmt->getBindingPoint()
				, stmt->getDescriptorSet() ) );

			// Create Sampler
			auto samplerVar = m_shader.registerSampler( originalVar->getName() + "_sampler"
				, samplerType
				, stmt->getBindingPoint()
				, stmt->getDescriptorSet() );
			samplerVar->updateFlag( ast::var::Flag::eImplicit );
			m_current->addStmt( ast::stmt::makeSamplerDecl( samplerVar
				, stmt->getBindingPoint()
				, stmt->getDescriptorSet() ) );

			// Link them
			linkVars( originalVar, textureVar, samplerVar );
		}
	}

	void StmtAdapter::visitShaderBufferDeclStmt( ast::stmt::ShaderBufferDecl * stmt )
	{
		auto ssboVar = stmt->getVariable();
		declareType( ssboVar->getType() );
		m_adaptationData.ssboList.push_back( ssboVar );
		m_current->addStmt( ast::stmt::makeShaderStructBufferDecl( stmt->getSsboName()
			, ast::var::makeVariable( ++m_adaptationData.nextVarId
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
			m_adaptationData.replacedVars.emplace( var
				, ast::expr::makeMbrSelect( ast::expr::makeArrayAccess( ssboVar->getType()
						, ast::expr::makeIdentifier( m_cache
							, ast::var::makeVariable( ++m_adaptationData.nextVarId
								, m_cache.getArray( ssboVar->getType(), 1u )
								, ssboVar->getName() ) )
						, ast::expr::makeLiteral( m_cache, 0 ) )
					, mbrIndex++
					, uint64_t( ast::var::Flag::eUniform ) ) );
		}
	}

	void StmtAdapter::visitShaderStructBufferDeclStmt( ast::stmt::ShaderStructBufferDecl * stmt )
	{
		declareType( stmt->getData()->getType() );
		m_adaptationData.ssboList.push_back( stmt->getSsboInstance() );
		m_current->addStmt( ast::stmt::makeShaderStructBufferDecl( stmt->getSsboName()
			, stmt->getSsboInstance()
			, stmt->getData()
			, stmt->getBindingPoint()
			, stmt->getDescriptorSet() ) );
	}

	void StmtAdapter::visitStructureDeclStmt( ast::stmt::StructureDecl * stmt )
	{
		declareType( stmt->getType() );
	}

	void StmtAdapter::visitVariableDeclStmt( ast::stmt::VariableDecl * stmt )
	{
		declareType( stmt->getVariable()->getType() );
		m_current->addStmt( ast::stmt::makeVariableDecl( stmt->getVariable() ) );
	}

	void StmtAdapter::visitPreprocExtension( ast::stmt::PreprocExtension * preproc )
	{
	}

	void StmtAdapter::visitPreprocVersion( ast::stmt::PreprocVersion * preproc )
	{
	}

	void StmtAdapter::writeMain( ast::stmt::FunctionDecl * stmt )
	{
		assert( stmt->getType()->getReturnType()->getKind() == ast::type::Kind::eVoid );
		ast::var::VariableList mainParameters;
		ast::type::TypePtr mainRetType = m_cache.getVoid();
		auto retType = m_adaptationData.fillParameters( mainParameters, *m_current );

		if ( retType )
		{
			mainRetType = retType;
		}

		auto cont = ast::stmt::makeFunctionDecl( m_cache.getFunction( mainRetType, mainParameters )
			, stmt->getName()
			, stmt->getFlags() );
		cont->addStmt( m_adaptationData.writeLocalesBegin() );

		// Call SDW_main function.
		cont->addStmt( ast::stmt::makeSimple( ast::expr::makeFnCall( m_cache.getVoid()
			, ast::expr::makeIdentifier( m_cache
				, ast::var::makeFunction( ++m_adaptationData.nextVarId
					, m_cache.getFunction( m_cache.getVoid(), ast::var::VariableList{} )
					, "SDW_" + stmt->getName() ) )
			, ast::expr::ExprList{} ) ) );

		cont->addStmt( m_adaptationData.writeLocalesEnd() );

		m_current->addStmt( std::move( cont ) );
	}

	ast::stmt::FunctionDeclPtr StmtAdapter::rewriteFuncHeader( ast::stmt::FunctionDecl * stmt )
	{
		ast::var::VariableList params;
		// Split sampled textures in sampler + texture in parameters list.
		for ( auto & param : *stmt->getType() )
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

		return ast::stmt::makeFunctionDecl( m_cache.getFunction( stmt->getType()->getReturnType(), params )
			, stmt->getName()
			, stmt->getFlags() );
	}

	void StmtAdapter::declareType( ast::type::TypePtr type )
	{
		if ( auto structType = getStructType( type ) )
		{
			if ( m_declaredStructs.insert( structType->getName() ).second )
			{
				m_inOutDeclarations->addStmt( ast::stmt::makeStructureDecl( structType ) );
			}
		}
	}
}
