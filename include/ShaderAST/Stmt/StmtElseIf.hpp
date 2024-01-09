/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtElseIf_H___
#define ___AST_StmtElseIf_H___
#pragma once

#include "StmtCompound.hpp"

#include "ShaderAST/Expr/Expr.hpp"

namespace ast::stmt
{
	class If;
	class ElseIf
		: public Compound
	{
		friend class If;
		friend class StmtCache;

	private:
		SDAST_API explicit ElseIf( StmtCache & stmtCache
			, expr::ExprPtr ctrlExpr );

	public:
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
