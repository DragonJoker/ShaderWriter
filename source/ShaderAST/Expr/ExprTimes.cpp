/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprTimes.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	Times::Times( ExprCache & exprCache
		, type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
		: Binary{ exprCache
			, std::move( type )
			, std::move( lhs )
			, std::move( rhs )
			, Kind::eTimes }
	{
	}

	void Times::accept( VisitorPtr vis )const
	{
		vis->visitTimesExpr( this );
	}
}

