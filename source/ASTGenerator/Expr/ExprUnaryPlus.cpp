/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprUnaryPlus.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast
{
	ExprUnaryPlus::ExprUnaryPlus( Type type
		, ExprPtr operand )
		: ExprUnary{ type, std::move( operand ), Kind::eUnaryPlus }
	{
	}

	void ExprUnaryPlus::accept( ExprVisitorPtr vis )
	{
		vis->visitUnaryPlusExpr( this );
	}
}
