/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprGreaterEqual.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	GreaterEqual::GreaterEqual( ExprPtr lhs
		, ExprPtr rhs )
		: Binary{ std::move( type::getBool() )
			, std::move( lhs )
			, std::move( rhs )
			, Kind::eGreaterEqual }
	{
	}

	void GreaterEqual::accept( VisitorPtr vis )
	{
		vis->visitGreaterEqualExpr( this );
	}
}
