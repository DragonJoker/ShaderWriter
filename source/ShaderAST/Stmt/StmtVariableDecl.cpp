/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtVariableDecl.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	VariableDecl::VariableDecl( StmtCache & stmtCache
		, var::VariablePtr variable )
		: Stmt{ stmtCache, sizeof( VariableDecl ), Kind::eVariableDecl }
		, m_variable{ std::move( variable ) }
	{
	}

	void VariableDecl::accept( VisitorPtr vis )const
	{
		vis->visitVariableDeclStmt( this );
	}
}
