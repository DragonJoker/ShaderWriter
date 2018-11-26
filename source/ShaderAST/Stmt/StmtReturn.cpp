/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtReturn.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	Return::Return( expr::ExprPtr expr )
		: Stmt{ Kind::eReturn }
		, m_expr{ std::move( expr ) }
	{
	}

	void Return::accept( VisitorPtr vis )
	{
		vis->visitReturnStmt( this );
	}
}
