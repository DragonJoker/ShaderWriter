/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/PreprocExtension.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	PreprocExtension::PreprocExtension( std::string name
		, ExtStatus status )
		: Stmt{ Kind::ePreprocExtension }
		, m_name{ std::move( name ) }
		, m_status{ status }
	{
	}

	void PreprocExtension::accept( VisitorPtr vis )
	{
		vis->visitPreprocExtension( this );
	}
}
