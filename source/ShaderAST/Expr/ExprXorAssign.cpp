/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprXorAssign.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	XorAssign::XorAssign( ExprCache & exprCache
		, type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
		: Assign{ exprCache
			, std::move( type )
			, std::move( lhs )
			, std::move( rhs )
			, Kind::eXorAssign }
	{
	}

	void XorAssign::accept( VisitorPtr vis )const
	{
		vis->visitXorAssignExpr( this );
	}
}
