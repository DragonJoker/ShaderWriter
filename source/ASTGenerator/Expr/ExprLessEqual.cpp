/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprLessEqual.hpp"
#include "ASTGenerator/Type/Type.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast
{
	ExprLessEqual::ExprLessEqual( ExprPtr lhs
		, ExprPtr rhs )
		: ExprBinary{ getBoolType()
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
