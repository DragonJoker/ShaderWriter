/*
See LICENSE file in root folder
*/
namespace sdw
{
	namespace details
	{
		template< typename ParamT >
		bool areOptionalEnabledRec( ParamT const & value )
		{
			return isOptionalEnabled( value );
		}

		template< typename ParamT
			, typename ... ParamsT >
			bool areOptionalEnabledRec( ParamT const & value
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
			addStmt( *findContainer( *this, rhs )
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
			addStmt( *findContainer( *this, rhs )
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
	expr::ExprPtr makeExpr( Optional< T > const & value )
	{
		if ( value.isEnabled() )
		{
			return makeExpr( static_cast< T const & >( value ) );
		}

		return nullptr;
	}

	template< typename T >
	bool isOptionalEnabled( T const & value )
	{
		return true;
	}

	template< typename T >
	bool isOptionalEnabled( Optional< T > const & value )
	{
		return value.isEnabled();
	}

	template< typename ... ParamsT >
	bool areOptionalEnabled( ParamsT const & ... values )
	{
		return details::areOptionalEnabledRec( values... );
	}
}
