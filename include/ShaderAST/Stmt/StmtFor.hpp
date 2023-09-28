/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtFor_H___
#define ___AST_StmtFor_H___
#pragma once

#include "StmtLoop.hpp"

#include "ShaderAST/Expr/ExprInit.hpp"

namespace ast::stmt
{
	class For
		: public Loop
	{
	public:
		SDAST_API For( StmtCache & stmtCache
			, expr::ExprPtr initExpr
			, expr::ExprPtr ctrlExpr
			, expr::ExprPtr incrExpr );

		SDAST_API void accept( VisitorPtr vis )override;

		inline expr::Expr * getInitExpr()const
		{
			return m_initExpr.get();
		}

		inline expr::Expr * getCtrlExpr()const
		{
			return m_ctrlExpr.get();
		}

		inline expr::Expr * getIncrExpr()const
		{
			return m_incrExpr.get();
		}

	private:
		expr::ExprPtr m_initExpr{};
		expr::ExprPtr m_ctrlExpr{};
		expr::ExprPtr m_incrExpr{};
	};
}

#endif
