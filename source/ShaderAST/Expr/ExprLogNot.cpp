/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprLogNot.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	LogNot::LogNot( ExprPtr operand )
		: Unary{ std::move( type::getBool() )
			, std::move( operand )
			, Kind::eLogNot }
	{
	}

	void LogNot::accept( VisitorPtr vis )
	{
		vis->visitLogNotExpr( this );
	}
}
