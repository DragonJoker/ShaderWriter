/*
See LICENSE file in root folder
*/
namespace sdw
{
	//*********************************************************************************************

	template< typename ValueT >
	inline Vec3T< ValueT >::Vec3T( ShaderWriter & writer
		, expr::ExprPtr expr
		, bool enabled )
		: Value{ writer, std::move( expr ), enabled }
	{
	}

	template< typename ValueT >
	template< typename IndexT >
	inline ValueT Vec3T< ValueT >::operator[]( IndexT const & offset )const
	{
		return writeBinOperator< ValueT >( *this, offset, sdw::makeArrayAccess );
	}

	template< typename ValueT >
	inline ValueT Vec3T< ValueT >::operator[]( int32_t offset )const
	{
		return writeBinOperator< ValueT >( *this, offset, sdw::makeArrayAccess );
	}

	template< typename ValueT >
	inline ValueT Vec3T< ValueT >::operator[]( uint32_t offset )const
	{
		return writeBinOperator< ValueT >( *this, offset, sdw::makeArrayAccess );
	}

	template< typename ValueT >
	Vec3T< ValueT > & Vec3T< ValueT >::operator+=( Vec3T< ValueT > const & rhs )
	{
		writeAssignOperator< Vec3T< ValueT > >( *this, rhs, sdw::makeAddAssign );
		return *this;
	}

	template< typename ValueT >
	Vec3T< ValueT > & Vec3T< ValueT >::operator-=( Vec3T< ValueT > const & rhs )
	{
		writeAssignOperator< Vec3T< ValueT > >( *this, rhs, sdw::makeMinusAssign );
		return *this;
	}

	template< typename ValueT >
	Vec3T< ValueT > & Vec3T< ValueT >::operator*=( Vec3T< ValueT > const & rhs )
	{
		writeAssignOperator< Vec3T< ValueT > >( *this, rhs, sdw::makeTimesAssign );
		return *this;
	}

	template< typename ValueT >
	Vec3T< ValueT > & Vec3T< ValueT >::operator/=( Vec3T< ValueT > const & rhs )
	{
		writeAssignOperator< Vec3T< ValueT > >( *this, rhs, sdw::makeDivideAssign );
		return *this;
	}

	template< typename ValueT >
	Vec3T< ValueT > & Vec3T< ValueT >::operator+=( ValueT const & rhs )
	{
		writeAssignOperator< Vec3T< ValueT > >( *this, rhs, sdw::makeAddAssign );
		return *this;
	}

	template< typename ValueT >
	Vec3T< ValueT > & Vec3T< ValueT >::operator-=( ValueT const & rhs )
	{
		writeAssignOperator< Vec3T< ValueT > >( *this, rhs, sdw::makeMinusAssign );
		return *this;
	}

	template< typename ValueT >
	Vec3T< ValueT > & Vec3T< ValueT >::operator*=( ValueT const & rhs )
	{
		writeAssignOperator< Vec3T< ValueT > >( *this, rhs, sdw::makeTimesAssign );
		return *this;
	}

	template< typename ValueT >
	Vec3T< ValueT > & Vec3T< ValueT >::operator/=( ValueT const & rhs )
	{
		writeAssignOperator< Vec3T< ValueT > >( *this, rhs, sdw::makeDivideAssign );
		return *this;
	}

	template< typename ValueT >
	Vec3T< ValueT > Vec3T< ValueT >::operator-()const
	{
		return writeUnOperator< Vec3T< ValueT > >( *this, sdw::makeUnMinus );
	}

	template< typename ValueT >
	Vec3T< ValueT > Vec3T< ValueT >::operator+()const
	{
		return writeUnOperator< Vec3T< ValueT > >( *this, sdw::makeUnPlus );
	}

	template< typename ValueT >
	inline ast::type::TypePtr Vec3T< ValueT >::makeType( ast::type::TypesCache & cache )
	{
		return sdw::makeType< Vec3T< ValueT > >( cache );
	}

	//*********************************************************************************************

	template< typename ValueT >
	Vec3T< Boolean > operator==( Vec3T< ValueT > const & lhs, Vec3T< ValueT > const & rhs )
	{
		return writeComparator< Vec3T< Boolean > >( lhs, rhs, sdw::makeEqual );
	}

	template< typename ValueT >
	Vec3T< Boolean > operator!=( Vec3T< ValueT > const & lhs, Vec3T< ValueT > const & rhs )
	{
		return writeComparator< Vec3T< Boolean > >( lhs, rhs, sdw::makeNEqual );
	}

	template< typename ValueT >
	Vec3T< Boolean > operator<( Vec3T< ValueT > const & lhs, Vec3T< ValueT > const & rhs )
	{
		return writeComparator< Vec3T< Boolean > >( lhs, rhs, sdw::makeLess );
	}

	template< typename ValueT >
	Vec3T< Boolean > operator<=( Vec3T< ValueT > const & lhs, Vec3T< ValueT > const & rhs )
	{
		return writeComparator< Vec3T< Boolean > >( lhs, rhs, sdw::makeLEqual );
	}

	template< typename ValueT >
	Vec3T< Boolean > operator>( Vec3T< ValueT > const & lhs, Vec3T< ValueT > const & rhs )
	{
		return writeComparator< Vec3T< Boolean > >( lhs, rhs, sdw::makeGreater );
	}

	template< typename ValueT >
	Vec3T< Boolean > operator>=( Vec3T< ValueT > const & lhs, Vec3T< ValueT > const & rhs )
	{
		return writeComparator< Vec3T< Boolean > >( lhs, rhs, sdw::makeGEqual );
	}

	//*********************************************************************************************

	template< typename ValueT, VecCompatibleT< ValueT > LhsT >
	inline Vec3T< ValueT > operator+( LhsT const & lhs
		, Vec3T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec3T< ValueT > >( lhs, rhs, sdw::makeAdd );
	}

	template< typename ValueT, VecCompatibleT< ValueT > RhsT >
	inline Vec3T< ValueT > operator+( Vec3T< ValueT > const & lhs
		, RhsT const & rhs )
	{
		return writeBinOperator< Vec3T< ValueT > >( lhs, rhs, sdw::makeAdd );
	}

	template< typename ValueT >
	inline Vec3T< ValueT > operator+( Vec3T< ValueT > const & lhs
		, Vec3T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec3T< ValueT > >( lhs, rhs, sdw::makeAdd );
	}

	template< typename ValueT, VecCompatibleT< ValueT > LhsT >
	inline Vec3T< ValueT > operator-( LhsT const & lhs
		, Vec3T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec3T< ValueT > >( lhs, rhs, sdw::makeMinus );
	}

	template< typename ValueT, VecCompatibleT< ValueT > RhsT >
	inline Vec3T< ValueT > operator-( Vec3T< ValueT > const & lhs
		, RhsT const & rhs )
	{
		return writeBinOperator< Vec3T< ValueT > >( lhs, rhs, sdw::makeMinus );
	}

	template< typename ValueT >
	inline Vec3T< ValueT > operator-( Vec3T< ValueT > const & lhs
		, Vec3T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec3T< ValueT > >( lhs, rhs, sdw::makeMinus );
	}

	template< typename ValueT, VecCompatibleT< ValueT > LhsT >
	inline Vec3T< ValueT > operator*( LhsT const & lhs
		, Vec3T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec3T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT, VecCompatibleT< ValueT > RhsT >
	inline Vec3T< ValueT > operator*( Vec3T< ValueT > const & lhs
		, RhsT const & rhs )
	{
		return writeBinOperator< Vec3T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	inline Vec3T< ValueT > operator*( Vec3T< ValueT > const & lhs
		, Vec3T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec3T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT, VecCompatibleT< ValueT > RhsT >
	inline Vec3T< ValueT > operator/( Vec3T< ValueT > const & lhs
		, RhsT const & rhs )
	{
		return writeBinOperator< Vec3T< ValueT > >( lhs, rhs, sdw::makeDivide );
	}

	template< typename ValueT >
	inline Vec3T< ValueT > operator/( Vec3T< ValueT > const & lhs
		, Vec3T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec3T< ValueT > >( lhs, rhs, sdw::makeDivide );
	}

	//*********************************************************************************************
}
