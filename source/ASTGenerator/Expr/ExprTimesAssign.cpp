/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprTimesAssign.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast
{
	ExprTimesAssign::ExprTimesAssign( TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
		: ExprAssign{ type
			, std::move( lhs )
			, std::move( rhs )
			, Expr::Kind::eTimesAssign }
	{
	}

	void ExprTimesAssign::accept( ExprVisitorPtr vis )
	{
		vis->visitTimesAssignExpr( this );
	}
}
