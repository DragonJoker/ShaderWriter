/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Stmt/StmtFor.hpp"

#include "ASTGenerator/Stmt/StmtVisitor.hpp"

namespace ast
{
	StmtFor::StmtFor( ExprPtr initExpr
		, ExprPtr ctrlExpr
		, ExprPtr incrExpr )
		: StmtCompound{ Kind::eFor }
		, m_initExpr{ std::move( initExpr ) }
		, m_ctrlExpr{ std::move( ctrlExpr ) }
		, m_incrExpr{ std::move( incrExpr ) }
	{
	}

	void StmtFor::accept( StmtVisitorPtr vis )
	{
		vis->visitForStmt( this );
	}
}
