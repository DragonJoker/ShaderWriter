/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/PreprocElse.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	PreprocElse::PreprocElse( StmtCache & stmtCache )
		: Container{ stmtCache, sizeof( PreprocElse ), Kind::ePreprocElse }
	{
	}

	void PreprocElse::accept( VisitorPtr vis )
	{
		vis->visitPreprocElse( this );
	}
}
