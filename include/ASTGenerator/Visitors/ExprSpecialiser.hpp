/*
See LICENSE file in root folder
*/
#ifndef ___SDW_GlslExprAdapter_H___
#define ___SDW_GlslExprAdapter_H___
#pragma once

#include "ASTGenerator/Visitors/CloneExpr.hpp"

#include <map>

namespace ast
{
	class ExprSpecialiser
		: public ExprCloner
	{
	public:
		static expr::ExprPtr submit( expr::Expr * expr
			, std::map< var::VariablePtr, expr::LiteralPtr > const & specialisations );
		static expr::ExprPtr submit( expr::ExprPtr const & expr
			, std::map< var::VariablePtr, expr::LiteralPtr > const & specialisations );

	private:
		ExprSpecialiser( expr::ExprPtr & result
			, std::map< var::VariablePtr, expr::LiteralPtr > const & specialisations );

		expr::ExprPtr doSubmit( expr::Expr * expr )override;

		void visitIdentifierExpr( expr::Identifier * expr )override;

	private:
		std::map< var::VariablePtr, expr::LiteralPtr > const & m_specialisations;
	};
}

#endif
