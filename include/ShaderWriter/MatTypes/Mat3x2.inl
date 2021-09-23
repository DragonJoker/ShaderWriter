/*
See LICENSE file in root folder
*/
namespace sdw
{
	template< typename ValueT >
	Mat3x2T< ValueT >::Mat3x2T( ShaderWriter & writer
		, expr::ExprPtr expr
		, bool enabled )
		: Value{ writer, std::move( expr ), enabled }
	{
	}

	template< typename ValueT >
	template< typename RhsT >
	Mat3x2T< ValueT > & Mat3x2T< ValueT >::operator=( RhsT const & rhs )
	{
		updateContainer( rhs );
		writeAssignOperator< Mat3x2T< ValueT > >( *this, rhs, sdw::makeAssign );
		return *this;
	}

	template< typename ValueT >
	template< typename IndexT >
	Vec2T< ValueT > Mat3x2T< ValueT >::operator[]( IndexT const & offset )const
	{
		return writeBinOperator< Vec2T< ValueT > >( *this, offset, sdw::makeArrayAccess );
	}

	template< typename ValueT >
	inline Vec2T< ValueT > Mat3x2T< ValueT >::operator[]( int32_t offset )const
	{
		return writeBinOperator< Vec2T< ValueT > >( *this, offset, sdw::makeArrayAccess );
	}

	template< typename ValueT >
	inline Vec2T< ValueT > Mat3x2T< ValueT >::operator[]( uint32_t offset )const
	{
		return writeBinOperator< Vec2T< ValueT > >( *this, offset, sdw::makeArrayAccess );
	}

	template< typename ValueT >
	inline ast::type::TypePtr Mat3x2T< ValueT >::makeType( ast::type::TypesCache & cache )
	{
		return sdw::makeType< Mat3x2T< ValueT > >( cache );
	}
}
