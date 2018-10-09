/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprModuloAssign.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast
{
	ExprModuloAssign::ExprModuloAssign( Type type
		, ExprPtr lhs
		, ExprPtr rhs )
		: ExprAssign{ type
			, std::move( lhs )
			, std::move( rhs )
			, Expr::Kind::eModuloAssign }
	{
	}

	void ExprModuloAssign::accept( ExprVisitorPtr vis )
	{
		vis->visitModuloAssignExpr( this );
	}
}
