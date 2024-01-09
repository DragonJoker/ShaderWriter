/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtElseIf.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	ElseIf::ElseIf( StmtCache & stmtCache
		, expr::ExprPtr ctrlExpr )
		: Compound{ stmtCache, sizeof( ElseIf ), Kind::eElseIf }
		, m_ctrlExpr{ std::move( ctrlExpr ) }
	{
	}

	void ElseIf::accept( VisitorPtr vis )const
	{
		vis->visitElseIfStmt( this );
	}
}
