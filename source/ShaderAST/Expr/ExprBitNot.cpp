/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprBitNot.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	BitNot::BitNot( type::TypePtr type
		, ExprPtr operand )
		: Unary{ std::move( type )
			, std::move( operand )
			, Kind::eBitNot }
	{
	}

	void BitNot::accept( VisitorPtr vis )
	{
		vis->visitBitNotExpr( this );
	}
}
