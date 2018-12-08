/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprNotEqual.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	NotEqual::NotEqual( type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
		: Binary{ std::move( type )
			, std::move( lhs )
			, std::move( rhs )
			, Kind::eNotEqual }
	{
	}

	void NotEqual::accept( VisitorPtr vis )
	{
		vis->visitNotEqualExpr( this );
	}
}
