/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprFnCall.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	FnCall::FnCall( type::TypePtr type
		, IdentifierPtr fn
		, ExprList && argList )
		: FnCall{ std::move( type ), std::move( fn ), nullptr, std::move( argList ) }
	{
	}

	FnCall::FnCall( type::TypePtr type
		, IdentifierPtr fn
		, ExprPtr instance
		, ExprList && argList )
		: Expr{ getExprTypesCache( *fn, instance, argList ), std::move( type ), Kind::eFnCall }
		, m_fn{ std::move( fn ) }
		, m_argList{ std::move( argList ) }
		, m_instance{ std::move( instance ) }
	{
	}

	void FnCall::accept( VisitorPtr vis )
	{
		vis->visitFnCallExpr( this );
	}
}
