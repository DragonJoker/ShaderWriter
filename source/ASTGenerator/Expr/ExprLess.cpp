/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprLess.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast
{
	ExprLess::ExprLess( ExprPtr lhs
		, ExprPtr rhs )
		: ExprBinary{ getBoolType()
			, std::move( lhs )
			, std::move( rhs )
			, Expr::Kind::eLess }
	{
	}

	void ExprLess::accept( ExprVisitorPtr vis )
	{
		vis->visitLessExpr( this );
	}
}
