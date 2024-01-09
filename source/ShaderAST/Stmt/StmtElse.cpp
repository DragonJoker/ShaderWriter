/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtElse.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	Else::Else( StmtCache & stmtCache )
		: Compound{ stmtCache, sizeof( Else ), Kind::eElse }
	{
	}

	void Else::accept( VisitorPtr vis )const
	{
		vis->visitElseStmt( this );
	}
}
