/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprAdd.hpp"
#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast
{
	ExprAdd::ExprAdd( Type type
		, ExprPtr lhs
		, ExprPtr rhs )
		: ExprBinary{ type
			, std::move( lhs )
			, std::move( rhs )
			, Expr::Kind::eAdd }
	{
	}

	void ExprAdd::accept( ExprVisitorPtr vis )
	{
		vis->visitAddExpr( this );
	}
}
