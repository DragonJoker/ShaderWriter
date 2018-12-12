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
	inline MaybeOptional< ValueT >::MaybeOptional( Shader * shader
		, expr::ExprPtr expr )
		: ValueT{ shader, std::move( expr ) }
		, m_optional{ false }
		, m_enabled{ true }
	{
	}

	template< typename ValueT >
	inline MaybeOptional< ValueT >::MaybeOptional( Shader * shader
		, expr::ExprPtr expr
		, bool enabled )
		: ValueT{ shader, std::move( expr ) }
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
		: ValueT{ rhs }
		, m_optional{ true }
		, m_enabled{ rhs.isEnabled() }
	{
	}

	template< typename ValueT >
	inline MaybeOptional< ValueT >::MaybeOptional( MaybeOptional< ValueT > const & rhs )
		: ValueT{ rhs }
		, m_optional{ rhs.isOptional() }
		, m_enabled{ rhs.isEnabled() }
	{
	}

	template< typename ValueT >
	inline MaybeOptional< ValueT >::operator ValueT()const
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

	template< typename T >
	inline bool isOptionalEnabled( MaybeOptional< T > const & value )
	{
		return value.isEnabled();
	}

	template< typename ValueT >
	inline expr::ExprPtr makeExpr( MaybeOptional< ValueT > const & value
		, bool force )
	{
		if ( value.isEnabled() || force )
		{
			return makeExpr( *findShader( value ), static_cast< ValueT const & >( value ) );
		}

		return nullptr;
	}

	//*************************************************************************

	template< typename ReturnT, typename OperandT, typename CreatorT >
	inline MaybeOptional< ReturnT > writeUnOperator( MaybeOptional< OperandT > const & operand
		, CreatorT creator )
	{
		auto & shader = *findShader( operand );

		if ( isAnyOptional( operand ) )
		{
			return MaybeOptional< ReturnT >{ &shader
				, creator( makeExpr( shader, operand ) )
				, operand.isEnabled() };
		}

		return ReturnT{ &shader
			, creator( ReturnT::makeType( findTypesCache( operand ) )
				, makeExpr( shader, operand ) ) };
	}

	//*************************************************************************

	template< typename ReturnT, typename LhsT, typename RhsT, typename CreatorT >
	MaybeOptional< ReturnT > writeBinOperator( MaybeOptional< LhsT > const & lhs
		, RhsT const & rhs
		, CreatorT creator )
	{
		auto & shader = *findShader( lhs, rhs );

		if ( isAnyOptional( lhs, rhs ) )
		{
			return MaybeOptional< ReturnT >{ &shader
				, creator( ReturnT::makeType( findTypesCache( lhs, rhs ) )
					, makeExpr( shader, lhs, true )
					, makeExpr( shader, rhs ) )
				, areOptionalEnabled( lhs, rhs ) };
		}

		return ReturnT{ &shader
			, creator( ReturnT::makeType( findTypesCache( lhs, rhs ) )
				, makeExpr( shader, lhs, true )
				, makeExpr( shader, rhs ) ) };
	}

	template< typename ReturnT, typename LhsT, typename RhsT, typename CreatorT >
	MaybeOptional< ReturnT > writeBinOperator( LhsT const & lhs
		, MaybeOptional< RhsT > const & rhs
		, CreatorT creator )
	{
		auto & shader = *findShader( lhs, rhs );

		if ( isAnyOptional( lhs, rhs ) )
		{
			return MaybeOptional< ReturnT >{ &shader
				, creator( ReturnT::makeType( findTypesCache( lhs, rhs ) )
					, makeExpr( shader, lhs )
					, makeExpr( shader, rhs, true ) )
				, areOptionalEnabled( lhs, rhs ) };
		}

		return ReturnT{ &shader
			, creator( ReturnT::makeType( findTypesCache( lhs, rhs ) )
				, makeExpr( shader, lhs )
				, makeExpr( shader, rhs, true ) ) };
	}

	template< typename ReturnT, typename LhsT, typename RhsT, typename CreatorT >
	MaybeOptional< ReturnT > writeBinOperator( MaybeOptional< LhsT > const & lhs
		, MaybeOptional< RhsT > const & rhs
		, CreatorT creator )
	{
		auto & shader = *findShader( lhs, rhs );

		if ( isAnyOptional( lhs, rhs ) )
		{
			return MaybeOptional< ReturnT >{ &shader
				, creator( ReturnT::makeType( findTypesCache( lhs, rhs ) )
					, makeExpr( shader, lhs, true )
					, makeExpr( shader, rhs, true ) )
				, areOptionalEnabled( lhs, rhs ) };
		}

		return ReturnT{ &shader
			, creator( ReturnT::makeType( findTypesCache( lhs, rhs ) )
				, makeExpr( shader, lhs, true )
				, makeExpr( shader, rhs, true ) ) };
	}

	//*************************************************************************

	template< typename ReturnT, typename LhsT, typename RhsT, typename CreatorT >
	void writeAssignOperator( LhsT const & lhs
		, RhsT const & rhs
		, CreatorT creator )
	{
		if ( areOptionalEnabled( lhs, rhs ) )
		{
			Shader & shader = *findShader( lhs, rhs );
			ast::expr::ExprPtr lhsExpr = sdw::makeExpr( shader, lhs, true );
			ast::expr::ExprPtr rhsExpr = sdw::makeExpr( shader, rhs, true );
			ast::type::TypePtr lhsType = details::getType( shader, lhs );
			ast::type::TypePtr rhsType = details::getType( shader, rhs );

			if ( rhsType != lhsType )
			{
				rhsExpr = sdw::makeCast( lhsType, std::move( rhsExpr ) );
			}

			addStmt( shader
				, sdw::makeSimple( creator( ReturnT::makeType( getTypesCache( shader ) )
					, makeExpr( shader, lhs )
					, makeExpr( shader, rhs ) ) ) );
		}
	}

	//*************************************************************************
}
