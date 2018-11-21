/*
See LICENSE file in root folder
*/
namespace sdw
{
	template< typename T >
	Sampler & Sampler::operator=( T const & rhs )
	{
		this->updateContainer( rhs );
		addStmt( *findContainer( *this, rhs )
			, sdw::makeSimple( sdw::makeAssign( m_expr->getType()
				, makeExpr( m_expr )
				, makeExpr( rhs ) ) ) );
		return *this;
	}
}
