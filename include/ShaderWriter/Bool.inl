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
		addStmt( *findContainer( *this, rhs )
			, sdw::makeSimple( sdw::makeAssign( type::getBool()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	//*************************************************************************

	template< typename ValueT >
	Optional< Boolean > operator==( Optional< ValueT > const & lhs, ValueT const & rhs )
	{
		auto lhsExpr = makeExpr( lhs );
		auto rhsExpr = makeExpr( rhs );
		auto lhsType = lhsExpr ? lhsExpr->getType() : nullptr;
		auto rhsType = rhsExpr ? rhsExpr->getType() : nullptr;
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeEqual( std::move( lhsExpr )
				, ( rhsType == lhsType
					? std::move( rhsExpr )
					: sdw::makeCast( lhsExpr->getType(), std::move( rhsExpr ) ) ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Boolean > operator!=( Optional< ValueT > const & lhs, ValueT const & rhs )
	{
		auto lhsExpr = makeExpr( lhs );
		auto rhsExpr = makeExpr( rhs );
		auto lhsType = lhsExpr ? lhsExpr->getType() : nullptr;
		auto rhsType = rhsExpr ? rhsExpr->getType() : nullptr;
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeNEqual( std::move( lhsExpr )
				, ( rhsType == lhsType
					? std::move( rhsExpr )
					: sdw::makeCast( lhsExpr->getType(), std::move( rhsExpr ) ) ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Boolean > operator<( Optional< ValueT > const & lhs, ValueT const & rhs )
	{
		auto lhsExpr = makeExpr( lhs );
		auto rhsExpr = makeExpr( rhs );
		auto lhsType = lhsExpr ? lhsExpr->getType() : nullptr;
		auto rhsType = rhsExpr ? rhsExpr->getType() : nullptr;
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeLess( std::move( lhsExpr )
				, ( rhsType == lhsType
					? std::move( rhsExpr )
					: sdw::makeCast( lhsExpr->getType(), std::move( rhsExpr ) ) ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Boolean > operator<=( Optional< ValueT > const & lhs, ValueT const & rhs )
	{
		auto lhsExpr = makeExpr( lhs );
		auto rhsExpr = makeExpr( rhs );
		auto lhsType = lhsExpr ? lhsExpr->getType() : nullptr;
		auto rhsType = rhsExpr ? rhsExpr->getType() : nullptr;
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeLEqual( std::move( lhsExpr )
				, ( rhsType == lhsType
					? std::move( rhsExpr )
					: sdw::makeCast( lhsExpr->getType(), std::move( rhsExpr ) ) ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Boolean > operator>( Optional< ValueT > const & lhs, ValueT const & rhs )
	{
		auto lhsExpr = makeExpr( lhs );
		auto rhsExpr = makeExpr( rhs );
		auto lhsType = lhsExpr ? lhsExpr->getType() : nullptr;
		auto rhsType = rhsExpr ? rhsExpr->getType() : nullptr;
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeGreater( std::move( lhsExpr )
				, ( rhsType == lhsType
					? std::move( rhsExpr )
					: sdw::makeCast( lhsExpr->getType(), std::move( rhsExpr ) ) ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Boolean > operator>=( Optional< ValueT > const & lhs, ValueT const & rhs )
	{
		auto lhsExpr = makeExpr( lhs );
		auto rhsExpr = makeExpr( rhs );
		auto lhsType = lhsExpr ? lhsExpr->getType() : nullptr;
		auto rhsType = rhsExpr ? rhsExpr->getType() : nullptr;
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeGEqual( std::move( lhsExpr )
				, ( rhsType == lhsType
					? std::move( rhsExpr )
					: sdw::makeCast( lhsExpr->getType(), std::move( rhsExpr ) ) ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Boolean > operator==( ValueT const & lhs, Optional< ValueT > const & rhs )
	{
		auto lhsExpr = makeExpr( lhs );
		auto rhsExpr = makeExpr( rhs );
		auto lhsType = lhsExpr ? lhsExpr->getType() : nullptr;
		auto rhsType = rhsExpr ? rhsExpr->getType() : nullptr;
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeEqual( std::move( lhsExpr )
				, ( rhsType == lhsType
					? std::move( rhsExpr )
					: sdw::makeCast( lhsExpr->getType(), std::move( rhsExpr ) ) ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Boolean > operator!=( ValueT const & lhs, Optional< ValueT > const & rhs )
	{
		auto lhsExpr = makeExpr( lhs );
		auto rhsExpr = makeExpr( rhs );
		auto lhsType = lhsExpr ? lhsExpr->getType() : nullptr;
		auto rhsType = rhsExpr ? rhsExpr->getType() : nullptr;
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeNEqual( std::move( lhsExpr )
				, ( rhsType == lhsType
					? std::move( rhsExpr )
					: sdw::makeCast( lhsExpr->getType(), std::move( rhsExpr ) ) ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Boolean > operator<( ValueT const & lhs, Optional< ValueT > const & rhs )
	{
		auto lhsExpr = makeExpr( lhs );
		auto rhsExpr = makeExpr( rhs );
		auto lhsType = lhsExpr ? lhsExpr->getType() : nullptr;
		auto rhsType = rhsExpr ? rhsExpr->getType() : nullptr;
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeLess( std::move( lhsExpr )
				, ( rhsType == lhsType
					? std::move( rhsExpr )
					: sdw::makeCast( lhsExpr->getType(), std::move( rhsExpr ) ) ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Boolean > operator<=( ValueT const & lhs, Optional< ValueT > const & rhs )
	{
		auto lhsExpr = makeExpr( lhs );
		auto rhsExpr = makeExpr( rhs );
		auto lhsType = lhsExpr ? lhsExpr->getType() : nullptr;
		auto rhsType = rhsExpr ? rhsExpr->getType() : nullptr;
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeLEqual( std::move( lhsExpr )
				, ( rhsType == lhsType
					? std::move( rhsExpr )
					: sdw::makeCast( lhsExpr->getType(), std::move( rhsExpr ) ) ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Boolean > operator>( ValueT const & lhs, Optional< ValueT > const & rhs )
	{
		auto lhsExpr = makeExpr( lhs );
		auto rhsExpr = makeExpr( rhs );
		auto lhsType = lhsExpr ? lhsExpr->getType() : nullptr;
		auto rhsType = rhsExpr ? rhsExpr->getType() : nullptr;
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeGreater( std::move( lhsExpr )
				, ( rhsType == lhsType
					? std::move( rhsExpr )
					: sdw::makeCast( lhsExpr->getType(), std::move( rhsExpr ) ) ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Boolean > operator>=( ValueT const & lhs, Optional< ValueT > const & rhs )
	{
		auto lhsExpr = makeExpr( lhs );
		auto rhsExpr = makeExpr( rhs );
		auto lhsType = lhsExpr ? lhsExpr->getType() : nullptr;
		auto rhsType = rhsExpr ? rhsExpr->getType() : nullptr;
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeGEqual( std::move( lhsExpr )
				, ( rhsType == lhsType
					? std::move( rhsExpr )
					: sdw::makeCast( lhsExpr->getType(), std::move( rhsExpr ) ) ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Boolean > operator==( Optional< ValueT > const & lhs, Optional< ValueT > const & rhs )
	{
		auto lhsExpr = makeExpr( lhs );
		auto rhsExpr = makeExpr( rhs );
		auto lhsType = lhsExpr ? lhsExpr->getType() : nullptr;
		auto rhsType = rhsExpr ? rhsExpr->getType() : nullptr;
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeEqual( std::move( lhsExpr )
				, ( rhsType == lhsType
					? std::move( rhsExpr )
					: sdw::makeCast( lhsExpr->getType(), std::move( rhsExpr ) ) ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Boolean > operator!=( Optional< ValueT > const & lhs, Optional< ValueT > const & rhs )
	{
		auto lhsExpr = makeExpr( lhs );
		auto rhsExpr = makeExpr( rhs );
		auto lhsType = lhsExpr ? lhsExpr->getType() : nullptr;
		auto rhsType = rhsExpr ? rhsExpr->getType() : nullptr;
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeNEqual( std::move( lhsExpr )
				, ( rhsType == lhsType
					? std::move( rhsExpr )
					: sdw::makeCast( lhsExpr->getType(), std::move( rhsExpr ) ) ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Boolean > operator<( Optional< ValueT > const & lhs, Optional< ValueT > const & rhs )
	{
		auto lhsExpr = makeExpr( lhs );
		auto rhsExpr = makeExpr( rhs );
		auto lhsType = lhsExpr ? lhsExpr->getType() : nullptr;
		auto rhsType = rhsExpr ? rhsExpr->getType() : nullptr;
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeLess( std::move( lhsExpr )
				, ( rhsType == lhsType
					? std::move( rhsExpr )
					: sdw::makeCast( lhsExpr->getType(), std::move( rhsExpr ) ) ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Boolean > operator<=( Optional< ValueT > const & lhs, Optional< ValueT > const & rhs )
	{
		auto lhsExpr = makeExpr( lhs );
		auto rhsExpr = makeExpr( rhs );
		auto lhsType = lhsExpr ? lhsExpr->getType() : nullptr;
		auto rhsType = rhsExpr ? rhsExpr->getType() : nullptr;
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeLEqual( std::move( lhsExpr )
				, ( rhsType == lhsType
					? std::move( rhsExpr )
					: sdw::makeCast( lhsExpr->getType(), std::move( rhsExpr ) ) ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Boolean > operator>( Optional< ValueT > const & lhs, Optional< ValueT > const & rhs )
	{
		auto lhsExpr = makeExpr( lhs );
		auto rhsExpr = makeExpr( rhs );
		auto lhsType = lhsExpr ? lhsExpr->getType() : nullptr;
		auto rhsType = rhsExpr ? rhsExpr->getType() : nullptr;
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeGreater( std::move( lhsExpr )
				, ( rhsType == lhsType
					? std::move( rhsExpr )
					: sdw::makeCast( lhsExpr->getType(), std::move( rhsExpr ) ) ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Boolean > operator>=( Optional< ValueT > const & lhs, Optional< ValueT > const & rhs )
	{
		auto lhsExpr = makeExpr( lhs );
		auto rhsExpr = makeExpr( rhs );
		auto lhsType = lhsExpr ? lhsExpr->getType() : nullptr;
		auto rhsType = rhsExpr ? rhsExpr->getType() : nullptr;
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeGEqual( std::move( lhsExpr )
				, ( rhsType == lhsType
					? std::move( rhsExpr )
					: sdw::makeCast( lhsExpr->getType(), std::move( rhsExpr ) ) ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	//*************************************************************************
}
