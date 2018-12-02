/*
See LICENSE file in root folder
*/
namespace sdw
{
	template< typename ValueT >
	Mat4x3T< ValueT >::Mat4x3T( Shader * shader
		, expr::ExprPtr expr )
		: Value{ shader, std::move( expr ) }
	{
	}

	template< typename ValueT >
	Mat4x3T< ValueT >::Mat4x3T( Mat4x3T const & rhs )
		: Value{ rhs.getShader(), makeExpr( rhs ) }
	{
	}

	template< typename ValueT >
	Mat4x3T< ValueT > & Mat4x3T< ValueT >::operator=( Mat4x3T< ValueT > const & rhs )
	{
		if ( this->getContainer() )
		{
			addStmt( *findContainer( *this, rhs )
				, sdw::makeSimple( sdw::makeAssign( Mat4x3T< ValueT >::makeType()
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
	Mat4x3T< ValueT > & Mat4x3T< ValueT >::operator=( RhsT const & rhs )
	{
		updateContainer( rhs );
		addStmt( *findContainer( *this, rhs )
			, sdw::makeSimple( sdw::makeAssign( Mat4x3T< ValueT >::makeType()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	template< typename ValueT >
	template< typename IndexT >
	Vec3T< ValueT > Mat4x3T< ValueT >::operator[]( IndexT const & rhs )const
	{
		return Vec3T< ValueT >{ findShader( *this, rhs )
			, sdw::makeArrayAccess( Vec3T< ValueT >::makeType()
				, makeExpr( *this )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline ast::type::TypePtr Mat4x3T< ValueT >::makeType()
	{
		return sdw::makeType< Mat4x3T< ValueT > >();
	}
}
