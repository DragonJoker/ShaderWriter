/*
See LICENSE file in root folder
*/
#include "ShaderAST/Visitors/ResolveConstants.hpp"

#include "ShaderAST/Expr/ExprCompositeConstruct.hpp"
#include "ShaderAST/Expr/ExprLiteral.hpp"
#include "ShaderAST/Expr/ExprVisitor.hpp"
#include "ShaderAST/Stmt/StmtCache.hpp"
#include "ShaderAST/Visitors/CloneExpr.hpp"
#include "ShaderAST/Visitors/CloneStmt.hpp"
#include "ShaderAST/Visitors/SimplifyStatements.hpp"

#include <cmath>

namespace ast
{
	namespace constants
	{
		namespace helpers
		{
			static uint32_t getLiteralIndex( expr::Literal const & lit )
			{
				assert( lit.getLiteralType() == expr::LiteralType::eInt8
					|| lit.getLiteralType() == expr::LiteralType::eInt16
					|| lit.getLiteralType() == expr::LiteralType::eInt32
					|| lit.getLiteralType() == expr::LiteralType::eInt64
					|| lit.getLiteralType() == expr::LiteralType::eUInt8
					|| lit.getLiteralType() == expr::LiteralType::eUInt16
					|| lit.getLiteralType() == expr::LiteralType::eUInt32
					|| lit.getLiteralType() == expr::LiteralType::eUInt64 );
				uint32_t result{};

				if ( lit.getLiteralType() == expr::LiteralType::eInt8 )
				{
					result = uint32_t( lit.getValue< expr::LiteralType::eInt8 >() );
				}
				else if ( lit.getLiteralType() == expr::LiteralType::eInt16 )
				{
					result = uint16_t( lit.getValue< expr::LiteralType::eInt16 >() );
				}
				else if ( lit.getLiteralType() == expr::LiteralType::eInt32 )
				{
					result = uint32_t( lit.getValue< expr::LiteralType::eInt32 >() );
				}
				else if ( lit.getLiteralType() == expr::LiteralType::eInt64 )
				{
					result = uint32_t( lit.getValue< expr::LiteralType::eInt64 >() );
				}
				else if ( lit.getLiteralType() == expr::LiteralType::eUInt8 )
				{
					result = lit.getValue< expr::LiteralType::eUInt8 >();
				}
				else if ( lit.getLiteralType() == expr::LiteralType::eUInt16 )
				{
					result = lit.getValue< expr::LiteralType::eUInt16 >();
				}
				else if ( lit.getLiteralType() == expr::LiteralType::eUInt32 )
				{
					result = lit.getValue< expr::LiteralType::eUInt32 >();
				}
				else
				{
					result = uint32_t( lit.getValue< expr::LiteralType::eUInt64 >() );
				}

				return result;
			}

			static expr::LiteralType getLiteralType( type::Type const & type )
			{
				type::Kind kind = type.getKind();

				switch ( kind )
				{
				case type::Kind::eBoolean:
					return expr::LiteralType::eBool;
				case type::Kind::eInt8:
					return expr::LiteralType::eInt8;
				case type::Kind::eInt16:
					return expr::LiteralType::eInt16;
				case type::Kind::eInt32:
					return expr::LiteralType::eInt32;
				case type::Kind::eInt64:
					return expr::LiteralType::eInt64;
				case type::Kind::eUInt8:
					return expr::LiteralType::eUInt8;
				case type::Kind::eUInt16:
					return expr::LiteralType::eUInt16;
				case type::Kind::eUInt32:
					return expr::LiteralType::eUInt32;
				case type::Kind::eUInt64:
					return expr::LiteralType::eUInt64;
				case type::Kind::eFloat:
					return expr::LiteralType::eFloat;
				case type::Kind::eDouble:
					return expr::LiteralType::eDouble;
				default:
					AST_Failure( "Unsupported kind for a literal" );
					return expr::LiteralType::eFloat;
				}
			}

			static bool needsVariableDecl( var::VariablePtr variable
				, stmt::Container * scope )
			{
				class ExprVisitor
					: public ast::expr::SimpleVisitor
				{
				public:
					static void submit( var::VariablePtr variable
						, ast::expr::Expr * expr
						, bool & result )
					{
						ExprVisitor vis{ variable, result };
						expr->accept( &vis );
					}

				private:
					explicit ExprVisitor( var::VariablePtr variable
						, bool & result )
						: m_variable{ variable }
						, m_result{ result }
					{
					}

				private:
					void visitUnaryExpr( ast::expr::Unary * expr )override
					{
						expr->getOperand()->accept( this );
					}

					void visitBinaryExpr( ast::expr::Binary * expr )override
					{
						expr->getLHS()->accept( this );
						expr->getRHS()->accept( this );
					}

					void visitArrayAccessExpr( ast::expr::ArrayAccess* expr )override
					{
						if ( expr->getLHS()->getKind() == expr::Kind::eIdentifier
							&& static_cast< expr::Identifier const & >( *expr->getLHS() ).getVariable()->getId() == m_variable->getId() )
						{
							m_result = expr->getRHS()->getKind() != expr::Kind::eLiteral;
						}
						else
						{
							expr->getLHS()->accept( this );
							expr->getRHS()->accept( this );
						}
					}

					void visitAggrInitExpr( ast::expr::AggrInit * expr )override
					{
						if ( expr->getIdentifier() )
						{
							expr->getIdentifier()->accept( this );
						}

						for ( auto & arg : expr->getInitialisers() )
						{
							arg->accept( this );
						}
					}

					void visitCompositeConstructExpr( ast::expr::CompositeConstruct * expr )override
					{
						for ( auto & arg : expr->getArgList() )
						{
							arg->accept( this );
						}
					}

					void visitMbrSelectExpr( ast::expr::MbrSelect * expr )override
					{
						expr->getOuterExpr()->accept( this );
					}

					void visitFnCallExpr( ast::expr::FnCall * expr )override
					{
						expr->getFn()->accept( this );

						for ( auto & arg : expr->getArgList() )
						{
							arg->accept( this );
						}
					}

					void visitIntrinsicCallExpr( ast::expr::IntrinsicCall * expr )override
					{
						for ( auto & arg : expr->getArgList() )
						{
							arg->accept( this );
						}
					}

					void visitCombinedImageAccessCallExpr( ast::expr::CombinedImageAccessCall * expr )override
					{
						for ( auto & arg : expr->getArgList() )
						{
							arg->accept( this );
						}
					}

					void visitImageAccessCallExpr( ast::expr::StorageImageAccessCall * expr )override
					{
						for ( auto & arg : expr->getArgList() )
						{
							arg->accept( this );
						}
					}

					void visitIdentifierExpr( ast::expr::Identifier * expr )override
					{
					}

					void visitInitExpr( ast::expr::Init * expr )override
					{
						expr->getIdentifier()->accept( this );
						expr->getInitialiser()->accept( this );
					}

					void visitLiteralExpr( ast::expr::Literal * expr )override
					{
					}

					void visitQuestionExpr( ast::expr::Question * expr )override
					{
						expr->getCtrlExpr()->accept( this );
						expr->getTrueExpr()->accept( this );
						expr->getFalseExpr()->accept( this );
					}

					void visitStreamAppendExpr( ast::expr::StreamAppend * expr )override
					{
						expr->getOperand()->accept( this );
					}

					void visitSwitchCaseExpr( ast::expr::SwitchCase * expr )override
					{
						expr->getLabel()->accept( this );
					}

					void visitSwitchTestExpr( ast::expr::SwitchTest * expr )override
					{
						expr->getValue()->accept( this );
					}

					void visitSwizzleExpr( ast::expr::Swizzle * expr )override
					{
						expr->getOuterExpr()->accept( this );
					}

				private:
					var::VariablePtr m_variable;
					bool & m_result;
				};

				class StmtVisitor
					: public ast::stmt::Visitor
				{
				public:
					static bool submit(var::VariablePtr variable
						, ast::stmt::Container * stmt )
					{
						bool result{ false };
						StmtVisitor vis{ variable, result };
						stmt->accept( &vis );
						return result;
					}

				private:
					StmtVisitor( var::VariablePtr variable
						, bool & result )
						: m_variable{ variable }
						, m_result{ result }
					{
					}
					void visitAccelerationStructureDeclStmt( stmt::AccelerationStructureDecl * stmt )override
					{
					}
					void visitBreakStmt( stmt::Break * stmt )override
					{
					}
					void visitBufferReferenceDeclStmt( stmt::BufferReferenceDecl * stmt )override
					{
					}
					void visitCommentStmt( stmt::Comment * stmt )override
					{
					}
					void visitCompoundStmt( stmt::Compound * stmt )override
					{
						visitContainerStmt( stmt );
					}
					void visitContainerStmt( stmt::Container * stmt )override
					{
						for ( auto & sub : *stmt )
						{
							sub->accept( this );
						}
					}
					void visitContinueStmt( stmt::Continue * stmt )override
					{
					}
					void visitConstantBufferDeclStmt( stmt::ConstantBufferDecl * stmt )override
					{
					}
					void visitDemoteStmt( stmt::Demote * stmt )override
					{
					}
					void visitDispatchMeshStmt( stmt::DispatchMesh * stmt )override
					{
					}
					void visitTerminateInvocationStmt( stmt::TerminateInvocation * stmt )override
					{
					}
					void visitDoWhileStmt( stmt::DoWhile * stmt )override
					{
						if ( stmt->getCtrlExpr() )
						{
							ExprVisitor::submit( m_variable, stmt->getCtrlExpr(), m_result );
						}

						visitContainerStmt( stmt );
					}
					void visitElseIfStmt( stmt::ElseIf * stmt )override
					{
						if ( stmt->getCtrlExpr() )
						{
							ExprVisitor::submit( m_variable, stmt->getCtrlExpr(), m_result );
						}

						visitContainerStmt( stmt );
					}
					void visitElseStmt( stmt::Else * stmt )override
					{
						visitContainerStmt( stmt );
					}
					void visitForStmt( stmt::For * stmt )override
					{
						if ( stmt->getCtrlExpr() )
						{
							ExprVisitor::submit( m_variable, stmt->getCtrlExpr(), m_result );
						}

						if ( stmt->getInitExpr() )
						{
							ExprVisitor::submit( m_variable, stmt->getInitExpr(), m_result );
						}

						visitContainerStmt( stmt );
					}
					void visitFragmentLayoutStmt( stmt::FragmentLayout * stmt )override
					{
					}
					void visitFunctionDeclStmt( stmt::FunctionDecl * stmt )override
					{
						visitContainerStmt( stmt );
					}
					void visitHitAttributeVariableDeclStmt( stmt::HitAttributeVariableDecl * stmt )override
					{
					}
					void visitIfStmt( stmt::If * stmt )override
					{
						if ( stmt->getCtrlExpr() )
						{
							ExprVisitor::submit( m_variable, stmt->getCtrlExpr(), m_result );
						}

						visitContainerStmt( stmt );
					}
					void visitImageDeclStmt( stmt::ImageDecl * stmt )override
					{
					}
					void visitIgnoreIntersectionStmt( stmt::IgnoreIntersection * stmt )override
					{
					}
					void visitInOutCallableDataVariableDeclStmt( stmt::InOutCallableDataVariableDecl * stmt )override
					{
					}
					void visitInOutRayPayloadVariableDeclStmt( stmt::InOutRayPayloadVariableDecl * stmt )override
					{
					}
					void visitInOutVariableDeclStmt( stmt::InOutVariableDecl * stmt )override
					{
					}
					void visitInputComputeLayoutStmt( stmt::InputComputeLayout * stmt )override
					{
					}
					void visitInputGeometryLayoutStmt( stmt::InputGeometryLayout * stmt )override
					{
					}
					void visitInputTessellationEvaluationLayoutStmt( stmt::InputTessellationEvaluationLayout * stmt )override
					{
					}
					void visitOutputGeometryLayoutStmt( stmt::OutputGeometryLayout * stmt )override
					{
					}
					void visitOutputMeshLayoutStmt( stmt::OutputMeshLayout * stmt )override
					{
					}
					void visitOutputTessellationControlLayoutStmt( stmt::OutputTessellationControlLayout * stmt )override
					{
					}
					void visitPerPrimitiveDeclStmt( stmt::PerPrimitiveDecl * stmt )override
					{
					}
					void visitPerVertexDeclStmt( stmt::PerVertexDecl * stmt )override
					{
					}
					void visitPushConstantsBufferDeclStmt( stmt::PushConstantsBufferDecl * stmt )override
					{
						visitContainerStmt( stmt );
					}
					void visitReturnStmt( stmt::Return * stmt )override
					{
						if ( stmt->getExpr() )
						{
							ExprVisitor::submit( m_variable, stmt->getExpr(), m_result );
						}
					}
					void visitCombinedImageDeclStmt( stmt::CombinedImageDecl * stmt )override
					{
					}
					void visitSampledImageDeclStmt( stmt::SampledImageDecl * stmt )override
					{
					}
					void visitSamplerDeclStmt( stmt::SamplerDecl * stmt )override
					{
					}
					void visitShaderBufferDeclStmt( stmt::ShaderBufferDecl * stmt )override
					{
						visitContainerStmt( stmt );
					}
					void visitShaderStructBufferDeclStmt( stmt::ShaderStructBufferDecl * stmt )override
					{
					}
					void visitSimpleStmt( stmt::Simple * stmt )override
					{
						if ( !m_result )
						{
							ExprVisitor::submit( m_variable, stmt->getExpr(), m_result );
						}
					}
					void visitSpecialisationConstantDeclStmt( stmt::SpecialisationConstantDecl * stmt )override
					{
					}
					void visitStructureDeclStmt( stmt::StructureDecl * stmt )override
					{
					}
					void visitSwitchCaseStmt( stmt::SwitchCase * stmt )override
					{
						if ( stmt->getCaseExpr() )
						{
							ExprVisitor::submit( m_variable, stmt->getCaseExpr(), m_result );
						}

						visitContainerStmt( stmt );
					}
					void visitSwitchStmt( stmt::Switch * stmt )override
					{
						if ( stmt->getTestExpr() )
						{
							ExprVisitor::submit( m_variable, stmt->getTestExpr(), m_result );
						}

						visitContainerStmt( stmt );
					}
					void visitTerminateRayStmt( stmt::TerminateRay * stmt )override
					{
					}
					void visitVariableDeclStmt( stmt::VariableDecl * stmt )override
					{
					}
					void visitWhileStmt( stmt::While * stmt )override
					{
						if ( stmt->getCtrlExpr() )
						{
							ExprVisitor::submit( m_variable, stmt->getCtrlExpr(), m_result );
						}

						visitContainerStmt( stmt );
					}
					void visitPreprocExtension( stmt::PreprocExtension * stmt )override
					{
					}
					void visitPreprocVersion( stmt::PreprocVersion * stmt )override
					{
					}

				private:
					var::VariablePtr m_variable;
					bool & m_result;
				};
				return StmtVisitor::submit( variable, scope );
			}
/*
			template< typename ValueT > struct ValueTraitsT;
			template<> struct ValueTraitsT< bool >
			{
				static constexpr expr::LiteralType literal = expr::LiteralType::eBool;
				static constexpr type::Kind kind = type::Kind::eBoolean;
			};
			template<> struct ValueTraitsT< int8_t >
			{
				static constexpr expr::LiteralType literal = expr::LiteralType::eInt8;
				static constexpr type::Kind kind = type::Kind::eInt8;
			};
			template<> struct ValueTraitsT< int16_t >
			{
				static constexpr expr::LiteralType literal = expr::LiteralType::eInt16;
				static constexpr type::Kind kind = type::Kind::eInt16;
			};
			template<> struct ValueTraitsT< int32_t >
			{
				static constexpr expr::LiteralType literal = expr::LiteralType::eInt32;
				static constexpr type::Kind kind = type::Kind::eInt32;
			};
			template<> struct ValueTraitsT< int64_t >
			{
				static constexpr expr::LiteralType literal = expr::LiteralType::eInt64;
				static constexpr type::Kind kind = type::Kind::eInt64;
			};
			template<> struct ValueTraitsT< uint8_t >
			{
				static constexpr expr::LiteralType literal = expr::LiteralType::eUInt8;
				static constexpr type::Kind kind = type::Kind::eUInt8;
			};
			template<> struct ValueTraitsT< uint16_t >
			{
				static constexpr expr::LiteralType literal = expr::LiteralType::eUInt16;
				static constexpr type::Kind kind = type::Kind::eUInt16;
			};
			template<> struct ValueTraitsT< uint32_t >
			{
				static constexpr expr::LiteralType literal = expr::LiteralType::eUInt32;
				static constexpr type::Kind kind = type::Kind::eUInt32;
			};
			template<> struct ValueTraitsT< uint64_t >
			{
				static constexpr expr::LiteralType literal = expr::LiteralType::eUInt64;
				static constexpr type::Kind kind = type::Kind::eUInt64;
			};
			template<> struct ValueTraitsT< float >
			{
				static constexpr expr::LiteralType literal = expr::LiteralType::eFloat;
				static constexpr type::Kind kind = type::Kind::eFloat;
			};
			template<> struct ValueTraitsT< double >
			{
				static constexpr expr::LiteralType literal = expr::LiteralType::eDouble;
				static constexpr type::Kind kind = type::Kind::eDouble;
			};
			template< typename ValueT > static constexpr type::Kind kindT = ValueTraitsT< ValueT >::kind;
			template< typename ValueT > static constexpr expr::LiteralType literalT = ValueTraitsT< ValueT >::literal;

			template< typename ValueT, size_t CountT >
			using DataT = std::array< ValueT, CountT >;

			template< typename ValueT, size_t CountT >
			DataT< ValueT, CountT > getData( expr::ExprList const & args )
			{
				DataT< ValueT, CountT > result{};

				switch ( CountT )
				{
				case 1u:
					return DataT< ValueT, 1u >{ static_cast< expr::Literal const & >( arg.front() ).getValue< literalT< ValueT > >() };
				case 2u:
				case 3u:
				case 4u:
				default:
					break;
				}

				return result;
			}

			template< typename ValueT, size_t CountT, typename FuncT >
			DataT< ValueT, CountT > processT( expr::ExprCache & exprCache
				, DataT< ValueT, CountT > args
				, FuncT func )
			{
				DataT< ValueT, CountT > result;
				auto itDst = result.begin();
				auto itSrc = args.begin();

				while ( itSrc != args.end() )
				{
					*itDst = func( *itSrc );
					++itSrc;
					++itDst;
				}

				return result;
			}

			expr::ExprList makeList( expr::ExprPtr arg0
				, expr::ExprPtr arg1 )
			{
				expr::ExprList result;
				result.push_back( std::move( arg0 ) );
				result.push_back( std::move( arg1 ) );
				return result;
			}

			expr::ExprList makeList( expr::ExprPtr arg0
				, expr::ExprPtr arg1
				, expr::ExprPtr arg2 )
			{
				expr::ExprList result;
				result.push_back( std::move( arg0 ) );
				result.push_back( std::move( arg1 ) );
				result.push_back( std::move( arg2 ) );
				return result;
			}

			expr::ExprList makeList( expr::ExprPtr arg0
				, expr::ExprPtr arg1
				, expr::ExprPtr arg2
				, expr::ExprPtr arg3 )
			{
				expr::ExprList result;
				result.push_back( std::move( arg0 ) );
				result.push_back( std::move( arg1 ) );
				result.push_back( std::move( arg2 ) );
				result.push_back( std::move( arg3 ) );
				return result;
			}

			template< typename ValueT, size_t CountT, typename FuncT >
			expr::ExprPtr applyT( type::TypesCache & typesCache
				, expr::ExprCache & exprCache
				, DataT< ValueT, CountT > args
				, FuncT func )
			{
				DataT< ValueT, CountT > result = processT( exprCache, std::move( args ), func );

				switch ( CountT )
				{
				case 1u:
					return exprCache.makeLiteral( typesCache, result.front() );
				case 2u:
					return exprCache.makeCompositeConstruct( expr::CompositeType::eVec2
						, kindT< ValueT >
						, makeList( exprCache.makeLiteral( typesCache, result[0] )
							, exprCache.makeLiteral( typesCache, result[1] ) ) );
				case 3u:
					return exprCache.makeCompositeConstruct( expr::CompositeType::eVec3
						, kindT< ValueT >
						, makeList( exprCache.makeLiteral( typesCache, result[0] )
							, exprCache.makeLiteral( typesCache, result[1] )
							, exprCache.makeLiteral( typesCache, result[2] ) ) );
				case 4u:
					return exprCache.makeCompositeConstruct( expr::CompositeType::eVec4
						, kindT< ValueT >
						, makeList( exprCache.makeLiteral( typesCache, result[0] )
							, exprCache.makeLiteral( typesCache, result[1] )
							, exprCache.makeLiteral( typesCache, result[2] )
							, exprCache.makeLiteral( typesCache, result[3] ) ) );
				default:
					return nullptr;
				}
			}

			float toDegrees( float radians )
			{
				return float( radians * 180.0f / 3.14159265358979323846 );
			}

			float toRadians( float degrees )
			{
				return float( degrees * 3.14159265358979323846 / 180.0f );
			}

			expr::ExprPtr degrees( type::TypesCache & typesCache
				, expr::ExprCache & exprCache
				, expr::ExprList args )
			{
				switch ( type::getComponentCount( arg->getType() ) )
				{
				case 1u: return applyT( typesCache, exprCache, getData< float, 1u >( args ), toDegrees );
				case 2u: return applyT( typesCache, exprCache, getData< float, 2u >( args ), toDegrees );
				case 3u: return applyT( typesCache, exprCache, getData< float, 3u >( args ), toDegrees );
				case 4u: return applyT( typesCache, exprCache, getData< float, 4u >( args ), toDegrees );
				default: return nullptr;
				}
			}

			bool isConstantResolvable( expr::Intrinsic intrinsic )
			{
				switch ( intrinsic )
				{
				case ast::expr::Intrinsic::eDegrees1:
				case ast::expr::Intrinsic::eDegrees2:
				case ast::expr::Intrinsic::eDegrees3:
				case ast::expr::Intrinsic::eDegrees4:
				case ast::expr::Intrinsic::eRadians1F:
				case ast::expr::Intrinsic::eRadians2F:
				case ast::expr::Intrinsic::eRadians3F:
				case ast::expr::Intrinsic::eRadians4F:
				case ast::expr::Intrinsic::eCos1:
				case ast::expr::Intrinsic::eCos2:
				case ast::expr::Intrinsic::eCos3:
				case ast::expr::Intrinsic::eCos4:
				case ast::expr::Intrinsic::eSin1:
				case ast::expr::Intrinsic::eSin2:
				case ast::expr::Intrinsic::eSin3:
				case ast::expr::Intrinsic::eSin4:
				case ast::expr::Intrinsic::eTan1:
				case ast::expr::Intrinsic::eTan2:
				case ast::expr::Intrinsic::eTan3:
				case ast::expr::Intrinsic::eTan4:
				case ast::expr::Intrinsic::eCosh1:
				case ast::expr::Intrinsic::eCosh2:
				case ast::expr::Intrinsic::eCosh3:
				case ast::expr::Intrinsic::eCosh4:
				case ast::expr::Intrinsic::eSinh1:
				case ast::expr::Intrinsic::eSinh2:
				case ast::expr::Intrinsic::eSinh3:
				case ast::expr::Intrinsic::eSinh4:
				case ast::expr::Intrinsic::eTanh1:
				case ast::expr::Intrinsic::eTanh2:
				case ast::expr::Intrinsic::eTanh3:
				case ast::expr::Intrinsic::eTanh4:
				case ast::expr::Intrinsic::eAcos1:
				case ast::expr::Intrinsic::eAcos2:
				case ast::expr::Intrinsic::eAcos3:
				case ast::expr::Intrinsic::eAcos4:
				case ast::expr::Intrinsic::eAsin1:
				case ast::expr::Intrinsic::eAsin2:
				case ast::expr::Intrinsic::eAsin3:
				case ast::expr::Intrinsic::eAsin4:
				case ast::expr::Intrinsic::eAtan1:
				case ast::expr::Intrinsic::eAtan2:
				case ast::expr::Intrinsic::eAtan3:
				case ast::expr::Intrinsic::eAtan4:
				case ast::expr::Intrinsic::eAtan21:
				case ast::expr::Intrinsic::eAtan22:
				case ast::expr::Intrinsic::eAtan23:
				case ast::expr::Intrinsic::eAtan24:
				case ast::expr::Intrinsic::eAcosh1:
				case ast::expr::Intrinsic::eAcosh2:
				case ast::expr::Intrinsic::eAcosh3:
				case ast::expr::Intrinsic::eAcosh4:
				case ast::expr::Intrinsic::eAsinh1:
				case ast::expr::Intrinsic::eAsinh2:
				case ast::expr::Intrinsic::eAsinh3:
				case ast::expr::Intrinsic::eAsinh4:
				case ast::expr::Intrinsic::eAtanh1:
				case ast::expr::Intrinsic::eAtanh2:
				case ast::expr::Intrinsic::eAtanh3:
				case ast::expr::Intrinsic::eAtanh4:
				case ast::expr::Intrinsic::ePow1:
				case ast::expr::Intrinsic::ePow2:
				case ast::expr::Intrinsic::ePow3:
				case ast::expr::Intrinsic::ePow4:
				case ast::expr::Intrinsic::eExp1:
				case ast::expr::Intrinsic::eExp2:
				case ast::expr::Intrinsic::eExp3:
				case ast::expr::Intrinsic::eExp4:
				case ast::expr::Intrinsic::eLog1:
				case ast::expr::Intrinsic::eLog2:
				case ast::expr::Intrinsic::eLog3:
				case ast::expr::Intrinsic::eLog4:
				case ast::expr::Intrinsic::eExp21:
				case ast::expr::Intrinsic::eExp22:
				case ast::expr::Intrinsic::eExp23:
				case ast::expr::Intrinsic::eExp24:
				case ast::expr::Intrinsic::eLog21:
				case ast::expr::Intrinsic::eLog22:
				case ast::expr::Intrinsic::eLog23:
				case ast::expr::Intrinsic::eLog24:
				case ast::expr::Intrinsic::eSqrt1F:
				case ast::expr::Intrinsic::eSqrt2F:
				case ast::expr::Intrinsic::eSqrt3F:
				case ast::expr::Intrinsic::eSqrt4F:
				case ast::expr::Intrinsic::eSqrt1D:
				case ast::expr::Intrinsic::eSqrt2D:
				case ast::expr::Intrinsic::eSqrt3D:
				case ast::expr::Intrinsic::eSqrt4D:
				case ast::expr::Intrinsic::eInverseSqrt1F:
				case ast::expr::Intrinsic::eInverseSqrt2F:
				case ast::expr::Intrinsic::eInverseSqrt3F:
				case ast::expr::Intrinsic::eInverseSqrt4F:
				case ast::expr::Intrinsic::eInverseSqrt1D:
				case ast::expr::Intrinsic::eInverseSqrt2D:
				case ast::expr::Intrinsic::eInverseSqrt3D:
				case ast::expr::Intrinsic::eInverseSqrt4D:
				case ast::expr::Intrinsic::eAbs1F:
				case ast::expr::Intrinsic::eAbs2F:
				case ast::expr::Intrinsic::eAbs3F:
				case ast::expr::Intrinsic::eAbs4F:
				case ast::expr::Intrinsic::eAbs1I:
				case ast::expr::Intrinsic::eAbs2I:
				case ast::expr::Intrinsic::eAbs3I:
				case ast::expr::Intrinsic::eAbs4I:
				case ast::expr::Intrinsic::eAbs1D:
				case ast::expr::Intrinsic::eAbs2D:
				case ast::expr::Intrinsic::eAbs3D:
				case ast::expr::Intrinsic::eAbs4D:
				case ast::expr::Intrinsic::eSign1F:
				case ast::expr::Intrinsic::eSign2F:
				case ast::expr::Intrinsic::eSign3F:
				case ast::expr::Intrinsic::eSign4F:
				case ast::expr::Intrinsic::eSign1I:
				case ast::expr::Intrinsic::eSign2I:
				case ast::expr::Intrinsic::eSign3I:
				case ast::expr::Intrinsic::eSign4I:
				case ast::expr::Intrinsic::eSign1D:
				case ast::expr::Intrinsic::eSign2D:
				case ast::expr::Intrinsic::eSign3D:
				case ast::expr::Intrinsic::eSign4D:
				case ast::expr::Intrinsic::eFloor1F:
				case ast::expr::Intrinsic::eFloor2F:
				case ast::expr::Intrinsic::eFloor3F:
				case ast::expr::Intrinsic::eFloor4F:
				case ast::expr::Intrinsic::eFloor1D:
				case ast::expr::Intrinsic::eFloor2D:
				case ast::expr::Intrinsic::eFloor3D:
				case ast::expr::Intrinsic::eFloor4D:
				case ast::expr::Intrinsic::eTrunc1F:
				case ast::expr::Intrinsic::eTrunc2F:
				case ast::expr::Intrinsic::eTrunc3F:
				case ast::expr::Intrinsic::eTrunc4F:
				case ast::expr::Intrinsic::eTrunc1D:
				case ast::expr::Intrinsic::eTrunc2D:
				case ast::expr::Intrinsic::eTrunc3D:
				case ast::expr::Intrinsic::eTrunc4D:
				case ast::expr::Intrinsic::eRound1F:
				case ast::expr::Intrinsic::eRound2F:
				case ast::expr::Intrinsic::eRound3F:
				case ast::expr::Intrinsic::eRound4F:
				case ast::expr::Intrinsic::eRound1D:
				case ast::expr::Intrinsic::eRound2D:
				case ast::expr::Intrinsic::eRound3D:
				case ast::expr::Intrinsic::eRound4D:
				case ast::expr::Intrinsic::eRoundEven1F:
				case ast::expr::Intrinsic::eRoundEven2F:
				case ast::expr::Intrinsic::eRoundEven3F:
				case ast::expr::Intrinsic::eRoundEven4F:
				case ast::expr::Intrinsic::eRoundEven1D:
				case ast::expr::Intrinsic::eRoundEven2D:
				case ast::expr::Intrinsic::eRoundEven3D:
				case ast::expr::Intrinsic::eRoundEven4D:
				case ast::expr::Intrinsic::eCeil1F:
				case ast::expr::Intrinsic::eCeil2F:
				case ast::expr::Intrinsic::eCeil3F:
				case ast::expr::Intrinsic::eCeil4F:
				case ast::expr::Intrinsic::eCeil1D:
				case ast::expr::Intrinsic::eCeil2D:
				case ast::expr::Intrinsic::eCeil3D:
				case ast::expr::Intrinsic::eCeil4D:
				case ast::expr::Intrinsic::eFract1F:
				case ast::expr::Intrinsic::eFract2F:
				case ast::expr::Intrinsic::eFract3F:
				case ast::expr::Intrinsic::eFract4F:
				case ast::expr::Intrinsic::eFract1D:
				case ast::expr::Intrinsic::eFract2D:
				case ast::expr::Intrinsic::eFract3D:
				case ast::expr::Intrinsic::eFract4D:
				case ast::expr::Intrinsic::eMod1F:
				case ast::expr::Intrinsic::eMod2F:
				case ast::expr::Intrinsic::eMod3F:
				case ast::expr::Intrinsic::eMod4F:
				case ast::expr::Intrinsic::eMod1D:
				case ast::expr::Intrinsic::eMod2D:
				case ast::expr::Intrinsic::eMod3D:
				case ast::expr::Intrinsic::eMod4D:
				case ast::expr::Intrinsic::eModf1F:
				case ast::expr::Intrinsic::eModf2F:
				case ast::expr::Intrinsic::eModf3F:
				case ast::expr::Intrinsic::eModf4F:
				case ast::expr::Intrinsic::eModf1D:
				case ast::expr::Intrinsic::eModf2D:
				case ast::expr::Intrinsic::eModf3D:
				case ast::expr::Intrinsic::eModf4D:
				case ast::expr::Intrinsic::eMin1F:
				case ast::expr::Intrinsic::eMin2F:
				case ast::expr::Intrinsic::eMin3F:
				case ast::expr::Intrinsic::eMin4F:
				case ast::expr::Intrinsic::eMin1D:
				case ast::expr::Intrinsic::eMin2D:
				case ast::expr::Intrinsic::eMin3D:
				case ast::expr::Intrinsic::eMin4D:
				case ast::expr::Intrinsic::eMin1I:
				case ast::expr::Intrinsic::eMin2I:
				case ast::expr::Intrinsic::eMin3I:
				case ast::expr::Intrinsic::eMin4I:
				case ast::expr::Intrinsic::eMin1U:
				case ast::expr::Intrinsic::eMin2U:
				case ast::expr::Intrinsic::eMin3U:
				case ast::expr::Intrinsic::eMin4U:
				case ast::expr::Intrinsic::eMax1F:
				case ast::expr::Intrinsic::eMax2F:
				case ast::expr::Intrinsic::eMax3F:
				case ast::expr::Intrinsic::eMax4F:
				case ast::expr::Intrinsic::eMax1D:
				case ast::expr::Intrinsic::eMax2D:
				case ast::expr::Intrinsic::eMax3D:
				case ast::expr::Intrinsic::eMax4D:
				case ast::expr::Intrinsic::eMax1I:
				case ast::expr::Intrinsic::eMax2I:
				case ast::expr::Intrinsic::eMax3I:
				case ast::expr::Intrinsic::eMax4I:
				case ast::expr::Intrinsic::eMax1U:
				case ast::expr::Intrinsic::eMax2U:
				case ast::expr::Intrinsic::eMax3U:
				case ast::expr::Intrinsic::eMax4U:
				case ast::expr::Intrinsic::eClamp1F:
				case ast::expr::Intrinsic::eClamp2F:
				case ast::expr::Intrinsic::eClamp3F:
				case ast::expr::Intrinsic::eClamp4F:
				case ast::expr::Intrinsic::eClamp1D:
				case ast::expr::Intrinsic::eClamp2D:
				case ast::expr::Intrinsic::eClamp3D:
				case ast::expr::Intrinsic::eClamp4D:
				case ast::expr::Intrinsic::eClamp1I:
				case ast::expr::Intrinsic::eClamp2I:
				case ast::expr::Intrinsic::eClamp3I:
				case ast::expr::Intrinsic::eClamp4I:
				case ast::expr::Intrinsic::eClamp1U:
				case ast::expr::Intrinsic::eClamp2U:
				case ast::expr::Intrinsic::eClamp3U:
				case ast::expr::Intrinsic::eClamp4U:
				case ast::expr::Intrinsic::eMix1F:
				case ast::expr::Intrinsic::eMix2F:
				case ast::expr::Intrinsic::eMix3F:
				case ast::expr::Intrinsic::eMix4F:
				case ast::expr::Intrinsic::eMix1D:
				case ast::expr::Intrinsic::eMix2D:
				case ast::expr::Intrinsic::eMix3D:
				case ast::expr::Intrinsic::eMix4D:
				case ast::expr::Intrinsic::eStep1F:
				case ast::expr::Intrinsic::eStep2F:
				case ast::expr::Intrinsic::eStep3F:
				case ast::expr::Intrinsic::eStep4F:
				case ast::expr::Intrinsic::eStep1D:
				case ast::expr::Intrinsic::eStep2D:
				case ast::expr::Intrinsic::eStep3D:
				case ast::expr::Intrinsic::eStep4D:
				case ast::expr::Intrinsic::eSmoothStep1F:
				case ast::expr::Intrinsic::eSmoothStep2F:
				case ast::expr::Intrinsic::eSmoothStep3F:
				case ast::expr::Intrinsic::eSmoothStep4F:
				case ast::expr::Intrinsic::eSmoothStep1D:
				case ast::expr::Intrinsic::eSmoothStep2D:
				case ast::expr::Intrinsic::eSmoothStep3D:
				case ast::expr::Intrinsic::eSmoothStep4D:
				case ast::expr::Intrinsic::eIsnan1F:
				case ast::expr::Intrinsic::eIsnan2F:
				case ast::expr::Intrinsic::eIsnan3F:
				case ast::expr::Intrinsic::eIsnan4F:
				case ast::expr::Intrinsic::eIsnan1D:
				case ast::expr::Intrinsic::eIsnan2D:
				case ast::expr::Intrinsic::eIsnan3D:
				case ast::expr::Intrinsic::eIsnan4D:
				case ast::expr::Intrinsic::eIsinf1F:
				case ast::expr::Intrinsic::eIsinf2F:
				case ast::expr::Intrinsic::eIsinf3F:
				case ast::expr::Intrinsic::eIsinf4F:
				case ast::expr::Intrinsic::eIsinf1D:
				case ast::expr::Intrinsic::eIsinf2D:
				case ast::expr::Intrinsic::eIsinf3D:
				case ast::expr::Intrinsic::eIsinf4D:
				case ast::expr::Intrinsic::eFma1F:
				case ast::expr::Intrinsic::eFma2F:
				case ast::expr::Intrinsic::eFma3F:
				case ast::expr::Intrinsic::eFma4F:
				case ast::expr::Intrinsic::eFma1D:
				case ast::expr::Intrinsic::eFma2D:
				case ast::expr::Intrinsic::eFma3D:
				case ast::expr::Intrinsic::eFma4D:
				case ast::expr::Intrinsic::eFrexp1F:
				case ast::expr::Intrinsic::eFrexp2F:
				case ast::expr::Intrinsic::eFrexp3F:
				case ast::expr::Intrinsic::eFrexp4F:
				case ast::expr::Intrinsic::eFrexp1D:
				case ast::expr::Intrinsic::eFrexp2D:
				case ast::expr::Intrinsic::eFrexp3D:
				case ast::expr::Intrinsic::eFrexp4D:
				case ast::expr::Intrinsic::eLdexp1F:
				case ast::expr::Intrinsic::eLdexp2F:
				case ast::expr::Intrinsic::eLdexp3F:
				case ast::expr::Intrinsic::eLdexp4F:
				case ast::expr::Intrinsic::eLdexp1D:
				case ast::expr::Intrinsic::eLdexp2D:
				case ast::expr::Intrinsic::eLdexp3D:
				case ast::expr::Intrinsic::eLdexp4D:
				case ast::expr::Intrinsic::eLength1F:
				case ast::expr::Intrinsic::eLength2F:
				case ast::expr::Intrinsic::eLength3F:
				case ast::expr::Intrinsic::eLength4F:
				case ast::expr::Intrinsic::eLength1D:
				case ast::expr::Intrinsic::eLength2D:
				case ast::expr::Intrinsic::eLength3D:
				case ast::expr::Intrinsic::eLength4D:
				case ast::expr::Intrinsic::eDistance1F:
				case ast::expr::Intrinsic::eDistance2F:
				case ast::expr::Intrinsic::eDistance3F:
				case ast::expr::Intrinsic::eDistance4F:
				case ast::expr::Intrinsic::eDistance1D:
				case ast::expr::Intrinsic::eDistance2D:
				case ast::expr::Intrinsic::eDistance3D:
				case ast::expr::Intrinsic::eDistance4D:
				case ast::expr::Intrinsic::eDot1F:
				case ast::expr::Intrinsic::eDot2F:
				case ast::expr::Intrinsic::eDot3F:
				case ast::expr::Intrinsic::eDot4F:
				case ast::expr::Intrinsic::eDot1D:
				case ast::expr::Intrinsic::eDot2D:
				case ast::expr::Intrinsic::eDot3D:
				case ast::expr::Intrinsic::eDot4D:
				case ast::expr::Intrinsic::eCrossF:
				case ast::expr::Intrinsic::eCrossD:
				case ast::expr::Intrinsic::eNormalize1F:
				case ast::expr::Intrinsic::eNormalize2F:
				case ast::expr::Intrinsic::eNormalize3F:
				case ast::expr::Intrinsic::eNormalize4F:
				case ast::expr::Intrinsic::eNormalize1D:
				case ast::expr::Intrinsic::eNormalize2D:
				case ast::expr::Intrinsic::eNormalize3D:
				case ast::expr::Intrinsic::eNormalize4D:
				case ast::expr::Intrinsic::eFaceForward1F:
				case ast::expr::Intrinsic::eFaceForward2F:
				case ast::expr::Intrinsic::eFaceForward3F:
				case ast::expr::Intrinsic::eFaceForward4F:
				case ast::expr::Intrinsic::eFaceForward1D:
				case ast::expr::Intrinsic::eFaceForward2D:
				case ast::expr::Intrinsic::eFaceForward3D:
				case ast::expr::Intrinsic::eFaceForward4D:
				case ast::expr::Intrinsic::eReflect1F:
				case ast::expr::Intrinsic::eReflect2F:
				case ast::expr::Intrinsic::eReflect3F:
				case ast::expr::Intrinsic::eReflect4F:
				case ast::expr::Intrinsic::eReflect1D:
				case ast::expr::Intrinsic::eReflect2D:
				case ast::expr::Intrinsic::eReflect3D:
				case ast::expr::Intrinsic::eReflect4D:
				case ast::expr::Intrinsic::eRefract1F:
				case ast::expr::Intrinsic::eRefract2F:
				case ast::expr::Intrinsic::eRefract3F:
				case ast::expr::Intrinsic::eRefract4F:
				case ast::expr::Intrinsic::eRefract1D:
				case ast::expr::Intrinsic::eRefract2D:
				case ast::expr::Intrinsic::eRefract3D:
				case ast::expr::Intrinsic::eRefract4D:
				case ast::expr::Intrinsic::eMatrixCompMult2x2F:
				case ast::expr::Intrinsic::eMatrixCompMult2x3F:
				case ast::expr::Intrinsic::eMatrixCompMult2x4F:
				case ast::expr::Intrinsic::eMatrixCompMult3x2F:
				case ast::expr::Intrinsic::eMatrixCompMult3x3F:
				case ast::expr::Intrinsic::eMatrixCompMult3x4F:
				case ast::expr::Intrinsic::eMatrixCompMult4x2F:
				case ast::expr::Intrinsic::eMatrixCompMult4x3F:
				case ast::expr::Intrinsic::eMatrixCompMult4x4F:
				case ast::expr::Intrinsic::eMatrixCompMult2x2D:
				case ast::expr::Intrinsic::eMatrixCompMult2x3D:
				case ast::expr::Intrinsic::eMatrixCompMult2x4D:
				case ast::expr::Intrinsic::eMatrixCompMult3x2D:
				case ast::expr::Intrinsic::eMatrixCompMult3x3D:
				case ast::expr::Intrinsic::eMatrixCompMult3x4D:
				case ast::expr::Intrinsic::eMatrixCompMult4x2D:
				case ast::expr::Intrinsic::eMatrixCompMult4x3D:
				case ast::expr::Intrinsic::eMatrixCompMult4x4D:
				case ast::expr::Intrinsic::eOuterProduct2x2F:
				case ast::expr::Intrinsic::eOuterProduct3x3F:
				case ast::expr::Intrinsic::eOuterProduct4x4F:
				case ast::expr::Intrinsic::eOuterProduct3x2F:
				case ast::expr::Intrinsic::eOuterProduct2x3F:
				case ast::expr::Intrinsic::eOuterProduct4x2F:
				case ast::expr::Intrinsic::eOuterProduct2x4F:
				case ast::expr::Intrinsic::eOuterProduct4x3F:
				case ast::expr::Intrinsic::eOuterProduct3x4F:
				case ast::expr::Intrinsic::eOuterProduct2x2D:
				case ast::expr::Intrinsic::eOuterProduct3x3D:
				case ast::expr::Intrinsic::eOuterProduct4x4D:
				case ast::expr::Intrinsic::eOuterProduct3x2D:
				case ast::expr::Intrinsic::eOuterProduct2x3D:
				case ast::expr::Intrinsic::eOuterProduct4x2D:
				case ast::expr::Intrinsic::eOuterProduct2x4D:
				case ast::expr::Intrinsic::eOuterProduct4x3D:
				case ast::expr::Intrinsic::eOuterProduct3x4D:
				case ast::expr::Intrinsic::eTranspose2x2F:
				case ast::expr::Intrinsic::eTranspose2x3F:
				case ast::expr::Intrinsic::eTranspose2x4F:
				case ast::expr::Intrinsic::eTranspose3x2F:
				case ast::expr::Intrinsic::eTranspose3x3F:
				case ast::expr::Intrinsic::eTranspose3x4F:
				case ast::expr::Intrinsic::eTranspose4x2F:
				case ast::expr::Intrinsic::eTranspose4x3F:
				case ast::expr::Intrinsic::eTranspose4x4F:
				case ast::expr::Intrinsic::eTranspose2x2D:
				case ast::expr::Intrinsic::eTranspose2x3D:
				case ast::expr::Intrinsic::eTranspose2x4D:
				case ast::expr::Intrinsic::eTranspose3x2D:
				case ast::expr::Intrinsic::eTranspose3x3D:
				case ast::expr::Intrinsic::eTranspose3x4D:
				case ast::expr::Intrinsic::eTranspose4x2D:
				case ast::expr::Intrinsic::eTranspose4x3D:
				case ast::expr::Intrinsic::eTranspose4x4D:
				case ast::expr::Intrinsic::eDeterminant2x2F:
				case ast::expr::Intrinsic::eDeterminant3x3F:
				case ast::expr::Intrinsic::eDeterminant4x4F:
				case ast::expr::Intrinsic::eDeterminant2x2D:
				case ast::expr::Intrinsic::eDeterminant3x3D:
				case ast::expr::Intrinsic::eDeterminant4x4D:
				case ast::expr::Intrinsic::eInverse2x2F:
				case ast::expr::Intrinsic::eInverse3x3F:
				case ast::expr::Intrinsic::eInverse4x4F:
				case ast::expr::Intrinsic::eInverse2x2D:
				case ast::expr::Intrinsic::eInverse3x3D:
				case ast::expr::Intrinsic::eInverse4x4D:
				case ast::expr::Intrinsic::eLessThan2F:
				case ast::expr::Intrinsic::eLessThan3F:
				case ast::expr::Intrinsic::eLessThan4F:
				case ast::expr::Intrinsic::eLessThan2D:
				case ast::expr::Intrinsic::eLessThan3D:
				case ast::expr::Intrinsic::eLessThan4D:
				case ast::expr::Intrinsic::eLessThan2I:
				case ast::expr::Intrinsic::eLessThan3I:
				case ast::expr::Intrinsic::eLessThan4I:
				case ast::expr::Intrinsic::eLessThan2U:
				case ast::expr::Intrinsic::eLessThan3U:
				case ast::expr::Intrinsic::eLessThan4U:
				case ast::expr::Intrinsic::eLessThanEqual2F:
				case ast::expr::Intrinsic::eLessThanEqual3F:
				case ast::expr::Intrinsic::eLessThanEqual4F:
				case ast::expr::Intrinsic::eLessThanEqual2D:
				case ast::expr::Intrinsic::eLessThanEqual3D:
				case ast::expr::Intrinsic::eLessThanEqual4D:
				case ast::expr::Intrinsic::eLessThanEqual2I:
				case ast::expr::Intrinsic::eLessThanEqual3I:
				case ast::expr::Intrinsic::eLessThanEqual4I:
				case ast::expr::Intrinsic::eLessThanEqual2U:
				case ast::expr::Intrinsic::eLessThanEqual3U:
				case ast::expr::Intrinsic::eLessThanEqual4U:
				case ast::expr::Intrinsic::eGreaterThan2F:
				case ast::expr::Intrinsic::eGreaterThan3F:
				case ast::expr::Intrinsic::eGreaterThan4F:
				case ast::expr::Intrinsic::eGreaterThan2D:
				case ast::expr::Intrinsic::eGreaterThan3D:
				case ast::expr::Intrinsic::eGreaterThan4D:
				case ast::expr::Intrinsic::eGreaterThan2I:
				case ast::expr::Intrinsic::eGreaterThan3I:
				case ast::expr::Intrinsic::eGreaterThan4I:
				case ast::expr::Intrinsic::eGreaterThan2U:
				case ast::expr::Intrinsic::eGreaterThan3U:
				case ast::expr::Intrinsic::eGreaterThan4U:
				case ast::expr::Intrinsic::eGreaterThanEqual2F:
				case ast::expr::Intrinsic::eGreaterThanEqual3F:
				case ast::expr::Intrinsic::eGreaterThanEqual4F:
				case ast::expr::Intrinsic::eGreaterThanEqual2D:
				case ast::expr::Intrinsic::eGreaterThanEqual3D:
				case ast::expr::Intrinsic::eGreaterThanEqual4D:
				case ast::expr::Intrinsic::eGreaterThanEqual2I:
				case ast::expr::Intrinsic::eGreaterThanEqual3I:
				case ast::expr::Intrinsic::eGreaterThanEqual4I:
				case ast::expr::Intrinsic::eGreaterThanEqual2U:
				case ast::expr::Intrinsic::eGreaterThanEqual3U:
				case ast::expr::Intrinsic::eGreaterThanEqual4U:
				case ast::expr::Intrinsic::eEqual2F:
				case ast::expr::Intrinsic::eEqual3F:
				case ast::expr::Intrinsic::eEqual4F:
				case ast::expr::Intrinsic::eEqual2D:
				case ast::expr::Intrinsic::eEqual3D:
				case ast::expr::Intrinsic::eEqual4D:
				case ast::expr::Intrinsic::eEqual2I:
				case ast::expr::Intrinsic::eEqual3I:
				case ast::expr::Intrinsic::eEqual4I:
				case ast::expr::Intrinsic::eEqual2U:
				case ast::expr::Intrinsic::eEqual3U:
				case ast::expr::Intrinsic::eEqual4U:
				case ast::expr::Intrinsic::eNotEqual2F:
				case ast::expr::Intrinsic::eNotEqual3F:
				case ast::expr::Intrinsic::eNotEqual4F:
				case ast::expr::Intrinsic::eNotEqual2D:
				case ast::expr::Intrinsic::eNotEqual3D:
				case ast::expr::Intrinsic::eNotEqual4D:
				case ast::expr::Intrinsic::eNotEqual2I:
				case ast::expr::Intrinsic::eNotEqual3I:
				case ast::expr::Intrinsic::eNotEqual4I:
				case ast::expr::Intrinsic::eNotEqual2U:
				case ast::expr::Intrinsic::eNotEqual3U:
				case ast::expr::Intrinsic::eNotEqual4U:
				case ast::expr::Intrinsic::eAll2:
				case ast::expr::Intrinsic::eAll3:
				case ast::expr::Intrinsic::eAll4:
				case ast::expr::Intrinsic::eAny2:
				case ast::expr::Intrinsic::eAny3:
				case ast::expr::Intrinsic::eAny4:
				case ast::expr::Intrinsic::eNot2:
				case ast::expr::Intrinsic::eNot3:
				case ast::expr::Intrinsic::eNot4:
				case ast::expr::Intrinsic::eUaddCarry1:
				case ast::expr::Intrinsic::eUaddCarry2:
				case ast::expr::Intrinsic::eUaddCarry3:
				case ast::expr::Intrinsic::eUaddCarry4:
				case ast::expr::Intrinsic::eUsubBorrow1:
				case ast::expr::Intrinsic::eUsubBorrow2:
				case ast::expr::Intrinsic::eUsubBorrow3:
				case ast::expr::Intrinsic::eUsubBorrow4:
				case ast::expr::Intrinsic::eUmulExtended1:
				case ast::expr::Intrinsic::eUmulExtended2:
				case ast::expr::Intrinsic::eUmulExtended3:
				case ast::expr::Intrinsic::eUmulExtended4:
				case ast::expr::Intrinsic::eImulExtended1:
				case ast::expr::Intrinsic::eImulExtended2:
				case ast::expr::Intrinsic::eImulExtended3:
				case ast::expr::Intrinsic::eImulExtended4:
				case ast::expr::Intrinsic::eBitfieldExtract1I:
				case ast::expr::Intrinsic::eBitfieldExtract2I:
				case ast::expr::Intrinsic::eBitfieldExtract3I:
				case ast::expr::Intrinsic::eBitfieldExtract4I:
				case ast::expr::Intrinsic::eBitfieldExtract1U:
				case ast::expr::Intrinsic::eBitfieldExtract2U:
				case ast::expr::Intrinsic::eBitfieldExtract3U:
				case ast::expr::Intrinsic::eBitfieldExtract4U:
				case ast::expr::Intrinsic::eBitfieldInsert1I:
				case ast::expr::Intrinsic::eBitfieldInsert2I:
				case ast::expr::Intrinsic::eBitfieldInsert3I:
				case ast::expr::Intrinsic::eBitfieldInsert4I:
				case ast::expr::Intrinsic::eBitfieldInsert1U:
				case ast::expr::Intrinsic::eBitfieldInsert2U:
				case ast::expr::Intrinsic::eBitfieldInsert3U:
				case ast::expr::Intrinsic::eBitfieldInsert4U:
				case ast::expr::Intrinsic::eBitfieldReverse1I:
				case ast::expr::Intrinsic::eBitfieldReverse2I:
				case ast::expr::Intrinsic::eBitfieldReverse3I:
				case ast::expr::Intrinsic::eBitfieldReverse4I:
				case ast::expr::Intrinsic::eBitfieldReverse1U:
				case ast::expr::Intrinsic::eBitfieldReverse2U:
				case ast::expr::Intrinsic::eBitfieldReverse3U:
				case ast::expr::Intrinsic::eBitfieldReverse4U:
				case ast::expr::Intrinsic::eBitCount1I:
				case ast::expr::Intrinsic::eBitCount2I:
				case ast::expr::Intrinsic::eBitCount3I:
				case ast::expr::Intrinsic::eBitCount4I:
				case ast::expr::Intrinsic::eBitCount1U:
				case ast::expr::Intrinsic::eBitCount2U:
				case ast::expr::Intrinsic::eBitCount3U:
				case ast::expr::Intrinsic::eBitCount4U:
				case ast::expr::Intrinsic::eFindLSB1I:
				case ast::expr::Intrinsic::eFindLSB2I:
				case ast::expr::Intrinsic::eFindLSB3I:
				case ast::expr::Intrinsic::eFindLSB4I:
				case ast::expr::Intrinsic::eFindLSB1U:
				case ast::expr::Intrinsic::eFindLSB2U:
				case ast::expr::Intrinsic::eFindLSB3U:
				case ast::expr::Intrinsic::eFindLSB4U:
				case ast::expr::Intrinsic::eFindMSB1I:
				case ast::expr::Intrinsic::eFindMSB2I:
				case ast::expr::Intrinsic::eFindMSB3I:
				case ast::expr::Intrinsic::eFindMSB4I:
				case ast::expr::Intrinsic::eFindMSB1U:
				case ast::expr::Intrinsic::eFindMSB2U:
				case ast::expr::Intrinsic::eFindMSB3U:
				case ast::expr::Intrinsic::eFindMSB4U:
					return true;
				default:
					return false;
				}
			}

			expr::ExprPtr resolveConstant( type::TypesCache & typesCache
				, expr::ExprCache & exprCache
				, expr::Intrinsic intrinsic
				, expr::ExprList argsList )
			{
				switch ( intrinsic )
				{
				case ast::expr::Intrinsic::eDegrees1:
				case ast::expr::Intrinsic::eDegrees2:
				case ast::expr::Intrinsic::eDegrees3:
				case ast::expr::Intrinsic::eDegrees4:
					return consts::helpers::degrees( typesCache, exprCache, std::move( argsList ) );
				//case ast::expr::Intrinsic::eRadians1F:
				//case ast::expr::Intrinsic::eRadians2F:
				//case ast::expr::Intrinsic::eRadians3F:
				//case ast::expr::Intrinsic::eRadians4F:
				//	return consts::helpers::radians( typesCache, exprCache, std::move( argsList ) );
				//case ast::expr::Intrinsic::eCos1:
				//case ast::expr::Intrinsic::eCos2:
				//case ast::expr::Intrinsic::eCos3:
				//case ast::expr::Intrinsic::eCos4:
				//	return consts::helpers::cos( typesCache, exprCache, std::move( argsList ) );
				//case ast::expr::Intrinsic::eSin1:
				//case ast::expr::Intrinsic::eSin2:
				//case ast::expr::Intrinsic::eSin3:
				//case ast::expr::Intrinsic::eSin4:
				//	return consts::helpers::sin( typesCache, exprCache, std::move( argsList ) );
				//case ast::expr::Intrinsic::eTan1:
				//case ast::expr::Intrinsic::eTan2:
				//case ast::expr::Intrinsic::eTan3:
				//case ast::expr::Intrinsic::eTan4:
				//	return consts::helpers::tan( typesCache, exprCache, std::move( argsList ) );
				//case ast::expr::Intrinsic::eCosh1:
				//case ast::expr::Intrinsic::eCosh2:
				//case ast::expr::Intrinsic::eCosh3:
				//case ast::expr::Intrinsic::eCosh4:
				//	return consts::helpers::cosh( typesCache, exprCache, std::move( argsList ) );
				//case ast::expr::Intrinsic::eSinh1:
				//case ast::expr::Intrinsic::eSinh2:
				//case ast::expr::Intrinsic::eSinh3:
				//case ast::expr::Intrinsic::eSinh4:
				//	return consts::helpers::sinh( typesCache, exprCache, std::move( argsList ) );
				//case ast::expr::Intrinsic::eTanh1:
				//case ast::expr::Intrinsic::eTanh2:
				//case ast::expr::Intrinsic::eTanh3:
				//case ast::expr::Intrinsic::eTanh4:
				//	return consts::helpers::tanh( typesCache, exprCache, std::move( argsList ) );
				//case ast::expr::Intrinsic::eAcos1:
				//case ast::expr::Intrinsic::eAcos2:
				//case ast::expr::Intrinsic::eAcos3:
				//case ast::expr::Intrinsic::eAcos4:
				//	return consts::helpers::acos( typesCache, exprCache, std::move( argsList ) );
				//case ast::expr::Intrinsic::eAsin1:
				//case ast::expr::Intrinsic::eAsin2:
				//case ast::expr::Intrinsic::eAsin3:
				//case ast::expr::Intrinsic::eAsin4:
				//	return consts::helpers::asin( typesCache, exprCache, std::move( argsList ) );
				//case ast::expr::Intrinsic::eAtan1:
				//case ast::expr::Intrinsic::eAtan2:
				//case ast::expr::Intrinsic::eAtan3:
				//case ast::expr::Intrinsic::eAtan4:
				//	return consts::helpers::atan( typesCache, exprCache, std::move( argsList ) );
				//case ast::expr::Intrinsic::eAtan21:
				//case ast::expr::Intrinsic::eAtan22:
				//case ast::expr::Intrinsic::eAtan23:
				//case ast::expr::Intrinsic::eAtan24:
				//	return consts::helpers::atan2( typesCache, exprCache, std::move( argsList ) );
				//case ast::expr::Intrinsic::eAcosh1:
				//case ast::expr::Intrinsic::eAcosh2:
				//case ast::expr::Intrinsic::eAcosh3:
				//case ast::expr::Intrinsic::eAcosh4:
				//	return consts::helpers::acosh( typesCache, exprCache, std::move( argsList ) );
				//case ast::expr::Intrinsic::eAsinh1:
				//case ast::expr::Intrinsic::eAsinh2:
				//case ast::expr::Intrinsic::eAsinh3:
				//case ast::expr::Intrinsic::eAsinh4:
				//	return consts::helpers::asinh( typesCache, exprCache, std::move( argsList ) );
				//case ast::expr::Intrinsic::eAtanh1:
				//case ast::expr::Intrinsic::eAtanh2:
				//case ast::expr::Intrinsic::eAtanh3:
				//case ast::expr::Intrinsic::eAtanh4:
				//	return consts::helpers::atanh( typesCache, exprCache, std::move( argsList ) );
				//case ast::expr::Intrinsic::ePow1:
				//case ast::expr::Intrinsic::ePow2:
				//case ast::expr::Intrinsic::ePow3:
				//case ast::expr::Intrinsic::ePow4:
				//	return consts::helpers::pow( typesCache, exprCache, std::move( argsList ) );
				//case ast::expr::Intrinsic::eExp1:
				//case ast::expr::Intrinsic::eExp2:
				//case ast::expr::Intrinsic::eExp3:
				//case ast::expr::Intrinsic::eExp4:
				//	return consts::helpers::exp( typesCache, exprCache, std::move( argsList ) );
				//case ast::expr::Intrinsic::eLog1:
				//case ast::expr::Intrinsic::eLog2:
				//case ast::expr::Intrinsic::eLog3:
				//case ast::expr::Intrinsic::eLog4:
				//	return consts::helpers::log( typesCache, exprCache, std::move( argsList ) );
				//case ast::expr::Intrinsic::eExp21:
				//case ast::expr::Intrinsic::eExp22:
				//case ast::expr::Intrinsic::eExp23:
				//case ast::expr::Intrinsic::eExp24:
				//	return consts::helpers::exp2( typesCache, exprCache, std::move( argsList ) );
				//case ast::expr::Intrinsic::eLog21:
				//case ast::expr::Intrinsic::eLog22:
				//case ast::expr::Intrinsic::eLog23:
				//case ast::expr::Intrinsic::eLog24:
				//	return consts::helpers::log2( typesCache, exprCache, std::move( argsList ) );
				//case ast::expr::Intrinsic::eSqrt1F:
				//case ast::expr::Intrinsic::eSqrt2F:
				//case ast::expr::Intrinsic::eSqrt3F:
				//case ast::expr::Intrinsic::eSqrt4F:
				//case ast::expr::Intrinsic::eSqrt1D:
				//case ast::expr::Intrinsic::eSqrt2D:
				//case ast::expr::Intrinsic::eSqrt3D:
				//case ast::expr::Intrinsic::eSqrt4D:
				//	return consts::helpers::sqrt( typesCache, exprCache, std::move( argsList ) );
				//case ast::expr::Intrinsic::eInverseSqrt1F:
				//case ast::expr::Intrinsic::eInverseSqrt2F:
				//case ast::expr::Intrinsic::eInverseSqrt3F:
				//case ast::expr::Intrinsic::eInverseSqrt4F:
				//case ast::expr::Intrinsic::eInverseSqrt1D:
				//case ast::expr::Intrinsic::eInverseSqrt2D:
				//case ast::expr::Intrinsic::eInverseSqrt3D:
				//case ast::expr::Intrinsic::eInverseSqrt4D:
				//	return consts::helpers::inverseSqrt( typesCache, exprCache, std::move( argsList ) );
				//case ast::expr::Intrinsic::eAbs1F:
				//case ast::expr::Intrinsic::eAbs2F:
				//case ast::expr::Intrinsic::eAbs3F:
				//case ast::expr::Intrinsic::eAbs4F:
				//case ast::expr::Intrinsic::eAbs1I:
				//case ast::expr::Intrinsic::eAbs2I:
				//case ast::expr::Intrinsic::eAbs3I:
				//case ast::expr::Intrinsic::eAbs4I:
				//case ast::expr::Intrinsic::eAbs1D:
				//case ast::expr::Intrinsic::eAbs2D:
				//case ast::expr::Intrinsic::eAbs3D:
				//case ast::expr::Intrinsic::eAbs4D:
				//	return consts::helpers::abs( typesCache, exprCache, std::move( argsList ) );
				//case ast::expr::Intrinsic::eSign1F:
				//case ast::expr::Intrinsic::eSign2F:
				//case ast::expr::Intrinsic::eSign3F:
				//case ast::expr::Intrinsic::eSign4F:
				//case ast::expr::Intrinsic::eSign1I:
				//case ast::expr::Intrinsic::eSign2I:
				//case ast::expr::Intrinsic::eSign3I:
				//case ast::expr::Intrinsic::eSign4I:
				//case ast::expr::Intrinsic::eSign1D:
				//case ast::expr::Intrinsic::eSign2D:
				//case ast::expr::Intrinsic::eSign3D:
				//case ast::expr::Intrinsic::eSign4D:
				//	return consts::helpers::sign( typesCache, exprCache, std::move( argsList ) );
				//case ast::expr::Intrinsic::eFloor1F:
				//case ast::expr::Intrinsic::eFloor2F:
				//case ast::expr::Intrinsic::eFloor3F:
				//case ast::expr::Intrinsic::eFloor4F:
				//case ast::expr::Intrinsic::eFloor1D:
				//case ast::expr::Intrinsic::eFloor2D:
				//case ast::expr::Intrinsic::eFloor3D:
				//case ast::expr::Intrinsic::eFloor4D:
				//	return consts::helpers::floor( typesCache, exprCache, std::move( argsList ) );
				//case ast::expr::Intrinsic::eTrunc1F:
				//case ast::expr::Intrinsic::eTrunc2F:
				//case ast::expr::Intrinsic::eTrunc3F:
				//case ast::expr::Intrinsic::eTrunc4F:
				//case ast::expr::Intrinsic::eTrunc1D:
				//case ast::expr::Intrinsic::eTrunc2D:
				//case ast::expr::Intrinsic::eTrunc3D:
				//case ast::expr::Intrinsic::eTrunc4D:
				//	return consts::helpers::trunc( typesCache, exprCache, std::move( argsList ) );
				//case ast::expr::Intrinsic::eRound1F:
				//case ast::expr::Intrinsic::eRound2F:
				//case ast::expr::Intrinsic::eRound3F:
				//case ast::expr::Intrinsic::eRound4F:
				//case ast::expr::Intrinsic::eRound1D:
				//case ast::expr::Intrinsic::eRound2D:
				//case ast::expr::Intrinsic::eRound3D:
				//case ast::expr::Intrinsic::eRound4D:
				//	return consts::helpers::round( typesCache, exprCache, std::move( argsList ) );
				//case ast::expr::Intrinsic::eRoundEven1F:
				//case ast::expr::Intrinsic::eRoundEven2F:
				//case ast::expr::Intrinsic::eRoundEven3F:
				//case ast::expr::Intrinsic::eRoundEven4F:
				//case ast::expr::Intrinsic::eRoundEven1D:
				//case ast::expr::Intrinsic::eRoundEven2D:
				//case ast::expr::Intrinsic::eRoundEven3D:
				//case ast::expr::Intrinsic::eRoundEven4D:
				//	return consts::helpers::roundEven( typesCache, exprCache, std::move( argsList ) );
				//case ast::expr::Intrinsic::eCeil1F:
				//case ast::expr::Intrinsic::eCeil2F:
				//case ast::expr::Intrinsic::eCeil3F:
				//case ast::expr::Intrinsic::eCeil4F:
				//case ast::expr::Intrinsic::eCeil1D:
				//case ast::expr::Intrinsic::eCeil2D:
				//case ast::expr::Intrinsic::eCeil3D:
				//case ast::expr::Intrinsic::eCeil4D:
				//	return consts::helpers::ceil( typesCache, exprCache, std::move( argsList ) );
				//case ast::expr::Intrinsic::eFract1F:
				//case ast::expr::Intrinsic::eFract2F:
				//case ast::expr::Intrinsic::eFract3F:
				//case ast::expr::Intrinsic::eFract4F:
				//case ast::expr::Intrinsic::eFract1D:
				//case ast::expr::Intrinsic::eFract2D:
				//case ast::expr::Intrinsic::eFract3D:
				//case ast::expr::Intrinsic::eFract4D:
				//	return consts::helpers::fract( typesCache, exprCache, std::move( argsList ) );
				//case ast::expr::Intrinsic::eMod1F:
				//case ast::expr::Intrinsic::eMod2F:
				//case ast::expr::Intrinsic::eMod3F:
				//case ast::expr::Intrinsic::eMod4F:
				//case ast::expr::Intrinsic::eMod1D:
				//case ast::expr::Intrinsic::eMod2D:
				//case ast::expr::Intrinsic::eMod3D:
				//case ast::expr::Intrinsic::eMod4D:
				//	return consts::helpers::mod( typesCache, exprCache, std::move( argsList ) );
				//case ast::expr::Intrinsic::eModf1F:
				//case ast::expr::Intrinsic::eModf2F:
				//case ast::expr::Intrinsic::eModf3F:
				//case ast::expr::Intrinsic::eModf4F:
				//case ast::expr::Intrinsic::eModf1D:
				//case ast::expr::Intrinsic::eModf2D:
				//case ast::expr::Intrinsic::eModf3D:
				//case ast::expr::Intrinsic::eModf4D:
				//	return consts::helpers::modf( typesCache, exprCache, std::move( argsList ) );
				//case ast::expr::Intrinsic::eMin1F:
				//case ast::expr::Intrinsic::eMin2F:
				//case ast::expr::Intrinsic::eMin3F:
				//case ast::expr::Intrinsic::eMin4F:
				//case ast::expr::Intrinsic::eMin1D:
				//case ast::expr::Intrinsic::eMin2D:
				//case ast::expr::Intrinsic::eMin3D:
				//case ast::expr::Intrinsic::eMin4D:
				//case ast::expr::Intrinsic::eMin1I:
				//case ast::expr::Intrinsic::eMin2I:
				//case ast::expr::Intrinsic::eMin3I:
				//case ast::expr::Intrinsic::eMin4I:
				//case ast::expr::Intrinsic::eMin1U:
				//case ast::expr::Intrinsic::eMin2U:
				//case ast::expr::Intrinsic::eMin3U:
				//case ast::expr::Intrinsic::eMin4U:
				//	return consts::helpers::min( typesCache, exprCache, std::move( argsList ) );
				//case ast::expr::Intrinsic::eMax1F:
				//case ast::expr::Intrinsic::eMax2F:
				//case ast::expr::Intrinsic::eMax3F:
				//case ast::expr::Intrinsic::eMax4F:
				//case ast::expr::Intrinsic::eMax1D:
				//case ast::expr::Intrinsic::eMax2D:
				//case ast::expr::Intrinsic::eMax3D:
				//case ast::expr::Intrinsic::eMax4D:
				//case ast::expr::Intrinsic::eMax1I:
				//case ast::expr::Intrinsic::eMax2I:
				//case ast::expr::Intrinsic::eMax3I:
				//case ast::expr::Intrinsic::eMax4I:
				//case ast::expr::Intrinsic::eMax1U:
				//case ast::expr::Intrinsic::eMax2U:
				//case ast::expr::Intrinsic::eMax3U:
				//case ast::expr::Intrinsic::eMax4U:
				//	return consts::helpers::max( typesCache, exprCache, std::move( argsList ) );
				//case ast::expr::Intrinsic::eClamp1F:
				//case ast::expr::Intrinsic::eClamp2F:
				//case ast::expr::Intrinsic::eClamp3F:
				//case ast::expr::Intrinsic::eClamp4F:
				//case ast::expr::Intrinsic::eClamp1D:
				//case ast::expr::Intrinsic::eClamp2D:
				//case ast::expr::Intrinsic::eClamp3D:
				//case ast::expr::Intrinsic::eClamp4D:
				//case ast::expr::Intrinsic::eClamp1I:
				//case ast::expr::Intrinsic::eClamp2I:
				//case ast::expr::Intrinsic::eClamp3I:
				//case ast::expr::Intrinsic::eClamp4I:
				//case ast::expr::Intrinsic::eClamp1U:
				//case ast::expr::Intrinsic::eClamp2U:
				//case ast::expr::Intrinsic::eClamp3U:
				//case ast::expr::Intrinsic::eClamp4U:
				//	return consts::helpers::clamp( typesCache, exprCache, std::move( argsList ) );
				//case ast::expr::Intrinsic::eMix1F:
				//case ast::expr::Intrinsic::eMix2F:
				//case ast::expr::Intrinsic::eMix3F:
				//case ast::expr::Intrinsic::eMix4F:
				//case ast::expr::Intrinsic::eMix1D:
				//case ast::expr::Intrinsic::eMix2D:
				//case ast::expr::Intrinsic::eMix3D:
				//case ast::expr::Intrinsic::eMix4D:
				//	return consts::helpers::mix( typesCache, exprCache, std::move( argsList ) );
				//case ast::expr::Intrinsic::eStep1F:
				//case ast::expr::Intrinsic::eStep2F:
				//case ast::expr::Intrinsic::eStep3F:
				//case ast::expr::Intrinsic::eStep4F:
				//case ast::expr::Intrinsic::eStep1D:
				//case ast::expr::Intrinsic::eStep2D:
				//case ast::expr::Intrinsic::eStep3D:
				//case ast::expr::Intrinsic::eStep4D:
				//	return consts::helpers::step( typesCache, exprCache, std::move( argsList ) );
				//case ast::expr::Intrinsic::eSmoothStep1F:
				//case ast::expr::Intrinsic::eSmoothStep2F:
				//case ast::expr::Intrinsic::eSmoothStep3F:
				//case ast::expr::Intrinsic::eSmoothStep4F:
				//case ast::expr::Intrinsic::eSmoothStep1D:
				//case ast::expr::Intrinsic::eSmoothStep2D:
				//case ast::expr::Intrinsic::eSmoothStep3D:
				//case ast::expr::Intrinsic::eSmoothStep4D:
				//	return consts::helpers::smoothStep( typesCache, exprCache, std::move( argsList ) );
				//case ast::expr::Intrinsic::eIsnan1F:
				//case ast::expr::Intrinsic::eIsnan2F:
				//case ast::expr::Intrinsic::eIsnan3F:
				//case ast::expr::Intrinsic::eIsnan4F:
				//case ast::expr::Intrinsic::eIsnan1D:
				//case ast::expr::Intrinsic::eIsnan2D:
				//case ast::expr::Intrinsic::eIsnan3D:
				//case ast::expr::Intrinsic::eIsnan4D:
				//	return consts::helpers::isnan( typesCache, exprCache, std::move( argsList ) );
				//case ast::expr::Intrinsic::eIsinf1F:
				//case ast::expr::Intrinsic::eIsinf2F:
				//case ast::expr::Intrinsic::eIsinf3F:
				//case ast::expr::Intrinsic::eIsinf4F:
				//case ast::expr::Intrinsic::eIsinf1D:
				//case ast::expr::Intrinsic::eIsinf2D:
				//case ast::expr::Intrinsic::eIsinf3D:
				//case ast::expr::Intrinsic::eIsinf4D:
				//	return consts::helpers::isinf( typesCache, exprCache, std::move( argsList ) );
				//case ast::expr::Intrinsic::eFma1F:
				//case ast::expr::Intrinsic::eFma2F:
				//case ast::expr::Intrinsic::eFma3F:
				//case ast::expr::Intrinsic::eFma4F:
				//case ast::expr::Intrinsic::eFma1D:
				//case ast::expr::Intrinsic::eFma2D:
				//case ast::expr::Intrinsic::eFma3D:
				//case ast::expr::Intrinsic::eFma4D:
				//	return consts::helpers::fma( typesCache, exprCache, std::move( argsList ) );
				//case ast::expr::Intrinsic::eFrexp1F:
				//case ast::expr::Intrinsic::eFrexp2F:
				//case ast::expr::Intrinsic::eFrexp3F:
				//case ast::expr::Intrinsic::eFrexp4F:
				//case ast::expr::Intrinsic::eFrexp1D:
				//case ast::expr::Intrinsic::eFrexp2D:
				//case ast::expr::Intrinsic::eFrexp3D:
				//case ast::expr::Intrinsic::eFrexp4D:
				//	return consts::helpers::frexp( typesCache, exprCache, std::move( argsList ) );
				//case ast::expr::Intrinsic::eLdexp1F:
				//case ast::expr::Intrinsic::eLdexp2F:
				//case ast::expr::Intrinsic::eLdexp3F:
				//case ast::expr::Intrinsic::eLdexp4F:
				//case ast::expr::Intrinsic::eLdexp1D:
				//case ast::expr::Intrinsic::eLdexp2D:
				//case ast::expr::Intrinsic::eLdexp3D:
				//case ast::expr::Intrinsic::eLdexp4D:
				//	return consts::helpers::ldexp( typesCache, exprCache, std::move( argsList ) );
				//case ast::expr::Intrinsic::eLength1F:
				//case ast::expr::Intrinsic::eLength2F:
				//case ast::expr::Intrinsic::eLength3F:
				//case ast::expr::Intrinsic::eLength4F:
				//case ast::expr::Intrinsic::eLength1D:
				//case ast::expr::Intrinsic::eLength2D:
				//case ast::expr::Intrinsic::eLength3D:
				//case ast::expr::Intrinsic::eLength4D:
				//	return consts::helpers::length( typesCache, exprCache, std::move( argsList ) );
				//case ast::expr::Intrinsic::eDistance1F:
				//case ast::expr::Intrinsic::eDistance2F:
				//case ast::expr::Intrinsic::eDistance3F:
				//case ast::expr::Intrinsic::eDistance4F:
				//case ast::expr::Intrinsic::eDistance1D:
				//case ast::expr::Intrinsic::eDistance2D:
				//case ast::expr::Intrinsic::eDistance3D:
				//case ast::expr::Intrinsic::eDistance4D:
				//	return consts::helpers::distance( typesCache, exprCache, std::move( argsList ) );
				//case ast::expr::Intrinsic::eDot1F:
				//case ast::expr::Intrinsic::eDot2F:
				//case ast::expr::Intrinsic::eDot3F:
				//case ast::expr::Intrinsic::eDot4F:
				//case ast::expr::Intrinsic::eDot1D:
				//case ast::expr::Intrinsic::eDot2D:
				//case ast::expr::Intrinsic::eDot3D:
				//case ast::expr::Intrinsic::eDot4D:
				//	return consts::helpers::dot( typesCache, exprCache, std::move( argsList ) );
				//case ast::expr::Intrinsic::eCrossF:
				//case ast::expr::Intrinsic::eCrossD:
				//	return consts::helpers::cross( typesCache, exprCache, std::move( argsList ) );
				//case ast::expr::Intrinsic::eNormalize1F:
				//case ast::expr::Intrinsic::eNormalize2F:
				//case ast::expr::Intrinsic::eNormalize3F:
				//case ast::expr::Intrinsic::eNormalize4F:
				//case ast::expr::Intrinsic::eNormalize1D:
				//case ast::expr::Intrinsic::eNormalize2D:
				//case ast::expr::Intrinsic::eNormalize3D:
				//case ast::expr::Intrinsic::eNormalize4D:
				//	return consts::helpers::normalize( typesCache, exprCache, std::move( argsList ) );
				//case ast::expr::Intrinsic::eFaceForward1F:
				//case ast::expr::Intrinsic::eFaceForward2F:
				//case ast::expr::Intrinsic::eFaceForward3F:
				//case ast::expr::Intrinsic::eFaceForward4F:
				//case ast::expr::Intrinsic::eFaceForward1D:
				//case ast::expr::Intrinsic::eFaceForward2D:
				//case ast::expr::Intrinsic::eFaceForward3D:
				//case ast::expr::Intrinsic::eFaceForward4D:
				//	return consts::helpers::faceForward( typesCache, exprCache, std::move( argsList ) );
				//case ast::expr::Intrinsic::eReflect1F:
				//case ast::expr::Intrinsic::eReflect2F:
				//case ast::expr::Intrinsic::eReflect3F:
				//case ast::expr::Intrinsic::eReflect4F:
				//case ast::expr::Intrinsic::eReflect1D:
				//case ast::expr::Intrinsic::eReflect2D:
				//case ast::expr::Intrinsic::eReflect3D:
				//case ast::expr::Intrinsic::eReflect4D:
				//	return consts::helpers::reflect( typesCache, exprCache, std::move( argsList ) );
				//case ast::expr::Intrinsic::eRefract1F:
				//case ast::expr::Intrinsic::eRefract2F:
				//case ast::expr::Intrinsic::eRefract3F:
				//case ast::expr::Intrinsic::eRefract4F:
				//case ast::expr::Intrinsic::eRefract1D:
				//case ast::expr::Intrinsic::eRefract2D:
				//case ast::expr::Intrinsic::eRefract3D:
				//case ast::expr::Intrinsic::eRefract4D:
				//	return consts::helpers::refract( typesCache, exprCache, std::move( argsList ) );
				//case ast::expr::Intrinsic::eMatrixCompMult2x2F:
				//case ast::expr::Intrinsic::eMatrixCompMult2x3F:
				//case ast::expr::Intrinsic::eMatrixCompMult2x4F:
				//case ast::expr::Intrinsic::eMatrixCompMult3x2F:
				//case ast::expr::Intrinsic::eMatrixCompMult3x3F:
				//case ast::expr::Intrinsic::eMatrixCompMult3x4F:
				//case ast::expr::Intrinsic::eMatrixCompMult4x2F:
				//case ast::expr::Intrinsic::eMatrixCompMult4x3F:
				//case ast::expr::Intrinsic::eMatrixCompMult4x4F:
				//case ast::expr::Intrinsic::eMatrixCompMult2x2D:
				//case ast::expr::Intrinsic::eMatrixCompMult2x3D:
				//case ast::expr::Intrinsic::eMatrixCompMult2x4D:
				//case ast::expr::Intrinsic::eMatrixCompMult3x2D:
				//case ast::expr::Intrinsic::eMatrixCompMult3x3D:
				//case ast::expr::Intrinsic::eMatrixCompMult3x4D:
				//case ast::expr::Intrinsic::eMatrixCompMult4x2D:
				//case ast::expr::Intrinsic::eMatrixCompMult4x3D:
				//case ast::expr::Intrinsic::eMatrixCompMult4x4D:
				//	return consts::helpers::matrixCompMult( typesCache, exprCache, std::move( argsList ) );
				//case ast::expr::Intrinsic::eOuterProduct2x2F:
				//case ast::expr::Intrinsic::eOuterProduct3x3F:
				//case ast::expr::Intrinsic::eOuterProduct4x4F:
				//case ast::expr::Intrinsic::eOuterProduct3x2F:
				//case ast::expr::Intrinsic::eOuterProduct2x3F:
				//case ast::expr::Intrinsic::eOuterProduct4x2F:
				//case ast::expr::Intrinsic::eOuterProduct2x4F:
				//case ast::expr::Intrinsic::eOuterProduct4x3F:
				//case ast::expr::Intrinsic::eOuterProduct3x4F:
				//case ast::expr::Intrinsic::eOuterProduct2x2D:
				//case ast::expr::Intrinsic::eOuterProduct3x3D:
				//case ast::expr::Intrinsic::eOuterProduct4x4D:
				//case ast::expr::Intrinsic::eOuterProduct3x2D:
				//case ast::expr::Intrinsic::eOuterProduct2x3D:
				//case ast::expr::Intrinsic::eOuterProduct4x2D:
				//case ast::expr::Intrinsic::eOuterProduct2x4D:
				//case ast::expr::Intrinsic::eOuterProduct4x3D:
				//case ast::expr::Intrinsic::eOuterProduct3x4D:
				//	return consts::helpers::outerProduct( typesCache, exprCache, std::move( argsList ) );
				//case ast::expr::Intrinsic::eTranspose2x2F:
				//case ast::expr::Intrinsic::eTranspose2x3F:
				//case ast::expr::Intrinsic::eTranspose2x4F:
				//case ast::expr::Intrinsic::eTranspose3x2F:
				//case ast::expr::Intrinsic::eTranspose3x3F:
				//case ast::expr::Intrinsic::eTranspose3x4F:
				//case ast::expr::Intrinsic::eTranspose4x2F:
				//case ast::expr::Intrinsic::eTranspose4x3F:
				//case ast::expr::Intrinsic::eTranspose4x4F:
				//case ast::expr::Intrinsic::eTranspose2x2D:
				//case ast::expr::Intrinsic::eTranspose2x3D:
				//case ast::expr::Intrinsic::eTranspose2x4D:
				//case ast::expr::Intrinsic::eTranspose3x2D:
				//case ast::expr::Intrinsic::eTranspose3x3D:
				//case ast::expr::Intrinsic::eTranspose3x4D:
				//case ast::expr::Intrinsic::eTranspose4x2D:
				//case ast::expr::Intrinsic::eTranspose4x3D:
				//case ast::expr::Intrinsic::eTranspose4x4D:
				//	return consts::helpers::transpose( typesCache, exprCache, std::move( argsList ) );
				//case ast::expr::Intrinsic::eDeterminant2x2F:
				//case ast::expr::Intrinsic::eDeterminant3x3F:
				//case ast::expr::Intrinsic::eDeterminant4x4F:
				//case ast::expr::Intrinsic::eDeterminant2x2D:
				//case ast::expr::Intrinsic::eDeterminant3x3D:
				//case ast::expr::Intrinsic::eDeterminant4x4D:
				//	return consts::helpers::determinant( typesCache, exprCache, std::move( argsList ) );
				//case ast::expr::Intrinsic::eInverse2x2F:
				//case ast::expr::Intrinsic::eInverse3x3F:
				//case ast::expr::Intrinsic::eInverse4x4F:
				//case ast::expr::Intrinsic::eInverse2x2D:
				//case ast::expr::Intrinsic::eInverse3x3D:
				//case ast::expr::Intrinsic::eInverse4x4D:
				//	return consts::helpers::inverse( typesCache, exprCache, std::move( argsList ) );
				//case ast::expr::Intrinsic::eLessThan2F:
				//case ast::expr::Intrinsic::eLessThan3F:
				//case ast::expr::Intrinsic::eLessThan4F:
				//case ast::expr::Intrinsic::eLessThan2D:
				//case ast::expr::Intrinsic::eLessThan3D:
				//case ast::expr::Intrinsic::eLessThan4D:
				//case ast::expr::Intrinsic::eLessThan2I:
				//case ast::expr::Intrinsic::eLessThan3I:
				//case ast::expr::Intrinsic::eLessThan4I:
				//case ast::expr::Intrinsic::eLessThan2U:
				//case ast::expr::Intrinsic::eLessThan3U:
				//case ast::expr::Intrinsic::eLessThan4U:
				//	return consts::helpers::lessThan( typesCache, exprCache, std::move( argsList ) );
				//case ast::expr::Intrinsic::eLessThanEqual2F:
				//case ast::expr::Intrinsic::eLessThanEqual3F:
				//case ast::expr::Intrinsic::eLessThanEqual4F:
				//case ast::expr::Intrinsic::eLessThanEqual2D:
				//case ast::expr::Intrinsic::eLessThanEqual3D:
				//case ast::expr::Intrinsic::eLessThanEqual4D:
				//case ast::expr::Intrinsic::eLessThanEqual2I:
				//case ast::expr::Intrinsic::eLessThanEqual3I:
				//case ast::expr::Intrinsic::eLessThanEqual4I:
				//case ast::expr::Intrinsic::eLessThanEqual2U:
				//case ast::expr::Intrinsic::eLessThanEqual3U:
				//case ast::expr::Intrinsic::eLessThanEqual4U:
				//	return consts::helpers::lessThanEqual( typesCache, exprCache, std::move( argsList ) );
				//case ast::expr::Intrinsic::eGreaterThan2F:
				//case ast::expr::Intrinsic::eGreaterThan3F:
				//case ast::expr::Intrinsic::eGreaterThan4F:
				//case ast::expr::Intrinsic::eGreaterThan2D:
				//case ast::expr::Intrinsic::eGreaterThan3D:
				//case ast::expr::Intrinsic::eGreaterThan4D:
				//case ast::expr::Intrinsic::eGreaterThan2I:
				//case ast::expr::Intrinsic::eGreaterThan3I:
				//case ast::expr::Intrinsic::eGreaterThan4I:
				//case ast::expr::Intrinsic::eGreaterThan2U:
				//case ast::expr::Intrinsic::eGreaterThan3U:
				//case ast::expr::Intrinsic::eGreaterThan4U:
				//	return consts::helpers::greaterThan( typesCache, exprCache, std::move( argsList ) );
				//case ast::expr::Intrinsic::eGreaterThanEqual2F:
				//case ast::expr::Intrinsic::eGreaterThanEqual3F:
				//case ast::expr::Intrinsic::eGreaterThanEqual4F:
				//case ast::expr::Intrinsic::eGreaterThanEqual2D:
				//case ast::expr::Intrinsic::eGreaterThanEqual3D:
				//case ast::expr::Intrinsic::eGreaterThanEqual4D:
				//case ast::expr::Intrinsic::eGreaterThanEqual2I:
				//case ast::expr::Intrinsic::eGreaterThanEqual3I:
				//case ast::expr::Intrinsic::eGreaterThanEqual4I:
				//case ast::expr::Intrinsic::eGreaterThanEqual2U:
				//case ast::expr::Intrinsic::eGreaterThanEqual3U:
				//case ast::expr::Intrinsic::eGreaterThanEqual4U:
				//	return consts::helpers::greaterThanEqual( typesCache, exprCache, std::move( argsList ) );
				//case ast::expr::Intrinsic::eEqual2F:
				//case ast::expr::Intrinsic::eEqual3F:
				//case ast::expr::Intrinsic::eEqual4F:
				//case ast::expr::Intrinsic::eEqual2D:
				//case ast::expr::Intrinsic::eEqual3D:
				//case ast::expr::Intrinsic::eEqual4D:
				//case ast::expr::Intrinsic::eEqual2I:
				//case ast::expr::Intrinsic::eEqual3I:
				//case ast::expr::Intrinsic::eEqual4I:
				//case ast::expr::Intrinsic::eEqual2U:
				//case ast::expr::Intrinsic::eEqual3U:
				//case ast::expr::Intrinsic::eEqual4U:
				//	return consts::helpers::equal( typesCache, exprCache, std::move( argsList ) );
				//case ast::expr::Intrinsic::eNotEqual2F:
				//case ast::expr::Intrinsic::eNotEqual3F:
				//case ast::expr::Intrinsic::eNotEqual4F:
				//case ast::expr::Intrinsic::eNotEqual2D:
				//case ast::expr::Intrinsic::eNotEqual3D:
				//case ast::expr::Intrinsic::eNotEqual4D:
				//case ast::expr::Intrinsic::eNotEqual2I:
				//case ast::expr::Intrinsic::eNotEqual3I:
				//case ast::expr::Intrinsic::eNotEqual4I:
				//case ast::expr::Intrinsic::eNotEqual2U:
				//case ast::expr::Intrinsic::eNotEqual3U:
				//case ast::expr::Intrinsic::eNotEqual4U:
				//	return consts::helpers::notEqual( typesCache, exprCache, std::move( argsList ) );
				//case ast::expr::Intrinsic::eAll2:
				//case ast::expr::Intrinsic::eAll3:
				//case ast::expr::Intrinsic::eAll4:
				//	return consts::helpers::all( typesCache, exprCache, std::move( argsList ) );
				//case ast::expr::Intrinsic::eAny2:
				//case ast::expr::Intrinsic::eAny3:
				//case ast::expr::Intrinsic::eAny4:
				//	return consts::helpers::any( typesCache, exprCache, std::move( argsList ) );
				//case ast::expr::Intrinsic::eNot2:
				//case ast::expr::Intrinsic::eNot3:
				//case ast::expr::Intrinsic::eNot4:
				//	return consts::helpers::negate( typesCache, exprCache, std::move( argsList ) );
				//case ast::expr::Intrinsic::eUaddCarry1:
				//case ast::expr::Intrinsic::eUaddCarry2:
				//case ast::expr::Intrinsic::eUaddCarry3:
				//case ast::expr::Intrinsic::eUaddCarry4:
				//	return consts::helpers::uaddCarry( typesCache, exprCache, std::move( argsList ) );
				//case ast::expr::Intrinsic::eUsubBorrow1:
				//case ast::expr::Intrinsic::eUsubBorrow2:
				//case ast::expr::Intrinsic::eUsubBorrow3:
				//case ast::expr::Intrinsic::eUsubBorrow4:
				//	return consts::helpers::usubBorrow( typesCache, exprCache, std::move( argsList ) );
				//case ast::expr::Intrinsic::eUmulExtended1:
				//case ast::expr::Intrinsic::eUmulExtended2:
				//case ast::expr::Intrinsic::eUmulExtended3:
				//case ast::expr::Intrinsic::eUmulExtended4:
				//	return consts::helpers::umulExtended( typesCache, exprCache, std::move( argsList ) );
				//case ast::expr::Intrinsic::eImulExtended1:
				//case ast::expr::Intrinsic::eImulExtended2:
				//case ast::expr::Intrinsic::eImulExtended3:
				//case ast::expr::Intrinsic::eImulExtended4:
				//	return consts::helpers::imulExtended( typesCache, exprCache, std::move( argsList ) );
				//case ast::expr::Intrinsic::eBitfieldExtract1I:
				//case ast::expr::Intrinsic::eBitfieldExtract2I:
				//case ast::expr::Intrinsic::eBitfieldExtract3I:
				//case ast::expr::Intrinsic::eBitfieldExtract4I:
				//case ast::expr::Intrinsic::eBitfieldExtract1U:
				//case ast::expr::Intrinsic::eBitfieldExtract2U:
				//case ast::expr::Intrinsic::eBitfieldExtract3U:
				//case ast::expr::Intrinsic::eBitfieldExtract4U:
				//	return consts::helpers::bitfieldExtract( typesCache, exprCache, std::move( argsList ) );
				//case ast::expr::Intrinsic::eBitfieldInsert1I:
				//case ast::expr::Intrinsic::eBitfieldInsert2I:
				//case ast::expr::Intrinsic::eBitfieldInsert3I:
				//case ast::expr::Intrinsic::eBitfieldInsert4I:
				//case ast::expr::Intrinsic::eBitfieldInsert1U:
				//case ast::expr::Intrinsic::eBitfieldInsert2U:
				//case ast::expr::Intrinsic::eBitfieldInsert3U:
				//case ast::expr::Intrinsic::eBitfieldInsert4U:
				//	return consts::helpers::bitfieldInsert( typesCache, exprCache, std::move( argsList ) );
				//case ast::expr::Intrinsic::eBitfieldReverse1I:
				//case ast::expr::Intrinsic::eBitfieldReverse2I:
				//case ast::expr::Intrinsic::eBitfieldReverse3I:
				//case ast::expr::Intrinsic::eBitfieldReverse4I:
				//case ast::expr::Intrinsic::eBitfieldReverse1U:
				//case ast::expr::Intrinsic::eBitfieldReverse2U:
				//case ast::expr::Intrinsic::eBitfieldReverse3U:
				//case ast::expr::Intrinsic::eBitfieldReverse4U:
				//	return consts::helpers::bitfieldReverse( typesCache, exprCache, std::move( argsList ) );
				//case ast::expr::Intrinsic::eBitCount1I:
				//case ast::expr::Intrinsic::eBitCount2I:
				//case ast::expr::Intrinsic::eBitCount3I:
				//case ast::expr::Intrinsic::eBitCount4I:
				//case ast::expr::Intrinsic::eBitCount1U:
				//case ast::expr::Intrinsic::eBitCount2U:
				//case ast::expr::Intrinsic::eBitCount3U:
				//case ast::expr::Intrinsic::eBitCount4U:
				//	return consts::helpers::bitCount( typesCache, exprCache, std::move( argsList ) );
				//case ast::expr::Intrinsic::eFindLSB1I:
				//case ast::expr::Intrinsic::eFindLSB2I:
				//case ast::expr::Intrinsic::eFindLSB3I:
				//case ast::expr::Intrinsic::eFindLSB4I:
				//case ast::expr::Intrinsic::eFindLSB1U:
				//case ast::expr::Intrinsic::eFindLSB2U:
				//case ast::expr::Intrinsic::eFindLSB3U:
				//case ast::expr::Intrinsic::eFindLSB4U:
				//	return consts::helpers::findLSB( typesCache, exprCache, std::move( argsList ) );
				//case ast::expr::Intrinsic::eFindMSB1I:
				//case ast::expr::Intrinsic::eFindMSB2I:
				//case ast::expr::Intrinsic::eFindMSB3I:
				//case ast::expr::Intrinsic::eFindMSB4I:
				//case ast::expr::Intrinsic::eFindMSB1U:
				//case ast::expr::Intrinsic::eFindMSB2U:
				//case ast::expr::Intrinsic::eFindMSB3U:
				//case ast::expr::Intrinsic::eFindMSB4U:
				//	return consts::helpers::findMSB( typesCache, exprCache, std::move( argsList ) );
				default:
					AST_Failure( "Unsupported intrinsics for constant resolution" );
					return nullptr;
				}
			}
*/
		}

		struct ConstantsContext
		{
			explicit ConstantsContext( ast::ShaderAllocatorBlock * alloc )
				: constExprs{ alloc }
				, constAggrExprs{ alloc }
			{
			}

			Map< uint32_t, ast::expr::ExprPtr > constExprs;
			Map< uint32_t, ast::expr::ExprList > constAggrExprs;
		};

		class ExprEvaluator
			: public ast::ExprCloner
		{
		public:
			static ast::expr::ExprPtr submit( ast::expr::ExprCache & exprCache
				, ast::expr::Expr * expr
				, ConstantsContext & context )
			{
				bool allLiterals{ false };
				return submit( exprCache
					, expr
					, context
					, allLiterals );
			}

			static expr::ExprPtr submit( expr::ExprCache & exprCache
				, expr::Expr * expr
				, ConstantsContext & context
				, bool & allLiterals )
			{
				expr::ExprPtr result{};
				ExprEvaluator vis{ exprCache, context, allLiterals, result };
				expr->accept( &vis );

				if ( expr->isNonUniform() )
				{
					result->updateFlag( expr::Flag::eNonUniform );
				}

				return result;
			}

		private:
			ExprEvaluator( ast::expr::ExprCache & exprCache
				, ConstantsContext & context
				, bool & allLiterals
				, ast::expr::ExprPtr & result )
				: ExprCloner{ exprCache, result }
				, m_context{ context }
				, m_allLiterals{ allLiterals }
			{
			}

			using ast::ExprCloner::doSubmit;

			expr::ExprPtr doSubmit( expr::Expr * expr
				, bool & allLiterals )
			{
				return submit( m_exprCache, expr, m_context, allLiterals );
			}

			expr::ExprPtr doSubmit( expr::Expr * expr )override
			{
				return doSubmit( expr, m_allLiterals );
			}

			void visitUnaryExpr( expr::Unary * expr )
			{
				TraceFunc
				auto op = doSubmit( expr->getOperand() );

				if ( op->getKind() == expr::Kind::eLiteral )
				{
					auto & literal = static_cast< expr::Literal const & >( *op );

					switch ( expr->getKind() )
					{
					case expr::Kind::eUnaryMinus:
						m_result = -literal;
						break;
					case expr::Kind::eUnaryPlus:
						m_result = std::move( op );
						break;
					case expr::Kind::eBitNot:
						m_result = ~literal;
						break;
					case expr::Kind::eLogNot:
						m_result = !literal;
						break;
					case expr::Kind::eCast:
						m_result = literal.castTo( helpers::getLiteralType( *expr->getType() ) );
						break;
					default:
						AST_Failure( "Unexpected unary expression" );
						m_result = ExprCloner::submit( m_exprCache, expr );
						break;
					}
				}
				else
				{
					m_result = ExprCloner::submit( m_exprCache, expr );
				}
			}

			void visitBinaryExpr( expr::Binary * expr )
			{
				TraceFunc
				auto lhs = doSubmit( expr->getLHS() );
				auto rhs = doSubmit( expr->getRHS() );

				if ( lhs->getKind() == expr::Kind::eLiteral
					&& rhs->getKind() == expr::Kind::eLiteral )
				{
					auto & lhsLiteral = static_cast< expr::Literal const & >( *lhs );
					auto & rhsLiteral = static_cast< expr::Literal const & >( *rhs );

					switch ( expr->getKind() )
					{
					case expr::Kind::eAdd:
						m_result = lhsLiteral + rhsLiteral;
						break;
					case expr::Kind::eBitAnd:
						m_result = lhsLiteral & rhsLiteral;
						break;
					case expr::Kind::eBitOr:
						m_result = lhsLiteral | rhsLiteral;
						break;
					case expr::Kind::eBitXor:
						m_result = lhsLiteral ^ rhsLiteral;
						break;
					case expr::Kind::eDivide:
						m_result = lhsLiteral / rhsLiteral;
						break;
					case expr::Kind::eLShift:
						m_result = lhsLiteral << rhsLiteral;
						break;
					case expr::Kind::eMinus:
						m_result = lhsLiteral - rhsLiteral;
						break;
					case expr::Kind::eModulo:
						m_result = lhsLiteral % rhsLiteral;
						break;
					case expr::Kind::eRShift:
						m_result = lhsLiteral >> rhsLiteral;
						break;
					case expr::Kind::eTimes:
						m_result = lhsLiteral * rhsLiteral;
						break;
					case expr::Kind::eLogAnd:
						m_result = lhsLiteral && rhsLiteral;
						break;
					case expr::Kind::eLogOr:
						m_result = lhsLiteral || rhsLiteral;
						break;
					case expr::Kind::eLess:
						m_result = lhsLiteral < rhsLiteral;
						break;
					case expr::Kind::eLessEqual:
						m_result = lhsLiteral <= rhsLiteral;
						break;
					case expr::Kind::eGreater:
						m_result = lhsLiteral > rhsLiteral;
						break;
					case expr::Kind::eGreaterEqual:
						m_result = lhsLiteral >= rhsLiteral;
						break;
					case expr::Kind::eEqual:
						m_result = lhsLiteral == rhsLiteral;
						break;
					case expr::Kind::eNotEqual:
						m_result = lhsLiteral != rhsLiteral;
						break;
					default:
						AST_Failure( "Unexpected binary expression" );
						m_result = ExprCloner::submit( m_exprCache, expr );
						break;
					}
				}
				else
				{
					switch ( expr->getKind() )
					{
					case expr::Kind::eAdd:
						m_result = m_exprCache.makeAdd( expr->getType(), std::move( lhs ), std::move( rhs ) );
						break;
					case expr::Kind::eBitAnd:
						m_result = m_exprCache.makeBitAnd( expr->getType(), std::move( lhs ), std::move( rhs ) );
						break;
					case expr::Kind::eBitOr:
						m_result = m_exprCache.makeBitOr( expr->getType(), std::move( lhs ), std::move( rhs ) );
						break;
					case expr::Kind::eBitXor:
						m_result = m_exprCache.makeBitXor( expr->getType(), std::move( lhs ), std::move( rhs ) );
						break;
					case expr::Kind::eDivide:
						m_result = m_exprCache.makeDivide( expr->getType(), std::move( lhs ), std::move( rhs ) );
						break;
					case expr::Kind::eLShift:
						m_result = m_exprCache.makeLShift( expr->getType(), std::move( lhs ), std::move( rhs ) );
						break;
					case expr::Kind::eMinus:
						m_result = m_exprCache.makeMinus( expr->getType(), std::move( lhs ), std::move( rhs ) );
						break;
					case expr::Kind::eModulo:
						m_result = m_exprCache.makeModulo( expr->getType(), std::move( lhs ), std::move( rhs ) );
						break;
					case expr::Kind::eRShift:
						m_result = m_exprCache.makeRShift( expr->getType(), std::move( lhs ), std::move( rhs ) );
						break;
					case expr::Kind::eTimes:
						m_result = m_exprCache.makeTimes( expr->getType(), std::move( lhs ), std::move( rhs ) );
						break;
					case expr::Kind::eLogAnd:
						m_result = m_exprCache.makeLogAnd( expr->getTypesCache(), std::move( lhs ), std::move( rhs ) );
						break;
					case expr::Kind::eLogOr:
						m_result = m_exprCache.makeLogOr( expr->getTypesCache(), std::move( lhs ), std::move( rhs ) );
						break;
					case expr::Kind::eLess:
						m_result = m_exprCache.makeLess( expr->getTypesCache(), std::move( lhs ), std::move( rhs ) );
						break;
					case expr::Kind::eLessEqual:
						m_result = m_exprCache.makeLessEqual( expr->getTypesCache(), std::move( lhs ), std::move( rhs ) );
						break;
					case expr::Kind::eGreater:
						m_result = m_exprCache.makeGreater( expr->getTypesCache(), std::move( lhs ), std::move( rhs ) );
						break;
					case expr::Kind::eGreaterEqual:
						m_result = m_exprCache.makeGreaterEqual( expr->getTypesCache(), std::move( lhs ), std::move( rhs ) );
						break;
					case expr::Kind::eEqual:
						m_result = m_exprCache.makeEqual( expr->getTypesCache(), std::move( lhs ), std::move( rhs ) );
						break;
					case expr::Kind::eNotEqual:
						m_result = m_exprCache.makeNotEqual( expr->getTypesCache(), std::move( lhs ), std::move( rhs ) );
						break;
					default:
						AST_Failure( "Unexpected binary expression" );
						m_result = ExprCloner::submit( m_exprCache, expr );
						break;
					}
				}
			}

			void visitAddExpr( expr::Add * expr )override
			{
				TraceFunc
				visitBinaryExpr( expr );
			}

			void visitArrayAccessExpr( expr::ArrayAccess * expr )override
			{
				TraceFunc
				bool processed = false;

				if ( expr->getLHS()->getKind() == expr::Kind::eIdentifier )
				{
					auto & ident = static_cast< expr::Identifier const & >( *expr->getLHS() );
					auto it = m_context.constAggrExprs.find( ident.getVariable()->getId() );

					if ( it != m_context.constAggrExprs.end() )
					{
						if ( expr->getRHS()->getKind() == expr::Kind::eLiteral )
						{
							auto & lit = static_cast< expr::Literal const & >( *expr->getRHS() );
							auto index = helpers::getLiteralIndex( lit );

							if ( index < it->second.size() )
							{
								processed = true;
								m_result = doSubmit( it->second[index] );
							}
							else
							{
								AST_Failure( "Out of bounds array access to constant aggr init." );
							}
						}
					}
				}

				if ( !processed
					&& expr->getLHS()->getKind() == expr::Kind::eSwizzle
					&& expr->getRHS()->getKind() == expr::Kind::eLiteral )
				{
					processed = true;
					auto & lit = static_cast< expr::Literal const & >( *expr->getRHS() );
					auto index = helpers::getLiteralIndex( lit );
					auto & outer = static_cast< expr::Swizzle & >( *expr->getLHS() );
					auto newOuter = doSubmit( outer.getOuterExpr() );
					m_result = doSubmit( m_exprCache.makeSwizzle( std::move( newOuter )
						, outer.getSwizzle()[index] ) );
				}

				if ( !processed
					&& expr->getLHS()->isConstant()
					&& expr->getLHS()->getKind() == expr::Kind::eAggrInit )
				{
					auto & aggrInit = static_cast< expr::AggrInit const & >( *expr->getLHS() );

					if ( expr->getRHS()->getKind() == expr::Kind::eLiteral )
					{
						auto & lit = static_cast< expr::Literal const & >( *expr->getRHS() );
						auto index = helpers::getLiteralIndex( lit );

						if ( index < aggrInit.getInitialisers().size() )
						{
							processed = true;
							m_result = doSubmit( aggrInit.getInitialisers()[index] );
						}
						else
						{
							AST_Failure( "Out of bounds array access to constant aggr init." );
						}
					}
				}

				if ( !processed )
				{
					m_allLiterals = false;
					ExprCloner::visitArrayAccessExpr( expr );
				}
			}

			void visitBitAndExpr( expr::BitAnd * expr )override
			{
				TraceFunc
				visitBinaryExpr( expr );
			}

			void visitBitNotExpr( expr::BitNot * expr )override
			{
				TraceFunc
				visitUnaryExpr( expr );
			}

			void visitBitOrExpr( expr::BitOr * expr )override
			{
				TraceFunc
				visitBinaryExpr( expr );
			}

			void visitBitXorExpr( expr::BitXor * expr )override
			{
				TraceFunc
				visitBinaryExpr( expr );
			}

			void visitCastExpr( expr::Cast * expr )override
			{
				TraceFunc
				auto operand = doSubmit( expr->getOperand() );

				if ( getComponentType( expr->getType() ) != type::Kind::eHalf )
				{
					visitUnaryExpr( expr );
				}
				else
				{
					m_result = ExprCloner::submit( m_exprCache, expr );
				}
			}

			void visitDivideExpr( expr::Divide * expr )override
			{
				TraceFunc
				visitBinaryExpr( expr );
			}

			void visitEqualExpr( expr::Equal * expr )override
			{
				TraceFunc
				visitBinaryExpr( expr );
			}

			void visitGreaterExpr( expr::Greater * expr )override
			{
				TraceFunc
				visitBinaryExpr( expr );
			}

			void visitGreaterEqualExpr( expr::GreaterEqual * expr )override
			{
				TraceFunc
				visitBinaryExpr( expr );
			}

			void visitIdentifierExpr( ast::expr::Identifier * expr )override
			{
				TraceFunc;
				auto var = expr->getVariable();
				auto initIt = m_context.constExprs.find( var->getId() );
				auto aggrIt = m_context.constAggrExprs.find( var->getId() );

				if ( initIt != m_context.constExprs.end() )
				{
					m_allLiterals = true;
					m_result = doSubmit( initIt->second );
				}
				else if ( aggrIt != m_context.constAggrExprs.end() )
				{
					m_allLiterals = true;
					expr::ExprList initialisers;

					for ( auto & init : aggrIt->second )
					{
						initialisers.push_back( doSubmit( init ) );
					}

					m_result = m_exprCache.makeAggrInit( expr->getType(), std::move( initialisers ) );
				}
				else
				{
					m_allLiterals = false;
					ExprCloner::visitIdentifierExpr( expr );
				}
			}

			void visitInitExpr( expr::Init * expr )override
			{
				TraceFunc
				auto allLiterals = true;
				auto init = doSubmit( expr->getInitialiser(), allLiterals );
				m_allLiterals = m_allLiterals && allLiterals;
				m_result = m_exprCache.makeInit( m_exprCache.makeIdentifier( *expr->getIdentifier() )
					, std::move( init ) );
			}

			void visitLessExpr( expr::Less * expr )override
			{
				TraceFunc
				visitBinaryExpr( expr );
			}

			void visitLessEqualExpr( expr::LessEqual * expr )override
			{
				TraceFunc
				visitBinaryExpr( expr );
			}

			void visitLiteralExpr( expr::Literal * expr )override
			{
				TraceFunc
				ExprCloner::visitLiteralExpr( expr );
			}

			void visitLogAndExpr( expr::LogAnd * expr )override
			{
				TraceFunc
				visitBinaryExpr( expr );
			}

			void visitLogNotExpr( expr::LogNot * expr )override
			{
				TraceFunc
				visitUnaryExpr( expr );
			}

			void visitLogOrExpr( expr::LogOr * expr )override
			{
				TraceFunc
				visitBinaryExpr( expr );
			}

			void visitLShiftExpr( expr::LShift * expr )override
			{
				TraceFunc
				visitBinaryExpr( expr );
			}

			void visitMbrSelectExpr( expr::MbrSelect * expr )override
			{
				TraceFunc
				bool processed = false;

				if ( expr->getOuterExpr()->getKind() == expr::Kind::eIdentifier )
				{
					auto & ident = static_cast< expr::Identifier const & >( *expr->getOuterExpr() );
					auto it = m_context.constAggrExprs.find( ident.getVariable()->getId() );

					if ( it != m_context.constAggrExprs.end() )
					{
						if ( expr->getMemberIndex() < it->second.size() )
						{
							processed = true;
							m_result = doSubmit( it->second[expr->getMemberIndex()] );
						}
						else
						{
							AST_Failure( "Out of bounds array access to constant aggr init." );
						}
					}
				}

				if ( !processed )
				{
					m_allLiterals = false;
					ExprCloner::visitMbrSelectExpr( expr );
				}
			}

			void visitMinusExpr( expr::Minus * expr )override
			{
				TraceFunc
				visitBinaryExpr( expr );
			}

			void visitModuloExpr( expr::Modulo * expr )override
			{
				TraceFunc
				visitBinaryExpr( expr );
			}

			void visitNotEqualExpr( expr::NotEqual * expr )override
			{
				TraceFunc
				visitBinaryExpr( expr );
			}

			void visitRShiftExpr( expr::RShift * expr )override
			{
				TraceFunc
				visitBinaryExpr( expr );
			}

			void visitSwizzleExpr( expr::Swizzle * expr )override
			{
				TraceFunc
				bool processed = false;

				if ( expr->getOuterExpr()->getKind() == expr::Kind::eIdentifier )
				{
					auto variable = static_cast< expr::Identifier const & >( *expr->getOuterExpr() ).getVariable();
					auto it = m_context.constAggrExprs.find( variable->getId() );

					if ( it != m_context.constAggrExprs.end() )
					{
						auto indices = getSwizzleIndices( expr->getSwizzle() );
						expr::ExprList initialisers;
						processed = true;

						for ( auto index : indices )
						{
							initialisers.push_back( doSubmit( it->second[index] ) );
						}

						if ( indices.size() > 1u )
						{
							auto scalarType = getScalarType( expr->getType()->getKind() );
							m_result = m_exprCache.makeCompositeConstruct( getCompositeType( expr->getType()->getKind() )
								, scalarType
								, std::move( initialisers ) );
						}
						else
						{
							m_result = std::move( initialisers.front() );
						}
					}
				}

				if ( !processed )
				{
					ExprCloner::visitSwizzleExpr( expr );
				}
			}

			void visitTimesExpr( expr::Times * expr )override
			{
				TraceFunc
				visitBinaryExpr( expr );
			}

			void visitUnaryMinusExpr( expr::UnaryMinus * expr )override
			{
				TraceFunc
				visitUnaryExpr( expr );
			}

			void visitUnaryPlusExpr( expr::UnaryPlus * expr )override
			{
				TraceFunc
					auto allLiterals = true;
				m_result = doSubmit( expr->getOperand(), allLiterals );
				m_allLiterals = m_allLiterals && allLiterals;
			}

			void visitAddAssignExpr( ast::expr::AddAssign * expr )override
			{
				AST_Failure( "Unexpected AddAssign expression" );
			}

			void visitAndAssignExpr( ast::expr::AndAssign * expr )override
			{
				AST_Failure( "Unexpected AndAssign expression" );
			}

			void visitDivideAssignExpr( ast::expr::DivideAssign * expr )override
			{
				AST_Failure( "Unexpected DivideAssign expression" );
			}

			void visitLShiftAssignExpr( ast::expr::LShiftAssign * expr )override
			{
				AST_Failure( "Unexpected LShiftAssign expression" );
			}

			void visitMinusAssignExpr( ast::expr::MinusAssign * expr )override
			{
				AST_Failure( "Unexpected MinusAssign expression" );
			}

			void visitModuloAssignExpr( ast::expr::ModuloAssign * expr )override
			{
				AST_Failure( "Unexpected ModuloAssign expression" );
			}

			void visitOrAssignExpr( ast::expr::OrAssign * expr )override
			{
				AST_Failure( "Unexpected OrAssign expression" );
			}

			void visitRShiftAssignExpr( ast::expr::RShiftAssign * expr )override
			{
				AST_Failure( "Unexpected RShiftAssign expression" );
			}

			void visitTimesAssignExpr( ast::expr::TimesAssign * expr )override
			{
				AST_Failure( "Unexpected TimesAssign expression" );
			}

			void visitXorAssignExpr( ast::expr::XorAssign * expr )override
			{
				AST_Failure( "Unexpected XorAssign expression" );
			}

		private:
			ConstantsContext & m_context;
			bool & m_allLiterals;
		};

		class StmtEvaluator
			: public StmtCloner
		{
		public:
			static stmt::ContainerPtr submit( stmt::StmtCache & stmtCache
				, expr::ExprCache & exprCache
				, type::TypesCache & typesCache
				, stmt::Container * stmt
				, ConstantsContext & context )
			{
				std::vector< stmt::Container * > contStack;
				return submit( stmtCache, exprCache, typesCache, stmt, context, contStack );
			}

		private:
			static stmt::ContainerPtr submit( stmt::StmtCache & stmtCache
				, expr::ExprCache & exprCache
				, type::TypesCache & typesCache
				, stmt::Container * stmt
				, ConstantsContext & context
				, std::vector< stmt::Container * > & contStack )
			{
				auto result = stmtCache.makeContainer();
				StmtEvaluator vis{ stmtCache, exprCache, typesCache, context, contStack, result };
				stmt->accept( &vis );
				return result;
			}

		private:
			StmtEvaluator( stmt::StmtCache & stmtCache
				, expr::ExprCache & exprCache
				, type::TypesCache & typesCache
				, ConstantsContext & context
				, std::vector< stmt::Container * > & contStack
				, stmt::ContainerPtr & result )
				: StmtCloner{ stmtCache, exprCache, result }
				, m_typesCache{ typesCache }
				, m_contStack{ contStack }
				, m_context{ context }
			{
			}

			using ast::StmtCloner::doSubmit;

			expr::ExprPtr doSubmit( expr::Expr * expr )override
			{
				bool allLiterals{ true };
				return doSubmit( expr, allLiterals );
			}

			expr::ExprPtr doSubmit( expr::Expr * expr, bool & allLiterals )
			{
				return ExprEvaluator::submit( m_exprCache, expr, m_context );
			}

			void processIfStmt( stmt::Container * stmt
				, ast::expr::ExprPtr ctrlExpr
				, bool & first
				, bool & stopped
				, uint32_t & ifs
				, uint32_t & elses )
			{
				TraceFunc
					if ( stopped )
					{
						return;
					}

				auto save = m_current;
				auto cont = m_stmtCache.makeContainer();
				m_current = cont.get();
				visitContainerStmt( stmt );
				m_current = save;

				if ( cont->empty() )
				{
					auto ifStmt = m_stmtCache.makeIf( std::move( ctrlExpr ) );

					m_ifStmts.push_back( ifStmt.get() );
					m_current->addStmt( std::move( ifStmt ) );
					++ifs;
					first = true;
				}
				else
				{
					auto ifStmt = m_stmtCache.makeIf( std::move( ctrlExpr ) );
					m_current = ifStmt.get();
					visitContainerStmt( cont.get() );
					m_current = save;

					m_ifStmts.push_back( ifStmt.get() );
					m_current->addStmt( std::move( ifStmt ) );
					++ifs;
					first = false;
				}
			}

			void processElseIfStmt( stmt::ElseIf * stmt
				, bool & first
				, bool & stopped
				, uint32_t & ifs
				, uint32_t & elses )
			{
				TraceFunc
					if ( stopped )
					{
						return;
					}

				bool allLiterals{ true };
				auto ctrlExpr = doSubmit( stmt->getCtrlExpr(), allLiterals );

				if ( ctrlExpr->getKind() == ast::expr::Kind::eLiteral )
				{
					auto & ctrlValue = static_cast< ast::expr::Literal const & >( *ctrlExpr );

					if ( ctrlValue.getValue< ast::expr::LiteralType::eBool >() )
					{
						processElseStmt( stmt, first, stopped, ifs, elses );
						stopped = true;
					}
				}
				else if ( first )
				{
					processIfStmt( stmt, std::move( ctrlExpr ), first, stopped, ifs, elses );
				}
				else
				{
					auto save = m_current;
					auto cont = m_stmtCache.makeContainer();
					m_current = cont.get();
					visitContainerStmt( stmt );
					m_current = save;

					if ( cont->empty() )
					{
						auto elseStmt = m_ifStmts.back()->createElse();
						m_current = elseStmt;
						auto ifStmt = m_stmtCache.makeIf( m_exprCache.makeLogNot( m_typesCache
							, std::move( ctrlExpr ) ) );

						m_ifStmts.push_back( ifStmt.get() );
						m_current->addStmt( std::move( ifStmt ) );
						m_contStack.push_back( save );
						++ifs;
						++elses;
						m_current = save;
						first = true;
					}
					else
					{
						auto elseStmt = m_ifStmts.back()->createElseIf( std::move( ctrlExpr ) );
						m_current = elseStmt;
						visitContainerStmt( cont.get() );
						m_current = save;
					}
				}
			}

			void processElseStmt( stmt::Container * stmt
				, bool & first
				, bool & stopped
				, uint32_t & ifs
				, uint32_t & elses )
			{
				TraceFunc
					if ( stopped )
					{
						return;
					}

				if ( first )
				{
					visitContainerStmt( stmt );
					first = false;
				}
				else
				{
					auto save = m_current;
					auto cont = m_stmtCache.makeContainer();
					m_current = cont.get();
					visitContainerStmt( stmt );
					m_current = save;

					if ( !cont->empty() )
					{
						auto elseStmt = m_ifStmts.back()->createElse();
						m_current = elseStmt;
						visitContainerStmt( cont.get() );
						m_current = save;
					}
				}
			}

		private:
			void visitContainerStmt( stmt::Container * cont )override
			{
				TraceFunc
				m_container = cont;

				for ( auto & stmt : *cont )
				{
					stmt->accept( this );
				}
			}

			void visitIfStmt( stmt::If * stmt )override
			{
				TraceFunc
				auto ctrlExpr = doSubmit( stmt->getCtrlExpr() );
				bool first = true;
				bool stopped = false;
				uint32_t ifs{};
				uint32_t elses{};

				if ( ctrlExpr->getKind() == ast::expr::Kind::eLiteral )
				{
					auto & ctrlValue = static_cast< ast::expr::Literal const & >( *ctrlExpr );

					if ( ctrlValue.getValue< ast::expr::LiteralType::eBool >() )
					{
						visitContainerStmt( stmt );
						return;
					}

					if ( stmt->getElseIfList().empty() )
					{
						if ( stmt->getElse() )
						{
							visitContainerStmt( stmt->getElse() );
						}

						return;
					}
				}
				else
				{
					processIfStmt( stmt, std::move( ctrlExpr ), first, stopped, ifs, elses );
				}

				for ( auto & elseIf : stmt->getElseIfList() )
				{
					processElseIfStmt( elseIf.get(), first, stopped, ifs, elses );
				}

				if ( stmt->getElse() )
				{
					processElseStmt( stmt->getElse(), first, stopped, ifs, elses );
				}

				while ( ifs-- )
				{
					m_ifStmts.pop_back();
				}

				while ( elses-- )
				{
					m_current = m_contStack.back();
					m_contStack.pop_back();
				}
			}

			void visitSimpleStmt( ast::stmt::Simple * stmt )override
			{
				TraceFunc;
				bool processed = false;

				if ( stmt->getExpr()->isConstant() )
				{
					if ( stmt->getExpr()->getKind() == ast::expr::Kind::eInit )
					{
						auto init = static_cast< ast::expr::Init * >( stmt->getExpr() );

						if ( auto ident = init->getIdentifier() )
						{
							if ( init->getInitialiser()->getKind() == ast::expr::Kind::eCompositeConstruct )
							{
								auto compositeCtor = static_cast< ast::expr::CompositeConstruct * >( init->getInitialiser() );

								if ( !helpers::needsVariableDecl( ident->getVariable(), m_container ) )
								{
									ast::expr::ExprList initialisers;

									for ( auto & arg : compositeCtor->getArgList() )
									{
										initialisers.emplace_back( doSubmit( arg.get() ) );
									}

									m_context.constAggrExprs.emplace( ident->getVariable()->getId()
										, std::move( initialisers ) );
									processed = true;
								}
							}
							else
							{
								m_context.constExprs.emplace( ident->getVariable()->getId()
									, doSubmit( init->getInitialiser() ) );
							}

							processed = true;
						}
					}
					else if ( stmt->getExpr()->getKind() == ast::expr::Kind::eAggrInit )
					{
						auto aggrInit = static_cast< ast::expr::AggrInit * >( stmt->getExpr() );

						if ( auto ident = aggrInit->getIdentifier() )
						{
							if ( !helpers::needsVariableDecl( ident->getVariable(), m_container ) )
							{
								ast::expr::ExprList initialisers;

								for ( auto & init : aggrInit->getInitialisers() )
								{
									initialisers.emplace_back( doSubmit( init.get() ) );
								}

								m_context.constAggrExprs.emplace( ident->getVariable()->getId()
									, std::move( initialisers ) );
								processed = true;
							}
						}
					}
				}

				if ( !processed )
				{
					StmtCloner::visitSimpleStmt( stmt );
				}
			}

			void visitSwitchStmt( ast::stmt::Switch * stmt )override
			{
				TraceFunc;
				bool processed = false;
				auto testExpr = doSubmit( stmt->getTestExpr() );
				auto testValueExpr = static_cast< expr::SwitchTest const & >( *testExpr ).getValue();

				if ( testValueExpr->getKind() == ast::expr::Kind::eLiteral )
				{
					auto it = std::find_if( stmt->begin()
						, stmt->end()
						, [this, testValueExpr]( stmt::StmtPtr const & lookup )
						{
							auto & caseStmt = static_cast< stmt::SwitchCase const & >( *lookup );
							bool result = false;

							if ( caseStmt.getCaseExpr() )
							{
								auto caseExpr = doSubmit( caseStmt.getCaseExpr() );
								auto caseValueExpr = static_cast< expr::SwitchCase const & >( *caseExpr ).getLabel();

								if ( caseValueExpr->getKind() == expr::Kind::eLiteral )
								{
									auto litResult = static_cast< expr::Literal const & >( *caseValueExpr ) == static_cast< expr::Literal const & >( *testValueExpr );
									result = litResult->getValue< expr::LiteralType::eBool >();
								}
							}

							return result;
						} );

					if ( it != stmt->end() )
					{
						processed = true;
						visitContainerStmt( &static_cast< stmt::SwitchCase & >( **it ) );
					}
					else if ( !static_cast< stmt::SwitchCase const & >( *stmt->back() ).getCaseExpr() )
					{
						processed = true;
						visitContainerStmt( &static_cast< stmt::SwitchCase & >( *stmt->back() ) );
					}
				}

				if ( !processed )
				{
					StmtCloner::visitSwitchStmt( stmt );
				}
			}

		private:
			type::TypesCache & m_typesCache;
			std::vector< stmt::Container * > & m_contStack;
			stmt::Container * m_container;
			ConstantsContext & m_context;
		};
	}

	stmt::ContainerPtr resolveConstants( stmt::StmtCache & stmtCache
		, expr::ExprCache & exprCache
		, type::TypesCache & typesCache
		, stmt::Container * stmt )
	{
		constants::ConstantsContext context{ &stmtCache.getAllocator() };
		return constants::StmtEvaluator::submit( stmtCache, exprCache, typesCache, stmt, context );
	}

	expr::ExprPtr resolveConstants( expr::ExprCache & exprCache
		, expr::Expr * expr )
	{
		constants::ConstantsContext context{ &exprCache.getAllocator() };
		return constants::ExprEvaluator::submit( exprCache, expr, context );
	}
}
