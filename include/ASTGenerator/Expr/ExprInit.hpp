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

		inline ExprIdentifier const & getIdentifier()const
		{
			return *m_identifier;
		}

		inline Expr const & getInitialiser()const
		{
			return *m_initialiser;
		}

	private:
		ExprIdentifierPtr m_identifier;
		ExprPtr m_initialiser;
	};
}

#endif
