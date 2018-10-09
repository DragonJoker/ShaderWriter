/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprEqual.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast
{
	ExprEqual::ExprEqual( ExprPtr lhs
		, ExprPtr rhs )
		: ExprBinary{ Type::eBoolean
			, std::move( lhs )
			, std::move( rhs )
			, Expr::Kind::eEqual }
	{
	}

	void ExprEqual::accept( ExprVisitorPtr vis )
	{
		vis->visitEqualExpr( this );
	}
}
