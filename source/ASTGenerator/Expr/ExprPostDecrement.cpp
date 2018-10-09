/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprPostDecrement.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast
{
	ExprPostDecrement::ExprPostDecrement( ExprPtr operand )
		: ExprUnary{ operand->getType(), std::move( operand ), Kind::ePostDecrement }
	{
	}

	void ExprPostDecrement::accept( ExprVisitorPtr vis )
	{
		vis->visitPostDecrementExpr( this );
	}
}
