/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/PreprocVersion.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	PreprocVersion::PreprocVersion( StmtCache & stmtCache
		, std::string name )
		: Stmt{ stmtCache, sizeof( PreprocVersion ), Kind::ePreprocVersion }
		, m_name{ std::move( name ) }
	{
	}

	void PreprocVersion::accept( VisitorPtr vis )const
	{
		vis->visitPreprocVersion( this );
	}
}
