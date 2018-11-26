/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprAndAssign.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

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
