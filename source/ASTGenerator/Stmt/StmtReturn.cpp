/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Stmt/StmtReturn.hpp"

#include "ASTGenerator/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	Return::Return( expr::ExprPtr expr )
		: Stmt{ Kind::eReturn }
		, m_expr{ std::move( expr ) }
	{
	}

	void Return::accept( VisitorPtr vis )
	{
		vis->visitReturnStmt( this );
	}
}
