/*
See LICENSE file in root folder
*/
namespace sdw
{
	//*************************************************************************

	template< typename ValueT >
	Mat3x3T< ValueT >::Mat3x3T( ShaderWriter & writer
		, expr::ExprPtr expr
		, bool enabled )
		: Value{ writer, std::move( expr ), enabled }
	{
	}

	template< typename ValueT >
	Mat3x3T< ValueT > & Mat3x3T< ValueT >::operator+=( Mat3x3T< ValueT > const & rhs )
	{
		writeAssignOperator< Mat3x3T< ValueT > >( *this, rhs, sdw::makeAddAssign );
		return *this;
	}

	template< typename ValueT >
	template< typename RhsT >
	ReturnWrapperT< Mat3x3T< ValueT > > Mat3x3T< ValueT >::operator=( RhsT const & rhs )
	{
		return writeAssignOperator< Mat3x3T< ValueT > >( *this, rhs, sdw::makeAssign );
	}

	template< typename ValueT >
	template< typename IndexT >
	ReturnWrapperT< Vec3T< ValueT > > Mat3x3T< ValueT >::operator[]( IndexT const & offset )const
	{
		return writeBinOperator< Vec3T< ValueT > >( *this, offset, sdw::makeArrayAccess );
	}

	template< typename ValueT >
	ReturnWrapperT< Vec3T< ValueT > > Mat3x3T< ValueT >::operator[]( int32_t offset )const
	{
		return writeBinOperator< Vec3T< ValueT > >( *this, offset, sdw::makeArrayAccess );
	}

	template< typename ValueT >
	ReturnWrapperT< Vec3T< ValueT > > Mat3x3T< ValueT >::operator[]( uint32_t offset )const
	{
		return writeBinOperator< Vec3T< ValueT > >( *this, offset, sdw::makeArrayAccess );
	}

	template< typename ValueT >
	ast::type::TypePtr Mat3x3T< ValueT >::makeType( ast::type::TypesCache & cache )
	{
		return sdw::makeType< Mat3x3T< ValueT > >( cache );
	}

	//*************************************************************************

	template< typename ValueT >
	ReturnWrapperT< Vec3T< ValueT > > operator*( Vec3T< ValueT > const & lhs
		, Mat3x3T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec3T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	ReturnWrapperT< Vec3T< ValueT > > operator*( Mat3x3T< ValueT > const & lhs
		, Vec3T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec3T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	ReturnWrapperT< Mat3x3T< ValueT > > operator*( Mat3x3T< ValueT > const & lhs
		, Mat3x3T< ValueT > const & rhs )
	{
		return writeBinOperator< Mat3x3T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	ReturnWrapperT< Mat3x3T< ValueT > > operator*( ValueT const & lhs
		, Mat3x3T< ValueT > const & rhs )
	{
		return writeBinOperator< Mat3x3T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	ReturnWrapperT< Mat3x3T< ValueT > > operator*( Mat3x3T< ValueT > const & lhs
		, ValueT const & rhs )
	{
		return writeBinOperator< Mat3x3T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	//*************************************************************************
}
