/*
See LICENSE file in root folder
*/
namespace sdw
{
	template< typename T >
	Float & Float::operator=( T const & rhs )
	{
		updateContainer( rhs );
		addStmt( *findContainer( *this, rhs )
			, makeSimple( sdw::makeAssign( type::getFloat()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}
}
