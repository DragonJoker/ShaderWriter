/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/Expr.hpp"

#include "ShaderAST/Visitors/CloneExpr.hpp"

namespace ast::expr
{
	Expr::Expr( ExprCache & exprCache
		, size_t size
		, type::TypesCache & typesCache
		, type::TypePtr type
		, Kind kind
		, Flag flag )
		: m_exprCache{ &exprCache }
		, m_typesCache{ &typesCache }
		, m_size{ size }
		, m_kind{ kind }
		, m_type{ std::move( type ) }
		, m_flags{ uint32_t( flag ) }
	{
	}

	ExprPtr Expr::clone()const
	{
		return ExprCloner::submit( *m_exprCache, *this );
	}
}
