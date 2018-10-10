/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprIdentifier.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

#include "ASTGenerator/Var/Variable.hpp"

namespace ast
{
	ExprIdentifier::ExprIdentifier( VariablePtr var )
		: Expr{ var->getType(), Expr::Kind::eIdentifier }
		, m_var{ std::move( var ) }
	{
	}

	void ExprIdentifier::accept( ExprVisitorPtr vis )
	{
		vis->visitIdentifierExpr( this );
	}
}
