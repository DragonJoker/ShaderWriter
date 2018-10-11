/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Stmt/PreprocIfDef.hpp"

#include "ASTGenerator/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	PreprocIfDef::PreprocIfDef( expr::IdentifierPtr identExpr )
		: Stmt{ Kind::ePreprocIfDef }
		, m_identExpr{ std::move( identExpr ) }
	{
	}

	void PreprocIfDef::accept( VisitorPtr vis )
	{
		vis->visitPreprocIfDef( this );
	}
}
