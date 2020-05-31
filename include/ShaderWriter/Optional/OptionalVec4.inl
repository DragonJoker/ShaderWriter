/*
See LICENSE file in root folder
*/
namespace sdw
{
	//*********************************************************************************************

	template< typename ValueT >
	inline Vec4T< ValueT > & Vec4T< ValueT >::operator=( Optional< Vec4T< ValueT > > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			if ( this->getContainer() )
			{
				writeAssignOperator< Vec4T< ValueT > >( *this, rhs, sdw::makeAssign );
			}
			else
			{
				Value::operator=( rhs );
			}
		}

		return *this;
	}

	//*********************************************************************************************

	template< typename ValueT >
	inline Vec4T< ValueT > operator+( CppTypeT< ValueT > const & lhs
		, Vec4T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeAdd );
	}

	template< typename ValueT >
	inline Vec4T< ValueT > operator+( ValueT const & lhs
		, Vec4T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeAdd );
	}

	template< typename ValueT >
	inline Vec4T< ValueT > operator+( Vec4T< ValueT > const & lhs
		, CppTypeT< ValueT > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeAdd );
	}

	template< typename ValueT >
	inline Vec4T< ValueT > operator+( Vec4T< ValueT > const & lhs
		, ValueT const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeAdd );
	}

	template< typename ValueT >
	inline Vec4T< ValueT > operator+( Vec4T< ValueT > const & lhs
		, Vec4T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeAdd );
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator+( Optional< ValueT > const & lhs
		, Vec4T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeAdd );
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator+( Optional< Vec4T< ValueT > > const & lhs
		, CppTypeT< ValueT > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeAdd );
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator+( Optional< Vec4T< ValueT > > const & lhs
		, ValueT const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeAdd );
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator+( Optional< Vec4T< ValueT > > const & lhs
		, Vec4T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeAdd );
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator+( CppTypeT< ValueT > const & lhs
		, Optional< Vec4T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeAdd );
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator+( ValueT const & lhs
		, Optional< Vec4T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeAdd );
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator+( Vec4T< ValueT > const & lhs
		, Optional< ValueT > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeAdd );
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator+( Vec4T< ValueT > const & lhs
		, Optional< Vec4T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeAdd );
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator+( Optional< ValueT > const & lhs
		, Optional< Vec4T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeAdd );
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator+( Optional< Vec4T< ValueT > > const & lhs
		, Optional< ValueT > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeAdd );
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator+( Optional< Vec4T< ValueT > > const & lhs
		, Optional< Vec4T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeAdd );
	}

	template< typename ValueT >
	inline Vec4T< ValueT > operator-( CppTypeT< ValueT > const & lhs
		, Vec4T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeMinus );
	}

	template< typename ValueT >
	inline Vec4T< ValueT > operator-( ValueT const & lhs
		, Vec4T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeMinus );
	}

	template< typename ValueT >
	inline Vec4T< ValueT > operator-( Vec4T< ValueT > const & lhs
		, ValueT const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeMinus );
	}

	template< typename ValueT >
	inline Vec4T< ValueT > operator-( Vec4T< ValueT > const & lhs
		, CppTypeT< ValueT > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeMinus );
	}

	template< typename ValueT >
	inline Vec4T< ValueT > operator-( Vec4T< ValueT > const & lhs
		, Vec4T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeMinus );
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator-( Optional< ValueT > const & lhs
		, Vec4T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeMinus );
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator-( Optional< Vec4T< ValueT > > const & lhs
		, CppTypeT< ValueT > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeMinus );
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator-( Optional< Vec4T< ValueT > > const & lhs
		, ValueT const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeMinus );
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator-( Optional< Vec4T< ValueT > > const & lhs
		, Vec4T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeMinus );
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator-( CppTypeT< ValueT > const & lhs
		, Optional< Vec4T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeMinus );
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator-( ValueT const & lhs
		, Optional< Vec4T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeMinus );
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator-( Vec4T< ValueT > const & lhs
		, Optional< ValueT > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeMinus );
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator-( Vec4T< ValueT > const & lhs
		, Optional< Vec4T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeMinus );
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator-( Optional< ValueT > const & lhs
		, Optional< Vec4T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeMinus );
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator-( Optional< Vec4T< ValueT > > const & lhs
		, Optional< ValueT > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeMinus );
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator-( Optional< Vec4T< ValueT > > const & lhs
		, Optional< Vec4T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeMinus );
	}

	template< typename ValueT >
	inline Vec4T< ValueT > operator*( ValueT const & lhs
		, Vec4T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	inline Vec4T< ValueT > operator*( CppTypeT< ValueT > const & lhs
		, Vec4T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	inline Vec4T< ValueT > operator*( Vec4T< ValueT > const & lhs
		, ValueT const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	inline Vec4T< ValueT > operator*( Vec4T< ValueT > const & lhs
		, CppTypeT< ValueT > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	inline Vec4T< ValueT > operator*( Vec4T< ValueT > const & lhs
		, Vec4T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator*( Optional< ValueT > const & lhs
		, Vec4T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator*( Optional< Vec4T< ValueT > > const & lhs
		, CppTypeT< ValueT > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator*( Optional< Vec4T< ValueT > > const & lhs
		, ValueT const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator*( Optional< Vec4T< ValueT > > const & lhs
		, Vec4T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator*( CppTypeT< ValueT > const & lhs
		, Optional< Vec4T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator*( ValueT const & lhs
		, Optional< Vec4T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator*( Vec4T< ValueT > const & lhs
		, Optional< ValueT > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator*( Vec4T< ValueT > const & lhs
		, Optional< Vec4T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator*( Optional< ValueT > const & lhs
		, Optional< Vec4T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator*( Optional< Vec4T< ValueT > > const & lhs
		, Optional< ValueT > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator*( Optional< Vec4T< ValueT > > const & lhs
		, Optional< Vec4T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator/( Optional< Vec4T< ValueT > > const & lhs
		, CppTypeT< ValueT > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeDivide );
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator/( Optional< Vec4T< ValueT > > const & lhs
		, ValueT const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeDivide );
	}

	template< typename ValueT >
	inline Vec4T< ValueT > operator/( Vec4T< ValueT > const & lhs
		, CppTypeT< ValueT > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeDivide );
	}

	template< typename ValueT >
	inline Vec4T< ValueT > operator/( Vec4T< ValueT > const & lhs
		, ValueT const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeDivide );
	}

	template< typename ValueT >
	inline Vec4T< ValueT > operator/( Vec4T< ValueT > const & lhs
		, Vec4T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeDivide );
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator/( Optional< Vec4T< ValueT > > const & lhs
		, Vec4T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeDivide );
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator/( Vec4T< ValueT > const & lhs
		, Optional< ValueT > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeDivide );
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator/( Vec4T< ValueT > const & lhs
		, Optional< Vec4T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeDivide );
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator/( Optional< Vec4T< ValueT > > const & lhs
		, Optional< ValueT > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeDivide );
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator/( Optional< Vec4T< ValueT > > const & lhs
		, Optional< Vec4T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeDivide );
	}

	//*************************************************************************
}
