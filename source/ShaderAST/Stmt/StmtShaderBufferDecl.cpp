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
		: Compound{ stmtCache, sizeof( ShaderBufferDecl ), Kind::eShaderBufferDecl }
		, m_variable{ std::move( variable ) }
		, m_bindingPoint{ bindingPoint }
		, m_bindingSet{ bindingSet }
	{
	}

	void ShaderBufferDecl::add( VariableDeclPtr decl )
	{
		addStmt( std::move( decl ) );
	}

	type::MemoryLayout ShaderBufferDecl::getMemoryLayout()const
	{
		return getType()->getMemoryLayout();
	}

	std::string ShaderBufferDecl::getSsboName()const
	{
		return m_variable->getName();
	}

	type::StructPtr ShaderBufferDecl::getType()const
	{
		return std::static_pointer_cast< type::Struct >( m_variable->getType() );
	}

	void ShaderBufferDecl::accept( VisitorPtr vis )const
	{
		vis->visitShaderBufferDeclStmt( this );
	}
}
