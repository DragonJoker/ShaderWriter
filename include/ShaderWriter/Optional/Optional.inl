/*
See LICENSE file in root folder
*/
namespace sdw
{
	namespace details
	{
		inline bool areOptionalEnabledRec()
		{
			return true;
		}

		template< typename ParamT >
		inline bool areOptionalEnabledRec( ParamT const & value )
		{
			return isOptionalEnabled( value );
		}

		template< typename ParamT
			, typename ... ParamsT >
		inline bool areOptionalEnabledRec( ParamT const & value
				, ParamsT const & ... values )
		{
			return isOptionalEnabled( value )
				&& areOptionalEnabledRec( values... );
		}
	}

	template< typename TypeT >
	Optional< TypeT >::Optional( Shader * shader
		, expr::ExprPtr expr
		, bool enabled )
		: TypeT{ shader, std::move( expr ) }
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
	Optional< TypeT >::Optional( Optional< TypeT > const & rhs )
		: TypeT{ rhs }
		, m_enabled{ rhs.m_enabled }
	{
	}

	template< typename TypeT >
	Optional< TypeT > Optional< TypeT >::operator=( Optional< TypeT > const & rhs )
	{
		if ( m_enabled )
		{
			addStmt( *findShader( *this, rhs )
				, sdw::makeSimple( sdw::makeAssign( this->getType()
					, makeExpr( *this )
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
			addStmt( *findShader( *this, rhs )
				, sdw::makeSimple( sdw::makeAssign( this->getType()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	template< typename TypeT >
	bool Optional< TypeT >::isEnabled()const
	{
		return m_enabled;
	}

	template< typename T >
	inline expr::ExprPtr makeExpr( Optional< T > const & value
		, bool force )
	{
		if ( value.isEnabled() || force )
		{
			return makeExpr( static_cast< T const & >( value ) );
		}

		return nullptr;
	}

	template< typename T >
	inline bool isOptionalEnabled( T const & value )
	{
		return true;
	}

	template< typename T >
	inline bool isOptionalEnabled( Optional< T > const & value )
	{
		return value.isEnabled();
	}

	template< typename ... ParamsT >
	inline bool areOptionalEnabled( ParamsT const & ... values )
	{
		return details::areOptionalEnabledRec( values... );
	}
}
