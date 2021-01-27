/*
See LICENSE file in root folder
*/
namespace sdw
{
	template< typename ValueT >
	Mat2x4T< ValueT >::Mat2x4T( ShaderWriter & writer
		, expr::ExprPtr expr
		, bool enabled )
		: Value{ writer, std::move( expr ), enabled }
	{
	}

	template< typename ValueT >
	Mat2x4T< ValueT >::Mat2x4T( Mat2x4T const & rhs )
		: Value{ *rhs.getWriter(), makeExpr( *findWriter( *this, rhs ), rhs ), rhs.isEnabled() }
	{
	}

	template< typename ValueT >
	Mat2x4T< ValueT > & Mat2x4T< ValueT >::operator=( Mat2x4T< ValueT > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			if ( this->getContainer() )
			{
				writeAssignOperator< Mat2x4T< ValueT > >( *this, rhs, sdw::makeAssign );
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
	Mat2x4T< ValueT > & Mat2x4T< ValueT >::operator=( RhsT const & rhs )
	{
		updateContainer( rhs );
		writeAssignOperator< Mat2x4T< ValueT > >( *this, rhs, sdw::makeAssign );
		return *this;
	}

	template< typename ValueT >
	template< typename IndexT >
	Vec4T< ValueT > Mat2x4T< ValueT >::operator[]( IndexT const & offset )const
	{
		return writeBinOperator< Vec4T< ValueT > >( *this, offset, sdw::makeArrayAccess );
	}

	template< typename ValueT >
	inline Vec4T< ValueT > Mat2x4T< ValueT >::operator[]( int32_t offset )const
	{
		return writeBinOperator< Vec4T< ValueT > >( *this, offset, sdw::makeArrayAccess );
	}

	template< typename ValueT >
	inline Vec4T< ValueT > Mat2x4T< ValueT >::operator[]( uint32_t offset )const
	{
		return writeBinOperator< Vec4T< ValueT > >( *this, offset, sdw::makeArrayAccess );
	}

	template< typename ValueT >
	inline ast::type::TypePtr Mat2x4T< ValueT >::makeType( ast::type::TypesCache & cache )
	{
		return sdw::makeType< Mat2x4T< ValueT > >( cache );
	}
}
