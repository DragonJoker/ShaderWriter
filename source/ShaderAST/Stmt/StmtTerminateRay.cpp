/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtTerminateRay.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	TerminateRay::TerminateRay()
		: Stmt{ Kind::eTerminateRay }
	{
	}

	void TerminateRay::accept( VisitorPtr vis )
	{
		vis->visitTerminateRayStmt( this );
	}
}
