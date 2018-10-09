/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Stmt/Stmt.hpp"

namespace ast
{
	Stmt::Stmt( Kind kind )
		: m_kind{ kind }
	{
	}

	Stmt::~Stmt()
	{
	}
}
