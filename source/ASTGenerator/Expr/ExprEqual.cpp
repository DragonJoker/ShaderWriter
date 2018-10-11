/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprEqual.hpp"
#include "ASTGenerator/Type/Type.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	Equal::Equal( ExprPtr lhs
		, ExprPtr rhs )
		: Binary{ std::move( type::getBool() )
			, std::move( lhs )
			, std::move( rhs )
			, Kind::eEqual }
	{
	}

	void Equal::accept( VisitorPtr vis )
	{
		vis->visitEqualExpr( this );
	}
}
