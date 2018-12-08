/*
See LICENSE file in root folder
*/
namespace sdw
{
	template< typename T >
	Float & Float::operator=( T const & rhs )
	{
		updateContainer( rhs );
		addStmt( *findShader( *this, rhs )
			, makeSimple( sdw::makeAssign( findTypesCache( *this, rhs ).getFloat()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}
}
