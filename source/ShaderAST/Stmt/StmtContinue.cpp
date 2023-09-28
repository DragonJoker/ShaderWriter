/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtContinue.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	Continue::Continue( StmtCache & stmtCache )
		: Stmt{ stmtCache, sizeof( Continue ), Kind::eContinue }
	{
	}

	void Continue::accept( VisitorPtr vis )
	{
		vis->visitContinueStmt( this );
	}
}
