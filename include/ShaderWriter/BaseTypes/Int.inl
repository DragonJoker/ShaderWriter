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
		addStmt( *findContainer( *this, rhs )
			, sdw::makeSimple( makeAssign( type::getInt()
				, makeExpr( *this )
				, ( rhsExpr->getType() == type::getInt()
					? std::move( rhsExpr )
					: makeCast( type::getInt(), std::move( rhsExpr ) ) ) ) ) );
		return *this;
	}
}
