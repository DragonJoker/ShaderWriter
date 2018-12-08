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
	Mat4T< ValueT >::Mat4T( Mat4T const & rhs )
		: Value{ rhs.getShader(), makeExpr( rhs ) }
	{
	}

	template< typename ValueT >
	Mat4T< ValueT > & Mat4T< ValueT >::operator=( Mat4T< ValueT > const & rhs )
	{
		if ( this->getContainer() )
		{
			addStmt( *findShader( *this, rhs )
				, sdw::makeSimple( sdw::makeAssign( Mat4T< ValueT >::makeType( findTypesCache( *this, rhs ) )
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
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeAssign( Mat4T< ValueT >::makeType( findTypesCache( *this, rhs ) )
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	template< typename ValueT >
	template< typename IndexT >
	Vec4T< ValueT > Mat4T< ValueT >::operator[]( IndexT const & rhs )const
	{
		return Vec4T< ValueT >{ findShader( *this, rhs )
			, sdw::makeArrayAccess( Vec4T< ValueT >::makeType( findTypesCache( *this, rhs ) )
				, makeExpr( *this )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline Vec4T< ValueT > Mat4T< ValueT >::operator[]( int32_t offset )const
	{
		return Vec4T< ValueT >{ findShader( *this, offset )
			, sdw::makeArrayAccess( Vec4T< ValueT >::makeType( findTypesCache( *this ) )
				, makeExpr( *this )
				, makeExpr( offset ) ) };
	}

	template< typename ValueT >
	inline Vec4T< ValueT > Mat4T< ValueT >::operator[]( uint32_t offset )const
	{
		return Vec4T< ValueT >{ findShader( *this, offset )
			, sdw::makeArrayAccess( Vec4T< ValueT >::makeType( findTypesCache( *this ) )
				, makeExpr( *this )
				, makeExpr( offset ) ) };
	}

	template< typename ValueT >
	inline Mat4T< ValueT > & Mat4T< ValueT >::operator+=( Mat4T< ValueT > const & rhs )
	{
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeAddAssign( Mat4T< ValueT >::makeType( findTypesCache( *this, rhs ) )
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	template< typename ValueT >
	inline ast::type::TypePtr Mat4T< ValueT >::makeType( ast::type::TypesCache & cache )
	{
		return sdw::makeType< Mat4T< ValueT > >( cache );
	}

	template< typename ValueT >
	Vec4T< ValueT > operator*( Vec4T< ValueT > const & lhs,
		Mat4T< ValueT > const & rhs )
	{
		return Vec4T< ValueT >{ findShader( lhs, rhs )
			, sdw::makeTimes( Vec4T< ValueT >::makeType( findTypesCache( lhs, rhs ) )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	Vec4T< ValueT > operator*( Mat4T< ValueT > const & lhs
		, Vec4T< ValueT > const & rhs )
	{
		return Vec4T< ValueT >{ findShader( lhs, rhs )
			, sdw::makeTimes( Vec4T< ValueT >::makeType( findTypesCache( lhs, rhs ) )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	Mat4T< ValueT > operator*( Mat4T< ValueT > const & lhs
		, Mat4T< ValueT > const & rhs )
	{
		return Mat4T< ValueT >{ findShader( lhs, rhs )
			, sdw::makeTimes( Mat4T< ValueT >::makeType( findTypesCache( lhs, rhs ) )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	Mat4T< ValueT > operator*( ValueT const & lhs,
		Mat4T< ValueT > const & rhs )
	{
		return Mat4T< ValueT >{ findShader( lhs, rhs )
			, sdw::makeTimes( Mat4T< ValueT >::makeType( findTypesCache( lhs, rhs ) )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	Mat4T< ValueT > operator*( Mat4T< ValueT > const & lhs
		, ValueT const & rhs )
	{
		return Mat4T< ValueT >{ findShader( lhs, rhs )
			, sdw::makeTimes( Mat4T< ValueT >::makeType( findTypesCache( lhs, rhs ) )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}
}
