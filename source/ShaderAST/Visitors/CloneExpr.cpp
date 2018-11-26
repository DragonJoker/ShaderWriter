/*
See LICENSE file in root folder
*/
#include "ShaderAST/Visitors/CloneExpr.hpp"

namespace ast
{
	expr::ExprPtr ExprCloner::submit( expr::Expr * expr )
	{
		expr::ExprPtr result;
		ExprCloner vis{ result };
		expr->accept( &vis );
		return result;
	}

	expr::ExprPtr ExprCloner::submit( expr::ExprPtr const & expr )
	{
		if ( expr )
		{
			return submit( expr.get() );
		}

		return nullptr;
	}

	ExprCloner::ExprCloner( expr::ExprPtr & result )
		: m_result{ result }
	{
	}

	expr::ExprPtr ExprCloner::doSubmit( expr::Expr * expr )
	{
		expr::ExprPtr result;
		ExprCloner vis{ result };
		expr->accept( &vis );
		return result;
	}

	expr::ExprPtr ExprCloner::doSubmit( expr::ExprPtr const & expr )
	{
		if ( expr )
		{
			return doSubmit( expr.get() );
		}

		return nullptr;
	}

	void ExprCloner::visitAddExpr( expr::Add * expr )
	{
		m_result = expr::makeAdd( expr->getType()
			, doSubmit( expr->getLHS() )
			, doSubmit( expr->getRHS() ) );
	}

	void ExprCloner::visitAddAssignExpr( expr::AddAssign * expr )
	{
		m_result = expr::makeAddAssign( expr->getType()
			, doSubmit( expr->getLHS() )
			, doSubmit( expr->getRHS() ) );
	}

	void ExprCloner::visitAggrInitExpr( expr::AggrInit * expr )
	{
		expr::ExprList initialisers;

		for ( auto & init : expr->getInitialisers() )
		{
			initialisers.emplace_back( doSubmit( init ) );
		}

		if ( expr->getIdentifier() )
		{
			m_result = expr::makeAggrInit( std::make_unique< expr::Identifier >( *expr->getIdentifier() )
				, std::move( initialisers ) );
		}
		else
		{
			m_result = expr::makeAggrInit( expr->getType()
				, std::move( initialisers ) );
		}
	}

	void ExprCloner::visitAndAssignExpr( expr::AndAssign * expr )
	{
		m_result = expr::makeAndAssign( expr->getType()
			, doSubmit( expr->getLHS() )
			, doSubmit( expr->getRHS() ) );
	}

	void ExprCloner::visitArrayAccessExpr( expr::ArrayAccess * expr )
	{
		m_result = std::make_unique< expr::ArrayAccess >( expr->getType()
			, doSubmit( expr->getLHS() )
			, doSubmit( expr->getRHS() ) );
	}

	void ExprCloner::visitAssignExpr( expr::Assign * expr )
	{
		m_result = expr::makeAssign( expr->getType()
			, doSubmit( expr->getLHS() )
			, doSubmit( expr->getRHS() ) );
	}

	void ExprCloner::visitBitAndExpr( expr::BitAnd * expr )
	{
		m_result = expr::makeBitAnd( expr->getType()
			, doSubmit( expr->getLHS() )
			, doSubmit( expr->getRHS() ) );
	}

	void ExprCloner::visitBitNotExpr( expr::BitNot * expr )
	{
		m_result = expr::makeBitNot( expr->getType()
			, doSubmit( expr->getOperand() ) );
	}

	void ExprCloner::visitBitOrExpr( expr::BitOr * expr )
	{
		m_result = expr::makeBitOr( expr->getType()
			, doSubmit( expr->getLHS() )
			, doSubmit( expr->getRHS() ) );
	}

	void ExprCloner::visitBitXorExpr( expr::BitXor * expr )
	{
		m_result = expr::makeBitXor( expr->getType()
			, doSubmit( expr->getLHS() )
			, doSubmit( expr->getRHS() ) );
	}

	void ExprCloner::visitCastExpr( expr::Cast * expr )
	{
		m_result = expr::makeCast( expr->getType()
			, doSubmit( expr->getOperand() ) );
	}

	void ExprCloner::visitCommaExpr( expr::Comma * expr )
	{
		m_result = expr::makeComma( doSubmit( expr->getLHS() )
			, doSubmit( expr->getRHS() ) );
	}

	void ExprCloner::visitCompositeConstructExpr( expr::CompositeConstruct * expr )
	{
		expr::ExprList args;

		for ( auto & arg : expr->getArgList() )
		{
			args.emplace_back( doSubmit( arg ) );
		}

		m_result = expr::makeCompositeConstruct( expr->getComposite()
			, expr->getComponent()
			, std::move( args ) );
	}

	void ExprCloner::visitDivideExpr( expr::Divide * expr )
	{
		m_result = expr::makeDivide( expr->getType()
			, doSubmit( expr->getLHS() )
			, doSubmit( expr->getRHS() ) );
	}

	void ExprCloner::visitDivideAssignExpr( expr::DivideAssign * expr )
	{
		m_result = expr::makeDivideAssign( expr->getType()
			, doSubmit( expr->getLHS() )
			, doSubmit( expr->getRHS() ) );
	}

	void ExprCloner::visitEqualExpr( expr::Equal * expr )
	{
		m_result = expr::makeEqual( doSubmit( expr->getLHS() )
			, doSubmit( expr->getRHS() ) );
	}

	void ExprCloner::visitFnCallExpr( expr::FnCall * expr )
	{
		expr::ExprList args;

		for ( auto & arg : expr->getArgList() )
		{
			args.emplace_back( doSubmit( arg ) );
		}

		if ( expr->isMember() )
		{
			m_result = expr::makeMemberFnCall( expr->getType()
				, std::make_unique< expr::Identifier >( *expr->getFn() )
				, doSubmit( expr->getInstance() )
				, std::move( args ) );
		}
		else
		{
			m_result = expr::makeFnCall( expr->getType()
				, std::make_unique< expr::Identifier >( *expr->getFn() )
				, std::move( args ) );
		}
	}

	void ExprCloner::visitGreaterExpr( expr::Greater * expr )
	{
		m_result = expr::makeGreater( doSubmit( expr->getLHS() )
			, doSubmit( expr->getRHS() ) );
	}

	void ExprCloner::visitGreaterEqualExpr( expr::GreaterEqual * expr )
	{
		m_result = expr::makeGreaterEqual( doSubmit( expr->getLHS() )
			, doSubmit( expr->getRHS() ) );
	}

	void ExprCloner::visitIdentifierExpr( expr::Identifier * expr )
	{
		m_result = expr::makeIdentifier( expr->getVariable() );
	}

	void ExprCloner::visitImageAccessCallExpr( expr::ImageAccessCall * expr )
	{
		expr::ExprList args;

		for ( auto & arg : expr->getArgList() )
		{
			args.emplace_back( doSubmit( arg ) );
		}

		m_result = expr::makeImageAccessCall( expr->getType()
			, expr->getImageAccess()
			, std::move( args ) );
	}

	void ExprCloner::visitInitExpr( expr::Init * expr )
	{
		m_result = expr::makeInit( std::make_unique< expr::Identifier >( *expr->getIdentifier() )
			, doSubmit( expr->getInitialiser() ) );
	}

	void ExprCloner::visitIntrinsicCallExpr( expr::IntrinsicCall * expr )
	{
		expr::ExprList args;

		for ( auto & arg : expr->getArgList() )
		{
			args.emplace_back( doSubmit( arg ) );
		}

		m_result = expr::makeIntrinsicCall( expr->getType()
			, expr->getIntrinsic()
			, std::move( args ) );
	}

	void ExprCloner::visitLessExpr( expr::Less * expr )
	{
		m_result = expr::makeLess( doSubmit( expr->getLHS() )
			, doSubmit( expr->getRHS() ) );
	}

	void ExprCloner::visitLessEqualExpr( expr::LessEqual * expr )
	{
		m_result = expr::makeLessEqual( doSubmit( expr->getLHS() )
			, doSubmit( expr->getRHS() ) );
	}

	void ExprCloner::visitLiteralExpr( expr::Literal * expr )
	{
		m_result = std::make_unique< expr::Literal >( *expr );
	}

	void ExprCloner::visitLogAndExpr( expr::LogAnd * expr )
	{
		m_result = expr::makeLogAnd( doSubmit( expr->getLHS() )
			, doSubmit( expr->getRHS() ) );
	}

	void ExprCloner::visitLogNotExpr( expr::LogNot * expr )
	{
		m_result = expr::makeLogNot( doSubmit( expr->getOperand() ) );
	}

	void ExprCloner::visitLogOrExpr( expr::LogOr * expr )
	{
		m_result = expr::makeLogOr( doSubmit( expr->getLHS() )
			, doSubmit( expr->getRHS() ) );
	}

	void ExprCloner::visitLShiftExpr( expr::LShift * expr )
	{
		m_result = expr::makeLShift( expr->getType()
			, doSubmit( expr->getLHS() )
			, doSubmit( expr->getRHS() ) );
	}

	void ExprCloner::visitLShiftAssignExpr( expr::LShiftAssign * expr )
	{
		m_result = expr::makeLShiftAssign( expr->getType()
			, doSubmit( expr->getLHS() )
			, doSubmit( expr->getRHS() ) );
	}

	void ExprCloner::visitMbrSelectExpr( expr::MbrSelect * expr )
	{
		m_result = expr::makeMbrSelect( doSubmit( expr->getOuterExpr() )
			, expr->getMemberIndex()
			, std::make_unique< expr::Identifier >( *static_cast< expr::Identifier * >( expr->getOperand() ) ) );
	}

	void ExprCloner::visitMinusExpr( expr::Minus * expr )
	{
		m_result = expr::makeMinus( expr->getType()
			, doSubmit( expr->getLHS() )
			, doSubmit( expr->getRHS() ) );
	}

	void ExprCloner::visitMinusAssignExpr( expr::MinusAssign * expr )
	{
		m_result = expr::makeMinusAssign( expr->getType()
			, doSubmit( expr->getLHS() )
			, doSubmit( expr->getRHS() ) );
	}

	void ExprCloner::visitModuloExpr( expr::Modulo * expr )
	{
		m_result = expr::makeModulo( expr->getType()
			, doSubmit( expr->getLHS() )
			, doSubmit( expr->getRHS() ) );
	}

	void ExprCloner::visitModuloAssignExpr( expr::ModuloAssign * expr )
	{
		m_result = expr::makeModuloAssign( expr->getType()
			, doSubmit( expr->getLHS() )
			, doSubmit( expr->getRHS() ) );
	}

	void ExprCloner::visitNotEqualExpr( expr::NotEqual * expr )
	{
		m_result = expr::makeNotEqual( doSubmit( expr->getLHS() )
			, doSubmit( expr->getRHS() ) );
	}

	void ExprCloner::visitOrAssignExpr( expr::OrAssign * expr )
	{
		m_result = expr::makeOrAssign( expr->getType()
			, doSubmit( expr->getLHS() )
			, doSubmit( expr->getRHS() ) );
	}

	void ExprCloner::visitPostDecrementExpr( expr::PostDecrement * expr )
	{
		m_result = expr::makePostDecrement( doSubmit( expr->getOperand() ) );
	}

	void ExprCloner::visitPostIncrementExpr( expr::PostIncrement * expr )
	{
		m_result = expr::makePostIncrement( doSubmit( expr->getOperand() ) );
	}

	void ExprCloner::visitPreDecrementExpr( expr::PreDecrement * expr )
	{
		m_result = expr::makePreDecrement( doSubmit( expr->getOperand() ) );
	}

	void ExprCloner::visitPreIncrementExpr( expr::PreIncrement * expr )
	{
		m_result = expr::makePreIncrement( doSubmit( expr->getOperand() ) );
	}

	void ExprCloner::visitQuestionExpr( expr::Question * expr )
	{
		m_result = expr::makeQuestion( expr->getType()
			, doSubmit( expr->getCtrlExpr() )
			, doSubmit( expr->getTrueExpr() )
			, doSubmit( expr->getFalseExpr() ) );
	}

	void ExprCloner::visitRShiftExpr( expr::RShift * expr )
	{
		m_result = expr::makeRShift( expr->getType()
			, doSubmit( expr->getLHS() )
			, doSubmit( expr->getRHS() ) );
	}

	void ExprCloner::visitRShiftAssignExpr( expr::RShiftAssign * expr )
	{
		m_result = expr::makeRShiftAssign( expr->getType()
			, doSubmit( expr->getLHS() )
			, doSubmit( expr->getRHS() ) );
	}

	void ExprCloner::visitSwitchCaseExpr( expr::SwitchCase * expr )
	{
		m_result = expr::makeSwitchCase( std::make_unique< expr::Literal >( *expr->getLabel() ) );
	}

	void ExprCloner::visitSwitchTestExpr( expr::SwitchTest * expr )
	{
		m_result = expr::makeSwitchTest( doSubmit( expr->getValue() ) );
	}

	void ExprCloner::visitSwizzleExpr( expr::Swizzle * expr )
	{
		m_result = std::make_unique< expr::Swizzle >( doSubmit( expr->getOuterExpr() )
			, expr->getSwizzle() );
	}

	void ExprCloner::visitTextureAccessCallExpr( expr::TextureAccessCall * expr )
	{
		expr::ExprList args;

		for ( auto & arg : expr->getArgList() )
		{
			args.emplace_back( doSubmit( arg ) );
		}

		m_result = expr::makeTextureAccessCall( expr->getType()
			, expr->getTextureAccess()
			, std::move( args ) );
	}

	void ExprCloner::visitTimesExpr( expr::Times * expr )
	{
		m_result = expr::makeTimes( expr->getType()
			, doSubmit( expr->getLHS() )
			, doSubmit( expr->getRHS() ) );
	}

	void ExprCloner::visitTimesAssignExpr( expr::TimesAssign * expr )
	{
		m_result = expr::makeTimesAssign( expr->getType()
			, doSubmit( expr->getLHS() )
			, doSubmit( expr->getRHS() ) );
	}

	void ExprCloner::visitUnaryMinusExpr( expr::UnaryMinus * expr )
	{
		m_result = expr::makeUnaryMinus( doSubmit( expr->getOperand() ) );
	}

	void ExprCloner::visitUnaryPlusExpr( expr::UnaryPlus * expr )
	{
		m_result = expr::makeUnaryMinus( doSubmit( expr->getOperand() ) );
	}

	void ExprCloner::visitXorAssignExpr( expr::XorAssign * expr )
	{
		m_result = expr::makeXorAssign( expr->getType()
			, doSubmit( expr->getLHS() )
			, doSubmit( expr->getRHS() ) );
	}
}
