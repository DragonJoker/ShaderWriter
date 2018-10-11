/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprNotEqual.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	NotEqual::NotEqual( ExprPtr lhs
		, ExprPtr rhs )
		: Binary{ std::move( type::getBool() )
			, std::move( lhs )
			, std::move( rhs )
			, Kind::eNotEqual }
	{
	}

	void NotEqual::accept( VisitorPtr vis )
	{
		vis->visitNotEqualExpr( this );
	}
}
