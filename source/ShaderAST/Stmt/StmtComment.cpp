/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtComment.hpp"

#include "ShaderAST/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	Comment::Comment( StmtCache & stmtCache
		, std::string text )
		: Stmt{ stmtCache, sizeof( Comment ), Kind::eComment }
		, m_text{ std::move( text ) }
	{
	}

	void Comment::accept( VisitorPtr vis )const
	{
		vis->visitCommentStmt( this );
	}
}
