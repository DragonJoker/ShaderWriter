/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtSimple.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	Simple::Simple( StmtCache & stmtCache
		, expr::ExprPtr expr )
		: Stmt{ stmtCache, sizeof( Simple ), Kind::eSimple }
		, m_expr{ std::move( expr ) }
	{
	}

	void Simple::accept( VisitorPtr vis )const
	{
		vis->visitSimpleStmt( this );
	}
}
