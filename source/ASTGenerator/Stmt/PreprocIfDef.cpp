/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Stmt/PreprocIfDef.hpp"

#include "ASTGenerator/Stmt/StmtVisitor.hpp"

namespace ast
{
	PreprocIfDef::PreprocIfDef( ExprIdentifierPtr identExpr )
		: Stmt{ Kind::ePreprocIfDef }
		, m_identExpr{ std::move( identExpr ) }
	{
	}

	void PreprocIfDef::accept( StmtVisitorPtr vis )
	{
		vis->visitPreprocIfDef( this );
	}
}
