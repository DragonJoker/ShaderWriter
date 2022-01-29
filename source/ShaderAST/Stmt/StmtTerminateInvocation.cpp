/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtTerminateInvocation.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	TerminateInvocation::TerminateInvocation()
		: Stmt{ Kind::eTerminateInvocation }
	{
	}

	void TerminateInvocation::accept( VisitorPtr vis )
	{
		vis->visitTerminateInvocationStmt( this );
	}
}
