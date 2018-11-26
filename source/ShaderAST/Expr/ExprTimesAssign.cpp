/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprTimesAssign.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	TimesAssign::TimesAssign( type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
		: Assign{ std::move( type )
			, std::move( lhs )
			, std::move( rhs )
			, Kind::eTimesAssign }
	{
	}

	void TimesAssign::accept( VisitorPtr vis )
	{
		vis->visitTimesAssignExpr( this );
	}
}
