/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Stmt/PreprocIf.hpp"

#include "ASTGenerator/Stmt/StmtVisitor.hpp"

namespace ast
{
	PreprocIf::PreprocIf( ExprPtr ctrlExpr )
		: Stmt{ Kind::ePreprocIf }
		, m_ctrlExpr{ std::move( ctrlExpr ) }
	{
	}

	void PreprocIf::accept( StmtVisitorPtr vis )
	{
		vis->visitPreprocIf( this );
	}
}
