/*
See LICENSE file in root folder
*/
namespace sdw
{
	template< typename T >
	Double & Double::operator=( T const & rhs )
	{
		updateContainer( rhs );
		addStmt( *findShader( *this, rhs )
			, makeSimple( sdw::makeAssign( findTypesCache( *this, rhs ).getDouble()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}
}
