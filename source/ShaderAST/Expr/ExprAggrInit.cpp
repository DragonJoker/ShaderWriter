/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprAggrInit.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	AggrInit::AggrInit( IdentifierPtr identifier
		, ExprList && initialisers )
		: Expr{ getExprTypesCache( *identifier, initialisers )
			, identifier->getType()
			, Kind::eAggrInit
			, ( isExprConstant( identifier, initialisers )
				? Flag::eConstant
				: Flag::eNone ) }
		, m_identifier{ std::move( identifier ) }
		, m_initialisers{ std::move( initialisers ) }
	{
#if !defined( NDEBUG )
		for ( auto & init : m_initialisers )
		{
			assert( init );
		}
#endif
	}

	AggrInit::AggrInit( type::TypePtr type
		, ExprList && initialisers )
		: Expr{ type->getCache()
			, type
			, Kind::eAggrInit
			, ( isExprConstant( initialisers )
				? Flag::eConstant
				: Flag::eNone ) }
		, m_initialisers{ std::move( initialisers ) }
	{
#if !defined( NDEBUG )
		for ( auto & init : m_initialisers )
		{
			assert( init );
		}
#endif
	}

	void AggrInit::accept( VisitorPtr vis )
	{
		vis->visitAggrInitExpr( this );
	}
}
