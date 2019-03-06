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
		static expr::ExprPtr submit( type::TypesCache & cache
			, expr::Expr * expr
			, std::map< var::VariablePtr, expr::LiteralPtr > const & specialisations );
		static expr::ExprPtr submit( type::TypesCache & cache
			, expr::ExprPtr const & expr
			, std::map< var::VariablePtr, expr::LiteralPtr > const & specialisations );

	private:
		ExprSpecialiser( type::TypesCache & cache
			, std::map< var::VariablePtr, expr::LiteralPtr > const & specialisations
			, expr::ExprPtr & result );

		expr::ExprPtr doSubmit( expr::Expr * expr )override;

		void visitIdentifierExpr( expr::Identifier * expr )override;

	private:
		type::TypesCache & m_cache;
		std::map< var::VariablePtr, expr::LiteralPtr > const & m_specialisations;
	};
}

#endif
