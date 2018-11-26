/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/PreprocElif.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	PreprocElif::PreprocElif( expr::ExprPtr ctrlExpr )
		: Container{ Kind::ePreprocElif }
		, m_ctrlExpr{ std::move( ctrlExpr ) }
	{
	}

	void PreprocElif::accept( VisitorPtr vis )
	{
		vis->visitPreprocElif( this );
	}
}
