/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprDivideAssign.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast
{
	ExprDivideAssign::ExprDivideAssign( TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
		: ExprAssign{ type
			, std::move( lhs )
			, std::move( rhs )
			, Expr::Kind::eDivideAssign }
	{
	}

	void ExprDivideAssign::accept( ExprVisitorPtr vis )
	{
		vis->visitDivideAssignExpr( this );
	}
}
