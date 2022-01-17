/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtBufferReferenceDecl.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	BufferReferenceDecl::BufferReferenceDecl( type::TypePtr type )
		: Stmt{ Kind::eBufferReferenceDecl }
		, m_type{ std::move( type ) }
	{
	}

	void BufferReferenceDecl::accept( VisitorPtr vis )
	{
		vis->visitBufferReferenceDeclStmt( this );
	}
}
