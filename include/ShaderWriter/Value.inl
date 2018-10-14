/*
See LICENSE file in root folder
*/
namespace sdw
{
	//***********************************************************************************************

	namespace details
	{
		inline Shader * getShader( Value const & value )
		{
			return value.getShader();
		}

		inline Shader * getShader( bool const & value )
		{
			return nullptr;
		}

		inline Shader * getShader( int32_t const & value )
		{
			return nullptr;
		}

		inline Shader * getShader( int64_t const & value )
		{
			return nullptr;
		}

		inline Shader * getShader( uint32_t const & value )
		{
			return nullptr;
		}

		inline Shader * getShader( uint64_t const & value )
		{
			return nullptr;
		}

		inline Shader * getShader( float const & value )
		{
			return nullptr;
		}

		inline Shader * getShader( double const & value )
		{
			return nullptr;
		}

		inline Shader * getShader( long double const & value )
		{
			return nullptr;
		}
	}

	//***********************************************************************************************

	template< typename Value, typename ... Values >
	inline void findShaderRec( Shader *& result
		, Value const & current
		, Values const & ... values );

	template< typename Value >
	inline void findShaderRec( Shader *& result
		, Value const & last )
	{
		if ( !result )
		{
			result = details::getShader( last );
		}
	}

	template< typename Value, typename ... Values >
	inline void findShaderRec( Shader *& result
		, Value const & current
		, Values const & ... values )
	{
		if ( !result )
		{
			result = details::getShader( current );
			findShaderRec( result, values... );
		}
	}

	template< typename ... ValuesT >
	inline Shader * findShader( ValuesT const & ... values )
	{
		Shader * result{ nullptr };
		findShaderRec( result, values... );
		return result;
	}

	template< typename ... ValuesT >
	inline stmt::Container * findContainer( ValuesT const & ... values )
	{
		auto shader = findShader( values... );
		stmt::Container * result{ nullptr };

		if ( shader )
		{
			result = getContainer( *shader );
		}

		return result;
	}

	//***********************************************************************************************

	template< typename T >
	T const & operator-( T const & value )
	{
		addStmt( *findContainer( value )
			, expr::makeUnaryMinus( clone( value.m_expr ) ) );
		return value;
	}

	template< typename T >
	T const & operator+( T const & value )
	{
		return value;
	}

	//***********************************************************************************************
}
