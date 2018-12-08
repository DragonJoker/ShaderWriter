/*
See LICENSE file in root folder
*/
namespace sdw
{
	//*************************************************************************

	template< typename T >
	inline Boolean & Boolean::operator=( T const & rhs )
	{
		updateContainer( rhs );
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeAssign( findTypesCache( *this, rhs ).getBool()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	//*************************************************************************

	template< typename ValueT >
	Optional< Boolean > operator==( Optional< ValueT > const & lhs, ValueT const & rhs )
	{
		auto lhsExpr = makeExpr( lhs, true );
		auto rhsExpr = makeExpr( rhs );
		auto lhsType = lhs.getType();
		auto rhsType = rhs.getType();
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeEqual( std::move( lhsExpr )
				, ( rhsType == lhsType
					? std::move( rhsExpr )
					: sdw::makeCast( lhsType, std::move( rhsExpr ) ) ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Boolean > operator!=( Optional< ValueT > const & lhs, ValueT const & rhs )
	{
		auto lhsExpr = makeExpr( lhs, true );
		auto rhsExpr = makeExpr( rhs );
		auto lhsType = lhs.getType();
		auto rhsType = rhs.getType();
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeNEqual( std::move( lhsExpr )
				, ( rhsType == lhsType
					? std::move( rhsExpr )
					: sdw::makeCast( lhsType, std::move( rhsExpr ) ) ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Boolean > operator<( Optional< ValueT > const & lhs, ValueT const & rhs )
	{
		auto lhsExpr = makeExpr( lhs, true );
		auto rhsExpr = makeExpr( rhs );
		auto lhsType = lhs.getType();
		auto rhsType = rhs.getType();
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeLess( std::move( lhsExpr )
				, ( rhsType == lhsType
					? std::move( rhsExpr )
					: sdw::makeCast( lhsType, std::move( rhsExpr ) ) ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Boolean > operator<=( Optional< ValueT > const & lhs, ValueT const & rhs )
	{
		auto lhsExpr = makeExpr( lhs, true );
		auto rhsExpr = makeExpr( rhs );
		auto lhsType = lhs.getType();
		auto rhsType = rhs.getType();
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeLEqual( std::move( lhsExpr )
				, ( rhsType == lhsType
					? std::move( rhsExpr )
					: sdw::makeCast( lhsType, std::move( rhsExpr ) ) ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Boolean > operator>( Optional< ValueT > const & lhs, ValueT const & rhs )
	{
		auto lhsExpr = makeExpr( lhs, true );
		auto rhsExpr = makeExpr( rhs );
		auto lhsType = lhs.getType();
		auto rhsType = rhs.getType();
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeGreater( std::move( lhsExpr )
				, ( rhsType == lhsType
					? std::move( rhsExpr )
					: sdw::makeCast( lhsType, std::move( rhsExpr ) ) ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Boolean > operator>=( Optional< ValueT > const & lhs, ValueT const & rhs )
	{
		auto lhsExpr = makeExpr( lhs, true );
		auto rhsExpr = makeExpr( rhs );
		auto lhsType = lhs.getType();
		auto rhsType = rhs.getType();
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeGEqual( std::move( lhsExpr )
				, ( rhsType == lhsType
					? std::move( rhsExpr )
					: sdw::makeCast( lhsType, std::move( rhsExpr ) ) ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Boolean > operator==( ValueT const & lhs, Optional< ValueT > const & rhs )
	{
		auto lhsExpr = makeExpr( lhs );
		auto rhsExpr = makeExpr( rhs, true );
		auto lhsType = lhs.getType();
		auto rhsType = rhs.getType();
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeEqual( std::move( lhsExpr )
				, ( rhsType == lhsType
					? std::move( rhsExpr )
					: sdw::makeCast( lhsType, std::move( rhsExpr ) ) ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Boolean > operator!=( ValueT const & lhs, Optional< ValueT > const & rhs )
	{
		auto lhsExpr = makeExpr( lhs );
		auto rhsExpr = makeExpr( rhs, true );
		auto lhsType = lhs.getType();
		auto rhsType = rhs.getType();
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeNEqual( std::move( lhsExpr )
				, ( rhsType == lhsType
					? std::move( rhsExpr )
					: sdw::makeCast( lhsType, std::move( rhsExpr ) ) ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Boolean > operator<( ValueT const & lhs, Optional< ValueT > const & rhs )
	{
		auto lhsExpr = makeExpr( lhs );
		auto rhsExpr = makeExpr( rhs, true );
		auto lhsType = lhs.getType();
		auto rhsType = rhs.getType();
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeLess( std::move( lhsExpr )
				, ( rhsType == lhsType
					? std::move( rhsExpr )
					: sdw::makeCast( lhsType, std::move( rhsExpr ) ) ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Boolean > operator<=( ValueT const & lhs, Optional< ValueT > const & rhs )
	{
		auto lhsExpr = makeExpr( lhs );
		auto rhsExpr = makeExpr( rhs, true );
		auto lhsType = lhs.getType();
		auto rhsType = rhs.getType();
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeLEqual( std::move( lhsExpr )
				, ( rhsType == lhsType
					? std::move( rhsExpr )
					: sdw::makeCast( lhsType, std::move( rhsExpr ) ) ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Boolean > operator>( ValueT const & lhs, Optional< ValueT > const & rhs )
	{
		auto lhsExpr = makeExpr( lhs );
		auto rhsExpr = makeExpr( rhs, true );
		auto lhsType = lhs.getType();
		auto rhsType = rhs.getType();
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeGreater( std::move( lhsExpr )
				, ( rhsType == lhsType
					? std::move( rhsExpr )
					: sdw::makeCast( lhsType, std::move( rhsExpr ) ) ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Boolean > operator>=( ValueT const & lhs, Optional< ValueT > const & rhs )
	{
		auto lhsExpr = makeExpr( lhs );
		auto rhsExpr = makeExpr( rhs, true );
		auto lhsType = lhs.getType();
		auto rhsType = rhs.getType();
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeGEqual( std::move( lhsExpr )
				, ( rhsType == lhsType
					? std::move( rhsExpr )
					: sdw::makeCast( lhsType, std::move( rhsExpr ) ) ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Boolean > operator==( Optional< ValueT > const & lhs, Optional< ValueT > const & rhs )
	{
		auto lhsExpr = makeExpr( lhs, true );
		auto rhsExpr = makeExpr( rhs, true );
		auto lhsType = lhs.getType();
		auto rhsType = rhs.getType();
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeEqual( std::move( lhsExpr )
				, ( rhsType == lhsType
					? std::move( rhsExpr )
					: sdw::makeCast( lhsType, std::move( rhsExpr ) ) ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Boolean > operator!=( Optional< ValueT > const & lhs, Optional< ValueT > const & rhs )
	{
		auto lhsExpr = makeExpr( lhs, true );
		auto rhsExpr = makeExpr( rhs, true );
		auto lhsType = lhs.getType();
		auto rhsType = rhs.getType();
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeNEqual( std::move( lhsExpr )
				, ( rhsType == lhsType
					? std::move( rhsExpr )
					: sdw::makeCast( lhsType, std::move( rhsExpr ) ) ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Boolean > operator<( Optional< ValueT > const & lhs, Optional< ValueT > const & rhs )
	{
		auto lhsExpr = makeExpr( lhs, true );
		auto rhsExpr = makeExpr( rhs, true );
		auto lhsType = lhs.getType();
		auto rhsType = rhs.getType();
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeLess( std::move( lhsExpr )
				, ( rhsType == lhsType
					? std::move( rhsExpr )
					: sdw::makeCast( lhsType, std::move( rhsExpr ) ) ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Boolean > operator<=( Optional< ValueT > const & lhs, Optional< ValueT > const & rhs )
	{
		auto lhsExpr = makeExpr( lhs, true );
		auto rhsExpr = makeExpr( rhs, true );
		auto lhsType = lhs.getType();
		auto rhsType = rhs.getType();
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeLEqual( std::move( lhsExpr )
				, ( rhsType == lhsType
					? std::move( rhsExpr )
					: sdw::makeCast( lhsType, std::move( rhsExpr ) ) ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Boolean > operator>( Optional< ValueT > const & lhs, Optional< ValueT > const & rhs )
	{
		auto lhsExpr = makeExpr( lhs, true );
		auto rhsExpr = makeExpr( rhs, true );
		auto lhsType = lhs.getType();
		auto rhsType = rhs.getType();
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeGreater( std::move( lhsExpr )
				, ( rhsType == lhsType
					? std::move( rhsExpr )
					: sdw::makeCast( lhsType, std::move( rhsExpr ) ) ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Boolean > operator>=( Optional< ValueT > const & lhs, Optional< ValueT > const & rhs )
	{
		auto lhsExpr = makeExpr( lhs, true );
		auto rhsExpr = makeExpr( rhs, true );
		auto lhsType = lhs.getType();
		auto rhsType = rhs.getType();
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeGEqual( std::move( lhsExpr )
				, ( rhsType == lhsType
					? std::move( rhsExpr )
					: sdw::makeCast( lhsType, std::move( rhsExpr ) ) ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	//*************************************************************************
}
