/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Stmt/StmtElse.hpp"

namespace ast
{
	StmtElse::StmtElse( StmtIf const & ifStmt )
		: StmtCompound{ Kind::eElse }
		, m_ifStmt{ ifStmt }
	{
	}
}
