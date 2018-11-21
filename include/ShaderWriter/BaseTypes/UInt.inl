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
		addStmt( *findContainer( *this, rhs )
			, sdw::makeSimple( sdw::makeAssign( type::getUInt()
				, makeExpr( *this )
				, ( rhsExpr->getType() == type::getInt()
					? std::move( rhsExpr )
					: makeCast( type::getInt(), std::move( rhsExpr ) ) ) ) ) );
		return *this;
	}
}
