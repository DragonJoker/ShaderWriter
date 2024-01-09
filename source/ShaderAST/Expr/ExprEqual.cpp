/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprEqual.hpp"
#include "ShaderAST/Type/Type.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	Equal::Equal( ExprCache & exprCache
		, type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
		: Binary{ exprCache
			, std::move( type )
			, std::move( lhs )
			, std::move( rhs )
			, Kind::eEqual }
	{
	}

	void Equal::accept( VisitorPtr vis )const
	{
		vis->visitEqualExpr( this );
	}
}
