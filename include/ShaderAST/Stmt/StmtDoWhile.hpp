/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtDoWhile_H___
#define ___AST_StmtDoWhile_H___
#pragma once

#include "StmtLoop.hpp"

#include "ShaderAST/Expr/Expr.hpp"

namespace ast::stmt
{
	class DoWhile
		: public Loop
	{
	public:
		SDAST_API explicit DoWhile( StmtCache & stmtCache
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
