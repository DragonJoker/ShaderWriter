/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Stmt/PreprocDefine.hpp"

#include "ASTGenerator/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	PreprocDefine::PreprocDefine( std::string name
		, expr::ExprPtr expr )
		: Stmt{ Kind::ePreprocDefine }
		, m_name{ std::move( name ) }
		, m_expr{ std::move( expr ) }
	{
	}

	void PreprocDefine::accept( VisitorPtr vis )
	{
		vis->visitPreprocDefine( this );
	}
}
