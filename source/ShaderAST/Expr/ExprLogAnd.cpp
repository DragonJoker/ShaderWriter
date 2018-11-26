/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprLogAnd.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	LogAnd::LogAnd( ExprPtr lhs
		, ExprPtr rhs )
		: Binary{ std::move( type::getBool() )
			, std::move( lhs )
			, std::move( rhs )
			, Kind::eLogAnd }
	{
	}

	void LogAnd::accept( VisitorPtr vis )
	{
		vis->visitLogAndExpr( this );
	}
}
