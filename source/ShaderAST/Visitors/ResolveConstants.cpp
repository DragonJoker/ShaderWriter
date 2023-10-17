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
						visitExprIdentifiers( expr->getLHS() );
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
					case expr::Kind::eUnaryMinus:
						m_result = -literal;
						break;
					case expr::Kind::eUnaryPlus:
					case expr::Kind::ePostDecrement:
					case expr::Kind::ePostIncrement:
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
					case expr::Kind::ePreDecrement:
						m_result = preDec( literal );
						break;
					case expr::Kind::ePreIncrement:
						m_result = preInc( literal );
						break;
					default:
						AST_Failure( "Unexpected unary expression" );
						m_result = ExprCloner::submit( m_exprCache, expr );
						break;
					}
				}
				else
				{
					m_allLiterals = false;
					m_result = ExprCloner::submit( m_exprCache, expr );
				}
			}

			void visitBinaryExpr( expr::Binary * expr )
			{
				TraceFunc;
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

			void visitIntrinsicCallExpr( expr::IntrinsicCall* expr )override
			{
				TraceFunc;
				m_allLiterals = false;
				ExprCloner::visitIntrinsicCallExpr( expr );
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
				TraceFunc;;
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
