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
			, IdentifierPtr member );

		void accept( VisitorPtr vis )override;

		inline Expr * getOuterExpr()const
		{
			return m_outer.get();
		}

	private:
		ExprPtr m_outer;
	};
	using MbrSelectPtr = std::unique_ptr< MbrSelect >;

	inline MbrSelectPtr makeMbrSelect( ExprPtr outer
		, IdentifierPtr member )
	{
		auto type = outer->getType();
		return std::make_unique< MbrSelect >( std::move( type )
			, std::move( outer )
			, std::move( member ) );
	}
}

#endif
