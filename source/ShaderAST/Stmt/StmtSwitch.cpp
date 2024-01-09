/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtSwitch.hpp"

#include "ShaderAST/Stmt/StmtCache.hpp"
#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	Switch::Switch( StmtCache & stmtCache
		, expr::SwitchTestPtr testExpr )
		: Compound{ stmtCache, sizeof( Switch ), Kind::eSwitch }
		, m_testExpr{ std::move( testExpr ) }
	{
	}

	SwitchCase * Switch::createCase( expr::SwitchCasePtr label )
	{
		auto caseStmt = getStmtCache().makeSwitchCase( std::move( label ) );
		auto result = caseStmt.get();
		addStmt( std::move( caseStmt ) );
		return result;
	}

	SwitchCase * Switch::createDefault()
	{
		auto caseStmt = getStmtCache().makeSwitchDefault();
		auto result = caseStmt.get();
		addStmt( std::move( caseStmt ) );
		return result;
	}

	void Switch::accept( VisitorPtr vis )const
	{
		vis->visitSwitchStmt( this );
	}
}
