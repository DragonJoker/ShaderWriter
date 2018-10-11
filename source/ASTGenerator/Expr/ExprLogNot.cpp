/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprLogNot.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

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
