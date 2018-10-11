/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprRShiftAssign.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	RShiftAssign::RShiftAssign( type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
		: Assign{ std::move( type )
			, std::move( lhs )
			, std::move( rhs )
			, Kind::eRShiftAssign }
	{
	}

	void RShiftAssign::accept( VisitorPtr vis )
	{
		vis->visitRShiftAssignExpr( this );
	}
}
