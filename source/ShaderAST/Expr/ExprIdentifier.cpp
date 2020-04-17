/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprIdentifier.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

#include "ShaderAST/Var/Variable.hpp"

namespace ast::expr
{
	Identifier::Identifier( type::TypesCache & cache
		, var::VariablePtr var )
		: Expr{ cache, var->getType(), Kind::eIdentifier, ( ( var->isConstant() && var->isStatic() ) ? Flag::eConstant : Flag::eNone ) }
		, m_var{ std::move( var ) }
	{
	}

	void Identifier::accept( VisitorPtr vis )
	{
		vis->visitIdentifierExpr( this );
	}
}
