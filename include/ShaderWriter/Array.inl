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
			, expr::makeArrayAccess( makeType( m_expr->get()->getKind() )
				, make( m_expr )
				, make( offset ) ) };
	}

	template< typename T >
	template< typename U >
	T Array< T >::operator[]( U const & offset )const
	{
		return T{ T::m_container
			, expr::makeArrayAccess( makeType( m_expr->get()->getKind() )
				, make( m_expr )
				, make( offset ) ) };
	}

	template< typename TypeT >
	expr::ExprPtr make( Array< TypeT > const & value )
	{
		return make( value.m_expr );
	}

	//*********************************************************************************************
}
