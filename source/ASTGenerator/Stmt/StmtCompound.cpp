/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Stmt/StmtCompound.hpp"

#include "ASTGenerator/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	Compound::Compound( Kind kind )
		: Container{ kind }
	{
	}
	
	Compound::Compound()
		: Compound{ Kind::eCompound }
	{
	}

	void Compound::accept( VisitorPtr vis )
	{
		vis->visitCompoundStmt( this );
	}
}
