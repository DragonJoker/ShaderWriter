/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprAndAssign.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast
{
	ExprAndAssign::ExprAndAssign( Type type
		, ExprPtr lhs
		, ExprPtr rhs )
		: ExprAssign{ type
			, std::move( lhs )
			, std::move( rhs )
			, Expr::Kind::eAndAssign }
	{
	}

	void ExprAndAssign::accept( ExprVisitorPtr vis )
	{
		vis->visitAndAssignExpr( this );
	}
}
