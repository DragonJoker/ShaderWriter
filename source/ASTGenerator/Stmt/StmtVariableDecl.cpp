/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Stmt/StmtVariableDecl.hpp"

namespace ast
{
	StmtVariableDecl::StmtVariableDecl( VariablePtr variable )
		: Stmt{ Kind::eVariableDecl }
	{
	}
}
