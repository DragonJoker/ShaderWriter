/*
See LICENSE file in root folder
*/
#ifndef ___SDW_GlslExprAdapter_H___
#define ___SDW_GlslExprAdapter_H___
#pragma once

#include "ShaderWriter/Visitors/CloneExpr.hpp"

namespace sdw
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

		ast::expr::ExprPtr doSubmit( ast::expr::Expr * expr )override;

		void visitIdentifierExpr( ast::expr::Identifier * expr )override;

	private:
		std::map< var::VariablePtr, expr::LiteralPtr > const & m_specialisations;
	};
}

#endif
