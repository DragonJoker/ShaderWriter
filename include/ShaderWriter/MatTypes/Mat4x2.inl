/*
See LICENSE file in root folder
*/
namespace sdw
{
	template< typename ValueT >
	Mat4x2T< ValueT >::Mat4x2T( Shader * shader
		, expr::ExprPtr expr )
		: Value{ shader, std::move( expr ) }
	{
	}

	template< typename ValueT >
	Mat4x2T< ValueT >::Mat4x2T( Mat4x2T const & rhs )
		: Value{ rhs.getShader(), makeExpr( *findShader( *this, rhs ), rhs ) }
	{
	}

	template< typename ValueT >
	Mat4x2T< ValueT > & Mat4x2T< ValueT >::operator=( Mat4x2T< ValueT > const & rhs )
	{
		if ( this->getContainer() )
		{
			writeAssignOperator< Mat4x2T< ValueT > >( *this, rhs, sdw::makeAssign );
		}
		else
		{
			Value::operator=( rhs );
		}

		return *this;
	}

	template< typename ValueT >
	template< typename RhsT >
	Mat4x2T< ValueT > & Mat4x2T< ValueT >::operator=( RhsT const & rhs )
	{
		updateContainer( rhs );
		writeAssignOperator< Mat4x2T< ValueT > >( *this, rhs, sdw::makeAssign );
		return *this;
	}

	template< typename ValueT >
	template< typename IndexT >
	Vec2T< ValueT > Mat4x2T< ValueT >::operator[]( IndexT const & offset )const
	{
		return writeBinOperator< Vec2T< ValueT > >( *this, offset, sdw::makeArrayAccess );
	}

	template< typename ValueT >
	inline Vec2T< ValueT > Mat4x2T< ValueT >::operator[]( int32_t offset )const
	{
		return writeBinOperator< Vec2T< ValueT > >( *this, offset, sdw::makeArrayAccess );
	}

	template< typename ValueT >
	inline Vec2T< ValueT > Mat4x2T< ValueT >::operator[]( uint32_t offset )const
	{
		return writeBinOperator< Vec2T< ValueT > >( *this, offset, sdw::makeArrayAccess );
	}

	template< typename ValueT >
	inline ast::type::TypePtr Mat4x2T< ValueT >::makeType( ast::type::TypesCache & cache )
	{
		return sdw::makeType< Mat4x2T< ValueT > >( cache );
	}
}
