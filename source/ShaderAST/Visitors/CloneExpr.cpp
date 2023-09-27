/*
See LICENSE file in root folder
*/
#include "ShaderAST/Visitors/CloneExpr.hpp"

#include "ShaderAST/Expr/ExprCache.hpp"

namespace ast
{
	expr::ExprPtr ExprCloner::submit( expr::ExprCache & exprCache
		, expr::Expr * expr )
	{
		if ( !expr )
		{
			return nullptr;
		}

		if ( expr->isDummy() )
		{
			return exprCache.makeDummyExpr( expr->getType() );
		}

		expr::ExprPtr result{};
		ExprCloner vis{ exprCache, result };
		expr->accept( &vis );

		if ( expr->isNonUniform() )
		{
			result->updateFlag( ast::expr::Flag::eNonUniform );
		}

		return result;
	}

	expr::ExprPtr ExprCloner::submit( expr::ExprCache & exprCache
		, expr::ExprPtr const & expr )
	{
		if ( expr )
		{
			return submit( exprCache, expr.get() );
		}

		return nullptr;
	}

	ExprCloner::ExprCloner( expr::ExprCache & exprCache
		, expr::ExprPtr & result )
		: m_exprCache{ exprCache }
		, m_result{ result }
	{
	}

	expr::ExprPtr ExprCloner::doSubmit( expr::Expr * expr )
	{
		if ( expr )
		{
			return submit( m_exprCache, expr );
		}

		return nullptr;
	}

	expr::ExprPtr ExprCloner::doSubmit( expr::ExprPtr const & expr )
	{
		return doSubmit( expr.get() );
	}

	void ExprCloner::visitAddExpr( expr::Add * expr )
	{
		TraceFunc
		auto lhs = doSubmit( expr->getLHS() );
		auto rhs = doSubmit( expr->getRHS() );

		if ( rhs && lhs )
		{
			m_result = m_exprCache.makeAdd( expr->getType()
				, std::move( lhs )
				, std::move( rhs ) );
		}
	}

	void ExprCloner::visitAddAssignExpr( expr::AddAssign * expr )
	{
		TraceFunc
		auto lhs = doSubmit( expr->getLHS() );
		auto rhs = doSubmit( expr->getRHS() );

		if ( rhs && lhs )
		{
			m_result = m_exprCache.makeAddAssign( expr->getType()
				, std::move( lhs )
				, std::move( rhs ) );
		}
	}

	void ExprCloner::visitAggrInitExpr( expr::AggrInit * expr )
	{
		TraceFunc
		expr::ExprList initialisers;

		for ( auto & init : expr->getInitialisers() )
		{
			initialisers.emplace_back( doSubmit( init ) );
		}

		if ( expr->getIdentifier() )
		{
			m_result = m_exprCache.makeAggrInit( m_exprCache.makeIdentifier( *expr->getIdentifier() )
				, std::move( initialisers ) );
		}
		else
		{
			m_result = m_exprCache.makeAggrInit( expr->getType()
				, std::move( initialisers ) );
		}
	}

	void ExprCloner::visitAliasExpr( expr::Alias * expr )
	{
		TraceFunc
		auto rhs = doSubmit( expr->getRHS() );

		if ( rhs )
		{
			m_result = m_exprCache.makeAlias( expr->getType()
				, m_exprCache.makeIdentifier( static_cast< expr::Identifier const & >( *expr->getLHS() ) )
				, std::move( rhs ) );
		}
	}

	void ExprCloner::visitAndAssignExpr( expr::AndAssign * expr )
	{
		TraceFunc
		auto lhs = doSubmit( expr->getLHS() );
		auto rhs = doSubmit( expr->getRHS() );

		if ( rhs && lhs )
		{
			m_result = m_exprCache.makeAndAssign( expr->getType()
				, std::move( lhs )
				, std::move( rhs ) );
		}
	}

	void ExprCloner::visitArrayAccessExpr( expr::ArrayAccess * expr )
	{
		TraceFunc
		auto lhs = doSubmit( expr->getLHS() );
		auto rhs = doSubmit( expr->getRHS() );

		if ( rhs && lhs )
		{
			m_result = m_exprCache.makeArrayAccess( expr->getType()
				, std::move( lhs )
				, std::move( rhs ) );
		}
	}

	void ExprCloner::visitAssignExpr( expr::Assign * expr )
	{
		TraceFunc
		auto lhs = doSubmit( expr->getLHS() );
		auto rhs = doSubmit( expr->getRHS() );

		if ( rhs && lhs )
		{
			m_result = m_exprCache.makeAssign( expr->getType()
				, std::move( lhs )
				, std::move( rhs ) );
		}
	}

	void ExprCloner::visitBitAndExpr( expr::BitAnd * expr )
	{
		TraceFunc
		auto lhs = doSubmit( expr->getLHS() );
		auto rhs = doSubmit( expr->getRHS() );

		if ( rhs && lhs )
		{
			m_result = m_exprCache.makeBitAnd( expr->getType()
				, std::move( lhs )
				, std::move( rhs ) );
		}
	}

	void ExprCloner::visitBitNotExpr( expr::BitNot * expr )
	{
		TraceFunc
		auto op = doSubmit( expr->getOperand() );

		if ( op )
		{
			m_result = m_exprCache.makeBitNot( std::move( op ) );
		}
	}

	void ExprCloner::visitBitOrExpr( expr::BitOr * expr )
	{
		TraceFunc
		auto lhs = doSubmit( expr->getLHS() );
		auto rhs = doSubmit( expr->getRHS() );

		if ( rhs && lhs )
		{
			m_result = m_exprCache.makeBitOr( expr->getType()
				, std::move( lhs )
				, std::move( rhs ) );
		}
	}

	void ExprCloner::visitBitXorExpr( expr::BitXor * expr )
	{
		TraceFunc
		auto lhs = doSubmit( expr->getLHS() );
		auto rhs = doSubmit( expr->getRHS() );

		if ( rhs && lhs )
		{
			m_result = m_exprCache.makeBitXor( expr->getType()
				, std::move( lhs )
				, std::move( rhs ) );
		}
	}

	void ExprCloner::visitCastExpr( expr::Cast * expr )
	{
		TraceFunc
		auto op = doSubmit( expr->getOperand() );

		if ( op )
		{
			m_result = m_exprCache.makeCast( expr->getType()
				, std::move( op ) );
		}
	}

	void ExprCloner::visitCommaExpr( expr::Comma * expr )
	{
		TraceFunc
		auto lhs = doSubmit( expr->getLHS() );
		auto rhs = doSubmit( expr->getRHS() );

		if ( rhs && lhs )
		{
			m_result = m_exprCache.makeComma( std::move( lhs )
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
		TraceFunc
		expr::ExprList args;

		for ( auto & arg : expr->getArgList() )
		{
			args.emplace_back( doSubmit( arg ) );
		}

		if ( expr->getComposite() == expr::CompositeType::eCombine )
		{
			m_result = m_exprCache.makeCompositeConstruct( std::move( args.front() )
				, std::move( args.back() ) );
		}
		else
		{
			m_result = m_exprCache.makeCompositeConstruct( expr->getComposite()
				, expr->getComponent()
				, std::move( args ) );
		}
	}

	void ExprCloner::visitCopyExpr( expr::Copy * expr )
	{
		TraceFunc
		auto op = doSubmit( expr->getOperand() );

		if ( op )
		{
			m_result = m_exprCache.makeCopy( std::move( op ) );
		}
	}

	void ExprCloner::visitDivideExpr( expr::Divide * expr )
	{
		TraceFunc
		auto lhs = doSubmit( expr->getLHS() );
		auto rhs = doSubmit( expr->getRHS() );

		if ( rhs && lhs )
		{
			m_result = m_exprCache.makeDivide( expr->getType()
				, std::move( lhs )
				, std::move( rhs ) );
		}
	}

	void ExprCloner::visitDivideAssignExpr( expr::DivideAssign * expr )
	{
		TraceFunc
		auto lhs = doSubmit( expr->getLHS() );
		auto rhs = doSubmit( expr->getRHS() );

		if ( rhs && lhs )
		{
			m_result = m_exprCache.makeDivideAssign( expr->getType()
				, std::move( lhs )
				, std::move( rhs ) );
		}
	}

	void ExprCloner::visitEqualExpr( expr::Equal * expr )
	{
		TraceFunc
		auto lhs = doSubmit( expr->getLHS() );
		auto rhs = doSubmit( expr->getRHS() );

		if ( rhs && lhs )
		{
			m_result = m_exprCache.makeEqual( expr->getType()
				, std::move( lhs )
				, std::move( rhs ) );
		}
	}

	void ExprCloner::visitFnCallExpr( expr::FnCall * expr )
	{
		TraceFunc
		expr::ExprList args;

		for ( auto & arg : expr->getArgList() )
		{
			args.emplace_back( doSubmit( arg ) );
		}

		if ( expr->isMember() )
		{
			m_result = m_exprCache.makeMemberFnCall( expr->getType()
				, m_exprCache.makeIdentifier( *expr->getFn() )
				, doSubmit( expr->getInstance() )
				, std::move( args ) );
		}
		else
		{
			m_result = m_exprCache.makeFnCall( expr->getType()
				, m_exprCache.makeIdentifier( *expr->getFn() )
				, std::move( args ) );
		}
	}

	void ExprCloner::visitGreaterExpr( expr::Greater * expr )
	{
		TraceFunc
		auto lhs = doSubmit( expr->getLHS() );
		auto rhs = doSubmit( expr->getRHS() );

		if ( rhs && lhs )
		{
			m_result = m_exprCache.makeGreater( expr->getType()
				, std::move( lhs )
				, std::move( rhs ) );
		}
	}

	void ExprCloner::visitGreaterEqualExpr( expr::GreaterEqual * expr )
	{
		TraceFunc
		auto lhs = doSubmit( expr->getLHS() );
		auto rhs = doSubmit( expr->getRHS() );

		if ( rhs && lhs )
		{
			m_result = m_exprCache.makeGreaterEqual( expr->getType()
				, std::move( lhs )
				, std::move( rhs ) );
		}
	}

	void ExprCloner::visitIdentifierExpr( expr::Identifier * expr )
	{
		TraceFunc
		m_result = m_exprCache.makeIdentifier( expr->getTypesCache(), expr->getVariable() );
	}

	void ExprCloner::visitImageAccessCallExpr( expr::StorageImageAccessCall * expr )
	{
		TraceFunc
		expr::ExprList args;

		for ( auto & arg : expr->getArgList() )
		{
			args.emplace_back( doSubmit( arg ) );
		}

		m_result = m_exprCache.makeStorageImageAccessCall( expr->getType()
			, expr->getImageAccess()
			, std::move( args ) );
	}

	void ExprCloner::visitInitExpr( expr::Init * expr )
	{
		TraceFunc
		m_result = m_exprCache.makeInit( m_exprCache.makeIdentifier( *expr->getIdentifier() )
			, doSubmit( expr->getInitialiser() ) );
	}

	void ExprCloner::visitIntrinsicCallExpr( expr::IntrinsicCall * expr )
	{
		TraceFunc
		expr::ExprList args;

		for ( auto & arg : expr->getArgList() )
		{
			args.emplace_back( doSubmit( arg ) );
		}

		m_result = m_exprCache.makeIntrinsicCall( expr->getType()
			, expr->getIntrinsic()
			, std::move( args ) );
	}

	void ExprCloner::visitLessExpr( expr::Less * expr )
	{
		TraceFunc
		auto lhs = doSubmit( expr->getLHS() );
		auto rhs = doSubmit( expr->getRHS() );

		if ( rhs && lhs )
		{
			m_result = m_exprCache.makeLess( expr->getType()
				, std::move( lhs )
				, std::move( rhs ) );
		}
	}

	void ExprCloner::visitLessEqualExpr( expr::LessEqual * expr )
	{
		TraceFunc
		auto lhs = doSubmit( expr->getLHS() );
		auto rhs = doSubmit( expr->getRHS() );

		if ( rhs && lhs )
		{
			m_result = m_exprCache.makeLessEqual( expr->getType()
				, std::move( lhs )
				, std::move( rhs ) );
		}
	}

	void ExprCloner::visitLiteralExpr( expr::Literal * expr )
	{
		TraceFunc
		m_result = m_exprCache.makeLiteral( *expr );
	}

	void ExprCloner::visitLogAndExpr( expr::LogAnd * expr )
	{
		TraceFunc
		auto lhs = doSubmit( expr->getLHS() );
		auto rhs = doSubmit( expr->getRHS() );

		if ( rhs && lhs )
		{
			m_result = m_exprCache.makeLogAnd( expr->getType()
				, std::move( lhs )
				, std::move( rhs ) );
		}
	}

	void ExprCloner::visitLogNotExpr( expr::LogNot * expr )
	{
		TraceFunc
		auto op = doSubmit( expr->getOperand() );

		if ( op )
		{
			m_result = m_exprCache.makeLogNot( expr->getType()
				, std::move( op ) );
		}
	}

	void ExprCloner::visitLogOrExpr( expr::LogOr * expr )
	{
		TraceFunc
		auto lhs = doSubmit( expr->getLHS() );
		auto rhs = doSubmit( expr->getRHS() );

		if ( rhs && lhs )
		{
			m_result = m_exprCache.makeLogOr( expr->getType()
				, std::move( lhs )
				, std::move( rhs ) );
		}
	}

	void ExprCloner::visitLShiftExpr( expr::LShift * expr )
	{
		TraceFunc
		auto lhs = doSubmit( expr->getLHS() );
		auto rhs = doSubmit( expr->getRHS() );

		if ( rhs && lhs )
		{
			m_result = m_exprCache.makeLShift( expr->getType()
				, std::move( lhs )
				, std::move( rhs ) );
		}
	}

	void ExprCloner::visitLShiftAssignExpr( expr::LShiftAssign * expr )
	{
		TraceFunc
		auto lhs = doSubmit( expr->getLHS() );
		auto rhs = doSubmit( expr->getRHS() );

		if ( rhs && lhs )
		{
			m_result = m_exprCache.makeLShiftAssign( expr->getType()
				, std::move( lhs )
				, std::move( rhs ) );
		}
	}

	void ExprCloner::visitMbrSelectExpr( expr::MbrSelect * expr )
	{
		TraceFunc
		m_result = m_exprCache.makeMbrSelect( doSubmit( expr->getOuterExpr() )
			, expr->getMemberIndex()
			, expr->getMemberFlags() );
	}

	void ExprCloner::visitMinusExpr( expr::Minus * expr )
	{
		TraceFunc
		auto lhs = doSubmit( expr->getLHS() );
		auto rhs = doSubmit( expr->getRHS() );

		if ( rhs && lhs )
		{
			m_result = m_exprCache.makeMinus( expr->getType()
				, std::move( lhs )
				, std::move( rhs ) );
		}
	}

	void ExprCloner::visitMinusAssignExpr( expr::MinusAssign * expr )
	{
		TraceFunc
		auto lhs = doSubmit( expr->getLHS() );
		auto rhs = doSubmit( expr->getRHS() );

		if ( rhs && lhs )
		{
			m_result = m_exprCache.makeMinusAssign( expr->getType()
				, std::move( lhs )
				, std::move( rhs ) );
		}
	}

	void ExprCloner::visitModuloExpr( expr::Modulo * expr )
	{
		TraceFunc
		auto lhs = doSubmit( expr->getLHS() );
		auto rhs = doSubmit( expr->getRHS() );

		if ( rhs && lhs )
		{
			m_result = m_exprCache.makeModulo( expr->getType()
				, std::move( lhs )
				, std::move( rhs ) );
		}
	}

	void ExprCloner::visitModuloAssignExpr( expr::ModuloAssign * expr )
	{
		TraceFunc
		auto lhs = doSubmit( expr->getLHS() );
		auto rhs = doSubmit( expr->getRHS() );

		if ( rhs && lhs )
		{
			m_result = m_exprCache.makeModuloAssign( expr->getType()
				, std::move( lhs )
				, std::move( rhs ) );
		}
	}

	void ExprCloner::visitNotEqualExpr( expr::NotEqual * expr )
	{
		TraceFunc
		auto lhs = doSubmit( expr->getLHS() );
		auto rhs = doSubmit( expr->getRHS() );

		if ( rhs && lhs )
		{
			m_result = m_exprCache.makeNotEqual( expr->getType()->getTypesCache()
				, std::move( lhs )
				, std::move( rhs ) );
		}
	}

	void ExprCloner::visitOrAssignExpr( expr::OrAssign * expr )
	{
		TraceFunc
		auto lhs = doSubmit( expr->getLHS() );
		auto rhs = doSubmit( expr->getRHS() );

		if ( rhs && lhs )
		{
			m_result = m_exprCache.makeOrAssign( expr->getType()
				, std::move( lhs )
				, std::move( rhs ) );
		}
	}

	void ExprCloner::visitPostDecrementExpr( expr::PostDecrement * expr )
	{
		TraceFunc
		auto op = doSubmit( expr->getOperand() );

		if ( op )
		{
			m_result = m_exprCache.makePostDecrement( std::move( op ) );
		}
	}

	void ExprCloner::visitPostIncrementExpr( expr::PostIncrement * expr )
	{
		TraceFunc
		auto op = doSubmit( expr->getOperand() );

		if ( op )
		{
			m_result = m_exprCache.makePostIncrement( std::move( op ) );
		}
	}

	void ExprCloner::visitPreDecrementExpr( expr::PreDecrement * expr )
	{
		TraceFunc
		auto op = doSubmit( expr->getOperand() );

		if ( op )
		{
			m_result = m_exprCache.makePreDecrement( std::move( op ) );
		}
	}

	void ExprCloner::visitPreIncrementExpr( expr::PreIncrement * expr )
	{
		TraceFunc
		auto op = doSubmit( expr->getOperand() );

		if ( op )
		{
			m_result = m_exprCache.makePreIncrement( std::move( op ) );
		}
	}

	void ExprCloner::visitQuestionExpr( expr::Question * expr )
	{
		TraceFunc
		m_result = m_exprCache.makeQuestion( expr->getType()
			, doSubmit( expr->getCtrlExpr() )
			, doSubmit( expr->getTrueExpr() )
			, doSubmit( expr->getFalseExpr() ) );
	}

	void ExprCloner::visitRShiftExpr( expr::RShift * expr )
	{
		TraceFunc
		auto lhs = doSubmit( expr->getLHS() );
		auto rhs = doSubmit( expr->getRHS() );

		if ( rhs && lhs )
		{
			m_result = m_exprCache.makeRShift( expr->getType()
				, std::move( lhs )
				, std::move( rhs ) );
		}
	}

	void ExprCloner::visitRShiftAssignExpr( expr::RShiftAssign * expr )
	{
		TraceFunc
		auto lhs = doSubmit( expr->getLHS() );
		auto rhs = doSubmit( expr->getRHS() );

		if ( rhs && lhs )
		{
			m_result = m_exprCache.makeRShiftAssign( expr->getType()
				, std::move( lhs )
				, std::move( rhs ) );
		}
	}

	void ExprCloner::visitStreamAppendExpr( expr::StreamAppend * expr )
	{
		TraceFunc
		auto op = doSubmit( expr->getOperand() );

		if ( op )
		{
			m_result = m_exprCache.makeStreamAppend( std::move( op ) );
		}
	}

	void ExprCloner::visitSwitchCaseExpr( expr::SwitchCase * expr )
	{
		TraceFunc
		m_result = m_exprCache.makeSwitchCase( m_exprCache.makeLiteral( *expr->getLabel() ) );
	}

	void ExprCloner::visitSwitchTestExpr( expr::SwitchTest * expr )
	{
		TraceFunc
		m_result = m_exprCache.makeSwitchTest( doSubmit( expr->getValue() ) );
	}

	void ExprCloner::visitSwizzleExpr( expr::Swizzle * expr )
	{
		TraceFunc
		m_result = m_exprCache.makeSwizzle( doSubmit( expr->getOuterExpr() )
			, expr->getSwizzle() );
	}

	void ExprCloner::visitCombinedImageAccessCallExpr( expr::CombinedImageAccessCall * expr )
	{
		TraceFunc
		expr::ExprList args;

		for ( auto & arg : expr->getArgList() )
		{
			args.emplace_back( doSubmit( arg ) );
		}

		m_result = m_exprCache.makeCombinedImageAccessCall( expr->getType()
			, expr->getCombinedImageAccess()
			, std::move( args ) );
	}

	void ExprCloner::visitTimesExpr( expr::Times * expr )
	{
		TraceFunc
		auto lhs = doSubmit( expr->getLHS() );
		auto rhs = doSubmit( expr->getRHS() );

		if ( rhs && lhs )
		{
			m_result = m_exprCache.makeTimes( expr->getType()
				, std::move( lhs )
				, std::move( rhs ) );
		}
	}

	void ExprCloner::visitTimesAssignExpr( expr::TimesAssign * expr )
	{
		TraceFunc
		auto lhs = doSubmit( expr->getLHS() );
		auto rhs = doSubmit( expr->getRHS() );

		if ( rhs && lhs )
		{
			m_result = m_exprCache.makeTimesAssign( expr->getType()
				, std::move( lhs )
				, std::move( rhs ) );
		}
	}

	void ExprCloner::visitUnaryMinusExpr( expr::UnaryMinus * expr )
	{
		TraceFunc
		auto op = doSubmit( expr->getOperand() );

		if ( op )
		{
			m_result = m_exprCache.makeUnaryMinus( std::move( op ) );
		}
	}

	void ExprCloner::visitUnaryPlusExpr( expr::UnaryPlus * expr )
	{
		TraceFunc
		auto op = doSubmit( expr->getOperand() );

		if ( op )
		{
			m_result = m_exprCache.makeUnaryPlus( std::move( op ) );
		}
	}

	void ExprCloner::visitXorAssignExpr( expr::XorAssign * expr )
	{
		TraceFunc
		auto lhs = doSubmit( expr->getLHS() );
		auto rhs = doSubmit( expr->getRHS() );

		if ( rhs && lhs )
		{
			m_result = m_exprCache.makeXorAssign( expr->getType()
				, std::move( lhs )
				, std::move( rhs ) );
		}
	}
}
