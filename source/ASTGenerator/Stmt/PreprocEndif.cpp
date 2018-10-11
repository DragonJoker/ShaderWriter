/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Stmt/PreprocEndif.hpp"

#include "ASTGenerator/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	PreprocEndif::PreprocEndif()
		: Stmt{ Kind::ePreprocEndif }
	{
	}

	void PreprocEndif::accept( VisitorPtr vis )
	{
		vis->visitPreprocEndif( this );
	}
}
