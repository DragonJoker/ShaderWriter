/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Stmt/PreprocElif.hpp"

#include "ASTGenerator/Stmt/StmtVisitor.hpp"

namespace ast
{
	PreprocElif::PreprocElif( ExprPtr ctrlExpr )
		: Stmt{ Kind::ePreprocElif }
		, m_ctrlExpr{ std::move( ctrlExpr ) }
	{
	}

	void PreprocElif::accept( StmtVisitorPtr vis )
	{
		vis->visitPreprocElif( this );
	}
}
