/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprMinus.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast
{
	ExprMinus::ExprMinus( TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
		: ExprBinary{ type
			, std::move( lhs )
			, std::move( rhs )
			, Expr::Kind::eMinus }
	{
	}

	void ExprMinus::accept( ExprVisitorPtr vis )
	{
		vis->visitMinusExpr( this );
	}
}
