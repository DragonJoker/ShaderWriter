/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Stmt/PreprocElse.hpp"

#include "ASTGenerator/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	PreprocElse::PreprocElse()
		: Container{ Kind::ePreprocElse }
	{
	}

	void PreprocElse::accept( VisitorPtr vis )
	{
		vis->visitPreprocElse( this );
	}
}
