/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtWhile_H___
#define ___AST_StmtWhile_H___
#pragma once

#include "StmtCompound.hpp"

#include "ASTGenerator/Expr/Expr.hpp"

namespace ast
{
	class StmtWhile
		: public StmtCompound
	{
	public:
		StmtWhile( ExprPtr ctrlExpr );

		void accept( StmtVisitorPtr vis )override;

		inline Expr const & getCtrlExpr()const
		{
			return *m_ctrlExpr.get();
		}

	private:
		ExprPtr m_ctrlExpr;
	};
}

#endif
