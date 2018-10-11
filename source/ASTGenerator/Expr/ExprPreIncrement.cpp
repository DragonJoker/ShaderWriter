/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprPreIncrement.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	PreIncrement::PreIncrement( ExprPtr operand )
		: Unary{ std::move( operand->get() )
			, std::move( operand )
			, Kind::ePreIncrement }
	{
	}

	void PreIncrement::accept( VisitorPtr vis )
	{
		vis->visitPreIncrementExpr( this );
	}
}
