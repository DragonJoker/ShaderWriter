/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprPostDecrement.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	PostDecrement::PostDecrement( ExprPtr operand )
		: Unary{ std::move( operand->getType() )
			, std::move( operand )
			, Kind::ePostDecrement }
	{
	}

	void PostDecrement::accept( VisitorPtr vis )
	{
		vis->visitPostDecrementExpr( this );
	}
}
