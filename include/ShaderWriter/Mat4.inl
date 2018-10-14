/*
See LICENSE file in root folder
*/
namespace sdw
{
	template< typename ValueT >
	Mat4T< ValueT >::Mat4T( Shader * shader
		, expr::ExprPtr expr )
		: Value{ shader, std::move( expr ) }
	{
	}

	template< typename ValueT >
	Mat4T< ValueT > & Mat4T< ValueT >::operator=( Mat4T< ValueT > const & rhs )
	{
		if ( m_container )
		{
			addStmt( *findContainer( *this, rhs )
				, stmt::makeSimple( expr::makeAssign( makeType( getType()->getKind() )
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}
		else
		{
			Value::operator=( rhs );
		}

		return *this;
	}

	template< typename ValueT >
	template< typename RhsT >
	Mat4T< ValueT > & Mat4T< ValueT >::operator=( RhsT const & rhs )
	{
		updateContainer( rhs );
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeAssign( makeType( getType()->getKind() )
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	template< typename ValueT >
	template< typename IndexT >
	Vec4T< ValueT > Mat4T< ValueT >::operator[]( IndexT const & rhs )const
	{
		return Vec4T< ValueT >{ findShader( *this, rhs )
			, expr::makeArrayAccess( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( *this )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	Vec4T< ValueT > operator*( Vec4T< ValueT > const & lhs,
		Mat4T< ValueT > const & rhs )
	{
		return Vec4T< ValueT >{ findShader( lhs, rhs )
			, expr::makeTimes( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	Vec4T< ValueT > operator*( Mat4T< ValueT > const & lhs
		, Vec4T< ValueT > const & rhs )
	{
		return Vec4T< ValueT >{ findShader( lhs, rhs )
			, expr::makeTimes( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}
}
