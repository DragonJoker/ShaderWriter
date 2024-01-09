/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprAddAssign.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	AddAssign::AddAssign( ExprCache & exprCache
		, type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
		: Assign{ exprCache
			, std::move( type )
			, std::move( lhs )
			, std::move( rhs )
			, Kind::eAddAssign }
	{
	}

	void AddAssign::accept( VisitorPtr vis )const
	{
		vis->visitAddAssignExpr( this );
	}
}
