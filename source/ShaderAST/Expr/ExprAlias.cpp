/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprAlias.hpp"
#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	Alias::Alias( ExprCache & exprCache
		, type::TypePtr type
		, IdentifierPtr lhs
		, ExprPtr rhs )
		: Binary{ exprCache
			, std::move( type )
			, std::move( lhs )
			, std::move( rhs )
			, Kind::eAlias }
	{
	}

	void Alias::accept( VisitorPtr vis )const
	{
		vis->visitAliasExpr( this );
	}
}
