/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprLogOr.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	LogOr::LogOr( type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
		: Binary{ std::move( type )
			, std::move( lhs )
			, std::move( rhs )
			, Kind::eLogOr }
	{
	}

	void LogOr::accept( VisitorPtr vis )
	{
		vis->visitLogOrExpr( this );
	}
}
