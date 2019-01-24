/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtBreak.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	Break::Break( bool switchCaseBreak )
		: Stmt{ Kind::eBreak }
		, m_switchCaseBreak{ switchCaseBreak }
	{
	}

	void Break::accept( VisitorPtr vis )
	{
		vis->visitBreakStmt( this );
	}
}
