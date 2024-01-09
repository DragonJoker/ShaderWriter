/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprUnaryMinus.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	UnaryMinus::UnaryMinus( ExprCache & exprCache
		, type::TypePtr type
		, ExprPtr operand )
		: Unary{ exprCache
			, std::move( type )
			, std::move( operand )
			, Kind::eUnaryMinus }
	{
	}

	void UnaryMinus::accept( VisitorPtr vis )const
	{
		vis->visitUnaryMinusExpr( this );
	}
}
