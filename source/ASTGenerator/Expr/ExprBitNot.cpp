/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprBitNot.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

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
