/*
See LICENSE file in root folder
*/
#include <ASTGenerator/Expr/ExprArrayAccess.hpp>

namespace sdw
{
	//*********************************************************************************************

	template< typename T >
	Array< T >::Array( stmt::Container * container
		, expr::ExprPtr expr )
		: T{ container, std::move( expr ) }
	{
	}

	template< typename T >
	template< typename U >
	T Array< T >::operator[]( U const & offset )
	{
		return T{ T::m_container
			, expr::makeArrayAccess( makeType( m_expr->getType()->getKind() )
				, makeExpr( m_expr )
				, makeExpr( offset ) ) };
	}

	template< typename T >
	template< typename U >
	T Array< T >::operator[]( U const & offset )const
	{
		return T{ T::m_container
			, expr::makeArrayAccess( makeType( m_expr->getType()->getKind() )
				, makeExpr( m_expr )
				, makeExpr( offset ) ) };
	}

	template< typename TypeT >
	expr::ExprPtr makeExpr( Array< TypeT > const & value )
	{
		return makeExpr( value.m_expr );
	}

	//*********************************************************************************************
}
