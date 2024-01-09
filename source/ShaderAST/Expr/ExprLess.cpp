/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprLess.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	Less::Less( ExprCache & exprCache
		, type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
		: Binary{ exprCache
			, std::move( type )
			, std::move( lhs )
			, std::move( rhs )
			, Kind::eLess }
	{
	}

	void Less::accept( VisitorPtr vis )const
	{
		vis->visitLessExpr( this );
	}
}
