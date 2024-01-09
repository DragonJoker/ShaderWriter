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
		SDAST_API IntrinsicCall( ExprCache & exprCache
			, type::TypePtr type
			, Intrinsic intrinsic
			, ExprList argList );

		SDAST_API void accept( VisitorPtr vis )const override;

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
	SDAST_API IntrinsicCallPtr makeControlBarrier( ExprCache & exprCache
		, type::TypesCache & typesCache
		, type::Scope executionScope
		, type::Scope memoryScope
		, type::MemorySemantics semantics );
	/**
	*@return
	*	void
	*@param[in] memoryScope
	*	type::scope
	*@param[in] semantics
	*	type::memorysemantics
	*/
	SDAST_API IntrinsicCallPtr makeMemoryBarrier( ExprCache & exprCache
		, type::TypesCache & typesCache
		, type::Scope memoryScope
		, type::MemorySemantics semantics );
}

#endif
