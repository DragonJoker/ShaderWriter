/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprPreDecrement.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast
{
	ExprPreDecrement::ExprPreDecrement( ExprPtr operand )
		: ExprUnary{ operand->getType(), std::move( operand ), Kind::ePreDecrement }
	{
	}

	void ExprPreDecrement::accept( ExprVisitorPtr vis )
	{
		vis->visitPreDecrementExpr( this );
	}
}
