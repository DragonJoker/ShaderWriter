/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprMinus.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

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
