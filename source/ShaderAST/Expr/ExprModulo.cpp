/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprModulo.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	Modulo::Modulo( type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
		: Binary{ std::move( type )
			, std::move( lhs )
			, std::move( rhs )
			, Kind::eModulo }
	{
	}

	void Modulo::accept( VisitorPtr vis )
	{
		vis->visitModuloExpr( this );
	}
}
