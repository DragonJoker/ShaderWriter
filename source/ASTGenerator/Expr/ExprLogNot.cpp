/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprLogNot.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast
{
	ExprLogNot::ExprLogNot( ExprPtr operand )
		: ExprUnary{ getBoolType()
			, std::move( operand )
			, Expr::Kind::eLogNot }
	{
	}

	void ExprLogNot::accept( ExprVisitorPtr vis )
	{
		vis->visitLogNotExpr( this );
	}
}
