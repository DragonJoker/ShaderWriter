/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtWhile.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	While::While( expr::ExprPtr ctrlExpr )
		: Loop{ Kind::eWhile }
		, m_ctrlExpr{ std::move( ctrlExpr ) }
	{
	}

	void While::accept( VisitorPtr vis )
	{
		vis->visitWhileStmt( this );
	}
}
