/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprLessEqual.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast
{
	ExprLessEqual::ExprLessEqual( ExprPtr lhs
		, ExprPtr rhs )
		: ExprBinary{ Type::eBoolean
			, std::move( lhs )
			, std::move( rhs )
			, Expr::Kind::eLessEqual }
	{
	}

	void ExprLessEqual::accept( ExprVisitorPtr vis )
	{
		vis->visitLessEqualExpr( this );
	}
}
