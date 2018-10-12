/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprPostIncrement.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	PostIncrement::PostIncrement( type::TypePtr type
		, ExprPtr operand )
		: Unary{ std::move( type )
			, std::move( operand )
			, Kind::ePostIncrement }
	{
	}

	void PostIncrement::accept( VisitorPtr vis )
	{
		vis->visitPostIncrementExpr( this );
	}
}
