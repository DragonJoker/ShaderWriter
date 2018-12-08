/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprLogNot.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	LogNot::LogNot( type::TypePtr type
		, ExprPtr operand )
		: Unary{ std::move( type )
			, std::move( operand )
			, Kind::eLogNot }
	{
	}

	void LogNot::accept( VisitorPtr vis )
	{
		vis->visitLogNotExpr( this );
	}
}
