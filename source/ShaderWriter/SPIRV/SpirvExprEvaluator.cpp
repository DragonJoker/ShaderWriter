/*
See LICENSE file in root folder
*/
#include "ShaderWriter/SPIRV/SpirvExprEvaluator.hpp"

#include <ASTGenerator/Expr/ExprVisitor.hpp>

#include <sstream>

namespace sdw::spirv
{
	namespace
	{
		class ExprEvaluator
			: public expr::SimpleVisitor
		{
		public:
			static expr::LiteralPtr submit( expr::Expr * expr
				, PreprocContext const & context )
			{
				expr::LiteralPtr result;
				ExprEvaluator vis{ result, context };
				expr->accept( &vis );
				return result;
			}

		private:
			ExprEvaluator( expr::LiteralPtr & result
				, PreprocContext const & context )
				: m_result{ result }
				, m_context{ context }
			{
			}

			void visitUnaryExpr( expr::Unary * expr )override
			{
				auto operand = submit( expr->getOperand(), m_context );

				switch ( expr->getKind() )
				{
				case expr::Kind::eBitNot:
					m_result = ~( *operand );
					break;
				case expr::Kind::eLogNot:
					m_result = !( *operand );
					break;
				case expr::Kind::eUnaryMinus:
					m_result = -( *operand );
					break;
				}
			}

			void visitBinaryExpr( expr::Binary * expr )override
			{
				auto lhs = submit( expr->getLHS(), m_context );
				auto rhs = submit( expr->getRHS(), m_context );

				switch ( expr->getKind() )
				{
				case expr::Kind::eAdd:
					m_result = *lhs + *rhs;
					break;
				case expr::Kind::eMinus:
					m_result = *lhs - *rhs;
					break;
				case expr::Kind::eTimes:
					m_result = *lhs * *rhs;
					break;
				case expr::Kind::eDivide:
					m_result = *lhs / *rhs;
					break;
				case expr::Kind::eModulo:
					m_result = *lhs % *rhs;
					break;
				case expr::Kind::eLShift:
					m_result = *lhs << *rhs;
					break;
				case expr::Kind::eRShift:
					m_result = *lhs >> *rhs;
					break;
				case expr::Kind::eBitAnd:
					m_result = *lhs & *rhs;
					break;
				case expr::Kind::eBitOr:
					m_result = *lhs | *rhs;
					break;
				case expr::Kind::eBitXor:
					m_result = *lhs ^ *rhs;
					break;
				case expr::Kind::eLogAnd:
					m_result = *lhs && *rhs;
					break;
				case expr::Kind::eLogOr:
					m_result = *lhs || *rhs;
					break;
				case expr::Kind::eEqual:
					m_result = *lhs == *rhs;
					break;
				case expr::Kind::eGreater:
					m_result = *lhs > *rhs;
					break;
				case expr::Kind::eGreaterEqual:
					m_result = *lhs >= *rhs;
					break;
				case expr::Kind::eLess:
					m_result = *lhs < *rhs;
					break;
				case expr::Kind::eLessEqual:
					m_result = *lhs <= *rhs;
					break;
				case expr::Kind::eNotEqual:
					m_result = *lhs != *rhs;
					break;
				}
			}

			void visitIdentifierExpr( expr::Identifier * expr )override
			{
				m_result = std::unique_ptr< expr::Literal >( new expr::Literal{ static_cast< expr::Literal const & >( *m_context.defines.at( expr->getVariable()->getName() ) ) } );
			}

			void visitLiteralExpr( expr::Literal * expr )override
			{
				m_result = std::unique_ptr< expr::Literal >( new expr::Literal{ *expr } );
			}

			void visitPreDecrementExpr( expr::PreDecrement * expr )override
			{
				assert( false && "Unexpected PreDecrement expression" );
			}

			void visitPreIncrementExpr( expr::PreIncrement * expr )override
			{
				assert( false && "Unexpected PreIncrement expression" );
			}

			void visitPostDecrementExpr( expr::PostDecrement * expr )override
			{
				assert( false && "Unexpected PostDecrement expression" );
			}

			void visitPostIncrementExpr( expr::PostIncrement * expr )override
			{
				assert( false && "Unexpected PostIncrement expression" );
			}

			void visitUnaryPlusExpr( expr::UnaryPlus * expr )override
			{
				assert( false && "Unexpected UnaryPlus expression" );
			}

			void visitAddAssignExpr( expr::AddAssign * expr )override
			{
				assert( false && "Unexpected AddAssign expression" );
			}

			void visitAndAssignExpr( expr::AndAssign * expr )override
			{
				assert( false && "Unexpected AndAssign expression" );
			}

			void visitArrayAccessExpr( expr::ArrayAccess * expr )override
			{
				assert( false && "Unexpected ArrayAccess expression" );
			}

			void visitAssignExpr( expr::Assign * expr )override
			{
				assert( false && "Unexpected Assign expression" );
			}

			void visitCastExpr( expr::Cast * expr )override
			{
				assert( false && "Unexpected Cast expression" );
			}

			void visitCommaExpr( expr::Comma * expr )override
			{
				assert( false && "Unexpected Comma expression" );
			}

			void visitDivideAssignExpr( expr::DivideAssign * expr )override
			{
				assert( false && "Unexpected DivideAssign expression" );
			}

			void visitLShiftAssignExpr( expr::LShiftAssign * expr )override
			{
				assert( false && "Unexpected LShiftAssign expression" );
			}

			void visitMinusAssignExpr( expr::MinusAssign * expr )override
			{
				assert( false && "Unexpected MinusAssign expression" );
			}

			void visitModuloAssignExpr( expr::ModuloAssign * expr )override
			{
				assert( false && "Unexpected ModuloAssign expression" );
			}

			void visitOrAssignExpr( expr::OrAssign * expr )override
			{
				assert( false && "Unexpected OrAssign expression" );
			}

			void visitRShiftAssignExpr( expr::RShiftAssign * expr )override
			{
				assert( false && "Unexpected RShiftAssign expression" );
			}

			void visitTimesAssignExpr( expr::TimesAssign * expr )override
			{
				assert( false && "Unexpected TimesAssign expression" );
			}

			void visitXorAssignExpr( expr::XorAssign * expr )override
			{
				assert( false && "Unexpected XorAssign expression" );
			}

			void visitAggrInitExpr( expr::AggrInit * expr )override
			{
				assert( false && "Unexpected AggrInit expression" );
			}

			void visitMbrSelectExpr( expr::MbrSelect * expr )override
			{
				assert( false && "Unexpected MbrSelect expression" );
			}

			void visitFnCallExpr( expr::FnCall * expr )override
			{
				assert( false && "Unexpected FnCall expression" );
			}

			void visitImageAccessCallExpr( expr::ImageAccessCall * expr )override
			{
				assert( false && "Unexpected ImageAccessCall expression" );
			}

			void visitInitExpr( expr::Init * expr )override
			{
				assert( false && "Unexpected Init expression" );
			}

			void visitIntrinsicCallExpr( expr::IntrinsicCall * expr )override
			{
				assert( false && "Unexpected IntrinsicCall expression" );
			}

			void visitQuestionExpr( expr::Question * expr )override
			{
				assert( false && "Unexpected Question expression" );
			}

			void visitSwitchCaseExpr( expr::SwitchCase * expr )override
			{
				assert( false && "Unexpected SwitchCase expression" );
			}

			void visitSwitchTestExpr( expr::SwitchTest * expr )override
			{
				assert( false && "Unexpected SwitchTest expression" );
			}

			void visitSwizzleExpr( expr::Swizzle * expr )override
			{
				assert( false && "Unexpected Swizzle expression" );
			}

			void visitTextureAccessCallExpr( expr::TextureAccessCall * expr )override
			{
				assert( false && "Unexpected TextureAccessCall expression" );
			}

		private:
			expr::LiteralPtr & m_result;
			PreprocContext const & m_context;
		};
	}

	bool eval( expr::Expr * expr
		, PreprocContext const & context )
	{
		return ExprEvaluator::submit( expr, context )->getValue< expr::LiteralType::eBool >();
	}
}
