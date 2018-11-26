/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtElseIf.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	ElseIf::ElseIf( expr::ExprPtr ctrlExpr )
		: Compound{ Kind::eElseIf }
		, m_ctrlExpr{ std::move( ctrlExpr ) }
	{
	}

	void ElseIf::accept( VisitorPtr vis )
	{
		vis->visitElseIfStmt( this );
	}
}
