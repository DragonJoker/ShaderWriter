/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprArrayAccess.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	ArrayAccess::ArrayAccess( type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
		: Binary{ std::move( type )
			, std::move( lhs )
			, std::move( rhs )
			, Kind::eArrayAccess }
	{
	}

	void ArrayAccess::accept( VisitorPtr vis )
	{
		vis->visitArrayAccessExpr( this );
	}
}
