/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprLogOr.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast
{
	ExprLogOr::ExprLogOr( ExprPtr lhs
		, ExprPtr rhs )
		: ExprBinary{ Type::eBoolean
			, std::move( lhs )
			, std::move( rhs )
			, Expr::Kind::eLogOr }
	{
	}

	void ExprLogOr::accept( ExprVisitorPtr vis )
	{
		vis->visitLogOrExpr( this );
	}
}
