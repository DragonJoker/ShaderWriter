/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprInit.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	Init::Init( IdentifierPtr identifier
		, ExprPtr initialiser )
		: Expr{ getExprTypesCache( initialiser ), std::move( identifier->getType() ), Kind::eInit }
		, m_identifier{ std::move( identifier ) }
		, m_initialiser{ std::move( initialiser ) }
	{
	}

	void Init::accept( VisitorPtr vis )
	{
		vis->visitInitExpr( this );
	}
}
