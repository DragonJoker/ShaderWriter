/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtTerminateRay.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	TerminateRay::TerminateRay( StmtCache & stmtCache )
		: Stmt{ stmtCache, sizeof( TerminateRay ), Kind::eTerminateRay }
	{
	}

	void TerminateRay::accept( VisitorPtr vis )const
	{
		vis->visitTerminateRayStmt( this );
	}
}
