/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtPushConstantsBufferDecl.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	PushConstantsBufferDecl::PushConstantsBufferDecl( std::string name )
		: Compound{ Kind::ePushConstantsBufferDecl }
		, m_name{ std::move( name ) }
	{
	}

	void PushConstantsBufferDecl::add( VariableDeclPtr decl )
	{
		addStmt( std::move( decl ) );
	}

	void PushConstantsBufferDecl::accept( VisitorPtr vis )
	{
		vis->visitPushConstantsBufferDeclStmt( this );
	}
}
