/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Stmt/StmtVariableDecl.hpp"

#include "ASTGenerator/Stmt/StmtVisitor.hpp"

namespace ast
{
	StmtVariableDecl::StmtVariableDecl( VariablePtr variable )
		: Stmt{ Kind::eVariableDecl }
	{
	}

	void StmtVariableDecl::accept( StmtVisitorPtr vis )
	{
		vis->visitVariableDeclStmt( this );
	}
}
