/*
See LICENSE file in root folder
*/
namespace sdw
{
	template< typename T >
	Int & Int::operator=( T const & rhs )
	{
		updateContainer( rhs );
		auto rhsExpr = makeExpr( rhs );
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( makeAssign( findTypesCache( *this, rhs ).getInt()
				, makeExpr( *this )
				, ( rhsExpr->getType() == findTypesCache( *this, rhs ).getInt()
					? std::move( rhsExpr )
					: makeCast( findTypesCache( *this, rhs ).getInt(), std::move( rhsExpr ) ) ) ) ) );
		return *this;
	}
}
