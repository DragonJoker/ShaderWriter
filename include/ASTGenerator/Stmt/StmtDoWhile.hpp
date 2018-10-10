/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtDoWhile_H___
#define ___AST_StmtDoWhile_H___
#pragma once

#include "StmtCompound.hpp"

#include "ASTGenerator/Expr/Expr.hpp"

namespace ast
{
	class StmtDoWhile
		: public StmtCompound
	{
	public:
		StmtDoWhile( ExprPtr ctrlExpr );

		void accept( StmtVisitorPtr vis )override;

		inline Expr * getCtrlExpr()const
		{
			return m_ctrlExpr.get();
		}

	private:
		ExprPtr m_ctrlExpr;
	};

	inline std::unique_ptr< StmtDoWhile > makeDoWhileStmt( ExprPtr ctrlExpr )
	{
		return std::make_unique< StmtDoWhile >( std::move( ctrlExpr ) );
	}
}

#endif
