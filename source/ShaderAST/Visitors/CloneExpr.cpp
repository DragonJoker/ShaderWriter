/*
See LICENSE file in root folder
*/
#include "ShaderAST/Visitors/CloneExpr.hpp"

namespace ast
{
	expr::ExprPtr ExprCloner::submit( expr::Expr * expr )
	{
		if ( !expr )
		{
			return nullptr;
		}

		if ( expr->isDummy() )
		{
			return std::make_unique< expr::Expr >( expr->getCache()
				, expr->getType()
				, expr::Kind::eIdentifier
				, expr::Flag::eDummy );
		}

		expr::ExprPtr result;
		ExprCloner vis{ result };
		expr->accept( &vis );

		if ( expr->isNonUniform() )
		{
			result->updateFlag( ast::expr::Flag::eNonUniform );
		}

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
		return submit( expr );
	}

	expr::ExprPtr ExprCloner::doSubmit( expr::ExprPtr const & expr )
	{
		if ( expr )
		{
			auto result = doSubmit( expr.get() );

			if ( result )
			{
				if ( expr->isNonUniform() )
				{
					result->updateFlag( ast::expr::Flag::eNonUniform );
				}
			}

			return result;
		}

		return nullptr;
	}

	void ExprCloner::visitAddExpr( expr::Add * expr )
	{
		auto lhs = doSubmit( expr->getLHS() );
		auto rhs = doSubmit( expr->getRHS() );

		if ( rhs && lhs )
		{
			m_result = expr::makeAdd( expr->getType()
				, std::move( lhs )
				, std::move( rhs ) );
		}
	}

	void ExprCloner::visitAddAssignExpr( expr::AddAssign * expr )
	{
		auto lhs = doSubmit( expr->getLHS() );
		auto rhs = doSubmit( expr->getRHS() );

		if ( rhs && lhs )
		{
			m_result = expr::makeAddAssign( expr->getType()
				, std::move( lhs )
				, std::move( rhs ) );
		}
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

	void ExprCloner::visitAliasExpr( expr::Alias * expr )
	{
		auto rhs = doSubmit( expr->getRHS() );

		if ( rhs )
		{
			m_result = expr::makeAlias( expr->getType()
				, std::make_unique< expr::Identifier >( static_cast< expr::Identifier const & >( *expr->getLHS() ) )
				, std::move( rhs ) );
		}
	}

	void ExprCloner::visitAndAssignExpr( expr::AndAssign * expr )
	{
		auto lhs = doSubmit( expr->getLHS() );
		auto rhs = doSubmit( expr->getRHS() );

		if ( rhs && lhs )
		{
			m_result = expr::makeAndAssign( expr->getType()
				, std::move( lhs )
				, std::move( rhs ) );
		}
	}

	void ExprCloner::visitArrayAccessExpr( expr::ArrayAccess * expr )
	{
		auto lhs = doSubmit( expr->getLHS() );
		auto rhs = doSubmit( expr->getRHS() );

		if ( rhs && lhs )
		{
			m_result = std::make_unique< expr::ArrayAccess >( expr->getType()
				, std::move( lhs )
				, std::move( rhs ) );
		}
	}

	void ExprCloner::visitAssignExpr( expr::Assign * expr )
	{
		auto lhs = doSubmit( expr->getLHS() );
		auto rhs = doSubmit( expr->getRHS() );

		if ( rhs && lhs )
		{
			m_result = expr::makeAssign( expr->getType()
				, std::move( lhs )
				, std::move( rhs ) );
		}
	}

	void ExprCloner::visitBitAndExpr( expr::BitAnd * expr )
	{
		auto lhs = doSubmit( expr->getLHS() );
		auto rhs = doSubmit( expr->getRHS() );

		if ( rhs && lhs )
		{
			m_result = expr::makeBitAnd( expr->getType()
				, std::move( lhs )
				, std::move( rhs ) );
		}
	}

	void ExprCloner::visitBitNotExpr( expr::BitNot * expr )
	{
		auto op = doSubmit( expr->getOperand() );

		if ( op )
		{
			m_result = ast::expr::makeBitNot( std::move( op ) );
		}
	}

	void ExprCloner::visitBitOrExpr( expr::BitOr * expr )
	{
		auto lhs = doSubmit( expr->getLHS() );
		auto rhs = doSubmit( expr->getRHS() );

		if ( rhs && lhs )
		{
			m_result = expr::makeBitOr( expr->getType()
				, std::move( lhs )
				, std::move( rhs ) );
		}
	}

	void ExprCloner::visitBitXorExpr( expr::BitXor * expr )
	{
		auto lhs = doSubmit( expr->getLHS() );
		auto rhs = doSubmit( expr->getRHS() );

		if ( rhs && lhs )
		{
			m_result = expr::makeBitXor( expr->getType()
				, std::move( lhs )
				, std::move( rhs ) );
		}
	}

	void ExprCloner::visitCastExpr( expr::Cast * expr )
	{
		auto op = doSubmit( expr->getOperand() );

		if ( op )
		{
			m_result = expr::makeCast( expr->getType()
				, std::move( op ) );
		}
	}

	void ExprCloner::visitCommaExpr( expr::Comma * expr )
	{
		auto lhs = doSubmit( expr->getLHS() );
		auto rhs = doSubmit( expr->getRHS() );

		if ( rhs && lhs )
		{
			m_result = expr::makeComma( std::move( lhs )
				, std::move( rhs ) );
		}
		else if ( lhs )
		{
			m_result = std::move( lhs );
		}
		else if ( rhs )
		{
			m_result = std::move( rhs );
		}
	}

	void ExprCloner::visitCompositeConstructExpr( expr::CompositeConstruct * expr )
	{
		expr::ExprList args;

		for ( auto & arg : expr->getArgList() )
		{
			args.emplace_back( doSubmit( arg ) );
		}

		if ( expr->getComposite() == expr::CompositeType::eCombine )
		{
			m_result = expr::makeCompositeConstruct( std::move( args.front() )
				, std::move( args.back() ) );
		}
		else
		{
			m_result = expr::makeCompositeConstruct( expr->getComposite()
				, expr->getComponent()
				, std::move( args ) );
		}
	}

	void ExprCloner::visitCopyExpr( expr::Copy * expr )
	{
		auto op = doSubmit( expr->getOperand() );

		if ( op )
		{
			m_result = expr::makeCopy( std::move( op ) );
		}
	}

	void ExprCloner::visitDivideExpr( expr::Divide * expr )
	{
		auto lhs = doSubmit( expr->getLHS() );
		auto rhs = doSubmit( expr->getRHS() );

		if ( rhs && lhs )
		{
			m_result = expr::makeDivide( expr->getType()
				, std::move( lhs )
				, std::move( rhs ) );
		}
	}

	void ExprCloner::visitDivideAssignExpr( expr::DivideAssign * expr )
	{
		auto lhs = doSubmit( expr->getLHS() );
		auto rhs = doSubmit( expr->getRHS() );

		if ( rhs && lhs )
		{
			m_result = expr::makeDivideAssign( expr->getType()
				, std::move( lhs )
				, std::move( rhs ) );
		}
	}

	void ExprCloner::visitEqualExpr( expr::Equal * expr )
	{
		auto lhs = doSubmit( expr->getLHS() );
		auto rhs = doSubmit( expr->getRHS() );

		if ( rhs && lhs )
		{
			m_result = std::make_unique< expr::Equal >( expr->getType()
				, std::move( lhs )
				, std::move( rhs ) );
		}
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
		auto lhs = doSubmit( expr->getLHS() );
		auto rhs = doSubmit( expr->getRHS() );

		if ( rhs && lhs )
		{
			m_result = std::make_unique< expr::Greater >( expr->getType()
				, std::move( lhs )
				, std::move( rhs ) );
		}
	}

	void ExprCloner::visitGreaterEqualExpr( expr::GreaterEqual * expr )
	{
		auto lhs = doSubmit( expr->getLHS() );
		auto rhs = doSubmit( expr->getRHS() );

		if ( rhs && lhs )
		{
			m_result = std::make_unique< expr::GreaterEqual >( expr->getType()
				, std::move( lhs )
				, std::move( rhs ) );
		}
	}

	void ExprCloner::visitIdentifierExpr( expr::Identifier * expr )
	{
		m_result = expr::makeIdentifier( expr->getCache(), expr->getVariable() );
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
		auto lhs = doSubmit( expr->getLHS() );
		auto rhs = doSubmit( expr->getRHS() );

		if ( rhs && lhs )
		{
			m_result = std::make_unique< expr::Less >( expr->getType()
				, std::move( lhs )
				, std::move( rhs ) );
		}
	}

	void ExprCloner::visitLessEqualExpr( expr::LessEqual * expr )
	{
		auto lhs = doSubmit( expr->getLHS() );
		auto rhs = doSubmit( expr->getRHS() );

		if ( rhs && lhs )
		{
			m_result = std::make_unique< expr::LessEqual >( expr->getType()
				, std::move( lhs )
				, std::move( rhs ) );
		}
	}

	void ExprCloner::visitLiteralExpr( expr::Literal * expr )
	{
		m_result = std::make_unique< expr::Literal >( *expr );
	}

	void ExprCloner::visitLogAndExpr( expr::LogAnd * expr )
	{
		auto lhs = doSubmit( expr->getLHS() );
		auto rhs = doSubmit( expr->getRHS() );

		if ( rhs && lhs )
		{
			m_result = std::make_unique< expr::LogAnd >( expr->getType()
				, std::move( lhs )
				, std::move( rhs ) );
		}
	}

	void ExprCloner::visitLogNotExpr( expr::LogNot * expr )
	{
		auto op = doSubmit( expr->getOperand() );

		if ( op )
		{
			m_result = std::make_unique< expr::LogNot >( expr->getType()
				, std::move( op ) );
		}
	}

	void ExprCloner::visitLogOrExpr( expr::LogOr * expr )
	{
		auto lhs = doSubmit( expr->getLHS() );
		auto rhs = doSubmit( expr->getRHS() );

		if ( rhs && lhs )
		{
			m_result = std::make_unique< expr::LogOr >( expr->getType()
				, std::move( lhs )
				, std::move( rhs ) );
		}
	}

	void ExprCloner::visitLShiftExpr( expr::LShift * expr )
	{
		auto lhs = doSubmit( expr->getLHS() );
		auto rhs = doSubmit( expr->getRHS() );

		if ( rhs && lhs )
		{
			m_result = expr::makeLShift( expr->getType()
				, std::move( lhs )
				, std::move( rhs ) );
		}
	}

	void ExprCloner::visitLShiftAssignExpr( expr::LShiftAssign * expr )
	{
		auto lhs = doSubmit( expr->getLHS() );
		auto rhs = doSubmit( expr->getRHS() );

		if ( rhs && lhs )
		{
			m_result = expr::makeLShiftAssign( expr->getType()
				, std::move( lhs )
				, std::move( rhs ) );
		}
	}

	void ExprCloner::visitMbrSelectExpr( expr::MbrSelect * expr )
	{
		m_result = expr::makeMbrSelect( doSubmit( expr->getOuterExpr() )
			, expr->getMemberIndex()
			, expr->getMemberFlags() );
	}

	void ExprCloner::visitMinusExpr( expr::Minus * expr )
	{
		auto lhs = doSubmit( expr->getLHS() );
		auto rhs = doSubmit( expr->getRHS() );

		if ( rhs && lhs )
		{
			m_result = expr::makeMinus( expr->getType()
				, std::move( lhs )
				, std::move( rhs ) );
		}
	}

	void ExprCloner::visitMinusAssignExpr( expr::MinusAssign * expr )
	{
		auto lhs = doSubmit( expr->getLHS() );
		auto rhs = doSubmit( expr->getRHS() );

		if ( rhs && lhs )
		{
			m_result = expr::makeMinusAssign( expr->getType()
				, std::move( lhs )
				, std::move( rhs ) );
		}
	}

	void ExprCloner::visitModuloExpr( expr::Modulo * expr )
	{
		auto lhs = doSubmit( expr->getLHS() );
		auto rhs = doSubmit( expr->getRHS() );

		if ( rhs && lhs )
		{
			m_result = expr::makeModulo( expr->getType()
				, std::move( lhs )
				, std::move( rhs ) );
		}
	}

	void ExprCloner::visitModuloAssignExpr( expr::ModuloAssign * expr )
	{
		auto lhs = doSubmit( expr->getLHS() );
		auto rhs = doSubmit( expr->getRHS() );

		if ( rhs && lhs )
		{
			m_result = expr::makeModuloAssign( expr->getType()
				, std::move( lhs )
				, std::move( rhs ) );
		}
	}

	void ExprCloner::visitNotEqualExpr( expr::NotEqual * expr )
	{
		auto lhs = doSubmit( expr->getLHS() );
		auto rhs = doSubmit( expr->getRHS() );

		if ( rhs && lhs )
		{
			m_result = expr::makeNotEqual( expr->getType()->getCache()
				, std::move( lhs )
				, std::move( rhs ) );
		}
	}

	void ExprCloner::visitOrAssignExpr( expr::OrAssign * expr )
	{
		auto lhs = doSubmit( expr->getLHS() );
		auto rhs = doSubmit( expr->getRHS() );

		if ( rhs && lhs )
		{
			m_result = expr::makeOrAssign( expr->getType()
				, std::move( lhs )
				, std::move( rhs ) );
		}
	}

	void ExprCloner::visitPostDecrementExpr( expr::PostDecrement * expr )
	{
		auto op = doSubmit( expr->getOperand() );

		if ( op )
		{
			m_result = expr::makePostDecrement( std::move( op ) );
		}
	}

	void ExprCloner::visitPostIncrementExpr( expr::PostIncrement * expr )
	{
		auto op = doSubmit( expr->getOperand() );

		if ( op )
		{
			m_result = expr::makePostIncrement( std::move( op ) );
		}
	}

	void ExprCloner::visitPreDecrementExpr( expr::PreDecrement * expr )
	{
		auto op = doSubmit( expr->getOperand() );

		if ( op )
		{
			m_result = expr::makePreDecrement( std::move( op ) );
		}
	}

	void ExprCloner::visitPreIncrementExpr( expr::PreIncrement * expr )
	{
		auto op = doSubmit( expr->getOperand() );

		if ( op )
		{
			m_result = expr::makePreIncrement( std::move( op ) );
		}
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
		auto lhs = doSubmit( expr->getLHS() );
		auto rhs = doSubmit( expr->getRHS() );

		if ( rhs && lhs )
		{
			m_result = expr::makeRShift( expr->getType()
				, std::move( lhs )
				, std::move( rhs ) );
		}
	}

	void ExprCloner::visitRShiftAssignExpr( expr::RShiftAssign * expr )
	{
		auto lhs = doSubmit( expr->getLHS() );
		auto rhs = doSubmit( expr->getRHS() );

		if ( rhs && lhs )
		{
			m_result = expr::makeRShiftAssign( expr->getType()
				, std::move( lhs )
				, std::move( rhs ) );
		}
	}

	void ExprCloner::visitSampledImageAccessCallExpr( expr::SampledImageAccessCall * expr )
	{
		expr::ExprList args;

		for ( auto & arg : expr->getArgList() )
		{
			args.emplace_back( doSubmit( arg ) );
		}

		m_result = expr::makeSampledImageAccessCall( expr->getType()
			, expr->getSampledImageAccess()
			, std::move( args ) );
	}

	void ExprCloner::visitStreamAppendExpr( expr::StreamAppend * expr )
	{
		auto op = doSubmit( expr->getOperand() );

		if ( op )
		{
			m_result = expr::makeStreamAppend( std::move( op ) );
		}
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

	void ExprCloner::visitCombinedImageAccessCallExpr( expr::CombinedImageAccessCall * expr )
	{
		expr::ExprList args;

		for ( auto & arg : expr->getArgList() )
		{
			args.emplace_back( doSubmit( arg ) );
		}

		m_result = expr::makeCombinedImageAccessCall( expr->getType()
			, expr->getCombinedImageAccess()
			, std::move( args ) );
	}

	void ExprCloner::visitTimesExpr( expr::Times * expr )
	{
		auto lhs = doSubmit( expr->getLHS() );
		auto rhs = doSubmit( expr->getRHS() );

		if ( rhs && lhs )
		{
			m_result = expr::makeTimes( expr->getType()
				, std::move( lhs )
				, std::move( rhs ) );
		}
	}

	void ExprCloner::visitTimesAssignExpr( expr::TimesAssign * expr )
	{
		auto lhs = doSubmit( expr->getLHS() );
		auto rhs = doSubmit( expr->getRHS() );

		if ( rhs && lhs )
		{
			m_result = expr::makeTimesAssign( expr->getType()
				, std::move( lhs )
				, std::move( rhs ) );
		}
	}

	void ExprCloner::visitUnaryMinusExpr( expr::UnaryMinus * expr )
	{
		auto op = doSubmit( expr->getOperand() );

		if ( op )
		{
			m_result = expr::makeUnaryMinus( std::move( op ) );
		}
	}

	void ExprCloner::visitUnaryPlusExpr( expr::UnaryPlus * expr )
	{
		auto op = doSubmit( expr->getOperand() );

		if ( op )
		{
			m_result = expr::makeUnaryPlus( std::move( op ) );
		}
	}

	void ExprCloner::visitXorAssignExpr( expr::XorAssign * expr )
	{
		auto lhs = doSubmit( expr->getLHS() );
		auto rhs = doSubmit( expr->getRHS() );

		if ( rhs && lhs )
		{
			m_result = expr::makeXorAssign( expr->getType()
				, std::move( lhs )
				, std::move( rhs ) );
		}
	}
}
