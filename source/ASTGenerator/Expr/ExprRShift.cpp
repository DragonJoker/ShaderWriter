/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprRShift.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	RShift::RShift( type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
		: Binary{ std::move( type )
			, std::move( lhs )
			, std::move( rhs )
			, Kind::eRShift }
	{
	}

	void RShift::accept( VisitorPtr vis )
	{
		vis->visitRShiftExpr( this );
	}
}
