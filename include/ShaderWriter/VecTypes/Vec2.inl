/*
See LICENSE file in root folder
*/
namespace sdw
{
	//*********************************************************************************************

	template< typename ValueT >
	Vec2T< ValueT >::Vec2T( ShaderWriter & writer
		, expr::ExprPtr expr
		, bool enabled )
		: Value{ writer, std::move( expr ), enabled }
	{
	}

	template< typename ValueT >
	template< typename IndexT >
	ReturnWrapperT< ValueT > Vec2T< ValueT >::operator[]( IndexT const & offset )const
	{
		return writeBinOperator< ValueT >( *this, offset, sdw::makeArrayAccess );
	}

	template< typename ValueT >
	ReturnWrapperT< ValueT > Vec2T< ValueT >::operator[]( int32_t offset )const
	{
		return writeBinOperator< ValueT >( *this, offset, sdw::makeArrayAccess );
	}

	template< typename ValueT >
	ReturnWrapperT< ValueT > Vec2T< ValueT >::operator[]( uint32_t offset )const
	{
		return writeBinOperator< ValueT >( *this, offset, sdw::makeArrayAccess );
	}

	template< typename ValueT >
	ReturnWrapperT< Vec2T< ValueT > > Vec2T< ValueT >::operator+=( Vec2T< ValueT > const & rhs )
	{
		return writeAssignOperator< Vec2T< ValueT > >( *this, rhs, sdw::makeAddAssign );
	}

	template< typename ValueT >
	ReturnWrapperT< Vec2T< ValueT > > Vec2T< ValueT >::operator-=( Vec2T< ValueT > const & rhs )
	{
		return writeAssignOperator< Vec2T< ValueT > >( *this, rhs, sdw::makeMinusAssign );
	}

	template< typename ValueT >
	ReturnWrapperT< Vec2T< ValueT > > Vec2T< ValueT >::operator*=( Vec2T< ValueT > const & rhs )
	{
		return writeAssignOperator< Vec2T< ValueT > >( *this, rhs, sdw::makeTimesAssign );
	}

	template< typename ValueT >
	ReturnWrapperT< Vec2T< ValueT > > Vec2T< ValueT >::operator/=( Vec2T< ValueT > const & rhs )
	{
		return writeAssignOperator< Vec2T< ValueT > >( *this, rhs, sdw::makeDivideAssign );
	}

	template< typename ValueT >
	ReturnWrapperT< Vec2T< ValueT > > Vec2T< ValueT >::operator+=( ValueT const & rhs )
	{
		return writeAssignOperator< Vec2T< ValueT > >( *this, rhs, sdw::makeAddAssign );
	}

	template< typename ValueT >
	ReturnWrapperT< Vec2T< ValueT > > Vec2T< ValueT >::operator-=( ValueT const & rhs )
	{
		return writeAssignOperator< Vec2T< ValueT > >( *this, rhs, sdw::makeMinusAssign );
	}

	template< typename ValueT >
	ReturnWrapperT< Vec2T< ValueT > > Vec2T< ValueT >::operator*=( ValueT const & rhs )
	{
		return writeAssignOperator< Vec2T< ValueT > >( *this, rhs, sdw::makeTimesAssign );
	}

	template< typename ValueT >
	ReturnWrapperT< Vec2T< ValueT > > Vec2T< ValueT >::operator/=( ValueT const & rhs )
	{
		return writeAssignOperator< Vec2T< ValueT > >( *this, rhs, sdw::makeDivideAssign );
	}
	
	template< typename ValueT >
	ReturnWrapperT< Vec2T< ValueT > > Vec2T< ValueT >::operator-()const
	{
		return writeUnOperator< Vec2T< ValueT > >( *this, sdw::makeUnMinus );
	}

	template< typename ValueT >
	ReturnWrapperT< Vec2T< ValueT > > Vec2T< ValueT >::operator+()const
	{
		return writeUnOperator< Vec2T< ValueT > >( *this, sdw::makeUnPlus );
	}

	template< typename ValueT >
	ast::type::TypePtr Vec2T< ValueT >::makeType( ast::type::TypesCache & cache )
	{
		return sdw::makeType< Vec2T< ValueT > >( cache );
	}

	//*********************************************************************************************

	template< typename ValueT >
	ReturnWrapperT< Vec2T< Boolean > > operator==( Vec2T< ValueT > const & lhs, Vec2T< ValueT > const & rhs )
	{
		return writeComparator< Vec2T< Boolean > >( lhs, rhs, sdw::makeEqual );
	}

	template< typename ValueT >
	ReturnWrapperT< Vec2T< Boolean > > operator!=( Vec2T< ValueT > const & lhs, Vec2T< ValueT > const & rhs )
	{
		return writeComparator< Vec2T< Boolean > >( lhs, rhs, sdw::makeNEqual );
	}

	template< typename ValueT >
	ReturnWrapperT< Vec2T< Boolean > > operator<( Vec2T< ValueT > const & lhs, Vec2T< ValueT > const & rhs )
	{
		return writeComparator< Vec2T< Boolean > >( lhs, rhs, sdw::makeLess );
	}

	template< typename ValueT >
	ReturnWrapperT< Vec2T< Boolean > > operator<=( Vec2T< ValueT > const & lhs, Vec2T< ValueT > const & rhs )
	{
		return writeComparator< Vec2T< Boolean > >( lhs, rhs, sdw::makeLEqual );
	}

	template< typename ValueT >
	ReturnWrapperT< Vec2T< Boolean > > operator>( Vec2T< ValueT > const & lhs, Vec2T< ValueT > const & rhs )
	{
		return writeComparator< Vec2T< Boolean > >( lhs, rhs, sdw::makeGreater );
	}

	template< typename ValueT >
	ReturnWrapperT< Vec2T< Boolean > > operator>=( Vec2T< ValueT > const & lhs, Vec2T< ValueT > const & rhs )
	{
		return writeComparator< Vec2T< Boolean > >( lhs, rhs, sdw::makeGEqual );
	}

	//*********************************************************************************************

	template< typename ValueT, VecCompatibleT< ValueT > LhsT >
	ReturnWrapperT< Vec2T< ValueT > > operator+( LhsT const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeAdd );
	}

	template< typename ValueT, VecCompatibleT< ValueT > RhsT >
	ReturnWrapperT< Vec2T< ValueT > > operator+( Vec2T< ValueT > const & lhs
		, RhsT const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeAdd );
	}

	template< typename ValueT >
	ReturnWrapperT< Vec2T< ValueT > > operator+( Vec2T< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeAdd );
	}

	template< typename ValueT, VecCompatibleT< ValueT > LhsT >
	ReturnWrapperT< Vec2T< ValueT > > operator-( LhsT const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeMinus );
	}

	template< typename ValueT, VecCompatibleT< ValueT > RhsT >
	ReturnWrapperT< Vec2T< ValueT > > operator-( Vec2T< ValueT > const & lhs
		, RhsT const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeMinus );
	}

	template< typename ValueT >
	ReturnWrapperT< Vec2T< ValueT > > operator-( Vec2T< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeMinus );
	}

	template< typename ValueT, VecCompatibleT< ValueT > LhsT >
	ReturnWrapperT< Vec2T< ValueT > > operator*( LhsT const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT, VecCompatibleT< ValueT > RhsT >
	ReturnWrapperT< Vec2T< ValueT > > operator*( Vec2T< ValueT > const & lhs
		, RhsT const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	ReturnWrapperT< Vec2T< ValueT > > operator*( Vec2T< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT, VecCompatibleT< ValueT > RhsT >
	ReturnWrapperT< Vec2T< ValueT > > operator/( Vec2T< ValueT > const & lhs
		, RhsT const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeDivide );
	}

	template< typename ValueT >
	ReturnWrapperT< Vec2T< ValueT > > operator/( Vec2T< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeDivide );
	}

	//*********************************************************************************************
}
