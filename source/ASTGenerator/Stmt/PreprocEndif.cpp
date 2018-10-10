/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Stmt/PreprocEndif.hpp"

#include "ASTGenerator/Stmt/StmtVisitor.hpp"

namespace ast
{
	PreprocEndif::PreprocEndif()
		: Stmt{ Kind::ePreprocEndif }
	{
	}

	void PreprocEndif::accept( StmtVisitorPtr vis )
	{
		vis->visitPreprocEndif( this );
	}
}
