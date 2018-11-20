/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Stmt/StmtShaderBufferDecl.hpp"

#include "ASTGenerator/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	ShaderBufferDecl::ShaderBufferDecl( std::string const & ssboName
		, var::VariablePtr ssboInstance
		, var::VariablePtr data
		, uint32_t bindingPoint
		, uint32_t bindingSet )
		: Compound{ Kind::eShaderBufferDecl }
		, m_ssboName{ std::move( ssboName ) }
		, m_ssboInstance{ std::move( ssboInstance ) }
		, m_data{ std::move( data ) }
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
