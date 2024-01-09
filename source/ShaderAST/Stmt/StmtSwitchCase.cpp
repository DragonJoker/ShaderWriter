/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtSwitchCase.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	SwitchCase::SwitchCase( StmtCache & stmtCache
		, expr::SwitchCasePtr caseExpr )
		: Compound{ stmtCache, sizeof( SwitchCase ), Kind::eSwitchCase }
		, m_caseExpr{ std::move( caseExpr ) }
	{
	}

	SwitchCase::SwitchCase( StmtCache & stmtCache )
		: Compound{ stmtCache, sizeof( SwitchCase ), Kind::eSwitchCase }
	{
	}

	void SwitchCase::accept( VisitorPtr vis )const
	{
		vis->visitSwitchCaseStmt( this );
	}
}
