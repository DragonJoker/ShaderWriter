/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtDemote.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	Demote::Demote()
		: Stmt{ Kind::eDemote }
	{
	}

	void Demote::accept( VisitorPtr vis )
	{
		vis->visitDemoteStmt( this );
	}
}
