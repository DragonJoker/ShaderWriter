/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprCast.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	Cast::Cast( type::TypePtr dstType
		, ExprPtr operand )
		: Unary{ std::move( dstType )
			, std::move( operand )
			, Kind::eCast }
	{
	}

	void Cast::accept( VisitorPtr vis )
	{
		vis->visitCastExpr( this );
	}
}
