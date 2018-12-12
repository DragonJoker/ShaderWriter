/*
See LICENSE file in root folder
*/
#include "MaybeOptionalVec4.hpp"

namespace sdw
{
	//*************************************************************************

	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > >::MaybeOptional( Shader * shader
		, expr::ExprPtr expr )
		: Vec4T< ValueT >{ shader, std::move( expr ) }
		, m_optional{ false }
		, m_enabled{ true }
	{
	}

	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > >::MaybeOptional( Shader * shader
		, expr::ExprPtr expr
		, bool enabled )
		: Vec4T< ValueT >{ shader, std::move( expr ) }
		, m_optional{ true }
		, m_enabled{ enabled }
	{
	}

	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > >::MaybeOptional( Vec4T< ValueT > const & rhs )
		: Vec4T< ValueT >{ rhs }
		, m_optional{ false }
		, m_enabled{ true }
	{
	}

	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > >::MaybeOptional( Optional< Vec4T< ValueT > > const & rhs )
		: Vec4T< ValueT >{ rhs }
		, m_optional{ true }
		, m_enabled{ rhs.isEnabled() }
	{
	}

	template< typename ValueT >
	MaybeOptional< Vec4T< ValueT > >::MaybeOptional( MaybeOptional< Vec4T< ValueT > > const & rhs )
		: Vec4T< ValueT >{ rhs }
		, m_optional{ rhs.isOptional() }
		, m_enabled{ rhs.isEnabled() }
	{
	}

	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > > & MaybeOptional< Vec4T< ValueT > >::operator=( MaybeOptional< Vec4T< ValueT > > const & rhs )
	{
		writeAssignOperator< Vec4T< ValueT > >( *this, rhs, sdw::makeAssign );
		return *this;
	}

	template< typename ValueT >
	template< typename IndexT >
	inline MaybeOptional< ValueT > MaybeOptional< Vec4T< ValueT > >::operator[]( IndexT const & offset )const
	{
		return writeBinOperator< ValueT >( *this, offset, sdw::makeArrayAccess );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > >::operator Vec4T< ValueT >()const
	{
		return *this;
	}

	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > >::operator Optional< Vec4T< ValueT > >()const
	{
		return Optional< Vec4T< ValueT > >{ *this
			, m_enabled };
	}

	template< typename ValueT >
	inline bool MaybeOptional< Vec4T< ValueT > >::isOptional()const
	{
		return m_optional;
	}

	template< typename ValueT >
	inline bool MaybeOptional< Vec4T< ValueT > >::isEnabled()const
	{
		return m_enabled;
	}

	template< typename ValueT >
	MaybeOptional< Vec4T< ValueT > > & MaybeOptional< Vec4T< ValueT > >::operator+=( Vec4T< ValueT > const & rhs )
	{
		writeAssignOperator< Vec4T< ValueT > >( *this, rhs, sdw::makeAddAssign );
		return *this;
	}

	template< typename ValueT >
	MaybeOptional< Vec4T< ValueT > > & MaybeOptional< Vec4T< ValueT > >::operator-=( Vec4T< ValueT > const & rhs )
	{
		writeAssignOperator< Vec4T< ValueT > >( *this, rhs, sdw::makeMinusAssign );
		return *this;
	}

	template< typename ValueT >
	MaybeOptional< Vec4T< ValueT > > & MaybeOptional< Vec4T< ValueT > >::operator*=( Vec4T< ValueT > const & rhs )
	{
		writeAssignOperator< Vec4T< ValueT > >( *this, rhs, sdw::makeTimesAssign );
		return *this;
	}

	template< typename ValueT >
	MaybeOptional< Vec4T< ValueT > > & MaybeOptional< Vec4T< ValueT > >::operator/=( Vec4T< ValueT > const & rhs )
	{
		writeAssignOperator< Vec4T< ValueT > >( *this, rhs, sdw::makeDivideAssign );
		return *this;
	}

	template< typename ValueT >
	MaybeOptional< Vec4T< ValueT > > & MaybeOptional< Vec4T< ValueT > >::operator+=( MaybeOptional< Vec4T< ValueT > > const & rhs )
	{
		writeAssignOperator< Vec4T< ValueT > >( *this, rhs, sdw::makeAddAssign );
		return *this;
	}

	template< typename ValueT >
	MaybeOptional< Vec4T< ValueT > > & MaybeOptional< Vec4T< ValueT > >::operator-=( MaybeOptional< Vec4T< ValueT > > const & rhs )
	{
		writeAssignOperator< Vec4T< ValueT > >( *this, rhs, sdw::makeMinusAssign );
		return *this;
	}

	template< typename ValueT >
	MaybeOptional< Vec4T< ValueT > > & MaybeOptional< Vec4T< ValueT > >::operator*=( MaybeOptional< Vec4T< ValueT > > const & rhs )
	{
		writeAssignOperator< Vec4T< ValueT > >( *this, rhs, sdw::makeTimesAssign );
		return *this;
	}

	template< typename ValueT >
	MaybeOptional< Vec4T< ValueT > > & MaybeOptional< Vec4T< ValueT > >::operator/=( MaybeOptional< Vec4T< ValueT > > const & rhs )
	{
		writeAssignOperator< Vec4T< ValueT > >( *this, rhs, sdw::makeDivideAssign );
		return *this;
	}

	template< typename ValueT >
	MaybeOptional< Vec4T< ValueT > > & MaybeOptional< Vec4T< ValueT > >::operator+=( ValueT const & rhs )
	{
		writeAssignOperator< Vec4T< ValueT > >( *this, rhs, sdw::makeAddAssign );
		return *this;
	}

	template< typename ValueT >
	MaybeOptional< Vec4T< ValueT > > & MaybeOptional< Vec4T< ValueT > >::operator-=( ValueT const & rhs )
	{
		writeAssignOperator< Vec4T< ValueT > >( *this, rhs, sdw::makeMinusAssign );
		return *this;
	}

	template< typename ValueT >
	MaybeOptional< Vec4T< ValueT > > & MaybeOptional< Vec4T< ValueT > >::operator*=( ValueT const & rhs )
	{
		writeAssignOperator< Vec4T< ValueT > >( *this, rhs, sdw::makeTimesAssign );
		return *this;
	}

	template< typename ValueT >
	MaybeOptional< Vec4T< ValueT > > & MaybeOptional< Vec4T< ValueT > >::operator/=( ValueT const & rhs )
	{
		writeAssignOperator< Vec4T< ValueT > >( *this, rhs, sdw::makeDivideAssign );
		return *this;
	}

	template< typename ValueT >
	MaybeOptional< Vec4T< ValueT > > & MaybeOptional< Vec4T< ValueT > >::operator+=( MaybeOptional< ValueT > const & rhs )
	{
		writeAssignOperator< Vec4T< ValueT > >( *this, rhs, sdw::makeAddAssign );
		return *this;
	}

	template< typename ValueT >
	MaybeOptional< Vec4T< ValueT > > & MaybeOptional< Vec4T< ValueT > >::operator-=( MaybeOptional< ValueT > const & rhs )
	{
		writeAssignOperator< Vec4T< ValueT > >( *this, rhs, sdw::makeMinusAssign );
		return *this;
	}

	template< typename ValueT >
	MaybeOptional< Vec4T< ValueT > > & MaybeOptional< Vec4T< ValueT > >::operator*=( MaybeOptional< ValueT > const & rhs )
	{
		writeAssignOperator< Vec4T< ValueT > >( *this, rhs, sdw::makeTimesAssign );
		return *this;
	}

	template< typename ValueT >
	MaybeOptional< Vec4T< ValueT > > & MaybeOptional< Vec4T< ValueT > >::operator/=( MaybeOptional< ValueT > const & rhs )
	{
		writeAssignOperator< Vec4T< ValueT > >( *this, rhs, sdw::makeDivideAssign );
		return *this;
	}

	//*************************************************************************

	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > > operator+( MaybeOptional< ValueT > const & lhs
		, Vec4T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeAdd );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > > operator+( MaybeOptional< Vec4T< ValueT > > const & lhs
		, ValueT const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeAdd );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > > operator+( MaybeOptional< Vec4T< ValueT > > const & lhs
		, Vec4T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeAdd );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > > operator+( ValueT const & lhs
		, MaybeOptional< Vec4T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeAdd );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > > operator+( Vec4T< ValueT > const & lhs
		, MaybeOptional< ValueT > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeAdd );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > > operator+( Vec4T< ValueT > const & lhs
		, MaybeOptional< Vec4T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeAdd );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > > operator+( MaybeOptional< ValueT > const & lhs
		, MaybeOptional< Vec4T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeAdd );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > > operator+( MaybeOptional< Vec4T< ValueT > > const & lhs
		, MaybeOptional< ValueT > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeAdd );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > > operator+( MaybeOptional< Vec4T< ValueT > > const & lhs
		, MaybeOptional< Vec4T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeAdd );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > > operator-( MaybeOptional< ValueT > const & lhs
		, Vec4T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeMinus );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > > operator-( MaybeOptional< Vec4T< ValueT > > const & lhs
		, ValueT const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeMinus );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > > operator-( MaybeOptional< Vec4T< ValueT > > const & lhs
		, Vec4T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeMinus );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > > operator-( ValueT const & lhs
		, MaybeOptional< Vec4T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeMinus );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > > operator-( Vec4T< ValueT > const & lhs
		, MaybeOptional< ValueT > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeMinus );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > > operator-( Vec4T< ValueT > const & lhs
		, MaybeOptional< Vec4T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeMinus );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > > operator-( MaybeOptional< ValueT > const & lhs
		, MaybeOptional< Vec4T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeMinus );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > > operator-( MaybeOptional< Vec4T< ValueT > > const & lhs
		, MaybeOptional< ValueT > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeMinus );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > > operator-( MaybeOptional< Vec4T< ValueT > > const & lhs
		, MaybeOptional< Vec4T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeMinus );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > > operator*( MaybeOptional< ValueT > const & lhs
		, Vec4T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > > operator*( MaybeOptional< Vec4T< ValueT > > const & lhs
		, ValueT const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > > operator*( MaybeOptional< Vec4T< ValueT > > const & lhs
		, Vec4T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > > operator*( ValueT const & lhs
		, MaybeOptional< Vec4T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > > operator*( Vec4T< ValueT > const & lhs
		, MaybeOptional< ValueT > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > > operator*( Vec4T< ValueT > const & lhs
		, MaybeOptional< Vec4T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > > operator*( MaybeOptional< ValueT > const & lhs
		, MaybeOptional< Vec4T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > > operator*( MaybeOptional< Vec4T< ValueT > > const & lhs
		, MaybeOptional< ValueT > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > > operator*( MaybeOptional< Vec4T< ValueT > > const & lhs
		, MaybeOptional< Vec4T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > > operator/( MaybeOptional< Vec4T< ValueT > > const & lhs
		, ValueT const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeDivide );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > > operator/( MaybeOptional< Vec4T< ValueT > > const & lhs
		, Vec4T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeDivide );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > > operator/( Vec4T< ValueT > const & lhs
		, MaybeOptional< ValueT > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeDivide );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > > operator/( Vec4T< ValueT > const & lhs
		, MaybeOptional< Vec4T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeDivide );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > > operator/( MaybeOptional< Vec4T< ValueT > > const & lhs
		, MaybeOptional< ValueT > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeDivide );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > > operator/( MaybeOptional< Vec4T< ValueT > > const & lhs
		, MaybeOptional< Vec4T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeDivide );
	}

	//*************************************************************************
}
