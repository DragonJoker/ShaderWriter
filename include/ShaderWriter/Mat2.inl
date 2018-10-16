/*
See LICENSE file in root folder
*/
namespace sdw
{
	template< typename ValueT >
	Mat2T< ValueT >::Mat2T( Shader * shader
		, expr::ExprPtr expr )
		: Value{ shader, std::move( expr ) }
	{
	}

	template< typename ValueT >
	Mat2T< ValueT > & Mat2T< ValueT >::operator=( Mat2T< ValueT > const & rhs )
	{
		if ( getContainer() )
		{
			addStmt( *findContainer( *this, rhs )
				, stmt::makeSimple( expr::makeAssign( makeType( this->getType()->getKind() )
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
	Mat2T< ValueT > & Mat2T< ValueT >::operator=( RhsT const & rhs )
	{
		updateContainer( rhs );
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeAssign( makeType( this->getType()->getKind() )
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	template< typename ValueT >
	template< typename IndexT >
	Vec2T< ValueT > Mat2T< ValueT >::operator[]( IndexT const & rhs )const
	{
		return Vec2T< ValueT >{ findShader( *this, rhs )
			, expr::makeArrayAccess( makeType( typeEnum< Vec2T< ValueT > > )
				, makeExpr( *this )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	Vec2T< ValueT > operator*( Vec2T< ValueT > const & lhs,
		Mat2T< ValueT > const & rhs )
	{
		return Vec2T< ValueT >{ findShader( lhs, rhs )
			, expr::makeTimes( makeType( typeEnum< Vec2T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	Vec2T< ValueT > operator*( Mat2T< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return Vec2T< ValueT >{ findShader( lhs, rhs )
			, expr::makeTimes( makeType( typeEnum< Vec2T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}
}
