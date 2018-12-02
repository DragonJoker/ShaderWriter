/*
See LICENSE file in root folder
*/
namespace sdw
{
	template< typename ValueT >
	Mat3x4T< ValueT >::Mat3x4T( Shader * shader
		, expr::ExprPtr expr )
		: Value{ shader, std::move( expr ) }
	{
	}

	template< typename ValueT >
	Mat3x4T< ValueT >::Mat3x4T( Mat3x4T const & rhs )
		: Value{ rhs.getShader(), makeExpr( rhs ) }
	{
	}

	template< typename ValueT >
	Mat3x4T< ValueT > & Mat3x4T< ValueT >::operator=( Mat3x4T< ValueT > const & rhs )
	{
		if ( this->getContainer() )
		{
			addStmt( *findContainer( *this, rhs )
				, sdw::makeSimple( sdw::makeAssign( Mat3x4T< ValueT >::makeType()
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
	Mat3x4T< ValueT > & Mat3x4T< ValueT >::operator=( RhsT const & rhs )
	{
		updateContainer( rhs );
		addStmt( *findContainer( *this, rhs )
			, sdw::makeSimple( sdw::makeAssign( Mat3x4T< ValueT >::makeType()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	template< typename ValueT >
	template< typename IndexT >
	Vec4T< ValueT > Mat3x4T< ValueT >::operator[]( IndexT const & rhs )const
	{
		return Vec4T< ValueT >{ findShader( *this, rhs )
			, sdw::makeArrayAccess( Vec4T< ValueT >::makeType()
				, makeExpr( *this )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline ast::type::TypePtr Mat3x4T< ValueT >::makeType()
	{
		return sdw::makeType< Mat3x4T< ValueT > >();
	}
}
