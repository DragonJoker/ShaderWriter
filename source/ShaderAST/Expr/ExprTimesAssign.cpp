/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprTimesAssign.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	TimesAssign::TimesAssign( ExprCache & exprCache
		, type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
		: Assign{ exprCache
			, std::move( type )
			, std::move( lhs )
			, std::move( rhs )
			, Kind::eTimesAssign }
	{
	}

	void TimesAssign::accept( VisitorPtr vis )const
	{
		vis->visitTimesAssignExpr( this );
	}
}
