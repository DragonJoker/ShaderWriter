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
	Mat2T< ValueT >::Mat2T( Mat2T const & rhs )
		: Value{ rhs.getShader(), makeExpr( rhs ) }
	{
	}

	template< typename ValueT >
	Mat2T< ValueT > & Mat2T< ValueT >::operator=( Mat2T< ValueT > const & rhs )
	{
		if ( this->getContainer() )
		{
			addStmt( *findShader( *this, rhs )
				, sdw::makeSimple( sdw::makeAssign( Mat2T< ValueT >::makeType( findTypesCache( *this, rhs ) )
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
	inline Mat2T< ValueT > & Mat2T< ValueT >::operator+=( Mat2T< ValueT > const & rhs )
	{
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeAddAssign( Mat2T< ValueT >::makeType( findTypesCache( *this, rhs ) )
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	template< typename ValueT >
	template< typename RhsT >
	Mat2T< ValueT > & Mat2T< ValueT >::operator=( RhsT const & rhs )
	{
		updateContainer( rhs );
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeAssign( Mat2T< ValueT >::makeType( findTypesCache( *this, rhs ) )
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	template< typename ValueT >
	template< typename IndexT >
	Vec2T< ValueT > Mat2T< ValueT >::operator[]( IndexT const & rhs )const
	{
		return Vec2T< ValueT >{ findShader( *this, rhs )
			, sdw::makeArrayAccess( Vec2T< ValueT >::makeType( findTypesCache( *this, rhs ) )
				, makeExpr( *this )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline Vec2T< ValueT > Mat2T< ValueT >::operator[]( int32_t offset )const
	{
		return Vec2T< ValueT >{ findShader( *this, offset )
			, sdw::makeArrayAccess( Vec2T< ValueT >::makeType( findTypesCache( *this ) )
				, makeExpr( *this )
				, makeExpr( offset ) ) };
	}

	template< typename ValueT >
	inline Vec2T< ValueT > Mat2T< ValueT >::operator[]( uint32_t offset )const
	{
		return Vec2T< ValueT >{ findShader( *this, offset )
			, sdw::makeArrayAccess( Vec2T< ValueT >::makeType( findTypesCache( *this ) )
				, makeExpr( *this )
				, makeExpr( offset ) ) };
	}

	template< typename ValueT >
	Vec2T< ValueT > operator*( Vec2T< ValueT > const & lhs,
		Mat2T< ValueT > const & rhs )
	{
		return Vec2T< ValueT >{ findShader( lhs, rhs )
			, sdw::makeTimes( Vec2T< ValueT >::makeType( findTypesCache( lhs, rhs ) )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	Vec2T< ValueT > operator*( Mat2T< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return Vec2T< ValueT >{ findShader( lhs, rhs )
			, sdw::makeTimes( Vec2T< ValueT >::makeType( findTypesCache( lhs, rhs ) )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	Mat2T< ValueT > operator*( Mat2T< ValueT > const & lhs
		, Mat2T< ValueT > const & rhs )
	{
		return Mat2T< ValueT >{ findShader( lhs, rhs )
			, sdw::makeTimes( Mat2T< ValueT >::makeType( findTypesCache( lhs, rhs ) )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	Mat2T< ValueT > operator*( ValueT const & lhs,
		Mat2T< ValueT > const & rhs )
	{
		return Mat2T< ValueT >{ findShader( lhs, rhs )
			, sdw::makeTimes( Mat2T< ValueT >::makeType( findTypesCache( lhs, rhs ) )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	Mat2T< ValueT > operator*( Mat2T< ValueT > const & lhs
		, ValueT const & rhs )
	{
		return Mat2T< ValueT >{ findShader( lhs, rhs )
			, sdw::makeTimes( Mat2T< ValueT >::makeType( findTypesCache( lhs, rhs ) )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline ast::type::TypePtr Mat2T< ValueT >::makeType( ast::type::TypesCache & cache )
	{
		return sdw::makeType< Mat2T< ValueT > >( cache );
	}
}
