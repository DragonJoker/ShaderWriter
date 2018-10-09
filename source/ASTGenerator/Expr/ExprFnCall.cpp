/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprFnCall.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast
{
	ExprFnCall::ExprFnCall( Type type
		, ExprIdentifierPtr fn
		, ExprList argList )
		: Expr{ type, Kind::eFnCall }
		, m_fn{ std::move( fn ) }
		, m_argList{ std::move( argList ) }
	{
	}

	void ExprFnCall::accept( ExprVisitorPtr vis )
	{
		vis->visitFnCallExpr( this );
	}
}
