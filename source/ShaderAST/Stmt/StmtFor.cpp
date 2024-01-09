/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtFor.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	For::For( StmtCache & stmtCache
		, expr::ExprPtr initExpr
		, expr::ExprPtr ctrlExpr
		, expr::ExprPtr incrExpr )
		: Loop{ stmtCache, sizeof( For ), Kind::eFor }
		, m_initExpr{ std::move( initExpr ) }
		, m_ctrlExpr{ std::move( ctrlExpr ) }
		, m_incrExpr{ std::move( incrExpr ) }
	{
	}

	void For::accept( VisitorPtr vis )const
	{
		vis->visitForStmt( this );
	}
}
