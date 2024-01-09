/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprInit_H___
#define ___AST_ExprInit_H___
#pragma once

#include "ExprIdentifier.hpp"

namespace ast::expr
{
	class Init
		: public Expr
	{
	public:
		SDAST_API Init( ExprCache & exprCache
			, IdentifierPtr identifier
			, ExprPtr initialiser );

		SDAST_API void accept( VisitorPtr vis )const override;

		bool hasIdentifier()const noexcept
		{
			return m_identifier != nullptr;
		}

		Identifier const & getIdentifier()const noexcept
		{
			assert( hasIdentifier() );
			return *m_identifier;
		}

		inline Expr const * getInitialiser()const noexcept
		{
			return m_initialiser.get();
		}

	private:
		IdentifierPtr m_identifier{};
		ExprPtr m_initialiser{};
	};
}

#endif
