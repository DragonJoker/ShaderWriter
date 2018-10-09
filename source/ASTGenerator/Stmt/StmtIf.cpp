/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Stmt/StmtIf.hpp"

#include "ASTGenerator/Stmt/StmtVisitor.hpp"

namespace ast
{
	StmtIf::StmtIf( ExprPtr ctrlExpr )
		: StmtCompound{ Kind::eIf }
		, m_ctrlExpr{ std::move( ctrlExpr ) }
	{
	}

	void StmtIf::accept( StmtVisitorPtr vis )
	{
		vis->visitIfStmt( this );
	}
}
