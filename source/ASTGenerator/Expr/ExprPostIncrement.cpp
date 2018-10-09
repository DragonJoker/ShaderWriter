/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprPostIncrement.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast
{
	ExprPostIncrement::ExprPostIncrement( ExprPtr operand )
		: ExprUnary{ operand->getType(), std::move( operand ), Kind::ePostIncrement }
	{
	}

	void ExprPostIncrement::accept( ExprVisitorPtr vis )
	{
		vis->visitPostIncrementExpr( this );
	}
}
