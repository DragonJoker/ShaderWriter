/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtSwitch_H___
#define ___AST_StmtSwitch_H___
#pragma once

#include "StmtCompound.hpp"

#include "StmtSwitchCase.hpp"
#include "ASTGenerator/Expr/ExprSwitchTest.hpp"

namespace ast
{
	class StmtSwitch
		: public StmtCompound
	{
	public:
		StmtSwitch( ExprSwitchTestPtr testExpr );
		void addCase( StmtSwitchCasePtr caseStmt );
		void addDefault( StmtSwitchCasePtr caseStmt );

		void accept( StmtVisitorPtr vis )override;

		inline Expr * getTestExpr()const
		{
			return m_testExpr.get();
		}

	private:
		StmtCompound::addStmt;

	private:
		ExprSwitchTestPtr m_testExpr;
	};

	inline std::unique_ptr< StmtSwitch > makeSwitchStmt( ExprSwitchTestPtr testExpr )
	{
		return std::make_unique< StmtSwitch >( std::move( testExpr ) );
	}
}

#endif
