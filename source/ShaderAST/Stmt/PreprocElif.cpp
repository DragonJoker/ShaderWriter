/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/PreprocElif.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	PreprocElif::PreprocElif( StmtCache & stmtCache
		, expr::ExprPtr ctrlExpr )
		: Container{ stmtCache, sizeof( PreprocElif ), Kind::ePreprocElif }
		, m_ctrlExpr{ std::move( ctrlExpr ) }
	{
	}

	void PreprocElif::accept( VisitorPtr vis )
	{
		vis->visitPreprocElif( this );
	}
}
