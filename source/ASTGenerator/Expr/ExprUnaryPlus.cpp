/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprUnaryPlus.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast
{
	ExprUnaryPlus::ExprUnaryPlus( ExprPtr operand )
		: ExprUnary{ operand->getType(), std::move( operand ), Kind::eUnaryPlus }
	{
	}

	void ExprUnaryPlus::accept( ExprVisitorPtr vis )
	{
		vis->visitUnaryPlusExpr( this );
	}
}
