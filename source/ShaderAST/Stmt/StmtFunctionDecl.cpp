/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtFunctionDecl.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	FunctionDecl::FunctionDecl( type::FunctionPtr type
		, std::string name )
		: Compound{ Kind::eFunctionDecl }
		, m_type{ std::move( type ) }
		, m_name{ std::move( name ) }
	{
	}

	void FunctionDecl::accept( VisitorPtr vis )
	{
		vis->visitFunctionDeclStmt( this );
	}
}
