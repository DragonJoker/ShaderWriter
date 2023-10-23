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
#include "ShaderAST/Visitors/GetExprName.hpp"
#include "ShaderAST/Visitors/SimplifyStatements.hpp"

#include <cmath>
#include <math.h>

namespace ast
{
	namespace constants
	{
		bool isAllLiterals( expr::Expr * expr );

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

					void visitExprIdentifiers( expr::Expr * expr )
					{
						auto idents = listIdentifiers( expr );

						for ( auto & ident : idents )
						{
							if ( ident->getVariable()->getId() == m_variable->getId() )
							{
								m_result = true;
							}
						}
					}

					void visitArrayAccessExpr( ast::expr::ArrayAccess* expr )override
					{
						if ( !isAllLiterals( expr->getRHS() ) )
						{
							visitExprIdentifiers( expr->getLHS() );
						}
						else
						{
							expr->getLHS()->accept( this );
						}

						expr->getRHS()->accept( this );
					}

					void visitAssignExpr( ast::expr::Assign * expr )override
					{
						visitExprIdentifiers( expr->getLHS() );
						expr->getRHS()->accept( this );
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

					void visitCombinedImageAccessCallExpr( ast::expr::CombinedImageAccessCall * expr )override
					{
						for ( auto & arg : expr->getArgList() )
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

					void visitFnCallExpr( ast::expr::FnCall * expr )override
					{
						expr->getFn()->accept( this );
						auto & fnType = static_cast< type::Function const & >( *expr->getFn()->getType() );
						auto paramIt = fnType.begin();

						for ( auto & arg : expr->getArgList() )
						{
							auto identifiers = listIdentifiers( arg.get() );

							if ( !identifiers.empty() )
							{
								for ( auto ident : identifiers )
								{
									if ( ident->getVariable()->getId() == m_variable->getId() )
									{
										m_result = ( *paramIt )->isOutputParam();
									}
								}
							}
							else
							{
								arg->accept( this );
							}

							++paramIt;
						}
					}

					void visitIdentifierExpr( ast::expr::Identifier * expr )override
					{
					}

					void visitImageAccessCallExpr( ast::expr::StorageImageAccessCall * expr )override
					{
						for ( auto & arg : expr->getArgList() )
						{
							arg->accept( this );
						}
					}

					void visitInitExpr( ast::expr::Init * expr )override
					{
						expr->getIdentifier()->accept( this );
						expr->getInitialiser()->accept( this );
					}

					void visitIntrinsicCallExpr( ast::expr::IntrinsicCall * expr )override
					{
						for ( auto & arg : expr->getArgList() )
						{
							arg->accept( this );
						}
					}

					void visitLiteralExpr( ast::expr::Literal * expr )override
					{
					}

					void visitMbrSelectExpr( ast::expr::MbrSelect * expr )override
					{
						expr->getOuterExpr()->accept( this );
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

					void visitPostDecrementExpr(expr::PostDecrement * expr)override
					{
						AST_Failure( "Unexpected PostDecrement expression" );
					}

					void visitPostIncrementExpr(expr::PostIncrement * expr)override
					{
						AST_Failure( "Unexpected PostIncrement expression" );
					}

					void visitPreDecrementExpr(expr::PreDecrement * expr)override
					{
						AST_Failure( "Unexpected PreDecrement expression" );
					}

					void visitPreIncrementExpr(expr::PreIncrement * expr)override
					{
						AST_Failure( "Unexpected PreIncrement expression" );
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

						for ( auto & elseIf : stmt->getElseIfList() )
						{
							visitContainerStmt( elseIf.get() );
						}

						if ( stmt->getElse() )
						{
							visitContainerStmt( stmt->getElse() );
						}
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

			static expr::ExprPtr getNthValue( expr::Expr const & init, uint32_t index )
			{
				if ( init.getKind() == expr::Kind::eAggrInit )
				{
					return static_cast< expr::AggrInit const & >( init ).getInitialisers()[index]->clone();
				}
				else if ( init.getKind() == expr::Kind::eCompositeConstruct )
				{
					return static_cast< expr::CompositeConstruct const & >( init ).getArgList()[index]->clone();
				}
				else
				{
					AST_Failure( "Non valid expression type to retrieve index value on." );
					return init.getExprCache().makeSwizzle( init.clone(), expr::SwizzleKind::fromOffset( index ) );
				}
			}

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

			static expr::ExprList getArgList( expr::Expr * expr )
			{
				expr::ExprList result;

				if ( expr->getKind() == expr::Kind::eCompositeConstruct )
				{
					for ( auto & arg : static_cast< expr::CompositeConstruct const & >( *expr ).getArgList() )
					{
						result.push_back( arg->clone() );
					}
				}
				else if ( expr->getKind() == expr::Kind::eAggrInit )
				{
					for ( auto & arg : static_cast< expr::AggrInit const & >( *expr ).getInitialisers() )
					{
						result.push_back( arg->clone() );
					}
				}
				else if ( expr->getKind() == expr::Kind::eLiteral )
				{
					result.push_back( expr->clone() );
				}
				else
				{
					throw std::invalid_argument{ "Can't process this expression" };
				}

				return result;
			}

			template< typename ValueT, size_t CountT >
			static DataT< ValueT, CountT > getData( expr::ExprPtr const & arg )
			{
				auto args = getArgList( arg.get() );

				if constexpr ( CountT == 1u )
				{
					return DataT< ValueT, 1u >{ static_cast< expr::Literal const & >( *args[0] ).getValue< literalT< ValueT > >() };
				}
				else if constexpr ( CountT == 2u )
				{
					return DataT< ValueT, 2u >{ static_cast< expr::Literal const & >( *args[0] ).getValue< literalT< ValueT > >()
						, static_cast< expr::Literal const & >( *args[1] ).getValue< literalT< ValueT > >() };
				}
				else if constexpr ( CountT == 3u )
				{
					return DataT< ValueT, 3u >{ static_cast< expr::Literal const & >( *args[0] ).getValue< literalT< ValueT > >()
						, static_cast< expr::Literal const & >( *args[1] ).getValue< literalT< ValueT > >()
						, static_cast< expr::Literal const & >( *args[2] ).getValue< literalT< ValueT > >() };
				}
				else if constexpr ( CountT == 4u )
				{
					return DataT< ValueT, 4u >{ static_cast< expr::Literal const & >( *args[0] ).getValue< literalT< ValueT > >()
						, static_cast< expr::Literal const & >( *args[1] ).getValue< literalT< ValueT > >()
						, static_cast< expr::Literal const & >( *args[2] ).getValue< literalT< ValueT > >()
						, static_cast< expr::Literal const & >( *args[3] ).getValue< literalT< ValueT > >() };
				}
			}

			template< typename ValueT, typename ValueU, size_t CountT, typename FuncT >
			static DataT< ValueU, CountT > process1T( expr::ExprCache & exprCache
				, DataT< ValueT, CountT > args
				, FuncT func )
			{
				DataT< ValueU, CountT > result;
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

			template< typename ValueT, typename ValueU, size_t CountT, typename FuncT >
			static DataT< ValueU, CountT > process2T( expr::ExprCache & exprCache
				, DataT< ValueT, CountT > args1
				, DataT< ValueT, CountT > args2
				, FuncT func )
			{
				DataT< ValueU, CountT > result;
				auto itDst = result.begin();
				auto itSrc1 = args1.begin();
				auto itSrc2 = args2.begin();

				while ( itSrc1 != args1.end() )
				{
					*itDst = func( *itSrc1, *itSrc2 );
					++itSrc1;
					++itSrc2;
					++itDst;
				}

				return result;
			}

			template< typename ValueT, typename ValueU, size_t CountT, typename FuncT >
			static DataT< ValueU, CountT > process3T( expr::ExprCache & exprCache
				, DataT< ValueT, CountT > args1
				, DataT< ValueT, CountT > args2
				, DataT< ValueT, CountT > args3
				, FuncT func )
			{
				DataT< ValueU, CountT > result;
				auto itDst = result.begin();
				auto itSrc1 = args1.begin();
				auto itSrc2 = args2.begin();
				auto itSrc3 = args3.begin();

				while ( itSrc1 != args1.end() )
				{
					*itDst = func( *itSrc1, *itSrc2, *itSrc3 );
					++itSrc1;
					++itSrc2;
					++itSrc3;
					++itDst;
				}

				return result;
			}

			static expr::ExprList makeList( expr::ExprPtr arg0
				, expr::ExprPtr arg1 )
			{
				expr::ExprList result;
				result.push_back( std::move( arg0 ) );
				result.push_back( std::move( arg1 ) );
				return result;
			}

			static expr::ExprList makeList( expr::ExprPtr arg0
				, expr::ExprPtr arg1
				, expr::ExprPtr arg2 )
			{
				expr::ExprList result;
				result.push_back( std::move( arg0 ) );
				result.push_back( std::move( arg1 ) );
				result.push_back( std::move( arg2 ) );
				return result;
			}

			static expr::ExprList makeList( expr::ExprPtr arg0
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

			template< typename ValueT, typename ValueU, size_t CountT, typename FuncT >
			static expr::ExprPtr apply1T( type::TypesCache & typesCache
				, expr::ExprCache & exprCache
				, DataT< ValueT, CountT > args
				, FuncT func )
			{
				DataT< ValueU, CountT > result = process1T< ValueT, ValueU >( exprCache, std::move( args ), func );

				switch ( CountT )
				{
				case 1u:
					return exprCache.makeLiteral( typesCache, result.front() );
				case 2u:
					return exprCache.makeCompositeConstruct( expr::CompositeType::eVec2
						, kindT< ValueU >
						, makeList( exprCache.makeLiteral( typesCache, result[0] )
							, exprCache.makeLiteral( typesCache, result[1] ) ) );
				case 3u:
					return exprCache.makeCompositeConstruct( expr::CompositeType::eVec3
						, kindT< ValueU >
						, makeList( exprCache.makeLiteral( typesCache, result[0] )
							, exprCache.makeLiteral( typesCache, result[1] )
							, exprCache.makeLiteral( typesCache, result[2] ) ) );
				case 4u:
					return exprCache.makeCompositeConstruct( expr::CompositeType::eVec4
						, kindT< ValueU >
						, makeList( exprCache.makeLiteral( typesCache, result[0] )
							, exprCache.makeLiteral( typesCache, result[1] )
							, exprCache.makeLiteral( typesCache, result[2] )
							, exprCache.makeLiteral( typesCache, result[3] ) ) );
				default:
					return nullptr;
				}
			}

			template< typename ValueT, typename ValueU, size_t CountT, typename FuncT >
			static expr::ExprPtr apply2T( type::TypesCache & typesCache
				, expr::ExprCache & exprCache
				, DataT< ValueT, CountT > args1
				, DataT< ValueT, CountT > args2
				, FuncT func )
			{
				DataT< ValueU, CountT > result = process2T< ValueT, ValueU >( exprCache, std::move( args1 ), std::move( args2 ), func );

				switch ( CountT )
				{
				case 1u:
					return exprCache.makeLiteral( typesCache, result.front() );
				case 2u:
					return exprCache.makeCompositeConstruct( expr::CompositeType::eVec2
						, kindT< ValueU >
						, makeList( exprCache.makeLiteral( typesCache, result[0] )
							, exprCache.makeLiteral( typesCache, result[1] ) ) );
				case 3u:
					return exprCache.makeCompositeConstruct( expr::CompositeType::eVec3
						, kindT< ValueU >
						, makeList( exprCache.makeLiteral( typesCache, result[0] )
							, exprCache.makeLiteral( typesCache, result[1] )
							, exprCache.makeLiteral( typesCache, result[2] ) ) );
				case 4u:
					return exprCache.makeCompositeConstruct( expr::CompositeType::eVec4
						, kindT< ValueU >
						, makeList( exprCache.makeLiteral( typesCache, result[0] )
							, exprCache.makeLiteral( typesCache, result[1] )
							, exprCache.makeLiteral( typesCache, result[2] )
							, exprCache.makeLiteral( typesCache, result[3] ) ) );
				default:
					return nullptr;
				}
			}

			template< typename ValueT, typename ValueU, size_t CountT, typename FuncT >
			static expr::ExprPtr apply3T( type::TypesCache & typesCache
				, expr::ExprCache & exprCache
				, DataT< ValueT, CountT > args1
				, DataT< ValueT, CountT > args2
				, DataT< ValueT, CountT > args3
				, FuncT func )
			{
				DataT< ValueU, CountT > result = process3T< ValueT, ValueU >( exprCache, std::move( args1 ), std::move( args2 ), std::move( args3 ), func );

				switch ( CountT )
				{
				case 1u:
					return exprCache.makeLiteral( typesCache, result.front() );
				case 2u:
					return exprCache.makeCompositeConstruct( expr::CompositeType::eVec2
						, kindT< ValueU >
						, makeList( exprCache.makeLiteral( typesCache, result[0] )
							, exprCache.makeLiteral( typesCache, result[1] ) ) );
				case 3u:
					return exprCache.makeCompositeConstruct( expr::CompositeType::eVec3
						, kindT< ValueU >
						, makeList( exprCache.makeLiteral( typesCache, result[0] )
							, exprCache.makeLiteral( typesCache, result[1] )
							, exprCache.makeLiteral( typesCache, result[2] ) ) );
				case 4u:
					return exprCache.makeCompositeConstruct( expr::CompositeType::eVec4
						, kindT< ValueU >
						, makeList( exprCache.makeLiteral( typesCache, result[0] )
							, exprCache.makeLiteral( typesCache, result[1] )
							, exprCache.makeLiteral( typesCache, result[2] )
							, exprCache.makeLiteral( typesCache, result[3] ) ) );
				default:
					return nullptr;
				}
			}

			template< typename ValueT, size_t CountT, typename FuncT >
			static expr::ExprPtr gatherT( type::TypesCache & typesCache
				, expr::ExprCache & exprCache
				, DataT< ValueT, CountT > args
				, FuncT func )
			{
				switch ( CountT )
				{
				case 2u:
					return exprCache.makeLiteral( typesCache, func( args[0], args[1] ) );
				case 3u:
					return exprCache.makeLiteral( typesCache, func( args[0], func( args[1], args[2] ) ) );
				case 4u:
					return exprCache.makeLiteral( typesCache, func( args[0], func( args[1], func( args[2], args[3] ) ) ) );
				default:
					return nullptr;
				}
			}

			template< typename ValueT, typename FuncT >
			static expr::ExprPtr intrinsic1T( type::TypesCache & typesCache
				, expr::ExprCache & exprCache
				, expr::ExprList args
				, FuncT func )
			{
				auto & arg = args.front();

				switch ( type::getComponentCount( arg->getType() ) )
				{
				case 1u: return apply1T< ValueT, ValueT >( typesCache, exprCache, getData< ValueT, 1u >( arg ), func );
				case 2u: return apply1T< ValueT, ValueT >( typesCache, exprCache, getData< ValueT, 2u >( arg ), func );
				case 3u: return apply1T< ValueT, ValueT >( typesCache, exprCache, getData< ValueT, 3u >( arg ), func );
				case 4u: return apply1T< ValueT, ValueT >( typesCache, exprCache, getData< ValueT, 4u >( arg ), func );
				default: return nullptr;
				}
			}

			template< typename ValueT, typename FuncT >
			static expr::ExprPtr intrinsic1BoolT( type::TypesCache & typesCache
				, expr::ExprCache & exprCache
				, expr::ExprList args
				, FuncT func )
			{
				auto & arg = args.front();

				switch ( type::getComponentCount( arg->getType() ) )
				{
				case 1u: return apply1T< ValueT, bool >( typesCache, exprCache, getData< ValueT, 1u >( arg ), func );
				case 2u: return apply1T< ValueT, bool >( typesCache, exprCache, getData< ValueT, 2u >( arg ), func );
				case 3u: return apply1T< ValueT, bool >( typesCache, exprCache, getData< ValueT, 3u >( arg ), func );
				case 4u: return apply1T< ValueT, bool >( typesCache, exprCache, getData< ValueT, 4u >( arg ), func );
				default: return nullptr;
				}
			}

			template< typename ValueT, typename FuncT >
			static expr::ExprPtr intrinsic2T( type::TypesCache & typesCache
				, expr::ExprCache & exprCache
				, expr::ExprList args
				, FuncT func )
			{
				auto & arg1 = args.front();
				auto & arg2 = args.back();

				switch ( type::getComponentCount( arg1->getType() ) )
				{
				case 1u: return apply2T< ValueT, ValueT >( typesCache, exprCache, getData< ValueT, 1u >( arg1 ), getData< ValueT, 1u >( arg2 ), func );
				case 2u: return apply2T< ValueT, ValueT >( typesCache, exprCache, getData< ValueT, 2u >( arg1 ), getData< ValueT, 2u >( arg2 ), func );
				case 3u: return apply2T< ValueT, ValueT >( typesCache, exprCache, getData< ValueT, 3u >( arg1 ), getData< ValueT, 3u >( arg2 ), func );
				case 4u: return apply2T< ValueT, ValueT >( typesCache, exprCache, getData< ValueT, 4u >( arg1 ), getData< ValueT, 4u >( arg2 ), func );
				default: return nullptr;
				}
			}

			template< typename ValueT, typename FuncT >
			static expr::ExprPtr intrinsicCompT( type::TypesCache & typesCache
				, expr::ExprCache & exprCache
				, expr::ExprList args
				, FuncT func )
			{
				auto & arg1 = args.front();
				auto & arg2 = args.back();

				switch ( type::getComponentCount( arg1->getType() ) )
				{
				case 1u: return apply2T< ValueT, bool >( typesCache, exprCache, getData< ValueT, 1u >( arg1 ), getData< ValueT, 1u >( arg2 ), func );
				case 2u: return apply2T< ValueT, bool >( typesCache, exprCache, getData< ValueT, 2u >( arg1 ), getData< ValueT, 2u >( arg2 ), func );
				case 3u: return apply2T< ValueT, bool >( typesCache, exprCache, getData< ValueT, 3u >( arg1 ), getData< ValueT, 3u >( arg2 ), func );
				case 4u: return apply2T< ValueT, bool >( typesCache, exprCache, getData< ValueT, 4u >( arg1 ), getData< ValueT, 4u >( arg2 ), func );
				default: return nullptr;
				}
			}

			template< typename ValueT, typename FuncT >
			static expr::ExprPtr intrinsic3T( type::TypesCache & typesCache
				, expr::ExprCache & exprCache
				, expr::ExprList args
				, FuncT func )
			{
				auto & arg1 = args[0];
				auto & arg2 = args[1];
				auto & arg3 = args[2];

				switch ( type::getComponentCount( arg1->getType() ) )
				{
				case 1u: return apply3T< ValueT, ValueT >( typesCache, exprCache, getData< ValueT, 1u >( arg1 ), getData< ValueT, 1u >( arg2 ), getData< ValueT, 1u >( arg3 ), func );
				case 2u: return apply3T< ValueT, ValueT >( typesCache, exprCache, getData< ValueT, 2u >( arg1 ), getData< ValueT, 2u >( arg2 ), getData< ValueT, 2u >( arg3 ), func );
				case 3u: return apply3T< ValueT, ValueT >( typesCache, exprCache, getData< ValueT, 3u >( arg1 ), getData< ValueT, 3u >( arg2 ), getData< ValueT, 3u >( arg3 ), func );
				case 4u: return apply3T< ValueT, ValueT >( typesCache, exprCache, getData< ValueT, 4u >( arg1 ), getData< ValueT, 4u >( arg2 ), getData< ValueT, 4u >( arg3 ), func );
				default: return nullptr;
				}
			}

			template< typename ValueT, typename FuncT >
			static expr::ExprPtr intrinsicGatherT( type::TypesCache & typesCache
				, expr::ExprCache & exprCache
				, expr::ExprList args
				, FuncT func )
			{
				auto & arg = args.front();

				switch ( type::getComponentCount( arg->getType() ) )
				{
				case 2u: return gatherT< ValueT >( typesCache, exprCache, getData< ValueT, 2u >( arg ), func );
				case 3u: return gatherT< ValueT >( typesCache, exprCache, getData< ValueT, 3u >( arg ), func );
				case 4u: return gatherT< ValueT >( typesCache, exprCache, getData< ValueT, 4u >( arg ), func );
				default: return nullptr;
				}
			}

			static bool isConstantResolvable( expr::Intrinsic intrinsic )
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
					return true;
				default:
					return false;
				}
			}

			static expr::ExprPtr resolveConstant( type::TypesCache & typesCache
				, expr::ExprCache & exprCache
				, expr::Intrinsic intrinsic
				, expr::ExprList argsList )
			{
				try
				{
					switch ( intrinsic )
					{
					case ast::expr::Intrinsic::eDegrees1:
					case ast::expr::Intrinsic::eDegrees2:
					case ast::expr::Intrinsic::eDegrees3:
					case ast::expr::Intrinsic::eDegrees4:
						return intrinsic1T< float >( typesCache, exprCache, std::move( argsList ), []( float v ){ return float( v * 180.0f / 3.14159265358979323846 ); } );
					case ast::expr::Intrinsic::eRadians1F:
					case ast::expr::Intrinsic::eRadians2F:
					case ast::expr::Intrinsic::eRadians3F:
					case ast::expr::Intrinsic::eRadians4F:
						return intrinsic1T< float >( typesCache, exprCache, std::move( argsList ), []( float v ){ return float( v * 3.14159265358979323846 / 180.0f ); } );
					case ast::expr::Intrinsic::eCos1:
					case ast::expr::Intrinsic::eCos2:
					case ast::expr::Intrinsic::eCos3:
					case ast::expr::Intrinsic::eCos4:
						return intrinsic1T< float >( typesCache, exprCache, std::move( argsList ), []( float v ){ return float( ::cos( v ) ); } );
					case ast::expr::Intrinsic::eSin1:
					case ast::expr::Intrinsic::eSin2:
					case ast::expr::Intrinsic::eSin3:
					case ast::expr::Intrinsic::eSin4:
						return intrinsic1T< float >( typesCache, exprCache, std::move( argsList ), []( float v ){ return float( ::sin( v ) ); } );
					case ast::expr::Intrinsic::eTan1:
					case ast::expr::Intrinsic::eTan2:
					case ast::expr::Intrinsic::eTan3:
					case ast::expr::Intrinsic::eTan4:
						return intrinsic1T< float >( typesCache, exprCache, std::move( argsList ), []( float v ){ return float( ::tan( v ) ); } );
					case ast::expr::Intrinsic::eCosh1:
					case ast::expr::Intrinsic::eCosh2:
					case ast::expr::Intrinsic::eCosh3:
					case ast::expr::Intrinsic::eCosh4:
						return intrinsic1T< float >( typesCache, exprCache, std::move( argsList ), []( float v ){ return float( ::cosh( v ) ); } );
					case ast::expr::Intrinsic::eSinh1:
					case ast::expr::Intrinsic::eSinh2:
					case ast::expr::Intrinsic::eSinh3:
					case ast::expr::Intrinsic::eSinh4:
						return intrinsic1T< float >( typesCache, exprCache, std::move( argsList ), []( float v ){ return float( ::sinh( v ) ); } );
					case ast::expr::Intrinsic::eTanh1:
					case ast::expr::Intrinsic::eTanh2:
					case ast::expr::Intrinsic::eTanh3:
					case ast::expr::Intrinsic::eTanh4:
						return intrinsic1T< float >( typesCache, exprCache, std::move( argsList ), []( float v ){ return float( ::tanh( v ) ); } );
					case ast::expr::Intrinsic::eAcos1:
					case ast::expr::Intrinsic::eAcos2:
					case ast::expr::Intrinsic::eAcos3:
					case ast::expr::Intrinsic::eAcos4:
						return intrinsic1T< float >( typesCache, exprCache, std::move( argsList ), []( float v ){ return float( ::acos( v ) ); } );
					case ast::expr::Intrinsic::eAsin1:
					case ast::expr::Intrinsic::eAsin2:
					case ast::expr::Intrinsic::eAsin3:
					case ast::expr::Intrinsic::eAsin4:
						return intrinsic1T< float >( typesCache, exprCache, std::move( argsList ), []( float v ){ return float( ::asin( v ) ); } );
					case ast::expr::Intrinsic::eAtan1:
					case ast::expr::Intrinsic::eAtan2:
					case ast::expr::Intrinsic::eAtan3:
					case ast::expr::Intrinsic::eAtan4:
						return intrinsic1T< float >( typesCache, exprCache, std::move( argsList ), []( float v ){ return float( ::atan( v ) ); } );
					case ast::expr::Intrinsic::eAtan21:
					case ast::expr::Intrinsic::eAtan22:
					case ast::expr::Intrinsic::eAtan23:
					case ast::expr::Intrinsic::eAtan24:
						return intrinsic2T< float >( typesCache, exprCache, std::move( argsList ), []( float v, float w ){ return float( ::atan2( v, w ) ); } );
					case ast::expr::Intrinsic::eAcosh1:
					case ast::expr::Intrinsic::eAcosh2:
					case ast::expr::Intrinsic::eAcosh3:
					case ast::expr::Intrinsic::eAcosh4:
						return intrinsic1T< float >( typesCache, exprCache, std::move( argsList ), []( float v ){ return float( ::acosh( v ) ); } );
					case ast::expr::Intrinsic::eAsinh1:
					case ast::expr::Intrinsic::eAsinh2:
					case ast::expr::Intrinsic::eAsinh3:
					case ast::expr::Intrinsic::eAsinh4:
						return intrinsic1T< float >( typesCache, exprCache, std::move( argsList ), []( float v ){ return float( ::asinh( v ) ); } );
					case ast::expr::Intrinsic::eAtanh1:
					case ast::expr::Intrinsic::eAtanh2:
					case ast::expr::Intrinsic::eAtanh3:
					case ast::expr::Intrinsic::eAtanh4:
						return intrinsic1T< float >( typesCache, exprCache, std::move( argsList ), []( float v ){ return float( ::atanh( v ) ); } );
					case ast::expr::Intrinsic::ePow1:
					case ast::expr::Intrinsic::ePow2:
					case ast::expr::Intrinsic::ePow3:
					case ast::expr::Intrinsic::ePow4:
						return intrinsic2T< float >( typesCache, exprCache, std::move( argsList ), []( float v, float w ){ return float( ::pow( v, w ) ); } );
					case ast::expr::Intrinsic::eExp1:
					case ast::expr::Intrinsic::eExp2:
					case ast::expr::Intrinsic::eExp3:
					case ast::expr::Intrinsic::eExp4:
						return intrinsic1T< float >( typesCache, exprCache, std::move( argsList ), []( float v ){ return float( ::exp( v ) ); } );
					case ast::expr::Intrinsic::eLog1:
					case ast::expr::Intrinsic::eLog2:
					case ast::expr::Intrinsic::eLog3:
					case ast::expr::Intrinsic::eLog4:
						return intrinsic1T< float >( typesCache, exprCache, std::move( argsList ), []( float v ){ return float( ::log( v ) ); } );
					case ast::expr::Intrinsic::eExp21:
					case ast::expr::Intrinsic::eExp22:
					case ast::expr::Intrinsic::eExp23:
					case ast::expr::Intrinsic::eExp24:
						return intrinsic1T< float >( typesCache, exprCache, std::move( argsList ), []( float v ){ return float( ::exp2( v ) ); } );
					case ast::expr::Intrinsic::eLog21:
					case ast::expr::Intrinsic::eLog22:
					case ast::expr::Intrinsic::eLog23:
					case ast::expr::Intrinsic::eLog24:
						return intrinsic1T< float >( typesCache, exprCache, std::move( argsList ), []( float v ){ return float( ::log2( v ) ); } );
					case ast::expr::Intrinsic::eSqrt1F:
					case ast::expr::Intrinsic::eSqrt2F:
					case ast::expr::Intrinsic::eSqrt3F:
					case ast::expr::Intrinsic::eSqrt4F:
						return intrinsic1T< float >( typesCache, exprCache, std::move( argsList ), []( float v ){ return float( ::sqrt( v ) ); } );
					case ast::expr::Intrinsic::eSqrt1D:
					case ast::expr::Intrinsic::eSqrt2D:
					case ast::expr::Intrinsic::eSqrt3D:
					case ast::expr::Intrinsic::eSqrt4D:
						return intrinsic1T< double >( typesCache, exprCache, std::move( argsList ), []( double v ){ return double( ::sqrt( v ) ); } );
					case ast::expr::Intrinsic::eInverseSqrt1F:
					case ast::expr::Intrinsic::eInverseSqrt2F:
					case ast::expr::Intrinsic::eInverseSqrt3F:
					case ast::expr::Intrinsic::eInverseSqrt4F:
						return intrinsic1T< float >( typesCache, exprCache, std::move( argsList ), []( float v ){ return float( 1.0f / ::sqrt( v ) ); } );
					case ast::expr::Intrinsic::eInverseSqrt1D:
					case ast::expr::Intrinsic::eInverseSqrt2D:
					case ast::expr::Intrinsic::eInverseSqrt3D:
					case ast::expr::Intrinsic::eInverseSqrt4D:
						return intrinsic1T< double >( typesCache, exprCache, std::move( argsList ), []( double v ){ return double( 1.0 / ::sqrt( v ) ); } );
					case ast::expr::Intrinsic::eAbs1F:
					case ast::expr::Intrinsic::eAbs2F:
					case ast::expr::Intrinsic::eAbs3F:
					case ast::expr::Intrinsic::eAbs4F:
						return intrinsic1T< float >( typesCache, exprCache, std::move( argsList ), []( float v ){ return std::abs( v ); } );
					case ast::expr::Intrinsic::eAbs1I:
					case ast::expr::Intrinsic::eAbs2I:
					case ast::expr::Intrinsic::eAbs3I:
					case ast::expr::Intrinsic::eAbs4I:
						return intrinsic1T< int32_t >( typesCache, exprCache, std::move( argsList ), []( int32_t v ){ return std::abs( v ); } );
					case ast::expr::Intrinsic::eAbs1D:
					case ast::expr::Intrinsic::eAbs2D:
					case ast::expr::Intrinsic::eAbs3D:
					case ast::expr::Intrinsic::eAbs4D:
						return intrinsic1T< double >( typesCache, exprCache, std::move( argsList ), []( double v ){ return std::abs( v ); } );
					case ast::expr::Intrinsic::eSign1F:
					case ast::expr::Intrinsic::eSign2F:
					case ast::expr::Intrinsic::eSign3F:
					case ast::expr::Intrinsic::eSign4F:
						return intrinsic1T< float >( typesCache, exprCache, std::move( argsList ), []( float v ){ return float( ( float( 0.0f ) < v ) - ( v < float( 0.0f ) ) ); } );
					case ast::expr::Intrinsic::eSign1I:
					case ast::expr::Intrinsic::eSign2I:
					case ast::expr::Intrinsic::eSign3I:
					case ast::expr::Intrinsic::eSign4I:
						return intrinsic1T< int32_t >( typesCache, exprCache, std::move( argsList ), []( int32_t v ){ return ( int32_t( 0 ) < v ) - ( v < int32_t( 0 ) ); } );
					case ast::expr::Intrinsic::eSign1D:
					case ast::expr::Intrinsic::eSign2D:
					case ast::expr::Intrinsic::eSign3D:
					case ast::expr::Intrinsic::eSign4D:
						return intrinsic1T< double >( typesCache, exprCache, std::move( argsList ), []( double v ){ return double( ( double( 0 ) < v ) - ( v < double( 0 ) ) ); } );
					case ast::expr::Intrinsic::eFloor1F:
					case ast::expr::Intrinsic::eFloor2F:
					case ast::expr::Intrinsic::eFloor3F:
					case ast::expr::Intrinsic::eFloor4F:
						return intrinsic1T< float >( typesCache, exprCache, std::move( argsList ), []( float v ){ return std::floor( v ); } );
					case ast::expr::Intrinsic::eFloor1D:
					case ast::expr::Intrinsic::eFloor2D:
					case ast::expr::Intrinsic::eFloor3D:
					case ast::expr::Intrinsic::eFloor4D:
						return intrinsic1T< double >( typesCache, exprCache, std::move( argsList ), []( double v ){ return std::floor( v ); } );
					case ast::expr::Intrinsic::eTrunc1F:
					case ast::expr::Intrinsic::eTrunc2F:
					case ast::expr::Intrinsic::eTrunc3F:
					case ast::expr::Intrinsic::eTrunc4F:
						return intrinsic1T< float >( typesCache, exprCache, std::move( argsList ), []( float v ){ return std::trunc( v ); } );
					case ast::expr::Intrinsic::eTrunc1D:
					case ast::expr::Intrinsic::eTrunc2D:
					case ast::expr::Intrinsic::eTrunc3D:
					case ast::expr::Intrinsic::eTrunc4D:
						return intrinsic1T< double >( typesCache, exprCache, std::move( argsList ), []( double v ){ return std::trunc( v ); } );
					case ast::expr::Intrinsic::eRound1F:
					case ast::expr::Intrinsic::eRound2F:
					case ast::expr::Intrinsic::eRound3F:
					case ast::expr::Intrinsic::eRound4F:
						return intrinsic1T< float >( typesCache, exprCache, std::move( argsList ), []( float v ){ return std::round( v ); } );
					case ast::expr::Intrinsic::eRound1D:
					case ast::expr::Intrinsic::eRound2D:
					case ast::expr::Intrinsic::eRound3D:
					case ast::expr::Intrinsic::eRound4D:
						return intrinsic1T< double >( typesCache, exprCache, std::move( argsList ), []( double v ){ return std::round( v ); } );
					case ast::expr::Intrinsic::eRoundEven1F:
					case ast::expr::Intrinsic::eRoundEven2F:
					case ast::expr::Intrinsic::eRoundEven3F:
					case ast::expr::Intrinsic::eRoundEven4F:
						return intrinsic1T< float >( typesCache, exprCache, std::move( argsList ), []( float v ){ return float( int( v + float( int( v ) % 2 ) ) ); } );
					case ast::expr::Intrinsic::eRoundEven1D:
					case ast::expr::Intrinsic::eRoundEven2D:
					case ast::expr::Intrinsic::eRoundEven3D:
					case ast::expr::Intrinsic::eRoundEven4D:
						return intrinsic1T< double >( typesCache, exprCache, std::move( argsList ), []( double v ){ return double( int( v + double( int( v ) % 2 ) ) ); } );
					case ast::expr::Intrinsic::eCeil1F:
					case ast::expr::Intrinsic::eCeil2F:
					case ast::expr::Intrinsic::eCeil3F:
					case ast::expr::Intrinsic::eCeil4F:
						return intrinsic1T< float >( typesCache, exprCache, std::move( argsList ), []( float v ){ return std::ceil( v ); } );
					case ast::expr::Intrinsic::eCeil1D:
					case ast::expr::Intrinsic::eCeil2D:
					case ast::expr::Intrinsic::eCeil3D:
					case ast::expr::Intrinsic::eCeil4D:
						return intrinsic1T< double >( typesCache, exprCache, std::move( argsList ), []( double v ){ return std::ceil( v ); } );
					case ast::expr::Intrinsic::eFract1F:
					case ast::expr::Intrinsic::eFract2F:
					case ast::expr::Intrinsic::eFract3F:
					case ast::expr::Intrinsic::eFract4F:
						return intrinsic1T< float >( typesCache, exprCache, std::move( argsList ), []( float v ){ return v - float( int64_t( v ) ); } );
					case ast::expr::Intrinsic::eFract1D:
					case ast::expr::Intrinsic::eFract2D:
					case ast::expr::Intrinsic::eFract3D:
					case ast::expr::Intrinsic::eFract4D:
						return intrinsic1T< double >( typesCache, exprCache, std::move( argsList ), []( double v ){ return v - double( int64_t( v ) ); } );
					case ast::expr::Intrinsic::eMod1F:
					case ast::expr::Intrinsic::eMod2F:
					case ast::expr::Intrinsic::eMod3F:
					case ast::expr::Intrinsic::eMod4F:
						return intrinsic2T< float >( typesCache, exprCache, std::move( argsList ), []( float v, float w ){ return v - w * std::floor( v / w ); } );
					case ast::expr::Intrinsic::eMod1D:
					case ast::expr::Intrinsic::eMod2D:
					case ast::expr::Intrinsic::eMod3D:
					case ast::expr::Intrinsic::eMod4D:
						return intrinsic2T< double >( typesCache, exprCache, std::move( argsList ), []( double v, double w ){ return v - w * std::floor( v / w ); } );
					case ast::expr::Intrinsic::eMin1F:
					case ast::expr::Intrinsic::eMin2F:
					case ast::expr::Intrinsic::eMin3F:
					case ast::expr::Intrinsic::eMin4F:
						return intrinsic2T< float >( typesCache, exprCache, std::move( argsList ), []( float v, float w ){ return std::min( v, w ); } );
					case ast::expr::Intrinsic::eMin1D:
					case ast::expr::Intrinsic::eMin2D:
					case ast::expr::Intrinsic::eMin3D:
					case ast::expr::Intrinsic::eMin4D:
						return intrinsic2T< double >( typesCache, exprCache, std::move( argsList ), []( double v, double w ){ return std::min( v, w ); } );
					case ast::expr::Intrinsic::eMin1I:
					case ast::expr::Intrinsic::eMin2I:
					case ast::expr::Intrinsic::eMin3I:
					case ast::expr::Intrinsic::eMin4I:
						return intrinsic2T< int32_t >( typesCache, exprCache, std::move( argsList ), []( int32_t v, int32_t w ){ return std::min( v, w ); } );
					case ast::expr::Intrinsic::eMin1U:
					case ast::expr::Intrinsic::eMin2U:
					case ast::expr::Intrinsic::eMin3U:
					case ast::expr::Intrinsic::eMin4U:
						return intrinsic2T< uint32_t >( typesCache, exprCache, std::move( argsList ), []( uint32_t v, uint32_t w ){ return std::min( v, w ); } );
					case ast::expr::Intrinsic::eMax1F:
					case ast::expr::Intrinsic::eMax2F:
					case ast::expr::Intrinsic::eMax3F:
					case ast::expr::Intrinsic::eMax4F:
						return intrinsic2T< float >( typesCache, exprCache, std::move( argsList ), []( float v, float w ){ return std::max( v, w ); } );
					case ast::expr::Intrinsic::eMax1D:
					case ast::expr::Intrinsic::eMax2D:
					case ast::expr::Intrinsic::eMax3D:
					case ast::expr::Intrinsic::eMax4D:
						return intrinsic2T< double >( typesCache, exprCache, std::move( argsList ), []( double v, double w ){ return std::max( v, w ); } );
					case ast::expr::Intrinsic::eMax1I:
					case ast::expr::Intrinsic::eMax2I:
					case ast::expr::Intrinsic::eMax3I:
					case ast::expr::Intrinsic::eMax4I:
						return intrinsic2T< int32_t >( typesCache, exprCache, std::move( argsList ), []( int32_t v, int32_t w ){ return std::max( v, w ); } );
					case ast::expr::Intrinsic::eMax1U:
					case ast::expr::Intrinsic::eMax2U:
					case ast::expr::Intrinsic::eMax3U:
					case ast::expr::Intrinsic::eMax4U:
						return intrinsic2T< uint32_t >( typesCache, exprCache, std::move( argsList ), []( uint32_t v, uint32_t w ){ return std::max( v, w ); } );
					case ast::expr::Intrinsic::eClamp1F:
					case ast::expr::Intrinsic::eClamp2F:
					case ast::expr::Intrinsic::eClamp3F:
					case ast::expr::Intrinsic::eClamp4F:
						return intrinsic3T< float >( typesCache, exprCache, std::move( argsList ), []( float v, float w, float x ){ return std::min( std::max( v, w ), x ); } );
					case ast::expr::Intrinsic::eClamp1D:
					case ast::expr::Intrinsic::eClamp2D:
					case ast::expr::Intrinsic::eClamp3D:
					case ast::expr::Intrinsic::eClamp4D:
						return intrinsic3T< double >( typesCache, exprCache, std::move( argsList ), []( double v, double w, double x ){ return std::min( std::max( v, w ), x ); } );
					case ast::expr::Intrinsic::eClamp1I:
					case ast::expr::Intrinsic::eClamp2I:
					case ast::expr::Intrinsic::eClamp3I:
					case ast::expr::Intrinsic::eClamp4I:
						return intrinsic3T< int32_t >( typesCache, exprCache, std::move( argsList ), []( int32_t v, int32_t w, int32_t x ){ return std::min( std::max( v, w ), x ); } );
					case ast::expr::Intrinsic::eClamp1U:
					case ast::expr::Intrinsic::eClamp2U:
					case ast::expr::Intrinsic::eClamp3U:
					case ast::expr::Intrinsic::eClamp4U:
						return intrinsic3T< uint32_t >( typesCache, exprCache, std::move( argsList ), []( uint32_t v, uint32_t w, uint32_t x ){ return std::min( std::max( v, w ), x ); } );
					case ast::expr::Intrinsic::eMix1F:
					case ast::expr::Intrinsic::eMix2F:
					case ast::expr::Intrinsic::eMix3F:
					case ast::expr::Intrinsic::eMix4F:
						return intrinsic3T< float >( typesCache, exprCache, std::move( argsList ), []( float v, float w, float x ){ return v * ( 1.0f - x ) + w * x; } );
					case ast::expr::Intrinsic::eMix1D:
					case ast::expr::Intrinsic::eMix2D:
					case ast::expr::Intrinsic::eMix3D:
					case ast::expr::Intrinsic::eMix4D:
						return intrinsic3T< double >( typesCache, exprCache, std::move( argsList ), []( double v, double w, double x ){ return v * ( 1.0f - x ) + w * x; } );
					case ast::expr::Intrinsic::eStep1F:
					case ast::expr::Intrinsic::eStep2F:
					case ast::expr::Intrinsic::eStep3F:
					case ast::expr::Intrinsic::eStep4F:
						return intrinsic2T< float >( typesCache, exprCache, std::move( argsList ), []( float v, float w ){ return w < v ? 0.0f : 1.0f; } );
					case ast::expr::Intrinsic::eStep1D:
					case ast::expr::Intrinsic::eStep2D:
					case ast::expr::Intrinsic::eStep3D:
					case ast::expr::Intrinsic::eStep4D:
						return intrinsic2T< double >( typesCache, exprCache, std::move( argsList ), []( double v, double w ){ return w < v ? 0.0f : 1.0f; } );
					case ast::expr::Intrinsic::eSmoothStep1F:
					case ast::expr::Intrinsic::eSmoothStep2F:
					case ast::expr::Intrinsic::eSmoothStep3F:
					case ast::expr::Intrinsic::eSmoothStep4F:
						return intrinsic3T< float >( typesCache, exprCache, std::move( argsList ), []( float v, float w, float x ){ auto t = std::min( std::max( ( x - v ) / ( w - v ) , 0.0f ), 1.0f ); return t * t * ( 3.0f - 2.0f * t ); } );
					case ast::expr::Intrinsic::eSmoothStep1D:
					case ast::expr::Intrinsic::eSmoothStep2D:
					case ast::expr::Intrinsic::eSmoothStep3D:
					case ast::expr::Intrinsic::eSmoothStep4D:
						return intrinsic3T< double >( typesCache, exprCache, std::move( argsList ), []( double v, double w, double x ){ auto t = std::min( std::max( ( x - v ) / ( w - v ) , 0.0 ), 1.0 ); return t * t * ( 3.0 - 2.0 * t ); } );
					case ast::expr::Intrinsic::eIsnan1F:
					case ast::expr::Intrinsic::eIsnan2F:
					case ast::expr::Intrinsic::eIsnan3F:
					case ast::expr::Intrinsic::eIsnan4F:
						return intrinsic1BoolT< float >( typesCache, exprCache, std::move( argsList ), []( float v ){ return std::isnan( v ); } );
					case ast::expr::Intrinsic::eIsnan1D:
					case ast::expr::Intrinsic::eIsnan2D:
					case ast::expr::Intrinsic::eIsnan3D:
					case ast::expr::Intrinsic::eIsnan4D:
						return intrinsic1BoolT< double >( typesCache, exprCache, std::move( argsList ), []( double v ){ return std::isnan( v ); } );
					case ast::expr::Intrinsic::eIsinf1F:
					case ast::expr::Intrinsic::eIsinf2F:
					case ast::expr::Intrinsic::eIsinf3F:
					case ast::expr::Intrinsic::eIsinf4F:
						return intrinsic1BoolT< float >( typesCache, exprCache, std::move( argsList ), []( float v ){ return std::isinf( v ); } );
					case ast::expr::Intrinsic::eIsinf1D:
					case ast::expr::Intrinsic::eIsinf2D:
					case ast::expr::Intrinsic::eIsinf3D:
					case ast::expr::Intrinsic::eIsinf4D:
						return intrinsic1BoolT< double >( typesCache, exprCache, std::move( argsList ), []( double v ){ return std::isinf( v ); } );
					case ast::expr::Intrinsic::eFma1F:
					case ast::expr::Intrinsic::eFma2F:
					case ast::expr::Intrinsic::eFma3F:
					case ast::expr::Intrinsic::eFma4F:
						return intrinsic3T< float >( typesCache, exprCache, std::move( argsList ), []( float v, float w, float x ){ return std::fma( v, w, x ); } );
					case ast::expr::Intrinsic::eFma1D:
					case ast::expr::Intrinsic::eFma2D:
					case ast::expr::Intrinsic::eFma3D:
					case ast::expr::Intrinsic::eFma4D:
						return intrinsic3T< double >( typesCache, exprCache, std::move( argsList ), []( double v, double w, double x ){ return std::fma( v, w, x ); } );
					case ast::expr::Intrinsic::eLessThan2F:
					case ast::expr::Intrinsic::eLessThan3F:
					case ast::expr::Intrinsic::eLessThan4F:
						return intrinsicCompT< float >( typesCache, exprCache, std::move( argsList ), []( float v, float w ){ return v < w; } );
					case ast::expr::Intrinsic::eLessThan2D:
					case ast::expr::Intrinsic::eLessThan3D:
					case ast::expr::Intrinsic::eLessThan4D:
						return intrinsicCompT< double >( typesCache, exprCache, std::move( argsList ), []( double v, double w ){ return v < w; } );
					case ast::expr::Intrinsic::eLessThan2I:
					case ast::expr::Intrinsic::eLessThan3I:
					case ast::expr::Intrinsic::eLessThan4I:
						return intrinsicCompT< int32_t >( typesCache, exprCache, std::move( argsList ), []( int32_t v, int32_t w ){ return v < w; } );
					case ast::expr::Intrinsic::eLessThan2U:
					case ast::expr::Intrinsic::eLessThan3U:
					case ast::expr::Intrinsic::eLessThan4U:
						return intrinsicCompT< uint32_t >( typesCache, exprCache, std::move( argsList ), []( uint32_t v, uint32_t w ){ return v < w; } );
					case ast::expr::Intrinsic::eLessThanEqual2F:
					case ast::expr::Intrinsic::eLessThanEqual3F:
					case ast::expr::Intrinsic::eLessThanEqual4F:
						return intrinsicCompT< float >( typesCache, exprCache, std::move( argsList ), []( float v, float w ){ return v <= w; } );
					case ast::expr::Intrinsic::eLessThanEqual2D:
					case ast::expr::Intrinsic::eLessThanEqual3D:
					case ast::expr::Intrinsic::eLessThanEqual4D:
						return intrinsicCompT< double >( typesCache, exprCache, std::move( argsList ), []( double v, double w ){ return v <= w; } );
					case ast::expr::Intrinsic::eLessThanEqual2I:
					case ast::expr::Intrinsic::eLessThanEqual3I:
					case ast::expr::Intrinsic::eLessThanEqual4I:
						return intrinsicCompT< int32_t >( typesCache, exprCache, std::move( argsList ), []( int32_t v, int32_t w ){ return v <= w; } );
					case ast::expr::Intrinsic::eLessThanEqual2U:
					case ast::expr::Intrinsic::eLessThanEqual3U:
					case ast::expr::Intrinsic::eLessThanEqual4U:
						return intrinsicCompT< uint32_t >( typesCache, exprCache, std::move( argsList ), []( uint32_t v, uint32_t w ){ return v <= w; } );
					case ast::expr::Intrinsic::eGreaterThan2F:
					case ast::expr::Intrinsic::eGreaterThan3F:
					case ast::expr::Intrinsic::eGreaterThan4F:
						return intrinsicCompT< float >( typesCache, exprCache, std::move( argsList ), []( float v, float w ){ return v > w; } );
					case ast::expr::Intrinsic::eGreaterThan2D:
					case ast::expr::Intrinsic::eGreaterThan3D:
					case ast::expr::Intrinsic::eGreaterThan4D:
						return intrinsicCompT< double >( typesCache, exprCache, std::move( argsList ), []( double v, double w ){ return v > w; } );
					case ast::expr::Intrinsic::eGreaterThan2I:
					case ast::expr::Intrinsic::eGreaterThan3I:
					case ast::expr::Intrinsic::eGreaterThan4I:
						return intrinsicCompT< int32_t >( typesCache, exprCache, std::move( argsList ), []( int32_t v, int32_t w ){ return v > w; } );
					case ast::expr::Intrinsic::eGreaterThan2U:
					case ast::expr::Intrinsic::eGreaterThan3U:
					case ast::expr::Intrinsic::eGreaterThan4U:
						return intrinsicCompT< uint32_t >( typesCache, exprCache, std::move( argsList ), []( uint32_t v, uint32_t w ){ return v > w; } );
					case ast::expr::Intrinsic::eGreaterThanEqual2F:
					case ast::expr::Intrinsic::eGreaterThanEqual3F:
					case ast::expr::Intrinsic::eGreaterThanEqual4F:
						return intrinsicCompT< float >( typesCache, exprCache, std::move( argsList ), []( float v, float w ){ return v >= w; } );
					case ast::expr::Intrinsic::eGreaterThanEqual2D:
					case ast::expr::Intrinsic::eGreaterThanEqual3D:
					case ast::expr::Intrinsic::eGreaterThanEqual4D:
						return intrinsicCompT< double >( typesCache, exprCache, std::move( argsList ), []( double v, double w ){ return v >= w; } );
					case ast::expr::Intrinsic::eGreaterThanEqual2I:
					case ast::expr::Intrinsic::eGreaterThanEqual3I:
					case ast::expr::Intrinsic::eGreaterThanEqual4I:
						return intrinsicCompT< int32_t >( typesCache, exprCache, std::move( argsList ), []( int32_t v, int32_t w ){ return v >= w; } );
					case ast::expr::Intrinsic::eGreaterThanEqual2U:
					case ast::expr::Intrinsic::eGreaterThanEqual3U:
					case ast::expr::Intrinsic::eGreaterThanEqual4U:
						return intrinsicCompT< uint32_t >( typesCache, exprCache, std::move( argsList ), []( uint32_t v, uint32_t w ){ return v >= w; } );
					case ast::expr::Intrinsic::eEqual2F:
					case ast::expr::Intrinsic::eEqual3F:
					case ast::expr::Intrinsic::eEqual4F:
						return intrinsicCompT< float >( typesCache, exprCache, std::move( argsList ), []( float v, float w ){ return v == w; } );
					case ast::expr::Intrinsic::eEqual2D:
					case ast::expr::Intrinsic::eEqual3D:
					case ast::expr::Intrinsic::eEqual4D:
						return intrinsicCompT< double >( typesCache, exprCache, std::move( argsList ), []( double v, double w ){ return v == w; } );
					case ast::expr::Intrinsic::eEqual2I:
					case ast::expr::Intrinsic::eEqual3I:
					case ast::expr::Intrinsic::eEqual4I:
						return intrinsicCompT< int32_t >( typesCache, exprCache, std::move( argsList ), []( int32_t v, int32_t w ){ return v == w; } );
					case ast::expr::Intrinsic::eEqual2U:
					case ast::expr::Intrinsic::eEqual3U:
					case ast::expr::Intrinsic::eEqual4U:
						return intrinsicCompT< uint32_t >( typesCache, exprCache, std::move( argsList ), []( uint32_t v, uint32_t w ){ return v == w; } );
					case ast::expr::Intrinsic::eNotEqual2F:
					case ast::expr::Intrinsic::eNotEqual3F:
					case ast::expr::Intrinsic::eNotEqual4F:
						return intrinsicCompT< float >( typesCache, exprCache, std::move( argsList ), []( float v, float w ){ return v != w; } );
					case ast::expr::Intrinsic::eNotEqual2D:
					case ast::expr::Intrinsic::eNotEqual3D:
					case ast::expr::Intrinsic::eNotEqual4D:
						return intrinsicCompT< double >( typesCache, exprCache, std::move( argsList ), []( double v, double w ){ return v != w; } );
					case ast::expr::Intrinsic::eNotEqual2I:
					case ast::expr::Intrinsic::eNotEqual3I:
					case ast::expr::Intrinsic::eNotEqual4I:
						return intrinsicCompT< int32_t >( typesCache, exprCache, std::move( argsList ), []( int32_t v, int32_t w ){ return v != w; } );
					case ast::expr::Intrinsic::eNotEqual2U:
					case ast::expr::Intrinsic::eNotEqual3U:
					case ast::expr::Intrinsic::eNotEqual4U:
						return intrinsicCompT< uint32_t >( typesCache, exprCache, std::move( argsList ), []( uint32_t v, uint32_t w ){ return v != w; } );
					case ast::expr::Intrinsic::eAll2:
					case ast::expr::Intrinsic::eAll3:
					case ast::expr::Intrinsic::eAll4:
						return intrinsicGatherT< bool >( typesCache, exprCache, std::move( argsList ), []( bool v, bool w ){ return v && w; } );
					case ast::expr::Intrinsic::eAny2:
					case ast::expr::Intrinsic::eAny3:
					case ast::expr::Intrinsic::eAny4:
						return intrinsicGatherT< bool >( typesCache, exprCache, std::move( argsList ), []( bool v, bool w ){ return v || w; } );
					case ast::expr::Intrinsic::eNot2:
					case ast::expr::Intrinsic::eNot3:
					case ast::expr::Intrinsic::eNot4:
						return intrinsic1T< bool >( typesCache, exprCache, std::move( argsList ), []( bool v ){ return !v; } );
					default:
						AST_Failure( "Unsupported intrinsics for constant resolution" );
						return nullptr;
					}
				}
				catch ( std::invalid_argument & )
				{
					return nullptr;
				}
			}
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
				, ConstantsContext & context
				, bool isLHS )
			{
				bool allLiterals{ true };
				return submit( exprCache
					, expr
					, context
					, allLiterals
					, isLHS );
			}

			static expr::ExprPtr submit( expr::ExprCache & exprCache
				, expr::Expr * expr
				, ConstantsContext & context
				, bool & allLiterals
				, bool isLHS )
			{
				expr::ExprPtr result{};
				ExprEvaluator vis{ exprCache, context, allLiterals, isLHS, result };
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
				, bool isLHS
				, ast::expr::ExprPtr & result )
				: ExprCloner{ exprCache, result }
				, m_context{ context }
				, m_allLiterals{ allLiterals }
				, m_isLHS{ isLHS }
			{
			}

			using ast::ExprCloner::doSubmit;

			expr::ExprPtr doSubmit( expr::Expr * expr
				, bool & allLiterals
				, bool isLHS = false )
			{
				return submit( m_exprCache, expr, m_context, allLiterals, isLHS );
			}

			expr::ExprPtr doSubmit( expr::Expr * expr )override
			{
				return doSubmit( expr, m_allLiterals, false );
			}

			void visitUnaryExpr( expr::Unary * expr )
			{
				TraceFunc;
				auto op = doSubmit( expr->getOperand() );

				if ( op->getKind() == expr::Kind::eLiteral )
				{
					auto & literal = static_cast< expr::Literal const & >( *op );

					switch ( expr->getKind() )
					{
					case expr::Kind::eBitNot:
						m_result = ~literal;
						break;
					case expr::Kind::eCast:
						m_result = literal.castTo( helpers::getLiteralType( *expr->getType() ) );
						break;
					case expr::Kind::eCopy:
						m_result = std::move( op );
						break;
					case expr::Kind::eLogNot:
						m_result = !literal;
						break;
					case expr::Kind::ePostDecrement:
						m_result = std::move( op );
						break;
					case expr::Kind::ePostIncrement:
						m_result = std::move( op );
						break;
					case expr::Kind::ePreDecrement:
						m_result = preDec( literal );
						break;
					case expr::Kind::ePreIncrement:
						m_result = preInc( literal );
						break;
					case expr::Kind::eStreamAppend:
						m_result = m_exprCache.makeStreamAppend( std::move( op ) );
						break;
					case expr::Kind::eUnaryMinus:
						m_result = -literal;
						break;
					case expr::Kind::eUnaryPlus:
						m_result = std::move( op );
						break;
					default:
						AST_Failure( "Unexpected unary expression" );
						m_result = ExprCloner::submit( m_exprCache, expr );
						break;
					}
				}

				if ( !m_result )
				{
					m_allLiterals = false;

					switch ( expr->getKind() )
					{
					case expr::Kind::eBitNot:
						m_result = m_exprCache.makeBitNot( std::move( op ) );
						break;
					case expr::Kind::eCast:
						m_result = m_exprCache.makeCast( expr->getType(), std::move( op ) );
						break;
					case expr::Kind::eCopy:
						m_result = m_exprCache.makeCopy( std::move( op ) );
						break;
					case expr::Kind::eLogNot:
						m_result = m_exprCache.makeLogNot( expr->getType(), std::move( op ) );
						break;
					case expr::Kind::ePostDecrement:
						m_result = m_exprCache.makePostDecrement( std::move( op ) );
						break;
					case expr::Kind::ePostIncrement:
						m_result = m_exprCache.makePostIncrement( std::move( op ) );
						break;
					case expr::Kind::ePreDecrement:
						m_exprCache.makePreDecrement( std::move( op ) );
						break;
					case expr::Kind::ePreIncrement:
						m_result = m_exprCache.makePreIncrement( std::move( op ) );
						break;
					case expr::Kind::eStreamAppend:
						m_result = m_exprCache.makeStreamAppend( std::move( op ) );
						break;
					case expr::Kind::eUnaryMinus:
						m_result = m_exprCache.makeUnaryMinus( std::move( op ) );
						break;
					case expr::Kind::eUnaryPlus:
						m_result = m_exprCache.makeUnaryPlus( std::move( op ) );
						break;
					default:
						AST_Failure( "Unexpected unary expression" );
						m_result = ExprCloner::submit( m_exprCache, expr );
						break;
					}
				}
			}

			expr::ExprPtr visitBinaryExpr( expr::Binary * expr
				, expr::Literal const & lhsLiteral
				, expr::Literal const & rhsLiteral )
			{
				switch ( expr->getKind() )
				{
				case expr::Kind::eAdd:
					return lhsLiteral + rhsLiteral;
				case expr::Kind::eBitAnd:
					return lhsLiteral & rhsLiteral;
				case expr::Kind::eBitOr:
					return lhsLiteral | rhsLiteral;
				case expr::Kind::eBitXor:
					return lhsLiteral ^ rhsLiteral;
				case expr::Kind::eDivide:
					return lhsLiteral / rhsLiteral;
				case expr::Kind::eLShift:
					return lhsLiteral << rhsLiteral;
				case expr::Kind::eMinus:
					return lhsLiteral - rhsLiteral;
				case expr::Kind::eModulo:
					return lhsLiteral % rhsLiteral;
				case expr::Kind::eRShift:
					return lhsLiteral >> rhsLiteral;
				case expr::Kind::eTimes:
					return lhsLiteral * rhsLiteral;
				case expr::Kind::eLogAnd:
					return lhsLiteral && rhsLiteral;
				case expr::Kind::eLogOr:
					return lhsLiteral || rhsLiteral;
				case expr::Kind::eLess:
					return lhsLiteral < rhsLiteral;
				case expr::Kind::eLessEqual:
					return lhsLiteral <= rhsLiteral;
				case expr::Kind::eGreater:
					return lhsLiteral > rhsLiteral;
				case expr::Kind::eGreaterEqual:
					return lhsLiteral >= rhsLiteral;
				case expr::Kind::eEqual:
					return lhsLiteral == rhsLiteral;
				case expr::Kind::eNotEqual:
					return lhsLiteral != rhsLiteral;
				default:
					AST_Failure( "Unexpected binary expression" );
					return ExprCloner::submit( m_exprCache, expr );
				}
			}

			void visitBinaryExpr( expr::Binary * expr )
			{
				TraceFunc;
				bool allLiterals = true;
				auto lhs = doSubmit( expr->getLHS(), allLiterals );
				auto rhs = doSubmit( expr->getRHS(), allLiterals );
				m_allLiterals = allLiterals && m_allLiterals;

				if ( allLiterals )
				{
					if ( lhs->getKind() == expr::Kind::eAggrInit
						&& rhs->getKind() == expr::Kind::eAggrInit )
					{
						auto & lhsInit = static_cast< expr::AggrInit const & >( *lhs );
						auto & rhsInit = static_cast< expr::AggrInit const & >( *rhs );

						if ( lhsInit.getInitialisers().size() == rhsInit.getInitialisers().size() )
						{
							expr::ExprList initialisers;

							for ( size_t i = 0u; i < lhsInit.getInitialisers().size(); ++i )
							{
								initialisers.push_back( visitBinaryExpr( expr
									, static_cast< expr::Literal const & >( *lhsInit.getInitialisers()[i] )
									, static_cast< expr::Literal const & >( *rhsInit.getInitialisers()[i] ) ) );
							}

							m_result = m_exprCache.makeAggrInit( expr->getType()
								, std::move( initialisers ) );
						}
					}
					else if ( lhs->getKind() == expr::Kind::eCompositeConstruct
						&& rhs->getKind() == expr::Kind::eCompositeConstruct )
					{
						auto & lhsComposite = static_cast< expr::CompositeConstruct const & >( *lhs );
						auto & rhsComposite = static_cast< expr::CompositeConstruct const & >( *rhs );

						if ( lhsComposite.getArgList().size() == rhsComposite.getArgList().size() )
						{
							expr::ExprList initialisers;

							for ( size_t i = 0u; i < lhsComposite.getArgList().size(); ++i )
							{
								initialisers.push_back( visitBinaryExpr( expr
									, static_cast< expr::Literal const & >( *lhsComposite.getArgList()[i] )
									, static_cast< expr::Literal const & >( *rhsComposite.getArgList()[i] ) ) );
							}

							m_result = m_exprCache.makeCompositeConstruct( lhsComposite.getComposite()
								, getComponentType( expr->getType() )
								, std::move( initialisers ) );
						}
					}
					else if ( lhs->getKind() == expr::Kind::eLiteral
						&& rhs->getKind() == expr::Kind::eLiteral )
					{
						m_result = visitBinaryExpr( expr
							, static_cast< expr::Literal const & >( *lhs )
							, static_cast< expr::Literal const & >( *rhs ) );
					}
				}

				if ( !m_result )
				{
					m_allLiterals = false;

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
				TraceFunc;
				visitBinaryExpr( expr );
			}

			// visitAggrInitExpr from ExprCloner

			void visitArrayAccessExpr( expr::ArrayAccess * expr )override
			{
				TraceFunc;
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

			void visitAssignExpr( ast::expr::Assign * expr )override
			{
				TraceFunc;
				auto lhs = doSubmit( expr->getLHS(), m_allLiterals, true );
				auto rhs = doSubmit( expr->getRHS() );

				if ( rhs && lhs )
				{
					m_result = m_exprCache.makeAssign( expr->getType()
						, std::move( lhs )
						, std::move( rhs ) );
				}
			}

			void visitBitAndExpr( expr::BitAnd * expr )override
			{
				TraceFunc;
				visitBinaryExpr( expr );
			}

			void visitBitNotExpr( expr::BitNot * expr )override
			{
				TraceFunc;
				visitUnaryExpr( expr );
			}

			void visitBitOrExpr( expr::BitOr * expr )override
			{
				TraceFunc;
				visitBinaryExpr( expr );
			}

			void visitBitXorExpr( expr::BitXor * expr )override
			{
				TraceFunc;
				visitBinaryExpr( expr );
			}

			void visitCastExpr( expr::Cast * expr )override
			{
				TraceFunc;

				if ( getComponentType( expr->getType() ) != type::Kind::eHalf )
				{
					visitUnaryExpr( expr );
				}
				else
				{
					ExprCloner::visitCastExpr( expr );
				}
			}

			void visitCombinedImageAccessCallExpr( expr::CombinedImageAccessCall* expr )override
			{
				TraceFunc;
				m_allLiterals = false;
				ExprCloner::visitCombinedImageAccessCallExpr( expr );
			}

			void visitDivideExpr( expr::Divide * expr )override
			{
				TraceFunc;
				visitBinaryExpr( expr );
			}

			void visitEqualExpr( expr::Equal * expr )override
			{
				TraceFunc;
				visitBinaryExpr( expr );
			}

			void visitFnCallExpr( expr::FnCall* expr )override
			{
				TraceFunc;
				m_allLiterals = false;
				ExprCloner::visitFnCallExpr( expr );
			}

			void visitGreaterExpr( expr::Greater * expr )override
			{
				TraceFunc;
				visitBinaryExpr( expr );
			}

			void visitGreaterEqualExpr( expr::GreaterEqual * expr )override
			{
				TraceFunc;
				visitBinaryExpr( expr );
			}

			void visitIdentifierExpr( ast::expr::Identifier * expr )override
			{
				TraceFunc;;
				auto var = expr->getVariable();
				auto initIt = m_context.constExprs.find( var->getId() );
				auto aggrIt = m_context.constAggrExprs.find( var->getId() );

				if ( !m_isLHS )
				{
					if ( initIt != m_context.constExprs.end() )
					{
						m_result = doSubmit( initIt->second );
					}
					else if ( aggrIt != m_context.constAggrExprs.end() )
					{
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
				else
				{
					if ( initIt != m_context.constExprs.end() )
					{
						m_context.constExprs.erase( initIt );
					}

					if ( aggrIt != m_context.constAggrExprs.end() )
					{
						m_context.constAggrExprs.erase( aggrIt );
					}

					m_allLiterals = false;
					ExprCloner::visitIdentifierExpr( expr );
				}
			}

			void visitImageAccessCallExpr( expr::StorageImageAccessCall * expr )override
			{
				TraceFunc;
				m_allLiterals = false;
				ExprCloner::visitImageAccessCallExpr( expr );
			}

			void visitInitExpr( expr::Init * expr )override
			{
				AST_Failure( "Unexpected Init expression" );
			}

			void visitIntrinsicCallExpr( expr::IntrinsicCall * expr )override
			{
				TraceFunc;

				if ( helpers::isConstantResolvable( expr->getIntrinsic() ) )
				{
					bool allLiterals = true;
					expr::ExprList args;

					for ( auto & arg : expr->getArgList() )
					{
						args.push_back( doSubmit( arg.get(), allLiterals ) );
					}

					if ( allLiterals )
					{
						m_result = helpers::resolveConstant( expr->getTypesCache(), m_exprCache, expr->getIntrinsic(), std::move( args ) );
					}

					m_allLiterals = allLiterals && m_allLiterals;
				}

				if ( !m_result )
				{
					ExprCloner::visitIntrinsicCallExpr( expr );
					m_allLiterals = false;
				}
			}

			void visitLessExpr( expr::Less * expr )override
			{
				TraceFunc;
				visitBinaryExpr( expr );
			}

			void visitLessEqualExpr( expr::LessEqual * expr )override
			{
				TraceFunc;
				visitBinaryExpr( expr );
			}

			void visitLogAndExpr( expr::LogAnd * expr )override
			{
				TraceFunc;
				visitBinaryExpr( expr );
			}

			void visitLogNotExpr( expr::LogNot * expr )override
			{
				TraceFunc;
				visitUnaryExpr( expr );
			}

			void visitLogOrExpr( expr::LogOr * expr )override
			{
				TraceFunc;
				visitBinaryExpr( expr );
			}

			void visitLShiftExpr( expr::LShift * expr )override
			{
				TraceFunc;
				visitBinaryExpr( expr );
			}

			void visitMbrSelectExpr( expr::MbrSelect * expr )override
			{
				TraceFunc;
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
				TraceFunc;
				visitBinaryExpr( expr );
			}

			void visitModuloExpr( expr::Modulo * expr )override
			{
				TraceFunc;
				visitBinaryExpr( expr );
			}

			void visitNotEqualExpr( expr::NotEqual * expr )override
			{
				TraceFunc;
				visitBinaryExpr( expr );
			}

			void visitRShiftExpr( expr::RShift * expr )override
			{
				TraceFunc;
				visitBinaryExpr( expr );
			}

			void visitQuestionExpr( expr::Question * expr )override
			{
				TraceFunc;
				auto condComponents = getComponentCount( expr->getCtrlExpr()->getType()->getKind() );
				// Components counts should be identical, after simplification pass.
				assert( condComponents == getComponentCount( expr->getTrueExpr()->getType()->getKind() ) );
				bool allLiterals{ true };
				auto ctrlExpr = doSubmit( expr->getCtrlExpr(), allLiterals );
				m_allLiterals = allLiterals && m_allLiterals;
				bool processed = false;

				if ( allLiterals )
				{
					processed = true;

					if ( condComponents == 1u )
					{
						assert( ctrlExpr->getKind() == expr::Kind::eLiteral );
						m_result = static_cast< expr::Literal const & >( *ctrlExpr ).getValue< expr::LiteralType::eBool >()
							? doSubmit( expr->getTrueExpr() )
							: doSubmit( expr->getFalseExpr() );
					}
					else
					{
						expr::ExprList initialisers;
						auto trueExpr = doSubmit( expr->getTrueExpr() );
						auto falseExpr = doSubmit( expr->getFalseExpr() );

						for ( auto i = 0u; i < condComponents; ++i )
						{
							auto ctrlValue = doSubmit( m_exprCache.makeSwizzle( ctrlExpr->clone()
								, expr::SwizzleKind::fromOffset( i ) ) );
							assert( ctrlValue->getKind() == expr::Kind::eLiteral );
							auto resultValue = static_cast< expr::Literal const & >( *ctrlValue ).getValue< expr::LiteralType::eBool >()
								? trueExpr->clone()
								: falseExpr->clone();
							initialisers.push_back( doSubmit( m_exprCache.makeSwizzle( std::move( resultValue )
								, expr::SwizzleKind::fromOffset( i ) ) ) );
						}

						auto scalarType = getScalarType( expr->getType()->getKind() );
						m_result = m_exprCache.makeCompositeConstruct( expr::CompositeType( condComponents - 1u )
							, scalarType
							, std::move( initialisers ) );
					}
				}

				if ( !processed )
				{
					ExprCloner::visitQuestionExpr( expr );
				}
			}

			void visitSwizzleExpr( expr::Swizzle * expr )override
			{
				TraceFunc;
				bool processed = false;

				if ( expr->getOuterExpr()->getKind() == expr::Kind::eIdentifier )
				{
					auto variable = static_cast< expr::Identifier const & >( *expr->getOuterExpr() ).getVariable();
					auto it = m_context.constAggrExprs.find( variable->getId() );

					if ( it != m_context.constAggrExprs.end() )
					{
						processed = true;
						auto indices = getSwizzleIndices( expr->getSwizzle() );
						expr::ExprList initialisers;

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
					bool allLiterals = true;
					auto outer = doSubmit( expr->getOuterExpr(), allLiterals );
					m_allLiterals = m_allLiterals && allLiterals;

					if ( allLiterals )
					{
						processed = true;
						auto indices = getSwizzleIndices( expr->getSwizzle() );
						expr::ExprList initialisers;

						for ( auto index : indices )
						{
							initialisers.push_back( helpers::getNthValue( *outer, index ) );
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
					m_allLiterals = false;
					ExprCloner::visitSwizzleExpr( expr );
				}
			}

			void visitTimesExpr( expr::Times * expr )override
			{
				TraceFunc;
				visitBinaryExpr( expr );
			}

			void visitUnaryMinusExpr( expr::UnaryMinus * expr )override
			{
				TraceFunc;
				visitUnaryExpr( expr );
			}

			void visitUnaryPlusExpr( expr::UnaryPlus * expr )override
			{
				TraceFunc;
				m_result = doSubmit( expr->getOperand() );
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

			void visitPostDecrementExpr(expr::PostDecrement * expr)override
			{
				AST_Failure( "Unexpected PostDecrement expression" );
			}

			void visitPostIncrementExpr(expr::PostIncrement * expr)override
			{
				AST_Failure( "Unexpected PostIncrement expression" );
			}

			void visitPreDecrementExpr(expr::PreDecrement * expr)override
			{
				AST_Failure( "Unexpected PreDecrement expression" );
			}

			void visitPreIncrementExpr(expr::PreIncrement * expr)override
			{
				AST_Failure( "Unexpected PreIncrement expression" );
			}

		private:
			ConstantsContext & m_context;
			bool & m_allLiterals;
			bool m_isLHS;
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
				return ExprEvaluator::submit( m_exprCache, expr, m_context, allLiterals, false );
			}

			void processIfStmt( stmt::Container * stmt
				, ast::expr::ExprPtr ctrlExpr
				, bool & first
				, bool & stopped
				, uint32_t & ifs
				, uint32_t & elses )
			{
				TraceFunc;
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
				TraceFunc;
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
				TraceFunc;
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
				TraceFunc;
				m_containers.push_back( cont );

				for ( auto & stmt : *cont )
				{
					stmt->accept( this );
				}

				m_containers.pop_back();
			}

			void visitIfStmt( stmt::If * stmt )override
			{
				TraceFunc;
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
				expr::Expr * expr{ stmt->getExpr() };
				auto ident = ( expr->getKind() == ast::expr::Kind::eAlias
					? static_cast< expr::Alias const & >( *expr ).getLHS()
					: ( expr->getKind() == ast::expr::Kind::eInit
						? static_cast< ast::expr::Init * >( expr )->getIdentifier()
						: ( expr->getKind() == ast::expr::Kind::eAggrInit
							? static_cast< ast::expr::AggrInit * >( expr )->getIdentifier()
							: nullptr ) ) );

				if ( ident )
				{
					expr::Expr * init{};

					if ( expr->getKind() == ast::expr::Kind::eAlias )
					{
						init = static_cast< expr::Alias const & >( *expr ).getRHS();
					}
					else if ( expr->getKind() == ast::expr::Kind::eInit )
					{
						init = static_cast< ast::expr::Init * >( expr )->getInitialiser();
					}

					if ( init )
					{
						if ( init->getKind() == ast::expr::Kind::eCompositeConstruct )
						{
							processed = true;
							auto compositeCtor = static_cast< ast::expr::CompositeConstruct * >( init );
							ast::expr::ExprList initialisers;
							bool allLiterals = true;

							for ( auto & arg : compositeCtor->getArgList() )
							{
								initialisers.emplace_back( doSubmit( arg.get(), allLiterals ) );
							}

							if ( !helpers::needsVariableDecl( ident->getVariable(), m_containers.back() ) )
							{
								if ( allLiterals )
								{
									m_context.constAggrExprs.emplace( ident->getVariable()->getId()
										, std::move( initialisers ) );
								}
								else
								{
									auto initialiser = m_exprCache.makeCompositeConstruct( compositeCtor->getComposite()
										, compositeCtor->getComponent()
										, std::move( initialisers ) );
									m_current->addStmt( m_stmtCache.makeSimple( m_exprCache.makeInit( m_exprCache.makeIdentifier( *ident )
										, std::move( initialiser ) ) ) );
								}
							}
							else
							{
								auto initialiser = m_exprCache.makeCompositeConstruct( compositeCtor->getComposite()
									, compositeCtor->getComponent()
									, std::move( initialisers ) );
								m_current->addStmt( m_stmtCache.makeSimple( m_exprCache.makeInit( m_exprCache.makeIdentifier( *ident )
									, std::move( initialiser ) ) ) );
							}
						}
						else
						{
							processed = true;
							bool allLiterals = true;
							auto initialiser = doSubmit( init, allLiterals );

							if ( allLiterals
								&& !helpers::needsVariableDecl( ident->getVariable(), m_containers.back() ) )
							{
								m_context.constExprs.emplace( ident->getVariable()->getId()
									, std::move( initialiser ) );
							}
							else
							{
								m_current->addStmt( m_stmtCache.makeSimple( m_exprCache.makeInit( m_exprCache.makeIdentifier( *ident )
									, std::move( initialiser ) ) ) );
							}
						}
					}
					else if ( expr->getKind() == ast::expr::Kind::eAggrInit )
					{
						auto aggrInit = static_cast< ast::expr::AggrInit * >( expr );
						processed = true;
						bool allLiterals = true;
						ast::expr::ExprList initialisers;

						for ( auto & initialiser : aggrInit->getInitialisers() )
						{
							initialisers.emplace_back( doSubmit( initialiser.get(), allLiterals ) );
						}

						if ( allLiterals
							&& !helpers::needsVariableDecl( ident->getVariable(), m_containers.back() ) )
						{
							m_context.constAggrExprs.emplace( ident->getVariable()->getId()
								, std::move( initialisers ) );
						}
						else
						{
							m_current->addStmt( m_stmtCache.makeSimple( m_exprCache.makeAggrInit( m_exprCache.makeIdentifier( *ident )
								, std::move( initialisers ) ) ) );
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
				TraceFunc;;
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
			std::vector< stmt::Container * > m_containers{};
			ConstantsContext & m_context;
		};

		bool isAllLiterals( expr::Expr * expr )
		{
			bool allLiterals = true;
			auto & exprCache = expr->getExprCache();
			constants::ConstantsContext context{ &exprCache.getAllocator() };
			ExprEvaluator::submit( exprCache
				, expr
				, context
				, allLiterals
				, true );
			return allLiterals;
		}
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
		return constants::ExprEvaluator::submit( exprCache, expr, context, false );
	}
}
