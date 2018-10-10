/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Stmt/StmtSwitch.hpp"

#include "ASTGenerator/Stmt/StmtVisitor.hpp"

namespace ast
{
	StmtSwitch::StmtSwitch( ExprSwitchTestPtr testExpr )
		: StmtCompound{ Kind::eSwitch }
		, m_testExpr{ std::move( testExpr ) }
	{
	}

	void StmtSwitch::addCase( StmtSwitchCasePtr caseStmt )
	{
		addStmt( std::move( caseStmt ) );
	}

	void StmtSwitch::addDefault( StmtSwitchCasePtr caseStmt )
	{
		addStmt( std::move( caseStmt ) );
	}

	void StmtSwitch::accept( StmtVisitorPtr vis )
	{
		vis->visitSwitchStmt( this );
	}
}
