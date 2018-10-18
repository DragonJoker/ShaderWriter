/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtSwitch_H___
#define ___AST_StmtSwitch_H___
#pragma once

#include "StmtCompound.hpp"

#include "StmtSwitchCase.hpp"
#include "ASTGenerator/Expr/ExprSwitchTest.hpp"

namespace ast::stmt
{
	class Switch
		: public Compound
	{
	public:
		Switch( expr::SwitchTestPtr testExpr );
		void addCase( SwitchCasePtr caseStmt );
		void addDefault( SwitchCasePtr caseStmt );

		void accept( VisitorPtr vis )override;

		inline expr::SwitchTest * getTestExpr()const
		{
			return m_testExpr.get();
		}

	private:
		using Compound::addStmt;

	private:
		expr::SwitchTestPtr m_testExpr;
	};
	using SwitchPtr = std::unique_ptr< Switch >;

	inline SwitchPtr makeSwitch( expr::SwitchTestPtr testExpr )
	{
		return std::make_unique< Switch >( std::move( testExpr ) );
	}
}

#endif
