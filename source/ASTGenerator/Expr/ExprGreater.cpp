/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprGreater.hpp"
#include "ASTGenerator/Type/Type.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast
{
	ExprGreater::ExprGreater( ExprPtr lhs
		, ExprPtr rhs )
		: ExprBinary{ getBoolType()
			, std::move( lhs )
			, std::move( rhs )
			, Expr::Kind::eGreater }
	{
	}

	void ExprGreater::accept( ExprVisitorPtr vis )
	{
		vis->visitGreaterExpr( this );
	}
}
