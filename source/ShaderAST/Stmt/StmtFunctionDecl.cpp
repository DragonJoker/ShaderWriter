/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtFunctionDecl.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"
#include "ShaderAST/Type/TypeFunction.hpp"

namespace ast::stmt
{
	FunctionDecl::FunctionDecl( StmtCache & stmtCache
		, var::VariablePtr funcVar
		, uint32_t flags )
		: Compound{ stmtCache, sizeof( FunctionDecl ), Kind::eFunctionDecl }
		, m_funcVar{ std::move( funcVar ) }
		, m_flags{ flags }
	{
	}

	void FunctionDecl::accept( VisitorPtr vis )const
	{
		vis->visitFunctionDeclStmt( this );
	}

	type::FunctionPtr FunctionDecl::getType()const
	{
		return std::static_pointer_cast< type::Function >( m_funcVar->getType() );
	}

	std::string const & FunctionDecl::getName()const
	{
		return m_funcVar->getName();
	}
}
