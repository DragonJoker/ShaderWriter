/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Stmt/StmtShaderStructBufferDecl.hpp"

#include "ASTGenerator/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	ShaderStructBufferDecl::ShaderStructBufferDecl( std::string const & ssboName
		, var::VariablePtr ssboInstance
		, var::VariablePtr data
		, uint32_t bindingPoint
		, uint32_t bindingSet )
		: Stmt{ Kind::eShaderStructBufferDecl }
		, m_ssboName{ std::move( ssboName ) }
		, m_ssboInstance{ std::move( ssboInstance ) }
		, m_data{ std::move( data ) }
		, m_bindingPoint{ bindingPoint }
		, m_bindingSet{ bindingSet }
	{
		assert( m_ssboInstance->getType()->getKind() == type::Kind::eStruct );
	}

	void ShaderStructBufferDecl::accept( VisitorPtr vis )
	{
		vis->visitShaderStructBufferDeclStmt( this );
	}
}
