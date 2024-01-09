/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtBufferReferenceDecl.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	BufferReferenceDecl::BufferReferenceDecl( StmtCache & stmtCache
		, type::TypePtr type )
		: Stmt{ stmtCache, sizeof( BufferReferenceDecl ), Kind::eBufferReferenceDecl }
		, m_type{ std::move( type ) }
	{
	}

	void BufferReferenceDecl::accept( VisitorPtr vis )const
	{
		vis->visitBufferReferenceDeclStmt( this );
	}
}
