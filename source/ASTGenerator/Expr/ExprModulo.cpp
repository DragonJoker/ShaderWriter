/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprModulo.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast
{
	ExprModulo::ExprModulo( TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
		: ExprBinary{ type
			, std::move( lhs )
			, std::move( rhs )
			, Kind::eModulo }
	{
	}

	void ExprModulo::accept( ExprVisitorPtr vis )
	{
		vis->visitModuloExpr( this );
	}
}
