/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtPerVertexDecl.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	PerVertexDecl::PerVertexDecl( StmtCache & stmtCache
		, PerVertexDecl::Source source
		, type::TypePtr type )
		: Stmt{ stmtCache, sizeof( PerVertexDecl ), Kind::ePerVertexDecl }
		, m_source{ source }
		, m_type{ type }
	{
	}

	void PerVertexDecl::accept( VisitorPtr vis )const
	{
		vis->visitPerVertexDeclStmt( this );
	}
}
