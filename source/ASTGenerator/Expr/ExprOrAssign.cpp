/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprOrAssign.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast
{
	ExprOrAssign::ExprOrAssign( TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
		: ExprAssign{ type
			, std::move( lhs )
			, std::move( rhs )
			, Expr::Kind::eOrAssign }
	{
	}

	void ExprOrAssign::accept( ExprVisitorPtr vis )
	{
		vis->visitOrAssignExpr( this );
	}
}
