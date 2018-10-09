/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprLogXor.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast
{
	ExprLogXor::ExprLogXor( ExprPtr lhs
		, ExprPtr rhs )
		: ExprBinary{ Type::eBoolean
			, std::move( lhs )
			, std::move( rhs )
			, Expr::Kind::eLogXor }
	{
	}

	void ExprLogXor::accept( ExprVisitorPtr vis )
	{
		vis->visitLogXorExpr( this );
	}
}
