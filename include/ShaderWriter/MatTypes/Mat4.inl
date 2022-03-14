/*
See LICENSE file in root folder
*/
namespace sdw
{
	//*************************************************************************

	template< typename ValueT >
	Mat4x4T< ValueT >::Mat4x4T( ShaderWriter & writer
		, expr::ExprPtr expr
		, bool enabled )
		: Value{ writer, std::move( expr ), enabled }
	{
	}

	template< typename ValueT >
	inline Mat4x4T< ValueT > & Mat4x4T< ValueT >::operator+=( Mat4x4T< ValueT > const & rhs )
	{
		writeAssignOperator< Mat4x4T< ValueT > >( *this, rhs, sdw::makeAddAssign );
		return *this;
	}

	template< typename ValueT >
	template< typename RhsT >
	Mat4x4T< ValueT > & Mat4x4T< ValueT >::operator=( RhsT const & rhs )
	{
		updateContainer( rhs );
		writeAssignOperator< Mat4x4T< ValueT > >( *this, rhs, sdw::makeAssign );
		return *this;
	}

	template< typename ValueT >
	template< typename IndexT >
	Vec4T< ValueT > Mat4x4T< ValueT >::operator[]( IndexT const & offset )const
	{
		return writeBinOperator< Vec4T< ValueT > >( *this, offset, sdw::makeArrayAccess );
	}

	template< typename ValueT >
	inline Vec4T< ValueT > Mat4x4T< ValueT >::operator[]( int32_t offset )const
	{
		return writeBinOperator< Vec4T< ValueT > >( *this, offset, sdw::makeArrayAccess );
	}

	template< typename ValueT >
	inline Vec4T< ValueT > Mat4x4T< ValueT >::operator[]( uint32_t offset )const
	{
		return writeBinOperator< Vec4T< ValueT > >( *this, offset, sdw::makeArrayAccess );
	}

	template< typename ValueT >
	inline ast::type::TypePtr Mat4x4T< ValueT >::makeType( ast::type::TypesCache & cache )
	{
		return sdw::makeType< Mat4x4T< ValueT > >( cache );
	}

	//*************************************************************************

	template< typename ValueT >
	Vec4T< ValueT > operator*( Vec4T< ValueT > const & lhs
		, Mat4x4T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	Vec4T< ValueT > operator*( Mat4x4T< ValueT > const & lhs
		, Vec4T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	Mat4x4T< ValueT > operator*( Mat4x4T< ValueT > const & lhs
		, Mat4x4T< ValueT > const & rhs )
	{
		return writeBinOperator< Mat4x4T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	Mat4x4T< ValueT > operator*( ValueT const & lhs
		, Mat4x4T< ValueT > const & rhs )
	{
		return writeBinOperator< Mat4x4T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	Mat4x4T< ValueT > operator*( Mat4x4T< ValueT > const & lhs
		, ValueT const & rhs )
	{
		return writeBinOperator< Mat4x4T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	//*************************************************************************
}
