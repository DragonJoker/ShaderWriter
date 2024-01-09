/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtWhile_H___
#define ___AST_StmtWhile_H___
#pragma once

#include "StmtLoop.hpp"

#include "ShaderAST/Expr/Expr.hpp"

namespace ast::stmt
{
	class While
		: public Loop
	{
	public:
		SDAST_API explicit While( StmtCache & stmtCache
			, expr::ExprPtr ctrlExpr );

		SDAST_API void accept( VisitorPtr vis )const override;

		inline expr::Expr const * getCtrlExpr()const
		{
			return m_ctrlExpr.get();
		}

	private:
		expr::ExprPtr m_ctrlExpr{};
	};
}

#endif
