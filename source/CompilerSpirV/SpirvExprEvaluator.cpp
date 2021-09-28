/*
See LICENSE file in root folder
*/
#include "SpirvExprEvaluator.hpp"

#include <ShaderAST/Expr/ExprVisitor.hpp>

#include <sstream>

namespace spirv
{
	namespace
	{
		class ExprEvaluator
			: public ast::expr::SimpleVisitor
		{
		public:
			static ast::expr::LiteralPtr submit( ast::expr::Expr * expr
				, PreprocContext const & context )
			{
				ast::expr::LiteralPtr result;
				ExprEvaluator vis{ result, context };
				expr->accept( &vis );
				return result;
			}

		private:
			ExprEvaluator( ast::expr::LiteralPtr & result
				, PreprocContext const & context )
				: m_result{ result }
				, m_context{ context }
			{
			}

			void visitUnaryExpr( ast::expr::Unary * expr )override
			{
				auto operand = submit( expr->getOperand(), m_context );

				switch ( expr->getKind() )
				{
				case ast::expr::Kind::eBitNot:
					m_result = ~( *operand );
					break;
				case ast::expr::Kind::eLogNot:
					m_result = !( *operand );
					break;
				case ast::expr::Kind::eUnaryMinus:
					m_result = -( *operand );
					break;
				default:
					break;
				}
			}

			void visitBinaryExpr( ast::expr::Binary * expr )override
			{
				auto lhs = submit( expr->getLHS(), m_context );
				auto rhs = submit( expr->getRHS(), m_context );

				switch ( expr->getKind() )
				{
				case ast::expr::Kind::eAdd:
					m_result = *lhs + *rhs;
					break;
				case ast::expr::Kind::eMinus:
					m_result = *lhs - *rhs;
					break;
				case ast::expr::Kind::eTimes:
					m_result = *lhs * *rhs;
					break;
				case ast::expr::Kind::eDivide:
					m_result = *lhs / *rhs;
					break;
				case ast::expr::Kind::eModulo:
					m_result = *lhs % *rhs;
					break;
				case ast::expr::Kind::eLShift:
					m_result = *lhs << *rhs;
					break;
				case ast::expr::Kind::eRShift:
					m_result = *lhs >> *rhs;
					break;
				case ast::expr::Kind::eBitAnd:
					m_result = *lhs & *rhs;
					break;
				case ast::expr::Kind::eBitOr:
					m_result = *lhs | *rhs;
					break;
				case ast::expr::Kind::eBitXor:
					m_result = *lhs ^ *rhs;
					break;
				case ast::expr::Kind::eLogAnd:
					m_result = *lhs && *rhs;
					break;
				case ast::expr::Kind::eLogOr:
					m_result = *lhs || *rhs;
					break;
				case ast::expr::Kind::eEqual:
					m_result = *lhs == *rhs;
					break;
				case ast::expr::Kind::eGreater:
					m_result = *lhs > *rhs;
					break;
				case ast::expr::Kind::eGreaterEqual:
					m_result = *lhs >= *rhs;
					break;
				case ast::expr::Kind::eLess:
					m_result = *lhs < *rhs;
					break;
				case ast::expr::Kind::eLessEqual:
					m_result = *lhs <= *rhs;
					break;
				case ast::expr::Kind::eNotEqual:
					m_result = *lhs != *rhs;
					break;
				default:
					break;
				}
			}

			void visitIdentifierExpr( ast::expr::Identifier * expr )override
			{
				auto it = m_context.constExprs.find( expr->getVariable()->getName() );
				assert( it != m_context.constExprs.end() );
				assert( it->second->getKind() == ast::expr::Kind::eLiteral );
				m_result = std::unique_ptr< ast::expr::Literal >( new ast::expr::Literal{ static_cast< ast::expr::Literal const & >( *it->second ) } );
			}

			void visitLiteralExpr( ast::expr::Literal * expr )override
			{
				m_result = std::unique_ptr< ast::expr::Literal >( new ast::expr::Literal{ *expr } );
			}

			void visitPreDecrementExpr( ast::expr::PreDecrement * expr )override
			{
				AST_Failure( "Unexpected PreDecrement expression" );
			}

			void visitPreIncrementExpr( ast::expr::PreIncrement * expr )override
			{
				AST_Failure( "Unexpected PreIncrement expression" );
			}

			void visitPostDecrementExpr( ast::expr::PostDecrement * expr )override
			{
				AST_Failure( "Unexpected PostDecrement expression" );
			}

			void visitPostIncrementExpr( ast::expr::PostIncrement * expr )override
			{
				AST_Failure( "Unexpected PostIncrement expression" );
			}

			void visitUnaryPlusExpr( ast::expr::UnaryPlus * expr )override
			{
				AST_Failure( "Unexpected UnaryPlus expression" );
			}

			void visitAddAssignExpr( ast::expr::AddAssign * expr )override
			{
				AST_Failure( "Unexpected AddAssign expression" );
			}

			void visitAndAssignExpr( ast::expr::AndAssign * expr )override
			{
				AST_Failure( "Unexpected AndAssign expression" );
			}

			void visitArrayAccessExpr( ast::expr::ArrayAccess * expr )override
			{
				AST_Failure( "Unexpected ArrayAccess expression" );
			}

			void visitAssignExpr( ast::expr::Assign * expr )override
			{
				AST_Failure( "Unexpected Assign expression" );
			}

			void visitCastExpr( ast::expr::Cast * expr )override
			{
				AST_Failure( "Unexpected Cast expression" );
			}

			void visitCommaExpr( ast::expr::Comma * expr )override
			{
				AST_Failure( "Unexpected Comma expression" );
			}

			void visitCompositeConstructExpr( ast::expr::CompositeConstruct * expr )override
			{
				AST_Failure( "Unexpected CompositeConstruct expression" );
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

			void visitAggrInitExpr( ast::expr::AggrInit * expr )override
			{
				AST_Failure( "Unexpected AggrInit expression" );
			}

			void visitMbrSelectExpr( ast::expr::MbrSelect * expr )override
			{
				AST_Failure( "Unexpected MbrSelect expression" );
			}

			void visitFnCallExpr( ast::expr::FnCall * expr )override
			{
				AST_Failure( "Unexpected FnCall expression" );
			}

			void visitImageAccessCallExpr( ast::expr::ImageAccessCall * expr )override
			{
				AST_Failure( "Unexpected ImageAccessCall expression" );
			}

			void visitInitExpr( ast::expr::Init * expr )override
			{
				AST_Failure( "Unexpected Init expression" );
			}

			void visitIntrinsicCallExpr( ast::expr::IntrinsicCall * expr )override
			{
				AST_Failure( "Unexpected IntrinsicCall expression" );
			}

			void visitQuestionExpr( ast::expr::Question * expr )override
			{
				AST_Failure( "Unexpected Question expression" );
			}

			void visitSwitchCaseExpr( ast::expr::SwitchCase * expr )override
			{
				AST_Failure( "Unexpected SwitchCase expression" );
			}

			void visitSwitchTestExpr( ast::expr::SwitchTest * expr )override
			{
				AST_Failure( "Unexpected SwitchTest expression" );
			}

			void visitSwizzleExpr( ast::expr::Swizzle * expr )override
			{
				AST_Failure( "Unexpected Swizzle expression" );
			}

			void visitTextureAccessCallExpr( ast::expr::TextureAccessCall * expr )override
			{
				AST_Failure( "Unexpected TextureAccessCall expression" );
			}

		private:
			ast::expr::LiteralPtr & m_result;
			PreprocContext const & m_context;
		};
	}

	bool eval( ast::expr::Expr * expr
		, PreprocContext const & context )
	{
		return getLiteral( expr, context )->getValue< ast::expr::LiteralType::eBool >();
	}

	ast::expr::LiteralPtr getLiteral( ast::expr::Expr * expr
		, PreprocContext const & context )
	{
		return ExprEvaluator::submit( expr, context );
	}
}
