/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprBitNot.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast
{
	ExprBitNot::ExprBitNot( Type type
		, ExprPtr lhs
		, ExprPtr rhs )
		: ExprBinary{ type
			, std::move( lhs )
			, std::move( rhs )
			, Expr::Kind::eBitNot }
	{
	}

	void ExprBitNot::accept( ExprVisitorPtr vis )
	{
		vis->visitBitNotExpr( this );
	}
}
