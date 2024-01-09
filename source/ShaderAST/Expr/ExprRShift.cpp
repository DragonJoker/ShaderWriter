/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprRShift.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	RShift::RShift( ExprCache & exprCache
		, type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
		: Binary{ exprCache
			, std::move( type )
			, std::move( lhs )
			, std::move( rhs )
			, Kind::eRShift }
	{
	}

	void RShift::accept( VisitorPtr vis )const
	{
		vis->visitRShiftExpr( this );
	}
}
