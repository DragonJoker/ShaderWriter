/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Stmt/PreprocExtension.hpp"

#include "ASTGenerator/Stmt/StmtVisitor.hpp"

namespace ast
{
	PreprocExtension::PreprocExtension( std::string name
		, Status status )
		: Stmt{ Kind::ePreprocExtension }
		, m_name{ std::move( name ) }
		, m_status{ status }
	{
	}

	void PreprocExtension::accept( StmtVisitorPtr vis )
	{
		vis->visitPreprocExtension( this );
	}
}
