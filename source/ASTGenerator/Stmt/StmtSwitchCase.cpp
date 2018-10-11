/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Stmt/StmtSwitchCase.hpp"

#include "ASTGenerator/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	SwitchCase::SwitchCase( expr::SwitchCasePtr caseExpr )
		: Compound{ Kind::eSwitchCase }
		, m_caseExpr{ std::move( caseExpr ) }
	{
	}

	SwitchCase::SwitchCase()
		: Compound{ Kind::eSwitchCase }
	{
	}

	void SwitchCase::accept( VisitorPtr vis )
	{
		vis->visitSwitchCaseStmt( this );
	}
}
