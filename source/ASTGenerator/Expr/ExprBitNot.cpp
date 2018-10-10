/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprBitNot.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast
{
	ExprBitNot::ExprBitNot( Type type
		, ExprPtr operand )
		: ExprUnary{ type
			, std::move( operand )
			, Expr::Kind::eBitNot }
	{
	}

	void ExprBitNot::accept( ExprVisitorPtr vis )
	{
		vis->visitBitNotExpr( this );
	}
}
