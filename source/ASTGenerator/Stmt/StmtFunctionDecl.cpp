/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Stmt/StmtFunctionDecl.hpp"

namespace ast
{
	StmtFunctionDecl::StmtFunctionDecl( Type retType
		, std::string name
		, VariableList parameters )
		: StmtCompound{ Kind::eFunctionDecl }
		, m_retType{ retType }
		, m_name{ std::move( name ) }
		, m_parameters{ std::move( parameters ) }
	{
	}
}
