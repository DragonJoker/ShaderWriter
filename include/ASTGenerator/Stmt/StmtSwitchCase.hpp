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
	class SwitchCase
		: public Compound
	{
	public:
		SwitchCase( expr::SwitchCasePtr caseExpr );
		SwitchCase();

		void accept( VisitorPtr vis )override;

		inline expr::SwitchCase * getCaseExpr()const
		{
			return m_caseExpr.get();
		}

	private:
		expr::SwitchCasePtr m_caseExpr;
	};
	using SwitchCasePtr = std::unique_ptr< SwitchCase >;

	inline std::unique_ptr< SwitchCase > makeSwitchCase( expr::SwitchCasePtr caseExpr )
	{
		return std::make_unique< SwitchCase >( std::move( caseExpr ) );
	}

	inline std::unique_ptr< SwitchCase > makeSwitchDefault()
	{
		return std::make_unique< SwitchCase >();
	}
}

#endif
