/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprCopy.hpp"
#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	Copy::Copy( ExprCache & exprCache
		, ExprPtr op )
		: Unary{ exprCache
			, std::move( op )
			, Kind::eCopy }
	{
	}

	void Copy::accept( VisitorPtr vis )const
	{
		vis->visitCopyExpr( this );
	}
}
