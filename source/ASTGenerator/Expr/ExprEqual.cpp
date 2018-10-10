/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprEqual.hpp"
#include "ASTGenerator/Type/Type.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast
{
	ExprEqual::ExprEqual( ExprPtr lhs
		, ExprPtr rhs )
		: ExprBinary{ getBoolType()
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
