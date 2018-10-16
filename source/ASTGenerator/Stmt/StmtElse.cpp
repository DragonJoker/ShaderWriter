/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Stmt/StmtElse.hpp"

#include "ASTGenerator/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	Else::Else()
		: Compound{ Kind::eElse }
	{
	}

	void Else::accept( VisitorPtr vis )
	{
		vis->visitElseStmt( this );
	}
}
