/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Stmt/StmtDoWhile.hpp"

#include "ASTGenerator/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	DoWhile::DoWhile( expr::ExprPtr ctrlExpr )
		: Compound{ Kind::eDoWhile }
		, m_ctrlExpr{ std::move( ctrlExpr ) }
	{
	}

	void DoWhile::accept( VisitorPtr vis )
	{
		vis->visitDoWhileStmt( this );
	}
}
