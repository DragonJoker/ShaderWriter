/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprBitAnd.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast
{
	ExprBitAnd::ExprBitAnd( Type type
		, ExprPtr lhs
		, ExprPtr rhs )
		: ExprBinary{ type
			, std::move( lhs )
			, std::move( rhs )
			, Expr::Kind::eBitAnd }
	{
	}

	void ExprBitAnd::accept( ExprVisitorPtr vis )
	{
		vis->visitBitAndExpr( this );
	}
}
