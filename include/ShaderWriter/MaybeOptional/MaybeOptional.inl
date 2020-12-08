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
	inline MaybeOptional< ValueT >::MaybeOptional( ShaderWriter & writer
		, expr::ExprPtr expr )
		: ValueT{ writer, std::move( expr ) }
		, m_optional{ false }
		, m_enabled{ true }
	{
	}

	template< typename ValueT >
	inline MaybeOptional< ValueT >::MaybeOptional( ShaderWriter & writer
		, expr::ExprPtr expr
		, bool enabled )
		: ValueT{ writer, std::move( expr ) }
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
		: ValueT{ static_cast< ValueT const & >( rhs ) }
		, m_optional{ true }
		, m_enabled{ rhs.isEnabled() }
	{
	}

	template< typename ValueT >
	inline MaybeOptional< ValueT >::MaybeOptional( MaybeOptional< ValueT > const & rhs )
		: ValueT{ static_cast< ValueT const & >( rhs ) }
		, m_optional{ rhs.isOptional() }
		, m_enabled{ rhs.isEnabled() }
	{
	}

	template< typename ValueT >
	inline MaybeOptional< ValueT > & MaybeOptional< ValueT >::operator=( ValueT const & rhs )
	{
		if ( isEnabled() )
		{
			ValueT::operator=( rhs );
		}

		return *this;
	}

	template< typename ValueT >
	inline MaybeOptional< ValueT > & MaybeOptional< ValueT >::operator=( Optional< ValueT > const & rhs )
	{
		if ( isEnabled() && rhs.isEnabled() )
		{
			ValueT::operator=( rhs );
		}

		return *this;
	}

	template< typename ValueT >
	inline MaybeOptional< ValueT > & MaybeOptional< ValueT >::operator=( MaybeOptional< ValueT > const & rhs )
	{
		if ( isEnabled() && rhs.isEnabled() )
		{
			ValueT::operator=( rhs );
		}

		return *this;
	}

	template< typename ValueT >
	inline MaybeOptional< ValueT >::operator ValueT const & ( )const
	{
		return *this;
	}

	template< typename ValueT >
	inline MaybeOptional< ValueT >::operator ValueT & ( )
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
	
	inline bool isAnyOptional( ShaderWriter const & writer )
	{
		return false;
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
		ShaderWriter & writer = *findWriter( value );

		if ( value.isEnabled() || force )
		{
			return makeExpr( writer, static_cast< ValueT const & >( value ) );
		}

		return getDummyExpr( writer, value.getType() );
	}

	//*************************************************************************

	template< typename ReturnT, typename OperandT, typename CreatorT >
	inline MaybeOptional< ReturnT > writeUnOperator( MaybeOptional< OperandT > const & operand
		, CreatorT creator )
	{
		ShaderWriter & writer = *findWriter( operand );

		if ( isAnyOptional( operand ) )
		{
			return MaybeOptional< ReturnT >{ writer
				, creator( makeExpr( writer, operand ) )
				, operand.isEnabled() };
		}

		return ReturnT{ writer
			, creator( makeExpr( writer, operand ) ) };
	}

	//*************************************************************************

	template< typename ReturnT, typename LhsT, typename RhsT, typename CreatorT >
	MaybeOptional< ReturnT > writeBinOperator( MaybeOptional< LhsT > const & lhs
		, RhsT const & rhs
		, CreatorT creator )
	{
		ShaderWriter & writer = *findWriter( lhs, rhs );

		if ( isAnyOptional( lhs, rhs ) )
		{
			return MaybeOptional< ReturnT >{ writer
				, creator( ReturnT::makeType( findTypesCache( lhs, rhs ) )
					, makeExpr( writer, lhs, true )
					, makeExpr( writer, rhs ) )
				, areOptionalEnabled( lhs, rhs ) };
		}

		return ReturnT{ writer
			, creator( ReturnT::makeType( findTypesCache( lhs, rhs ) )
				, makeExpr( writer, lhs, true )
				, makeExpr( writer, rhs ) ) };
	}

	template< typename ReturnT, typename LhsT, typename RhsT, typename CreatorT >
	MaybeOptional< ReturnT > writeBinOperator( LhsT const & lhs
		, MaybeOptional< RhsT > const & rhs
		, CreatorT creator )
	{
		ShaderWriter & writer = *findWriter( lhs, rhs );

		if ( isAnyOptional( lhs, rhs ) )
		{
			return MaybeOptional< ReturnT >{ writer
				, creator( ReturnT::makeType( findTypesCache( lhs, rhs ) )
					, makeExpr( writer, lhs )
					, makeExpr( writer, rhs, true ) )
				, areOptionalEnabled( lhs, rhs ) };
		}

		return ReturnT{ writer
			, creator( ReturnT::makeType( findTypesCache( lhs, rhs ) )
				, makeExpr( writer, lhs )
				, makeExpr( writer, rhs, true ) ) };
	}

	template< typename ReturnT, typename LhsT, typename RhsT, typename CreatorT >
	MaybeOptional< ReturnT > writeBinOperator( MaybeOptional< LhsT > const & lhs
		, MaybeOptional< RhsT > const & rhs
		, CreatorT creator )
	{
		ShaderWriter & writer = *findWriter( lhs, rhs );

		if ( isAnyOptional( lhs, rhs ) )
		{
			return MaybeOptional< ReturnT >{ writer
				, creator( ReturnT::makeType( findTypesCache( lhs, rhs ) )
					, makeExpr( writer, lhs, true )
					, makeExpr( writer, rhs, true ) )
				, areOptionalEnabled( lhs, rhs ) };
		}

		return ReturnT{ writer
			, creator( ReturnT::makeType( findTypesCache( lhs, rhs ) )
				, makeExpr( writer, lhs, true )
				, makeExpr( writer, rhs, true ) ) };
	}

	//*************************************************************************

	template< typename ReturnT, typename LhsT, typename RhsT, typename CreatorT >
	void writeAssignOperator( LhsT const & lhs
		, RhsT const & rhs
		, CreatorT creator )
	{
		if ( areOptionalEnabled( lhs, rhs ) )
		{
			ShaderWriter & writer = *findWriter( lhs, rhs );
			ast::expr::ExprPtr lhsExpr = sdw::makeExpr( writer, lhs, true );
			ast::expr::ExprPtr rhsExpr = sdw::makeExpr( writer, rhs, true );
			ast::type::TypePtr lhsType = details::getType( writer, lhs );
			ast::type::TypePtr rhsType = details::getType( writer, rhs );

			if ( rhsType != lhsType )
			{
				rhsExpr = sdw::makeCast( lhsType, std::move( rhsExpr ) );
			}

			addStmt( writer
				, sdw::makeSimple( creator( ReturnT::makeType( getTypesCache( writer ) )
					, makeExpr( writer, lhs )
					, makeExpr( writer, rhs ) ) ) );
		}
	}

	//*************************************************************************
}
