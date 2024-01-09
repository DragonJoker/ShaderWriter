/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprDivideAssign.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	DivideAssign::DivideAssign( ExprCache & exprCache
		, type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
		: Assign{ exprCache
			, std::move( type )
			, std::move( lhs )
			, std::move( rhs )
			, Kind::eDivideAssign }
	{
	}

	void DivideAssign::accept( VisitorPtr vis )const
	{
		vis->visitDivideAssignExpr( this );
	}
}
