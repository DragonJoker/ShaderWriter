/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprDivideAssign.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	DivideAssign::DivideAssign( type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
		: Assign{ std::move( type )
			, std::move( lhs )
			, std::move( rhs )
			, Kind::eDivideAssign }
	{
	}

	void DivideAssign::accept( VisitorPtr vis )
	{
		vis->visitDivideAssignExpr( this );
	}
}
