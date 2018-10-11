/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprPostIncrement.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	PostIncrement::PostIncrement( ExprPtr operand )
		: Unary{ std::move( operand->getType() )
			, std::move( operand )
			, Kind::ePostIncrement }
	{
	}

	void PostIncrement::accept( VisitorPtr vis )
	{
		vis->visitPostIncrementExpr( this );
	}
}
