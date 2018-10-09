/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Stmt/StmtWhile.hpp"

#include "ASTGenerator/Stmt/StmtVisitor.hpp"

namespace ast
{
	StmtWhile::StmtWhile( ExprPtr ctrlExpr )
		: StmtCompound{ Kind::eWhile }
		, m_ctrlExpr{ std::move( ctrlExpr ) }
	{
	}

	void StmtWhile::accept( StmtVisitorPtr vis )
	{
		vis->visitWhileStmt( this );
	}
}
