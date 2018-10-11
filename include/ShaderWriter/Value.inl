/*
See LICENSE file in root folder
*/
namespace sdw
{
	//***********************************************************************************************

	namespace details
	{
		inline stmt::Container * getContainer( Value const & value )
		{
			return value.m_container;
		}

		inline stmt::Container * getContainer( bool const & value )
		{
			return nullptr;
		}

		inline stmt::Container * getContainer( int32_t const & value )
		{
			return nullptr;
		}

		inline stmt::Container * getContainer( int64_t const & value )
		{
			return nullptr;
		}

		inline stmt::Container * getContainer( uint32_t const & value )
		{
			return nullptr;
		}

		inline stmt::Container * getContainer( uint64_t const & value )
		{
			return nullptr;
		}

		inline stmt::Container * getContainer( float const & value )
		{
			return nullptr;
		}

		inline stmt::Container * getContainer( double const & value )
		{
			return nullptr;
		}

		inline stmt::Container * getContainer( long double const & value )
		{
			return nullptr;
		}
	}

	//***********************************************************************************************

	template< typename Value, typename ... Values >
	inline void findContainerRec( stmt::Container *& result
		, Value const & current
		, Values const & ... values );

	template< typename Value >
	inline void findContainerRec( stmt::Container *& result
		, Value const & last )
	{
		if ( !result )
		{
			result = details::getContainer( last );
		}
	}

	template< typename Value, typename ... Values >
	inline void findContainerRec( stmt::Container *& result
		, Value const & current
		, Values const & ... values )
	{
		if ( !result )
		{
			result = details::getContainer( current );
			findContainerRec( result, values... );
		}
	}

	template< typename ... ValuesT >
	inline stmt::Container * findContainer( ValuesT const & ... values )
	{
		stmt::Container * result{ nullptr };
		findContainerRec( result, values... );
		return result;
	}

	//***********************************************************************************************

	template< typename T >
	T const & operator-( T const & value )
	{
		addStmt( *value.m_container, expr::makeUnaryMinus( clone( value.m_expr ) ) );
		return value;
	}

	template< typename T >
	T const & operator+( T const & value )
	{
		return value;
	}

	//***********************************************************************************************
}
