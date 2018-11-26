/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/PreprocVersion.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	PreprocVersion::PreprocVersion( std::string name )
		: Stmt{ Kind::ePreprocVersion }
		, m_name{ std::move( name ) }
	{
	}

	void PreprocVersion::accept( VisitorPtr vis )
	{
		vis->visitPreprocVersion( this );
	}
}
