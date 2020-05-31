/*
See LICENSE file in root folder
*/
namespace sdw
{
	//*********************************************************************************************

	template< typename ValueT >
	inline MaybeOptional< Array< ValueT > >::MaybeOptional( Shader * shader
		, expr::ExprPtr expr )
		: Array< ValueT >{ shader, std::move( expr ) }
		, m_optional{ false }
		, m_enabled{ true }
	{
	}

	template< typename ValueT >
	MaybeOptional< Array< ValueT > >::MaybeOptional( Shader * shader
		, expr::ExprPtr expr
		, bool enabled )
		: Array< ValueT >{ shader, std::move( expr ) }
		, m_optional{ true }
		, m_enabled{ enabled }
	{
	}

	template< typename ValueT >
	inline MaybeOptional< Array< ValueT > >::MaybeOptional( Array< ValueT > const & rhs )
		: Array< ValueT >{ rhs }
		, m_optional{ false }
		, m_enabled{ true }
	{
	}

	template< typename ValueT >
	inline MaybeOptional< Array< ValueT > >::MaybeOptional( Optional< Array< ValueT > > const & rhs )
		: Array< ValueT >{ rhs }
		, m_optional{ true }
		, m_enabled{ rhs.isEnabled() }
	{
	}

	template< typename ValueT >
	MaybeOptional< Array< ValueT > >::MaybeOptional( MaybeOptional< Array< ValueT > > const & rhs )
		: Array< ValueT >{ rhs }
		, m_optional{ rhs.isOptional() }
		, m_enabled{ rhs.isEnabled() }
	{
	}

	template< typename ValueT >
	inline MaybeOptional< Array< ValueT > > & MaybeOptional< Array< ValueT > >::operator=( Array< ValueT > const & rhs )
	{
		if ( isEnabled() )
		{
			Array< ValueT >::operator=( rhs );
		}

		return *this;
	}

	template< typename ValueT >
	inline MaybeOptional< Array< ValueT > > & MaybeOptional< Array< ValueT > >::operator=( Optional< Array< ValueT > > const & rhs )
	{
		if ( isEnabled() && rhs.isEnabled() )
		{
			Array< ValueT >::operator=( rhs );
		}

		return *this;
	}

	template< typename ValueT >
	inline MaybeOptional< Array< ValueT > > & MaybeOptional< Array< ValueT > >::operator=( MaybeOptional< Array< ValueT > > const & rhs )
	{
		if ( isEnabled() && rhs.isEnabled() )
		{
			Array< ValueT >::operator=( rhs );
		}

		return *this;
	}

	template< typename ValueT >
	template< typename IndexT >
	MaybeOptional< ValueT > MaybeOptional< Array< ValueT > >::operator[]( IndexT const & offset )const
	{
		return writeBinOperator< MaybeOptional< ValueT > >( *this, offset, sdw::makeArrayAccess );
	}

	template< typename ValueT >
	inline MaybeOptional< Array< ValueT > >::operator Array< ValueT >()const
	{
		return *this;
	}

	template< typename ValueT >
	inline MaybeOptional< Array< ValueT > >::operator Optional< Array< ValueT > >()const
	{
		return Optional< Array< ValueT > >{ *this
			, m_enabled };
	}

	template< typename ValueT >
	inline bool MaybeOptional< Array< ValueT > >::isOptional()const
	{
		return m_optional;
	}

	template< typename ValueT >
	inline bool MaybeOptional< Array< ValueT > >::isEnabled()const
	{
		return m_enabled;
	}

	//*********************************************************************************************

	template< typename ValueT >
	inline Optional< Array< ValueT > > & Optional< Array< ValueT > >::operator=( MaybeOptional< Array< ValueT > > const & rhs )
	{
		if ( isEnabled() && rhs.isEnabled() )
		{
			Array< ValueT >::operator=( rhs );
		}

		return *this;
	}

	//*********************************************************************************************
}
