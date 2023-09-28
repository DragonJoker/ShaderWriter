/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/PreprocEndif.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	PreprocEndif::PreprocEndif( StmtCache & stmtCache )
		: Stmt{ stmtCache, sizeof( PreprocEndif ), Kind::ePreprocEndif }
	{
	}

	void PreprocEndif::accept( VisitorPtr vis )
	{
		vis->visitPreprocEndif( this );
	}
}
