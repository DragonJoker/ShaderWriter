/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprGreaterEqual.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	GreaterEqual::GreaterEqual( ExprCache & exprCache
		, type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
		: Binary{ exprCache
			, std::move( type )
			, std::move( lhs )
			, std::move( rhs )
			, Kind::eGreaterEqual }
	{
	}

	void GreaterEqual::accept( VisitorPtr vis )const
	{
		vis->visitGreaterEqualExpr( this );
	}
}
