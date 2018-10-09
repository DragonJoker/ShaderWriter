/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprMinusAssign.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast
{
	ExprMinusAssign::ExprMinusAssign( Type type
		, ExprPtr lhs
		, ExprPtr rhs )
		: ExprAssign{ type
			, std::move( lhs )
			, std::move( rhs )
			, Expr::Kind::eMinusAssign }
	{
	}

	void ExprMinusAssign::accept( ExprVisitorPtr vis )
	{
		vis->visitMinusAssignExpr( this );
	}
}
