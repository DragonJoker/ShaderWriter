/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Stmt/StmtEmitVertex.hpp"

#include "ASTGenerator/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	EmitVertex::EmitVertex()
		: Stmt{ Kind::eEmitVertex }
	{
	}

	void EmitVertex::accept( VisitorPtr vis )
	{
		vis->visitEmitVertexStmt( this );
	}
}
