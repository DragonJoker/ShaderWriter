/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprGreaterEqual.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

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
