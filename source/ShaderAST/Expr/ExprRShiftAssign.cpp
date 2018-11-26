/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprRShiftAssign.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

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
