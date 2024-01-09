/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprPostDecrement.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	PostDecrement::PostDecrement( ExprCache & exprCache
		, type::TypePtr type
		, ExprPtr operand )
		: Unary{ exprCache
			, std::move( type )
			, std::move( operand )
			, Kind::ePostDecrement }
	{
	}

	void PostDecrement::accept( VisitorPtr vis )const
	{
		vis->visitPostDecrementExpr( this );
	}
}
