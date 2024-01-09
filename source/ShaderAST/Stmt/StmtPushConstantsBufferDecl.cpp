/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtPushConstantsBufferDecl.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	PushConstantsBufferDecl::PushConstantsBufferDecl( StmtCache & stmtCache
		, std::string name
		, type::MemoryLayout layout )
		: Compound{ stmtCache, sizeof( PushConstantsBufferDecl ), Kind::ePushConstantsBufferDecl }
		, m_name{ std::move( name ) }
		, m_layout{ layout }
	{
	}

	void PushConstantsBufferDecl::add( VariableDeclPtr decl )
	{
		addStmt( std::move( decl ) );
	}

	void PushConstantsBufferDecl::accept( VisitorPtr vis )const
	{
		vis->visitPushConstantsBufferDeclStmt( this );
	}
}
