/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprUnaryPlus.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	UnaryPlus::UnaryPlus( ExprPtr operand )
		: Unary{ std::move( operand->get() )
			, std::move( operand )
			, Kind::eUnaryPlus }
	{
	}

	void UnaryPlus::accept( VisitorPtr vis )
	{
		vis->visitUnaryPlusExpr( this );
	}
}
