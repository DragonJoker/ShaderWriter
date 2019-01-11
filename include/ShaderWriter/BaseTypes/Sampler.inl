/*
See LICENSE file in root folder
*/
namespace sdw
{
	template< typename T >
	Sampler & Sampler::operator=( T const & rhs )
	{
		this->updateContainer( rhs );
		auto & shader = *findShader( *this, rhs );
		addStmt( shader
			, sdw::makeSimple( sdw::makeAssign( m_expr->getType()
				, makeExpr( shader, m_expr )
				, makeExpr( shader, rhs ) ) ) );
		return *this;
	}
}
