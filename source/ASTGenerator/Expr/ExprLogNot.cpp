/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprLogNot.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast
{
	ExprLogNot::ExprLogNot( ExprPtr lhs
		, ExprPtr rhs )
		: ExprBinary{ Type::eBoolean
			, std::move( lhs )
			, std::move( rhs )
			, Expr::Kind::eLogNot }
	{
	}

	void ExprLogNot::accept( ExprVisitorPtr vis )
	{
		vis->visitLogNotExpr( this );
	}
}
