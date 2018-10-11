/*
See LICENSE file in root folder
*/
namespace sdw
{
	template< typename ValueT >
	Mat2T< ValueT >::Mat2T( stmt::Container * container
		, expr::ExprPtr expr )
		: Value{ container, std::move( expr ) }
	{
	}

	template< typename ValueT >
	Mat2T< ValueT > & Mat2T< ValueT >::operator=( Mat2T< ValueT > const & rhs )
	{
		if ( m_container )
		{
			addStmt( *m_container
				, stmt::makeSimple( expr::makeAssign( makeType( m_expr->get()->getKind() )
					, make( m_expr )
					, make( rhs ) ) ) );
		}
		else
		{
			Type::operator=( rhs );
			m_container = rhs.m_container;
		}

		return *this;
	}

	template< typename ValueT >
	template< typename RhsT >
	Mat2T< ValueT > & Mat2T< ValueT >::operator=( RhsT const & rhs )
	{
		updateContainer( rhs );
		addStmt( *m_container
			, stmt::makeSimple( expr::makeAssign( makeType( m_expr->get()->getKind() )
				, make( m_expr )
				, make( rhs ) ) ) );
		return *this;
	}

	template< typename ValueT >
	template< typename IndexT >
	Vec2T< ValueT > Mat2T< ValueT >::operator[]( IndexT const & rhs )const
	{
		return Vec2T< ValueT >{ m_container
			, expr::makeArrayAccess( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, m_expr
				, make( rhs ) ) };
	}
}
