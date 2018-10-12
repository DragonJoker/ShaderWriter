/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprPreIncrement.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	PreIncrement::PreIncrement( type::TypePtr type
		, ExprPtr operand )
		: Unary{ std::move( type )
			, std::move( operand )
			, Kind::ePreIncrement }
	{
	}

	void PreIncrement::accept( VisitorPtr vis )
	{
		vis->visitPreIncrementExpr( this );
	}
}
