/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Stmt/StmtWhile.hpp"

#include "ASTGenerator/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	While::While( expr::ExprPtr ctrlExpr )
		: Compound{ Kind::eWhile }
		, m_ctrlExpr{ std::move( ctrlExpr ) }
	{
	}

	void While::accept( VisitorPtr vis )
	{
		vis->visitWhileStmt( this );
	}
}
