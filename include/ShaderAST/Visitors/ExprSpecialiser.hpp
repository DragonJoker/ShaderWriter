/*
See LICENSE file in root folder
*/
#ifndef ___SDW_ExprSpecialiser_H___
#define ___SDW_ExprSpecialiser_H___
#pragma once

#include "ShaderAST/Visitors/CloneExpr.hpp"

#include <map>

namespace ast
{
	class ExprSpecialiser
		: public ExprCloner
	{
	public:
		SDAST_API static expr::ExprPtr submit( expr::ExprCache & exprCache
			, type::TypesCache & typesCache
			, expr::Expr * expr
			, std::map< var::VariablePtr, expr::LiteralPtr > const & specialisations );
		SDAST_API static expr::ExprPtr submit( expr::ExprCache & exprCache
			, type::TypesCache & typesCache
			, expr::ExprPtr const & expr
			, std::map< var::VariablePtr, expr::LiteralPtr > const & specialisations );

	private:
		SDAST_API ExprSpecialiser( expr::ExprCache & exprCache
			, type::TypesCache & typesCache
			, std::map< var::VariablePtr, expr::LiteralPtr > const & specialisations
			, expr::ExprPtr & result );

		SDAST_API expr::ExprPtr doSubmit( expr::Expr * expr )override;

		SDAST_API void visitIdentifierExpr( expr::Identifier * expr )override;

	private:
		type::TypesCache & m_typesCache;
		std::map< var::VariablePtr, expr::LiteralPtr > const & m_specialisations;
	};
}

#endif
