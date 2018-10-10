/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprTimes.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast
{
	ExprTimes::ExprTimes( TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
		: ExprBinary{ type
			, std::move( lhs )
			, std::move( rhs )
			, Expr::Kind::eTimes }
	{
	}

	void ExprTimes::accept( ExprVisitorPtr vis )
	{
		vis->visitTimesExpr( this );
	}
}

