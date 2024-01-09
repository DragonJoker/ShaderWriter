/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprGreater.hpp"
#include "ShaderAST/Type/Type.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	Greater::Greater( ExprCache & exprCache
		, type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
		: Binary{ exprCache
			, std::move( type )
			, std::move( lhs )
			, std::move( rhs )
			, Kind::eGreater }
	{
	}

	void Greater::accept( VisitorPtr vis )const
	{
		vis->visitGreaterExpr( this );
	}
}
