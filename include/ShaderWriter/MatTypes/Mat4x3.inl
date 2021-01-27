/*
See LICENSE file in root folder
*/
namespace sdw
{
	template< typename ValueT >
	Mat4x3T< ValueT >::Mat4x3T( ShaderWriter & writer
		, expr::ExprPtr expr
		, bool enabled )
		: Value{ writer, std::move( expr ), enabled }
	{
	}

	template< typename ValueT >
	Mat4x3T< ValueT >::Mat4x3T( Mat4x3T const & rhs )
		: Value{ *rhs.getWriter(), makeExpr( *findWriter( *this, rhs ), rhs ), rhs.isEnabled() }
	{
	}

	template< typename ValueT >
	Mat4x3T< ValueT > & Mat4x3T< ValueT >::operator=( Mat4x3T< ValueT > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			if ( this->getContainer() )
			{
				writeAssignOperator< Mat4x3T< ValueT > >( *this, rhs, sdw::makeAssign );
			}
			else
			{
				Value::operator=( rhs );
			}
		}

		return *this;
	}

	template< typename ValueT >
	template< typename RhsT >
	Mat4x3T< ValueT > & Mat4x3T< ValueT >::operator=( RhsT const & rhs )
	{
		updateContainer( rhs );
		writeAssignOperator< Mat4x3T< ValueT > >( *this, rhs, sdw::makeAssign );
		return *this;
	}

	template< typename ValueT >
	template< typename IndexT >
	Vec3T< ValueT > Mat4x3T< ValueT >::operator[]( IndexT const & offset )const
	{
		return writeBinOperator< Vec3T< ValueT > >( *this, offset, sdw::makeArrayAccess );
	}

	template< typename ValueT >
	inline Vec3T< ValueT > Mat4x3T< ValueT >::operator[]( int32_t offset )const
	{
		return writeBinOperator< Vec3T< ValueT > >( *this, offset, sdw::makeArrayAccess );
	}

	template< typename ValueT >
	inline Vec3T< ValueT > Mat4x3T< ValueT >::operator[]( uint32_t offset )const
	{
		return writeBinOperator< Vec3T< ValueT > >( *this, offset, sdw::makeArrayAccess );
	}

	template< typename ValueT >
	inline ast::type::TypePtr Mat4x3T< ValueT >::makeType( ast::type::TypesCache & cache )
	{
		return sdw::makeType< Mat4x3T< ValueT > >( cache );
	}
}
