/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Stmt/StmtBoundVariableDecl.hpp"

#include "ASTGenerator/Stmt/StmtVisitor.hpp"

namespace ast
{
	StmtBoundVariableDecl::StmtBoundVariableDecl( VariablePtr variable
		, uint32_t bindingPoint
		, uint32_t bindingSet )
		: Stmt{ Kind::eBoundVariableDecl }
		, m_variable{ std::move( variable ) }
		, m_bindingPoint{ bindingPoint }
		, m_bindingSet{ bindingSet }
	{
	}

	void StmtBoundVariableDecl::accept( StmtVisitorPtr vis )
	{
		vis->visitBoundVariableDeclStmt( this );
	}
}
