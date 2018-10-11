/*
See LICENSE file in root folder
*/
#include <ASTGenerator/Expr/ExprAssign.hpp>
#include <ASTGenerator/Stmt/StmtSimple.hpp>

namespace sdw
{
	template< typename TypeT >
	Optional< TypeT >::Optional( stmt::Container * container
		, expr::ExprPtr expr
		, bool enabled )
		: TypeT{ container, std::move( expr ) }
		, m_enabled{ enabled }
	{
	}

	template< typename TypeT >
	Optional< TypeT >::Optional( TypeT const & other
		, bool enabled )
		: TypeT{ other }
		, m_enabled{ enabled }
	{
	}

	template< typename TypeT >
	Optional< TypeT > Optional< TypeT >::operator=( Optional< TypeT > const & rhs )
	{
		if ( m_enabled )
		{
			addStmt( *m_container
				, stmt::makeSimple( expr::makeAssign( m_expr->getType()
					, makeExpr( m_expr )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	template< typename TypeT >
	template< typename T >
	Optional< TypeT > Optional< TypeT >::operator=( T const & rhs )
	{
		if ( m_enabled )
		{
			addStmt( *m_container
				, stmt::makeSimple( expr::makeAssign( m_expr->getType()
					, makeExpr( m_expr )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	template< typename TypeT >
	bool Optional< TypeT >::isEnabled()const
	{
		return m_enabled;
	}

	template< typename TypeT >
	Optional< TypeT >::operator Optional< Value >()const
	{
		return Optional< Value >{ *this, isEnabled() };
	}

	template< typename T >
	expr::ExprPtr makeExpr( Optional< T > const & value )
	{
		if ( value.isEnabled() )
		{
			return makeExpr( value.m_expr );
		}

		return nullptr;
	}
}
