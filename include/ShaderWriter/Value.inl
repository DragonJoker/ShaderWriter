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

	inline void findShaderRec( Shader *& result )
	{
	}

	template< typename ValueT >
	inline void findShaderRec( Shader *& result
		, ValueT const & last )
	{
		result = details::getShader( last );
	}

	template< typename ValueT, typename ... ValuesT >
	inline void findShaderRec( Shader *& result
		, ValueT const & current
		, ValuesT const & ... values )
	{
		result = details::getShader( current );

		if ( !result )
		{
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

	inline Shader * findShader( ShaderWriter const & value )
	{
		return &sdw::getShader( value );
	}

	//***********************************************************************************************

	namespace details
	{
		inline void findExprRec( ast::expr::ExprPtr & result
			, Shader & shader )
		{
		}

		template< typename ValueT >
		inline void findExprRec( ast::expr::ExprPtr & result
			, Shader & shader
			, ValueT const & last )
		{
			result = makeExpr( shader, last );
		}

		template< typename ValueT, typename ... ValuesT >
		inline void findExprRec( ast::expr::ExprPtr & result
			, Shader & shader
			, ValueT const & current
			, ValuesT const & ... values )
		{
			result = makeExpr( shader, current );

			if ( !result )
			{
				findExprRec( result, shader, values... );
			}
		}

		template< typename ... ValuesT >
		inline ast::expr::ExprPtr findExpr( ValuesT const & ... values )
		{
			ast::expr::ExprPtr result{ nullptr };
			auto & shader = *findShader( values... );
			findExprRec( result, shader, values... );
			return result;
		}
	}

	//***********************************************************************************************

	template< typename ... ValuesT >
	inline ast::type::TypesCache & findTypesCache( ValuesT const & ... values )
	{
		Shader * shader = findShader( values... );

		if ( shader )
		{
			return getTypesCache( *shader );
		}

		auto expr = details::findExpr( values... );
		assert( expr );
		return expr->getCache();
	}

	inline ast::type::TypesCache & findTypesCache( ShaderWriter const & value )
	{
		return sdw::getTypesCache( value );
	}

	//***********************************************************************************************

	template< typename ... ValuesT >
	inline stmt::Container * findContainer( ValuesT const & ... values )
	{
		Shader * shader = findShader( values... );
		stmt::Container * result{ nullptr };

		if ( shader )
		{
			result = getContainer( *shader );
		}

		return result;
	}

	//***********************************************************************************************

	template< typename ReturnT, typename OperandT, typename CreatorT >
	inline ReturnT writeUnOperator( OperandT const & operand
		, CreatorT creator )
	{
		auto & shader = *findShader( operand );
		return ReturnT{ &shader
			, creator( makeExpr( shader, operand ) ) };
	}

	template< typename ReturnT, typename LhsT, typename RhsT, typename CreatorT >
	inline ReturnT writeBinOperator( LhsT const & lhs
		, RhsT const & rhs
		, CreatorT creator )
	{
		auto & shader = *findShader( lhs, rhs );
		return ReturnT{ &shader
			, creator( ReturnT::makeType( findTypesCache( lhs, rhs ) )
				, makeExpr( shader, lhs )
				, makeExpr( shader, rhs ) ) };
	}

	//***********************************************************************************************
}
