/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Stmt/StmtElse.hpp"

#include "ASTGenerator/Stmt/StmtVisitor.hpp"

namespace ast
{
	StmtElse::StmtElse( StmtIf const & ifStmt )
		: StmtCompound{ Kind::eElse }
		, m_ifStmt{ ifStmt }
	{
	}

	void StmtElse::accept( StmtVisitorPtr vis )
	{
		vis->visitElseStmt( this );
	}
}
