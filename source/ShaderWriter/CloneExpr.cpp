/*
See LICENSE file in root folder
*/
#include "ShaderWriter/CloneExpr.hpp"

#include <ASTGenerator/Expr/ExprVisitor.hpp>

namespace sdw
{
	using namespace ast;

	namespace
	{
		class ExprCloner
			: public expr::Visitor
		{
		public:
			static expr::ExprPtr submit( expr::Expr * expr )
			{
				expr::ExprPtr result;
				ExprCloner vis{ result };
				expr->accept( &vis );
				return result;
			}

			static expr::ExprPtr submit( expr::ExprPtr const & expr )
			{
				if ( expr )
				{
					return submit( expr.get() );
				}

				return nullptr;
			}

		private:
			ExprCloner( expr::ExprPtr & result )
				: m_result{ result }
			{
			}

			void visitAddExpr( expr::Add * expr )override
			{
				m_result = expr::makeAdd( expr->getType()
					, submit( expr->getLHS() )
					, submit( expr->getRHS() ) );
			}

			void visitAddAssignExpr( expr::AddAssign * expr )override
			{
				m_result = expr::makeAddAssign( expr->getType()
					, submit( expr->getLHS() )
					, submit( expr->getRHS() ) );
			}

			void visitAggrInitExpr( expr::AggrInit * expr )override
			{
				expr::ExprList initialisers;

				for ( auto & init : expr->getInitialisers() )
				{
					initialisers.emplace_back( submit( init ) );
				}

				m_result = expr::makeAggrInit( std::make_unique< expr::Identifier >( *expr->getIdentifier() )
					, std::move( initialisers ) );
			}

			void visitAndAssignExpr( expr::AndAssign * expr )override
			{
				m_result = expr::makeAndAssign( expr->getType()
					, submit( expr->getLHS() )
					, submit( expr->getRHS() ) );
			}

			void visitArrayAccessExpr( expr::ArrayAccess * expr )override
			{
				m_result = expr::makeArrayAccess( expr->getType()
					, submit( expr->getLHS() )
					, submit( expr->getRHS() ) );
			}

			void visitAssignExpr( expr::Assign * expr )override
			{
				m_result = expr::makeAssign( expr->getType()
					, submit( expr->getLHS() )
					, submit( expr->getRHS() ) );
			}

			void visitBitAndExpr( expr::BitAnd * expr )override
			{
				m_result = expr::makeBitAnd( expr->getType()
					, submit( expr->getLHS() )
					, submit( expr->getRHS() ) );
			}

			void visitBitNotExpr( expr::BitNot * expr )override
			{
				m_result = expr::makeBitNot( expr->getType()
					, submit( expr->getOperand() ) );
			}

			void visitBitOrExpr( expr::BitOr * expr )override
			{
				m_result = expr::makeBitOr( expr->getType()
					, submit( expr->getLHS() )
					, submit( expr->getRHS() ) );
			}

			void visitBitXorExpr( expr::BitXor * expr )override
			{
				m_result = expr::makeBitXor( expr->getType()
					, submit( expr->getLHS() )
					, submit( expr->getRHS() ) );
			}

			void visitCastExpr( expr::Cast * expr )override
			{
				m_result = expr::makeCast( expr->getType()
					, submit( expr->getOperand() ) );
			}

			void visitCommaExpr( expr::Comma * expr )override
			{
				m_result = expr::makeComma( submit( expr->getLHS() )
					, submit( expr->getRHS() ) );
			}

			void visitDivideExpr( expr::Divide * expr )override
			{
				m_result = expr::makeDivide( expr->getType()
					, submit( expr->getLHS() )
					, submit( expr->getRHS() ) );
			}

			void visitDivideAssignExpr( expr::DivideAssign * expr )override
			{
				m_result = expr::makeDivideAssign( expr->getType()
					, submit( expr->getLHS() )
					, submit( expr->getRHS() ) );
			}

			void visitEqualExpr( expr::Equal * expr )override
			{
				m_result = expr::makeEqual( submit( expr->getLHS() )
					, submit( expr->getRHS() ) );
			}

			void visitFnCallExpr( expr::FnCall * expr )override
			{
				expr::ExprList args;

				for ( auto & arg : expr->getArgList() )
				{
					args.emplace_back( submit( arg ) );
				}

				m_result = expr::makeFnCall( expr->getType()
					, std::make_unique< expr::Identifier >( *expr->getFn() )
					, std::move( args ) );
			}

			void visitGreaterExpr( expr::Greater * expr )override
			{
				m_result = expr::makeGreater( submit( expr->getLHS() )
					, submit( expr->getRHS() ) );
			}

			void visitGreaterEqualExpr( expr::GreaterEqual * expr )override
			{
				m_result = expr::makeGreaterEqual( submit( expr->getLHS() )
					, submit( expr->getRHS() ) );
			}

			void visitIdentifierExpr( expr::Identifier * expr )override
			{
				m_result = expr::makeIdentifier( expr->getVariable() );
			}

			void visitImageAccessCallExpr( expr::ImageAccessCall * expr )override
			{
				expr::ExprList args;

				for ( auto & arg : expr->getArgList() )
				{
					args.emplace_back( submit( arg ) );
				}

				m_result = expr::makeImageAccessCall( expr->getType()
					, expr->getImageAccess()
					, std::move( args ) );
			}

			void visitInitExpr( expr::Init * expr )override
			{
				m_result = expr::makeInit( std::make_unique< expr::Identifier >( *expr->getIdentifier() )
					, submit( expr->getInitialiser() ) );
			}

			void visitIntrinsicCallExpr( expr::IntrinsicCall * expr )override
			{
				expr::ExprList args;

				for ( auto & arg : expr->getArgList() )
				{
					args.emplace_back( submit( arg ) );
				}

				m_result = expr::makeIntrinsicCall( expr->getType()
					, expr->getIntrinsic()
					, std::move( args ) );
			}

			void visitLessExpr( expr::Less * expr )override
			{
				m_result = expr::makeLess( submit( expr->getLHS() )
					, submit( expr->getRHS() ) );
			}

			void visitLessEqualExpr( expr::LessEqual * expr )override
			{
				m_result = expr::makeLessEqual( submit( expr->getLHS() )
					, submit( expr->getRHS() ) );
			}

			void visitLiteralExpr( expr::Literal * expr )override
			{
				m_result = std::make_unique< expr::Literal >( *expr );
			}

			void visitLogAndExpr( expr::LogAnd * expr )override
			{
				m_result = expr::makeLogAnd( submit( expr->getLHS() )
					, submit( expr->getRHS() ) );
			}

			void visitLogNotExpr( expr::LogNot * expr )override
			{
				m_result = expr::makeLogNot( submit( expr->getOperand() ) );
			}

			void visitLogOrExpr( expr::LogOr * expr )override
			{
				m_result = expr::makeLogOr( submit( expr->getLHS() )
					, submit( expr->getRHS() ) );
			}

			void visitLShiftExpr( expr::LShift * expr )override
			{
				m_result = expr::makeLShift( expr->getType()
					, submit( expr->getLHS() )
					, submit( expr->getRHS() ) );
			}

			void visitLShiftAssignExpr( expr::LShiftAssign * expr )override
			{
				m_result = expr::makeLShiftAssign( expr->getType()
					, submit( expr->getLHS() )
					, submit( expr->getRHS() ) );
			}

			void visitMbrSelectExpr( expr::MbrSelect * expr )override
			{
				m_result = expr::makeMbrSelect( submit( expr->getOuterExpr() )
					, std::make_unique< expr::Identifier >( *static_cast< expr::Identifier * >( expr->getOperand() ) ) );
			}

			void visitMinusExpr( expr::Minus * expr )override
			{
				m_result = expr::makeMinus( expr->getType()
					, submit( expr->getLHS() )
					, submit( expr->getRHS() ) );
			}

			void visitMinusAssignExpr( expr::MinusAssign * expr )override
			{
				m_result = expr::makeMinusAssign( expr->getType()
					, submit( expr->getLHS() )
					, submit( expr->getRHS() ) );
			}

			void visitModuloExpr( expr::Modulo * expr )override
			{
				m_result = expr::makeModulo( expr->getType()
					, submit( expr->getLHS() )
					, submit( expr->getRHS() ) );
			}

			void visitModuloAssignExpr( expr::ModuloAssign * expr )override
			{
				m_result = expr::makeModuloAssign( expr->getType()
					, submit( expr->getLHS() )
					, submit( expr->getRHS() ) );
			}

			void visitNotEqualExpr( expr::NotEqual * expr )override
			{
				m_result = expr::makeNotEqual( submit( expr->getLHS() )
					, submit( expr->getRHS() ) );
			}

			void visitOrAssignExpr( expr::OrAssign * expr )override
			{
				m_result = expr::makeOrAssign( expr->getType()
					, submit( expr->getLHS() )
					, submit( expr->getRHS() ) );
			}

			void visitPostDecrementExpr( expr::PostDecrement * expr )override
			{
				m_result = expr::makePostDecrement( submit( expr->getOperand() ) );
			}

			void visitPostIncrementExpr( expr::PostIncrement * expr )override
			{
				m_result = expr::makePostIncrement( submit( expr->getOperand() ) );
			}

			void visitPreDecrementExpr( expr::PreDecrement * expr )override
			{
				m_result = expr::makePreDecrement( submit( expr->getOperand() ) );
			}

			void visitPreIncrementExpr( expr::PreIncrement * expr )override
			{
				m_result = expr::makePreIncrement( submit( expr->getOperand() ) );
			}

			void visitQuestionExpr( expr::Question * expr )override
			{
				m_result = expr::makeQuestion( expr->getType()
					, submit( expr->getCtrlExpr() )
					, submit( expr->getTrueExpr() )
					, submit( expr->getFalseExpr() ) );
			}

			void visitRShiftExpr( expr::RShift * expr )override
			{
				m_result = expr::makeRShift( expr->getType()
					, submit( expr->getLHS() )
					, submit( expr->getRHS() ) );
			}

			void visitRShiftAssignExpr( expr::RShiftAssign * expr )override
			{
				m_result = expr::makeRShiftAssign( expr->getType()
					, submit( expr->getLHS() )
					, submit( expr->getRHS() ) );
			}

			void visitSwitchCaseExpr( expr::SwitchCase * expr )override
			{
				m_result = expr::makeSwitchCase( std::make_unique< expr::Literal >( *expr->getLabel() ) );
			}

			void visitSwitchTestExpr( expr::SwitchTest * expr )override
			{
				m_result = expr::makeSwitchTest( submit( expr->getValue() ) );
			}

			void visitTextureAccessCallExpr( expr::TextureAccessCall * expr )override
			{
				expr::ExprList args;

				for ( auto & arg : expr->getArgList() )
				{
					args.emplace_back( submit( arg ) );
				}

				m_result = expr::makeTextureAccessCall( expr->getType()
					, expr->getTextureAccess()
					, std::move( args ) );
			}

			void visitTimesExpr( expr::Times * expr )override
			{
				m_result = expr::makeTimes( expr->getType()
					, submit( expr->getLHS() )
					, submit( expr->getRHS() ) );
			}

			void visitTimesAssignExpr( expr::TimesAssign * expr )override
			{
				m_result = expr::makeTimesAssign( expr->getType()
					, submit( expr->getLHS() )
					, submit( expr->getRHS() ) );
			}

			void visitUnaryMinusExpr( expr::UnaryMinus * expr )override
			{
				m_result = expr::makeUnaryMinus( submit( expr->getOperand() ) );
			}

			void visitUnaryPlusExpr( expr::UnaryPlus * expr )override
			{
				m_result = expr::makeUnaryMinus( submit( expr->getOperand() ) );
			}

			void visitXorAssignExpr( expr::XorAssign * expr )override
			{
				m_result = expr::makeXorAssign( expr->getType()
					, submit( expr->getLHS() )
					, submit( expr->getRHS() ) );
			}


		private:
			expr::ExprPtr & m_result;
		};
	}

	expr::ExprPtr makeExpr( expr::ExprPtr const & expr )
	{
		return ExprCloner::submit( expr );
	}

	expr::ExprPtr makeExpr( expr::Expr * expr )
	{
		return ExprCloner::submit( expr );
	}
}
