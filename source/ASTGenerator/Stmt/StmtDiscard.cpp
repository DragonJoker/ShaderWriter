/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Stmt/StmtDiscard.hpp"

#include "ASTGenerator/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	Discard::Discard()
		: Stmt{ Kind::eDiscard }
	{
	}

	void Discard::accept( VisitorPtr vis )
	{
		vis->visitDiscardStmt( this );
	}
}
