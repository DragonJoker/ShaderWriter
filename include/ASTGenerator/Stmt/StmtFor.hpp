/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtFor_H___
#define ___AST_StmtFor_H___
#pragma once

#include "StmtCompound.hpp"

#include "ASTGenerator/Expr/Expr.hpp"

namespace ast
{
	class StmtFor
		: public StmtCompound
	{
	public:
		StmtFor( ExprPtr initExpr
			, ExprPtr ctrlExpr
			, ExprPtr incrExpr );

		inline Expr const & getInitExpr()const
		{
			return *m_initExpr.get();
		}

		inline Expr const & getCtrlExpr()const
		{
			return *m_ctrlExpr.get();
		}

		inline Expr const & getIncrExpr()const
		{
			return *m_incrExpr.get();
		}

	private:
		ExprPtr m_initExpr;
		ExprPtr m_ctrlExpr;
		ExprPtr m_incrExpr;
	};
}

#endif
