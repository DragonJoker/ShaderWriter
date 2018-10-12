/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprPostDecrement.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	PostDecrement::PostDecrement( type::TypePtr type
		, ExprPtr operand )
		: Unary{ std::move( type )
			, std::move( operand )
			, Kind::ePostDecrement }
	{
	}

	void PostDecrement::accept( VisitorPtr vis )
	{
		vis->visitPostDecrementExpr( this );
	}
}
