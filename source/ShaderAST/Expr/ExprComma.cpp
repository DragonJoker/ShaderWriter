/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprComma.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	Comma::Comma( ExprCache & exprCache
		, type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
		: Binary{ exprCache
			, std::move(type)
			, std::move( lhs )
			, std::move( rhs )
			, Kind::eComma }
	{
	}

	void Comma::accept( VisitorPtr vis )const
	{
		vis->visitCommaExpr( this );
	}
}
