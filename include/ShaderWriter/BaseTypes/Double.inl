/*
See LICENSE file in root folder
*/
namespace sdw
{
	template< typename T >
	Double & Double::operator=( T const & rhs )
	{
		updateContainer( rhs );
		addStmt( *findContainer( *this, rhs )
			, makeSimple( sdw::makeAssign( type::getDouble()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}
}
