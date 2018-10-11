/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Stmt/StmtElse.hpp"

#include "ASTGenerator/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	Else::Else( If const & ifStmt )
		: Compound{ Kind::eElse }
		, m_ifStmt{ ifStmt }
	{
	}

	void Else::accept( VisitorPtr vis )
	{
		vis->visitElseStmt( this );
	}
}
