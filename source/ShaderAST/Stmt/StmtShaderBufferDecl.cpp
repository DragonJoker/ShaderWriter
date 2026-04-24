/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtShaderBufferDecl.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	ShaderBufferDecl::ShaderBufferDecl( StmtCache & stmtCache
		, var::VariablePtr variable
		, uint32_t bindingPoint
		, uint32_t bindingSet )
		: Stmt{ stmtCache, sizeof( ShaderBufferDecl ), Kind::eShaderBufferDecl }
		, m_variable{ std::move( variable ) }
		, m_type{ static_cast< type::StorageBuffer * >( getNonArrayType( m_variable->getType() ) ) }
		, m_bindingPoint{ bindingPoint }
		, m_bindingSet{ bindingSet }
		, m_arraySize{ type::getArraySize( m_variable->getType() ) }
	{
	}

	void ShaderBufferDecl::accept( VisitorPtr vis )const
	{
		vis->visitShaderBufferDeclStmt( this );
	}
}
