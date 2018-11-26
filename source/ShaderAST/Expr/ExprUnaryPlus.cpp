/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprUnaryPlus.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	UnaryPlus::UnaryPlus( type::TypePtr type
		, ExprPtr operand )
		: Unary{ std::move( type )
			, std::move( operand )
			, Kind::eUnaryPlus }
	{
	}

	void UnaryPlus::accept( VisitorPtr vis )
	{
		vis->visitUnaryPlusExpr( this );
	}
}
