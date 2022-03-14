/*
See LICENSE file in root folder
*/
namespace sdw
{
	//*************************************************************************

	template< typename ValueT >
	Mat2x2T< ValueT >::Mat2x2T( ShaderWriter & writer
		, expr::ExprPtr expr
		, bool enabled )
		: Value{ writer, std::move( expr ), enabled }
	{
	}

	template< typename ValueT >
	inline Mat2x2T< ValueT > & Mat2x2T< ValueT >::operator+=( Mat2x2T< ValueT > const & rhs )
	{
		writeAssignOperator< Mat2x2T< ValueT > >( *this, rhs, sdw::makeAddAssign );
		return *this;
	}

	template< typename ValueT >
	template< typename RhsT >
	Mat2x2T< ValueT > & Mat2x2T< ValueT >::operator=( RhsT const & rhs )
	{
		updateContainer( rhs );
		writeAssignOperator< Mat2x2T< ValueT > >( *this, rhs, sdw::makeAssign );
		return *this;
	}

	template< typename ValueT >
	template< typename IndexT >
	Vec2T< ValueT > Mat2x2T< ValueT >::operator[]( IndexT const & offset )const
	{
		return writeBinOperator< Vec2T< ValueT > >( *this, offset, sdw::makeArrayAccess );
	}

	template< typename ValueT >
	inline Vec2T< ValueT > Mat2x2T< ValueT >::operator[]( int32_t offset )const
	{
		return writeBinOperator< Vec2T< ValueT > >( *this, offset, sdw::makeArrayAccess );
	}

	template< typename ValueT >
	inline Vec2T< ValueT > Mat2x2T< ValueT >::operator[]( uint32_t offset )const
	{
		return writeBinOperator< Vec2T< ValueT > >( *this, offset, sdw::makeArrayAccess );
	}

	template< typename ValueT >
	inline ast::type::TypePtr Mat2x2T< ValueT >::makeType( ast::type::TypesCache & cache )
	{
		return sdw::makeType< Mat2x2T< ValueT > >( cache );
	}

	//*************************************************************************

	template< typename ValueT >
	Vec2T< ValueT > operator*( Vec2T< ValueT > const & lhs
		, Mat2x2T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	Vec2T< ValueT > operator*( Mat2x2T< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	Mat2x2T< ValueT > operator*( Mat2x2T< ValueT > const & lhs
		, Mat2x2T< ValueT > const & rhs )
	{
		return writeBinOperator< Mat2x2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	Mat2x2T< ValueT > operator*( ValueT const & lhs
		, Mat2x2T< ValueT > const & rhs )
	{
		return writeBinOperator< Mat2x2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	Mat2x2T< ValueT > operator*( Mat2x2T< ValueT > const & lhs
		, ValueT const & rhs )
	{
		return writeBinOperator< Mat2x2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	//*************************************************************************
}
