/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtSwitch_H___
#define ___AST_StmtSwitch_H___
#pragma once

#include "StmtCompound.hpp"

#include "StmtSwitchCase.hpp"
#include "ShaderAST/Expr/ExprSwitchTest.hpp"

namespace ast::stmt
{
	class SwitchCase;

	class Switch
		: public Compound
	{
	public:
		SDAST_API explicit Switch( StmtCache & stmtCache
			, expr::SwitchTestPtr testExpr );

		SDAST_API SwitchCase * createCase( expr::SwitchCasePtr label );
		SDAST_API SwitchCase * createDefault();

		SDAST_API void accept( VisitorPtr vis )const override;

		inline expr::SwitchTest * getTestExpr()const
		{
			return m_testExpr.get();
		}

	private:
		using Compound::addStmt;

	private:
		expr::SwitchTestPtr m_testExpr{};
	};
}

#endif
