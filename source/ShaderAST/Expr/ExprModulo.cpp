/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprModulo.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	Modulo::Modulo( ExprCache & exprCache
		, type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
		: Binary{ exprCache
			, std::move( type )
			, std::move( lhs )
			, std::move( rhs )
			, Kind::eModulo }
	{
	}

	void Modulo::accept( VisitorPtr vis )const
	{
		vis->visitModuloExpr( this );
	}
}
