/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtVariableDecl.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	VariableDecl::VariableDecl( var::VariablePtr variable )
		: Stmt{ Kind::eVariableDecl }
		, m_variable{ std::move( variable ) }
	{
	}

	void VariableDecl::accept( VisitorPtr vis )
	{
		vis->visitVariableDeclStmt( this );
	}
}
