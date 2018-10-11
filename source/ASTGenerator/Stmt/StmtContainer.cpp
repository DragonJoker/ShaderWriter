/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Stmt/StmtContainer.hpp"

#include "ASTGenerator/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	Container::Container( Kind kind )
		: Stmt{ kind }
	{
	}

	void Container::addStmt( StmtPtr stmt )
	{
		m_statements.emplace_back( std::move( stmt ) );
	}

	void Container::accept( VisitorPtr vis )
	{
		vis->visitContainerStmt( this );
	}
}
