/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtShaderStructBufferDecl.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	ShaderStructBufferDecl::ShaderStructBufferDecl( StmtCache & stmtCache
		, std::string ssboName
		, var::VariablePtr ssboInstance
		, var::VariablePtr data
		, uint32_t bindingPoint
		, uint32_t bindingSet )
		: Stmt{ stmtCache, sizeof( ShaderStructBufferDecl ), Kind::eShaderStructBufferDecl }
		, m_ssboName{ std::move( ssboName ) }
		, m_ssboInstance{ std::move( ssboInstance ) }
		, m_data{ std::move( data ) }
		, m_bindingPoint{ bindingPoint }
		, m_bindingSet{ bindingSet }
	{
		assert( m_ssboInstance->getType()->getKind() == type::Kind::eStruct );
	}

	void ShaderStructBufferDecl::accept( VisitorPtr vis )const
	{
		vis->visitShaderStructBufferDeclStmt( this );
	}
}
