/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtFor.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	For::For( expr::ExprPtr initExpr
		, expr::ExprPtr ctrlExpr
		, expr::ExprPtr incrExpr )
		: Compound{ Kind::eFor }
		, m_initExpr{ std::move( initExpr ) }
		, m_ctrlExpr{ std::move( ctrlExpr ) }
		, m_incrExpr{ std::move( incrExpr ) }
	{
	}

	void For::accept( VisitorPtr vis )
	{
		vis->visitForStmt( this );
	}
}
