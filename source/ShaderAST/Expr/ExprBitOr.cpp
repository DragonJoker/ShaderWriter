/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprBitOr.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	BitOr::BitOr( ExprCache & exprCache
		, type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
		: Binary{ exprCache
			, std::move( type )
			, std::move( lhs )
			, std::move( rhs )
			, Kind::eBitOr }
	{
	}

	void BitOr::accept( VisitorPtr vis )const
	{
		vis->visitBitOrExpr( this );
	}
}
