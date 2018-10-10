/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprLogAnd.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast
{
	ExprLogAnd::ExprLogAnd( ExprPtr lhs
		, ExprPtr rhs )
		: ExprBinary{ getBoolType()
			, std::move( lhs )
			, std::move( rhs )
			, Expr::Kind::eLogAnd }
	{
	}

	void ExprLogAnd::accept( ExprVisitorPtr vis )
	{
		vis->visitLogAndExpr( this );
	}
}
