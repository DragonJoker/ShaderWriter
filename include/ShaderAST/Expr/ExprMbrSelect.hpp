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
		MbrSelect( ExprPtr outer
			, uint32_t memberIndex
			, uint32_t memberFlags );

		void accept( VisitorPtr vis )override;

		inline type::StructPtr getOuterType()const
		{
			return std::static_pointer_cast< type::Struct >( m_outer->getType() );
		}
		
		inline Expr * getOuterExpr()const
		{
			return m_outer.get();
		}

		inline uint32_t getMemberIndex()const
		{
			return m_memberIndex;
		}

		//\return The variable flags for the member.
		inline uint32_t getMemberFlags()const
		{
			return var::FlagHolder::getFlags();
		}

	private:
		using var::FlagHolder::getFlags;

	private:
		ExprPtr m_outer;
		uint32_t m_memberIndex;
	};
	using MbrSelectPtr = std::unique_ptr< MbrSelect >;

	inline MbrSelectPtr makeMbrSelect( ExprPtr outer
		, uint32_t memberIndex
		, uint32_t flags )
	{
		return std::make_unique< MbrSelect >( std::move( outer )
			, memberIndex
			, flags );
	}
}

#endif
