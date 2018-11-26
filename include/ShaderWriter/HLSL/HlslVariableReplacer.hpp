/*
See LICENSE file in root folder
*/
#ifndef ___AST_HlslVariableReplacer_H___
#define ___AST_HlslVariableReplacer_H___
#pragma once

#include <ASTGenerator/Visitors/CloneExpr.hpp>

namespace sdw::hlsl
{
	class VariableReplacer
		: public ExprCloner
	{
	public:
		static expr::ExprPtr submit( expr::Expr * expr
			, var::VariablePtr origin
			, var::VariablePtr replacement );
		static expr::ExprPtr submit( expr::ExprPtr const & expr
			, var::VariablePtr origin
			, var::VariablePtr replacement );                       

	private:
		VariableReplacer( expr::ExprPtr & result
			, var::VariablePtr origin
			, var::VariablePtr replacement );

		ast::expr::ExprPtr doSubmit( ast::expr::Expr * expr )override;
		void visitIdentifierExpr( expr::Identifier * expr )override;

	private:
		var::VariablePtr m_origin;
		var::VariablePtr m_replacement;
	};
}

#endif
