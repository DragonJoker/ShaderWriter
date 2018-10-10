/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Stmt/StmtReturn.hpp"

#include "ASTGenerator/Stmt/StmtVisitor.hpp"

namespace ast
{
	StmtReturn::StmtReturn( ExprPtr expr )
		: Stmt{ Kind::eReturn }
		, m_expr{ std::move( expr ) }
	{
	}

	void StmtReturn::accept( StmtVisitorPtr vis )
	{
		vis->visitReturnStmt( this );
	}
}
