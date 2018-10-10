/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprRShift.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast
{
	ExprRShift::ExprRShift( TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
		: ExprBinary{ type
			, std::move( lhs )
			, std::move( rhs )
			, Expr::Kind::eRShift }
	{
	}

	void ExprRShift::accept( ExprVisitorPtr vis )
	{
		vis->visitRShiftExpr( this );
	}
}
