/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprLogOr.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	LogOr::LogOr( ExprCache & exprCache
		, type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
		: Binary{ exprCache
			, std::move( type )
			, std::move( lhs )
			, std::move( rhs )
			, Kind::eLogOr }
	{
	}

	void LogOr::accept( VisitorPtr vis )const
	{
		vis->visitLogOrExpr( this );
	}
}
