/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Stmt/StmtConstantBufferDecl.hpp"

#include "ASTGenerator/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	ConstantBufferDecl::ConstantBufferDecl( std::string name
		, type::MemoryLayout layout
		, uint32_t bindingPoint
		, uint32_t bindingSet )
		: Compound{ Kind::eConstantBufferDecl }
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

	void ConstantBufferDecl::accept( VisitorPtr vis )
	{
		vis->visitConstantBufferDeclStmt( this );
	}
}
