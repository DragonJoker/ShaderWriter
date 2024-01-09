/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprAdd.hpp"
#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	Add::Add( ExprCache & exprCache
		, type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
		: Binary{ exprCache
			, std::move( type )
			, std::move( lhs )
			, std::move( rhs )
			, Kind::eAdd }
	{
	}

	void Add::accept( VisitorPtr vis )const
	{
		vis->visitAddExpr( this );
	}
}
