/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprIdentifier.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

#include "ASTGenerator/Var/Variable.hpp"

namespace ast::expr
{
	Identifier::Identifier( var::VariablePtr var )
		: Expr{ std::move( var->get() ), Kind::eIdentifier }
		, m_var{ std::move( var ) }
	{
	}

	void Identifier::accept( VisitorPtr vis )
	{
		vis->visitIdentifierExpr( this );
	}
}
