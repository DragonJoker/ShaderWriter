/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprBitOr.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast
{
	ExprBitOr::ExprBitOr( Type type
		, ExprPtr lhs
		, ExprPtr rhs )
		: ExprBinary{ type
			, std::move( lhs )
			, std::move( rhs )
			, Expr::Kind::eBitOr }
	{
	}

	void ExprBitOr::accept( ExprVisitorPtr vis )
	{
		vis->visitBitOrExpr( this );
	}
}
