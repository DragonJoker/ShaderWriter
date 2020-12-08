/*
See LICENSE file in root folder
*/
namespace sdw
{
	//*************************************************************************

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
	}

	//*************************************************************************

	template< typename ValueT >
	Optional< ValueT >::Optional( ShaderWriter & writer
		, expr::ExprPtr expr
		, bool enabled )
		: ValueT{ writer, std::move( expr ) }
		, m_enabled{ enabled }
	{
	}

	template< typename ValueT >
	Optional< ValueT >::Optional( ValueT const & other
		, bool enabled )
		: ValueT{ other }
		, m_enabled{ enabled }
	{
	}

	template< typename ValueT >
	Optional< ValueT >::Optional( Optional< ValueT > const & rhs )
		: ValueT{ static_cast< ValueT const & >( rhs ) }
		, m_enabled{ rhs.m_enabled }
	{
	}

	template< typename ValueT >
	Optional< ValueT > & Optional< ValueT >::operator=( Optional< ValueT > const & rhs )
	{
		writeAssignOperator< ValueT >( *this, rhs, sdw::makeAssign );
		return *this;
	}

	template< typename ValueT >
	template< typename T >
	Optional< ValueT > & Optional< ValueT >::operator=( T const & rhs )
	{
		writeAssignOperator< ValueT >( *this, rhs, sdw::makeAssign );
		return *this;
	}

	template< typename ValueT >
	bool Optional< ValueT >::isEnabled()const
	{
		return m_enabled;
	}

	template< typename ValueT >
	template< typename T >
	Optional< ValueT > & Optional< ValueT >::operator+=( T const & rhs )
	{
		if constexpr ( hasArithmeticOperators< ValueT > )
		{
			if ( isEnabled() )
			{
				ValueT::operator+=( rhs );
			}
		}

		return *this;
	}

	template< typename ValueT >
	template< typename T >
	Optional< ValueT > & Optional< ValueT >::operator-=( T const & rhs )
	{
		if constexpr ( hasArithmeticOperators< ValueT > )
		{
			if ( isEnabled() )
			{
				ValueT::operator-=( rhs );
			}
		}

		return *this;
	}

	template< typename ValueT >
	template< typename T >
	Optional< ValueT > & Optional< ValueT >::operator*=( T const & rhs )
	{
		if constexpr ( hasArithmeticOperators< ValueT > )
		{
			if ( isEnabled() )
			{
				ValueT::operator*=( rhs );
			}
		}

		return *this;
	}

	template< typename ValueT >
	template< typename T >
	Optional< ValueT > & Optional< ValueT >::operator/=( T const & rhs )
	{
		if constexpr ( hasArithmeticOperators< ValueT > )
		{
			if ( isEnabled() )
			{
				ValueT::operator/=( rhs );
			}
		}

		return *this;
	}

	template< typename ValueT >
	Optional< ValueT > Optional< ValueT >::operator-()const
	{
		if constexpr ( hasArithmeticOperators< ValueT > )
		{
			if ( isEnabled() )
			{
				ValueT::operator-();
			}
		}

		return *this;
	}

	template< typename ValueT >
	Optional< ValueT > Optional< ValueT >::operator+()const
	{
		if constexpr ( hasArithmeticOperators< ValueT > )
		{
			if ( isEnabled() )
			{
				ValueT::operator+();
			}
		}

		return *this;
	}

	//*************************************************************************

	template< typename T >
	inline expr::ExprPtr makeExpr( ShaderWriter & writer
		, Optional< T > const & value
		, bool force )
	{
		if ( value.isEnabled() || force )
		{
			return makeExpr( writer
				, static_cast< T const & >( value ) );
		}

		return getDummyExpr( writer, value.getType() );
	}

	template< typename T >
	inline bool isOptionalEnabled( T const & value )
	{
		static_assert( !isOptional< T >, "Unexpected Optional" );
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

	//*************************************************************************

	template< typename ReturnT, typename OperandT, typename CreatorT >
	inline Optional< ReturnT > writeUnOperator( Optional< OperandT > const & operand
		, CreatorT creator )
	{
		ShaderWriter & writer = *findWriter( operand );
		return Optional< ReturnT >{ writer
			, creator( makeExpr( writer, operand ) )
			, operand.isEnabled() };
	}

	//*************************************************************************

	template< typename ReturnT, typename LhsT, typename RhsT, typename CreatorT >
	Optional< ReturnT > writeBinOperator( Optional< LhsT > const & lhs
		, RhsT const & rhs
		, CreatorT creator )
	{
		ShaderWriter & writer = *findWriter( lhs, rhs );
		return Optional< ReturnT >{ writer
			, creator( ReturnT::makeType( findTypesCache( lhs, rhs ) )
				, makeExpr( writer, lhs, true )
				, makeExpr( writer, rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ReturnT, typename LhsT, typename RhsT, typename CreatorT >
	Optional< ReturnT > writeBinOperator( LhsT const & lhs
		, Optional< RhsT > const & rhs
		, CreatorT creator )
	{
		ShaderWriter & writer = *findWriter( lhs, rhs );
		return Optional< ReturnT >{ writer
			, creator( ReturnT::makeType( findTypesCache( lhs, rhs ) )
				, makeExpr( writer, lhs )
				, makeExpr( writer, rhs, true ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ReturnT, typename LhsT, typename RhsT, typename CreatorT >
	Optional< ReturnT > writeBinOperator( Optional< LhsT > const & lhs
		, Optional< RhsT > const & rhs
		, CreatorT creator )
	{
		auto & writer = *findWriter( lhs, rhs );
		return Optional< ReturnT >{ writer
			, creator( ReturnT::makeType( findTypesCache( lhs, rhs ) )
				, makeExpr( writer, lhs, true )
				, makeExpr( writer, rhs, true ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	//*************************************************************************
}
