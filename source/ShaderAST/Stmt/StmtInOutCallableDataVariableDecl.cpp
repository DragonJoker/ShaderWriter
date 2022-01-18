/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtInOutCallableDataVariableDecl.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	InOutCallableDataVariableDecl::InOutCallableDataVariableDecl( var::VariablePtr variable
		, uint32_t location )
		: Stmt{ Kind::eInOutCallableDataVariableDecl }
		, m_variable{ std::move( variable ) }
		, m_location{ location }
	{
	}

	void InOutCallableDataVariableDecl::accept( VisitorPtr vis )
	{
		vis->visitInOutCallableDataVariableDeclStmt( this );
	}
}