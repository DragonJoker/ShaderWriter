/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtElseIf_H___
#define ___AST_StmtElseIf_H___
#pragma once

#include "StmtCompound.hpp"

#include "ASTGenerator/Expr/Expr.hpp"

namespace ast
{
	class StmtIf;
	class StmtElseIf
		: public StmtCompound
	{
	public:
		StmtElseIf( StmtIf const & ifStmt
			, ExprPtr ctrlExpr );

		void accept( StmtVisitorPtr vis )override;

		inline Expr * getCtrlExpr()const
		{
			return m_ctrlExpr.get();
		}

	private:
		StmtIf const & m_ifStmt;
		ExprPtr m_ctrlExpr;
	};

	inline std::unique_ptr< StmtElseIf > makeElseIfStmt( StmtIf const & ifStmt
		, ExprPtr ctrlExpr )
	{
		return std::make_unique< StmtElseIf >( ifStmt
			, std::move( ctrlExpr ) );
	}
}

#endif
