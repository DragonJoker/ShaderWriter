/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/PreprocExtension.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	PreprocExtension::PreprocExtension( StmtCache & stmtCache
		, std::string name
		, ExtStatus status )
		: Stmt{ stmtCache, sizeof( PreprocExtension ), Kind::ePreprocExtension }
		, m_name{ std::move( name ) }
		, m_status{ status }
	{
	}

	void PreprocExtension::accept( VisitorPtr vis )const
	{
		vis->visitPreprocExtension( this );
	}
}
