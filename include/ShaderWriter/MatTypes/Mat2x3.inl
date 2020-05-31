/*
See LICENSE file in root folder
*/
namespace sdw
{
	template< typename ValueT >
	Mat2x3T< ValueT >::Mat2x3T( Shader * shader
		, expr::ExprPtr expr )
		: Value{ shader, std::move( expr ) }
	{
	}

	template< typename ValueT >
	Mat2x3T< ValueT >::Mat2x3T( Mat2x3T const & rhs )
		: Value{ rhs.getShader(), makeExpr( *findShader( *this, rhs ), rhs ) }
	{
	}

	template< typename ValueT >
	Mat2x3T< ValueT > & Mat2x3T< ValueT >::operator=( Mat2x3T< ValueT > const & rhs )
	{
		if ( this->getContainer() )
		{
			writeAssignOperator< Mat2x3T< ValueT > >( *this, rhs, sdw::makeAssign );
		}
		else
		{
			Value::operator=( rhs );
		}

		return *this;
	}

	template< typename ValueT >
	template< typename RhsT >
	Mat2x3T< ValueT > & Mat2x3T< ValueT >::operator=( RhsT const & rhs )
	{
		updateContainer( rhs );
		writeAssignOperator< Mat2x3T< ValueT > >( *this, rhs, sdw::makeAssign );
		return *this;
	}

	template< typename ValueT >
	template< typename IndexT >
	Vec3T< ValueT > Mat2x3T< ValueT >::operator[]( IndexT const & offset )const
	{
		return writeBinOperator< Vec3T< ValueT > >( *this, offset, sdw::makeArrayAccess );
	}

	template< typename ValueT >
	inline Vec3T< ValueT > Mat2x3T< ValueT >::operator[]( int32_t offset )const
	{
		return writeBinOperator< Vec3T< ValueT > >( *this, offset, sdw::makeArrayAccess );
	}

	template< typename ValueT >
	inline Vec3T< ValueT > Mat2x3T< ValueT >::operator[]( uint32_t offset )const
	{
		return writeBinOperator< Vec3T< ValueT > >( *this, offset, sdw::makeArrayAccess );
	}

	template< typename ValueT >
	inline ast::type::TypePtr Mat2x3T< ValueT >::makeType( ast::type::TypesCache & cache )
	{
		return sdw::makeType< Mat2x3T< ValueT > >( cache );
	}
}
