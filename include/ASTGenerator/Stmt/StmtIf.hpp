/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtIf_H___
#define ___AST_StmtIf_H___
#pragma once

#include "StmtCompound.hpp"

#include "ASTGenerator/Expr/Expr.hpp"

namespace ast
{
	class StmtIf
		: public StmtCompound
	{
	public:
		StmtIf( ExprPtr ctrlExpr );

		inline Expr const & getCtrlExpr()const
		{
			return *m_ctrlExpr.get();
		}

	private:
		ExprPtr m_ctrlExpr;
	};
}

#endif
