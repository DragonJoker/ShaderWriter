/*
See LICENSE file in root folder
*/
namespace sdw
{
	template< typename T >
	Int & Int::operator=( T const & rhs )
	{
		updateContainer( rhs );
		addStmt( *findContainer( *this, rhs )
			, sdw::makeSimple( makeAssign( type::getInt()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}
}
