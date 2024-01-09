/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprBitNot.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	BitNot::BitNot( ExprCache & exprCache
		, type::TypePtr type
		, ExprPtr operand )
		: Unary{ exprCache
			, std::move( type )
			, std::move( operand )
			, Kind::eBitNot }
	{
	}

	void BitNot::accept( VisitorPtr vis )const
	{
		vis->visitBitNotExpr( this );
	}
}
