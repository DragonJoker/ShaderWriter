/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtReturn.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	Return::Return( StmtCache & stmtCache
		, expr::ExprPtr expr )
		: Stmt{ stmtCache, sizeof( Return ), Kind::eReturn }
		, m_expr{ std::move( expr ) }
	{
	}

	void Return::accept( VisitorPtr vis )const
	{
		vis->visitReturnStmt( this );
	}
}
