/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Stmt/StmtCompound.hpp"

namespace ast
{
	StmtCompound::StmtCompound( Stmt::Kind kind )
		: Stmt{ kind }
	{
	}

	void StmtCompound::addStmt( StmtPtr stmt )
	{
		m_statements.emplace_back( std::move( stmt ) );
	}
}
