/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtInOutVariableDecl.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	InOutVariableDecl::InOutVariableDecl( var::VariablePtr variable
		, uint32_t location
		, uint32_t streamIndex
		, uint32_t blendIndex )
		: Stmt{ Kind::eInOutVariableDecl }
		, m_variable{ std::move( variable ) }
		, m_location{ location }
		, m_streamIndex{ streamIndex }
		, m_blendIndex{ blendIndex }
	{
	}

	void InOutVariableDecl::accept( VisitorPtr vis )
	{
		vis->visitInOutVariableDeclStmt( this );
	}
}
