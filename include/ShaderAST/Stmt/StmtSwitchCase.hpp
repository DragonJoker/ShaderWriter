/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtSwitchCase_H___
#define ___AST_StmtSwitchCase_H___
#pragma once

#include "StmtCompound.hpp"

#include "ShaderAST/Expr/ExprSwitchCase.hpp"

namespace ast::stmt
{
	class Switch;

	class SwitchCase
		: public Compound
	{
		friend class Switch;
		friend class StmtCache;

	private:
		SDAST_API explicit SwitchCase( StmtCache & stmtCache
			, expr::SwitchCasePtr caseExpr );
		SDAST_API explicit SwitchCase( StmtCache & stmtCache );

	public:
		SDAST_API void accept( VisitorPtr vis )const override;

		inline expr::SwitchCase * getCaseExpr()const
		{
			return m_caseExpr.get();
		}

	private:
		expr::SwitchCasePtr m_caseExpr{};
	};
}

#endif
