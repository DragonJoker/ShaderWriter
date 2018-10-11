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
		AggrInit( IdentifierPtr identifier
			, ExprList && initialisers );

		void accept( VisitorPtr vis )override;

		inline Identifier * getIdentifier()const
		{
			return m_identifier.get();
		}

		inline ExprList const & getInitialisers()const
		{
			return m_initialisers;
		}

	private:
		IdentifierPtr m_identifier;
		ExprList m_initialisers;
	};
	using AggrInitPtr = std::unique_ptr< AggrInit >;

	inline AggrInitPtr makeAggrInit( IdentifierPtr identifier
		, ExprList && initialisers )
	{
		return std::make_unique< AggrInit >( std::move( identifier )
			, std::move( initialisers ) );
	}
}

#endif
