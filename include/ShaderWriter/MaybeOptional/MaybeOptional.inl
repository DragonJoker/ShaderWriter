/*
See LICENSE file in root folder
*/
namespace sdw
{
	//*************************************************************************

	namespace details
	{
		template< typename ValueT >
		struct IsOptional
		{
			static inline bool get( ValueT const & )
			{
				return false;
			}
		};
		
		template< typename ValueT >
		struct IsOptional< Optional< ValueT > >
		{
			static inline bool get( Optional< ValueT > const & )
			{
				return true;
			}
		};
		
		template< typename ValueT >
		struct IsOptional< MaybeOptional< ValueT > >
		{
			static inline bool get( MaybeOptional< ValueT > const & v )
			{
				return v.isOptional();
			}
		};

		inline bool isAnyOptionalRec()
		{
			return false;
		}

		template< typename ParamT >
		inline bool isAnyOptionalRec( ParamT const & value )
		{
			return IsOptional< ParamT >::get( value );
		}

		template< typename ParamT
			, typename ... ParamsT >
		inline bool isAnyOptionalRec( ParamT const & value
				, ParamsT const & ... values )
		{
			return IsOptional< ParamT >::get( value )
				|| isAnyOptionalRec( std::forward< ParamsT const & >( values )... );
		}
	}

	//*************************************************************************

	template< typename ValueT >
	inline MaybeOptional< ValueT >::MaybeOptional( Shader * shader
		, expr::ExprPtr expr )
		: ValueT{ shader, std::move( expr ) }
		, m_optional{ false }
		, m_enabled{ true }
	{
	}

	template< typename ValueT >
	inline MaybeOptional< ValueT >::MaybeOptional( Shader * shader
		, expr::ExprPtr expr
		, bool enabled )
		: ValueT{ shader, std::move( expr ) }
		, m_optional{ true }
		, m_enabled{ enabled }
	{
	}

	template< typename ValueT >
	inline MaybeOptional< ValueT >::MaybeOptional( ValueT const & rhs )
		: ValueT{ rhs }
		, m_optional{ false }
		, m_enabled{ true }
	{
	}

	template< typename ValueT >
	inline MaybeOptional< ValueT >::MaybeOptional( Optional< ValueT > const & rhs )
		: ValueT{ rhs }
		, m_optional{ true }
		, m_enabled{ rhs.isEnabled() }
	{
	}

	template< typename ValueT >
	inline MaybeOptional< ValueT >::MaybeOptional( MaybeOptional< ValueT > const & rhs )
		: ValueT{ rhs }
		, m_optional{ rhs.isOptional() }
		, m_enabled{ rhs.isEnabled() }
	{
	}

	template< typename ValueT >
	inline MaybeOptional< ValueT >::operator ValueT()const
	{
		return *this;
	}

	template< typename ValueT >
	inline MaybeOptional< ValueT >::operator Optional< ValueT >()const
	{
		return Optional< ValueT >{ *this
			, m_enabled };
	}

	template< typename ValueT >
	inline bool MaybeOptional< ValueT >::isOptional()const
	{
		return m_optional;
	}

	template< typename ValueT >
	inline bool MaybeOptional< ValueT >::isEnabled()const
	{
		return m_enabled;
	}

	//*************************************************************************

	template< typename ... ParamsT >
	inline bool isAnyOptional( ParamsT const & ... params )
	{
		return details::isAnyOptionalRec( std::forward< ParamsT const & >( params )... );
	}

	template< typename T >
	inline bool isOptionalEnabled( MaybeOptional< T > const & value )
	{
		return value.isEnabled();
	}

	template< typename ValueT >
	inline expr::ExprPtr makeExpr( MaybeOptional< ValueT > const & value
		, bool force )
	{
		if ( value.isEnabled() || force )
		{
			return makeExpr( static_cast< ValueT const & >( value ) );
		}

		return nullptr;
	}

	//*************************************************************************
}
