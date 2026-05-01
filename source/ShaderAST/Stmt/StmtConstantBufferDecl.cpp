/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtConstantBufferDecl.hpp"

#include "ShaderAST/ShaderLog.hpp"
#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	ConstantBufferDecl::ConstantBufferDecl( StmtCache & stmtCache
		, var::VariablePtr variable
		, uint32_t bindingPoint
		, uint32_t bindingSet )
		: Stmt{ stmtCache, sizeof( ShaderBufferDecl ), Kind::eConstantBufferDecl }
		, m_variable{ std::move( variable ) }
		, m_type{ static_cast< type::UniformBuffer * >( getNonArrayType( m_variable->getType() ) ) }
		, m_bindingPoint{ bindingPoint }
		, m_bindingSet{ bindingSet }
	{
		if ( type::getArraySize( m_variable->getType() ) != ast::type::NotArray )
		{
#ifndef NDEBUG
			AST_Failure( "Constant buffer variable cannot be an array" );
#else
			AST_Exception( "Constant buffer variable cannot be an array" );
#endif
		}
	}

	void ConstantBufferDecl::accept( VisitorPtr vis )const
	{
		vis->visitConstantBufferDeclStmt( this );
	}
}
