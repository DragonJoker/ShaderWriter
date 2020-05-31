/*
See LICENSE file in root folder
*/
#include "MaybeOptionalMat3x4.hpp"

namespace sdw
{
	template< typename ValueT >
	MaybeOptional< Mat3x4T< ValueT > >::MaybeOptional( Shader * shader
		, expr::ExprPtr expr )
		: Mat3x4T< ValueT >{ shader, std::move( expr ) }
		, m_optional{ false }
		, m_enabled{ true }
	{
	}

	template< typename ValueT >
	MaybeOptional< Mat3x4T< ValueT > >::MaybeOptional( Shader * shader
		, expr::ExprPtr expr
		, bool enabled )
		: Mat3x4T< ValueT >{ shader, std::move( expr ) }
		, m_optional{ true }
		, m_enabled{ enabled }
	{
	}

	template< typename ValueT >
	inline MaybeOptional< Mat3x4T< ValueT > >::MaybeOptional( Mat3x4T< ValueT > const & rhs )
		: Mat3x4T< ValueT >{ rhs }
		, m_optional{ false }
		, m_enabled{ true }
	{
	}

	template< typename ValueT >
	inline MaybeOptional< Mat3x4T< ValueT > >::MaybeOptional( Optional< Mat3x4T< ValueT > > const & rhs )
		: Mat3x4T< ValueT >{ rhs }
		, m_optional{ true }
		, m_enabled{ rhs.isEnabled() }
	{
	}

	template< typename ValueT >
	MaybeOptional< Mat3x4T< ValueT > >::MaybeOptional( MaybeOptional< Mat3x4T< ValueT > > const & rhs )
		: Mat3x4T< ValueT >{ rhs }
		, m_optional{ rhs.isOptional() }
		, m_enabled{ rhs.isEnabled() }
	{
	}

	template< typename ValueT >
	inline MaybeOptional< Mat3x4T< ValueT > > & MaybeOptional< Mat3x4T< ValueT > >::operator=( Mat3x4T< ValueT > const & rhs )
	{
		if ( isEnabled() )
		{
			Mat3x4T< ValueT >::operator=( rhs );
		}

		return *this;
	}

	template< typename ValueT >
	inline MaybeOptional< Mat3x4T< ValueT > > & MaybeOptional< Mat3x4T< ValueT > >::operator=( Optional< Mat3x4T< ValueT > > const & rhs )
	{
		if ( isEnabled() && rhs.isEnabled() )
		{
			Mat3x4T< ValueT >::operator=( rhs );
		}

		return *this;
	}

	template< typename ValueT >
	inline MaybeOptional< Mat3x4T< ValueT > > & MaybeOptional< Mat3x4T< ValueT > >::operator=( MaybeOptional< Mat3x4T< ValueT > > const & rhs )
	{
		if ( isEnabled() && rhs.isEnabled() )
		{
			Mat3x4T< ValueT >::operator=( rhs );
		}

		return *this;
	}

	template< typename ValueT >
	template< typename IndexT >
	MaybeOptional< Vec4T< ValueT > > MaybeOptional< Mat3x4T< ValueT > >::operator[]( IndexT const & offset )const
	{
		return writeBinOperator< Vec4T< ValueT > >( *this, offset, sdw::makeArrayAccess );
	}

	template< typename ValueT >
	inline MaybeOptional< Mat3x4T< ValueT > >::operator Mat3x4T< ValueT >()const
	{
		return *this;
	}

	template< typename ValueT >
	inline MaybeOptional< Mat3x4T< ValueT > >::operator Optional< Mat3x4T< ValueT > >()const
	{
		return Optional< Mat3x4T< ValueT > >{ *this
			, m_enabled };
	}

	template< typename ValueT >
	inline bool MaybeOptional< Mat3x4T< ValueT > >::isOptional()const
	{
		return m_optional;
	}

	template< typename ValueT >
	inline bool MaybeOptional< Mat3x4T< ValueT > >::isEnabled()const
	{
		return m_enabled;
	}
}
