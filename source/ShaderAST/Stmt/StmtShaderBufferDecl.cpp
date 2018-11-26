/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtShaderBufferDecl.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	ShaderBufferDecl::ShaderBufferDecl( std::string const & ssboName
		, type::MemoryLayout layout
		, uint32_t bindingPoint
		, uint32_t bindingSet )
		: Compound{ Kind::eShaderBufferDecl }
		, m_ssboName{ std::move( ssboName ) }
		, m_layout{ layout }
		, m_bindingPoint{ bindingPoint }
		, m_bindingSet{ bindingSet }
	{
	}

	void ShaderBufferDecl::add( VariableDeclPtr decl )
	{
		addStmt( std::move( decl ) );
	}

	void ShaderBufferDecl::accept( VisitorPtr vis )
	{
		vis->visitShaderBufferDeclStmt( this );
	}
}
