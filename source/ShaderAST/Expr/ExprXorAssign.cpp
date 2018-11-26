/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprXorAssign.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	XorAssign::XorAssign( type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
		: Assign{ std::move( type )
			, std::move( lhs )
			, std::move( rhs )
			, Kind::eXorAssign }
	{
	}

	void XorAssign::accept( VisitorPtr vis )
	{
		vis->visitXorAssignExpr( this );
	}
}
