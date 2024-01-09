/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprUnaryPlus.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	UnaryPlus::UnaryPlus( ExprCache & exprCache
		, type::TypePtr type
		, ExprPtr operand )
		: Unary{ exprCache
			, std::move( type )
			, std::move( operand )
			, Kind::eUnaryPlus }
	{
	}

	void UnaryPlus::accept( VisitorPtr vis )const
	{
		vis->visitUnaryPlusExpr( this );
	}
}
