/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprLess.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

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
