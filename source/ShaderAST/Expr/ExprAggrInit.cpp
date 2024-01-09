/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprAggrInit.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	AggrInit::AggrInit( ExprCache & exprCache
		, IdentifierPtr identifier
		, ExprList initialisers )
		: Expr{ exprCache
			, sizeof( AggrInit )
			, getExprTypesCache( *identifier, initialisers )
			, identifier->getType()
			, Kind::eAggrInit
			, ( isExprConstant( identifier, initialisers )
				? Flag::eConstant
				: Flag::eNone ) }
		, m_identifier{ std::move( identifier ) }
		, m_initialisers{ std::move( initialisers ) }
	{
#if !defined( NDEBUG )
		for ( auto const & init : m_initialisers )
		{
			assert( init );
		}
#endif
	}

	AggrInit::AggrInit( ExprCache & exprCache
		, type::TypePtr type
		, ExprList initialisers )
		: Expr{ exprCache
			, sizeof( AggrInit )
			, type->getTypesCache()
			, type
			, Kind::eAggrInit
			, ( isExprConstant( initialisers )
				? Flag::eConstant
				: Flag::eNone ) }
		, m_initialisers{ std::move( initialisers ) }
	{
#if !defined( NDEBUG )
		for ( auto const & init : m_initialisers )
		{
			assert( init );
		}
#endif
	}

	void AggrInit::accept( VisitorPtr vis )const
	{
		vis->visitAggrInitExpr( this );
	}
}
