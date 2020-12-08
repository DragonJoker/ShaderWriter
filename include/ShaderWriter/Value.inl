/*
See LICENSE file in root folder
*/
namespace sdw
{
	//***********************************************************************************************

	namespace details
	{
		inline ShaderWriter * getWriter( bool const & value )
		{
			return nullptr;
		}
		
		inline ShaderWriter * getWriter( int32_t const & value )
		{
			return nullptr;
		}

		inline ShaderWriter * getWriter( int64_t const & value )
		{
			return nullptr;
		}

		inline ShaderWriter * getWriter( uint32_t const & value )
		{
			return nullptr;
		}

		inline ShaderWriter * getWriter( uint64_t const & value )
		{
			return nullptr;
		}

		inline ShaderWriter * getWriter( float const & value )
		{
			return nullptr;
		}

		inline ShaderWriter * getWriter( double const & value )
		{
			return nullptr;
		}

		inline ShaderWriter * getWriter( long double const & value )
		{
			return nullptr;
		}

		template< typename ValueT >
		inline ShaderWriter * getWriter( ValueT const & value )
		{
			return value.getWriter();
		}
	}

	//***********************************************************************************************

	inline void findWriterRec( ShaderWriter *& result )
	{
	}

	template< typename ValueT >
	inline void findWriterRec( ShaderWriter *& result
		, ValueT const & last )
	{
		result = details::getWriter( last );
	}

	template< typename ValueT, typename ... ValuesT >
	inline void findWriterRec( ShaderWriter *& result
		, ValueT const & current
		, ValuesT const & ... values )
	{
		result = details::getWriter( current );

		if ( !result )
		{
			findWriterRec( result, values... );
		}
	}

	template< typename ... ValuesT >
	inline ShaderWriter * findWriter( ValuesT const & ... values )
	{
		ShaderWriter * result{ nullptr };
		findWriterRec( result, values... );
		return result;
	}

	//***********************************************************************************************

	namespace details
	{
		inline void findExprRec( ast::expr::ExprPtr & result
			, ShaderWriter & writer )
		{
		}

		template< typename ValueT >
		inline void findExprRec( ast::expr::ExprPtr & result
			, ShaderWriter & writer
			, ValueT const & last )
		{
			result = makeExpr( writer, last );
		}

		template< typename ValueT, typename ... ValuesT >
		inline void findExprRec( ast::expr::ExprPtr & result
			, ShaderWriter & writer
			, ValueT const & current
			, ValuesT const & ... values )
		{
			result = makeExpr( writer, current );

			if ( !result )
			{
				findExprRec( result, writer, values... );
			}
		}

		template< typename ... ValuesT >
		inline ast::expr::ExprPtr findExpr( ValuesT const & ... values )
		{
			ast::expr::ExprPtr result{ nullptr };
			auto & writer = *findWriter( values... );
			findExprRec( result, writer, values... );
			return result;
		}
	}

	//***********************************************************************************************

	template< typename ... ValuesT >
	inline ast::type::TypesCache & findTypesCache( ValuesT const & ... values )
	{
		ShaderWriter * writer = findWriter( values... );

		if ( writer )
		{
			return getTypesCache( *writer );
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
		ShaderWriter * writer = findWriter( values... );
		stmt::Container * result{ nullptr };

		if ( writer )
		{
			result = getContainer( *writer );
		}

		return result;
	}

	//***********************************************************************************************

	template< typename ReturnT, typename OperandT, typename CreatorT >
	inline ReturnT writeUnOperator( OperandT const & operand
		, CreatorT creator )
	{
		auto & writer = *findWriter( operand );
		return ReturnT{ writer
			, creator( makeExpr( writer, operand ) ) };
	}

	template< typename ReturnT, typename LhsT, typename RhsT, typename CreatorT >
	inline ReturnT writeBinOperator( LhsT const & lhs
		, RhsT const & rhs
		, CreatorT creator )
	{
		auto & writer = *findWriter( lhs, rhs );
		return ReturnT{ writer
			, creator( ReturnT::makeType( findTypesCache( lhs, rhs ) )
				, makeExpr( writer, lhs )
				, makeExpr( writer, rhs ) ) };
	}

	//***********************************************************************************************
}
