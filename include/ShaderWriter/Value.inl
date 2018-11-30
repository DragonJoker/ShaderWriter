/*
See LICENSE file in root folder
*/
namespace sdw
{
	//***********************************************************************************************

	namespace details
	{
		template< typename ValueT >
		inline Shader * getShader( ValueT const & value )
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

	inline void findShaderRec( Shader *& result )
	{
	}

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
	T operator-( T const & value )
	{
		return T{ findShader( value )
			, sdw::makeUnMinus( makeExpr( value ) ) };
	}

	template< typename T >
	T operator+( T const & value )
	{
		return value;
	}

	//***********************************************************************************************
}
