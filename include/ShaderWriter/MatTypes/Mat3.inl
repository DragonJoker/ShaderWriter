/*
See LICENSE file in root folder
*/
namespace sdw
{
	//*************************************************************************

	template< typename ValueT >
	Mat3T< ValueT >::Mat3T( ShaderWriter & writer
		, expr::ExprPtr expr
		, bool enabled )
		: Value{ writer, std::move( expr ), enabled }
	{
	}

	template< typename ValueT >
	inline Mat3T< ValueT > & Mat3T< ValueT >::operator+=( Mat3T< ValueT > const & rhs )
	{
		writeAssignOperator< Mat3T< ValueT > >( *this, rhs, sdw::makeAddAssign );
		return *this;
	}

	template< typename ValueT >
	template< typename RhsT >
	Mat3T< ValueT > & Mat3T< ValueT >::operator=( RhsT const & rhs )
	{
		updateContainer( rhs );
		writeAssignOperator< Mat3T< ValueT > >( *this, rhs, sdw::makeAssign );
		return *this;
	}

	template< typename ValueT >
	template< typename IndexT >
	Vec3T< ValueT > Mat3T< ValueT >::operator[]( IndexT const & offset )const
	{
		return writeBinOperator< Vec3T< ValueT > >( *this, offset, sdw::makeArrayAccess );
	}

	template< typename ValueT >
	inline Vec3T< ValueT > Mat3T< ValueT >::operator[]( int32_t offset )const
	{
		return writeBinOperator< Vec3T< ValueT > >( *this, offset, sdw::makeArrayAccess );
	}

	template< typename ValueT >
	inline Vec3T< ValueT > Mat3T< ValueT >::operator[]( uint32_t offset )const
	{
		return writeBinOperator< Vec3T< ValueT > >( *this, offset, sdw::makeArrayAccess );
	}

	template< typename ValueT >
	inline ast::type::TypePtr Mat3T< ValueT >::makeType( ast::type::TypesCache & cache )
	{
		return sdw::makeType< Mat3T< ValueT > >( cache );
	}

	//*************************************************************************

	template< typename ValueT >
	Vec3T< ValueT > operator*( Vec3T< ValueT > const & lhs
		, Mat3T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec3T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	Vec3T< ValueT > operator*( Mat3T< ValueT > const & lhs
		, Vec3T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec3T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	Mat3T< ValueT > operator*( Mat3T< ValueT > const & lhs
		, Mat3T< ValueT > const & rhs )
	{
		return writeBinOperator< Mat3T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	Mat3T< ValueT > operator*( ValueT const & lhs
		, Mat3T< ValueT > const & rhs )
	{
		return writeBinOperator< Mat3T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	Mat3T< ValueT > operator*( Mat3T< ValueT > const & lhs
		, ValueT const & rhs )
	{
		return writeBinOperator< Mat3T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	//*************************************************************************
}
