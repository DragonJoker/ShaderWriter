/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtDoWhile.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	DoWhile::DoWhile( expr::ExprPtr ctrlExpr )
		: Loop{ Kind::eDoWhile }
		, m_ctrlExpr{ std::move( ctrlExpr ) }
	{
	}

	void DoWhile::accept( VisitorPtr vis )
	{
		vis->visitDoWhileStmt( this );
	}
}
