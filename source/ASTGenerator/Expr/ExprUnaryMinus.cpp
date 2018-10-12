/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprUnaryMinus.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	UnaryMinus::UnaryMinus( type::TypePtr type
		, ExprPtr operand )
		: Unary{ std::move( type )
			, std::move( operand )
			, Kind::eUnaryMinus }
	{
	}

	void UnaryMinus::accept( VisitorPtr vis )
	{
		vis->visitUnaryMinusExpr( this );
	}
}
