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
		: public Unary
	{
	public:
		MbrSelect( type::TypePtr type
			, ExprPtr outer
			, uint32_t memberIndex
			, IdentifierPtr member );

		void accept( VisitorPtr vis )override;

		inline Expr * getOuterExpr()const
		{
			return m_outer.get();
		}

		inline Identifier * getMember()const
		{
			return static_cast< Identifier * >( getOperand() );
		}

		inline uint32_t getMemberIndex()const
		{
			return m_memberIndex;
		}

	private:
		ExprPtr m_outer;
		uint32_t m_memberIndex;
	};
	using MbrSelectPtr = std::unique_ptr< MbrSelect >;

	inline MbrSelectPtr makeMbrSelect( ExprPtr outer
		, uint32_t memberIndex
		, IdentifierPtr member )
	{
		auto type = member->getType();
		return std::make_unique< MbrSelect >( std::move( type )
			, std::move( outer )
			, memberIndex
			, std::move( member ) );
	}
}

#endif
