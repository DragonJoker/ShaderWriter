/*
See LICENSE file in root folder
*/
namespace sdw
{
	//*************************************************************************

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > >::Optional( Shader * shader
		, expr::ExprPtr expr
		, bool enabled )
		: Vec2T< ValueT >{ shader, std::move( expr ) }
		, m_enabled{ enabled }
	{
	}

	template< typename ValueT >
	Optional< Vec2T< ValueT > >::Optional( Vec2T< ValueT > const & rhs
		, bool enabled )
		: Vec2T< ValueT >{ rhs }
		, m_enabled{ enabled }
	{
	}

	template< typename ValueT >
	Optional< Vec2T< ValueT > >::Optional( Optional< Vec2T< ValueT > > const & rhs )
		: Vec2T< ValueT >{ rhs }
		, m_enabled{ rhs.m_enabled }
	{
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > & Optional< Vec2T< ValueT > >::operator=( Optional< Vec2T< ValueT > > const & rhs )
	{
		writeAssignOperator< Vec2T< ValueT > >( *this, rhs, sdw::makeAssign );
		return *this;
	}

	template< typename ValueT >
	bool Optional< Vec2T< ValueT > >::isEnabled()const
	{
		return m_enabled;
	}

	template< typename ValueT >
	Optional< Vec2T< ValueT > >::operator Optional< Value >()const
	{
		return Optional< Value >{ *this
			, makeExpr( this->getExpr() )
			, isEnabled() };
	}

	template< typename ValueT >
	template< typename IndexT >
	inline Optional< ValueT > Optional< Vec2T< ValueT > >::operator[]( IndexT const & offset )const
	{
		return writeBinOperator< ValueT >( *this, offset, sdw::makeArrayAccess );
	}

	template< typename ValueT >
	Optional< Vec2T< ValueT > > & Optional< Vec2T< ValueT > >::operator+=( Vec2T< ValueT > const & rhs )
	{
		writeAssignOperator< Vec2T< ValueT > >( *this, rhs, sdw::makeAddAssign );
		return *this;
	}

	template< typename ValueT >
	Optional< Vec2T< ValueT > > & Optional< Vec2T< ValueT > >::operator-=( Vec2T< ValueT > const & rhs )
	{
		writeAssignOperator< Vec2T< ValueT > >( *this, rhs, sdw::makeMinusAssign );
		return *this;
	}

	template< typename ValueT >
	Optional< Vec2T< ValueT > > & Optional< Vec2T< ValueT > >::operator*=( Vec2T< ValueT > const & rhs )
	{
		writeAssignOperator< Vec2T< ValueT > >( *this, rhs, sdw::makeTimesAssign );
		return *this;
	}

	template< typename ValueT >
	Optional< Vec2T< ValueT > > & Optional< Vec2T< ValueT > >::operator/=( Vec2T< ValueT > const & rhs )
	{
		writeAssignOperator< Vec2T< ValueT > >( *this, rhs, sdw::makeDivideAssign );
		return *this;
	}

	template< typename ValueT >
	Optional< Vec2T< ValueT > > & Optional< Vec2T< ValueT > >::operator+=( Optional< Vec2T< ValueT > > const & rhs )
	{
		writeAssignOperator< Vec2T< ValueT > >( *this, rhs, sdw::makeAddAssign );
		return *this;
	}

	template< typename ValueT >
	Optional< Vec2T< ValueT > > & Optional< Vec2T< ValueT > >::operator-=( Optional< Vec2T< ValueT > > const & rhs )
	{
		writeAssignOperator< Vec2T< ValueT > >( *this, rhs, sdw::makeMinusAssign );
		return *this;
	}

	template< typename ValueT >
	Optional< Vec2T< ValueT > > & Optional< Vec2T< ValueT > >::operator*=( Optional< Vec2T< ValueT > > const & rhs )
	{
		writeAssignOperator< Vec2T< ValueT > >( *this, rhs, sdw::makeTimesAssign );
		return *this;
	}

	template< typename ValueT >
	Optional< Vec2T< ValueT > > & Optional< Vec2T< ValueT > >::operator/=( Optional< Vec2T< ValueT > > const & rhs )
	{
		writeAssignOperator< Vec2T< ValueT > >( *this, rhs, sdw::makeDivideAssign );
		return *this;
	}

	template< typename ValueT >
	Optional< Vec2T< ValueT > > & Optional< Vec2T< ValueT > >::operator+=( ValueT const & rhs )
	{
		writeAssignOperator< Vec2T< ValueT > >( *this, rhs, sdw::makeAddAssign );
		return *this;
	}

	template< typename ValueT >
	Optional< Vec2T< ValueT > > & Optional< Vec2T< ValueT > >::operator-=( ValueT const & rhs )
	{
		writeAssignOperator< Vec2T< ValueT > >( *this, rhs, sdw::makeMinusAssign );
		return *this;
	}

	template< typename ValueT >
	Optional< Vec2T< ValueT > > & Optional< Vec2T< ValueT > >::operator*=( ValueT const & rhs )
	{
		writeAssignOperator< Vec2T< ValueT > >( *this, rhs, sdw::makeTimesAssign );
		return *this;
	}

	template< typename ValueT >
	Optional< Vec2T< ValueT > > & Optional< Vec2T< ValueT > >::operator/=( ValueT const & rhs )
	{
		writeAssignOperator< Vec2T< ValueT > >( *this, rhs, sdw::makeDivideAssign );
		return *this;
	}

	template< typename ValueT >
	Optional< Vec2T< ValueT > > & Optional< Vec2T< ValueT > >::operator+=( Optional< ValueT > const & rhs )
	{
		writeAssignOperator< Vec2T< ValueT > >( *this, rhs, sdw::makeAddAssign );
		return *this;
	}

	template< typename ValueT >
	Optional< Vec2T< ValueT > > & Optional< Vec2T< ValueT > >::operator-=( Optional< ValueT > const & rhs )
	{
		writeAssignOperator< Vec2T< ValueT > >( *this, rhs, sdw::makeMinusAssign );
		return *this;
	}

	template< typename ValueT >
	Optional< Vec2T< ValueT > > & Optional< Vec2T< ValueT > >::operator*=( Optional< ValueT > const & rhs )
	{
		writeAssignOperator< Vec2T< ValueT > >( *this, rhs, sdw::makeTimesAssign );
		return *this;
	}

	template< typename ValueT >
	Optional< Vec2T< ValueT > > & Optional< Vec2T< ValueT > >::operator/=( Optional< ValueT > const & rhs )
	{
		writeAssignOperator< Vec2T< ValueT > >( *this, rhs, sdw::makeDivideAssign );
		return *this;
	}

	//*************************************************************************

	template< typename ValueT >
	inline Vec2T< ValueT > operator+( ValueT const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeAdd );
	}

	template< typename ValueT >
	inline Vec2T< ValueT > operator+( Vec2T< ValueT > const & lhs
		, ValueT const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeAdd );
	}

	template< typename ValueT >
	inline Vec2T< ValueT > operator+( Vec2T< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeAdd );
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator+( Optional< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeAdd );
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator+( Optional< Vec2T< ValueT > > const & lhs
		, ValueT const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeAdd );
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator+( Optional< Vec2T< ValueT > > const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeAdd );
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator+( ValueT const & lhs
		, Optional< Vec2T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeAdd );
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator+( Vec2T< ValueT > const & lhs
		, Optional< ValueT > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeAdd );
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator+( Vec2T< ValueT > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeAdd );
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator+( Optional< ValueT > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeAdd );
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator+( Optional< Vec2T< ValueT > > const & lhs
		, Optional< ValueT > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeAdd );
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator+( Optional< Vec2T< ValueT > > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeAdd );
	}

	template< typename ValueT >
	inline Vec2T< ValueT > operator-( ValueT const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeMinus );
	}

	template< typename ValueT >
	inline Vec2T< ValueT > operator-( Vec2T< ValueT > const & lhs
		, ValueT const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeMinus );
	}

	template< typename ValueT >
	inline Vec2T< ValueT > operator-( Vec2T< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeMinus );
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator-( Optional< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeMinus );
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator-( Optional< Vec2T< ValueT > > const & lhs
		, ValueT const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeMinus );
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator-( Optional< Vec2T< ValueT > > const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeMinus );
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator-( ValueT const & lhs
		, Optional< Vec2T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeMinus );
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator-( Vec2T< ValueT > const & lhs
		, Optional< ValueT > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeMinus );
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator-( Vec2T< ValueT > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeMinus );
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator-( Optional< ValueT > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeMinus );
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator-( Optional< Vec2T< ValueT > > const & lhs
		, Optional< ValueT > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeMinus );
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator-( Optional< Vec2T< ValueT > > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeMinus );
	}

	template< typename ValueT >
	inline Vec2T< ValueT > operator*( ValueT const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	inline Vec2T< ValueT > operator*( Vec2T< ValueT > const & lhs
		, ValueT const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	inline Vec2T< ValueT > operator*( Vec2T< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator*( Optional< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator*( Optional< Vec2T< ValueT > > const & lhs
		, ValueT const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator*( Optional< Vec2T< ValueT > > const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator*( ValueT const & lhs
		, Optional< Vec2T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator*( Vec2T< ValueT > const & lhs
		, Optional< ValueT > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator*( Vec2T< ValueT > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator*( Optional< ValueT > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator*( Optional< Vec2T< ValueT > > const & lhs
		, Optional< ValueT > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator*( Optional< Vec2T< ValueT > > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	inline Vec2T< ValueT > operator/( Vec2T< ValueT > const & lhs
		, ValueT const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeDivide );
	}

	template< typename ValueT >
	inline Vec2T< ValueT > operator/( Vec2T< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeDivide );
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator/( Optional< Vec2T< ValueT > > const & lhs
		, ValueT const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeDivide );
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator/( Optional< Vec2T< ValueT > > const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeDivide );
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator/( Vec2T< ValueT > const & lhs
		, Optional< ValueT > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeDivide );
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator/( Vec2T< ValueT > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeDivide );
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator/( Optional< Vec2T< ValueT > > const & lhs
		, Optional< ValueT > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeDivide );
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator/( Optional< Vec2T< ValueT > > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeDivide );
	}

	//*************************************************************************
}
