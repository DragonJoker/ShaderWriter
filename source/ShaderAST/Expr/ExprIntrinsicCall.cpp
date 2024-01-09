/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprIntrinsicCall.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	IntrinsicCall::IntrinsicCall( ExprCache & exprCache
		, type::TypePtr type
		, Intrinsic intrinsic
		, ExprList argList )
		: Expr{ exprCache
			, sizeof( IntrinsicCall )
			, type->getTypesCache()
			, type
			, Kind::eIntrinsicCall, Flag::eNone }
		, m_intrinsic{ intrinsic }
		, m_argList{ std::move( argList ) }
	{
	}

	void IntrinsicCall::accept( VisitorPtr vis )const
	{
		vis->visitIntrinsicCallExpr( this );
	}

	IntrinsicCallPtr makeControlBarrier( ExprCache & exprCache
		, type::TypesCache & typesCache
		, type::Scope executionScope
		, type::Scope memoryScope
		, type::MemorySemantics semantics )
	{
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVoid )
			, Intrinsic::eControlBarrier
			, exprCache.makeLiteral( typesCache, uint32_t( executionScope ) )
			, exprCache.makeLiteral( typesCache, uint32_t( memoryScope ) )
			, exprCache.makeLiteral( typesCache, uint32_t( semantics ) ) );
	}

	IntrinsicCallPtr makeMemoryBarrier( ExprCache & exprCache
		, type::TypesCache & typesCache
		, type::Scope memoryScope
		, type::MemorySemantics semantics )
	{
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVoid )
			, Intrinsic::eMemoryBarrier
			, exprCache.makeLiteral( typesCache, uint32_t( memoryScope ) )
			, exprCache.makeLiteral( typesCache, uint32_t( semantics ) ) );
	}
}
