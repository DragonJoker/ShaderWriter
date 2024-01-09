/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprPreIncrement.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	PreIncrement::PreIncrement( ExprCache & exprCache
		, type::TypePtr type
		, ExprPtr operand )
		: Unary{ exprCache
			, std::move( type )
			, std::move( operand )
			, Kind::ePreIncrement }
	{
	}

	void PreIncrement::accept( VisitorPtr vis )const
	{
		vis->visitPreIncrementExpr( this );
	}
}
