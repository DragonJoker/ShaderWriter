/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprModuloAssign.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	ModuloAssign::ModuloAssign( ExprCache & exprCache
		, type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
		: Assign{ exprCache
			, std::move( type )
			, std::move( lhs )
			, std::move( rhs )
			, Kind::eModuloAssign }
	{
	}

	void ModuloAssign::accept( VisitorPtr vis )const
	{
		vis->visitModuloAssignExpr( this );
	}
}
