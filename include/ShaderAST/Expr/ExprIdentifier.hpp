/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprIdentifier_H___
#define ___AST_ExprIdentifier_H___
#pragma once

#include "Expr.hpp"

namespace ast::expr
{
	class Identifier
		: public Expr
	{
	public:
		SDAST_API Identifier( type::TypesCache & cache
			, var::VariablePtr var );

		SDAST_API void accept( VisitorPtr vis )override;

		inline var::VariablePtr getVariable()const
		{
			return m_var;
		}

	private:
		var::VariablePtr m_var;
	};
	using IdentifierPtr = std::unique_ptr< Identifier >;

	inline IdentifierPtr makeIdentifier( type::TypesCache & cache
		, var::VariablePtr var )
	{
		return std::make_unique< Identifier >( cache
			, std::move( var ) );
	}
}

#endif
