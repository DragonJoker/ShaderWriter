/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprIntrinsicCall_H___
#define ___AST_ExprIntrinsicCall_H___
#pragma once

#include "ExprList.hpp"
#include "ExprLiteral.hpp"

#include "EnumIntrinsic.hpp"
#include "IntrinsicCallHelpers.hpp"

namespace ast::expr
{
	class IntrinsicCall
		: public Expr
	{
	public:
		SDAST_API IntrinsicCall( type::TypePtr type
			, Intrinsic intrinsic
			, ExprList && argList );

		SDAST_API void accept( VisitorPtr vis )override;

		inline ExprList const & getArgList()const
		{
			return m_argList;
		}

		inline Intrinsic getIntrinsic()const
		{
			return m_intrinsic;
		}

	private:
		Intrinsic m_intrinsic;
		ExprList m_argList;
	};
	using IntrinsicCallPtr = std::unique_ptr< IntrinsicCall >;

	inline IntrinsicCallPtr makeIntrinsicCall( type::TypePtr type
		, Intrinsic intrinsic
		, ExprList && argList )
	{
		return std::make_unique< IntrinsicCall >( std::move( type )
			, intrinsic
			, std::move( argList ) );
	}

	template< typename ... Params >
	inline IntrinsicCallPtr makeIntrinsicCall( type::TypePtr type
		, Intrinsic intrinsic
		, Params ... args )
	{
		ExprList argList;
		helpers::fillArgsListRec( argList, std::forward< Params >( args )... );
		return makeIntrinsicCall( std::move( type )
			, intrinsic
			, std::move( argList ) );
	}

	// Shader Invocation and Memory Control Functions

	/**
	*@return
	*	void
	*@param[in] executionScope
	*	type::scope
	*@param[in] memoryScope
	*	type::scope
	*@param[in] semantics
	*	type::memorysemantics
	*/
	inline IntrinsicCallPtr makeControlBarrier( type::TypesCache & cache
		, type::Scope executionScope
		, type::Scope memoryScope
		, type::MemorySemantics semantics )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVoid )
			, Intrinsic::eControlBarrier
			, makeLiteral( cache, uint32_t( executionScope ) )
			, makeLiteral( cache, uint32_t( memoryScope ) )
			, makeLiteral( cache, uint32_t( semantics ) ) );
	}
	/**
	*@return
	*	void
	*@param[in] memoryScope
	*	type::scope
	*@param[in] semantics
	*	type::memorysemantics
	*/
	inline IntrinsicCallPtr makeMemoryBarrier( type::TypesCache & cache
		, type::Scope memoryScope
		, type::MemorySemantics semantics )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVoid )
			, Intrinsic::eMemoryBarrier
			, makeLiteral( cache, uint32_t( memoryScope ) )
			, makeLiteral( cache, uint32_t( semantics ) ) );
	}
}

#endif
