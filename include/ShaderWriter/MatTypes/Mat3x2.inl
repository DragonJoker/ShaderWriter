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
	ReturnWrapperT< Mat3x2T< ValueT > > Mat3x2T< ValueT >::operator=( RhsT const & rhs )
	{
		updateContainer( rhs );
		return writeAssignOperator< Mat3x2T< ValueT > >( *this, rhs, sdw::makeAssign );
	}

	template< typename ValueT >
	template< typename IndexT >
	ReturnWrapperT< Vec2T< ValueT > > Mat3x2T< ValueT >::operator[]( IndexT const & offset )const
	{
		return writeBinOperator< Vec2T< ValueT > >( *this, offset, sdw::makeArrayAccess );
	}

	template< typename ValueT >
	ReturnWrapperT< Vec2T< ValueT > > Mat3x2T< ValueT >::operator[]( int32_t offset )const
	{
		return writeBinOperator< Vec2T< ValueT > >( *this, offset, sdw::makeArrayAccess );
	}

	template< typename ValueT >
	ReturnWrapperT< Vec2T< ValueT > > Mat3x2T< ValueT >::operator[]( uint32_t offset )const
	{
		return writeBinOperator< Vec2T< ValueT > >( *this, offset, sdw::makeArrayAccess );
	}

	template< typename ValueT >
	ast::type::TypePtr Mat3x2T< ValueT >::makeType( ast::type::TypesCache & cache )
	{
		return sdw::makeType< Mat3x2T< ValueT > >( cache );
	}
}
