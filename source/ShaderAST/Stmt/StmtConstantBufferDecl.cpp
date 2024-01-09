/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtConstantBufferDecl.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	ConstantBufferDecl::ConstantBufferDecl( StmtCache & stmtCache
		, std::string name
		, type::MemoryLayout layout
		, uint32_t bindingPoint
		, uint32_t bindingSet )
		: Compound{ stmtCache, sizeof( ConstantBufferDecl ), Kind::eConstantBufferDecl }
		, m_name{ std::move( name ) }
		, m_layout{ layout }
		, m_bindingPoint{ bindingPoint }
		, m_bindingSet{ bindingSet }
	{
	}

	void ConstantBufferDecl::add( VariableDeclPtr decl )
	{
		addStmt( std::move( decl ) );
	}

	void ConstantBufferDecl::accept( VisitorPtr vis )const
	{
		vis->visitConstantBufferDeclStmt( this );
	}
}
