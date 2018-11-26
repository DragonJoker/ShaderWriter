/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprIdentifier.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

#include "ShaderAST/Var/Variable.hpp"

namespace ast::expr
{
	Identifier::Identifier( var::VariablePtr var )
		: Expr{ std::move( var->getType() ), Kind::eIdentifier }
		, m_var{ std::move( var ) }
	{
	}

	void Identifier::accept( VisitorPtr vis )
	{
		vis->visitIdentifierExpr( this );
	}
}
