/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprPreDecrement.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	PreDecrement::PreDecrement( type::TypePtr type
		, ExprPtr operand )
		: Unary{ std::move( type )
			, std::move( operand )
			, Kind::ePreDecrement }
	{
	}

	void PreDecrement::accept( VisitorPtr vis )
	{
		vis->visitPreDecrementExpr( this );
	}
}
