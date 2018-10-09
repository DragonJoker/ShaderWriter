/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprNotEqual.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast
{
	ExprNotEqual::ExprNotEqual( ExprPtr lhs
		, ExprPtr rhs )
		: ExprBinary{ Type::eBoolean
			, std::move( lhs )
			, std::move( rhs )
			, Expr::Kind::eNotEqual }
	{
	}

	void ExprNotEqual::accept( ExprVisitorPtr vis )
	{
		vis->visitNotEqualExpr( this );
	}
}
