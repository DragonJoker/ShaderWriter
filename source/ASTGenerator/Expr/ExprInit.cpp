/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprInit.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast
{
	ExprInit::ExprInit( ExprIdentifierPtr identifier
		, ExprPtr initialiser )
		: Expr{ identifier->getType(), Expr::Kind::eInit }
		, m_identifier{ std::move( identifier ) }
		, m_initialiser{ std::move( initialiser ) }
	{
	}

	void ExprInit::accept( ExprVisitorPtr vis )
	{
		vis->visitInitExpr( this );
	}
}
