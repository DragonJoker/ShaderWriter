/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtDoWhile.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	DoWhile::DoWhile( StmtCache & stmtCache
		, expr::ExprPtr ctrlExpr )
		: Loop{ stmtCache, sizeof( DoWhile ), Kind::eDoWhile }
		, m_ctrlExpr{ std::move( ctrlExpr ) }
	{
	}

	void DoWhile::accept( VisitorPtr vis )const
	{
		vis->visitDoWhileStmt( this );
	}
}
