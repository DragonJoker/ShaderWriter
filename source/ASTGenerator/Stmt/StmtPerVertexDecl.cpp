/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Stmt/StmtPerVertexDecl.hpp"

#include "ASTGenerator/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	PerVertexDecl::PerVertexDecl( PerVertexDecl::Source source
		, type::StructPtr type )
		: Stmt{ Kind::ePerVertexDecl }
		, m_source{ source }
		, m_type{ type }
	{
	}

	void PerVertexDecl::accept( VisitorPtr vis )
	{
		vis->visitPerVertexDeclStmt( this );
	}
}
