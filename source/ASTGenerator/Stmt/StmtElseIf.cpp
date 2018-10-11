/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Stmt/StmtElseIf.hpp"

#include "ASTGenerator/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	ElseIf::ElseIf( If const & ifStmt
		, expr::ExprPtr ctrlExpr )
		: Compound{ Kind::eElseIf }
		, m_ifStmt{ ifStmt }
		, m_ctrlExpr{ std::move( ctrlExpr ) }
	{
	}

	void ElseIf::accept( VisitorPtr vis )
	{
		vis->visitElseIfStmt( this );
	}
}
