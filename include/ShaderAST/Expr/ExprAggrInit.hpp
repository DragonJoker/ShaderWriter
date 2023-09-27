/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprAggrInit_H___
#define ___AST_ExprAggrInit_H___
#pragma once

#include "ExprIdentifier.hpp"
#include "ExprList.hpp"

namespace ast::expr
{
	class AggrInit
		: public Expr
	{
	public:
		SDAST_API AggrInit( ExprCache & exprCache
			, IdentifierPtr identifier
			, ExprList initialisers );
		SDAST_API AggrInit( ExprCache & exprCache
			, type::TypePtr type
			, ExprList initialisers );

		SDAST_API void accept( VisitorPtr vis )override;

		inline Identifier * getIdentifier()const
		{
			return m_identifier.get();
		}

		inline ExprList const & getInitialisers()const
		{
			return m_initialisers;
		}

	private:
		IdentifierPtr m_identifier{};
		ExprList m_initialisers;
	};
}

#endif
