/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtFunctionDecl.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	FunctionDecl::FunctionDecl( type::FunctionPtr type
		, std::string name
		, uint32_t flags )
		: Compound{ Kind::eFunctionDecl }
		, m_type{ std::move( type ) }
		, m_name{ std::move( name ) }
		, m_flags{ flags }
	{
	}

	void FunctionDecl::accept( VisitorPtr vis )
	{
		vis->visitFunctionDeclStmt( this );
	}
}
