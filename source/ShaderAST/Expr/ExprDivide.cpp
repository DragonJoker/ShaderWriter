/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprDivide.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	Divide::Divide( ExprCache & exprCache
		, type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
		: Binary{ exprCache
			, std::move( type )
			, std::move( lhs )
			, std::move( rhs )
			, Kind::eDivide }
	{
	}

	void Divide::accept( VisitorPtr vis )const
	{
		vis->visitDivideExpr( this );
	}
}
