/*
See LICENSE file in root folder
*/
#include "GlslAdaptStatements.hpp"

#include <ShaderAST/Shader.hpp>
#include <ShaderAST/Expr/MakeIntrinsic.hpp>
#include <ShaderAST/Type/TypeCache.hpp>
#include <ShaderAST/Visitors/CloneExpr.hpp>

#include <algorithm>

namespace glsl
{
	namespace adapt
	{
		namespace helpers
		{
			static ast::expr::ExprPtr swizzleConvert( ast::expr::ExprCache & exprCache
				, ast::type::TypePtr dst
				, ast::type::TypePtr src
				, ast::expr::ExprPtr expr )
			{
				ast::expr::SwizzleKind swizzle;
				auto srcCount = getComponentCount( src->getKind() );
				auto dstCount = getComponentCount( dst->getKind() );

				switch ( srcCount )
				{
				case 1:
					switch ( dstCount )
					{
					case 1:
						swizzle = ast::expr::SwizzleKind::e0;
						break;
					case 2:
						swizzle = ast::expr::SwizzleKind::e00;
						break;
					case 3:
						swizzle = ast::expr::SwizzleKind::e000;
						break;
					default:
						swizzle = ast::expr::SwizzleKind::e0000;
						break;
					}
					break;
				case 2:
					switch ( dstCount )
					{
					case 1:
						swizzle = ast::expr::SwizzleKind::e0;
						break;
					case 2:
						swizzle = ast::expr::SwizzleKind::e01;
						break;
					case 3:
						swizzle = ast::expr::SwizzleKind::e011;
						break;
					default:
						swizzle = ast::expr::SwizzleKind::e0111;
						break;
					}
					break;
				case 3:
					switch ( dstCount )
					{
					case 1:
						swizzle = ast::expr::SwizzleKind::e0;
						break;
					case 2:
						swizzle = ast::expr::SwizzleKind::e01;
						break;
					case 3:
						swizzle = ast::expr::SwizzleKind::e012;
						break;
					default:
						swizzle = ast::expr::SwizzleKind::e0122;
						break;
					}
					break;
				default:
					switch ( dstCount )
					{
					case 1:
						swizzle = ast::expr::SwizzleKind::e0;
						break;
					case 2:
						swizzle = ast::expr::SwizzleKind::e01;
						break;
					case 3:
						swizzle = ast::expr::SwizzleKind::e012;
						break;
					default:
						swizzle = ast::expr::SwizzleKind::e0123;
						break;
					}
					break;
				}

				return exprCache.makeSwizzle( std::move( expr )
					, swizzle );
			}

			static ast::expr::ExprPtr registerPerVertexBuiltin( ast::expr::ExprCache & exprCache
				, ast::type::TypesCache & typesCache
				, ast::Builtin builtin
				, ast::type::TypePtr type
				, uint64_t flags
				, uint32_t & nextVarId
				, IOVars & io )
			{
				auto [it, res] = io.perVertexMbrs.try_emplace( builtin );

				if ( res )
				{
					++nextVarId;
					it->second = exprCache.makeIdentifier( typesCache
						, ast::var::makeBuiltin( nextVarId
							, builtin
							, type
							, flags ) );
				}

				return ast::ExprCloner::submit( exprCache, *it->second );
			}

			static ast::expr::ExprPtr registerPerPrimitiveBuiltin( ast::expr::ExprCache & exprCache
				, ast::type::TypesCache & typesCache
				, ast::Builtin builtin
				, ast::type::TypePtr type
				, uint64_t flags
				, uint32_t & nextVarId
				, IOVars & io )
			{
				auto [it, res] = io.perPrimitiveMbrs.try_emplace( builtin );

				if ( res )
				{
					++nextVarId;
					it->second = exprCache.makeIdentifier( typesCache
						, ast::var::makeBuiltin( nextVarId
							, builtin
							, type
							, flags ) );
				}

				return ast::ExprCloner::submit( exprCache, *it->second );
			}

			static void enableExtension( ast::stmt::StmtCache & stmtCache
				, ast::stmt::Container & cont
				, GlslExtension const & extension
				, uint32_t shaderVersion )
			{
				if ( extension.coreVersion > shaderVersion )
				{
					cont.addStmt( stmtCache.makePreprocExtension( extension.name
						, ast::stmt::PreprocExtension::ExtStatus::eEnabled ) );
				}
			}

			static ast::stmt::PerVertexDecl::Source getPerVertexSource( ast::ShaderStage stage
				, bool isInput )
			{
				switch ( stage )
				{
				case ast::ShaderStage::eVertex:
					assert( !isInput );
					return ast::stmt::PerVertexDecl::eVertexOutput;
				case ast::ShaderStage::eTessellationControl:
					if ( isInput )
					{
						return ast::stmt::PerVertexDecl::eTessellationControlInput;
					}
					return ast::stmt::PerVertexDecl::eTessellationControlOutput;
				case ast::ShaderStage::eTessellationEvaluation:
					if ( isInput )
					{
						return ast::stmt::PerVertexDecl::eTessellationEvaluationInput;
					}
					return ast::stmt::PerVertexDecl::eTessellationEvaluationOutput;
				case ast::ShaderStage::eGeometry:
					if ( isInput )
					{
						return ast::stmt::PerVertexDecl::eGeometryInput;
					}
					return ast::stmt::PerVertexDecl::eGeometryOutput;
				case ast::ShaderStage::eMeshNV:
				case ast::ShaderStage::eMesh:
					return ast::stmt::PerVertexDecl::eMeshOutput;
				case ast::ShaderStage::eFragment:
					AST_Failure( "Unexpected gl_PerVertex declaration in fragment shader." );
					return ast::stmt::PerVertexDecl::eVertexOutput;
				case ast::ShaderStage::eCompute:
					AST_Failure( "Unexpected gl_PerVertex declaration in fragment shader." );
					return ast::stmt::PerVertexDecl::eVertexOutput;
				default:
					AST_Failure( "Unexpected shader stage." );
					return ast::stmt::PerVertexDecl::eVertexOutput;
				}
			}

			static ast::type::StructPtr getPerVertexBaseType( ast::type::TypesCache & typesCache
				, ast::EntryPoint entryPoint
				, bool isInput )
			{
				auto result{ typesCache.getIOStruct( "gl_PerVertex"
					, entryPoint
					, ( isInput ? ast::var::Flag::eShaderInput : ast::var::Flag::eShaderOutput ) ) };

				if ( !result->hasMember( ast::Builtin::ePosition ) )
				{
					result->declMember( ast::Builtin::ePosition
						, ast::type::Kind::eVec4F
						, ast::type::NotArray );
					result->declMember( ast::Builtin::ePointSize
						, ast::type::Kind::eFloat
						, ast::type::NotArray );
					result->declMember( ast::Builtin::eClipDistance
						, ast::type::Kind::eFloat
						, 8u );
					result->declMember( ast::Builtin::eCullDistance
						, ast::type::Kind::eFloat
						, 8u );
				}

				return result;
			}

			static ast::type::ArrayPtr getPerVertexArrayType( ast::type::TypesCache & typesCache
				, ast::EntryPoint entryPoint
				, uint32_t count
				, bool isInput )
			{
				return typesCache.getArray( getPerVertexBaseType( typesCache, entryPoint, isInput )
					, count );
			}

			static ast::type::StructPtr getMeshNVPerVertexBaseType( ast::type::TypesCache & typesCache
				, bool isInput )
			{
				auto result{ typesCache.getIOStruct( "gl_MeshPerVertexNV"
					, ast::EntryPoint::eMesh
					, ( isInput ? ast::var::Flag::eShaderInput : ast::var::Flag::eShaderOutput ) ) };

				if ( !result->hasMember( ast::Builtin::ePosition ) )
				{
					result->declMember( ast::Builtin::ePosition
						, ast::type::Kind::eVec4F
						, ast::type::NotArray );
					result->declMember( ast::Builtin::ePositionPerViewNV
						, ast::type::Kind::eVec4F
						, ast::type::UnknownArraySize );
					result->declMember( ast::Builtin::ePointSize
						, ast::type::Kind::eFloat
						, ast::type::NotArray );
					result->declMember( ast::Builtin::eClipDistance
						, ast::type::Kind::eFloat
						, 8u );
					result->declMember( ast::Builtin::eClipDistancePerViewNV
						, typesCache.getArray( typesCache.getFloat(), 8u )
						, ast::type::UnknownArraySize );
					result->declMember( ast::Builtin::eCullDistance
						, ast::type::Kind::eFloat
						, 8u );
					result->declMember( ast::Builtin::eCullDistancePerViewNV
						, typesCache.getArray( typesCache.getFloat(), 8u )
						, ast::type::UnknownArraySize );
				}

				return result;
			}

			static ast::type::ArrayPtr getMeshNVPerVertexArrayType( ast::type::TypesCache & typesCache
				, uint32_t count
				, bool isInput )
			{
				return typesCache.getArray( getMeshNVPerVertexBaseType( typesCache, isInput )
					, count );
			}

			static ast::type::StructPtr getMeshPerVertexBaseType( ast::type::TypesCache & typesCache
				, bool isInput )
			{
				auto result{ typesCache.getIOStruct( "gl_MeshPerVertexEXT"
					, ast::EntryPoint::eMesh
					, ( isInput ? ast::var::Flag::eShaderInput : ast::var::Flag::eShaderOutput ) ) };

				if ( !result->hasMember( ast::Builtin::ePosition ) )
				{
					result->declMember( ast::Builtin::ePosition
						, ast::type::Kind::eVec4F
						, ast::type::NotArray );
					result->declMember( ast::Builtin::ePositionPerViewNV
						, ast::type::Kind::eVec4F
						, ast::type::UnknownArraySize );
					result->declMember( ast::Builtin::ePointSize
						, ast::type::Kind::eFloat
						, ast::type::NotArray );
					result->declMember( ast::Builtin::eClipDistance
						, ast::type::Kind::eFloat
						, 8u );
					result->declMember( ast::Builtin::eClipDistancePerViewNV
						, typesCache.getArray( typesCache.getFloat(), 8u )
						, ast::type::UnknownArraySize );
					result->declMember( ast::Builtin::eCullDistance
						, ast::type::Kind::eFloat
						, 8u );
					result->declMember( ast::Builtin::eCullDistancePerViewNV
						, typesCache.getArray( typesCache.getFloat(), 8u )
						, ast::type::UnknownArraySize );
				}

				return result;
			}

			static ast::type::ArrayPtr getMeshPerVertexArrayType( ast::type::TypesCache & typesCache
				, uint32_t count
				, bool isInput )
			{
				return typesCache.getArray( getMeshPerVertexBaseType( typesCache, isInput )
					, count );
			}

			static ast::type::TypePtr getPerVertexType( ast::type::TypesCache & typesCache
				, ast::ShaderStage stage
				, bool isInput
				, uint32_t maxPoint
				, ast::type::InputLayout inputLayout )
			{
				switch ( stage )
				{
				case ast::ShaderStage::eVertex:
					assert( !isInput );
					return getPerVertexBaseType( typesCache
						, ast::EntryPoint::eVertex
						, isInput );
				case ast::ShaderStage::eTessellationControl:
					if ( isInput )
					{
						return getPerVertexArrayType( typesCache
							, ast::EntryPoint::eTessellationControl
							, maxPoint
							, isInput );
					}
					return  getPerVertexArrayType( typesCache
						, ast::EntryPoint::eTessellationControl
						, 32u
						, isInput );
				case ast::ShaderStage::eTessellationEvaluation:
					if ( isInput )
					{
						return getPerVertexArrayType( typesCache
							, ast::EntryPoint::eTessellationEvaluation
							, 32u
							, isInput );
					}
					return getPerVertexBaseType( typesCache
						, ast::EntryPoint::eTessellationEvaluation
						, isInput );
				case ast::ShaderStage::eGeometry:
					if ( isInput )
					{
						return getPerVertexArrayType( typesCache
							, ast::EntryPoint::eGeometry
							, getArraySize( inputLayout )
							, isInput );
					}
					return getPerVertexBaseType( typesCache
						, ast::EntryPoint::eGeometry
						, isInput );
				case ast::ShaderStage::eMeshNV:
					assert( !isInput );
					return getMeshNVPerVertexArrayType( typesCache
						, getArraySize( inputLayout )
						, isInput );
				case ast::ShaderStage::eMesh:
					assert( !isInput );
					return getMeshPerVertexArrayType( typesCache
						, getArraySize( inputLayout )
						, isInput );
				case ast::ShaderStage::eFragment:
					AST_Failure( "Unexpected gl_PerVertex declaration in fragment shader." );
					return nullptr;
				case ast::ShaderStage::eCompute:
					AST_Failure( "Unexpected gl_PerVertex declaration in compute shader." );
					return nullptr;
				default:
					AST_Failure( "Unexpected shader stage." );
					return nullptr;
				}
			}

			static ast::type::StructPtr getPerPrimitiveNVBaseType( ast::type::TypesCache & typesCache
				, bool isInput )
			{
				auto result{ typesCache.getIOStruct( "gl_MeshPerPrimitiveNV"
					, ast::EntryPoint::eMesh
					, ( isInput ? ast::var::Flag::eShaderInput : ast::var::Flag::eShaderOutput ) ) };

				if ( !result->hasMember( ast::Builtin::ePrimitiveID ) )
				{
					result->declMember( ast::Builtin::ePrimitiveID
						, ast::type::Kind::eInt32
						, ast::type::NotArray );
					result->declMember( ast::Builtin::eLayer
						, ast::type::Kind::eInt32
						, ast::type::NotArray );
					result->declMember( ast::Builtin::eLayerPerViewNV
						, ast::type::Kind::eInt32
						, ast::type::UnknownArraySize );
					result->declMember( ast::Builtin::eViewportIndex
						, ast::type::Kind::eInt32
						, ast::type::NotArray );
					result->declMember( ast::Builtin::eViewportMaskNV
						, ast::type::Kind::eInt32
						, 1u );
					result->declMember( ast::Builtin::eViewportMaskPerViewNV
						, typesCache.getArray( typesCache.getInt32(), 1u )
						, ast::type::UnknownArraySize );
				}

				return result;
			}

			static ast::type::ArrayPtr getPerPrimitiveNVArrayType( ast::type::TypesCache & typesCache
				, uint32_t count
				, bool isInput )
			{
				return typesCache.getArray( getPerPrimitiveNVBaseType( typesCache, isInput )
					, count );
			}

			static ast::type::StructPtr getPerPrimitiveBaseType( ast::type::TypesCache & typesCache
				, bool isInput )
			{
				auto result{ typesCache.getIOStruct( "gl_MeshPerPrimitiveEXT"
					, ast::EntryPoint::eMesh
					, ( isInput ? ast::var::Flag::eShaderInput : ast::var::Flag::eShaderOutput ) ) };

				if ( !result->hasMember( ast::Builtin::ePrimitiveID ) )
				{
					result->declMember( ast::Builtin::ePrimitiveID
						, ast::type::Kind::eInt32
						, ast::type::NotArray );
					result->declMember( ast::Builtin::eLayer
						, ast::type::Kind::eInt32
						, ast::type::NotArray );
					result->declMember( ast::Builtin::eLayerPerViewNV
						, ast::type::Kind::eInt32
						, ast::type::UnknownArraySize );
					result->declMember( ast::Builtin::eViewportIndex
						, ast::type::Kind::eInt32
						, ast::type::NotArray );
					result->declMember( ast::Builtin::eCullPrimitive
						, ast::type::Kind::eBoolean
						, ast::type::NotArray );
					result->declMember( ast::Builtin::eViewportMaskNV
						, ast::type::Kind::eInt32
						, 1u );
					result->declMember( ast::Builtin::eViewportMaskPerViewNV
						, typesCache.getArray( typesCache.getInt32(), 1u )
						, ast::type::UnknownArraySize );
				}

				return result;
			}

			static ast::type::ArrayPtr getPerPrimitiveArrayType( ast::type::TypesCache & typesCache
				, uint32_t count
				, bool isInput )
			{
				return typesCache.getArray( getPerPrimitiveBaseType( typesCache, isInput )
					, count );
			}

			static ast::type::TypePtr getPerPrimitiveType( ast::type::TypesCache & typesCache
				, ast::ShaderStage stage
				, bool isInput
				, uint32_t maxPrimitives )
			{
				switch ( stage )
				{
				case ast::ShaderStage::eMeshNV:
					assert( !isInput );
					return getPerPrimitiveNVArrayType( typesCache
						, maxPrimitives
						, isInput );
				case ast::ShaderStage::eMesh:
					assert( !isInput );
					return getPerPrimitiveArrayType( typesCache
						, maxPrimitives
						, isInput );
				case ast::ShaderStage::eVertex:
					AST_Failure( "Unexpected gl_PerVertex declaration in vertex shader." );
					return nullptr;
				case ast::ShaderStage::eTessellationControl:
					AST_Failure( "Unexpected gl_PerVertex declaration in tessellation control shader." );
					return nullptr;
				case ast::ShaderStage::eTessellationEvaluation:
					AST_Failure( "Unexpected gl_PerVertex declaration in tessellation evaluation shader." );
					return nullptr;
				case ast::ShaderStage::eGeometry:
					AST_Failure( "Unexpected gl_PerVertex declaration in geometry shader." );
					return nullptr;
				case ast::ShaderStage::eFragment:
					AST_Failure( "Unexpected gl_PerVertex declaration in fragment shader." );
					return nullptr;
				case ast::ShaderStage::eCompute:
					AST_Failure( "Unexpected gl_PerVertex declaration in compute shader." );
					return nullptr;
				default:
					AST_Failure( "Unexpected shader stage." );
					return nullptr;
				}
			}
		}

		class ExprAdapter
			: public ast::ExprCloner
		{
		public:
			static ast::expr::ExprPtr submit( ast::stmt::StmtCache & stmtCache
				, ast::expr::ExprCache & exprCache
				, ast::type::TypesCache & typesCache
				, ast::expr::Expr const & expr
				, AdaptationData & adaptationData
				, ast::stmt::Container * container )
			{
				ast::expr::ExprPtr result{};
				ExprAdapter vis{ stmtCache, exprCache, typesCache, adaptationData, container, result };
				expr.accept( &vis );
				return result;
			}

		private:
			ExprAdapter( ast::stmt::StmtCache & stmtCache
				, ast::expr::ExprCache & exprCache
				, ast::type::TypesCache & typesCache
				, AdaptationData & adaptationData
				, ast::stmt::Container * container
				, ast::expr::ExprPtr & result )
				: ExprCloner{ exprCache, result }
				, m_stmtCache{ stmtCache }
				, m_typesCache{ typesCache }
				, m_adaptationData{ adaptationData }
				, m_container{ container }
			{
			}

			using ast::ExprCloner::doSubmit;

			ast::expr::ExprPtr doSubmit( ast::expr::Expr const & expr )override
			{
				ast::expr::ExprPtr result{};
				ExprAdapter vis{ m_stmtCache, m_exprCache, m_typesCache, m_adaptationData, m_container, result };
				expr.accept( &vis );

				if ( expr.isNonUniform() )
				{
					result->updateFlag( ast::expr::Flag::eNonUniform );
				}

				return result;
			}

			void visitAssignExpr( ast::expr::Assign const * expr )override
			{
				if ( auto lhs = expr->getLHS();
					lhs->getKind() == ast::expr::Kind::eMbrSelect )
				{
					auto & mbrSelect = static_cast< ast::expr::MbrSelect const & >( *lhs );
					auto outer = mbrSelect.getOuterExpr();

					if ( outer->getKind() == ast::expr::Kind::eArrayAccess )
					{
						auto structType = mbrSelect.getOuterType();
						auto mbr = structType->getMember( mbrSelect.getMemberIndex() );

						if ( mbr.builtin == ast::Builtin::ePrimitiveIndicesNV )
						{
							auto & io = m_adaptationData.outputs;
							auto it = io.vars.find( structType );
							assert( it != io.vars.end() );
							auto mbrIt = std::find_if( it->second.begin()
								, it->second.end()
								, [&mbr]( ast::var::VariablePtr const & lookup )
								{
									return lookup->getBuiltin() == mbr.builtin
										|| lookup->getName() == mbr.name
										|| lookup->getName() == "gl_" + mbr.name;
								} );
							assert( mbrIt != it->second.end() );

							// Compute base index, based on declared type of builtin
							auto & arrayAccess = static_cast< ast::expr::ArrayAccess const & >( *outer );
							auto index = arrayAccess.getRHS();
							ast::expr::ExprPtr multiplier{};

							switch ( mbr.type->getKind() )
							{
							case ast::type::Kind::eUInt32:
								break;
							case ast::type::Kind::eVec2U32:
								multiplier = m_exprCache.makeLiteral( m_typesCache, 2u );
								break;
							case ast::type::Kind::eVec3U32:
								multiplier = m_exprCache.makeLiteral( m_typesCache, 3u );
								break;
							default:
								AST_Failure( "Unsupported type for gl_PrimitiveIndicesNV" );
								break;
							}

							auto baseIndex = doSubmit( index );

							if ( multiplier )
							{
								baseIndex = m_exprCache.makeTimes( m_typesCache.getUInt32()
									, doSubmit( index )
									, std::move( multiplier ) );
							}

							auto componentCount = getComponentCount( mbr.type );

							if ( componentCount == 1u )
							{
								m_result = m_exprCache.makeArrayAccess( m_typesCache.getUInt32()
									, m_exprCache.makeIdentifier( m_typesCache, *mbrIt )
									, std::move( baseIndex ) );
								m_result = m_exprCache.makeAssign( mbr.type
									, std::move( m_result )
									, doSubmit( *expr->getRHS() ) );
							}
							else
							{
								m_result = m_exprCache.makeArrayAccess( m_typesCache.getUInt32()
									, m_exprCache.makeIdentifier( m_typesCache, *mbrIt )
									, ExprCloner::submit( m_exprCache, *baseIndex ) );
								m_result = m_exprCache.makeAssign( mbr.type
									, std::move( m_result )
									, m_exprCache.makeSwizzle( doSubmit( *expr->getRHS() )
										, ast::expr::SwizzleKind{ ast::expr::SwizzleKind::e0 } ) );

								if ( componentCount >= 2u )
								{
									m_container->addStmt( m_stmtCache.makeSimple( std::move( m_result ) ) );
									m_result = m_exprCache.makeArrayAccess( m_typesCache.getUInt32()
										, m_exprCache.makeIdentifier( m_typesCache, *mbrIt )
										, m_exprCache.makeAdd( m_typesCache.getUInt32()
											, ExprCloner::submit( m_exprCache, *baseIndex )
											, m_exprCache.makeLiteral( m_typesCache, 1u ) ) );
									m_result = m_exprCache.makeAssign( mbr.type
										, std::move( m_result )
										, m_exprCache.makeSwizzle( doSubmit( *expr->getRHS() )
											, ast::expr::SwizzleKind{ ast::expr::SwizzleKind::e1 } ) );
								}

								if ( componentCount >= 3u )
								{
									m_container->addStmt( m_stmtCache.makeSimple( std::move( m_result ) ) );
									m_result = m_exprCache.makeArrayAccess( m_typesCache.getUInt32()
										, m_exprCache.makeIdentifier( m_typesCache, *mbrIt )
										, m_exprCache.makeAdd( m_typesCache.getUInt32()
											, ExprCloner::submit( m_exprCache, *baseIndex )
											, m_exprCache.makeLiteral( m_typesCache, 2u ) ) );
									m_result = m_exprCache.makeAssign( mbr.type
										, std::move( m_result )
										, m_exprCache.makeSwizzle( doSubmit( *expr->getRHS() )
											, ast::expr::SwizzleKind{ ast::expr::SwizzleKind::e2 } ) );
								}
							}
						}
					}
				}

				if ( !m_result )
				{
					ExprCloner::visitAssignExpr( expr );
				}
			}

			void visitArrayAccessExpr( ast::expr::ArrayAccess const * expr )override
			{
				ExprCloner::visitArrayAccessExpr( expr );
			}

			void visitIdentifierExpr( ast::expr::Identifier const * expr )override
			{
				auto it = m_adaptationData.aliases.find( expr->getVariable() );

				if ( it != m_adaptationData.aliases.end() )
				{
					m_result = m_exprCache.makeIdentifier( expr->getTypesCache(), it->second );
				}
				else
				{
					ExprCloner::visitIdentifierExpr( expr );
				}
			}

			void visitImageAccessCallExpr( ast::expr::StorageImageAccessCall const * expr )override
			{
				if ( expr->getImageAccess() >= ast::expr::StorageImageAccess::eImageStore1DF
					&& expr->getImageAccess() <= ast::expr::StorageImageAccess::eImageStore2DMSArrayU )
				{
					doProcessImageStore( *expr );
				}
				else
				{
					ExprCloner::visitImageAccessCallExpr( expr );
				}
			}

			void visitIntrinsicCallExpr( ast::expr::IntrinsicCall const * expr )override
			{
				if ( expr->getIntrinsic() >= ast::expr::Intrinsic::eFma1F
					&& expr->getIntrinsic() <= ast::expr::Intrinsic::eFma4D
					&& m_adaptationData.writerConfig.wantedVersion < v4_3 )
				{
					assert( expr->getArgList().size() == 3u );
					m_result = m_exprCache.makeAdd( expr->getType()
						, m_exprCache.makeTimes( expr->getType()
							, doSubmit( *expr->getArgList()[0] )
							, doSubmit( *expr->getArgList()[1] ) )
						, doSubmit( *expr->getArgList()[2] ) );
				}
				else if ( expr->getIntrinsic() == ast::expr::Intrinsic::eTraceRay )
				{
					ast::expr::ExprList args;

					for ( auto & arg : expr->getArgList() )
					{
						args.emplace_back( doSubmit( *arg ) );
					}

					auto payLoad = std::move( args.back() );
					args.pop_back();
					auto rayDesc = std::move( args.back() );
					args.pop_back();
					// Replace RayDesc parameter with its four members
					assert( rayDesc->getType()->getRawKind() == ast::type::Kind::eRayDesc );
					uint32_t index = 0u;
					for ( auto mbr : *getStructType( rayDesc->getType() ) )
					{
						args.push_back( m_exprCache.makeMbrSelect( ExprCloner::submit( m_exprCache, *rayDesc ), index, 0u ) );
						++index;
					}
					// Extract location from RayPayload type, to set it as last param.
					args.push_back( m_exprCache.makeLiteral( m_typesCache
						, int( static_cast< ast::type::RayPayload const & >( *payLoad->getType() ).getLocation() ) ) );
					m_result = m_exprCache.makeIntrinsicCall( expr->getType()
						, expr->getIntrinsic()
						, std::move( args ) );
				}
				else if ( expr->getIntrinsic() == ast::expr::Intrinsic::eExecuteCallable )
				{
					ast::expr::ExprList args;

					for ( auto & arg : expr->getArgList() )
					{
						args.emplace_back( doSubmit( *arg ) );
					}

					auto callData = std::move( args.back() );
					args.pop_back();
					// Extract location from RayPayload type, to set it as last param.
					args.push_back( m_exprCache.makeLiteral( m_typesCache
						, int( static_cast< ast::type::CallableData const & >( *callData->getType() ).getLocation() ) ) );
					m_result = m_exprCache.makeIntrinsicCall( expr->getType()
						, expr->getIntrinsic()
						, std::move( args ) );
				}
				else if ( expr->getIntrinsic() == ast::expr::Intrinsic::eReportIntersection )
				{
					ast::expr::ExprList args;

					for ( auto & arg : expr->getArgList() )
					{
						args.emplace_back( doSubmit( *arg ) );
					}

					// Remove unused HitAttribute last param.
					args.pop_back();
					m_result = m_exprCache.makeIntrinsicCall( expr->getType()
						, expr->getIntrinsic()
						, std::move( args ) );
				}
				else if ( expr->getIntrinsic() == ast::expr::Intrinsic::eSetMeshOutputCountsNV )
				{
					ast::expr::ExprList args;

					for ( auto & arg : expr->getArgList() )
					{
						args.emplace_back( doSubmit( *arg ) );
					}

					auto numPrimitives = std::move( args.back() );
					args.pop_back();
					// previous to last is numVertices, which is ignored
					args.pop_back();
					auto type = numPrimitives->getType();
					++m_adaptationData.nextVarId;
					auto var = ast::var::makeBuiltin( m_adaptationData.nextVarId
						, ast::Builtin::ePrimitiveCountNV
						, type
						, ast::var::Flag::eShaderOutput );
					m_result = m_exprCache.makeAssign( type
						, m_exprCache.makeIdentifier( m_typesCache, var )
						, std::move( numPrimitives ) );
				}
				else if ( expr->getIntrinsic() == ast::expr::Intrinsic::eDispatchMeshNV )
				{
					ast::expr::ExprList args;

					for ( auto & arg : expr->getArgList() )
					{
						args.emplace_back( doSubmit( *arg ) );
					}

					auto numTasks = std::move( args.back() );
					args.pop_back();
					auto type = numTasks->getType();
					++m_adaptationData.nextVarId;
					auto var = ast::var::makeBuiltin( m_adaptationData.nextVarId
						, ast::Builtin::eTaskCountNV
						, type
						, ast::var::Flag::eShaderOutput );
					m_result = m_exprCache.makeAssign( type
						, m_exprCache.makeIdentifier( m_typesCache, var )
						, std::move( numTasks ) );
				}
				else if ( expr->getIntrinsic() != ast::expr::Intrinsic::eHelperInvocation )
				{
					ast::expr::ExprList args;

					for ( auto & arg : expr->getArgList() )
					{
						args.emplace_back( doSubmit( *arg ) );
					}

					m_result = m_exprCache.makeIntrinsicCall( expr->getType()
						, expr->getIntrinsic()
						, std::move( args ) );
				}
			}

			void visitMbrSelectExpr( ast::expr::MbrSelect const * expr )override
			{
				m_result = doProcessMbr( *expr->getOuterExpr()
					, expr->getMemberIndex()
					, expr->getMemberFlags() );

				if ( !m_result )
				{
					ExprCloner::visitMbrSelectExpr( expr );
				}
			}

			void visitStreamAppendExpr( ast::expr::StreamAppend const * expr )override
			{
				m_result = makeEmitVertex( m_exprCache, m_typesCache );
			}

			void visitCombinedImageAccessCallExpr( ast::expr::CombinedImageAccessCall const * expr )override
			{
				if ( expr->getCombinedImageAccess() >= ast::expr::CombinedImageAccess::eTexture1DShadowF
					&& expr->getCombinedImageAccess() <= ast::expr::CombinedImageAccess::eTextureProjGradOffset2DShadowF )
				{
					doProcessTextureShadow( *expr );
				}
				else if ( expr->getCombinedImageAccess() >= ast::expr::CombinedImageAccess::eTexture1DF
					&& expr->getCombinedImageAccess() <= ast::expr::CombinedImageAccess::eTextureProjGradOffset3DU )
				{
					doProcessTextureSample( *expr );
				}
				else if ( expr->getCombinedImageAccess() >= ast::expr::CombinedImageAccess::eTextureGather2DF
					&& expr->getCombinedImageAccess() <= ast::expr::CombinedImageAccess::eTextureGatherOffsets2DArrayU )
				{
					doProcessTextureGather( *expr );
				}
				else
				{
					ast::expr::ExprList args;

					for ( auto & arg : expr->getArgList() )
					{
						args.emplace_back( doSubmit( *arg ) );
					}

					m_result = m_exprCache.makeCombinedImageAccessCall( expr->getType()
						, expr->getCombinedImageAccess()
						, std::move( args ) );
				}
			}

		private:
			void doProcessImageStore( ast::expr::StorageImageAccessCall const & expr )
			{
				auto imgArgType = std::static_pointer_cast< ast::type::Image >( expr.getArgList()[0]->getType() );
				auto config = imgArgType->getConfig();
				auto sampledType = m_typesCache.getSampledType( config.format );
				auto glslType = m_typesCache.getVec4Type( getScalarType( sampledType->getKind() ) );
				ast::expr::ExprList args;

				for ( auto & arg : expr.getArgList() )
				{
					if ( arg != expr.getArgList().back() )
					{
						args.emplace_back( doSubmit( *arg ) );
					}
					else
					{
						// Convert last parameter to appropriate gvec4 type.
						auto result = doSubmit( *arg );

						if ( sampledType != glslType )
						{
							result = ( ( getComponentCount( *sampledType ) == 1u )
								? [this, &glslType, &result]()
								{
									ast::expr::ExprList list;
									list.emplace_back( std::move( result ) );
									return m_exprCache.makeCompositeConstruct( getCompositeType( glslType->getKind() )
										, getComponentType( *glslType )
										, std::move( list ) );
								}()
								: helpers::swizzleConvert( m_exprCache, glslType, sampledType, std::move( result ) ) );
						}

						args.emplace_back( std::move( result ) );
					}
				}

				m_result = m_exprCache.makeStorageImageAccessCall( expr.getType()
					, expr.getImageAccess()
					, std::move( args ) );
			}

			void doProcessTextureShadow( ast::expr::CombinedImageAccessCall const & expr )
			{
				ast::expr::ExprList args;
				// First parameter is the sampled image
				args.emplace_back( doSubmit( *expr.getArgList()[0] ) );
				// For texture shadow functions, dref value is put inside the coords parameter, instead of being aside.
				assert( expr.getArgList().size() >= 3u );

				if ( expr.getCombinedImageAccess() == ast::expr::CombinedImageAccess::eTexture1DShadowF
					|| expr.getCombinedImageAccess() == ast::expr::CombinedImageAccess::eTexture1DShadowFBias
					|| expr.getCombinedImageAccess() == ast::expr::CombinedImageAccess::eTextureProj1DShadowF
					|| expr.getCombinedImageAccess() == ast::expr::CombinedImageAccess::eTextureProj1DShadowFBias
					|| expr.getCombinedImageAccess() == ast::expr::CombinedImageAccess::eTextureLod1DShadowF
					|| expr.getCombinedImageAccess() == ast::expr::CombinedImageAccess::eTextureOffset1DShadowF
					|| expr.getCombinedImageAccess() == ast::expr::CombinedImageAccess::eTextureOffset1DShadowFBias
					|| expr.getCombinedImageAccess() == ast::expr::CombinedImageAccess::eTextureProjOffset1DShadowF
					|| expr.getCombinedImageAccess() == ast::expr::CombinedImageAccess::eTextureProjOffset1DShadowFBias
					|| expr.getCombinedImageAccess() == ast::expr::CombinedImageAccess::eTextureLodOffset1DShadowF
					|| expr.getCombinedImageAccess() == ast::expr::CombinedImageAccess::eTextureProjLod1DShadowF
					|| expr.getCombinedImageAccess() == ast::expr::CombinedImageAccess::eTextureProjLodOffset1DShadowF
					|| expr.getCombinedImageAccess() == ast::expr::CombinedImageAccess::eTextureGrad1DShadowF
					|| expr.getCombinedImageAccess() == ast::expr::CombinedImageAccess::eTextureGradOffset1DShadowF
					|| expr.getCombinedImageAccess() == ast::expr::CombinedImageAccess::eTextureProjGrad1DShadowF
					|| expr.getCombinedImageAccess() == ast::expr::CombinedImageAccess::eTextureProjGradOffset1DShadowF )
				{
					ast::expr::ExprList merged;

					switch ( expr.getArgList()[1]->getType()->getKind() )
					{
					case ast::type::Kind::eFloat:
						// Texture1DShadow accesses.
						// Merge second and third parameters to the appropriate vector type (float=>vec2, vec2=>vec3, vec3=>vec4).
						merged.emplace_back( doSubmit( *expr.getArgList()[1] ) );
						merged.emplace_back( doSubmit( *expr.getArgList()[1] ) );
						merged.emplace_back( doSubmit( *expr.getArgList()[2] ) );
						args.emplace_back( m_exprCache.makeCompositeConstruct( ast::expr::CompositeType::eVec3
							, ast::type::Kind::eFloat
							, std::move( merged ) ) );
						break;
					case ast::type::Kind::eVec2F:
					{
						// TextureProj1DShadow accesses.
						merged.emplace_back( m_exprCache.makeSwizzle( doSubmit( *expr.getArgList()[1] ), ast::expr::SwizzleKind{ ast::expr::SwizzleKind::e0 } ) );
						merged.emplace_back( m_exprCache.makeSwizzle( doSubmit( *expr.getArgList()[1] ), ast::expr::SwizzleKind{ ast::expr::SwizzleKind::e0 } ) );
						merged.emplace_back( doSubmit( *expr.getArgList()[2] ) );
						merged.emplace_back( m_exprCache.makeSwizzle( doSubmit( *expr.getArgList()[1] ), ast::expr::SwizzleKind{ ast::expr::SwizzleKind::e1 } ) );
						args.emplace_back( m_exprCache.makeCompositeConstruct( ast::expr::CompositeType::eVec4
							, ast::type::Kind::eFloat
							, std::move( merged ) ) );
					}
					break;
					case ast::type::Kind::eVec3F:
						merged.emplace_back( doSubmit( *expr.getArgList()[1] ) );
						merged.emplace_back( doSubmit( *expr.getArgList()[2] ) );
						args.emplace_back( m_exprCache.makeCompositeConstruct( ast::expr::CompositeType::eVec4
							, ast::type::Kind::eFloat
							, std::move( merged ) ) );
						break;
					case ast::type::Kind::eVec4F:
						// If the first type was a vec4, forget about merging
						args.emplace_back( doSubmit( *expr.getArgList()[1] ) );
						args.emplace_back( doSubmit( *expr.getArgList()[2] ) );
						break;
					default:
						break;
					}
				}
				else
				{
					// Merge second and third parameters to the appropriate vector type (float=>vec2, vec2=>vec3, vec3=>vec4).
					ast::expr::ExprList merged;
					merged.emplace_back( doSubmit( *expr.getArgList()[1] ) );
					merged.emplace_back( doSubmit( *expr.getArgList()[2] ) );

					switch ( merged[0]->getType()->getKind() )
					{
					case ast::type::Kind::eFloat:
						args.emplace_back( m_exprCache.makeCompositeConstruct( ast::expr::CompositeType::eVec2
							, ast::type::Kind::eFloat
							, std::move( merged ) ) );
						break;
					case ast::type::Kind::eVec2F:
						args.emplace_back( m_exprCache.makeCompositeConstruct( ast::expr::CompositeType::eVec3
							, ast::type::Kind::eFloat
							, std::move( merged ) ) );
						break;
					case ast::type::Kind::eVec3F:
						args.emplace_back( m_exprCache.makeCompositeConstruct( ast::expr::CompositeType::eVec4
							, ast::type::Kind::eFloat
							, std::move( merged ) ) );
						break;
					case ast::type::Kind::eVec4F:
						// If the first type was a vec4, forget about merging
						args.emplace_back( doSubmit( *expr.getArgList()[1] ) );
						args.emplace_back( doSubmit( *expr.getArgList()[2] ) );
						break;
					default:
						break;
					}
				}

				// Other parameters remain unchanged.
				for ( size_t i = 3u; i < expr.getArgList().size(); ++i )
				{
					args.emplace_back( doSubmit( *expr.getArgList()[i] ) );
				}

				m_result = m_exprCache.makeCombinedImageAccessCall( expr.getType()
					, expr.getCombinedImageAccess()
					, std::move( args ) );
			}

			void doProcessTextureSample( ast::expr::CombinedImageAccessCall const & expr )
			{
				auto imgArgType = std::static_pointer_cast< ast::type::CombinedImage >( expr.getArgList()[0]->getType() );
				auto config = imgArgType->getConfig();
				auto callRetType = m_typesCache.getSampledType( config.format );
				ast::expr::ExprList args;

				for ( auto & arg : expr.getArgList() )
				{
					args.emplace_back( doSubmit( *arg ) );
				}

				m_result = m_exprCache.makeCombinedImageAccessCall( expr.getType()
					, expr.getCombinedImageAccess()
					, std::move( args ) );

				auto glslRetType = m_typesCache.getVec4Type( getScalarType( callRetType->getKind() ) );

				if ( callRetType != glslRetType )
				{
					m_result = helpers::swizzleConvert( m_exprCache, callRetType, glslRetType, std::move( m_result ) );
				}
			}

			void doProcessTextureGather( ast::expr::CombinedImageAccessCall const & expr )
			{
				ast::expr::ExprList args;

				for ( auto & arg : expr.getArgList() )
				{
					args.emplace_back( doSubmit( *arg ) );
				}

				// Component parameter is the last one in GLSL whilst it is the last before
				// optional ones in SPIR-V, hence we move it to the right place.
				// 0->img, 1->coord, 2->component
				auto it = args.begin() + 2u;
				auto compArg = std::move( *it );
				args.erase( it );
				args.emplace_back( std::move( compArg ) );

				m_result = m_exprCache.makeCombinedImageAccessCall( expr.getType()
					, expr.getCombinedImageAccess()
					, std::move( args ) );
			}

			ast::expr::ExprPtr doProcessIOMbr( ast::expr::Expr const * outer
				, uint32_t mbrIndex
				, uint64_t mbrFlags
				, bool isInput
				, IOVars & io )
			{
				assert( isStructType( outer->getType() ) );
				auto structType = getStructType( outer->getType() );
				auto & mbr = *std::next( structType->begin(), ptrdiff_t( mbrIndex ) );
				
				if ( auto compType = getComponentType( mbr.type );
					( m_adaptationData.writerConfig.shaderStage != ast::ShaderStage::eVertex || !isInput )
					&& !isMeshStage( m_adaptationData.writerConfig.shaderStage )
					&& !isRayTraceStage( m_adaptationData.writerConfig.shaderStage )
					&& ( isUnsignedIntType( compType ) || isSignedIntType( compType ) ) )
				{
					mbrFlags = mbrFlags | ast::var::Flag::eFlat;
				}

				ast::expr::ExprPtr result{};

				if ( isPerVertex( mbr.builtin
					, m_adaptationData.writerConfig.shaderStage ) )
				{
					ast::expr::ExprPtr indexExpr{};

					if ( outer->getKind() == ast::expr::Kind::eArrayAccess )
					{
						auto & arrayAccess = static_cast< ast::expr::ArrayAccess const & >( *outer );
						outer = arrayAccess.getLHS();

						if ( outer->getKind() == ast::expr::Kind::eIdentifier
							&& io.isMainVar( static_cast< ast::expr::Identifier const & >( *outer ).getVariable() ) )
						{
							indexExpr = doSubmit( arrayAccess.getRHS() );
						}
					}

					if ( outer->getKind() == ast::expr::Kind::eIdentifier
						&& io.isMainVar( static_cast< ast::expr::Identifier const & >( *outer ).getVariable() ) )
					{
						if ( indexExpr )
						{
							auto type = getNonArrayType( io.perVertex->getType() );
							assert( isStructType( type ) );
							auto perVertexType = getStructType( type );
							mbrIndex = perVertexType->findMember( mbr.builtin );
							assert( mbrIndex != ast::type::Struct::NotFound );
							result = m_exprCache.makeArrayAccess( perVertexType
								, m_exprCache.makeIdentifier( m_typesCache, io.perVertex )
								, std::move( indexExpr ) );
							result = m_exprCache.makeMbrSelect( std::move( result )
								, mbrIndex
								, mbrFlags | ast::var::Flag::eBuiltin );
						}
						else
						{
							result = helpers::registerPerVertexBuiltin( m_exprCache
								, m_typesCache
								, mbr.builtin
								, mbr.type
								, mbrFlags
								, m_adaptationData.nextVarId
								, io );
						}
					}
				}
				else if ( isPerPrimitive( mbr.builtin
					, m_adaptationData.writerConfig.shaderStage ) )
				{
					ast::expr::ExprPtr indexExpr{};

					if ( outer->getKind() == ast::expr::Kind::eArrayAccess )
					{
						auto & arrayAccess = static_cast< ast::expr::ArrayAccess const & >( *outer );
						outer = arrayAccess.getLHS();

						if ( outer->getKind() == ast::expr::Kind::eIdentifier
							&& io.isMainVar( static_cast< ast::expr::Identifier const & >( *outer ).getVariable() ) )
						{
							indexExpr = doSubmit( arrayAccess.getRHS() );
						}
					}

					if ( outer->getKind() == ast::expr::Kind::eIdentifier
						&& io.isMainVar( static_cast< ast::expr::Identifier const & >( *outer ).getVariable() ) )
					{
						if ( indexExpr )
						{
							auto type = getNonArrayType( io.perPrimitive->getType() );
							assert( isStructType( type ) );
							auto perPrimitiveType = getStructType( type );
							mbrIndex = perPrimitiveType->findMember( mbr.builtin );
							assert( mbrIndex != ast::type::Struct::NotFound );
							result = m_exprCache.makeArrayAccess( perPrimitiveType
								, m_exprCache.makeIdentifier( m_typesCache, io.perPrimitive )
								, std::move( indexExpr ) );
							result = m_exprCache.makeMbrSelect( std::move( result )
								, mbrIndex
								, mbrFlags | ast::var::Flag::eBuiltin );
						}
						else
						{
							result = helpers::registerPerPrimitiveBuiltin( m_exprCache
								, m_typesCache
								, mbr.builtin
								, mbr.type
								, mbrFlags
								, m_adaptationData.nextVarId
								, io );
						}
					}
				}
				else if ( mbr.builtin != ast::Builtin::eNone )
				{
					auto it = io.vars.find( structType );

					if ( it == io.vars.end() )
					{
						auto structIt = io.builtinsStructs.find( structType );

						if ( structIt != io.builtinsStructs.end() )
						{
							it = io.vars.find( structIt->second.first );
						}
					}

					if ( it != io.vars.end() )
					{
						auto mbrIt = std::find_if( it->second.begin()
							, it->second.end()
							, [&mbr]( ast::var::VariablePtr const & lookup )
							{
								return ( mbr.builtin != ast::Builtin::eNone && mbr.builtin == lookup->getBuiltin() )
									|| lookup->getName() == mbr.name
									|| lookup->getName() == "gl_" + mbr.name;
							} );
						assert( mbrIt != it->second.end() );
						result = m_exprCache.makeIdentifier( m_typesCache
							, *mbrIt );
					}
				}
				else
				{
					ast::expr::ExprPtr indexExpr{};

					if ( outer->getKind() == ast::expr::Kind::eArrayAccess )
					{
						auto & arrayAccess = static_cast< ast::expr::ArrayAccess const & >( *outer );
						outer = arrayAccess.getLHS();

						if ( outer->getKind() == ast::expr::Kind::eIdentifier
							&& io.isMainVar( static_cast< ast::expr::Identifier const & >( *outer ).getVariable() ) )
						{
							indexExpr = doSubmit( arrayAccess.getRHS() );
						}
					}
					else if ( outer->getType()->getKind() == ast::type::Kind::eTessellationControlOutput )
					{
						indexExpr = helpers::registerPerVertexBuiltin( m_exprCache
							, m_typesCache
							, ast::Builtin::eInvocationID
							, m_typesCache.getUInt32()
							, uint64_t( ast::var::Flag::eShaderInput )
							, m_adaptationData.nextVarId
							, io );
					}

					if ( outer->getKind() == ast::expr::Kind::eIdentifier
						&& io.isMainVar( static_cast< ast::expr::Identifier const & >( *outer ).getVariable() ) )
					{
						auto it = io.vars.find( structType );

						if ( it == io.vars.end() )
						{
							auto structIt = io.othersStructs.find( structType );

							if ( structIt != io.othersStructs.end() )
							{
								return m_exprCache.makeMbrSelect( m_exprCache.makeIdentifier( m_typesCache, structIt->second )
									, mbrIndex
									, mbrFlags );
							}
						}

						assert( it != io.vars.end() );
						auto mbrIt = std::find_if( it->second.begin()
							, it->second.end()
							, [&mbr]( ast::var::VariablePtr const & lookup )
							{
								return lookup->getName() == mbr.name
									|| ( !lookup->isBuiltin()
										&& ( lookup->getName() == "sdwIn_" + mbr.name
											|| lookup->getName() == "sdwOut_" + mbr.name ) )
									|| ( lookup->isBuiltin()
										&& lookup->getName() == "gl_" + mbr.name );
							} );
						assert( mbrIt != it->second.end() );
						result = m_exprCache.makeIdentifier( m_typesCache
							, *mbrIt );

						if ( indexExpr )
						{
							result = m_exprCache.makeArrayAccess( mbr.type
								, std::move( result )
								, std::move( indexExpr ) );
						}
					}
				}

				return result;
			}

			ast::expr::ExprPtr doProcessMbr( ast::expr::Expr const & outer
				, uint32_t mbrIndex
				, uint64_t mbrFlags )
			{
				auto result = doProcessIOMbr( &outer, mbrIndex, mbrFlags, true, m_adaptationData.inputs );

				if ( !result )
				{
					result = doProcessIOMbr( &outer, mbrIndex, mbrFlags, false, m_adaptationData.outputs );
				}

				return result;
			}

		private:
			ast::stmt::StmtCache & m_stmtCache;
			ast::type::TypesCache & m_typesCache;
			AdaptationData & m_adaptationData;
			ast::stmt::Container * m_container;
		};

		class StmtAdapter
			: public ast::StmtCloner
		{
		public:
			static ast::stmt::ContainerPtr submit( ast::stmt::StmtCache & stmtCache
				, ast::expr::ExprCache & exprCache
				, ast::type::TypesCache & typesCache
				, ast::stmt::Container const & container
				, AdaptationData & adaptationData )
			{
				auto result = stmtCache.makeContainer();

				if ( auto it = std::find_if( container.begin()
					, container.end()
					, []( ast::stmt::StmtPtr const & lookup )
					{
						return lookup->getKind() == ast::stmt::Kind::ePreprocVersion;
					} );
					it == container.end() )
				{
					result->addStmt( stmtCache.makePreprocVersion( writeValue( adaptationData.writerConfig.wantedVersion ) ) );

					for ( auto & extension : adaptationData.intrinsicsConfig.requiredExtensions )
					{
						helpers::enableExtension( stmtCache, *result, extension, adaptationData.writerConfig.wantedVersion );
					}
				}

				StmtAdapter vis{ stmtCache, exprCache, typesCache, adaptationData, result.get(), result };
				container.accept( &vis );
				return result;
			}

		private:
			StmtAdapter( ast::stmt::StmtCache & stmtCache
				, ast::expr::ExprCache & exprCache
				, ast::type::TypesCache & typesCache
				, AdaptationData & adaptationData
				, ast::stmt::Container * globalsCont
				, ast::stmt::ContainerPtr & result )
				: ast::StmtCloner{ stmtCache, exprCache, result }
				, m_typesCache{ typesCache }
				, m_adaptationData{ adaptationData }
				, m_entryPointFinish{ m_stmtCache.makeContainer() }
				, m_globalsCont{ globalsCont }
			{
				if ( m_adaptationData.intrinsicsConfig.requiresRayDescDecl )
				{
					declareType( typesCache.getRayDesc() );
				}
			}

			using ast::StmtCloner::doSubmit;

			ast::expr::ExprPtr doSubmit( ast::expr::Expr const & expr )override
			{
				return ExprAdapter::submit( m_stmtCache
					, m_exprCache
					, m_typesCache
					, expr
					, m_adaptationData
					, m_current );
			}

			void visitConstantBufferDeclStmt( ast::stmt::ConstantBufferDecl const * stmt )override
			{
				if ( stmt->getMemoryLayout() == ast::type::MemoryLayout::eStd430
					&& !m_adaptationData.writerConfig.hasStd430Layout )
				{
					throw ast::Exception{ "std430 layout is not supported, consider using std140" };
				}

				if ( m_adaptationData.writerConfig.hasDescriptorSets )
				{
					ast::StmtCloner::visitConstantBufferDeclStmt( stmt );
				}
				else
				{
					auto save = m_current;
					auto cont = m_stmtCache.makeConstantBufferDecl( stmt->getName()
						, stmt->getMemoryLayout()
						, stmt->getBindingPoint()
						, InvalidIndex );
					m_current = cont.get();
					visitContainerStmt( stmt );
					m_current = save;
					m_current->addStmt( std::move( cont ) );
				}
			}

			void visitFunctionDeclStmt( ast::stmt::FunctionDecl const * stmt )override
			{
				if ( stmt->getFlags() )
				{
					auto isEntryPoint = stmt->isEntryPoint();

					for ( auto & param : *stmt->getType() )
					{
						auto type = param->getType();

						switch ( type->getKind() )
						{
						case ast::type::Kind::eFragmentInput:
							doProcess( param, static_cast< ast::type::FragmentInput const & >( *type ) );
							break;
						case ast::type::Kind::eGeometryOutput:
							doProcess( param, static_cast< ast::type::GeometryOutput const & >( *type ) );
							break;
						case ast::type::Kind::eGeometryInput:
							doProcess( param, static_cast< ast::type::GeometryInput const & >( *type ) );
							break;
						case ast::type::Kind::eTessellationInputPatch:
							doProcess( param, static_cast< ast::type::TessellationInputPatch const & >( *type ) );
							break;
						case ast::type::Kind::eTessellationControlInput:
							doProcess( param, static_cast< ast::type::TessellationControlInput const & >( *type ) );
							break;
						case ast::type::Kind::eTessellationEvaluationInput:
							doProcess( param, static_cast< ast::type::TessellationEvaluationInput const & >( *type ) );
							break;
						case ast::type::Kind::eComputeInput:
							doProcess( param, static_cast< ast::type::ComputeInput const & >( *type ) );
							break;
						case ast::type::Kind::eTessellationOutputPatch:
							doProcess( param, static_cast< ast::type::TessellationOutputPatch const & >( *type ) );
							break;
						case ast::type::Kind::eTessellationControlOutput:
							doProcess( param, static_cast< ast::type::TessellationControlOutput const & >( *type ) );
							break;
						case ast::type::Kind::eMeshVertexOutput:
							doProcess( param, static_cast< ast::type::MeshVertexOutput const & >( *type ) );
							break;
						case ast::type::Kind::eMeshPrimitiveOutput:
							doProcess( param, static_cast< ast::type::MeshPrimitiveOutput const & >( *type ) );
							break;
						case ast::type::Kind::eTaskPayloadNV:
							doProcessTaskPayload( param );
							break;
						case ast::type::Kind::eTaskPayload:
							doProcessTaskPayload( param );
							break;
						case ast::type::Kind::eTaskPayloadInNV:
							doProcessTaskPayload( param );
							break;
						case ast::type::Kind::eTaskPayloadIn:
							doProcessTaskPayload( param );
							break;
						default:
						{
							uint32_t arraySize = ast::type::NotArray;

							if ( type->getKind() == ast::type::Kind::eArray )
							{
								auto & arrayType = static_cast< ast::type::Array const & >( *type );
								type = arrayType.getType();
								arraySize = arrayType.getArraySize();
							}

							if ( isStructType( type ) )
							{
								auto structType = getStructType( type );

								if ( structType->isShaderInput() )
								{
									doProcessInput( param
										, std::static_pointer_cast< ast::type::IOStruct >( structType )
										, arraySize
										, isEntryPoint );
								}
								else if ( structType->isShaderOutput() )
								{
									doProcessOutput( param
										, std::static_pointer_cast< ast::type::IOStruct >( structType )
										, arraySize
										, isEntryPoint );
								}
							}
						}
						break;
						}
					}

					if ( stmt->isEntryPoint() )
					{
						doProcessEntryPoint( *stmt );
					}
					else if ( stmt->isPatchRoutine() )
					{
						doProcessPatchRoutine( *stmt );
					}
				}
				else
				{
					ast::StmtCloner::visitFunctionDeclStmt( stmt );
				}
			}

			void visitHitAttributeVariableDeclStmt( ast::stmt::HitAttributeVariableDecl const * stmt )override
			{
				auto var = stmt->getVariable();
				declareType( var->getType() );
				m_globalsCont->addStmt( m_stmtCache.makeHitAttributeVariableDecl( var ) );
			}

			void visitImageDeclStmt( ast::stmt::ImageDecl const * stmt )override
			{
				if ( m_adaptationData.writerConfig.hasDescriptorSets )
				{
					ast::StmtCloner::visitImageDeclStmt( stmt );
				}
				else
				{
					m_current->addStmt( m_stmtCache.makeImageDecl( stmt->getVariable()
						, stmt->getBindingPoint()
						, InvalidIndex ) );
				}
			}

			void visitInOutCallableDataVariableDeclStmt( ast::stmt::InOutCallableDataVariableDecl const * stmt )override
			{
				auto var = stmt->getVariable();
				declareType( var->getType() );

				if ( var->isCallableData() )
				{
					var->updateFlag( ast::var::Flag::eShaderOutput );
					m_globalsCont->addStmt( m_stmtCache.makeInOutCallableDataVariableDecl( var
						, stmt->getLocation() ) );
				}
				else
				{
					StmtCloner::visitInOutCallableDataVariableDeclStmt( stmt );
				}
			}

			void visitInOutRayPayloadVariableDeclStmt( ast::stmt::InOutRayPayloadVariableDecl const * stmt )override
			{
				auto var = stmt->getVariable();
				declareType( var->getType() );

				if ( var->isRayPayload() )
				{
					var->updateFlag( ast::var::Flag::eShaderOutput );
					m_globalsCont->addStmt( m_stmtCache.makeInOutRayPayloadVariableDecl( var
						, stmt->getLocation() ) );
				}
				else
				{
					StmtCloner::visitInOutRayPayloadVariableDeclStmt( stmt );
				}
			}

			void visitInOutVariableDeclStmt( ast::stmt::InOutVariableDecl const * stmt )override
			{
				declareType( stmt->getVariable()->getType() );
				StmtCloner::visitInOutVariableDeclStmt( stmt );
			}

			void visitInputComputeLayoutStmt( ast::stmt::InputComputeLayout const * stmt )override
			{
				declareType( stmt->getType() );
				StmtCloner::visitInputComputeLayoutStmt( stmt );
			}

			void visitInputGeometryLayoutStmt( ast::stmt::InputGeometryLayout const * stmt )override
			{
				declareType( stmt->getType() );
				StmtCloner::visitInputGeometryLayoutStmt( stmt );
			}

			void visitOutputGeometryLayoutStmt( ast::stmt::OutputGeometryLayout const * stmt )override
			{
				declareType( stmt->getType() );
				StmtCloner::visitOutputGeometryLayoutStmt( stmt );
			}

			void visitOutputMeshLayoutStmt( ast::stmt::OutputMeshLayout const * stmt )override
			{
				declareType( stmt->getType() );
				StmtCloner::visitOutputMeshLayoutStmt( stmt );
			}

			void visitPushConstantsBufferDeclStmt( ast::stmt::PushConstantsBufferDecl const * stmt )override
			{
				if ( stmt->getMemoryLayout() == ast::type::MemoryLayout::eStd430
					&& !m_adaptationData.writerConfig.hasStd430Layout )
				{
					throw ast::Exception{ "std430 layout is not supported, consider using std140" };
				}

				auto save = m_current;
				ast::stmt::ContainerPtr cont;

				if ( m_adaptationData.writerConfig.vulkanGlsl )
				{
					cont = m_stmtCache.makePushConstantsBufferDecl( stmt->getName()
						, stmt->getMemoryLayout() );
				}
				else
				{
					// PCB are not supported, implement them as UBO.
					cont = m_stmtCache.makeConstantBufferDecl( stmt->getName()
						, stmt->getMemoryLayout()
						, InvalidIndex
						, InvalidIndex );
				}

				m_current = cont.get();
				m_inPCB = true;
				visitContainerStmt( stmt );
				m_inPCB = false;
				m_current = save;
				m_current->addStmt( std::move( cont ) );
			}

			void visitCombinedImageDeclStmt( ast::stmt::CombinedImageDecl const * stmt )override
			{
				if ( m_adaptationData.writerConfig.hasDescriptorSets )
				{
					ast::StmtCloner::visitCombinedImageDeclStmt( stmt );
				}
				else
				{
					m_current->addStmt( m_stmtCache.makeCombinedImageDecl( stmt->getVariable()
						, stmt->getBindingPoint()
						, InvalidIndex ) );
				}
			}

			void visitSampledImageDeclStmt( ast::stmt::SampledImageDecl const * stmt )override
			{
				if ( m_adaptationData.writerConfig.hasDescriptorSets )
				{
					ast::StmtCloner::visitSampledImageDeclStmt( stmt );
				}
				else
				{
					m_current->addStmt( m_stmtCache.makeSampledImageDecl( stmt->getVariable()
						, stmt->getBindingPoint()
						, InvalidIndex ) );
				}
			}

			void visitShaderBufferDeclStmt( ast::stmt::ShaderBufferDecl const * stmt )override
			{
				if ( stmt->getMemoryLayout() == ast::type::MemoryLayout::eStd430
					&& !m_adaptationData.writerConfig.hasStd430Layout )
				{
					throw ast::Exception{ "std430 layout is not supported, consider using std140" };
				}

				if ( m_adaptationData.writerConfig.hasDescriptorSets )
				{
					ast::StmtCloner::visitShaderBufferDeclStmt( stmt );
				}
				else
				{
					auto save = m_current;
					auto cont = m_stmtCache.makeShaderBufferDecl( stmt->getVariable()
						, stmt->getBindingPoint()
						, InvalidIndex );
					m_current = cont.get();
					visitContainerStmt( stmt );
					m_current = save;
					m_current->addStmt( std::move( cont ) );
				}
			}

			void visitShaderStructBufferDeclStmt( ast::stmt::ShaderStructBufferDecl const * stmt )override
			{
				declareType( stmt->getData()->getType() );

				if ( stmt->getMemoryLayout() == ast::type::MemoryLayout::eStd430
					&& !m_adaptationData.writerConfig.hasStd430Layout )
				{
					throw ast::Exception{ "std430 layout is not supported, consider using std140" };
				}

				if ( m_adaptationData.writerConfig.hasDescriptorSets )
				{
					ast::StmtCloner::visitShaderStructBufferDeclStmt( stmt );
				}
				else
				{
					m_current->addStmt( m_stmtCache.makeShaderStructBufferDecl( stmt->getSsboName()
						, stmt->getSsboInstance()
						, stmt->getData()
						, stmt->getBindingPoint()
						, InvalidIndex ) );
				}
			}

			void visitStructureDeclStmt( ast::stmt::StructureDecl const * stmt )override
			{
				declareType( stmt->getType() );
			}

			void visitVariableDeclStmt( ast::stmt::VariableDecl const * stmt )override
			{
				auto var = stmt->getVariable();
				declareType( var->getType() );
				ast::StmtCloner::visitVariableDeclStmt( stmt );
			}

			void visitPreprocVersion( ast::stmt::PreprocVersion const * preproc )override
			{
				m_result->addStmt( m_stmtCache.makePreprocVersion( preproc->getName() ) );
				auto cont = m_stmtCache.makeContainer();

				if ( !cont->empty() )
				{
					m_result->addStmt( std::move( cont ) );
				}
			}

			void declareType( ast::type::TypePtr type )
			{
				if ( auto structType = getStructType( getNonArrayType( type ) ) )
				{
					if ( type->getKind() != ast::type::Kind::eTaskPayloadNV
						&& type->getKind() != ast::type::Kind::eTaskPayloadInNV
						&& m_declaredStructs.insert( structType->getName() ).second )
					{
						m_globalsCont->addStmt( m_stmtCache.makeStructureDecl( structType ) );
					}
				}
			}

		private:
			void doProcess( ast::var::VariablePtr var
				, ast::type::FragmentInput const & fragType )
			{
				auto type = fragType.getType();

				if ( isStructType( type ) )
				{
					auto structType = getStructType( type );
					assert( structType->isShaderInput() );
					doProcessInput( var
						, std::static_pointer_cast< ast::type::IOStruct >( structType )
						, ast::type::NotArray
						, true );
				}

				m_current->addStmt( m_stmtCache.makeFragmentLayout( type
					, fragType.getOrigin()
					, fragType.getCenter() ) );
			}

			void doProcess( ast::var::VariablePtr var
				, ast::type::GeometryOutput const & geomType )
			{
				auto type = geomType.getType();

				if ( isStructType( type ) )
				{
					auto structType = getStructType( type );
					assert( structType->isShaderOutput() );
					doProcessOutput( var
						, std::static_pointer_cast< ast::type::IOStruct >( structType )
						, ast::type::NotArray
						, true );
				}

				m_current->addStmt( m_stmtCache.makeOutputGeometryLayout( type
					, geomType.getLayout()
					, geomType.getCount() ) );
			}

			void doProcess( ast::var::VariablePtr var
				, ast::type::GeometryInput const & geomType )
			{
				auto type = geomType.getType();
				m_inputLayout = geomType.getLayout();

				if ( isStructType( type ) )
				{
					auto structType = getStructType( type );
					assert( structType->isShaderInput() );
					doProcessInput( var
						, std::static_pointer_cast< ast::type::IOStruct >( structType )
						, getArraySize( geomType.getLayout() )
						, true );
				}

				m_current->addStmt( m_stmtCache.makeInputGeometryLayout( type
					, geomType.getLayout() ) );
			}

			void doProcess( ast::var::VariablePtr var
				, ast::type::TessellationInputPatch const & patchType )
			{
				if ( isStructType( patchType.getType() ) )
				{
					auto structType = getStructType( patchType.getType() );
					auto flags = structType->getFlag();
					auto outStructType = std::make_shared< ast::type::IOStruct >( patchType.getTypesCache()
						, structType->getMemoryLayout()
						, structType->getName() + "Repl"
						, getEntryPointType( m_adaptationData.stage )
						, ast::var::Flag( flags ) );
					auto outBuiltinsType = std::make_shared< ast::type::IOStruct >( patchType.getTypesCache()
						, structType->getMemoryLayout()
						, structType->getName() + "Builtins"
						, getEntryPointType( m_adaptationData.stage )
						, ast::var::Flag::eShaderInput );
					auto othersVar = ast::var::makeVariable( { ++m_adaptationData.nextVarId, var->getName() + "Others" }
						, ast::type::makeTessellationInputPatchType( outStructType
							, patchType.getDomain()
							, patchType.getLocation() )
						, var->getFlags() );
					auto builtinsVar = ast::var::makeVariable( { ++m_adaptationData.nextVarId, var->getName() + "Builtins" }
					, outBuiltinsType );
					auto & io = m_adaptationData.inputs;

					for ( auto & mbr : *structType )
					{
						auto name = ( mbr.builtin != ast::Builtin::eNone
							? "gl_" + getName( mbr.builtin )
							: mbr.name );

						if ( mbr.builtin == ast::Builtin::eNone )
						{
							outStructType->declMember( mbr.name
								, mbr.type
								, mbr.location );
						}
						else
						{
							outBuiltinsType->declMember( mbr.builtin
								, getNonArrayType( mbr.type )->getKind()
								, getArraySize( mbr.type )
								, ast::type::Struct::InvalidLocation );
							auto typeIt = io.vars.try_emplace( outBuiltinsType ).first;
							auto it = std::find_if( typeIt->second.begin()
								, typeIt->second.end()
								, [&name]( ast::var::VariablePtr const & lookup )
								{
									return name == lookup->getName();
								} );

							if ( it == typeIt->second.end() )
							{
								++m_adaptationData.nextVarId;
								auto mbrVar = ast::var::makeBuiltin( m_adaptationData.nextVarId
									, mbr.builtin
									, mbr.type
									, outBuiltinsType->getFlag() );
								typeIt->second.emplace_back( mbrVar );
							}
						}
					}

					if ( !outStructType->empty() )
					{
						io.othersStructs.try_emplace( structType, othersVar );
						declareType( outStructType );
						m_current->addStmt( m_stmtCache.makeInOutVariableDecl( othersVar
							, patchType.getLocation() ) );
						io.setMainVar( var );
					}

					if ( !outBuiltinsType->empty() )
					{
						io.builtinsStructs.try_emplace( structType, outBuiltinsType, uint32_t( outStructType->size() ) );
					}
				}
			}

			void doProcess( ast::var::VariablePtr var
				, ast::type::TessellationOutputPatch const & patchType )
			{
				if ( isStructType( patchType.getType() ) )
				{
					auto structType = getStructType( patchType.getType() );
					auto flags = structType->getFlag();
					auto outStructType = std::make_shared< ast::type::IOStruct >( patchType.getTypesCache()
						, structType->getMemoryLayout()
						, structType->getName() + "Repl"
						, getEntryPointType( m_adaptationData.stage )
						, ast::var::Flag( flags ) );
					auto outBuiltinsType = std::make_shared< ast::type::IOStruct >( patchType.getTypesCache()
						, structType->getMemoryLayout()
						, structType->getName() + "Builtins"
						, getEntryPointType( m_adaptationData.stage )
						, ast::var::Flag::eShaderOutput );
					auto othersVar = ast::var::makeVariable( { ++m_adaptationData.nextVarId, var->getName() + "Others" }
						, ast::type::makeTessellationOutputPatchType( outStructType
							, patchType.getLocation() )
						, var->getFlags() );
					auto builtinsVar = ast::var::makeVariable( { ++m_adaptationData.nextVarId, var->getName() + "Builtins" }
					, outBuiltinsType );
					auto & io = m_adaptationData.outputs;

					for ( auto & mbr : *structType )
					{
						auto name = ( mbr.builtin != ast::Builtin::eNone
							? "gl_" + getName( mbr.builtin )
							: mbr.name );

						if ( mbr.builtin == ast::Builtin::eNone )
						{
							outStructType->declMember( mbr.name
								, mbr.type
								, mbr.location );
						}
						else
						{
							outBuiltinsType->declMember( mbr.builtin
								, getNonArrayType( mbr.type )->getKind()
								, getArraySize( mbr.type )
								, ast::type::Struct::InvalidLocation );
							auto typeIt = io.vars.try_emplace( outBuiltinsType ).first;
							auto it = std::find_if( typeIt->second.begin()
								, typeIt->second.end()
								, [&name]( ast::var::VariablePtr const & lookup )
								{
									return name == lookup->getName();
								} );

							if ( it == typeIt->second.end() )
							{
								++m_adaptationData.nextVarId;
								auto mbrVar = ast::var::makeBuiltin( m_adaptationData.nextVarId
									, mbr.builtin
									, mbr.type
									, outBuiltinsType->getFlag() );
								typeIt->second.emplace_back( mbrVar );
							}
						}
					}

					if ( !outStructType->empty() )
					{
						io.othersStructs.try_emplace( structType, othersVar );
						declareType( outStructType );
						m_current->addStmt( m_stmtCache.makeInOutVariableDecl( othersVar
							, patchType.getLocation() ) );
						io.setMainVar( var );
					}

					if ( !outBuiltinsType->empty() )
					{
						io.builtinsStructs.try_emplace( structType, outBuiltinsType, uint32_t( outStructType->size() ) );
					}
				}
			}

			void doProcess( ast::var::VariablePtr var
				, ast::type::TessellationControlInput const & tessType )
			{
				auto type = tessType.getType();
				m_maxPoint = tessType.getInputVertices();

				if ( isStructType( type ) )
				{
					auto structType = getStructType( type );
					assert( structType->isShaderInput() );
					doProcessInput( var
						, std::static_pointer_cast< ast::type::IOStruct >( structType )
						, 32u
						, true );
				}
			}

			void doProcess( ast::var::VariablePtr var
				, ast::type::TessellationControlOutput const & tessType )
			{
				auto type = tessType.getType();
				uint32_t arraySize = tessType.getOutputVertices();

				if ( isStructType( type ) )
				{
					auto structType = getStructType( type );
					assert( structType->isShaderOutput() );
					doProcessOutput( var
						, std::static_pointer_cast< ast::type::IOStruct >( structType )
						, arraySize
						, true );
				}

				m_current->addStmt( m_stmtCache.makeOutputTessellationControlLayout( type
					, tessType.getDomain()
					, tessType.getPartitioning()
					, tessType.getTopology()
					, tessType.getOrder()
					, tessType.getOutputVertices() ) );
			}

			void doProcess( ast::var::VariablePtr var
				, ast::type::TessellationEvaluationInput const & tessType )
			{
				auto type = tessType.getType();
				m_maxPoint = tessType.getInputVertices();

				if ( isStructType( type ) )
				{
					auto structType = getStructType( type );
					assert( structType->isShaderInput() );
					doProcessInput( var
						, std::static_pointer_cast< ast::type::IOStruct >( structType )
						, 32u
						, true );
				}

				m_current->addStmt( m_stmtCache.makeInputTessellationEvaluationLayout( tessType.getType()
					, tessType.getDomain()
					, tessType.getPartitioning()
					, tessType.getPrimitiveOrdering() ) );
			}

			void doProcess( ast::var::VariablePtr var
				, ast::type::MeshVertexOutput const & meshType )
			{
				m_meshVtxVar = var;
				m_meshVtxType = &meshType;
				m_maxPoint = meshType.getMaxVertices();

				if ( m_meshPrimType )
				{
					doProcessMeshOutputs();
					m_current->addStmt( m_stmtCache.makeOutputMeshLayout( meshType.getType()
						, m_meshPrimType->getTopology()
						, m_maxPoint
						, m_maxPrimitives ) );
				}
			}

			void doProcess( ast::var::VariablePtr var
				, ast::type::MeshPrimitiveOutput const & meshType )
			{
				m_meshPrimVar = var;
				m_meshPrimType = &meshType;
				m_maxPrimitives = meshType.getMaxPrimitives();

				if ( m_meshVtxType )
				{
					doProcessMeshOutputs();
					m_current->addStmt( m_stmtCache.makeOutputMeshLayout( meshType.getType()
						, meshType.getTopology()
						, m_maxPoint
						, m_maxPrimitives ) );
				}
			}

			void doProcessTaskPayload( ast::var::VariablePtr var )
			{
				m_current->addStmt( m_stmtCache.makeVariableDecl( var ) );
			}

			void doProcess( ast::var::VariablePtr var
				, ast::type::ComputeInput const & compType )
			{
				if ( auto type = compType.getType();
					isStructType( type ) )
				{
					auto structType = getStructType( type );
					assert( structType->isShaderInput() );
					doProcessInput( var
						, std::static_pointer_cast< ast::type::IOStruct >( structType )
						, ast::type::NotArray
						, true );
				}

				if ( isMeshNVStage( m_adaptationData.stage ) )
				{
					m_current->addStmt( m_stmtCache.makeInputComputeLayout( compType.getType()
						, compType.getLocalSizeX() * compType.getLocalSizeY() * compType.getLocalSizeZ()
						, 1u
						, 1u ) );
				}
				else
				{
					m_current->addStmt( m_stmtCache.makeInputComputeLayout( compType.getType()
						, compType.getLocalSizeX()
						, compType.getLocalSizeY()
						, compType.getLocalSizeZ() ) );
				}
			}

			void doProcessOutput( ast::var::VariablePtr var
				, ast::type::IOStructPtr structType
				, uint32_t arraySize
				, bool declVar )
			{
				doProcessIO( var
					, structType
					, arraySize
					, declVar
					, false
					, m_adaptationData.outputs );
			}

			void doProcessInput( ast::var::VariablePtr var
				, ast::type::IOStructPtr structType
				, uint32_t arraySize
				, bool declVar )
			{
				doProcessIO( var
					, structType
					, arraySize
					, declVar
					, true
					, m_adaptationData.inputs );
			}

			void doProcessIO( ast::var::VariablePtr var
				, ast::type::IOStructPtr structType
				, uint32_t arraySize
				, bool declVar
				, bool isInput
				, IOVars & io )
			{
				io.setMainVar( var );

				for ( auto & mbr : *structType )
				{
					if ( isPerVertex( mbr.builtin
						, m_adaptationData.writerConfig.shaderStage ) )
					{
						auto type = doDeclarePerVertex( isInput );
						std::string outerName;

						if ( type->getKind() == ast::type::Kind::eArray )
						{
							if ( isInput )
							{
								outerName = "gl_in";
							}
							else if ( m_adaptationData.writerConfig.shaderStage == ast::ShaderStage::eMesh )
							{
								outerName = "gl_MeshVerticesEXT";
							}
							else if ( m_adaptationData.writerConfig.shaderStage == ast::ShaderStage::eMeshNV )
							{
								outerName = "gl_MeshVerticesNV";
							}
							else
							{
								outerName = "gl_out";
							}
						}

						io.perVertex = ast::var::makeVariable( ast::EntityName{ ++m_adaptationData.nextVarId, outerName }
						, type
							, ( ast::var::Flag::eBuiltin
								| ( isInput ? ast::var::Flag::eShaderInput : ast::var::Flag::eShaderOutput ) ) );
					}
					else if ( isPerPrimitive( mbr.builtin
						, m_adaptationData.writerConfig.shaderStage ) )
					{
						auto type = doDeclarePerPrimitive( isInput );
						io.perPrimitive = ast::var::makeVariable( ast::EntityName{ ++m_adaptationData.nextVarId, "gl_MeshPrimitivesNV" }
						, type
							, ( ast::var::Flag::eBuiltin
								| ( isInput ? ast::var::Flag::eShaderInput : ast::var::Flag::eShaderOutput ) ) );
					}
					else
					{
						auto name = ( mbr.builtin != ast::Builtin::eNone
							? "gl_" + getName( mbr.builtin )
							: "sdw" + ( isInput ? std::string{ "In" } : std::string{ "Out" } ) + "_" + mbr.name );
						auto typeIt = io.vars.try_emplace( structType ).first;

						if ( auto it = std::find_if( typeIt->second.begin()
							, typeIt->second.end()
							, [&name]( ast::var::VariablePtr const & lookup )
							{
								return name == lookup->getName();
							} );
							it == typeIt->second.end() )
						{
							auto mbrFlags = structType->getFlag()
								| ( mbr.builtin != ast::Builtin::eNone
									? ast::var::Flag::eBuiltin
									: ast::var::Flag::eNone );
							auto mbrType = mbr.type;
							auto compType = getComponentType( mbrType );

							if ( mbr.builtin == ast::Builtin::ePrimitiveIndicesNV
								|| mbr.builtin == ast::Builtin::ePrimitivePointIndices
								|| mbr.builtin == ast::Builtin::ePrimitiveLineIndices
								|| mbr.builtin == ast::Builtin::ePrimitiveTriangleIndices )
							{
								mbrType = m_typesCache.getBasicType( compType );
							}
							else if ( ( m_adaptationData.writerConfig.shaderStage != ast::ShaderStage::eVertex || !isInput )
								&& !isMeshStage( m_adaptationData.writerConfig.shaderStage )
								&& !isRayTraceStage( m_adaptationData.writerConfig.shaderStage )
								&& ( isUnsignedIntType( compType ) || isSignedIntType( compType ) ) )
							{
								mbrFlags = mbrFlags | ast::var::Flag::eFlat;
							}

							++m_adaptationData.nextVarId;
							auto mbrVar = ( ( mbr.builtin != ast::Builtin::eNone )
								? ast::var::makeBuiltin( m_adaptationData.nextVarId
									, mbr.builtin
									, ( arraySize == ast::type::NotArray
										? mbrType
										: m_typesCache.getArray( mbrType, arraySize ) )
										, mbrFlags )
								: ast::var::makeVariable( ast::EntityName{ m_adaptationData.nextVarId, name }
									, ( arraySize == ast::type::NotArray
										? mbrType
										: m_typesCache.getArray( mbrType, arraySize ) )
										, mbrFlags ) );
							typeIt->second.emplace_back( mbrVar );

							if ( declVar && mbr.builtin == ast::Builtin::eNone )
							{
								m_current->addStmt( m_stmtCache.makeInOutVariableDecl( mbrVar
									, mbr.location ) );
							}
						}
					}
				}
			}

			void doProcessEntryPoint( ast::stmt::FunctionDecl const & stmt )
			{
				auto funcType = m_typesCache.getFunction( m_typesCache.getVoid(), {} );
				auto save = m_current;
				auto cont = m_stmtCache.makeFunctionDecl( ast::var::makeVariable( stmt.getFuncVar()->getId()
						, funcType
						, stmt.getName()
						, stmt.getFuncVar()->getFlags() )
					, stmt.getFlags() );
				m_current = cont.get();
				visitContainerStmt( &stmt );

				if ( stmt.isEntryPoint() )
				{
					visitContainerStmt( m_entryPointFinish.get() );
				}

				m_current = save;
				m_current->addStmt( std::move( cont ) );
			}

			void doProcessPatchRoutine( ast::stmt::FunctionDecl const & stmt )
			{
				auto save = m_current;
				m_current = m_entryPointFinish.get();
				visitContainerStmt( &stmt );
				m_current = save;
			}

			ast::type::TypePtr doDeclarePerVertex( bool isInput )
			{
				if ( ( isInput && !m_inPerVertex )
					|| ( !isInput && !m_outPerVertex ) )
				{
					auto type = helpers::getPerVertexType( m_typesCache
						, m_adaptationData.writerConfig.shaderStage
						, isInput
						, m_maxPoint
						, m_inputLayout );
					m_current->addStmt( m_stmtCache.makePerVertexDecl( helpers::getPerVertexSource( m_adaptationData.writerConfig.shaderStage
						, isInput )
						, type ) );

					if ( isInput )
					{
						m_inPerVertex = type;
					}
					else
					{
						m_outPerVertex = type;
					}

					return type;
				}

				if ( isInput )
				{
					return m_inPerVertex;
				}

				return m_outPerVertex;
			}

			ast::type::TypePtr doDeclarePerPrimitive( bool isInput )
			{
				if ( ( isInput && !m_inPerPrimitive )
					|| ( !isInput && !m_outPerPrimitive ) )
				{
					auto type = helpers::getPerPrimitiveType( m_typesCache
						, m_adaptationData.writerConfig.shaderStage
						, isInput
						, m_maxPrimitives );
					m_current->addStmt( m_stmtCache.makePerPrimitiveDecl( type ) );

					if ( isInput )
					{
						m_inPerPrimitive = type;
					}
					else
					{
						m_outPerPrimitive = type;
					}

					return type;
				}

				if ( isInput )
				{
					return m_inPerPrimitive;
				}

				return m_outPerPrimitive;
			}

			void doProcessMeshOutputs()
			{
				auto type = m_meshVtxType->getType();

				if ( isStructType( type ) )
				{
					auto structType = getStructType( type );
					assert( structType->isShaderOutput() );
					doProcessOutput( m_meshVtxVar
						, std::static_pointer_cast< ast::type::IOStruct >( structType )
						, ast::type::UnknownArraySize
						, true );
				}

				type = m_meshPrimType->getType();

				if ( isStructType( type ) )
				{
					auto structType = getStructType( type );
					assert( structType->isShaderOutput() );
					doProcessOutput( m_meshPrimVar
						, std::static_pointer_cast< ast::type::IOStruct >( structType )
						, ast::type::UnknownArraySize
						, true );
				}
			}


		private:
			ast::type::TypesCache & m_typesCache;
			AdaptationData & m_adaptationData;
			ast::stmt::ContainerPtr m_entryPointFinish{};
			ast::stmt::Container * m_globalsCont{};
			ast::UnorderedStringSet m_declaredStructs{};
			uint32_t m_maxPoint{};
			uint32_t m_maxPrimitives{};
			ast::type::InputLayout m_inputLayout{};
			ast::type::TypePtr m_inPerVertex{};
			ast::type::TypePtr m_outPerVertex{};
			ast::type::TypePtr m_inPerPrimitive{};
			ast::type::TypePtr m_outPerPrimitive{};
			ast::var::VariablePtr m_meshVtxVar{};
			ast::type::MeshVertexOutput const * m_meshVtxType{};
			ast::var::VariablePtr m_meshPrimVar{};
			ast::type::MeshPrimitiveOutput const * m_meshPrimType{};
			bool m_inPCB{};
		};
	}

	ast::stmt::ContainerPtr adaptStatements( ast::stmt::StmtCache & stmtCache
		, ast::expr::ExprCache & exprCache
		, ast::type::TypesCache & typesCache
		, ast::stmt::Container const & container
		, AdaptationData & adaptationData )
	{
		return adapt::StmtAdapter::submit( stmtCache
			, exprCache
			, typesCache
			, container
			, adaptationData );
	}
}
