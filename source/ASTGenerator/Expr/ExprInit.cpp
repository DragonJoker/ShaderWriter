/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprInit.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	Init::Init( IdentifierPtr identifier
		, ExprPtr initialiser )
		: Expr{ std::move( identifier->get() ), Kind::eInit }
		, m_identifier{ std::move( identifier ) }
		, m_initialiser{ std::move( initialiser ) }
	{
	}

	void Init::accept( VisitorPtr vis )
	{
		vis->visitInitExpr( this );
	}
}
