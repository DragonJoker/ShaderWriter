/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtBreak.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	Break::Break( StmtCache & stmtCache
		, bool switchCaseBreak )
		: Stmt{ stmtCache, sizeof( Break ), Kind::eBreak }
		, m_switchCaseBreak{ switchCaseBreak }
	{
	}

	void Break::accept( VisitorPtr vis )const
	{
		vis->visitBreakStmt( this );
	}
}
