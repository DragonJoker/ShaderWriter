/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Stmt/StmtComment.hpp"

#include "ASTGenerator/Stmt/StmtVisitor.hpp"

namespace ast::stmt
{
	Comment::Comment( std::string text )
		: Stmt{ Kind::eComment }
		, m_text{ std::move( text ) }
	{
	}

	void Comment::accept( VisitorPtr vis )
	{
		vis->visitCommentStmt( this );
	}
}
