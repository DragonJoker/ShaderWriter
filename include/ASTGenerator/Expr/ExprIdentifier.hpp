/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprIdentifier_H___
#define ___AST_ExprIdentifier_H___
#pragma once

#include "Expr.hpp"

namespace ast
{
	class ExprIdentifier
		: public Expr
	{
	public:
		ExprIdentifier( VariablePtr var );

		void accept( ExprVisitorPtr vis )override;

		inline VariablePtr getVariable()const
		{
			return m_var;
		}

	private:
		VariablePtr m_var;
	};
	using ExprIdentifierPtr = std::unique_ptr< ExprIdentifier >;

	inline ExprIdentifierPtr makeIdentifierExpr( VariablePtr var )
	{
		return std::make_unique< ExprIdentifier >( std::move( var ) );
	}
}

#endif
