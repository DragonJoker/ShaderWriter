/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprRShiftAssign.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast
{
	ExprRShiftAssign::ExprRShiftAssign( TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
		: ExprAssign{ type
			, std::move( lhs )
			, std::move( rhs )
			, Expr::Kind::eRShiftAssign }
	{
	}

	void ExprRShiftAssign::accept( ExprVisitorPtr vis )
	{
		vis->visitRShiftAssignExpr( this );
	}
}
