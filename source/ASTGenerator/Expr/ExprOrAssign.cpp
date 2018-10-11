/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprOrAssign.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	OrAssign::OrAssign( type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
		: Assign{ std::move( type )
			, std::move( lhs )
			, std::move( rhs )
			, Kind::eOrAssign }
	{
	}

	void OrAssign::accept( VisitorPtr vis )
	{
		vis->visitOrAssignExpr( this );
	}
}
