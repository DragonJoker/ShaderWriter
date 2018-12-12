/*
See LICENSE file in root folder
*/
namespace sdw
{
	//*************************************************************************

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > >::Optional( Shader * shader
		, expr::ExprPtr expr
		, bool enabled )
		: Vec4T< ValueT >{ shader, std::move( expr ) }
		, m_enabled{ enabled }
	{
	}

	template< typename ValueT >
	Optional< Vec4T< ValueT > >::Optional( Vec4T< ValueT > const & rhs
		, bool enabled )
		: Vec4T< ValueT >{ rhs }
		, m_enabled{ enabled }
	{
	}

	template< typename ValueT >
	Optional< Vec4T< ValueT > >::Optional( Optional< Vec4T< ValueT > > const & rhs )
		: Vec4T< ValueT >{ rhs }
		, m_enabled{ rhs.m_enabled }
	{
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > & Optional< Vec4T< ValueT > >::operator=( Optional< Vec4T< ValueT > > const & rhs )
	{
		writeAssignOperator< Vec4T< ValueT > >( *this, rhs, sdw::makeAssign );
		return *this;
	}

	template< typename ValueT >
	bool Optional< Vec4T< ValueT > >::isEnabled()const
	{
		return m_enabled;
	}

	template< typename ValueT >
	Optional< Vec4T< ValueT > >::operator Optional< Value >()const
	{
		return Optional< Value >{ *this
			, makeExpr( this->getExpr() )
			, isEnabled() };
	}

	template< typename ValueT >
	template< typename IndexT >
	inline Optional< ValueT > Optional< Vec4T< ValueT > >::operator[]( IndexT const & offset )const
	{
		return writeBinOperator< ValueT >( *this, offset, sdw::makeArrayAccess );
	}

	template< typename ValueT >
	Optional< Vec4T< ValueT > > & Optional< Vec4T< ValueT > >::operator+=( Vec4T< ValueT > const & rhs )
	{
		writeAssignOperator< Vec4T< ValueT > >( *this, rhs, sdw::makeAddAssign );
		return *this;
	}

	template< typename ValueT >
	Optional< Vec4T< ValueT > > & Optional< Vec4T< ValueT > >::operator-=( Vec4T< ValueT > const & rhs )
	{
		writeAssignOperator< Vec4T< ValueT > >( *this, rhs, sdw::makeMinusAssign );
		return *this;
	}

	template< typename ValueT >
	Optional< Vec4T< ValueT > > & Optional< Vec4T< ValueT > >::operator*=( Vec4T< ValueT > const & rhs )
	{
		writeAssignOperator< Vec4T< ValueT > >( *this, rhs, sdw::makeTimesAssign );
		return *this;
	}

	template< typename ValueT >
	Optional< Vec4T< ValueT > > & Optional< Vec4T< ValueT > >::operator/=( Vec4T< ValueT > const & rhs )
	{
		writeAssignOperator< Vec4T< ValueT > >( *this, rhs, sdw::makeDivideAssign );
		return *this;
	}

	template< typename ValueT >
	Optional< Vec4T< ValueT > > & Optional< Vec4T< ValueT > >::operator+=( Optional< Vec4T< ValueT > > const & rhs )
	{
		writeAssignOperator< Vec4T< ValueT > >( *this, rhs, sdw::makeAddAssign );
		return *this;
	}

	template< typename ValueT >
	Optional< Vec4T< ValueT > > & Optional< Vec4T< ValueT > >::operator-=( Optional< Vec4T< ValueT > > const & rhs )
	{
		writeAssignOperator< Vec4T< ValueT > >( *this, rhs, sdw::makeMinusAssign );
		return *this;
	}

	template< typename ValueT >
	Optional< Vec4T< ValueT > > & Optional< Vec4T< ValueT > >::operator*=( Optional< Vec4T< ValueT > > const & rhs )
	{
		writeAssignOperator< Vec4T< ValueT > >( *this, rhs, sdw::makeTimesAssign );
		return *this;
	}

	template< typename ValueT >
	Optional< Vec4T< ValueT > > & Optional< Vec4T< ValueT > >::operator/=( Optional< Vec4T< ValueT > > const & rhs )
	{
		writeAssignOperator< Vec4T< ValueT > >( *this, rhs, sdw::makeDivideAssign );
		return *this;
	}

	template< typename ValueT >
	Optional< Vec4T< ValueT > > & Optional< Vec4T< ValueT > >::operator+=( ValueT const & rhs )
	{
		writeAssignOperator< Vec4T< ValueT > >( *this, rhs, sdw::makeAddAssign );
		return *this;
	}

	template< typename ValueT >
	Optional< Vec4T< ValueT > > & Optional< Vec4T< ValueT > >::operator-=( ValueT const & rhs )
	{
		writeAssignOperator< Vec4T< ValueT > >( *this, rhs, sdw::makeMinusAssign );
		return *this;
	}

	template< typename ValueT >
	Optional< Vec4T< ValueT > > & Optional< Vec4T< ValueT > >::operator*=( ValueT const & rhs )
	{
		writeAssignOperator< Vec4T< ValueT > >( *this, rhs, sdw::makeTimesAssign );
		return *this;
	}

	template< typename ValueT >
	Optional< Vec4T< ValueT > > & Optional< Vec4T< ValueT > >::operator/=( ValueT const & rhs )
	{
		writeAssignOperator< Vec4T< ValueT > >( *this, rhs, sdw::makeDivideAssign );
		return *this;
	}

	template< typename ValueT >
	Optional< Vec4T< ValueT > > & Optional< Vec4T< ValueT > >::operator+=( Optional< ValueT > const & rhs )
	{
		writeAssignOperator< Vec4T< ValueT > >( *this, rhs, sdw::makeAddAssign );
		return *this;
	}

	template< typename ValueT >
	Optional< Vec4T< ValueT > > & Optional< Vec4T< ValueT > >::operator-=( Optional< ValueT > const & rhs )
	{
		writeAssignOperator< Vec4T< ValueT > >( *this, rhs, sdw::makeMinusAssign );
		return *this;
	}

	template< typename ValueT >
	Optional< Vec4T< ValueT > > & Optional< Vec4T< ValueT > >::operator*=( Optional< ValueT > const & rhs )
	{
		writeAssignOperator< Vec4T< ValueT > >( *this, rhs, sdw::makeTimesAssign );
		return *this;
	}

	template< typename ValueT >
	Optional< Vec4T< ValueT > > & Optional< Vec4T< ValueT > >::operator/=( Optional< ValueT > const & rhs )
	{
		writeAssignOperator< Vec4T< ValueT > >( *this, rhs, sdw::makeDivideAssign );
		return *this;
	}

	//*************************************************************************

	template< typename ValueT >
	inline Vec4T< ValueT > operator+( ValueT const & lhs
		, Vec4T< ValueT > const & rhs )
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
	inline Vec4T< ValueT > operator*( Vec4T< ValueT > const & lhs
		, ValueT const & rhs )
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
	inline Vec4T< ValueT > operator/( Vec4T< ValueT > const & lhs
		, Vec4T< ValueT > const & rhs )
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
	inline Optional< Vec4T< ValueT > > operator/( Optional< Vec4T< ValueT > > const & lhs
		, Vec4T< ValueT > const & rhs )
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
	inline Optional< Vec4T< ValueT > > operator/( Vec4T< ValueT > const & lhs
		, Optional< Vec4T< ValueT > > const & rhs )
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
	inline Optional< Vec4T< ValueT > > operator/( Optional< Vec4T< ValueT > > const & lhs
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

	//*************************************************************************
}
