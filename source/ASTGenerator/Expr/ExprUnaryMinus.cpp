/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprUnaryMinus.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast
{
	ExprUnaryMinus::ExprUnaryMinus( ExprPtr operand )
		: ExprUnary{ operand->getType(), std::move( operand ), Kind::eUnaryMinus }
	{
	}

	void ExprUnaryMinus::accept( ExprVisitorPtr vis )
	{
		vis->visitUnaryMinusExpr( this );
	}
}
