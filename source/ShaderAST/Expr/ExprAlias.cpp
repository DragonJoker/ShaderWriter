/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprAlias.hpp"
#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	Alias::Alias( type::TypePtr type
		, IdentifierPtr lhs
		, ExprPtr rhs )
		: Binary{ std::move( type )
			, std::move( lhs )
			, std::move( rhs )
			, Kind::eAlias }
	{
	}

	void Alias::accept( VisitorPtr vis )
	{
		vis->visitAliasExpr( this );
	}
}
