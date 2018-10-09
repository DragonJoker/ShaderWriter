/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Stmt/StmtDoWhile.hpp"

#include "ASTGenerator/Stmt/StmtVisitor.hpp"

namespace ast
{
	StmtDoWhile::StmtDoWhile( ExprPtr ctrlExpr )
		: StmtCompound{ Kind::eDoWhile }
		, m_ctrlExpr{ std::move( ctrlExpr ) }
	{
	}

	void StmtDoWhile::accept( StmtVisitorPtr vis )
	{
		vis->visitDoWhileStmt( this );
	}
}
