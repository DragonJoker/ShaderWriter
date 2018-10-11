/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Stmt/StmtFunctionDecl.hpp"

#include "ASTGenerator/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	FunctionDecl::FunctionDecl( type::TypePtr retType
		, std::string name
		, var::VariableList parameters )
		: Compound{ Kind::eFunctionDecl }
		, m_retType{ std::move( retType ) }
		, m_name{ std::move( name ) }
		, m_parameters{ std::move( parameters ) }
	{
	}

	void FunctionDecl::accept( VisitorPtr vis )
	{
		vis->visitFunctionDeclStmt( this );
	}
}
