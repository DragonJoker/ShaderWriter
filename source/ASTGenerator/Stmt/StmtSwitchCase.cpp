/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Stmt/StmtSwitchCase.hpp"

#include "ASTGenerator/Stmt/StmtVisitor.hpp"

namespace ast
{
	StmtSwitchCase::StmtSwitchCase( ExprSwitchCasePtr caseExpr )
		: StmtCompound{ Kind::eSwitchCase }
		, m_caseExpr{ std::move( caseExpr ) }
	{
	}

	StmtSwitchCase::StmtSwitchCase()
		: StmtCompound{ Kind::eSwitchCase }
	{
	}

	void StmtSwitchCase::accept( StmtVisitorPtr vis )
	{
		vis->visitSwitchCaseStmt( this );
	}
}
