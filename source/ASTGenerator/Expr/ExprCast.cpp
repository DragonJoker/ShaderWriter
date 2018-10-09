/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprCast.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast
{
	ExprCast::ExprCast( Type dstType
		, ExprPtr operand )
		: ExprUnary{ dstType
			, std::move( operand )
			, Expr::Kind::eCast }
	{
	}

	void ExprCast::accept( ExprVisitorPtr vis )
	{
		vis->visitCastExpr( this );
	}
}
