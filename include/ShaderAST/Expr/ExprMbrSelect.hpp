/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprMbrSelect_H___
#define ___AST_ExprMbrSelect_H___
#pragma once

#include "ExprIdentifier.hpp"
#include "ExprUnary.hpp"

namespace ast::expr
{
	class MbrSelect
		: public Expr
		, public var::FlagHolder
	{
	public:
		SDAST_API MbrSelect( ExprCache & exprCache
			, ExprPtr outer
			, uint32_t memberIndex
			, uint64_t memberFlags );

		SDAST_API void accept( VisitorPtr vis )const override;

		SDAST_API type::StructPtr getOuterType()const;
		
		inline Expr const * getOuterExpr()const
		{
			return m_outer.get();
		}

		inline uint32_t getMemberIndex()const
		{
			return m_memberIndex;
		}

		//\return The variable flags for the member.
		inline uint64_t getMemberFlags()const
		{
			return var::FlagHolder::getFlags();
		}

	private:
		using var::FlagHolder::getFlags;

	private:
		ExprPtr m_outer{};
		uint32_t m_memberIndex;
	};
}

#endif
