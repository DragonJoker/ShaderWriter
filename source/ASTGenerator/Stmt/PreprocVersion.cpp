/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Stmt/PreprocVersion.hpp"

#include "ASTGenerator/Stmt/StmtVisitor.hpp"

namespace ast
{
	PreprocVersion::PreprocVersion( std::string name )
		: Stmt{ Kind::ePreprocVersion }
		, m_name{ std::move( name ) }
	{
	}

	void PreprocVersion::accept( StmtVisitorPtr vis )
	{
		vis->visitPreprocVersion( this );
	}
}
