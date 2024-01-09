/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtCompound.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	Compound::Compound( StmtCache & stmtCache
		, size_t size
		, Kind kind )
		: Container{ stmtCache, size, kind }
	{
	}
	
	Compound::Compound( StmtCache & stmtCache )
		: Compound{ stmtCache, sizeof( Compound ), Kind::eCompound }
	{
	}

	void Compound::accept( VisitorPtr vis )const
	{
		vis->visitCompoundStmt( this );
	}
}
