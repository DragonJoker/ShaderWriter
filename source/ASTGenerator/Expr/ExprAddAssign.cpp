/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprAddAssign.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast
{
	ExprAddAssign::ExprAddAssign( TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
		: ExprAssign{ type
			, std::move( lhs )
			, std::move( rhs )
			, Expr::Kind::eAddAssign }
	{
	}

	void ExprAddAssign::accept( ExprVisitorPtr vis )
	{
		vis->visitAddAssignExpr( this );
	}
}
