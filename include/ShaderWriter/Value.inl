/*
See LICENSE file in root folder
*/
namespace sdw
{
	//***********************************************************************************************

	namespace details
	{
	//*************************************************************************

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

		template< typename TypeT >
		struct TypeGetter
		{
			static inline ast::type::TypePtr get( ShaderWriter & writer, TypeT const & value )
			{
				return value.getType();
			}
		};

		template<>
		struct TypeGetter< int32_t >
		{
			static inline ast::type::TypePtr get( ShaderWriter & writer, int32_t )
			{
				return getTypesCache( writer ).getInt();
			}
		};

		template<>
		struct TypeGetter< uint32_t >
		{
			static inline ast::type::TypePtr get( ShaderWriter & writer, uint32_t )
			{
				return getTypesCache( writer ).getUInt();
			}
		};

		template<>
		struct TypeGetter< float >
		{
			static inline ast::type::TypePtr get( ShaderWriter & writer, float )
			{
				return getTypesCache( writer ).getFloat();
			}
		};

		template<>
		struct TypeGetter< double >
		{
			static inline ast::type::TypePtr get( ShaderWriter & writer, double )
			{
				return getTypesCache( writer ).getDouble();
			}
		};

		template< typename TypeT >
		inline ast::type::TypePtr getType( ShaderWriter & writer, TypeT const & value )
		{
			return TypeGetter< TypeT >::get( writer, value );
		}

		inline ShaderWriter * getWriter( bool const & value )
		{
			return &getCurrentWriter();
		}
		
		inline ShaderWriter * getWriter( int32_t const & value )
		{
			return &getCurrentWriter();
		}

		inline ShaderWriter * getWriter( int64_t const & value )
		{
			return &getCurrentWriter();
		}

		inline ShaderWriter * getWriter( uint32_t const & value )
		{
			return &getCurrentWriter();
		}

		inline ShaderWriter * getWriter( uint64_t const & value )
		{
			return &getCurrentWriter();
		}

		inline ShaderWriter * getWriter( float const & value )
		{
			return &getCurrentWriter();
		}

		inline ShaderWriter * getWriter( double const & value )
		{
			return &getCurrentWriter();
		}

		inline ShaderWriter * getWriter( long double const & value )
		{
			return &getCurrentWriter();
		}

		template< typename ValueT >
		inline ShaderWriter * getWriter( ValueT const & value )
		{
			return value.getWriter();
		}

		inline ShaderWriter * getWriter( ShaderWriter & value )
		{
			return &value;
		}
	}

	//***********************************************************************************************

	template< typename ValueT >
	inline bool isOptionalEnabled( ValueT const & value )
	{
		return value.isEnabled();
	}

	template< typename ... ParamsT >
	inline bool areOptionalEnabled( ParamsT const & ... values )
	{
		return details::areOptionalEnabledRec( values... );
	}

	//***********************************************************************************************

	inline void findWriterRec( ShaderWriter *& result )
	{
	}

	template< typename ValueT >
	inline void findWriterRec( ShaderWriter *& result
		, ValueT && last )
	{
		result = details::getWriter( last );
	}

	template< typename ValueT, typename ... ValuesT >
	inline void findWriterRec( ShaderWriter *& result
		, ValueT && current
		, ValuesT && ... values )
	{
		result = details::getWriter( current );

		if ( !result )
		{
			findWriterRec( result, values... );
		}
	}

	template< typename ... ValuesT >
	inline ShaderWriter * findWriter( ValuesT && ... values )
	{
		ShaderWriter * result{ nullptr };
		findWriterRec( result, values... );
		return result;
	}

	template< typename ... ValuesT >
	inline ShaderWriter & findWriterMandat( ValuesT && ... values )
	{
		auto result = findWriter( values... );

		if ( !result )
		{
			result = &getCurrentWriter();
		}

		return *result;
	}

	//***********************************************************************************************

	namespace details
	{
		template< typename ValueT >
		inline ast::type::TypePtr getType( ValueT const & value )
		{
			return nullptr;
		}

		inline ast::type::TypePtr getType( Value const & value )
		{
			return value.getType();
		}

		inline void findExprRec( ast::expr::ExprPtr & result
			, ShaderWriter & writer )
		{
		}

		template< typename ValueT >
		inline void findTypeRec( ast::type::TypePtr & result
			, ValueT const & last )
		{
			result = getType( last );
		}

		template< typename ValueT, typename ... ValuesT >
		inline void findTypeRec( ast::type::TypePtr & result
			, ValueT const & current
			, ValuesT const & ... values )
		{
			result = getType( current );

			if ( !result )
			{
				findTypeRec( result, values... );
			}
		}

		template< typename ... ValuesT >
		inline ast::type::TypePtr findType( ValuesT const & ... values )
		{
			ast::type::TypePtr result{ nullptr };
			findTypeRec( result, values... );
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

		auto type = details::findType( values... );
		assert( type );
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wnull-dereference"
		return type->getCache();
#pragma GCC diagnostic pop
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

	template< typename ReturnT, typename LhsT, typename RhsT, typename CreatorT >
	void writeAssignOperator( LhsT const & lhs
		, RhsT const & rhs
		, CreatorT creator )
	{
		if ( areOptionalEnabled( lhs, rhs ) )
		{
			ShaderWriter & writer = findWriterMandat( lhs, rhs );
			ast::expr::ExprPtr lhsExpr = sdw::makeExpr( writer, lhs, true );
			ast::expr::ExprPtr rhsExpr = sdw::makeExpr( writer, rhs, true );
			ast::type::TypePtr lhsType = lhsExpr->getType();
			ast::type::TypePtr rhsType = rhsExpr->getType();

			if constexpr ( !std::is_same_v< CppTypeT< LhsT >, CppTypeT< RhsT > > )
			{
				if ( rhsType->getNonMemberType() != lhsType->getNonMemberType() )
				{
					rhsExpr = sdw::makeCast( lhsType, std::move( rhsExpr ) );
				}
			}

			addStmt( writer
				, sdw::makeSimple( creator( ReturnT::makeType( getTypesCache( writer ) )
					, std::move( lhsExpr )
					, std::move( rhsExpr ) ) ) );
		}
	}

	template< typename ReturnT, typename OperandT, typename CreatorT >
	inline ReturnT writeUnOperator( OperandT const & operand
		, CreatorT creator )
	{
		auto & writer = findWriterMandat( operand );
		return ReturnT{ writer
			, creator( makeExpr( writer, operand ) )
			, operand.isEnabled() };
	}

	template< typename ReturnT, typename LhsT, typename RhsT, typename CreatorT >
	inline ReturnT writeBinOperator( LhsT const & lhs
		, RhsT const & rhs
		, CreatorT creator )
	{
		auto & writer = findWriterMandat( lhs, rhs );
		return ReturnT{ writer
			, creator( ReturnT::makeType( findTypesCache( lhs, rhs ) )
				, makeExpr( writer, lhs )
				, makeExpr( writer, rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	//***********************************************************************************************
}
