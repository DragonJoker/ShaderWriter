/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprBitAnd.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	BitAnd::BitAnd( ExprCache & exprCache
		, type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
		: Binary{ exprCache
			, std::move( type )
			, std::move( lhs )
			, std::move( rhs )
			, Kind::eBitAnd }
	{
	}

	void BitAnd::accept( VisitorPtr vis )const
	{
		vis->visitBitAndExpr( this );
	}
}
