/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprComma.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	Comma::Comma( type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
		: Binary{ std::move(type)
			, std::move( lhs )
			, std::move( rhs )
			, Kind::eComma }
	{
	}

	void Comma::accept( VisitorPtr vis )
	{
		vis->visitCommaExpr( this );
	}
}
