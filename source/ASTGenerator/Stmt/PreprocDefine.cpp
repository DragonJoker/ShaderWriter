/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Stmt/PreprocDefine.hpp"

#include "ASTGenerator/Stmt/StmtVisitor.hpp"

namespace ast
{
	PreprocDefine::PreprocDefine( std::string name
		, ExprPtr expr )
		: Stmt{ Kind::ePreprocDefine }
		, m_name{ std::move( name ) }
		, m_expr{ std::move( expr ) }
	{
	}

	void PreprocDefine::accept( StmtVisitorPtr vis )
	{
		vis->visitPreprocDefine( this );
	}
}
