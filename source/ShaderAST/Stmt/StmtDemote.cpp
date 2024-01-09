/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtDemote.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	Demote::Demote( StmtCache & stmtCache )
		: Stmt{ stmtCache, sizeof( Demote ), Kind::eDemote }
	{
	}

	void Demote::accept( VisitorPtr vis )const
	{
		vis->visitDemoteStmt( this );
	}
}
