/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprBitXor.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	BitXor::BitXor( ExprCache & exprCache
		, type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
		: Binary{ exprCache
			, std::move( type )
			, std::move( lhs )
			, std::move( rhs )
			, Kind::eBitXor }
	{
	}

	void BitXor::accept( VisitorPtr vis )const
	{
		vis->visitBitXorExpr( this );
	}
}
