/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtInOutVariableDecl.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	InOutVariableDecl::InOutVariableDecl( var::VariablePtr variable
		, uint32_t location )
		: Stmt{ Kind::eInOutVariableDecl }
		, m_variable{ std::move( variable ) }
		, m_location{ location }
	{
	}

	void InOutVariableDecl::accept( VisitorPtr vis )
	{
		vis->visitInOutVariableDeclStmt( this );
	}
}
