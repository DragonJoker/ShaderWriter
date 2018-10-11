/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Stmt/StmtSimple.hpp"

#include "ASTGenerator/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	Simple::Simple( expr::ExprPtr expr )
		: Stmt{ Kind::eSimple }
		, m_expr{ std::move( expr ) }
	{
	}

	void Simple::accept( VisitorPtr vis )
	{
		vis->visitSimpleStmt( this );
	}
}
