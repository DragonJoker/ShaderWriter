/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprAndAssign.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	AndAssign::AndAssign( type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
		: Assign{ std::move( type )
			, std::move( lhs )
			, std::move( rhs )
			, Kind::eAndAssign }
	{
	}

	void AndAssign::accept( VisitorPtr vis )
	{
		vis->visitAndAssignExpr( this );
	}
}
