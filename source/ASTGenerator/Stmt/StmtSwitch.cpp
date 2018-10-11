/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Stmt/StmtSwitch.hpp"

#include "ASTGenerator/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	Switch::Switch( expr::SwitchTestPtr testExpr )
		: Compound{ Kind::eSwitch }
		, m_testExpr{ std::move( testExpr ) }
	{
	}

	void Switch::addCase( SwitchCasePtr caseStmt )
	{
		addStmt( std::move( caseStmt ) );
	}

	void Switch::addDefault( SwitchCasePtr caseStmt )
	{
		addStmt( std::move( caseStmt ) );
	}

	void Switch::accept( VisitorPtr vis )
	{
		vis->visitSwitchStmt( this );
	}
}
