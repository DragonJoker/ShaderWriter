/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Stmt/PreprocElif.hpp"

#include "ASTGenerator/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	PreprocElif::PreprocElif( expr::ExprPtr ctrlExpr )
		: Stmt{ Kind::ePreprocElif }
		, m_ctrlExpr{ std::move( ctrlExpr ) }
	{
	}

	void PreprocElif::accept( VisitorPtr vis )
	{
		vis->visitPreprocElif( this );
	}
}
