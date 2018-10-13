/*
See LICENSE file in root folder
*/
namespace sdw
{
	template< typename ValueT >
	Mat4T< ValueT >::Mat4T( stmt::Container * container
		, expr::ExprPtr expr )
		: Value{ container, std::move( expr ) }
	{
	}

	template< typename ValueT >
	Mat4T< ValueT > & Mat4T< ValueT >::operator=( Mat4T< ValueT > const & rhs )
	{
		if ( m_container )
		{
			addStmt( *m_container
				, stmt::makeSimple( expr::makeAssign( makeType( m_expr->getType()->getKind() )
					, makeExpr( m_expr )
					, makeExpr( rhs ) ) ) );
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
	Mat4T< ValueT > & Mat4T< ValueT >::operator=( RhsT const & rhs )
	{
		updateContainer( rhs );
		addStmt( *m_container
			, stmt::makeSimple( expr::makeAssign( makeType( m_expr->getType()->getKind() )
				, makeExpr( m_expr )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	template< typename ValueT >
	template< typename IndexT >
	Vec4T< ValueT > Mat4T< ValueT >::operator[]( IndexT const & rhs )const
	{
		return Vec4T< ValueT >{ m_container
			, expr::makeArrayAccess( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( m_expr )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	Vec4T< ValueT > operator*( Vec4T< ValueT > const & lhs,
		Mat4T< ValueT > const & rhs )
	{
		return Vec4T< ValueT >{ m_container
			, expr::makeTimes( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	Vec4T< ValueT > operator*( Mat4T< ValueT > const & lhs
		, Vec4T< ValueT > const & rhs )
	{
		return Vec4T< ValueT >{ m_container
			, expr::makeTimes( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}
}
