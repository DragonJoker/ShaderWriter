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
		SDAST_API Init( IdentifierPtr identifier
			, ExprPtr initialiser );

		SDAST_API void accept( VisitorPtr vis )override;

		inline Identifier * getIdentifier()const
		{
			return m_identifier.get();
		}

		inline Expr * getInitialiser()const
		{
			return m_initialiser.get();
		}

	private:
		IdentifierPtr m_identifier;
		ExprPtr m_initialiser;
	};
	using InitPtr = std::unique_ptr< Init >;

	inline InitPtr makeInit( IdentifierPtr identifier
		, ExprPtr initialiser )
	{
		return std::make_unique< Init >( std::move( identifier )
			, std::move( initialiser ) );
	}
}

#endif
