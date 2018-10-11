/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprFnCall.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	FnCall::FnCall( type::TypePtr type
		, IdentifierPtr fn
		, ExprList && argList )
		: Expr{ std::move( type ), Kind::eFnCall }
		, m_fn{ std::move( fn ) }
		, m_argList{ std::move( argList ) }
	{
	}

	void FnCall::accept( VisitorPtr vis )
	{
		vis->visitFnCallExpr( this );
	}
}
