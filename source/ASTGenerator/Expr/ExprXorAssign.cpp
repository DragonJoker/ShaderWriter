/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprXorAssign.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast
{
	ExprXorAssign::ExprXorAssign( Type type
		, ExprPtr lhs
		, ExprPtr rhs )
		: ExprAssign{ type
			, std::move( lhs )
			, std::move( rhs )
			, Expr::Kind::eXorAssign }
	{
	}

	void ExprXorAssign::accept( ExprVisitorPtr vis )
	{
		vis->visitXorAssignExpr( this );
	}
}
