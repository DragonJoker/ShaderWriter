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
#include <numbers>
#include <math.h>

namespace ast
{
	using expr::LitBool;
	using expr::LitInt8;
	using expr::LitInt16;
	using expr::LitInt32;
	using expr::LitInt64;
	using expr::LitUInt8;
	using expr::LitUInt16;
	using expr::LitUInt32;
	using expr::LitUInt64;
	using expr::LitFloat32;
	using expr::LitFloat64;

	namespace constants
	{
		bool isAllLiterals( expr::Expr const & expr );

		namespace helpers
		{
			static uint32_t getLiteralIndex( expr::Literal const & lit )
			{
				AST_Assert( lit.getLiteralType() == expr::LiteralType::eInt8
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
					result = uint32_t( lit.getValue< expr::LiteralType::eUInt8 >() );
				}
				else if ( lit.getLiteralType() == expr::LiteralType::eUInt16 )
				{
					result = uint32_t( lit.getValue< expr::LiteralType::eUInt16 >() );
				}
				else if ( lit.getLiteralType() == expr::LiteralType::eUInt32 )
				{
					result = uint32_t( lit.getValue< expr::LiteralType::eUInt32 >() );
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
				auto result = expr::LiteralType::eFloat;

				switch ( kind )
				{
				case type::Kind::eBoolean:
					result = expr::LiteralType::eBool;
					break;
				case type::Kind::eInt8:
					result = expr::LiteralType::eInt8;
					break;
				case type::Kind::eInt16:
					result = expr::LiteralType::eInt16;
					break;
				case type::Kind::eInt32:
					result = expr::LiteralType::eInt32;
					break;
				case type::Kind::eInt64:
					result = expr::LiteralType::eInt64;
					break;
				case type::Kind::eUInt8:
					result = expr::LiteralType::eUInt8;
					break;
				case type::Kind::eUInt16:
					result = expr::LiteralType::eUInt16;
					break;
				case type::Kind::eUInt32:
					result = expr::LiteralType::eUInt32;
					break;
				case type::Kind::eUInt64:
					result = expr::LiteralType::eUInt64;
					break;
				case type::Kind::eFloat:
					result = expr::LiteralType::eFloat;
					break;
				case type::Kind::eDouble:
					result = expr::LiteralType::eDouble;
					break;
				default:
					break;
				}

				return result;
			}

			static bool needsVariableDecl( var::VariablePtr variable
				, stmt::Container const & scope )
			{
				class ExprVisitor
					: public ast::expr::SimpleVisitor
				{
				public:
					static void submit( var::VariablePtr variable
						, ast::expr::Expr const & expr
						, bool & result )
					{
						ExprVisitor vis{ variable, result };
						expr.accept( &vis );
					}

				private:
					explicit ExprVisitor( var::VariablePtr variable
						, bool & result )
						: m_variable{ variable }
						, m_result{ result }
					{
					}

				private:
					void visitExprIdentifiers( expr::Expr const & expr )
					{
						for ( auto & ident : listIdentifiers( expr ) )
						{
							if ( ident->getVariable()->getId() == m_variable->getId() )
							{
								m_result = true;
							}
						}
					}

					void visitUnaryExpr( ast::expr::Unary const * expr )override
					{
						expr->getOperand()->accept( this );
					}

					void visitBinaryExpr( ast::expr::Binary const * expr )override
					{
						expr->getLHS()->accept( this );
						expr->getRHS()->accept( this );
					}

					void visitArrayAccessExpr( ast::expr::ArrayAccess const * expr )override
					{
						if ( !isAllLiterals( *expr->getRHS() ) )
						{
							visitExprIdentifiers( *expr->getLHS() );
						}
						else
						{
							expr->getLHS()->accept( this );
						}

						expr->getRHS()->accept( this );
					}

					void visitAssignExpr( ast::expr::Assign const * expr )override
					{
						visitExprIdentifiers( *expr->getLHS() );
						expr->getRHS()->accept( this );
					}

					void visitAggrInitExpr( ast::expr::AggrInit const * expr )override
					{
						if ( expr->hasIdentifier() )
						{
							expr->getIdentifier().accept( this );
						}

						for ( auto & arg : expr->getInitialisers() )
						{
							arg->accept( this );
						}
					}

					void visitCombinedImageAccessCallExpr( ast::expr::CombinedImageAccessCall const * expr )override
					{
						for ( auto & arg : expr->getArgList() )
						{
							arg->accept( this );
						}
					}

					void visitCompositeConstructExpr( ast::expr::CompositeConstruct const * expr )override
					{
						for ( auto & arg : expr->getArgList() )
						{
							arg->accept( this );
						}
					}

					void visitFnCallExpr( ast::expr::FnCall const * expr )override
					{
						expr->getFn()->accept( this );
						auto & fnType = static_cast< type::Function const & >( *expr->getFn()->getType() );
						auto paramIt = fnType.begin();

						for ( auto & arg : expr->getArgList() )
						{
							if ( auto identifiers = listIdentifiers( *arg );
								!identifiers.empty() )
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

					void visitIdentifierExpr( ast::expr::Identifier const * expr )override
					{
					}

					void visitImageAccessCallExpr( ast::expr::StorageImageAccessCall const * expr )override
					{
						for ( auto & arg : expr->getArgList() )
						{
							arg->accept( this );
						}
					}

					void visitInitExpr( ast::expr::Init const * expr )override
					{
						if ( expr->hasIdentifier() )
						{
							expr->getIdentifier().accept( this );
						}

						expr->getInitialiser()->accept( this );
					}

					void visitIntrinsicCallExpr( ast::expr::IntrinsicCall const * expr )override
					{
						for ( auto & arg : expr->getArgList() )
						{
							arg->accept( this );
						}
					}

					void visitLiteralExpr( ast::expr::Literal const * expr )override
					{
					}

					void visitMbrSelectExpr( ast::expr::MbrSelect const * expr )override
					{
						expr->getOuterExpr()->accept( this );
					}

					void visitQuestionExpr( ast::expr::Question const * expr )override
					{
						expr->getCtrlExpr()->accept( this );
						expr->getTrueExpr()->accept( this );
						expr->getFalseExpr()->accept( this );
					}

					void visitStreamAppendExpr( ast::expr::StreamAppend const * expr )override
					{
						expr->getOperand()->accept( this );
					}

					void visitSwitchCaseExpr( ast::expr::SwitchCase const * expr )override
					{
						expr->getLabel()->accept( this );
					}

					void visitSwitchTestExpr( ast::expr::SwitchTest const * expr )override
					{
						expr->getValue()->accept( this );
					}

					void visitSwizzleExpr( ast::expr::Swizzle const * expr )override
					{
						expr->getOuterExpr()->accept( this );
					}

					void visitAddAssignExpr( ast::expr::AddAssign const * expr )override
					{
						AST_Exception( "Unexpected AddAssign expression" );
					}

					void visitAndAssignExpr( ast::expr::AndAssign const * expr )override
					{
						AST_Exception( "Unexpected AndAssign expression" );
					}

					void visitDivideAssignExpr( ast::expr::DivideAssign const * expr )override
					{
						AST_Exception( "Unexpected DivideAssign expression" );
					}

					void visitLShiftAssignExpr( ast::expr::LShiftAssign const * expr )override
					{
						AST_Exception( "Unexpected LShiftAssign expression" );
					}

					void visitMinusAssignExpr( ast::expr::MinusAssign const * expr )override
					{
						AST_Exception( "Unexpected MinusAssign expression" );
					}

					void visitModuloAssignExpr( ast::expr::ModuloAssign const * expr )override
					{
						AST_Exception( "Unexpected ModuloAssign expression" );
					}

					void visitOrAssignExpr( ast::expr::OrAssign const * expr )override
					{
						AST_Exception( "Unexpected OrAssign expression" );
					}

					void visitRShiftAssignExpr( ast::expr::RShiftAssign const * expr )override
					{
						AST_Exception( "Unexpected RShiftAssign expression" );
					}

					void visitTimesAssignExpr( ast::expr::TimesAssign const * expr )override
					{
						AST_Exception( "Unexpected TimesAssign expression" );
					}

					void visitXorAssignExpr( ast::expr::XorAssign const * expr )override
					{
						AST_Exception( "Unexpected XorAssign expression" );
					}

					void visitPostDecrementExpr(expr::PostDecrement const * expr )override
					{
						AST_Exception( "Unexpected PostDecrement expression" );
					}

					void visitPostIncrementExpr(expr::PostIncrement const * expr )override
					{
						AST_Exception( "Unexpected PostIncrement expression" );
					}

					void visitPreDecrementExpr(expr::PreDecrement const * expr )override
					{
						AST_Exception( "Unexpected PreDecrement expression" );
					}

					void visitPreIncrementExpr(expr::PreIncrement const * expr )override
					{
						AST_Exception( "Unexpected PreIncrement expression" );
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
						, ast::stmt::Container const & stmt )
					{
						bool result{ false };
						StmtVisitor vis{ variable, result };
						stmt.accept( &vis );
						return result;
					}

				private:
					StmtVisitor( var::VariablePtr variable
						, bool & result )
						: m_variable{ variable }
						, m_result{ result }
					{
					}
					void visitAccelerationStructureDeclStmt( stmt::AccelerationStructureDecl const * stmt )override
					{
					}
					void visitBreakStmt( stmt::Break const * stmt )override
					{
					}
					void visitBufferReferenceDeclStmt( stmt::BufferReferenceDecl const * stmt )override
					{
					}
					void visitCommentStmt( stmt::Comment const * stmt )override
					{
					}
					void visitCompoundStmt( stmt::Compound const * stmt )override
					{
						visitContainerStmt( stmt );
					}
					void visitContainerStmt( stmt::Container const * stmt )override
					{
						for ( auto & sub : *stmt )
						{
							sub->accept( this );
						}
					}
					void visitContinueStmt( stmt::Continue const * stmt )override
					{
					}
					void visitConstantBufferDeclStmt( stmt::ConstantBufferDecl const * stmt )override
					{
					}
					void visitDemoteStmt( stmt::Demote const * stmt )override
					{
					}
					void visitDispatchMeshStmt( stmt::DispatchMesh const * stmt )override
					{
					}
					void visitTerminateInvocationStmt( stmt::TerminateInvocation const * stmt )override
					{
					}
					void visitDoWhileStmt( stmt::DoWhile const * stmt )override
					{
						if ( stmt->getCtrlExpr() )
						{
							ExprVisitor::submit( m_variable, *stmt->getCtrlExpr(), m_result );
						}

						visitContainerStmt( stmt );
					}
					void visitElseIfStmt( stmt::ElseIf const * stmt )override
					{
						if ( stmt->getCtrlExpr() )
						{
							ExprVisitor::submit( m_variable, *stmt->getCtrlExpr(), m_result );
						}

						visitContainerStmt( stmt );
					}
					void visitElseStmt( stmt::Else const * stmt )override
					{
						visitContainerStmt( stmt );
					}
					void visitForStmt( stmt::For const * stmt )override
					{
						if ( stmt->getCtrlExpr() )
						{
							ExprVisitor::submit( m_variable, *stmt->getCtrlExpr(), m_result );
						}

						if ( stmt->getInitExpr() )
						{
							ExprVisitor::submit( m_variable, *stmt->getInitExpr(), m_result );
						}

						visitContainerStmt( stmt );
					}
					void visitFragmentLayoutStmt( stmt::FragmentLayout const * stmt )override
					{
					}
					void visitFunctionDeclStmt( stmt::FunctionDecl const * stmt )override
					{
						visitContainerStmt( stmt );
					}
					void visitHitAttributeVariableDeclStmt( stmt::HitAttributeVariableDecl const * stmt )override
					{
					}
					void visitIfStmt( stmt::If const * stmt )override
					{
						if ( stmt->getCtrlExpr() )
						{
							ExprVisitor::submit( m_variable, *stmt->getCtrlExpr(), m_result );
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
					void visitImageDeclStmt( stmt::ImageDecl const * stmt )override
					{
					}
					void visitIgnoreIntersectionStmt( stmt::IgnoreIntersection const * stmt )override
					{
					}
					void visitInOutCallableDataVariableDeclStmt( stmt::InOutCallableDataVariableDecl const * stmt )override
					{
					}
					void visitInOutRayPayloadVariableDeclStmt( stmt::InOutRayPayloadVariableDecl const * stmt )override
					{
					}
					void visitInOutVariableDeclStmt( stmt::InOutVariableDecl const * stmt )override
					{
					}
					void visitInputComputeLayoutStmt( stmt::InputComputeLayout const * stmt )override
					{
					}
					void visitInputGeometryLayoutStmt( stmt::InputGeometryLayout const * stmt )override
					{
					}
					void visitInputTessellationEvaluationLayoutStmt( stmt::InputTessellationEvaluationLayout const * stmt )override
					{
					}
					void visitOutputGeometryLayoutStmt( stmt::OutputGeometryLayout const * stmt )override
					{
					}
					void visitOutputMeshLayoutStmt( stmt::OutputMeshLayout const * stmt )override
					{
					}
					void visitOutputTessellationControlLayoutStmt( stmt::OutputTessellationControlLayout const * stmt )override
					{
					}
					void visitPerPrimitiveDeclStmt( stmt::PerPrimitiveDecl const * stmt )override
					{
					}
					void visitPerVertexDeclStmt( stmt::PerVertexDecl const * stmt )override
					{
					}
					void visitPushConstantsBufferDeclStmt( stmt::PushConstantsBufferDecl const * stmt )override
					{
						visitContainerStmt( stmt );
					}
					void visitReturnStmt( stmt::Return const * stmt )override
					{
						if ( auto expr = stmt->getExpr() )
						{
							ExprVisitor::submit( m_variable, *expr, m_result );
						}
					}
					void visitCombinedImageDeclStmt( stmt::CombinedImageDecl const * stmt )override
					{
					}
					void visitSampledImageDeclStmt( stmt::SampledImageDecl const * stmt )override
					{
					}
					void visitSamplerDeclStmt( stmt::SamplerDecl const * stmt )override
					{
					}
					void visitShaderBufferDeclStmt( stmt::ShaderBufferDecl const * stmt )override
					{
						visitContainerStmt( stmt );
					}
					void visitShaderStructBufferDeclStmt( stmt::ShaderStructBufferDecl const * stmt )override
					{
					}
					void visitSimpleStmt( stmt::Simple const * stmt )override
					{
						if ( !m_result )
						{
							ExprVisitor::submit( m_variable, *stmt->getExpr(), m_result );
						}
					}
					void visitSpecialisationConstantDeclStmt( stmt::SpecialisationConstantDecl const * stmt )override
					{
					}
					void visitStructureDeclStmt( stmt::StructureDecl const * stmt )override
					{
					}
					void visitSwitchCaseStmt( stmt::SwitchCase const * stmt )override
					{
						if ( stmt->getCaseExpr() )
						{
							ExprVisitor::submit( m_variable, *stmt->getCaseExpr(), m_result );
						}

						visitContainerStmt( stmt );
					}
					void visitSwitchStmt( stmt::Switch const * stmt )override
					{
						if ( stmt->getTestExpr() )
						{
							ExprVisitor::submit( m_variable, *stmt->getTestExpr(), m_result );
						}

						visitContainerStmt( stmt );
					}
					void visitTerminateRayStmt( stmt::TerminateRay const * stmt )override
					{
					}
					void visitVariableDeclStmt( stmt::VariableDecl const * stmt )override
					{
					}
					void visitWhileStmt( stmt::While const * stmt )override
					{
						if ( stmt->getCtrlExpr() )
						{
							ExprVisitor::submit( m_variable, *stmt->getCtrlExpr(), m_result );
						}

						visitContainerStmt( stmt );
					}
					void visitPreprocExtension( stmt::PreprocExtension const * stmt )override
					{
					}
					void visitPreprocVersion( stmt::PreprocVersion const * stmt )override
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
				expr::ExprPtr result{};

				if ( init.getKind() == expr::Kind::eAggrInit )
				{
					result = static_cast< expr::AggrInit const & >( init ).getInitialisers()[index]->clone();
				}
				else if ( init.getKind() == expr::Kind::eCompositeConstruct )
				{
					result = static_cast< expr::CompositeConstruct const & >( init ).getArgList()[index]->clone();
				}
				else
				{
					AST_Exception( "Non valid expression type to retrieve index value on." );
				}

				return result;
			}

			template< typename ValueT > struct ValueTraitsT;
			template<> struct ValueTraitsT< bool >
			{
				static constexpr expr::LiteralType literal = expr::LiteralType::eBool;
				static constexpr type::Kind kind = type::Kind::eBoolean;
			};
			template<> struct ValueTraitsT< signed char >
			{
				static constexpr expr::LiteralType literal = expr::LiteralType::eInt8;
				static constexpr type::Kind kind = type::Kind::eInt8;
			};
			template<> struct ValueTraitsT< signed short >
			{
				static constexpr expr::LiteralType literal = expr::LiteralType::eInt16;
				static constexpr type::Kind kind = type::Kind::eInt16;
			};
			template<> struct ValueTraitsT< signed int >
			{
				static constexpr expr::LiteralType literal = expr::LiteralType::eInt32;
				static constexpr type::Kind kind = type::Kind::eInt32;
			};
			template<> struct ValueTraitsT< signed long >
			{
				static constexpr expr::LiteralType literal = expr::LiteralType::eInt32;
				static constexpr type::Kind kind = type::Kind::eInt32;
			};
			template<> struct ValueTraitsT< signed long long >
			{
				static constexpr expr::LiteralType literal = expr::LiteralType::eInt64;
				static constexpr type::Kind kind = type::Kind::eInt64;
			};
			template<> struct ValueTraitsT< unsigned char >
			{
				static constexpr expr::LiteralType literal = expr::LiteralType::eUInt8;
				static constexpr type::Kind kind = type::Kind::eUInt8;
			};
			template<> struct ValueTraitsT< unsigned short >
			{
				static constexpr expr::LiteralType literal = expr::LiteralType::eUInt16;
				static constexpr type::Kind kind = type::Kind::eUInt16;
			};
			template<> struct ValueTraitsT< unsigned int >
			{
				static constexpr expr::LiteralType literal = expr::LiteralType::eUInt32;
				static constexpr type::Kind kind = type::Kind::eUInt32;
			};
			template<> struct ValueTraitsT< unsigned long >
			{
				static constexpr expr::LiteralType literal = expr::LiteralType::eUInt32;
				static constexpr type::Kind kind = type::Kind::eUInt32;
			};
			template<> struct ValueTraitsT< unsigned long long >
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

			static expr::ExprList getArgList( expr::Expr const & expr )
			{
				expr::ExprList result;

				if ( expr.getKind() == expr::Kind::eCompositeConstruct )
				{
					for ( auto & arg : static_cast< expr::CompositeConstruct const & >( expr ).getArgList() )
					{
						result.push_back( arg->clone() );
					}
				}
				else if ( expr.getKind() == expr::Kind::eAggrInit )
				{
					for ( auto & arg : static_cast< expr::AggrInit const & >( expr ).getInitialisers() )
					{
						result.push_back( arg->clone() );
					}
				}
				else if ( expr.getKind() == expr::Kind::eLiteral )
				{
					result.push_back( expr.clone() );
				}
				else
				{
					AST_Exception( "Can't process this expression" );
				}

				return result;
			}

			template< typename ValueT, size_t CountT >
			static DataT< ValueT, CountT > getData( expr::Expr const & arg )
			{
				auto args = getArgList( arg );

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
			static DataT< ValueU, CountT > process1T( DataT< ValueT, CountT > args
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
			static DataT< ValueU, CountT > process2T( DataT< ValueT, CountT > args1
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
			static DataT< ValueU, CountT > process3T( DataT< ValueT, CountT > args1
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
				expr::ExprPtr result{};
				DataT< ValueU, CountT > processed = process1T< ValueT, ValueU >( std::move( args ), func );

				switch ( CountT )
				{
				case 1u:
					result = exprCache.makeLiteral( typesCache, processed.front() );
					break;
				case 2u:
					result = exprCache.makeCompositeConstruct( expr::CompositeType::eVec2
						, kindT< ValueU >
						, makeList( exprCache.makeLiteral( typesCache, processed[0] )
							, exprCache.makeLiteral( typesCache, processed[1] ) ) );
					break;
				case 3u:
					result = exprCache.makeCompositeConstruct( expr::CompositeType::eVec3
						, kindT< ValueU >
						, makeList( exprCache.makeLiteral( typesCache, processed[0] )
							, exprCache.makeLiteral( typesCache, processed[1] )
							, exprCache.makeLiteral( typesCache, processed[2] ) ) );
					break;
				case 4u:
					result = exprCache.makeCompositeConstruct( expr::CompositeType::eVec4
						, kindT< ValueU >
						, makeList( exprCache.makeLiteral( typesCache, processed[0] )
							, exprCache.makeLiteral( typesCache, processed[1] )
							, exprCache.makeLiteral( typesCache, processed[2] )
							, exprCache.makeLiteral( typesCache, processed[3] ) ) );
					break;
				default:
					break;
				}

				return result;
			}

			template< typename ValueT, typename ValueU, size_t CountT, typename FuncT >
			static expr::ExprPtr apply2T( type::TypesCache & typesCache
				, expr::ExprCache & exprCache
				, DataT< ValueT, CountT > args1
				, DataT< ValueT, CountT > args2
				, FuncT func )
			{
				expr::ExprPtr result{};
				DataT< ValueU, CountT > processed = process2T< ValueT, ValueU >( std::move( args1 ), std::move( args2 ), func );

				switch ( CountT )
				{
				case 1u:
					result = exprCache.makeLiteral( typesCache, processed.front() );
					break;
				case 2u:
					result = exprCache.makeCompositeConstruct( expr::CompositeType::eVec2
						, kindT< ValueU >
						, makeList( exprCache.makeLiteral( typesCache, processed[0] )
							, exprCache.makeLiteral( typesCache, processed[1] ) ) );
					break;
				case 3u:
					result = exprCache.makeCompositeConstruct( expr::CompositeType::eVec3
						, kindT< ValueU >
						, makeList( exprCache.makeLiteral( typesCache, processed[0] )
							, exprCache.makeLiteral( typesCache, processed[1] )
							, exprCache.makeLiteral( typesCache, processed[2] ) ) );
					break;
				case 4u:
					result = exprCache.makeCompositeConstruct( expr::CompositeType::eVec4
						, kindT< ValueU >
						, makeList( exprCache.makeLiteral( typesCache, processed[0] )
							, exprCache.makeLiteral( typesCache, processed[1] )
							, exprCache.makeLiteral( typesCache, processed[2] )
							, exprCache.makeLiteral( typesCache, processed[3] ) ) );
					break;
				default:
					break;
				}

				return result;
			}

			template< typename ValueT, typename ValueU, size_t CountT, typename FuncT >
			static expr::ExprPtr apply3T( type::TypesCache & typesCache
				, expr::ExprCache & exprCache
				, DataT< ValueT, CountT > args1
				, DataT< ValueT, CountT > args2
				, DataT< ValueT, CountT > args3
				, FuncT func )
			{
				expr::ExprPtr result{};
				DataT< ValueU, CountT > processed = process3T< ValueT, ValueU >( std::move( args1 ), std::move( args2 ), std::move( args3 ), func );

				switch ( CountT )
				{
				case 1u:
					result = exprCache.makeLiteral( typesCache, processed.front() );
					break;
				case 2u:
					result = exprCache.makeCompositeConstruct( expr::CompositeType::eVec2
						, kindT< ValueU >
						, makeList( exprCache.makeLiteral( typesCache, processed[0] )
							, exprCache.makeLiteral( typesCache, processed[1] ) ) );
					break;
				case 3u:
					result = exprCache.makeCompositeConstruct( expr::CompositeType::eVec3
						, kindT< ValueU >
						, makeList( exprCache.makeLiteral( typesCache, processed[0] )
							, exprCache.makeLiteral( typesCache, processed[1] )
							, exprCache.makeLiteral( typesCache, processed[2] ) ) );
					break;
				case 4u:
					result = exprCache.makeCompositeConstruct( expr::CompositeType::eVec4
						, kindT< ValueU >
						, makeList( exprCache.makeLiteral( typesCache, processed[0] )
							, exprCache.makeLiteral( typesCache, processed[1] )
							, exprCache.makeLiteral( typesCache, processed[2] )
							, exprCache.makeLiteral( typesCache, processed[3] ) ) );
					break;
				default:
					break;
				}

				return result;
			}

			template< typename ValueT, size_t CountT, typename FuncT >
			static expr::ExprPtr gatherT( type::TypesCache & typesCache
				, expr::ExprCache & exprCache
				, DataT< ValueT, CountT > args
				, FuncT func )
			{
				expr::ExprPtr result{};

				switch ( CountT )
				{
				case 2u:
					result = exprCache.makeLiteral( typesCache, func( args[0], args[1] ) );
					break;
				case 3u:
					result = exprCache.makeLiteral( typesCache, func( args[0], func( args[1], args[2] ) ) );
					break;
				case 4u:
					result = exprCache.makeLiteral( typesCache, func( args[0], func( args[1], func( args[2], args[3] ) ) ) );
					break;
				default:
					break;
				}

				return result;
			}

			template< typename ValueT, typename FuncT >
			static expr::ExprPtr intrinsic1T( type::TypesCache & typesCache
				, expr::ExprCache & exprCache
				, expr::ExprList args
				, FuncT func )
			{
				expr::ExprPtr result{};

				switch ( auto & arg = *args.front();
					type::getComponentCount( arg.getType() ) )
				{
				case 1u: result = apply1T< ValueT, ValueT >( typesCache, exprCache, getData< ValueT, 1u >( arg ), func ); break;
				case 2u: result = apply1T< ValueT, ValueT >( typesCache, exprCache, getData< ValueT, 2u >( arg ), func ); break;
				case 3u: result = apply1T< ValueT, ValueT >( typesCache, exprCache, getData< ValueT, 3u >( arg ), func ); break;
				case 4u: result = apply1T< ValueT, ValueT >( typesCache, exprCache, getData< ValueT, 4u >( arg ), func ); break;
				default: break;
				}

				return result;
			}

			template< typename ValueT, typename FuncT >
			static expr::ExprPtr intrinsic1BoolT( type::TypesCache & typesCache
				, expr::ExprCache & exprCache
				, expr::ExprList args
				, FuncT func )
			{
				expr::ExprPtr result{};

				switch ( auto & arg = *args.front();
					type::getComponentCount( arg.getType() ) )
				{
				case 1u: result = apply1T< ValueT, bool >( typesCache, exprCache, getData< ValueT, 1u >( arg ), func ); break;
				case 2u: result = apply1T< ValueT, bool >( typesCache, exprCache, getData< ValueT, 2u >( arg ), func ); break;
				case 3u: result = apply1T< ValueT, bool >( typesCache, exprCache, getData< ValueT, 3u >( arg ), func ); break;
				case 4u: result = apply1T< ValueT, bool >( typesCache, exprCache, getData< ValueT, 4u >( arg ), func ); break;
				default: break;
				}

				return result;
			}

			template< typename ValueT, typename FuncT >
			static expr::ExprPtr intrinsic2T( type::TypesCache & typesCache
				, expr::ExprCache & exprCache
				, expr::ExprList args
				, FuncT func )
			{
				expr::ExprPtr result{};
				auto & arg2 = *args.back();

				switch ( auto & arg1 = *args.front();
					type::getComponentCount( arg1.getType() ) )
				{
				case 1u: result = apply2T< ValueT, ValueT >( typesCache, exprCache, getData< ValueT, 1u >( arg1 ), getData< ValueT, 1u >( arg2 ), func ); break;
				case 2u: result = apply2T< ValueT, ValueT >( typesCache, exprCache, getData< ValueT, 2u >( arg1 ), getData< ValueT, 2u >( arg2 ), func ); break;
				case 3u: result = apply2T< ValueT, ValueT >( typesCache, exprCache, getData< ValueT, 3u >( arg1 ), getData< ValueT, 3u >( arg2 ), func ); break;
				case 4u: result = apply2T< ValueT, ValueT >( typesCache, exprCache, getData< ValueT, 4u >( arg1 ), getData< ValueT, 4u >( arg2 ), func ); break;
				default: break;
				}

				return result;
			}

			template< typename ValueT, typename FuncT >
			static expr::ExprPtr intrinsicCompT( type::TypesCache & typesCache
				, expr::ExprCache & exprCache
				, expr::ExprList args
				, FuncT func )
			{
				expr::ExprPtr result{};
				auto & arg2 = *args.back();

				switch ( auto & arg1 = *args.front();
					type::getComponentCount( arg1.getType() ) )
				{
				case 1u: result = apply2T< ValueT, bool >( typesCache, exprCache, getData< ValueT, 1u >( arg1 ), getData< ValueT, 1u >( arg2 ), func ); break;
				case 2u: result = apply2T< ValueT, bool >( typesCache, exprCache, getData< ValueT, 2u >( arg1 ), getData< ValueT, 2u >( arg2 ), func ); break;
				case 3u: result = apply2T< ValueT, bool >( typesCache, exprCache, getData< ValueT, 3u >( arg1 ), getData< ValueT, 3u >( arg2 ), func ); break;
				case 4u: result = apply2T< ValueT, bool >( typesCache, exprCache, getData< ValueT, 4u >( arg1 ), getData< ValueT, 4u >( arg2 ), func ); break;
				default: break;
				}

				return result;
			}

			template< typename ValueT, typename FuncT >
			static expr::ExprPtr intrinsic3T( type::TypesCache & typesCache
				, expr::ExprCache & exprCache
				, expr::ExprList args
				, FuncT func )
			{
				expr::ExprPtr result{};
				auto & arg2 = *args[1];
				auto & arg3 = *args[2];

				switch ( auto & arg1 = *args[0];
					type::getComponentCount( arg1.getType() ) )
				{
				case 1u: result = apply3T< ValueT, ValueT >( typesCache, exprCache, getData< ValueT, 1u >( arg1 ), getData< ValueT, 1u >( arg2 ), getData< ValueT, 1u >( arg3 ), func ); break;
				case 2u: result = apply3T< ValueT, ValueT >( typesCache, exprCache, getData< ValueT, 2u >( arg1 ), getData< ValueT, 2u >( arg2 ), getData< ValueT, 2u >( arg3 ), func ); break;
				case 3u: result = apply3T< ValueT, ValueT >( typesCache, exprCache, getData< ValueT, 3u >( arg1 ), getData< ValueT, 3u >( arg2 ), getData< ValueT, 3u >( arg3 ), func ); break;
				case 4u: result = apply3T< ValueT, ValueT >( typesCache, exprCache, getData< ValueT, 4u >( arg1 ), getData< ValueT, 4u >( arg2 ), getData< ValueT, 4u >( arg3 ), func ); break;
				default: break;
				}

				return result;
			}

			template< typename ValueT, typename FuncT >
			static expr::ExprPtr intrinsicGatherT( type::TypesCache & typesCache
				, expr::ExprCache & exprCache
				, expr::ExprList args
				, FuncT func )
			{
				expr::ExprPtr result{};

				switch ( auto & arg = *args.front();
					type::getComponentCount( arg.getType() ) )
				{
				case 2u: result = gatherT< ValueT >( typesCache, exprCache, getData< ValueT, 2u >( arg ), func ); break;
				case 3u: result = gatherT< ValueT >( typesCache, exprCache, getData< ValueT, 3u >( arg ), func ); break;
				case 4u: result = gatherT< ValueT >( typesCache, exprCache, getData< ValueT, 4u >( arg ), func ); break;
				default: break;
				}

				return result;
			}

			static bool isConstantResolvable( expr::Intrinsic intrinsic )
			{
				return intrinsic == ast::expr::Intrinsic::eDegrees1
					|| intrinsic == ast::expr::Intrinsic::eDegrees2
					|| intrinsic == ast::expr::Intrinsic::eDegrees3
					|| intrinsic == ast::expr::Intrinsic::eDegrees4
					|| intrinsic == ast::expr::Intrinsic::eRadians1F
					|| intrinsic == ast::expr::Intrinsic::eRadians2F
					|| intrinsic == ast::expr::Intrinsic::eRadians3F
					|| intrinsic == ast::expr::Intrinsic::eRadians4F
					|| intrinsic == ast::expr::Intrinsic::eCos1
					|| intrinsic == ast::expr::Intrinsic::eCos2
					|| intrinsic == ast::expr::Intrinsic::eCos3
					|| intrinsic == ast::expr::Intrinsic::eCos4
					|| intrinsic == ast::expr::Intrinsic::eSin1
					|| intrinsic == ast::expr::Intrinsic::eSin2
					|| intrinsic == ast::expr::Intrinsic::eSin3
					|| intrinsic == ast::expr::Intrinsic::eSin4
					|| intrinsic == ast::expr::Intrinsic::eTan1
					|| intrinsic == ast::expr::Intrinsic::eTan2
					|| intrinsic == ast::expr::Intrinsic::eTan3
					|| intrinsic == ast::expr::Intrinsic::eTan4
					|| intrinsic == ast::expr::Intrinsic::eCosh1
					|| intrinsic == ast::expr::Intrinsic::eCosh2
					|| intrinsic == ast::expr::Intrinsic::eCosh3
					|| intrinsic == ast::expr::Intrinsic::eCosh4
					|| intrinsic == ast::expr::Intrinsic::eSinh1
					|| intrinsic == ast::expr::Intrinsic::eSinh2
					|| intrinsic == ast::expr::Intrinsic::eSinh3
					|| intrinsic == ast::expr::Intrinsic::eSinh4
					|| intrinsic == ast::expr::Intrinsic::eTanh1
					|| intrinsic == ast::expr::Intrinsic::eTanh2
					|| intrinsic == ast::expr::Intrinsic::eTanh3
					|| intrinsic == ast::expr::Intrinsic::eTanh4
					|| intrinsic == ast::expr::Intrinsic::eAcos1
					|| intrinsic == ast::expr::Intrinsic::eAcos2
					|| intrinsic == ast::expr::Intrinsic::eAcos3
					|| intrinsic == ast::expr::Intrinsic::eAcos4
					|| intrinsic == ast::expr::Intrinsic::eAsin1
					|| intrinsic == ast::expr::Intrinsic::eAsin2
					|| intrinsic == ast::expr::Intrinsic::eAsin3
					|| intrinsic == ast::expr::Intrinsic::eAsin4
					|| intrinsic == ast::expr::Intrinsic::eAtan1
					|| intrinsic == ast::expr::Intrinsic::eAtan2
					|| intrinsic == ast::expr::Intrinsic::eAtan3
					|| intrinsic == ast::expr::Intrinsic::eAtan4
					|| intrinsic == ast::expr::Intrinsic::eAtan21
					|| intrinsic == ast::expr::Intrinsic::eAtan22
					|| intrinsic == ast::expr::Intrinsic::eAtan23
					|| intrinsic == ast::expr::Intrinsic::eAtan24
					|| intrinsic == ast::expr::Intrinsic::eAcosh1
					|| intrinsic == ast::expr::Intrinsic::eAcosh2
					|| intrinsic == ast::expr::Intrinsic::eAcosh3
					|| intrinsic == ast::expr::Intrinsic::eAcosh4
					|| intrinsic == ast::expr::Intrinsic::eAsinh1
					|| intrinsic == ast::expr::Intrinsic::eAsinh2
					|| intrinsic == ast::expr::Intrinsic::eAsinh3
					|| intrinsic == ast::expr::Intrinsic::eAsinh4
					|| intrinsic == ast::expr::Intrinsic::eAtanh1
					|| intrinsic == ast::expr::Intrinsic::eAtanh2
					|| intrinsic == ast::expr::Intrinsic::eAtanh3
					|| intrinsic == ast::expr::Intrinsic::eAtanh4
					|| intrinsic == ast::expr::Intrinsic::ePow1
					|| intrinsic == ast::expr::Intrinsic::ePow2
					|| intrinsic == ast::expr::Intrinsic::ePow3
					|| intrinsic == ast::expr::Intrinsic::ePow4
					|| intrinsic == ast::expr::Intrinsic::eExp1
					|| intrinsic == ast::expr::Intrinsic::eExp2
					|| intrinsic == ast::expr::Intrinsic::eExp3
					|| intrinsic == ast::expr::Intrinsic::eExp4
					|| intrinsic == ast::expr::Intrinsic::eLog1
					|| intrinsic == ast::expr::Intrinsic::eLog2
					|| intrinsic == ast::expr::Intrinsic::eLog3
					|| intrinsic == ast::expr::Intrinsic::eLog4
					|| intrinsic == ast::expr::Intrinsic::eExp21
					|| intrinsic == ast::expr::Intrinsic::eExp22
					|| intrinsic == ast::expr::Intrinsic::eExp23
					|| intrinsic == ast::expr::Intrinsic::eExp24
					|| intrinsic == ast::expr::Intrinsic::eLog21
					|| intrinsic == ast::expr::Intrinsic::eLog22
					|| intrinsic == ast::expr::Intrinsic::eLog23
					|| intrinsic == ast::expr::Intrinsic::eLog24
					|| intrinsic == ast::expr::Intrinsic::eSqrt1F
					|| intrinsic == ast::expr::Intrinsic::eSqrt2F
					|| intrinsic == ast::expr::Intrinsic::eSqrt3F
					|| intrinsic == ast::expr::Intrinsic::eSqrt4F
					|| intrinsic == ast::expr::Intrinsic::eSqrt1D
					|| intrinsic == ast::expr::Intrinsic::eSqrt2D
					|| intrinsic == ast::expr::Intrinsic::eSqrt3D
					|| intrinsic == ast::expr::Intrinsic::eSqrt4D
					|| intrinsic == ast::expr::Intrinsic::eInverseSqrt1F
					|| intrinsic == ast::expr::Intrinsic::eInverseSqrt2F
					|| intrinsic == ast::expr::Intrinsic::eInverseSqrt3F
					|| intrinsic == ast::expr::Intrinsic::eInverseSqrt4F
					|| intrinsic == ast::expr::Intrinsic::eInverseSqrt1D
					|| intrinsic == ast::expr::Intrinsic::eInverseSqrt2D
					|| intrinsic == ast::expr::Intrinsic::eInverseSqrt3D
					|| intrinsic == ast::expr::Intrinsic::eInverseSqrt4D
					|| intrinsic == ast::expr::Intrinsic::eAbs1F
					|| intrinsic == ast::expr::Intrinsic::eAbs2F
					|| intrinsic == ast::expr::Intrinsic::eAbs3F
					|| intrinsic == ast::expr::Intrinsic::eAbs4F
					|| intrinsic == ast::expr::Intrinsic::eAbs1I
					|| intrinsic == ast::expr::Intrinsic::eAbs2I
					|| intrinsic == ast::expr::Intrinsic::eAbs3I
					|| intrinsic == ast::expr::Intrinsic::eAbs4I
					|| intrinsic == ast::expr::Intrinsic::eAbs1D
					|| intrinsic == ast::expr::Intrinsic::eAbs2D
					|| intrinsic == ast::expr::Intrinsic::eAbs3D
					|| intrinsic == ast::expr::Intrinsic::eAbs4D
					|| intrinsic == ast::expr::Intrinsic::eSign1F
					|| intrinsic == ast::expr::Intrinsic::eSign2F
					|| intrinsic == ast::expr::Intrinsic::eSign3F
					|| intrinsic == ast::expr::Intrinsic::eSign4F
					|| intrinsic == ast::expr::Intrinsic::eSign1I
					|| intrinsic == ast::expr::Intrinsic::eSign2I
					|| intrinsic == ast::expr::Intrinsic::eSign3I
					|| intrinsic == ast::expr::Intrinsic::eSign4I
					|| intrinsic == ast::expr::Intrinsic::eSign1D
					|| intrinsic == ast::expr::Intrinsic::eSign2D
					|| intrinsic == ast::expr::Intrinsic::eSign3D
					|| intrinsic == ast::expr::Intrinsic::eSign4D
					|| intrinsic == ast::expr::Intrinsic::eFloor1F
					|| intrinsic == ast::expr::Intrinsic::eFloor2F
					|| intrinsic == ast::expr::Intrinsic::eFloor3F
					|| intrinsic == ast::expr::Intrinsic::eFloor4F
					|| intrinsic == ast::expr::Intrinsic::eFloor1D
					|| intrinsic == ast::expr::Intrinsic::eFloor2D
					|| intrinsic == ast::expr::Intrinsic::eFloor3D
					|| intrinsic == ast::expr::Intrinsic::eFloor4D
					|| intrinsic == ast::expr::Intrinsic::eTrunc1F
					|| intrinsic == ast::expr::Intrinsic::eTrunc2F
					|| intrinsic == ast::expr::Intrinsic::eTrunc3F
					|| intrinsic == ast::expr::Intrinsic::eTrunc4F
					|| intrinsic == ast::expr::Intrinsic::eTrunc1D
					|| intrinsic == ast::expr::Intrinsic::eTrunc2D
					|| intrinsic == ast::expr::Intrinsic::eTrunc3D
					|| intrinsic == ast::expr::Intrinsic::eTrunc4D
					|| intrinsic == ast::expr::Intrinsic::eRound1F
					|| intrinsic == ast::expr::Intrinsic::eRound2F
					|| intrinsic == ast::expr::Intrinsic::eRound3F
					|| intrinsic == ast::expr::Intrinsic::eRound4F
					|| intrinsic == ast::expr::Intrinsic::eRound1D
					|| intrinsic == ast::expr::Intrinsic::eRound2D
					|| intrinsic == ast::expr::Intrinsic::eRound3D
					|| intrinsic == ast::expr::Intrinsic::eRound4D
					|| intrinsic == ast::expr::Intrinsic::eRoundEven1F
					|| intrinsic == ast::expr::Intrinsic::eRoundEven2F
					|| intrinsic == ast::expr::Intrinsic::eRoundEven3F
					|| intrinsic == ast::expr::Intrinsic::eRoundEven4F
					|| intrinsic == ast::expr::Intrinsic::eRoundEven1D
					|| intrinsic == ast::expr::Intrinsic::eRoundEven2D
					|| intrinsic == ast::expr::Intrinsic::eRoundEven3D
					|| intrinsic == ast::expr::Intrinsic::eRoundEven4D
					|| intrinsic == ast::expr::Intrinsic::eCeil1F
					|| intrinsic == ast::expr::Intrinsic::eCeil2F
					|| intrinsic == ast::expr::Intrinsic::eCeil3F
					|| intrinsic == ast::expr::Intrinsic::eCeil4F
					|| intrinsic == ast::expr::Intrinsic::eCeil1D
					|| intrinsic == ast::expr::Intrinsic::eCeil2D
					|| intrinsic == ast::expr::Intrinsic::eCeil3D
					|| intrinsic == ast::expr::Intrinsic::eCeil4D
					|| intrinsic == ast::expr::Intrinsic::eFract1F
					|| intrinsic == ast::expr::Intrinsic::eFract2F
					|| intrinsic == ast::expr::Intrinsic::eFract3F
					|| intrinsic == ast::expr::Intrinsic::eFract4F
					|| intrinsic == ast::expr::Intrinsic::eFract1D
					|| intrinsic == ast::expr::Intrinsic::eFract2D
					|| intrinsic == ast::expr::Intrinsic::eFract3D
					|| intrinsic == ast::expr::Intrinsic::eFract4D
					|| intrinsic == ast::expr::Intrinsic::eMod1F
					|| intrinsic == ast::expr::Intrinsic::eMod2F
					|| intrinsic == ast::expr::Intrinsic::eMod3F
					|| intrinsic == ast::expr::Intrinsic::eMod4F
					|| intrinsic == ast::expr::Intrinsic::eMod1D
					|| intrinsic == ast::expr::Intrinsic::eMod2D
					|| intrinsic == ast::expr::Intrinsic::eMod3D
					|| intrinsic == ast::expr::Intrinsic::eMod4D
					|| intrinsic == ast::expr::Intrinsic::eMin1F
					|| intrinsic == ast::expr::Intrinsic::eMin2F
					|| intrinsic == ast::expr::Intrinsic::eMin3F
					|| intrinsic == ast::expr::Intrinsic::eMin4F
					|| intrinsic == ast::expr::Intrinsic::eMin1D
					|| intrinsic == ast::expr::Intrinsic::eMin2D
					|| intrinsic == ast::expr::Intrinsic::eMin3D
					|| intrinsic == ast::expr::Intrinsic::eMin4D
					|| intrinsic == ast::expr::Intrinsic::eMin1I
					|| intrinsic == ast::expr::Intrinsic::eMin2I
					|| intrinsic == ast::expr::Intrinsic::eMin3I
					|| intrinsic == ast::expr::Intrinsic::eMin4I
					|| intrinsic == ast::expr::Intrinsic::eMin1U
					|| intrinsic == ast::expr::Intrinsic::eMin2U
					|| intrinsic == ast::expr::Intrinsic::eMin3U
					|| intrinsic == ast::expr::Intrinsic::eMin4U
					|| intrinsic == ast::expr::Intrinsic::eMax1F
					|| intrinsic == ast::expr::Intrinsic::eMax2F
					|| intrinsic == ast::expr::Intrinsic::eMax3F
					|| intrinsic == ast::expr::Intrinsic::eMax4F
					|| intrinsic == ast::expr::Intrinsic::eMax1D
					|| intrinsic == ast::expr::Intrinsic::eMax2D
					|| intrinsic == ast::expr::Intrinsic::eMax3D
					|| intrinsic == ast::expr::Intrinsic::eMax4D
					|| intrinsic == ast::expr::Intrinsic::eMax1I
					|| intrinsic == ast::expr::Intrinsic::eMax2I
					|| intrinsic == ast::expr::Intrinsic::eMax3I
					|| intrinsic == ast::expr::Intrinsic::eMax4I
					|| intrinsic == ast::expr::Intrinsic::eMax1U
					|| intrinsic == ast::expr::Intrinsic::eMax2U
					|| intrinsic == ast::expr::Intrinsic::eMax3U
					|| intrinsic == ast::expr::Intrinsic::eMax4U
					|| intrinsic == ast::expr::Intrinsic::eClamp1F
					|| intrinsic == ast::expr::Intrinsic::eClamp2F
					|| intrinsic == ast::expr::Intrinsic::eClamp3F
					|| intrinsic == ast::expr::Intrinsic::eClamp4F
					|| intrinsic == ast::expr::Intrinsic::eClamp1D
					|| intrinsic == ast::expr::Intrinsic::eClamp2D
					|| intrinsic == ast::expr::Intrinsic::eClamp3D
					|| intrinsic == ast::expr::Intrinsic::eClamp4D
					|| intrinsic == ast::expr::Intrinsic::eClamp1I
					|| intrinsic == ast::expr::Intrinsic::eClamp2I
					|| intrinsic == ast::expr::Intrinsic::eClamp3I
					|| intrinsic == ast::expr::Intrinsic::eClamp4I
					|| intrinsic == ast::expr::Intrinsic::eClamp1U
					|| intrinsic == ast::expr::Intrinsic::eClamp2U
					|| intrinsic == ast::expr::Intrinsic::eClamp3U
					|| intrinsic == ast::expr::Intrinsic::eClamp4U
					|| intrinsic == ast::expr::Intrinsic::eMix1F
					|| intrinsic == ast::expr::Intrinsic::eMix2F
					|| intrinsic == ast::expr::Intrinsic::eMix3F
					|| intrinsic == ast::expr::Intrinsic::eMix4F
					|| intrinsic == ast::expr::Intrinsic::eMix1D
					|| intrinsic == ast::expr::Intrinsic::eMix2D
					|| intrinsic == ast::expr::Intrinsic::eMix3D
					|| intrinsic == ast::expr::Intrinsic::eMix4D
					|| intrinsic == ast::expr::Intrinsic::eStep1F
					|| intrinsic == ast::expr::Intrinsic::eStep2F
					|| intrinsic == ast::expr::Intrinsic::eStep3F
					|| intrinsic == ast::expr::Intrinsic::eStep4F
					|| intrinsic == ast::expr::Intrinsic::eStep1D
					|| intrinsic == ast::expr::Intrinsic::eStep2D
					|| intrinsic == ast::expr::Intrinsic::eStep3D
					|| intrinsic == ast::expr::Intrinsic::eStep4D
					|| intrinsic == ast::expr::Intrinsic::eSmoothStep1F
					|| intrinsic == ast::expr::Intrinsic::eSmoothStep2F
					|| intrinsic == ast::expr::Intrinsic::eSmoothStep3F
					|| intrinsic == ast::expr::Intrinsic::eSmoothStep4F
					|| intrinsic == ast::expr::Intrinsic::eSmoothStep1D
					|| intrinsic == ast::expr::Intrinsic::eSmoothStep2D
					|| intrinsic == ast::expr::Intrinsic::eSmoothStep3D
					|| intrinsic == ast::expr::Intrinsic::eSmoothStep4D
					|| intrinsic == ast::expr::Intrinsic::eIsnan1F
					|| intrinsic == ast::expr::Intrinsic::eIsnan2F
					|| intrinsic == ast::expr::Intrinsic::eIsnan3F
					|| intrinsic == ast::expr::Intrinsic::eIsnan4F
					|| intrinsic == ast::expr::Intrinsic::eIsnan1D
					|| intrinsic == ast::expr::Intrinsic::eIsnan2D
					|| intrinsic == ast::expr::Intrinsic::eIsnan3D
					|| intrinsic == ast::expr::Intrinsic::eIsnan4D
					|| intrinsic == ast::expr::Intrinsic::eIsinf1F
					|| intrinsic == ast::expr::Intrinsic::eIsinf2F
					|| intrinsic == ast::expr::Intrinsic::eIsinf3F
					|| intrinsic == ast::expr::Intrinsic::eIsinf4F
					|| intrinsic == ast::expr::Intrinsic::eIsinf1D
					|| intrinsic == ast::expr::Intrinsic::eIsinf2D
					|| intrinsic == ast::expr::Intrinsic::eIsinf3D
					|| intrinsic == ast::expr::Intrinsic::eIsinf4D
					|| intrinsic == ast::expr::Intrinsic::eFma1F
					|| intrinsic == ast::expr::Intrinsic::eFma2F
					|| intrinsic == ast::expr::Intrinsic::eFma3F
					|| intrinsic == ast::expr::Intrinsic::eFma4F
					|| intrinsic == ast::expr::Intrinsic::eFma1D
					|| intrinsic == ast::expr::Intrinsic::eFma2D
					|| intrinsic == ast::expr::Intrinsic::eFma3D
					|| intrinsic == ast::expr::Intrinsic::eFma4D
					|| intrinsic == ast::expr::Intrinsic::eLessThan2F
					|| intrinsic == ast::expr::Intrinsic::eLessThan3F
					|| intrinsic == ast::expr::Intrinsic::eLessThan4F
					|| intrinsic == ast::expr::Intrinsic::eLessThan2D
					|| intrinsic == ast::expr::Intrinsic::eLessThan3D
					|| intrinsic == ast::expr::Intrinsic::eLessThan4D
					|| intrinsic == ast::expr::Intrinsic::eLessThan2I
					|| intrinsic == ast::expr::Intrinsic::eLessThan3I
					|| intrinsic == ast::expr::Intrinsic::eLessThan4I
					|| intrinsic == ast::expr::Intrinsic::eLessThan2U
					|| intrinsic == ast::expr::Intrinsic::eLessThan3U
					|| intrinsic == ast::expr::Intrinsic::eLessThan4U
					|| intrinsic == ast::expr::Intrinsic::eLessThanEqual2F
					|| intrinsic == ast::expr::Intrinsic::eLessThanEqual3F
					|| intrinsic == ast::expr::Intrinsic::eLessThanEqual4F
					|| intrinsic == ast::expr::Intrinsic::eLessThanEqual2D
					|| intrinsic == ast::expr::Intrinsic::eLessThanEqual3D
					|| intrinsic == ast::expr::Intrinsic::eLessThanEqual4D
					|| intrinsic == ast::expr::Intrinsic::eLessThanEqual2I
					|| intrinsic == ast::expr::Intrinsic::eLessThanEqual3I
					|| intrinsic == ast::expr::Intrinsic::eLessThanEqual4I
					|| intrinsic == ast::expr::Intrinsic::eLessThanEqual2U
					|| intrinsic == ast::expr::Intrinsic::eLessThanEqual3U
					|| intrinsic == ast::expr::Intrinsic::eLessThanEqual4U
					|| intrinsic == ast::expr::Intrinsic::eGreaterThan2F
					|| intrinsic == ast::expr::Intrinsic::eGreaterThan3F
					|| intrinsic == ast::expr::Intrinsic::eGreaterThan4F
					|| intrinsic == ast::expr::Intrinsic::eGreaterThan2D
					|| intrinsic == ast::expr::Intrinsic::eGreaterThan3D
					|| intrinsic == ast::expr::Intrinsic::eGreaterThan4D
					|| intrinsic == ast::expr::Intrinsic::eGreaterThan2I
					|| intrinsic == ast::expr::Intrinsic::eGreaterThan3I
					|| intrinsic == ast::expr::Intrinsic::eGreaterThan4I
					|| intrinsic == ast::expr::Intrinsic::eGreaterThan2U
					|| intrinsic == ast::expr::Intrinsic::eGreaterThan3U
					|| intrinsic == ast::expr::Intrinsic::eGreaterThan4U
					|| intrinsic == ast::expr::Intrinsic::eGreaterThanEqual2F
					|| intrinsic == ast::expr::Intrinsic::eGreaterThanEqual3F
					|| intrinsic == ast::expr::Intrinsic::eGreaterThanEqual4F
					|| intrinsic == ast::expr::Intrinsic::eGreaterThanEqual2D
					|| intrinsic == ast::expr::Intrinsic::eGreaterThanEqual3D
					|| intrinsic == ast::expr::Intrinsic::eGreaterThanEqual4D
					|| intrinsic == ast::expr::Intrinsic::eGreaterThanEqual2I
					|| intrinsic == ast::expr::Intrinsic::eGreaterThanEqual3I
					|| intrinsic == ast::expr::Intrinsic::eGreaterThanEqual4I
					|| intrinsic == ast::expr::Intrinsic::eGreaterThanEqual2U
					|| intrinsic == ast::expr::Intrinsic::eGreaterThanEqual3U
					|| intrinsic == ast::expr::Intrinsic::eGreaterThanEqual4U
					|| intrinsic == ast::expr::Intrinsic::eEqual2F
					|| intrinsic == ast::expr::Intrinsic::eEqual3F
					|| intrinsic == ast::expr::Intrinsic::eEqual4F
					|| intrinsic == ast::expr::Intrinsic::eEqual2D
					|| intrinsic == ast::expr::Intrinsic::eEqual3D
					|| intrinsic == ast::expr::Intrinsic::eEqual4D
					|| intrinsic == ast::expr::Intrinsic::eEqual2I
					|| intrinsic == ast::expr::Intrinsic::eEqual3I
					|| intrinsic == ast::expr::Intrinsic::eEqual4I
					|| intrinsic == ast::expr::Intrinsic::eEqual2U
					|| intrinsic == ast::expr::Intrinsic::eEqual3U
					|| intrinsic == ast::expr::Intrinsic::eEqual4U
					|| intrinsic == ast::expr::Intrinsic::eNotEqual2F
					|| intrinsic == ast::expr::Intrinsic::eNotEqual3F
					|| intrinsic == ast::expr::Intrinsic::eNotEqual4F
					|| intrinsic == ast::expr::Intrinsic::eNotEqual2D
					|| intrinsic == ast::expr::Intrinsic::eNotEqual3D
					|| intrinsic == ast::expr::Intrinsic::eNotEqual4D
					|| intrinsic == ast::expr::Intrinsic::eNotEqual2I
					|| intrinsic == ast::expr::Intrinsic::eNotEqual3I
					|| intrinsic == ast::expr::Intrinsic::eNotEqual4I
					|| intrinsic == ast::expr::Intrinsic::eNotEqual2U
					|| intrinsic == ast::expr::Intrinsic::eNotEqual3U
					|| intrinsic == ast::expr::Intrinsic::eNotEqual4U
					|| intrinsic == ast::expr::Intrinsic::eAll2
					|| intrinsic == ast::expr::Intrinsic::eAll3
					|| intrinsic == ast::expr::Intrinsic::eAll4
					|| intrinsic == ast::expr::Intrinsic::eAny2
					|| intrinsic == ast::expr::Intrinsic::eAny3
					|| intrinsic == ast::expr::Intrinsic::eAny4
					|| intrinsic == ast::expr::Intrinsic::eNot2
					|| intrinsic == ast::expr::Intrinsic::eNot3
					|| intrinsic == ast::expr::Intrinsic::eNot4;
			}

			static expr::ExprPtr resolveConstant( type::TypesCache & typesCache
				, expr::ExprCache & exprCache
				, expr::Intrinsic intrinsic
				, expr::ExprList argsList )
			{
				expr::ExprPtr result{};
				try
				{
					switch ( intrinsic )
					{
					case ast::expr::Intrinsic::eDegrees1:
					case ast::expr::Intrinsic::eDegrees2:
					case ast::expr::Intrinsic::eDegrees3:
					case ast::expr::Intrinsic::eDegrees4:
						result = intrinsic1T< LitFloat32 >( typesCache, exprCache, std::move( argsList ), []( LitFloat32 v ){ return LitFloat32( v * 180.0f / std::numbers::pi ); } );
						break;
					case ast::expr::Intrinsic::eRadians1F:
					case ast::expr::Intrinsic::eRadians2F:
					case ast::expr::Intrinsic::eRadians3F:
					case ast::expr::Intrinsic::eRadians4F:
						result = intrinsic1T< LitFloat32 >( typesCache, exprCache, std::move( argsList ), []( LitFloat32 v ){ return LitFloat32( v * std::numbers::pi / 180.0f ); } );
						break;
					case ast::expr::Intrinsic::eCos1:
					case ast::expr::Intrinsic::eCos2:
					case ast::expr::Intrinsic::eCos3:
					case ast::expr::Intrinsic::eCos4:
						result = intrinsic1T< LitFloat32 >( typesCache, exprCache, std::move( argsList ), []( LitFloat32 v ){ return LitFloat32( ::cos( v ) ); } );
						break;
					case ast::expr::Intrinsic::eSin1:
					case ast::expr::Intrinsic::eSin2:
					case ast::expr::Intrinsic::eSin3:
					case ast::expr::Intrinsic::eSin4:
						result = intrinsic1T< LitFloat32 >( typesCache, exprCache, std::move( argsList ), []( LitFloat32 v ){ return LitFloat32( ::sin( v ) ); } );
						break;
					case ast::expr::Intrinsic::eTan1:
					case ast::expr::Intrinsic::eTan2:
					case ast::expr::Intrinsic::eTan3:
					case ast::expr::Intrinsic::eTan4:
						result = intrinsic1T< LitFloat32 >( typesCache, exprCache, std::move( argsList ), []( LitFloat32 v ){ return LitFloat32( ::tan( v ) ); } );
						break;
					case ast::expr::Intrinsic::eCosh1:
					case ast::expr::Intrinsic::eCosh2:
					case ast::expr::Intrinsic::eCosh3:
					case ast::expr::Intrinsic::eCosh4:
						result = intrinsic1T< LitFloat32 >( typesCache, exprCache, std::move( argsList ), []( LitFloat32 v ){ return LitFloat32( ::cosh( v ) ); } );
						break;
					case ast::expr::Intrinsic::eSinh1:
					case ast::expr::Intrinsic::eSinh2:
					case ast::expr::Intrinsic::eSinh3:
					case ast::expr::Intrinsic::eSinh4:
						result = intrinsic1T< LitFloat32 >( typesCache, exprCache, std::move( argsList ), []( LitFloat32 v ){ return LitFloat32( ::sinh( v ) ); } );
						break;
					case ast::expr::Intrinsic::eTanh1:
					case ast::expr::Intrinsic::eTanh2:
					case ast::expr::Intrinsic::eTanh3:
					case ast::expr::Intrinsic::eTanh4:
						result = intrinsic1T< LitFloat32 >( typesCache, exprCache, std::move( argsList ), []( LitFloat32 v ){ return LitFloat32( ::tanh( v ) ); } );
						break;
					case ast::expr::Intrinsic::eAcos1:
					case ast::expr::Intrinsic::eAcos2:
					case ast::expr::Intrinsic::eAcos3:
					case ast::expr::Intrinsic::eAcos4:
						result = intrinsic1T< LitFloat32 >( typesCache, exprCache, std::move( argsList ), []( LitFloat32 v ){ return LitFloat32( ::acos( v ) ); } );
						break;
					case ast::expr::Intrinsic::eAsin1:
					case ast::expr::Intrinsic::eAsin2:
					case ast::expr::Intrinsic::eAsin3:
					case ast::expr::Intrinsic::eAsin4:
						result = intrinsic1T< LitFloat32 >( typesCache, exprCache, std::move( argsList ), []( LitFloat32 v ){ return LitFloat32( ::asin( v ) ); } );
						break;
					case ast::expr::Intrinsic::eAtan1:
					case ast::expr::Intrinsic::eAtan2:
					case ast::expr::Intrinsic::eAtan3:
					case ast::expr::Intrinsic::eAtan4:
						result = intrinsic1T< LitFloat32 >( typesCache, exprCache, std::move( argsList ), []( LitFloat32 v ){ return LitFloat32( ::atan( v ) ); } );
						break;
					case ast::expr::Intrinsic::eAtan21:
					case ast::expr::Intrinsic::eAtan22:
					case ast::expr::Intrinsic::eAtan23:
					case ast::expr::Intrinsic::eAtan24:
						result = intrinsic2T< LitFloat32 >( typesCache, exprCache, std::move( argsList ), []( LitFloat32 v, LitFloat32 w ){ return LitFloat32( ::atan2( v, w ) ); } );
						break;
					case ast::expr::Intrinsic::eAcosh1:
					case ast::expr::Intrinsic::eAcosh2:
					case ast::expr::Intrinsic::eAcosh3:
					case ast::expr::Intrinsic::eAcosh4:
						result = intrinsic1T< LitFloat32 >( typesCache, exprCache, std::move( argsList ), []( LitFloat32 v ){ return LitFloat32( ::acosh( v ) ); } );
						break;
					case ast::expr::Intrinsic::eAsinh1:
					case ast::expr::Intrinsic::eAsinh2:
					case ast::expr::Intrinsic::eAsinh3:
					case ast::expr::Intrinsic::eAsinh4:
						result = intrinsic1T< LitFloat32 >( typesCache, exprCache, std::move( argsList ), []( LitFloat32 v ){ return LitFloat32( ::asinh( v ) ); } );
						break;
					case ast::expr::Intrinsic::eAtanh1:
					case ast::expr::Intrinsic::eAtanh2:
					case ast::expr::Intrinsic::eAtanh3:
					case ast::expr::Intrinsic::eAtanh4:
						result = intrinsic1T< LitFloat32 >( typesCache, exprCache, std::move( argsList ), []( LitFloat32 v ){ return LitFloat32( ::atanh( v ) ); } );
						break;
					case ast::expr::Intrinsic::ePow1:
					case ast::expr::Intrinsic::ePow2:
					case ast::expr::Intrinsic::ePow3:
					case ast::expr::Intrinsic::ePow4:
						result = intrinsic2T< LitFloat32 >( typesCache, exprCache, std::move( argsList ), []( LitFloat32 v, LitFloat32 w ){ return LitFloat32( ::pow( v, w ) ); } );
						break;
					case ast::expr::Intrinsic::eExp1:
					case ast::expr::Intrinsic::eExp2:
					case ast::expr::Intrinsic::eExp3:
					case ast::expr::Intrinsic::eExp4:
						result = intrinsic1T< LitFloat32 >( typesCache, exprCache, std::move( argsList ), []( LitFloat32 v ){ return LitFloat32( ::exp( v ) ); } );
						break;
					case ast::expr::Intrinsic::eLog1:
					case ast::expr::Intrinsic::eLog2:
					case ast::expr::Intrinsic::eLog3:
					case ast::expr::Intrinsic::eLog4:
						result = intrinsic1T< LitFloat32 >( typesCache, exprCache, std::move( argsList ), []( LitFloat32 v ){ return LitFloat32( ::log( v ) ); } );
						break;
					case ast::expr::Intrinsic::eExp21:
					case ast::expr::Intrinsic::eExp22:
					case ast::expr::Intrinsic::eExp23:
					case ast::expr::Intrinsic::eExp24:
						result = intrinsic1T< LitFloat32 >( typesCache, exprCache, std::move( argsList ), []( LitFloat32 v ){ return LitFloat32( ::exp2( v ) ); } );
						break;
					case ast::expr::Intrinsic::eLog21:
					case ast::expr::Intrinsic::eLog22:
					case ast::expr::Intrinsic::eLog23:
					case ast::expr::Intrinsic::eLog24:
						result = intrinsic1T< LitFloat32 >( typesCache, exprCache, std::move( argsList ), []( LitFloat32 v ){ return LitFloat32( ::log2( v ) ); } );
						break;
					case ast::expr::Intrinsic::eSqrt1F:
					case ast::expr::Intrinsic::eSqrt2F:
					case ast::expr::Intrinsic::eSqrt3F:
					case ast::expr::Intrinsic::eSqrt4F:
						result = intrinsic1T< LitFloat32 >( typesCache, exprCache, std::move( argsList ), []( LitFloat32 v ){ return LitFloat32( ::sqrt( v ) ); } );
						break;
					case ast::expr::Intrinsic::eSqrt1D:
					case ast::expr::Intrinsic::eSqrt2D:
					case ast::expr::Intrinsic::eSqrt3D:
					case ast::expr::Intrinsic::eSqrt4D:
						result = intrinsic1T< LitFloat64 >( typesCache, exprCache, std::move( argsList ), []( LitFloat64 v ){ return LitFloat64( ::sqrt( v ) ); } );
						break;
					case ast::expr::Intrinsic::eInverseSqrt1F:
					case ast::expr::Intrinsic::eInverseSqrt2F:
					case ast::expr::Intrinsic::eInverseSqrt3F:
					case ast::expr::Intrinsic::eInverseSqrt4F:
						result = intrinsic1T< LitFloat32 >( typesCache, exprCache, std::move( argsList ), []( LitFloat32 v ){ return LitFloat32( 1.0f / ::sqrt( v ) ); } );
						break;
					case ast::expr::Intrinsic::eInverseSqrt1D:
					case ast::expr::Intrinsic::eInverseSqrt2D:
					case ast::expr::Intrinsic::eInverseSqrt3D:
					case ast::expr::Intrinsic::eInverseSqrt4D:
						result = intrinsic1T< LitFloat64 >( typesCache, exprCache, std::move( argsList ), []( LitFloat64 v ){ return LitFloat64( 1.0 / ::sqrt( v ) ); } );
						break;
					case ast::expr::Intrinsic::eAbs1F:
					case ast::expr::Intrinsic::eAbs2F:
					case ast::expr::Intrinsic::eAbs3F:
					case ast::expr::Intrinsic::eAbs4F:
						result = intrinsic1T< LitFloat32 >( typesCache, exprCache, std::move( argsList ), []( LitFloat32 v ){ return std::abs( v ); } );
						break;
					case ast::expr::Intrinsic::eAbs1I:
					case ast::expr::Intrinsic::eAbs2I:
					case ast::expr::Intrinsic::eAbs3I:
					case ast::expr::Intrinsic::eAbs4I:
						result = intrinsic1T< LitInt32 >( typesCache, exprCache, std::move( argsList ), []( LitInt32 v ){ return std::abs( v ); } );
						break;
					case ast::expr::Intrinsic::eAbs1D:
					case ast::expr::Intrinsic::eAbs2D:
					case ast::expr::Intrinsic::eAbs3D:
					case ast::expr::Intrinsic::eAbs4D:
						result = intrinsic1T< LitFloat64 >( typesCache, exprCache, std::move( argsList ), []( LitFloat64 v ){ return std::abs( v ); } );
						break;
					case ast::expr::Intrinsic::eSign1F:
					case ast::expr::Intrinsic::eSign2F:
					case ast::expr::Intrinsic::eSign3F:
					case ast::expr::Intrinsic::eSign4F:
						result = intrinsic1T< LitFloat32 >( typesCache, exprCache, std::move( argsList ), []( LitFloat32 v ){ return LitFloat32( ( LitFloat32( 0.0f ) < v ) - ( v < LitFloat32( 0.0f ) ) ); } );
						break;
					case ast::expr::Intrinsic::eSign1I:
					case ast::expr::Intrinsic::eSign2I:
					case ast::expr::Intrinsic::eSign3I:
					case ast::expr::Intrinsic::eSign4I:
						result = intrinsic1T< LitInt32 >( typesCache, exprCache, std::move( argsList ), []( LitInt32 v ){ return ( LitInt32( 0 ) < v ) - ( v < LitInt32( 0 ) ); } );
						break;
					case ast::expr::Intrinsic::eSign1D:
					case ast::expr::Intrinsic::eSign2D:
					case ast::expr::Intrinsic::eSign3D:
					case ast::expr::Intrinsic::eSign4D:
						result = intrinsic1T< LitFloat64 >( typesCache, exprCache, std::move( argsList ), []( LitFloat64 v ){ return LitFloat64( ( LitFloat64( 0 ) < v ) - ( v < LitFloat64( 0 ) ) ); } );
						break;
					case ast::expr::Intrinsic::eFloor1F:
					case ast::expr::Intrinsic::eFloor2F:
					case ast::expr::Intrinsic::eFloor3F:
					case ast::expr::Intrinsic::eFloor4F:
						result = intrinsic1T< LitFloat32 >( typesCache, exprCache, std::move( argsList ), []( LitFloat32 v ){ return std::floor( v ); } );
						break;
					case ast::expr::Intrinsic::eFloor1D:
					case ast::expr::Intrinsic::eFloor2D:
					case ast::expr::Intrinsic::eFloor3D:
					case ast::expr::Intrinsic::eFloor4D:
						result = intrinsic1T< LitFloat64 >( typesCache, exprCache, std::move( argsList ), []( LitFloat64 v ){ return std::floor( v ); } );
						break;
					case ast::expr::Intrinsic::eTrunc1F:
					case ast::expr::Intrinsic::eTrunc2F:
					case ast::expr::Intrinsic::eTrunc3F:
					case ast::expr::Intrinsic::eTrunc4F:
						result = intrinsic1T< LitFloat32 >( typesCache, exprCache, std::move( argsList ), []( LitFloat32 v ){ return std::trunc( v ); } );
						break;
					case ast::expr::Intrinsic::eTrunc1D:
					case ast::expr::Intrinsic::eTrunc2D:
					case ast::expr::Intrinsic::eTrunc3D:
					case ast::expr::Intrinsic::eTrunc4D:
						result = intrinsic1T< LitFloat64 >( typesCache, exprCache, std::move( argsList ), []( LitFloat64 v ){ return std::trunc( v ); } );
						break;
					case ast::expr::Intrinsic::eRound1F:
					case ast::expr::Intrinsic::eRound2F:
					case ast::expr::Intrinsic::eRound3F:
					case ast::expr::Intrinsic::eRound4F:
						result = intrinsic1T< LitFloat32 >( typesCache, exprCache, std::move( argsList ), []( LitFloat32 v ){ return std::round( v ); } );
						break;
					case ast::expr::Intrinsic::eRound1D:
					case ast::expr::Intrinsic::eRound2D:
					case ast::expr::Intrinsic::eRound3D:
					case ast::expr::Intrinsic::eRound4D:
						result = intrinsic1T< LitFloat64 >( typesCache, exprCache, std::move( argsList ), []( LitFloat64 v ){ return std::round( v ); } );
						break;
					case ast::expr::Intrinsic::eRoundEven1F:
					case ast::expr::Intrinsic::eRoundEven2F:
					case ast::expr::Intrinsic::eRoundEven3F:
					case ast::expr::Intrinsic::eRoundEven4F:
						result = intrinsic1T< LitFloat32 >( typesCache, exprCache, std::move( argsList ), []( LitFloat32 v ){ return LitFloat32( int( v + LitFloat32( int( v ) % 2 ) ) ); } );
						break;
					case ast::expr::Intrinsic::eRoundEven1D:
					case ast::expr::Intrinsic::eRoundEven2D:
					case ast::expr::Intrinsic::eRoundEven3D:
					case ast::expr::Intrinsic::eRoundEven4D:
						result = intrinsic1T< LitFloat64 >( typesCache, exprCache, std::move( argsList ), []( LitFloat64 v ){ return LitFloat64( int( v + LitFloat64( int( v ) % 2 ) ) ); } );
						break;
					case ast::expr::Intrinsic::eCeil1F:
					case ast::expr::Intrinsic::eCeil2F:
					case ast::expr::Intrinsic::eCeil3F:
					case ast::expr::Intrinsic::eCeil4F:
						result = intrinsic1T< LitFloat32 >( typesCache, exprCache, std::move( argsList ), []( LitFloat32 v ){ return std::ceil( v ); } );
						break;
					case ast::expr::Intrinsic::eCeil1D:
					case ast::expr::Intrinsic::eCeil2D:
					case ast::expr::Intrinsic::eCeil3D:
					case ast::expr::Intrinsic::eCeil4D:
						result = intrinsic1T< LitFloat64 >( typesCache, exprCache, std::move( argsList ), []( LitFloat64 v ){ return std::ceil( v ); } );
						break;
					case ast::expr::Intrinsic::eFract1F:
					case ast::expr::Intrinsic::eFract2F:
					case ast::expr::Intrinsic::eFract3F:
					case ast::expr::Intrinsic::eFract4F:
						result = intrinsic1T< LitFloat32 >( typesCache, exprCache, std::move( argsList ), []( LitFloat32 v ){ return v - LitFloat32( int64_t( v ) ); } );
						break;
					case ast::expr::Intrinsic::eFract1D:
					case ast::expr::Intrinsic::eFract2D:
					case ast::expr::Intrinsic::eFract3D:
					case ast::expr::Intrinsic::eFract4D:
						result = intrinsic1T< LitFloat64 >( typesCache, exprCache, std::move( argsList ), []( LitFloat64 v ){ return v - LitFloat64( int64_t( v ) ); } );
						break;
					case ast::expr::Intrinsic::eMod1F:
					case ast::expr::Intrinsic::eMod2F:
					case ast::expr::Intrinsic::eMod3F:
					case ast::expr::Intrinsic::eMod4F:
						result = intrinsic2T< LitFloat32 >( typesCache, exprCache, std::move( argsList ), []( LitFloat32 v, LitFloat32 w ){ return v - w * std::floor( v / w ); } );
						break;
					case ast::expr::Intrinsic::eMod1D:
					case ast::expr::Intrinsic::eMod2D:
					case ast::expr::Intrinsic::eMod3D:
					case ast::expr::Intrinsic::eMod4D:
						result = intrinsic2T< LitFloat64 >( typesCache, exprCache, std::move( argsList ), []( LitFloat64 v, LitFloat64 w ){ return v - w * std::floor( v / w ); } );
						break;
					case ast::expr::Intrinsic::eMin1F:
					case ast::expr::Intrinsic::eMin2F:
					case ast::expr::Intrinsic::eMin3F:
					case ast::expr::Intrinsic::eMin4F:
						result = intrinsic2T< LitFloat32 >( typesCache, exprCache, std::move( argsList ), []( LitFloat32 v, LitFloat32 w ){ return std::min( v, w ); } );
						break;
					case ast::expr::Intrinsic::eMin1D:
					case ast::expr::Intrinsic::eMin2D:
					case ast::expr::Intrinsic::eMin3D:
					case ast::expr::Intrinsic::eMin4D:
						result = intrinsic2T< LitFloat64 >( typesCache, exprCache, std::move( argsList ), []( LitFloat64 v, LitFloat64 w ){ return std::min( v, w ); } );
						break;
					case ast::expr::Intrinsic::eMin1I:
					case ast::expr::Intrinsic::eMin2I:
					case ast::expr::Intrinsic::eMin3I:
					case ast::expr::Intrinsic::eMin4I:
						result = intrinsic2T< LitInt32 >( typesCache, exprCache, std::move( argsList ), []( LitInt32 v, LitInt32 w ){ return std::min( v, w ); } );
						break;
					case ast::expr::Intrinsic::eMin1U:
					case ast::expr::Intrinsic::eMin2U:
					case ast::expr::Intrinsic::eMin3U:
					case ast::expr::Intrinsic::eMin4U:
						result = intrinsic2T< LitUInt32 >( typesCache, exprCache, std::move( argsList ), []( LitUInt32 v, LitUInt32 w ){ return std::min( v, w ); } );
						break;
					case ast::expr::Intrinsic::eMax1F:
					case ast::expr::Intrinsic::eMax2F:
					case ast::expr::Intrinsic::eMax3F:
					case ast::expr::Intrinsic::eMax4F:
						result = intrinsic2T< LitFloat32 >( typesCache, exprCache, std::move( argsList ), []( LitFloat32 v, LitFloat32 w ){ return std::max( v, w ); } );
						break;
					case ast::expr::Intrinsic::eMax1D:
					case ast::expr::Intrinsic::eMax2D:
					case ast::expr::Intrinsic::eMax3D:
					case ast::expr::Intrinsic::eMax4D:
						result = intrinsic2T< LitFloat64 >( typesCache, exprCache, std::move( argsList ), []( LitFloat64 v, LitFloat64 w ){ return std::max( v, w ); } );
						break;
					case ast::expr::Intrinsic::eMax1I:
					case ast::expr::Intrinsic::eMax2I:
					case ast::expr::Intrinsic::eMax3I:
					case ast::expr::Intrinsic::eMax4I:
						result = intrinsic2T< LitInt32 >( typesCache, exprCache, std::move( argsList ), []( LitInt32 v, LitInt32 w ){ return std::max( v, w ); } );
						break;
					case ast::expr::Intrinsic::eMax1U:
					case ast::expr::Intrinsic::eMax2U:
					case ast::expr::Intrinsic::eMax3U:
					case ast::expr::Intrinsic::eMax4U:
						result = intrinsic2T< LitUInt32 >( typesCache, exprCache, std::move( argsList ), []( LitUInt32 v, LitUInt32 w ){ return std::max( v, w ); } );
						break;
					case ast::expr::Intrinsic::eClamp1F:
					case ast::expr::Intrinsic::eClamp2F:
					case ast::expr::Intrinsic::eClamp3F:
					case ast::expr::Intrinsic::eClamp4F:
						result = intrinsic3T< LitFloat32 >( typesCache, exprCache, std::move( argsList ), []( LitFloat32 v, LitFloat32 w, LitFloat32 x ){ return std::min( std::max( v, w ), x ); } );
						break;
					case ast::expr::Intrinsic::eClamp1D:
					case ast::expr::Intrinsic::eClamp2D:
					case ast::expr::Intrinsic::eClamp3D:
					case ast::expr::Intrinsic::eClamp4D:
						result = intrinsic3T< LitFloat64 >( typesCache, exprCache, std::move( argsList ), []( LitFloat64 v, LitFloat64 w, LitFloat64 x ){ return std::min( std::max( v, w ), x ); } );
						break;
					case ast::expr::Intrinsic::eClamp1I:
					case ast::expr::Intrinsic::eClamp2I:
					case ast::expr::Intrinsic::eClamp3I:
					case ast::expr::Intrinsic::eClamp4I:
						result = intrinsic3T< LitInt32 >( typesCache, exprCache, std::move( argsList ), []( LitInt32 v, LitInt32 w, LitInt32 x ){ return std::min( std::max( v, w ), x ); } );
						break;
					case ast::expr::Intrinsic::eClamp1U:
					case ast::expr::Intrinsic::eClamp2U:
					case ast::expr::Intrinsic::eClamp3U:
					case ast::expr::Intrinsic::eClamp4U:
						result = intrinsic3T< LitUInt32 >( typesCache, exprCache, std::move( argsList ), []( LitUInt32 v, LitUInt32 w, LitUInt32 x ){ return std::min( std::max( v, w ), x ); } );
						break;
					case ast::expr::Intrinsic::eMix1F:
					case ast::expr::Intrinsic::eMix2F:
					case ast::expr::Intrinsic::eMix3F:
					case ast::expr::Intrinsic::eMix4F:
						result = intrinsic3T< LitFloat32 >( typesCache, exprCache, std::move( argsList ), []( LitFloat32 v, LitFloat32 w, LitFloat32 x ){ return v * ( 1.0f - x ) + w * x; } );
						break;
					case ast::expr::Intrinsic::eMix1D:
					case ast::expr::Intrinsic::eMix2D:
					case ast::expr::Intrinsic::eMix3D:
					case ast::expr::Intrinsic::eMix4D:
						result = intrinsic3T< LitFloat64 >( typesCache, exprCache, std::move( argsList ), []( LitFloat64 v, LitFloat64 w, LitFloat64 x ){ return v * ( 1.0f - x ) + w * x; } );
						break;
					case ast::expr::Intrinsic::eStep1F:
					case ast::expr::Intrinsic::eStep2F:
					case ast::expr::Intrinsic::eStep3F:
					case ast::expr::Intrinsic::eStep4F:
						result = intrinsic2T< LitFloat32 >( typesCache, exprCache, std::move( argsList ), []( LitFloat32 v, LitFloat32 w ){ return w < v ? 0.0f : 1.0f; } );
						break;
					case ast::expr::Intrinsic::eStep1D:
					case ast::expr::Intrinsic::eStep2D:
					case ast::expr::Intrinsic::eStep3D:
					case ast::expr::Intrinsic::eStep4D:
						result = intrinsic2T< LitFloat64 >( typesCache, exprCache, std::move( argsList ), []( LitFloat64 v, LitFloat64 w ){ return w < v ? 0.0f : 1.0f; } );
						break;
					case ast::expr::Intrinsic::eSmoothStep1F:
					case ast::expr::Intrinsic::eSmoothStep2F:
					case ast::expr::Intrinsic::eSmoothStep3F:
					case ast::expr::Intrinsic::eSmoothStep4F:
						result = intrinsic3T< LitFloat32 >( typesCache, exprCache, std::move( argsList ), []( LitFloat32 v, LitFloat32 w, LitFloat32 x ){ auto t = std::min( std::max( ( x - v ) / ( w - v ) , 0.0f ), 1.0f ); return t * t * ( 3.0f - 2.0f * t ); } );
						break;
					case ast::expr::Intrinsic::eSmoothStep1D:
					case ast::expr::Intrinsic::eSmoothStep2D:
					case ast::expr::Intrinsic::eSmoothStep3D:
					case ast::expr::Intrinsic::eSmoothStep4D:
						result = intrinsic3T< LitFloat64 >( typesCache, exprCache, std::move( argsList ), []( LitFloat64 v, LitFloat64 w, LitFloat64 x ){ auto t = std::min( std::max( ( x - v ) / ( w - v ) , 0.0 ), 1.0 ); return t * t * ( 3.0 - 2.0 * t ); } );
						break;
					case ast::expr::Intrinsic::eIsnan1F:
					case ast::expr::Intrinsic::eIsnan2F:
					case ast::expr::Intrinsic::eIsnan3F:
					case ast::expr::Intrinsic::eIsnan4F:
						result = intrinsic1BoolT< LitFloat32 >( typesCache, exprCache, std::move( argsList ), []( LitFloat32 v ){ return std::isnan( v ); } );
						break;
					case ast::expr::Intrinsic::eIsnan1D:
					case ast::expr::Intrinsic::eIsnan2D:
					case ast::expr::Intrinsic::eIsnan3D:
					case ast::expr::Intrinsic::eIsnan4D:
						result = intrinsic1BoolT< LitFloat64 >( typesCache, exprCache, std::move( argsList ), []( LitFloat64 v ){ return std::isnan( v ); } );
						break;
					case ast::expr::Intrinsic::eIsinf1F:
					case ast::expr::Intrinsic::eIsinf2F:
					case ast::expr::Intrinsic::eIsinf3F:
					case ast::expr::Intrinsic::eIsinf4F:
						result = intrinsic1BoolT< LitFloat32 >( typesCache, exprCache, std::move( argsList ), []( LitFloat32 v ){ return std::isinf( v ); } );
						break;
					case ast::expr::Intrinsic::eIsinf1D:
					case ast::expr::Intrinsic::eIsinf2D:
					case ast::expr::Intrinsic::eIsinf3D:
					case ast::expr::Intrinsic::eIsinf4D:
						result = intrinsic1BoolT< LitFloat64 >( typesCache, exprCache, std::move( argsList ), []( LitFloat64 v ){ return std::isinf( v ); } );
						break;
					case ast::expr::Intrinsic::eFma1F:
					case ast::expr::Intrinsic::eFma2F:
					case ast::expr::Intrinsic::eFma3F:
					case ast::expr::Intrinsic::eFma4F:
						result = intrinsic3T< LitFloat32 >( typesCache, exprCache, std::move( argsList ), []( LitFloat32 v, LitFloat32 w, LitFloat32 x ){ return std::fma( v, w, x ); } );
						break;
					case ast::expr::Intrinsic::eFma1D:
					case ast::expr::Intrinsic::eFma2D:
					case ast::expr::Intrinsic::eFma3D:
					case ast::expr::Intrinsic::eFma4D:
						result = intrinsic3T< LitFloat64 >( typesCache, exprCache, std::move( argsList ), []( LitFloat64 v, LitFloat64 w, LitFloat64 x ){ return std::fma( v, w, x ); } );
						break;
					case ast::expr::Intrinsic::eLessThan2F:
					case ast::expr::Intrinsic::eLessThan3F:
					case ast::expr::Intrinsic::eLessThan4F:
						result = intrinsicCompT< LitFloat32 >( typesCache, exprCache, std::move( argsList ), []( LitFloat32 v, LitFloat32 w ){ return v < w; } );
						break;
					case ast::expr::Intrinsic::eLessThan2D:
					case ast::expr::Intrinsic::eLessThan3D:
					case ast::expr::Intrinsic::eLessThan4D:
						result = intrinsicCompT< LitFloat64 >( typesCache, exprCache, std::move( argsList ), []( LitFloat64 v, LitFloat64 w ){ return v < w; } );
						break;
					case ast::expr::Intrinsic::eLessThan2I:
					case ast::expr::Intrinsic::eLessThan3I:
					case ast::expr::Intrinsic::eLessThan4I:
						result = intrinsicCompT< LitInt32 >( typesCache, exprCache, std::move( argsList ), []( LitInt32 v, LitInt32 w ){ return v < w; } );
						break;
					case ast::expr::Intrinsic::eLessThan2U:
					case ast::expr::Intrinsic::eLessThan3U:
					case ast::expr::Intrinsic::eLessThan4U:
						result = intrinsicCompT< LitUInt32 >( typesCache, exprCache, std::move( argsList ), []( LitUInt32 v, LitUInt32 w ){ return v < w; } );
						break;
					case ast::expr::Intrinsic::eLessThanEqual2F:
					case ast::expr::Intrinsic::eLessThanEqual3F:
					case ast::expr::Intrinsic::eLessThanEqual4F:
						result = intrinsicCompT< LitFloat32 >( typesCache, exprCache, std::move( argsList ), []( LitFloat32 v, LitFloat32 w ){ return v <= w; } );
						break;
					case ast::expr::Intrinsic::eLessThanEqual2D:
					case ast::expr::Intrinsic::eLessThanEqual3D:
					case ast::expr::Intrinsic::eLessThanEqual4D:
						result = intrinsicCompT< LitFloat64 >( typesCache, exprCache, std::move( argsList ), []( LitFloat64 v, LitFloat64 w ){ return v <= w; } );
						break;
					case ast::expr::Intrinsic::eLessThanEqual2I:
					case ast::expr::Intrinsic::eLessThanEqual3I:
					case ast::expr::Intrinsic::eLessThanEqual4I:
						result = intrinsicCompT< LitInt32 >( typesCache, exprCache, std::move( argsList ), []( LitInt32 v, LitInt32 w ){ return v <= w; } );
						break;
					case ast::expr::Intrinsic::eLessThanEqual2U:
					case ast::expr::Intrinsic::eLessThanEqual3U:
					case ast::expr::Intrinsic::eLessThanEqual4U:
						result = intrinsicCompT< LitUInt32 >( typesCache, exprCache, std::move( argsList ), []( LitUInt32 v, LitUInt32 w ){ return v <= w; } );
						break;
					case ast::expr::Intrinsic::eGreaterThan2F:
					case ast::expr::Intrinsic::eGreaterThan3F:
					case ast::expr::Intrinsic::eGreaterThan4F:
						result = intrinsicCompT< LitFloat32 >( typesCache, exprCache, std::move( argsList ), []( LitFloat32 v, LitFloat32 w ){ return v > w; } );
						break;
					case ast::expr::Intrinsic::eGreaterThan2D:
					case ast::expr::Intrinsic::eGreaterThan3D:
					case ast::expr::Intrinsic::eGreaterThan4D:
						result = intrinsicCompT< LitFloat64 >( typesCache, exprCache, std::move( argsList ), []( LitFloat64 v, LitFloat64 w ){ return v > w; } );
						break;
					case ast::expr::Intrinsic::eGreaterThan2I:
					case ast::expr::Intrinsic::eGreaterThan3I:
					case ast::expr::Intrinsic::eGreaterThan4I:
						result = intrinsicCompT< LitInt32 >( typesCache, exprCache, std::move( argsList ), []( LitInt32 v, LitInt32 w ){ return v > w; } );
						break;
					case ast::expr::Intrinsic::eGreaterThan2U:
					case ast::expr::Intrinsic::eGreaterThan3U:
					case ast::expr::Intrinsic::eGreaterThan4U:
						result = intrinsicCompT< LitUInt32 >( typesCache, exprCache, std::move( argsList ), []( LitUInt32 v, LitUInt32 w ){ return v > w; } );
						break;
					case ast::expr::Intrinsic::eGreaterThanEqual2F:
					case ast::expr::Intrinsic::eGreaterThanEqual3F:
					case ast::expr::Intrinsic::eGreaterThanEqual4F:
						result = intrinsicCompT< LitFloat32 >( typesCache, exprCache, std::move( argsList ), []( LitFloat32 v, LitFloat32 w ){ return v >= w; } );
						break;
					case ast::expr::Intrinsic::eGreaterThanEqual2D:
					case ast::expr::Intrinsic::eGreaterThanEqual3D:
					case ast::expr::Intrinsic::eGreaterThanEqual4D:
						result = intrinsicCompT< LitFloat64 >( typesCache, exprCache, std::move( argsList ), []( LitFloat64 v, LitFloat64 w ){ return v >= w; } );
						break;
					case ast::expr::Intrinsic::eGreaterThanEqual2I:
					case ast::expr::Intrinsic::eGreaterThanEqual3I:
					case ast::expr::Intrinsic::eGreaterThanEqual4I:
						result = intrinsicCompT< LitInt32 >( typesCache, exprCache, std::move( argsList ), []( LitInt32 v, LitInt32 w ){ return v >= w; } );
						break;
					case ast::expr::Intrinsic::eGreaterThanEqual2U:
					case ast::expr::Intrinsic::eGreaterThanEqual3U:
					case ast::expr::Intrinsic::eGreaterThanEqual4U:
						result = intrinsicCompT< LitUInt32 >( typesCache, exprCache, std::move( argsList ), []( LitUInt32 v, LitUInt32 w ){ return v >= w; } );
						break;
					case ast::expr::Intrinsic::eEqual2F:
					case ast::expr::Intrinsic::eEqual3F:
					case ast::expr::Intrinsic::eEqual4F:
						result = intrinsicCompT< LitFloat32 >( typesCache, exprCache, std::move( argsList ), []( LitFloat32 v, LitFloat32 w ){ return v == w; } );
						break;
					case ast::expr::Intrinsic::eEqual2D:
					case ast::expr::Intrinsic::eEqual3D:
					case ast::expr::Intrinsic::eEqual4D:
						result = intrinsicCompT< LitFloat64 >( typesCache, exprCache, std::move( argsList ), []( LitFloat64 v, LitFloat64 w ){ return v == w; } );
						break;
					case ast::expr::Intrinsic::eEqual2I:
					case ast::expr::Intrinsic::eEqual3I:
					case ast::expr::Intrinsic::eEqual4I:
						result = intrinsicCompT< LitInt32 >( typesCache, exprCache, std::move( argsList ), []( LitInt32 v, LitInt32 w ){ return v == w; } );
						break;
					case ast::expr::Intrinsic::eEqual2U:
					case ast::expr::Intrinsic::eEqual3U:
					case ast::expr::Intrinsic::eEqual4U:
						result = intrinsicCompT< LitUInt32 >( typesCache, exprCache, std::move( argsList ), []( LitUInt32 v, LitUInt32 w ){ return v == w; } );
						break;
					case ast::expr::Intrinsic::eNotEqual2F:
					case ast::expr::Intrinsic::eNotEqual3F:
					case ast::expr::Intrinsic::eNotEqual4F:
						result = intrinsicCompT< LitFloat32 >( typesCache, exprCache, std::move( argsList ), []( LitFloat32 v, LitFloat32 w ){ return v != w; } );
						break;
					case ast::expr::Intrinsic::eNotEqual2D:
					case ast::expr::Intrinsic::eNotEqual3D:
					case ast::expr::Intrinsic::eNotEqual4D:
						result = intrinsicCompT< LitFloat64 >( typesCache, exprCache, std::move( argsList ), []( LitFloat64 v, LitFloat64 w ){ return v != w; } );
						break;
					case ast::expr::Intrinsic::eNotEqual2I:
					case ast::expr::Intrinsic::eNotEqual3I:
					case ast::expr::Intrinsic::eNotEqual4I:
						result = intrinsicCompT< LitInt32 >( typesCache, exprCache, std::move( argsList ), []( LitInt32 v, LitInt32 w ){ return v != w; } );
						break;
					case ast::expr::Intrinsic::eNotEqual2U:
					case ast::expr::Intrinsic::eNotEqual3U:
					case ast::expr::Intrinsic::eNotEqual4U:
						result = intrinsicCompT< LitUInt32 >( typesCache, exprCache, std::move( argsList ), []( LitUInt32 v, LitUInt32 w ){ return v != w; } );
						break;
					case ast::expr::Intrinsic::eAll2:
					case ast::expr::Intrinsic::eAll3:
					case ast::expr::Intrinsic::eAll4:
						result = intrinsicGatherT< LitBool >( typesCache, exprCache, std::move( argsList ), []( LitBool v, LitBool w ){ return v && w; } );
						break;
					case ast::expr::Intrinsic::eAny2:
					case ast::expr::Intrinsic::eAny3:
					case ast::expr::Intrinsic::eAny4:
						result = intrinsicGatherT< LitBool >( typesCache, exprCache, std::move( argsList ), []( LitBool v, LitBool w ){ return v || w; } );
						break;
					case ast::expr::Intrinsic::eNot2:
					case ast::expr::Intrinsic::eNot3:
					case ast::expr::Intrinsic::eNot4:
						result = intrinsic1T< LitBool >( typesCache, exprCache, std::move( argsList ), []( LitBool v ){ return !v; } );
						break;
					default:
						break;
					}
				}
				catch ( ast::Exception & )
				{
					// Nothing to do here
				}

				return result;
			}
		}

		struct ConstComposite
		{
			ConstComposite( ast::expr::CompositeType pcomposite
				, ast::type::Kind pcomponent
				, ast::expr::ExprList pinitialisers )
				: composite{ pcomposite }
				, component{ pcomponent }
				, initialisers{ std::move( pinitialisers ) }
			{
			}

			ast::expr::CompositeType composite;
			ast::type::Kind component;
			ast::expr::ExprList initialisers;
		};

		struct ConstantsContext
		{
			explicit ConstantsContext( ast::ShaderAllocatorBlock * alloc )
				: constExprs{ alloc }
				, constAggrExprs{ alloc }
				, constCompositeExprs{ alloc }
			{
			}

			Map< uint32_t, ast::expr::ExprPtr > constExprs;
			Map< uint32_t, ast::expr::ExprList > constAggrExprs;
			Map< uint32_t, ConstComposite > constCompositeExprs;
		};

		class ExprEvaluator
			: public ast::ExprCloner
		{
		public:
			static ast::expr::ExprPtr submit( ast::expr::ExprCache & exprCache
				, ast::expr::Expr const & expr
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
				, expr::Expr const & expr
				, ConstantsContext & context
				, bool & allLiterals
				, bool isLHS )
			{
				expr::ExprPtr result{};
				ExprEvaluator vis{ exprCache, context, allLiterals, isLHS, result };
				expr.accept( &vis );

				if ( expr.isNonUniform() )
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

			expr::ExprPtr doSubmit( expr::Expr const & expr
				, bool & allLiterals
				, bool isLHS = false )
			{
				return submit( m_exprCache, expr, m_context, allLiterals, isLHS );
			}

			expr::ExprPtr doComputeBinaryExpr( expr::Binary const & expr
				, expr::Literal const & lhsLiteral
				, expr::Literal const & rhsLiteral )
			{
				expr::ExprPtr result{};

				switch ( expr.getKind() )
				{
				case expr::Kind::eAdd:
					result = lhsLiteral + rhsLiteral;
					break;
				case expr::Kind::eBitAnd:
					result = lhsLiteral & rhsLiteral;
					break;
				case expr::Kind::eBitOr:
					result = lhsLiteral | rhsLiteral;
					break;
				case expr::Kind::eBitXor:
					result = lhsLiteral ^ rhsLiteral;
					break;
				case expr::Kind::eDivide:
					result = lhsLiteral / rhsLiteral;
					break;
				case expr::Kind::eLShift:
					result = lhsLiteral << rhsLiteral;
					break;
				case expr::Kind::eMinus:
					result = lhsLiteral - rhsLiteral;
					break;
				case expr::Kind::eModulo:
					result = lhsLiteral % rhsLiteral;
					break;
				case expr::Kind::eRShift:
					result = lhsLiteral >> rhsLiteral;
					break;
				case expr::Kind::eTimes:
					result = lhsLiteral * rhsLiteral;
					break;
				case expr::Kind::eLogAnd:
					result = lhsLiteral && rhsLiteral;
					break;
				case expr::Kind::eLogOr:
					result = lhsLiteral || rhsLiteral;
					break;
				case expr::Kind::eLess:
					result = lhsLiteral < rhsLiteral;
					break;
				case expr::Kind::eLessEqual:
					result = lhsLiteral <= rhsLiteral;
					break;
				case expr::Kind::eGreater:
					result = lhsLiteral > rhsLiteral;
					break;
				case expr::Kind::eGreaterEqual:
					result = lhsLiteral >= rhsLiteral;
					break;
				case expr::Kind::eEqual:
					result = lhsLiteral == rhsLiteral;
					break;
				case expr::Kind::eNotEqual:
					result = lhsLiteral != rhsLiteral;
					break;
				default:
					break;
				}

				AST_Assert( result && "Unexpected binary expression" );
				return result;
			}

			void doProcessLiteralBinaryExpr( expr::Binary const & expr
				, expr::Expr const & lhs
				, expr::Expr const & rhs )
			{
				if ( lhs.getKind() == expr::Kind::eAggrInit
					&& rhs.getKind() == expr::Kind::eAggrInit )
				{
					auto & lhsInit = static_cast< expr::AggrInit const & >( lhs );
					auto & rhsInit = static_cast< expr::AggrInit const & >( rhs );

					if ( lhsInit.getInitialisers().size() == rhsInit.getInitialisers().size() )
					{
						expr::ExprList initialisers;

						for ( size_t i = 0u; i < lhsInit.getInitialisers().size(); ++i )
						{
							initialisers.push_back( doComputeBinaryExpr( expr
								, static_cast< expr::Literal const & >( *lhsInit.getInitialisers()[i] )
								, static_cast< expr::Literal const & >( *rhsInit.getInitialisers()[i] ) ) );
						}

						m_result = m_exprCache.makeAggrInit( expr.getType()
							, std::move( initialisers ) );
					}
				}
				else if ( lhs.getKind() == expr::Kind::eCompositeConstruct
					&& rhs.getKind() == expr::Kind::eCompositeConstruct )
				{
					auto & lhsComposite = static_cast< expr::CompositeConstruct const & >( lhs );
					auto & rhsComposite = static_cast< expr::CompositeConstruct const & >( rhs );

					if ( lhsComposite.getArgList().size() == rhsComposite.getArgList().size() )
					{
						expr::ExprList initialisers;

						for ( size_t i = 0u; i < lhsComposite.getArgList().size(); ++i )
						{
							initialisers.push_back( doComputeBinaryExpr( expr
								, static_cast< expr::Literal const & >( *lhsComposite.getArgList()[i] )
								, static_cast< expr::Literal const & >( *rhsComposite.getArgList()[i] ) ) );
						}

						m_result = m_exprCache.makeCompositeConstruct( lhsComposite.getComposite()
							, getComponentType( expr.getType() )
							, std::move( initialisers ) );
					}
				}
				else if ( lhs.getKind() == expr::Kind::eLiteral
					&& rhs.getKind() == expr::Kind::eLiteral )
				{
					m_result = doComputeBinaryExpr( expr
						, static_cast< expr::Literal const & >( lhs )
						, static_cast< expr::Literal const & >( rhs ) );
				}
			}

			bool doProcessArrayAccessIdentifier( expr::ArrayAccess const & expr )
			{
				bool processed = false;
				auto & ident = static_cast< expr::Identifier const & >( *expr.getLHS() );
				auto aggrIt = m_context.constAggrExprs.find( ident.getVariable()->getId() );
				auto compIt = m_context.constCompositeExprs.find( ident.getVariable()->getId() );

				if ( aggrIt != m_context.constAggrExprs.end()
					&& expr.getRHS()->getKind() == expr::Kind::eLiteral )
				{
					auto & lit = static_cast< expr::Literal const & >( *expr.getRHS() );
					auto index = helpers::getLiteralIndex( lit );

					if ( index < aggrIt->second.size() )
					{
						processed = true;
						m_result = doSubmit( *aggrIt->second[index] );
					}
					else
					{
						AST_Exception( "Out of bounds array access to constant aggr init." );
					}
				}
				else if ( compIt != m_context.constCompositeExprs.end()
					&& expr.getRHS()->getKind() == expr::Kind::eLiteral )
				{
					auto & lit = static_cast< expr::Literal const & >( *expr.getRHS() );
					auto index = helpers::getLiteralIndex( lit );

					if ( index < compIt->second.initialisers.size() )
					{
						processed = true;
						m_result = doSubmit( *compIt->second.initialisers[index] );
					}
					else
					{
						AST_Exception( "Out of bounds array access to constant aggr init." );
					}
				}

				return processed;
			}

			void doProcessArrayAccessSwizzle( expr::ArrayAccess const & expr )
			{
				auto & lit = static_cast< expr::Literal const & >( *expr.getRHS() );
				auto index = helpers::getLiteralIndex( lit );
				auto & outer = static_cast< expr::Swizzle const & >( *expr.getLHS() );
				auto newOuter = doSubmit( outer.getOuterExpr() );
				m_result = doSubmit( *m_exprCache.makeSwizzle( std::move( newOuter )
					, outer.getSwizzle()[index] ) );
			}

			bool doProcessArrayAccessConstAggrInit( expr::ArrayAccess const & expr )
			{
				bool processed = false;
				auto & aggrInit = static_cast< expr::AggrInit const & >( *expr.getLHS() );

				if ( expr.getRHS()->getKind() == expr::Kind::eLiteral )
				{
					auto & lit = static_cast< expr::Literal const & >( *expr.getRHS() );
					auto index = helpers::getLiteralIndex( lit );

					if ( index < aggrInit.getInitialisers().size() )
					{
						processed = true;
						m_result = doSubmit( *aggrInit.getInitialisers()[index] );
					}
					else
					{
						AST_Exception( "Out of bounds array access to constant aggr init." );
					}
				}

				return processed;
			}

			using ast::ExprCloner::doSubmit;

			expr::ExprPtr doSubmit( expr::Expr const & expr )override
			{
				return doSubmit( expr, m_allLiterals, false );
			}

			bool doProcessSwizzleIdentifier( expr::Swizzle const & expr )
			{
				bool processed = false;
				auto variable = static_cast< expr::Identifier const & >( *expr.getOuterExpr() ).getVariable();
				auto aggrIt = m_context.constAggrExprs.find( variable->getId() );
				auto compIt = m_context.constCompositeExprs.find( variable->getId() );

				if ( aggrIt != m_context.constAggrExprs.end() )
				{
					processed = true;
					auto indices = getSwizzleIndices( expr.getSwizzle() );
					expr::ExprList initialisers;

					for ( auto index : indices )
					{
						initialisers.push_back( doSubmit( *aggrIt->second[index] ) );
					}

					if ( indices.size() > 1u )
					{
						auto scalarType = getScalarType( expr.getType()->getKind() );
						m_result = m_exprCache.makeCompositeConstruct( getCompositeType( expr.getType()->getKind() )
							, scalarType
							, std::move( initialisers ) );
					}
					else
					{
						m_result = std::move( initialisers.front() );
					}
				}
				else if ( compIt != m_context.constCompositeExprs.end() )
				{
					processed = true;
					auto indices = getSwizzleIndices( expr.getSwizzle() );
					expr::ExprList initialisers;

					for ( auto index : indices )
					{
						initialisers.push_back( doSubmit( *compIt->second.initialisers[index] ) );
					}

					if ( indices.size() > 1u )
					{
						auto scalarType = getScalarType( expr.getType()->getKind() );
						m_result = m_exprCache.makeCompositeConstruct( getCompositeType( expr.getType()->getKind() )
							, scalarType
							, std::move( initialisers ) );
					}
					else
					{
						m_result = std::move( initialisers.front() );
					}
				}

				return processed;
			}

			void doProcessLiteralSwizzle( expr::Swizzle const & expr
				, expr::Expr const & outer )
			{
				auto indices = getSwizzleIndices( expr.getSwizzle() );
				expr::ExprList initialisers;

				for ( auto index : indices )
				{
					initialisers.push_back( helpers::getNthValue( outer, index ) );
				}

				if ( indices.size() > 1u )
				{
					auto scalarType = getScalarType( expr.getType()->getKind() );
					m_result = m_exprCache.makeCompositeConstruct( getCompositeType( expr.getType()->getKind() )
						, scalarType
						, std::move( initialisers ) );
				}
				else
				{
					m_result = std::move( initialisers.front() );
				}
			}

			void visitUnaryExpr( expr::Unary const * expr )
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
					case expr::Kind::eStreamAppend:
						m_result = m_exprCache.makeStreamAppend( std::move( op ) );
						break;
					case expr::Kind::eUnaryMinus:
						m_result = -literal;
						break;
					default:
						AST_Failure( "Unexpected unary expression" );
#if !SDAST_ExceptAssert
						m_result = ExprCloner::submit( m_exprCache, expr );
#endif
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
					case expr::Kind::eStreamAppend:
						m_result = m_exprCache.makeStreamAppend( std::move( op ) );
						break;
					case expr::Kind::eUnaryMinus:
						m_result = m_exprCache.makeUnaryMinus( std::move( op ) );
						break;
					default:
						AST_Failure( "Unexpected unary expression" );
#if !SDAST_ExceptAssert
						m_result = ExprCloner::submit( m_exprCache, expr );
#endif
						break;
					}
				}
			}

			void visitBinaryExpr( expr::Binary const * expr )
			{
				TraceFunc;
				bool allLiterals = true;
				auto lhs = doSubmit( *expr->getLHS(), allLiterals );
				auto rhs = doSubmit( *expr->getRHS(), allLiterals );
				m_allLiterals = allLiterals && m_allLiterals;

				if ( allLiterals )
				{
					doProcessLiteralBinaryExpr( *expr, *lhs, *rhs );
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
#if !SDAST_ExceptAssert
						m_result = ExprCloner::submit( m_exprCache, expr );
#endif
						break;
					}
				}
			}

			void visitAddExpr( expr::Add const * expr )override
			{
				TraceFunc;
				visitBinaryExpr( expr );
			}

			// visitAggrInitExpr from ExprCloner

			void visitArrayAccessExpr( expr::ArrayAccess const * expr )override
			{
				TraceFunc;
				bool processed = false;

				if ( expr->getLHS()->getKind() == expr::Kind::eIdentifier )
				{
					processed = doProcessArrayAccessIdentifier( *expr );
				}

				if ( !processed
					&& expr->getLHS()->getKind() == expr::Kind::eSwizzle
					&& expr->getRHS()->getKind() == expr::Kind::eLiteral )
				{
					processed = true;
					doProcessArrayAccessSwizzle( *expr );
				}

				if ( !processed
					&& expr->getLHS()->isConstant()
					&& expr->getLHS()->getKind() == expr::Kind::eAggrInit )
				{
					processed = doProcessArrayAccessConstAggrInit( *expr );
				}

				if ( !processed )
				{
					m_allLiterals = false;
					ExprCloner::visitArrayAccessExpr( expr );
				}
			}

			void visitAssignExpr( ast::expr::Assign const * expr )override
			{
				TraceFunc;
				auto lhs = doSubmit( *expr->getLHS(), m_allLiterals, true );
				auto rhs = doSubmit( *expr->getRHS() );

				if ( rhs && lhs )
				{
					m_result = m_exprCache.makeAssign( expr->getType()
						, std::move( lhs )
						, std::move( rhs ) );
				}
			}

			void visitBitAndExpr( expr::BitAnd const * expr )override
			{
				TraceFunc;
				visitBinaryExpr( expr );
			}

			void visitBitNotExpr( expr::BitNot const * expr )override
			{
				TraceFunc;
				visitUnaryExpr( expr );
			}

			void visitBitOrExpr( expr::BitOr const * expr )override
			{
				TraceFunc;
				visitBinaryExpr( expr );
			}

			void visitBitXorExpr( expr::BitXor const * expr )override
			{
				TraceFunc;
				visitBinaryExpr( expr );
			}

			void visitCastExpr( expr::Cast const * expr )override
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

			void visitCombinedImageAccessCallExpr( expr::CombinedImageAccessCall const * expr )override
			{
				TraceFunc;
				m_allLiterals = false;
				ExprCloner::visitCombinedImageAccessCallExpr( expr );
			}

			void visitCopyExpr( expr::Copy const * expr )override
			{
				TraceFunc;
				visitUnaryExpr( expr );
			}

			void visitDivideExpr( expr::Divide const * expr )override
			{
				TraceFunc;
				visitBinaryExpr( expr );
			}

			void visitEqualExpr( expr::Equal const * expr )override
			{
				TraceFunc;
				visitBinaryExpr( expr );
			}

			void visitFnCallExpr( expr::FnCall const * expr )override
			{
				TraceFunc;
				m_allLiterals = false;
				ExprCloner::visitFnCallExpr( expr );
			}

			void visitGreaterExpr( expr::Greater const * expr )override
			{
				TraceFunc;
				visitBinaryExpr( expr );
			}

			void visitGreaterEqualExpr( expr::GreaterEqual const * expr )override
			{
				TraceFunc;
				visitBinaryExpr( expr );
			}

			void visitIdentifierExpr( ast::expr::Identifier const * expr )override
			{
				TraceFunc;
				auto var = expr->getVariable();
				auto initIt = m_context.constExprs.find( var->getId() );
				auto aggrIt = m_context.constAggrExprs.find( var->getId() );
				auto compIt = m_context.constCompositeExprs.find( var->getId() );

				if ( !m_isLHS )
				{
					if ( initIt != m_context.constExprs.end() )
					{
						m_result = doSubmit( *initIt->second );
					}
					else if ( aggrIt != m_context.constAggrExprs.end() )
					{
						expr::ExprList initialisers;

						for ( auto const & init : aggrIt->second )
						{
							initialisers.push_back( doSubmit( *init ) );
						}

						m_result = m_exprCache.makeAggrInit( expr->getType(), std::move( initialisers ) );
					}
					else if ( compIt != m_context.constCompositeExprs.end() )
					{
						expr::ExprList initialisers;

						for ( auto const & init : compIt->second.initialisers )
						{
							initialisers.push_back( doSubmit( *init ) );
						}

						m_result = m_exprCache.makeCompositeConstruct( compIt->second.composite
							, compIt->second.component
							, std::move( initialisers ) );
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

					if ( compIt != m_context.constCompositeExprs.end() )
					{
						m_context.constCompositeExprs.erase( compIt );
					}

					m_allLiterals = false;
					ExprCloner::visitIdentifierExpr( expr );
				}
			}

			void visitImageAccessCallExpr( expr::StorageImageAccessCall const * expr )override
			{
				TraceFunc;
				m_allLiterals = false;
				ExprCloner::visitImageAccessCallExpr( expr );
			}

			void visitInitExpr( expr::Init const * expr )override
			{
				AST_Failure( "Unexpected Init expression" );
			}

			void visitIntrinsicCallExpr( expr::IntrinsicCall const * expr )override
			{
				TraceFunc;

				if ( helpers::isConstantResolvable( expr->getIntrinsic() ) )
				{
					bool allLiterals = true;
					expr::ExprList args;

					for ( auto & arg : expr->getArgList() )
					{
						args.push_back( doSubmit( *arg, allLiterals ) );
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

			void visitLessExpr( expr::Less const * expr )override
			{
				TraceFunc;
				visitBinaryExpr( expr );
			}

			void visitLessEqualExpr( expr::LessEqual const * expr )override
			{
				TraceFunc;
				visitBinaryExpr( expr );
			}

			void visitLogAndExpr( expr::LogAnd const * expr )override
			{
				TraceFunc;
				visitBinaryExpr( expr );
			}

			void visitLogNotExpr( expr::LogNot const * expr )override
			{
				TraceFunc;
				visitUnaryExpr( expr );
			}

			void visitLogOrExpr( expr::LogOr const * expr )override
			{
				TraceFunc;
				visitBinaryExpr( expr );
			}

			void visitLShiftExpr( expr::LShift const * expr )override
			{
				TraceFunc;
				visitBinaryExpr( expr );
			}

			void visitMbrSelectExpr( expr::MbrSelect const * expr )override
			{
				TraceFunc;
				bool processed = false;

				if ( expr->getOuterExpr()->getKind() == expr::Kind::eIdentifier )
				{
					auto & ident = static_cast< expr::Identifier const & >( *expr->getOuterExpr() );
					auto aggrIt = m_context.constAggrExprs.find( ident.getVariable()->getId() );
					auto compIt = m_context.constCompositeExprs.find( ident.getVariable()->getId() );

					if ( aggrIt != m_context.constAggrExprs.end() )
					{
						if ( expr->getMemberIndex() < aggrIt->second.size() )
						{
							processed = true;
							m_result = doSubmit( *aggrIt->second[expr->getMemberIndex()] );
						}
						else
						{
							AST_Failure( "Out of bounds array access to constant aggr init." );
						}
					}
					else if ( compIt != m_context.constCompositeExprs.end() )
					{
						if ( expr->getMemberIndex() < compIt->second.initialisers.size() )
						{
							processed = true;
							m_result = doSubmit( *compIt->second.initialisers[expr->getMemberIndex()] );
						}
						else
						{
							AST_Failure( "Out of bounds array access to constant aggr init." );
						}
					}
				}

				if ( !processed )
				{
					auto outer = doSubmit( expr->getOuterExpr() );

					if ( outer->getKind() == expr::Kind::eAggrInit )
					{
						auto & aggrInit = static_cast< expr::AggrInit const & >( *outer );
						m_result = doSubmit( *aggrInit.getInitialisers()[expr->getMemberIndex()] );
					}
					else
					{
						m_allLiterals = false;
						m_result = m_exprCache.makeMbrSelect( std::move( outer )
							, expr->getMemberIndex()
							, expr->getMemberFlags() );
					}
				}
			}

			void visitMinusExpr( expr::Minus const * expr )override
			{
				TraceFunc;
				visitBinaryExpr( expr );
			}

			void visitModuloExpr( expr::Modulo const * expr )override
			{
				TraceFunc;
				visitBinaryExpr( expr );
			}

			void visitNotEqualExpr( expr::NotEqual const * expr )override
			{
				TraceFunc;
				visitBinaryExpr( expr );
			}

			void visitRShiftExpr( expr::RShift const * expr )override
			{
				TraceFunc;
				visitBinaryExpr( expr );
			}

			void visitQuestionExpr( expr::Question const * expr )override
			{
				TraceFunc;
				auto condComponents = getComponentCount( expr->getCtrlExpr()->getType()->getKind() );
				// Components counts should be identical, after simplification pass.
				AST_Assert( condComponents == getComponentCount( expr->getTrueExpr()->getType()->getKind() ) );
				bool allLiterals{ true };
				auto ctrlExpr = doSubmit( *expr->getCtrlExpr(), allLiterals );
				m_allLiterals = allLiterals && m_allLiterals;
				bool processed = false;

				if ( allLiterals )
				{
					processed = true;

					if ( condComponents == 1u )
					{
						AST_Assert( ctrlExpr->getKind() == expr::Kind::eLiteral );
						m_result = static_cast< expr::Literal const & >( *ctrlExpr ).getValue< expr::LiteralType::eBool >()
							? doSubmit( *expr->getTrueExpr() )
							: doSubmit( *expr->getFalseExpr() );
					}
					else
					{
						expr::ExprList initialisers;
						auto trueExpr = doSubmit( expr->getTrueExpr() );
						auto falseExpr = doSubmit( expr->getFalseExpr() );

						for ( auto i = 0u; i < condComponents; ++i )
						{
							auto ctrlValue = doSubmit( *m_exprCache.makeSwizzle( ctrlExpr->clone()
								, expr::SwizzleKind::fromOffset( i ) ) );
							AST_Assert( ctrlValue->getKind() == expr::Kind::eLiteral );
							auto resultValue = static_cast< expr::Literal const & >( *ctrlValue ).getValue< expr::LiteralType::eBool >()
								? trueExpr->clone()
								: falseExpr->clone();
							initialisers.push_back( doSubmit( *m_exprCache.makeSwizzle( std::move( resultValue )
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

			void visitSwizzleExpr( expr::Swizzle const * expr )override
			{
				TraceFunc;
				bool processed = false;

				if ( expr->getOuterExpr()->getKind() == expr::Kind::eIdentifier )
				{
					processed = doProcessSwizzleIdentifier( *expr );
				}

				if ( !processed )
				{
					bool allLiterals = true;
					auto outer = doSubmit( *expr->getOuterExpr(), allLiterals );
					m_allLiterals = m_allLiterals && allLiterals;

					if ( allLiterals )
					{
						processed = true;
						doProcessLiteralSwizzle( *expr, *outer );
					}
				}

				if ( !processed )
				{
					m_allLiterals = false;
					ExprCloner::visitSwizzleExpr( expr );
				}
			}

			void visitStreamAppendExpr( expr::StreamAppend const * expr )override
			{
				TraceFunc;
				visitUnaryExpr( expr );
			}

			void visitTimesExpr( expr::Times const * expr )override
			{
				TraceFunc;
				visitBinaryExpr( expr );
			}

			void visitUnaryMinusExpr( expr::UnaryMinus const * expr )override
			{
				TraceFunc;
				visitUnaryExpr( expr );
			}

			void visitUnaryPlusExpr( expr::UnaryPlus const * expr )override
			{
				TraceFunc;
				m_result = doSubmit( expr->getOperand() );
			}

			void visitAddAssignExpr( ast::expr::AddAssign const * expr )override
			{
				AST_Failure( "Unexpected AddAssign expression" );
			}

			void visitAndAssignExpr( ast::expr::AndAssign const * expr )override
			{
				AST_Failure( "Unexpected AndAssign expression" );
			}

			void visitDivideAssignExpr( ast::expr::DivideAssign const * expr )override
			{
				AST_Failure( "Unexpected DivideAssign expression" );
			}

			void visitLShiftAssignExpr( ast::expr::LShiftAssign const * expr )override
			{
				AST_Failure( "Unexpected LShiftAssign expression" );
			}

			void visitMinusAssignExpr( ast::expr::MinusAssign const * expr )override
			{
				AST_Failure( "Unexpected MinusAssign expression" );
			}

			void visitModuloAssignExpr( ast::expr::ModuloAssign const * expr )override
			{
				AST_Failure( "Unexpected ModuloAssign expression" );
			}

			void visitOrAssignExpr( ast::expr::OrAssign const * expr )override
			{
				AST_Failure( "Unexpected OrAssign expression" );
			}

			void visitRShiftAssignExpr( ast::expr::RShiftAssign const * expr )override
			{
				AST_Failure( "Unexpected RShiftAssign expression" );
			}

			void visitTimesAssignExpr( ast::expr::TimesAssign const * expr )override
			{
				AST_Failure( "Unexpected TimesAssign expression" );
			}

			void visitXorAssignExpr( ast::expr::XorAssign const * expr )override
			{
				AST_Failure( "Unexpected XorAssign expression" );
			}

			void visitPostDecrementExpr(expr::PostDecrement const * expr )override
			{
				AST_Failure( "Unexpected PostDecrement expression" );
			}

			void visitPostIncrementExpr(expr::PostIncrement const * expr )override
			{
				AST_Failure( "Unexpected PostIncrement expression" );
			}

			void visitPreDecrementExpr(expr::PreDecrement const * expr )override
			{
				AST_Failure( "Unexpected PreDecrement expression" );
			}

			void visitPreIncrementExpr(expr::PreIncrement const * expr )override
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
				, stmt::Container const & stmt
				, ConstantsContext & context )
			{
				std::vector< stmt::Container * > contStack;
				auto result = stmtCache.makeContainer();
				StmtEvaluator vis{ stmtCache, exprCache, typesCache, context, contStack, result };
				stmt.accept( &vis );
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

			expr::ExprPtr doSubmit( expr::Expr const & expr )override
			{
				bool allLiterals{ true };
				return doSubmit( expr, allLiterals );
			}

			expr::ExprPtr doSubmit( expr::Expr const & expr, bool & allLiterals )
			{
				return ExprEvaluator::submit( m_exprCache, expr, m_context, allLiterals, false );
			}

			void processIfStmt( stmt::Container const * stmt
				, ast::expr::ExprPtr ctrlExpr
				, bool & first
				, bool const & stopped
				, uint32_t & ifs )
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

			void processElseStmt( stmt::Container const * stmt
				, bool & first
				, bool const & stopped )
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
			void visitContainerStmt( stmt::Container const * cont )override
			{
				TraceFunc;
				m_containers.push_back( cont );

				for ( auto & stmt : *cont )
				{
					stmt->accept( this );
				}

				m_containers.pop_back();
			}

			void visitIfStmt( stmt::If const * stmt )override
			{
				TraceFunc;
				auto ctrlExpr = doSubmit( stmt->getCtrlExpr() );
				bool first = true;
				bool stopped = false;
				uint32_t ifs{};

				if ( ctrlExpr->getKind() == ast::expr::Kind::eLiteral )
				{
					if ( auto & ctrlValue = static_cast< ast::expr::Literal const & >( *ctrlExpr );
						ctrlValue.getValue< ast::expr::LiteralType::eBool >() )
					{
						visitContainerStmt( stmt );
					}
					else if ( stmt->getElse() )
					{
						visitContainerStmt( stmt->getElse() );
					}
				}
				else
				{
					processIfStmt( stmt, std::move( ctrlExpr ), first, stopped, ifs );

					if ( stmt->getElse() )
					{
						processElseStmt( stmt->getElse(), first, stopped );
					}

					while ( ifs-- )
					{
						m_ifStmts.pop_back();
					}
				}
			}

			expr::Identifier const * doRetrieveInitIdentifier( expr::Expr const & expr )const
			{
				if ( expr.getKind() == ast::expr::Kind::eAlias )
				{
					return ( static_cast< expr::Alias const & >( expr ).hasIdentifier()
						? &static_cast< expr::Alias const & >( expr ).getIdentifier()
						: nullptr );
				}

				if ( expr.getKind() == ast::expr::Kind::eInit )
				{
					return ( static_cast< expr::Init const & >( expr ).hasIdentifier()
						? &static_cast< expr::Init const & >( expr ).getIdentifier()
						: nullptr );
				}

				if ( expr.getKind() == ast::expr::Kind::eAggrInit )
				{
					return ( static_cast< expr::AggrInit const & >( expr ).hasIdentifier()
						? &static_cast< expr::AggrInit const & >( expr ).getIdentifier()
						: nullptr );
				}

				return nullptr;
			}

			void doProcessCompositeCtor( expr::Identifier const & ident
				, expr::CompositeConstruct const & compositeCtor
				, bool isAlias )
			{
				ast::expr::ExprList initialisers;
				bool allLiterals = true;

				for ( auto & arg : compositeCtor.getArgList() )
				{
					initialisers.emplace_back( doSubmit( *arg, allLiterals ) );
				}

				if ( !helpers::needsVariableDecl( ident.getVariable(), *m_containers.back() ) )
				{
					if ( allLiterals )
					{
						m_context.constCompositeExprs.try_emplace( ident.getVariable()->getId()
							, compositeCtor.getComposite()
							, compositeCtor.getComponent()
							, std::move( initialisers ) );
					}
					else
					{
						auto initialiser = m_exprCache.makeCompositeConstruct( compositeCtor.getComposite()
							, compositeCtor.getComponent()
							, std::move( initialisers ) );

						if ( isAlias )
						{
							m_current->addStmt( m_stmtCache.makeSimple( m_exprCache.makeAlias( ident.getType()
								, m_exprCache.makeIdentifier( ident )
								, std::move( initialiser ) ) ) );
						}
						else
						{
							m_current->addStmt( m_stmtCache.makeSimple( m_exprCache.makeInit( m_exprCache.makeIdentifier( ident )
								, std::move( initialiser ) ) ) );
						}
					}
				}
				else
				{
					auto initialiser = m_exprCache.makeCompositeConstruct( compositeCtor.getComposite()
						, compositeCtor.getComponent()
						, std::move( initialisers ) );

					if ( isAlias )
					{
						m_current->addStmt( m_stmtCache.makeSimple( m_exprCache.makeAlias( ident.getType()
							, m_exprCache.makeIdentifier( ident )
							, std::move( initialiser ) ) ) );
					}
					else
					{
						m_current->addStmt( m_stmtCache.makeSimple( m_exprCache.makeInit( m_exprCache.makeIdentifier( ident )
							, std::move( initialiser ) ) ) );
					}
				}
			}

			void doProcessAggrInit( expr::Identifier const & ident
				, expr::AggrInit const & aggrInit )
			{
				bool allLiterals = true;
				ast::expr::ExprList initialisers;

				for ( auto & initialiser : aggrInit.getInitialisers() )
				{
					initialisers.emplace_back( doSubmit( *initialiser, allLiterals ) );
				}

				if ( allLiterals
					&& !helpers::needsVariableDecl( ident.getVariable(), *m_containers.back() ) )
				{
					m_context.constAggrExprs.try_emplace( ident.getVariable()->getId()
						, std::move( initialisers ) );
				}
				else
				{
					m_current->addStmt( m_stmtCache.makeSimple( m_exprCache.makeAggrInit( m_exprCache.makeIdentifier( ident )
						, std::move( initialisers ) ) ) );
				}
			}

			void visitSimpleStmt( ast::stmt::Simple const * stmt )override
			{
				TraceFunc;
				bool processed = false;
				expr::Expr const * expr{ stmt->getExpr() };

				if ( auto ident = doRetrieveInitIdentifier( *expr ) )
				{
					bool isAlias = false;
					expr::Expr const * init{};

					if ( expr->getKind() == ast::expr::Kind::eAlias )
					{
						isAlias = true;
						init = static_cast< expr::Alias const & >( *expr ).getAliasedExpr();
					}
					else if ( expr->getKind() == ast::expr::Kind::eInit )
					{
						init = static_cast< ast::expr::Init const & >( *expr ).getInitialiser();
					}

					if ( init )
					{
						if ( init->getKind() == ast::expr::Kind::eCompositeConstruct )
						{
							processed = true;
							doProcessCompositeCtor( *ident
								, static_cast< ast::expr::CompositeConstruct const & >( *init )
								, isAlias );
						}
						else
						{
							processed = true;
							bool allLiterals = true;
							auto initialiser = doSubmit( *init, allLiterals );

							if ( allLiterals
								&& !helpers::needsVariableDecl( ident->getVariable(), *m_containers.back() ) )
							{
								m_context.constExprs.emplace( ident->getVariable()->getId()
									, std::move( initialiser ) );
							}
							else if ( isAlias )
							{
								m_current->addStmt( m_stmtCache.makeSimple( m_exprCache.makeAlias( ident->getType()
									, m_exprCache.makeIdentifier( *ident )
									, std::move( initialiser ) ) ) );
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
						processed = true;
						doProcessAggrInit( *ident
							, static_cast< ast::expr::AggrInit const & >( *expr ) );
					}
				}

				if ( !processed )
				{
					StmtCloner::visitSimpleStmt( stmt );
				}
			}

			void visitSwitchStmt( ast::stmt::Switch const * stmt )override
			{
				TraceFunc;
				bool processed = false;
				auto testExpr = doSubmit( stmt->getTestExpr() );

				if ( auto testValueExpr = static_cast< expr::SwitchTest const & >( *testExpr ).getValue();
					testValueExpr->getKind() == ast::expr::Kind::eLiteral )
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
			std::vector< stmt::Container const * > m_containers{};
			ConstantsContext & m_context;
		};

		bool isAllLiterals( expr::Expr const & expr )
		{
			bool allLiterals = true;
			auto & exprCache = expr.getExprCache();
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
		, stmt::Container const & stmt )
	{
		constants::ConstantsContext context{ &stmtCache.getAllocator() };
		return constants::StmtEvaluator::submit( stmtCache, exprCache, typesCache, stmt, context );
	}

	expr::ExprPtr resolveConstants( expr::ExprCache & exprCache
		, expr::Expr const & expr )
	{
		constants::ConstantsContext context{ &exprCache.getAllocator() };
		return constants::ExprEvaluator::submit( exprCache, expr, context, false );
	}
}
