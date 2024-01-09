/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprAssign.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	Assign::Assign( ExprCache & exprCache
		, type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs
		, Kind kind )
		: Binary{ exprCache
			, std::move( type )
			, std::move( lhs )
			, std::move( rhs )
			, kind }
	{
	}

	void Assign::accept( VisitorPtr vis )const
	{
		vis->visitAssignExpr( this );
	}
}
