/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtContainer.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	Container::Container( StmtCache & stmtCache
		, size_t size
		, Kind kind )
		: Stmt{ stmtCache, size, kind }
	{
	}

	Container::Container( StmtCache & stmtCache )
		: Stmt{ stmtCache, sizeof( Container ), Kind::eContainer }
	{
	}

	void Container::addStmt( StmtPtr stmt )
	{
		m_statements.emplace_back( std::move( stmt ) );
	}

	void Container::accept( VisitorPtr vis )const
	{
		vis->visitContainerStmt( this );
	}
}
