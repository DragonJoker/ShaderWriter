/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtIgnoreIntersection.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	IgnoreIntersection::IgnoreIntersection( StmtCache & stmtCache )
		: Stmt{ stmtCache, sizeof( IgnoreIntersection ), Kind::eIgnoreIntersection }
	{
	}

	void IgnoreIntersection::accept( VisitorPtr vis )const
	{
		vis->visitIgnoreIntersectionStmt( this );
	}
}
