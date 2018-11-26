/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtDiscard.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

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
