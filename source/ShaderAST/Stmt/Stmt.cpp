/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/Stmt.hpp"

namespace ast::stmt
{
	Stmt::Stmt( Kind kind )
		: m_kind{ kind }
	{
	}

	Stmt::~Stmt()
	{
	}
}
