/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprLessEqual.hpp"
#include "ASTGenerator/Type/Type.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

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
