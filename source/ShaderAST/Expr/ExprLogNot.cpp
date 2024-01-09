/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprLogNot.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	LogNot::LogNot( ExprCache & exprCache
		, type::TypePtr type
		, ExprPtr operand )
		: Unary{ exprCache
			, std::move( type )
			, std::move( operand )
			, Kind::eLogNot }
	{
	}

	void LogNot::accept( VisitorPtr vis )const
	{
		vis->visitLogNotExpr( this );
	}
}
