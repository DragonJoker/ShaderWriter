/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprPreDecrement.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	PreDecrement::PreDecrement( ExprCache & exprCache
		, type::TypePtr type
		, ExprPtr operand )
		: Unary{ exprCache
			, std::move( type )
			, std::move( operand )
			, Kind::ePreDecrement }
	{
	}

	void PreDecrement::accept( VisitorPtr vis )const
	{
		vis->visitPreDecrementExpr( this );
	}
}
