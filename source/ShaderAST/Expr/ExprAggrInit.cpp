/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprAggrInit.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	AggrInit::AggrInit( IdentifierPtr identifier
		, ExprList && initialisers )
		: Expr{ std::move( identifier->getType() ), Kind::eAggrInit }
		, m_identifier{ std::move( identifier ) }
		, m_initialisers{ std::move( initialisers ) }
	{
	}

	AggrInit::AggrInit( type::TypePtr type
		, ExprList && initialisers )
		: Expr{ std::move( type ), Kind::eAggrInit }
		, m_initialisers{ std::move( initialisers ) }
	{
	}

	void AggrInit::accept( VisitorPtr vis )
	{
		vis->visitAggrInitExpr( this );
	}
}
