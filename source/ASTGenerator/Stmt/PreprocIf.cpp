/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Stmt/PreprocIf.hpp"

#include "ASTGenerator/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	PreprocIf::PreprocIf( expr::ExprPtr ctrlExpr )
		: Stmt{ Kind::ePreprocIf }
		, m_ctrlExpr{ std::move( ctrlExpr ) }
	{
	}

	void PreprocIf::accept( VisitorPtr vis )
	{
		vis->visitPreprocIf( this );
	}
}
