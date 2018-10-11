/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprPreDecrement.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	PreDecrement::PreDecrement( ExprPtr operand )
		: Unary{ std::move( operand->get() )
			, std::move( operand )
			, Kind::ePreDecrement }
	{
	}

	void PreDecrement::accept( VisitorPtr vis )
	{
		vis->visitPreDecrementExpr( this );
	}
}
