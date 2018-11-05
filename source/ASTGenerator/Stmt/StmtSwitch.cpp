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

	SwitchCase * Switch::createCase( expr::SwitchCasePtr label )
	{
		auto caseStmt = std::unique_ptr< SwitchCase >( new SwitchCase{ std::move( label ) } );
		auto result = caseStmt.get();
		addStmt( std::move( caseStmt ) );
		return result;
	}

	SwitchCase * Switch::createDefault()
	{
		auto caseStmt = std::unique_ptr< SwitchCase >( new SwitchCase{} );
		auto result = caseStmt.get();
		addStmt( std::move( caseStmt ) );
		return result;
	}

	void Switch::accept( VisitorPtr vis )
	{
		vis->visitSwitchStmt( this );
	}
}
