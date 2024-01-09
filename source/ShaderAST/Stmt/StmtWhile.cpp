/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtWhile.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	While::While( StmtCache & stmtCache
		, expr::ExprPtr ctrlExpr )
		: Loop{ stmtCache, sizeof( While ), Kind::eWhile }
		, m_ctrlExpr{ std::move( ctrlExpr ) }
	{
	}

	void While::accept( VisitorPtr vis )const
	{
		vis->visitWhileStmt( this );
	}
}
