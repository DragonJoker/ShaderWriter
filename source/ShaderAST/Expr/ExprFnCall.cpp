/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprFnCall.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	FnCall::FnCall( ExprCache & exprCache
		, type::TypePtr type
		, IdentifierPtr fn
		, ExprList argList )
		: FnCall{ exprCache
			, std::move( type )
			, std::move( fn )
			, nullptr
			, std::move( argList ) }
	{
	}

	FnCall::FnCall( ExprCache & exprCache
		, type::TypePtr type
		, IdentifierPtr fn
		, ExprPtr instance
		, ExprList argList )
		: Expr{ exprCache
			, sizeof( FnCall )
			, getExprTypesCache( *fn, instance, argList )
			, std::move( type )
			, Kind::eFnCall
			, ( isExprConstant( argList, fn ) ? Flag::eConstant : Flag::eNone ) }
		, m_fn{ std::move( fn ) }
		, m_argList{ std::move( argList ) }
		, m_instance{ std::move( instance ) }
	{
	}

	void FnCall::accept( VisitorPtr vis )const
	{
		vis->visitFnCallExpr( this );
	}
}
