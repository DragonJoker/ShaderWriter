/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtIf_H___
#define ___AST_StmtIf_H___
#pragma once

#include "StmtElse.hpp"
#include "StmtElseIf.hpp"

#include "ShaderAST/Expr/Expr.hpp"

namespace ast::stmt
{
	class If
		: public Compound
	{
	public:
		SDAST_API explicit If( StmtCache & stmtCache
			, expr::ExprPtr ctrlExpr );

		SDAST_API Else * createElse();
		SDAST_API ElseIf * createElseIf( expr::ExprPtr ctrlExpr );

		SDAST_API void accept( VisitorPtr vis )const override;

		inline expr::Expr const * getCtrlExpr()const noexcept
		{
			return m_ctrlExpr.get();
		}

		inline Else const * getElse()const noexcept
		{
			return m_else.get();
		}

		inline ElseIfList const & getElseIfList()const noexcept
		{
			return m_elseIfs;
		}

	private:
		expr::ExprPtr m_ctrlExpr{};
		ElsePtr m_else;
		ElseIfList m_elseIfs;
	};
}

#endif
