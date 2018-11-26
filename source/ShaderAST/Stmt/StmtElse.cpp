/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtElse.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	Else::Else()
		: Compound{ Kind::eElse }
	{
	}

	void Else::accept( VisitorPtr vis )
	{
		vis->visitElseStmt( this );
	}
}
