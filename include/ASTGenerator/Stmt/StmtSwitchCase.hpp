/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtSwitchCase_H___
#define ___AST_StmtSwitchCase_H___
#pragma once

#include "StmtCompound.hpp"

#include "ASTGenerator/Expr/ExprSwitchCase.hpp"

namespace ast::stmt
{
	class Switch;
	class SwitchCase
		: public Compound
	{
		friend class Switch;

	private:
		SwitchCase( expr::SwitchCasePtr caseExpr );
		SwitchCase();

	public:
		void accept( VisitorPtr vis )override;

		inline expr::SwitchCase * getCaseExpr()const
		{
			return m_caseExpr.get();
		}

	private:
		expr::SwitchCasePtr m_caseExpr;
	};
	using SwitchCasePtr = std::unique_ptr< SwitchCase >;
}

#endif
