/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprPreIncrement.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

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
