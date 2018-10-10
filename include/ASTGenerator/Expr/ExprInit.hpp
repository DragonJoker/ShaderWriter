/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprInit_H___
#define ___AST_ExprInit_H___
#pragma once

#include "ExprIdentifier.hpp"

namespace ast
{
	class ExprInit
		: public Expr
	{
	public:
		ExprInit( ExprIdentifierPtr identifier
			, ExprPtr initialiser );

		void accept( ExprVisitorPtr vis )override;

		inline ExprIdentifier * getIdentifier()const
		{
			return m_identifier.get();
		}

		inline Expr * getInitialiser()const
		{
			return m_initialiser.get();
		}

	private:
		ExprIdentifierPtr m_identifier;
		ExprPtr m_initialiser;
	};
	using ExprInitPtr = std::unique_ptr< ExprInit >;

	inline ExprInitPtr makeInitExpr( ExprIdentifierPtr identifier
		, ExprPtr initialiser )
	{
		return std::make_unique< ExprInit >( std::move( identifier )
			, std::move( initialiser ) );
	}
}

#endif
