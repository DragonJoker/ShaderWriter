/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtInOutCallableDataVariableDecl.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	InOutCallableDataVariableDecl::InOutCallableDataVariableDecl( StmtCache & stmtCache
		, var::VariablePtr variable
		, uint32_t location )
		: Stmt{ stmtCache, sizeof( InOutCallableDataVariableDecl ), Kind::eInOutCallableDataVariableDecl }
		, m_variable{ std::move( variable ) }
		, m_location{ location }
	{
	}

	void InOutCallableDataVariableDecl::accept( VisitorPtr vis )const
	{
		vis->visitInOutCallableDataVariableDeclStmt( this );
	}
}
