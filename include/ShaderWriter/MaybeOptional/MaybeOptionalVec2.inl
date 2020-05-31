/*
See LICENSE file in root folder
*/
#include "MaybeOptionalVec2.hpp"

namespace sdw
{
	//*************************************************************************

	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > >::MaybeOptional( Shader * shader
		, expr::ExprPtr expr )
		: Vec2T< ValueT >{ shader, std::move( expr ) }
		, m_optional{ false }
		, m_enabled{ true }
	{
	}

	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > >::MaybeOptional( Shader * shader
		, expr::ExprPtr expr
		, bool enabled )
		: Vec2T< ValueT >{ shader, std::move( expr ) }
		, m_optional{ true }
		, m_enabled{ enabled }
	{
	}

	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > >::MaybeOptional( Vec2T< ValueT > const & rhs )
		: Vec2T< ValueT >{ rhs }
		, m_optional{ false }
		, m_enabled{ true }
	{
	}

	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > >::MaybeOptional( Optional< Vec2T< ValueT > > const & rhs )
		: Vec2T< ValueT >{ rhs }
		, m_optional{ true }
		, m_enabled{ rhs.isEnabled() }
	{
	}

	template< typename ValueT >
	MaybeOptional< Vec2T< ValueT > >::MaybeOptional( MaybeOptional< Vec2T< ValueT > > const & rhs )
		: Vec2T< ValueT >{ rhs }
		, m_optional{ rhs.isOptional() }
		, m_enabled{ rhs.isEnabled() }
	{
	}

	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > & MaybeOptional< Vec2T< ValueT > >::operator=( Vec2T< ValueT > const & rhs )
	{
		if ( isEnabled() )
		{
			Vec2T< ValueT >::operator=( rhs );
		}

		return *this;
	}

	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > & MaybeOptional< Vec2T< ValueT > >::operator=( Optional< Vec2T< ValueT > > const & rhs )
	{
		if ( isEnabled() && rhs.isEnabled() )
		{
			Vec2T< ValueT >::operator=( rhs );
		}

		return *this;
	}

	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > & MaybeOptional< Vec2T< ValueT > >::operator=( MaybeOptional< Vec2T< ValueT > > const & rhs )
	{
		if ( isEnabled() && rhs.isEnabled() )
		{
			Vec2T< ValueT >::operator=( rhs );
		}

		return *this;
	}

	template< typename ValueT >
	template< typename IndexT >
	inline MaybeOptional< ValueT > MaybeOptional< Vec2T< ValueT > >::operator[]( IndexT const & offset )const
	{
		return writeBinOperator< ValueT >( *this, offset, sdw::makeArrayAccess );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > >::operator Vec2T< ValueT >()const
	{
		return *this;
	}

	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > >::operator Optional< Vec2T< ValueT > >()const
	{
		return Optional< Vec2T< ValueT > >{ *this
			, m_enabled };
	}

	template< typename ValueT >
	inline bool MaybeOptional< Vec2T< ValueT > >::isOptional()const
	{
		return m_optional;
	}

	template< typename ValueT >
	inline bool MaybeOptional< Vec2T< ValueT > >::isEnabled()const
	{
		return m_enabled;
	}

	//*********************************************************************************************

	template< typename ValueT >
	inline Vec2T< ValueT > & Vec2T< ValueT >::operator=( MaybeOptional< Vec2T< ValueT > > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			if ( this->getContainer() )
			{
				writeAssignOperator< Vec2T< ValueT > >( *this, rhs, sdw::makeAssign );
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
	inline Optional< Vec2T< ValueT > > & Optional< Vec2T< ValueT > >::operator=( MaybeOptional< Vec2T< ValueT > > const & rhs )
	{
		if ( isEnabled() && rhs.isEnabled() )
		{
			Vec2T< ValueT >::operator=( rhs );
		}

		return *this;
	}

	//*********************************************************************************************

	template< typename ValueT >
	MaybeOptional< Vec2T< ValueT > > & MaybeOptional< Vec2T< ValueT > >::operator+=( Vec2T< ValueT > const & rhs )
	{
		writeAssignOperator< Vec2T< ValueT > >( *this, rhs, sdw::makeAddAssign );
		return *this;
	}

	template< typename ValueT >
	MaybeOptional< Vec2T< ValueT > > & MaybeOptional< Vec2T< ValueT > >::operator-=( Vec2T< ValueT > const & rhs )
	{
		writeAssignOperator< Vec2T< ValueT > >( *this, rhs, sdw::makeMinusAssign );
		return *this;
	}

	template< typename ValueT >
	MaybeOptional< Vec2T< ValueT > > & MaybeOptional< Vec2T< ValueT > >::operator*=( Vec2T< ValueT > const & rhs )
	{
		writeAssignOperator< Vec2T< ValueT > >( *this, rhs, sdw::makeTimesAssign );
		return *this;
	}

	template< typename ValueT >
	MaybeOptional< Vec2T< ValueT > > & MaybeOptional< Vec2T< ValueT > >::operator/=( Vec2T< ValueT > const & rhs )
	{
		writeAssignOperator< Vec2T< ValueT > >( *this, rhs, sdw::makeDivideAssign );
		return *this;
	}

	template< typename ValueT >
	MaybeOptional< Vec2T< ValueT > > & MaybeOptional< Vec2T< ValueT > >::operator+=( MaybeOptional< Vec2T< ValueT > > const & rhs )
	{
		writeAssignOperator< Vec2T< ValueT > >( *this, rhs, sdw::makeAddAssign );
		return *this;
	}

	template< typename ValueT >
	MaybeOptional< Vec2T< ValueT > > & MaybeOptional< Vec2T< ValueT > >::operator-=( MaybeOptional< Vec2T< ValueT > > const & rhs )
	{
		writeAssignOperator< Vec2T< ValueT > >( *this, rhs, sdw::makeMinusAssign );
		return *this;
	}

	template< typename ValueT >
	MaybeOptional< Vec2T< ValueT > > & MaybeOptional< Vec2T< ValueT > >::operator*=( MaybeOptional< Vec2T< ValueT > > const & rhs )
	{
		writeAssignOperator< Vec2T< ValueT > >( *this, rhs, sdw::makeTimesAssign );
		return *this;
	}

	template< typename ValueT >
	MaybeOptional< Vec2T< ValueT > > & MaybeOptional< Vec2T< ValueT > >::operator/=( MaybeOptional< Vec2T< ValueT > > const & rhs )
	{
		writeAssignOperator< Vec2T< ValueT > >( *this, rhs, sdw::makeDivideAssign );
		return *this;
	}

	template< typename ValueT >
	MaybeOptional< Vec2T< ValueT > > & MaybeOptional< Vec2T< ValueT > >::operator+=( ValueT const & rhs )
	{
		writeAssignOperator< Vec2T< ValueT > >( *this, rhs, sdw::makeAddAssign );
		return *this;
	}

	template< typename ValueT >
	MaybeOptional< Vec2T< ValueT > > & MaybeOptional< Vec2T< ValueT > >::operator-=( ValueT const & rhs )
	{
		writeAssignOperator< Vec2T< ValueT > >( *this, rhs, sdw::makeMinusAssign );
		return *this;
	}

	template< typename ValueT >
	MaybeOptional< Vec2T< ValueT > > & MaybeOptional< Vec2T< ValueT > >::operator*=( ValueT const & rhs )
	{
		writeAssignOperator< Vec2T< ValueT > >( *this, rhs, sdw::makeTimesAssign );
		return *this;
	}

	template< typename ValueT >
	MaybeOptional< Vec2T< ValueT > > & MaybeOptional< Vec2T< ValueT > >::operator/=( ValueT const & rhs )
	{
		writeAssignOperator< Vec2T< ValueT > >( *this, rhs, sdw::makeDivideAssign );
		return *this;
	}

	template< typename ValueT >
	MaybeOptional< Vec2T< ValueT > > & MaybeOptional< Vec2T< ValueT > >::operator+=( MaybeOptional< ValueT > const & rhs )
	{
		writeAssignOperator< Vec2T< ValueT > >( *this, rhs, sdw::makeAddAssign );
		return *this;
	}

	template< typename ValueT >
	MaybeOptional< Vec2T< ValueT > > & MaybeOptional< Vec2T< ValueT > >::operator-=( MaybeOptional< ValueT > const & rhs )
	{
		writeAssignOperator< Vec2T< ValueT > >( *this, rhs, sdw::makeMinusAssign );
		return *this;
	}

	template< typename ValueT >
	MaybeOptional< Vec2T< ValueT > > & MaybeOptional< Vec2T< ValueT > >::operator*=( MaybeOptional< ValueT > const & rhs )
	{
		writeAssignOperator< Vec2T< ValueT > >( *this, rhs, sdw::makeTimesAssign );
		return *this;
	}

	template< typename ValueT >
	MaybeOptional< Vec2T< ValueT > > & MaybeOptional< Vec2T< ValueT > >::operator/=( MaybeOptional< ValueT > const & rhs )
	{
		writeAssignOperator< Vec2T< ValueT > >( *this, rhs, sdw::makeDivideAssign );
		return *this;
	}

	template< typename ValueT >
	MaybeOptional< Vec2T< ValueT > > MaybeOptional< Vec2T< ValueT > >::operator-()const
	{
		return writeUnOperator< Vec2T< ValueT > >( *this, sdw::makeUnMinus );
	}

	template< typename ValueT >
	MaybeOptional< Vec2T< ValueT > > MaybeOptional< Vec2T< ValueT > >::operator+()const
	{
		return writeUnOperator< Vec2T< ValueT > >( *this, sdw::makeUnPlus );
	}

	//*************************************************************************

	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator+( MaybeOptional< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeAdd );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator+( MaybeOptional< Vec2T< ValueT > > const & lhs
		, CppTypeT< ValueT > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeAdd );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator+( MaybeOptional< Vec2T< ValueT > > const & lhs
		, ValueT const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeAdd );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator+( MaybeOptional< Vec2T< ValueT > > const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeAdd );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator+( CppTypeT< ValueT > const & lhs
		, MaybeOptional< Vec2T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeAdd );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator+( ValueT const & lhs
		, MaybeOptional< Vec2T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeAdd );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator+( Vec2T< ValueT > const & lhs
		, MaybeOptional< ValueT > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeAdd );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator+( Vec2T< ValueT > const & lhs
		, MaybeOptional< Vec2T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeAdd );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator+( MaybeOptional< ValueT > const & lhs
		, MaybeOptional< Vec2T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeAdd );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator+( MaybeOptional< Vec2T< ValueT > > const & lhs
		, MaybeOptional< ValueT > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeAdd );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator+( MaybeOptional< Vec2T< ValueT > > const & lhs
		, MaybeOptional< Vec2T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeAdd );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator-( MaybeOptional< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeMinus );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator-( MaybeOptional< Vec2T< ValueT > > const & lhs
		, CppTypeT< ValueT > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeMinus );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator-( MaybeOptional< Vec2T< ValueT > > const & lhs
		, ValueT const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeMinus );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator-( MaybeOptional< Vec2T< ValueT > > const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeMinus );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator-( CppTypeT< ValueT > const & lhs
		, MaybeOptional< Vec2T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeMinus );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator-( ValueT const & lhs
		, MaybeOptional< Vec2T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeMinus );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator-( Vec2T< ValueT > const & lhs
		, MaybeOptional< ValueT > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeMinus );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator-( Vec2T< ValueT > const & lhs
		, MaybeOptional< Vec2T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeMinus );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator-( MaybeOptional< ValueT > const & lhs
		, MaybeOptional< Vec2T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeMinus );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator-( MaybeOptional< Vec2T< ValueT > > const & lhs
		, MaybeOptional< ValueT > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeMinus );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator-( MaybeOptional< Vec2T< ValueT > > const & lhs
		, MaybeOptional< Vec2T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeMinus );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator*( MaybeOptional< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator*( MaybeOptional< Vec2T< ValueT > > const & lhs
		, CppTypeT< ValueT > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator*( MaybeOptional< Vec2T< ValueT > > const & lhs
		, ValueT const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator*( MaybeOptional< Vec2T< ValueT > > const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator*( CppTypeT< ValueT > const & lhs
		, MaybeOptional< Vec2T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator*( ValueT const & lhs
		, MaybeOptional< Vec2T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator*( Vec2T< ValueT > const & lhs
		, MaybeOptional< ValueT > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator*( Vec2T< ValueT > const & lhs
		, MaybeOptional< Vec2T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator*( MaybeOptional< ValueT > const & lhs
		, MaybeOptional< Vec2T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator*( MaybeOptional< Vec2T< ValueT > > const & lhs
		, MaybeOptional< ValueT > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator*( MaybeOptional< Vec2T< ValueT > > const & lhs
		, MaybeOptional< Vec2T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator/( MaybeOptional< Vec2T< ValueT > > const & lhs
		, CppTypeT< ValueT > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeDivide );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator/( MaybeOptional< Vec2T< ValueT > > const & lhs
		, ValueT const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeDivide );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator/( MaybeOptional< Vec2T< ValueT > > const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeDivide );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator/( Vec2T< ValueT > const & lhs
		, MaybeOptional< ValueT > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeDivide );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator/( Vec2T< ValueT > const & lhs
		, MaybeOptional< Vec2T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeDivide );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator/( MaybeOptional< Vec2T< ValueT > > const & lhs
		, MaybeOptional< ValueT > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeDivide );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator/( MaybeOptional< Vec2T< ValueT > > const & lhs
		, MaybeOptional< Vec2T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeDivide );
	}

	//*************************************************************************
}
