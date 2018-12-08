/*
See LICENSE file in root folder
*/
namespace sdw
{
	template< typename ValueT >
	Mat3T< ValueT >::Mat3T( Shader * shader
		, expr::ExprPtr expr )
		: Value{ shader, std::move( expr ) }
	{
	}

	template< typename ValueT >
	Mat3T< ValueT >::Mat3T( Mat3T const & rhs )
		: Value{ rhs.getShader(), makeExpr( rhs ) }
	{
	}

	template< typename ValueT >
	Mat3T< ValueT > & Mat3T< ValueT >::operator=( Mat3T< ValueT > const & rhs )
	{
		if ( this->getContainer() )
		{
			addStmt( *findShader( *this, rhs )
				, sdw::makeSimple( sdw::makeAssign( Mat3T< ValueT >::makeType( findTypesCache( *this, rhs ) )
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
	Mat3T< ValueT > & Mat3T< ValueT >::operator=( RhsT const & rhs )
	{
		updateContainer( rhs );
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeAssign( Mat3T< ValueT >::makeType( findTypesCache( *this, rhs ) )
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	template< typename ValueT >
	template< typename IndexT >
	Vec3T< ValueT > Mat3T< ValueT >::operator[]( IndexT const & rhs )const
	{
		return Vec3T< ValueT >{ findShader( *this, rhs )
			, sdw::makeArrayAccess( Vec3T< ValueT >::makeType( findTypesCache( *this, rhs ) )
				, makeExpr( *this )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline Vec3T< ValueT > Mat3T< ValueT >::operator[]( int32_t offset )const
	{
		return Vec3T< ValueT >{ findShader( *this, offset )
			, sdw::makeArrayAccess( Vec3T< ValueT >::makeType( findTypesCache( *this ) )
				, makeExpr( *this )
				, makeExpr( offset ) ) };
	}

	template< typename ValueT >
	inline Vec3T< ValueT > Mat3T< ValueT >::operator[]( uint32_t offset )const
	{
		return Vec3T< ValueT >{ findShader( *this, offset )
			, sdw::makeArrayAccess( Vec3T< ValueT >::makeType( findTypesCache( *this ) )
				, makeExpr( *this )
				, makeExpr( offset ) ) };
	}

	template< typename ValueT >
	inline Mat3T< ValueT > & Mat3T< ValueT >::operator+=( Mat3T< ValueT > const & rhs )
	{
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeAddAssign( Mat3T< ValueT >::makeType( findTypesCache( *this, rhs ) )
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	template< typename ValueT >
	Vec3T< ValueT > operator*( Vec3T< ValueT > const & lhs,
		Mat3T< ValueT > const & rhs )
	{
		return Vec3T< ValueT >{ findShader( lhs, rhs )
			, sdw::makeTimes( Vec3T< ValueT >::makeType( findTypesCache( lhs, rhs ) )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	Vec3T< ValueT > operator*( Mat3T< ValueT > const & lhs
		, Vec3T< ValueT > const & rhs )
	{
		return Vec3T< ValueT >{ findShader( lhs, rhs )
			, sdw::makeTimes( Vec3T< ValueT >::makeType( findTypesCache( lhs, rhs ) )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	Mat3T< ValueT > operator*( Mat3T< ValueT > const & lhs
		, Mat3T< ValueT > const & rhs )
	{
		return Mat3T< ValueT >{ findShader( lhs, rhs )
			, sdw::makeTimes( Mat3T< ValueT >::makeType( findTypesCache( lhs, rhs ) )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	Mat3T< ValueT > operator*( ValueT const & lhs,
		Mat3T< ValueT > const & rhs )
	{
		return Mat3T< ValueT >{ findShader( lhs, rhs )
			, sdw::makeTimes( Mat3T< ValueT >::makeType( findTypesCache( lhs, rhs ) )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	Mat3T< ValueT > operator*( Mat3T< ValueT > const & lhs
		, ValueT const & rhs )
	{
		return Mat3T< ValueT >{ findShader( lhs, rhs )
			, sdw::makeTimes( Mat3T< ValueT >::makeType( findTypesCache( lhs, rhs ) )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline ast::type::TypePtr Mat3T< ValueT >::makeType( ast::type::TypesCache & cache )
	{
		return sdw::makeType< Mat3T< ValueT > >( cache );
	}
}
