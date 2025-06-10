/*
See LICENSE file in root folder
*/
namespace sdw
{
	template< typename ValueT >
	Mat2x3T< ValueT >::Mat2x3T( ShaderWriter & writer
		, expr::ExprPtr expr
		, bool enabled )
		: Value{ writer, std::move( expr ), enabled }
	{
	}

	template< typename ValueT >
	template< typename RhsT >
	ReturnWrapperT< Mat2x3T< ValueT > > Mat2x3T< ValueT >::operator=( RhsT const & rhs )
	{
		updateContainer( rhs );
		return writeAssignOperator< Mat2x3T< ValueT > >( *this, rhs, sdw::makeAssign );
	}

	template< typename ValueT >
	template< typename IndexT >
	ReturnWrapperT< Vec3T< ValueT > > Mat2x3T< ValueT >::operator[]( IndexT const & offset )const
	{
		return writeBinOperator< Vec3T< ValueT > >( *this, offset, sdw::makeArrayAccess );
	}

	template< typename ValueT >
	ReturnWrapperT< Vec3T< ValueT > > Mat2x3T< ValueT >::operator[]( int32_t offset )const
	{
		return writeBinOperator< Vec3T< ValueT > >( *this, offset, sdw::makeArrayAccess );
	}

	template< typename ValueT >
	ReturnWrapperT< Vec3T< ValueT > > Mat2x3T< ValueT >::operator[]( uint32_t offset )const
	{
		return writeBinOperator< Vec3T< ValueT > >( *this, offset, sdw::makeArrayAccess );
	}

	template< typename ValueT >
	ast::type::TypePtr Mat2x3T< ValueT >::makeType( ast::type::TypesCache & cache )
	{
		return sdw::makeType< Mat2x3T< ValueT > >( cache );
	}
}
