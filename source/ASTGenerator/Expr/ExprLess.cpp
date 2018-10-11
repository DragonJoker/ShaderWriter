/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprLess.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	Less::Less( ExprPtr lhs
		, ExprPtr rhs )
		: Binary{ std::move( type::getBool() )
			, std::move( lhs )
			, std::move( rhs )
			, Kind::eLess }
	{
	}

	void Less::accept( VisitorPtr vis )
	{
		vis->visitLessExpr( this );
	}
}
