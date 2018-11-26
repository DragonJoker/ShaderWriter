/*
See LICENSE file in root folder
*/
#ifndef ___AST_HlslVariableReplacer_H___
#define ___AST_HlslVariableReplacer_H___
#pragma once

#include <ShaderAST/Visitors/CloneExpr.hpp>

namespace hlsl
{
	class VariableReplacer
		: public ast::ExprCloner
	{
	public:
		static ast::expr::ExprPtr submit( ast::expr::Expr * expr
			, ast::var::VariablePtr origin
			, ast::var::VariablePtr replacement );
		static ast::expr::ExprPtr submit( ast::expr::ExprPtr const & expr
			, ast::var::VariablePtr origin
			, ast::var::VariablePtr replacement );                       

	private:
		VariableReplacer( ast::expr::ExprPtr & result
			, ast::var::VariablePtr origin
			, ast::var::VariablePtr replacement );

		ast::expr::ExprPtr doSubmit( ast::expr::Expr * expr )override;
		void visitIdentifierExpr( ast::expr::Identifier * expr )override;

	private:
		ast::var::VariablePtr m_origin;
		ast::var::VariablePtr m_replacement;
	};
}

#endif
