/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprDivide.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast
{
	ExprDivide::ExprDivide( Type type
		, ExprPtr lhs
		, ExprPtr rhs )
		: ExprBinary{ type
			, std::move( lhs )
			, std::move( rhs )
			, Expr::Kind::eDivide }
	{
	}

	void ExprDivide::accept( ExprVisitorPtr vis )
	{
		vis->visitDivideExpr( this );
	}
}
