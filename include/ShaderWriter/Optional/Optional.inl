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
	}

	//*************************************************************************

	template< typename ValueT >
	Optional< ValueT >::Optional( Shader * shader
		, expr::ExprPtr expr
		, bool enabled )
		: ValueT{ shader, std::move( expr ) }
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
		: ValueT{ rhs }
		, m_enabled{ rhs.m_enabled }
	{
	}

	template< typename ValueT >
	Optional< ValueT > Optional< ValueT >::operator=( Optional< ValueT > const & rhs )
	{
		writeAssignOperator< ValueT >( *this, rhs, sdw::makeAssign );
		return *this;
	}

	template< typename ValueT >
	template< typename T >
	Optional< ValueT > Optional< ValueT >::operator=( T const & rhs )
	{
		writeAssignOperator< ValueT >( *this, rhs, sdw::makeAssign );
		return *this;
	}

	template< typename ValueT >
	bool Optional< ValueT >::isEnabled()const
	{
		return m_enabled;
	}

	//*************************************************************************

	template< typename T >
	inline expr::ExprPtr makeExpr( Shader & shader
		, Optional< T > const & value
		, bool force )
	{
		if ( value.isEnabled() || force )
		{
			return makeExpr( shader
				, static_cast< T const & >( value ) );
		}

		return nullptr;
	}

	template< typename T >
	inline bool isOptionalEnabled( T const & value )
	{
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
		auto & shader = *findShader( operand );
		return Optional< ReturnT >{ &shader
			, creator( makeExpr( shader, operand ) )
			, operand.isEnabled() };
	}

	//*************************************************************************

	template< typename ReturnT, typename LhsT, typename RhsT, typename CreatorT >
	Optional< ReturnT > writeBinOperator( Optional< LhsT > const & lhs
		, RhsT const & rhs
		, CreatorT creator )
	{
		auto & shader = *findShader( lhs, rhs );
		return Optional< ReturnT >{ &shader
			, creator( ReturnT::makeType( findTypesCache( lhs, rhs ) )
				, makeExpr( shader, lhs, true )
				, makeExpr( shader, rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ReturnT, typename LhsT, typename RhsT, typename CreatorT >
	Optional< ReturnT > writeBinOperator( LhsT const & lhs
		, Optional< RhsT > const & rhs
		, CreatorT creator )
	{
		auto & shader = *findShader( lhs, rhs );
		return Optional< ReturnT >{ &shader
			, creator( ReturnT::makeType( findTypesCache( lhs, rhs ) )
				, makeExpr( shader, lhs )
				, makeExpr( shader, rhs, true ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ReturnT, typename LhsT, typename RhsT, typename CreatorT >
	Optional< ReturnT > writeBinOperator( Optional< LhsT > const & lhs
		, Optional< RhsT > const & rhs
		, CreatorT creator )
	{
		auto & shader = *findShader( lhs, rhs );
		return Optional< ReturnT >{ &shader
			, creator( ReturnT::makeType( findTypesCache( lhs, rhs ) )
				, makeExpr( shader, lhs, true )
				, makeExpr( shader, rhs, true ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	//*************************************************************************
}
