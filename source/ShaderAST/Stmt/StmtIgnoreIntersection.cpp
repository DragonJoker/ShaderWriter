/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtIgnoreIntersection.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	IgnoreIntersection::IgnoreIntersection()
		: Stmt{ Kind::eIgnoreIntersection }
	{
	}

	void IgnoreIntersection::accept( VisitorPtr vis )
	{
		vis->visitIgnoreIntersectionStmt( this );
	}
}
