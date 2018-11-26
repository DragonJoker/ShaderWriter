/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprLessEqual.hpp"
#include "ShaderAST/Type/Type.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	LessEqual::LessEqual( ExprPtr lhs
		, ExprPtr rhs )
		: Binary{ std::move( type::getBool() )
			, std::move( lhs )
			, std::move( rhs )
			, Kind::eLessEqual }
	{
	}

	void LessEqual::accept( VisitorPtr vis )
	{
		vis->visitLessEqualExpr( this );
	}
}
