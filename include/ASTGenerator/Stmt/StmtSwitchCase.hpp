/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtSwitchCase_H___
#define ___AST_StmtSwitchCase_H___
#pragma once

#include "StmtCompound.hpp"

#include "ASTGenerator/Expr/ExprSwitchCase.hpp"

namespace ast
{
	class StmtSwitchCase
		: public StmtCompound
	{
	public:
		StmtSwitchCase( ExprSwitchCasePtr caseExpr );
		StmtSwitchCase();

		void accept( StmtVisitorPtr vis )override;

		inline ExprSwitchCase * getCaseExpr()const
		{
			return m_caseExpr.get();
		}

	private:
		ExprSwitchCasePtr m_caseExpr;
	};
	using StmtSwitchCasePtr = std::unique_ptr< StmtSwitchCase >;

	inline std::unique_ptr< StmtSwitchCase > makeSwitchCaseStmt( ExprSwitchCasePtr caseExpr )
	{
		return std::make_unique< StmtSwitchCase >( std::move( caseExpr ) );
	}

	inline std::unique_ptr< StmtSwitchCase > makeSwitchDefaultStmt()
	{
		return std::make_unique< StmtSwitchCase >();
	}
}

#endif
