/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprMinus.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	Minus::Minus( type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
		: Binary{ std::move( type )
			, std::move( lhs )
			, std::move( rhs )
			, Kind::eMinus }
	{
	}

	void Minus::accept( VisitorPtr vis )
	{
		vis->visitMinusExpr( this );
	}
}
