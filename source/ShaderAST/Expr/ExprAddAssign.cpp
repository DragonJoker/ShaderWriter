/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprAddAssign.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	AddAssign::AddAssign( type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
		: Assign{ std::move( type )
			, std::move( lhs )
			, std::move( rhs )
			, Kind::eAddAssign }
	{
	}

	void AddAssign::accept( VisitorPtr vis )
	{
		vis->visitAddAssignExpr( this );
	}
}
