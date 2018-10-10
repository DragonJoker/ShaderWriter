/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtIf_H___
#define ___AST_StmtIf_H___
#pragma once

#include "StmtElse.hpp"
#include "StmtElseIf.hpp"

#include "ASTGenerator/Expr/Expr.hpp"

namespace ast
{
	class StmtIf
		: public StmtCompound
	{
	public:
		StmtIf( ExprPtr ctrlExpr );

		StmtElse * createElse();
		StmtElseIf * createElseIf( ExprPtr ctrlExpr );

		void accept( StmtVisitorPtr vis )override;

		inline Expr * getCtrlExpr()const
		{
			return m_ctrlExpr.get();
		}

		inline StmtElse * getElse()
		{
			return m_else.get();
		}

		inline StmtList const & getElseIfList()
		{
			return m_elseIfs;
		}

	private:
		ExprPtr m_ctrlExpr;
		std::unique_ptr< StmtElse > m_else;
		StmtList m_elseIfs;
	};

	inline std::unique_ptr< StmtIf > makeIfStmt( ExprPtr ctrlExpr )
	{
		return std::make_unique< StmtIf >( std::move( ctrlExpr ) );
	}
}

#endif
