/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprComma.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast
{
	ExprComma::ExprComma( ExprPtr lhs
		, ExprPtr rhs )
		: ExprBinary{ rhs->getType()
			, std::move( lhs )
			, std::move( rhs )
			, Expr::Kind::eComma }
	{
	}

	void ExprComma::accept( ExprVisitorPtr vis )
	{
		vis->visitCommaExpr( this );
	}
}
