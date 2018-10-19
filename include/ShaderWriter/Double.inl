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
			, makeSimple( makeAssign( type::getDouble()
				, makeExpr( m_expr )
				, makeExpr( rhs ) ) ) );
		return *this;
	}
}
