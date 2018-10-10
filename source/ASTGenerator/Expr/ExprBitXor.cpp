/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprBitXor.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast
{
	ExprBitXor::ExprBitXor( TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
		: ExprBinary{ type
			, std::move( lhs )
			, std::move( rhs )
			, Expr::Kind::eBitXor }
	{
	}

	void ExprBitXor::accept( ExprVisitorPtr vis )
	{
		vis->visitBitXorExpr( this );
	}
}
