/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Stmt/StmtInOutVariableDecl.hpp"

#include "ASTGenerator/Stmt/StmtVisitor.hpp"

namespace ast
{
	StmtInOutVariableDecl::StmtInOutVariableDecl( VariablePtr variable
		, uint32_t location
		, Direction direction )
		: Stmt{ Kind::eInOutVariableDecl }
		, m_variable{ std::move( variable ) }
		, m_location{ location }
		, m_direction{ direction }
	{
	}

	void StmtInOutVariableDecl::accept( StmtVisitorPtr vis )
	{
		vis->visitInOutVariableDeclStmt( this );
	}
}
