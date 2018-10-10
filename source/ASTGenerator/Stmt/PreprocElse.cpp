/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Stmt/PreprocElse.hpp"

#include "ASTGenerator/Stmt/StmtVisitor.hpp"

namespace ast
{
	PreprocElse::PreprocElse()
		: Stmt{ Kind::ePreprocElse }
	{
	}

	void PreprocElse::accept( StmtVisitorPtr vis )
	{
		vis->visitPreprocElse( this );
	}
}
