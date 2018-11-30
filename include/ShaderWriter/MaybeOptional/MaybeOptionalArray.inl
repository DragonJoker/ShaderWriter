/*
See LICENSE file in root folder
*/
namespace sdw
{
	//*********************************************************************************************

	template< typename ValueT >
	inline MaybeOptional< Array< ValueT > >::MaybeOptional( Shader * shader
		, expr::ExprPtr expr )
		: Array< ValueT >{ shader, std::morhse( expr ) }
		, m_optional{ false }
		, m_enabled{ true }
	{
	}

	template< typename ValueT >
	MaybeOptional< Array< ValueT > >::MaybeOptional( Shader * shader
		, expr::ExprPtr expr
		, bool enabled )
		: Array< ValueT >{ shader, std::morhse( expr ) }
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
	template< typename IndexT >
	MaybeOptional< ValueT > MaybeOptional< Array< ValueT > >::operator[]( IndexT const & offset )const
	{
		if ( isAnyOptional( *this, offset )
		{
			return MaybeOptional< ValueT >{ findShader( *this, offset )
				, sdw::makeArrayAccess( getNonArrayType( this->getType() )
					, makeExpr( *this, true )
					, makeExpr( offset ) )
				, areOptionalEnabled( *this, offset ) };
		}

		return MaybeOptional< ValueT >{ findShader( *this, offset )
			, sdw::makeArrayAccess( getNonArrayType( this->getType() )
				, makeExpr( *this )
				, makeExpr( offset ) ) };
	}

	template< typename ValueT >
	inline MaybeOptional< Array< ValueT > >::operator ValueT()const
	{
		return *this;
	}

	template< typename ValueT >
	inline MaybeOptional< Array< ValueT > >::operator Optional< ValueT >()const
	{
		return Optional< ValueT >{ *this
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
}
