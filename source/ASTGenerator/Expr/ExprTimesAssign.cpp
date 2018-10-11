/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprTimesAssign.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	TimesAssign::TimesAssign( type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
		: Assign{ std::move( type )
			, std::move( lhs )
			, std::move( rhs )
			, Kind::eTimesAssign }
	{
	}

	void TimesAssign::accept( VisitorPtr vis )
	{
		vis->visitTimesAssignExpr( this );
	}
}
