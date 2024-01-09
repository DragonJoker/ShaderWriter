/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprMinusAssign.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	MinusAssign::MinusAssign( ExprCache & exprCache
		, type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
		: Assign{ exprCache
			, std::move( type )
			, std::move( lhs )
			, std::move( rhs )
			, Kind::eMinusAssign }
	{
	}

	void MinusAssign::accept( VisitorPtr vis )const
	{
		vis->visitMinusAssignExpr( this );
	}
}
