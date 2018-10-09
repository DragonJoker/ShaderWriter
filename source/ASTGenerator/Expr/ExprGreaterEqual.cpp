/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprGreaterEqual.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast
{
	ExprGreaterEqual::ExprGreaterEqual( ExprPtr lhs
		, ExprPtr rhs )
		: ExprBinary{ Type::eBoolean
			, std::move( lhs )
			, std::move( rhs )
			, Expr::Kind::eGreaterEqual }
	{
	}

	void ExprGreaterEqual::accept( ExprVisitorPtr vis )
	{
		vis->visitGreaterEqualExpr( this );
	}
}
