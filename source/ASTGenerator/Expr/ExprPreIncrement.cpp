/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprPreIncrement.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast
{
	ExprPreIncrement::ExprPreIncrement( ExprPtr operand )
		: ExprUnary{ operand->getType(), std::move( operand ), Kind::ePreIncrement }
	{
	}

	void ExprPreIncrement::accept( ExprVisitorPtr vis )
	{
		vis->visitPreIncrementExpr( this );
	}
}
