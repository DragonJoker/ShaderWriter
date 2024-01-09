/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtTerminateInvocation.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	TerminateInvocation::TerminateInvocation( StmtCache & stmtCache )
		: Stmt{ stmtCache, sizeof( TerminateInvocation ), Kind::eTerminateInvocation }
	{
	}

	void TerminateInvocation::accept( VisitorPtr vis )const
	{
		vis->visitTerminateInvocationStmt( this );
	}
}
