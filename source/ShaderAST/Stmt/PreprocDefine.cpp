/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/PreprocDefine.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	PreprocDefine::PreprocDefine( EntityName nameId
		, expr::ExprPtr expr )
		: Stmt{ Kind::ePreprocDefine }
		, m_nameId{ std::move( nameId ) }
		, m_expr{ std::move( expr ) }
	{
	}

	void PreprocDefine::accept( VisitorPtr vis )
	{
		vis->visitPreprocDefine( this );
	}
}
