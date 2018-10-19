/*
See LICENSE file in root folder
*/
namespace sdw
{
	//*****************************************************************************************

	template< ImageType ST >
	ImageT< ST >::ImageT( Shader * shader
		, expr::ExprPtr expr )
		: Value{ shader, std::move( expr ) }
	{
	}

	template< ImageType ST >
	template< typename T >
	ImageT< ST > & ImageT< ST >::operator=( T const & rhs )
	{
		this->updateContainer( rhs );
		addStmt( *findContainer( *this, rhs )
			, sdw::makeSimple( sdw::makeAssign( m_expr->getType()
				, makeExpr( m_expr )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	template< ImageType ST >
	ImageT< ST >::operator uint32_t()
	{
		return 0u;
	}

	//*****************************************************************************************
}
