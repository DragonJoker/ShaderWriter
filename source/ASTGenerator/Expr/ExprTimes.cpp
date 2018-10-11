/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprTimes.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	Times::Times( type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
		: Binary{ std::move( type )
			, std::move( lhs )
			, std::move( rhs )
			, Kind::eTimes }
	{
	}

	void Times::accept( VisitorPtr vis )
	{
		vis->visitTimesExpr( this );
	}
}

