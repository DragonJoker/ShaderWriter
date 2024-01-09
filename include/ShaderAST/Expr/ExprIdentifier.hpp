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
		SDAST_API Identifier( ExprCache & exprCache
			, type::TypesCache & typesCache
			, var::VariablePtr var );
		SDAST_API Identifier( ExprCache & exprCache
			, Identifier const & rhs );

		SDAST_API void accept( VisitorPtr vis )const override;

		inline var::VariablePtr getVariable()const
		{
			return m_var;
		}

	private:
		var::VariablePtr m_var;
	};
}

#endif
