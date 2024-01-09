/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprIdentifier.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

#include "ShaderAST/Var/Variable.hpp"

namespace ast::expr
{
	Identifier::Identifier( ExprCache & exprCache
		, type::TypesCache & typesCache
		, var::VariablePtr var )
		: Expr{ exprCache
			, sizeof( Identifier )
			, typesCache
			, var->getType()
			, Kind::eIdentifier
			, ( var->isConstant() ? Flag::eConstant : Flag::eNone ) }
		, m_var{ std::move( var ) }
	{
	}

	Identifier::Identifier( ExprCache & exprCache
		, Identifier const & rhs )
		: Expr{ exprCache
			, sizeof( Identifier )
			, rhs.getTypesCache()
			, rhs.getType()
			, Kind::eIdentifier
			, Flag( rhs.getFlags() ) }
		, m_var{ rhs.m_var }
	{
	}

	void Identifier::accept( VisitorPtr vis )const
	{
		vis->visitIdentifierExpr( this );
	}
}
