/*
See LICENSE file in root folder
*/
namespace sdw
{
	template< typename T >
	UInt & UInt::operator=( T const & rhs )
	{
		updateContainer( rhs );
		auto rhsExpr = makeExpr( rhs );
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeAssign( findTypesCache( *this, rhs ).getUInt()
				, makeExpr( *this )
				, ( rhsExpr->getType() == findTypesCache( *this, rhs ).getUInt()
					? std::move( rhsExpr )
					: sdw::makeCast( findTypesCache( *this, rhs ).getUInt(), std::move( rhsExpr ) ) ) ) ) );
		return *this;
	}
}
