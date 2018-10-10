/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Stmt/StmtElseIf.hpp"

#include "ASTGenerator/Stmt/StmtVisitor.hpp"

namespace ast
{
	StmtElseIf::StmtElseIf( StmtIf const & ifStmt
		, ExprPtr ctrlExpr )
		: StmtCompound{ Kind::eElseIf }
		, m_ifStmt{ ifStmt }
		, m_ctrlExpr{ std::move( ctrlExpr ) }
	{
	}

	void StmtElseIf::accept( StmtVisitorPtr vis )
	{
		vis->visitElseIfStmt( this );
	}
}
