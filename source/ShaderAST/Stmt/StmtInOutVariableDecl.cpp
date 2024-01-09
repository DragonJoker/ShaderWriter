/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtInOutVariableDecl.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	InOutVariableDecl::InOutVariableDecl( StmtCache & stmtCache
		, var::VariablePtr variable
		, uint32_t location
		, uint32_t streamIndex
		, uint32_t blendIndex )
		: Stmt{ stmtCache, sizeof( InOutVariableDecl ), Kind::eInOutVariableDecl }
		, m_variable{ std::move( variable ) }
		, m_location{ location }
		, m_streamIndex{ streamIndex }
		, m_blendIndex{ blendIndex }
	{
	}

	void InOutVariableDecl::accept( VisitorPtr vis )const
	{
		vis->visitInOutVariableDeclStmt( this );
	}
}
