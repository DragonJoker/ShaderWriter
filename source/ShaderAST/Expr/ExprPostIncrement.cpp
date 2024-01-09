/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprPostIncrement.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	PostIncrement::PostIncrement( ExprCache & exprCache
		, type::TypePtr type
		, ExprPtr operand )
		: Unary{ exprCache
			, std::move( type )
			, std::move( operand )
			, Kind::ePostIncrement }
	{
	}

	void PostIncrement::accept( VisitorPtr vis )const
	{
		vis->visitPostIncrementExpr( this );
	}
}
