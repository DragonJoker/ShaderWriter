/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprAssign.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast
{
	ExprAssign::ExprAssign( Type type
		, ExprPtr lhs
		, ExprPtr rhs
		, Expr::Kind kind )
		: ExprBinary{ type
			, std::move( lhs )
			, std::move( rhs )
			, kind }
	{
	}

	void ExprAssign::accept( ExprVisitorPtr vis )
	{
		vis->visitAssignExpr( this );
	}
}
