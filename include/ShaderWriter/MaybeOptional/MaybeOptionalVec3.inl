/*
See LICENSE file in root folder
*/
#include "MaybeOptionalVec3.hpp"

namespace sdw
{
	//*************************************************************************

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > >::MaybeOptional( Shader * shader
		, expr::ExprPtr expr )
		: Vec3T< ValueT >{ shader, std::move( expr ) }
		, m_optional{ false }
		, m_enabled{ true }
	{
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > >::MaybeOptional( Shader * shader
		, expr::ExprPtr expr
		, bool enabled )
		: Vec3T< ValueT >{ shader, std::move( expr ) }
		, m_optional{ true }
		, m_enabled{ enabled }
	{
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > >::MaybeOptional( Vec3T< ValueT > const & rhs )
		: Vec3T< ValueT >{ rhs }
		, m_optional{ false }
		, m_enabled{ true }
	{
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > >::MaybeOptional( Optional< Vec3T< ValueT > > const & rhs )
		: Vec3T< ValueT >{ rhs }
		, m_optional{ true }
		, m_enabled{ rhs.isEnabled() }
	{
	}

	template< typename ValueT >
	MaybeOptional< Vec3T< ValueT > >::MaybeOptional( MaybeOptional< Vec3T< ValueT > > const & rhs )
		: Vec3T< ValueT >{ rhs }
		, m_optional{ rhs.isOptional() }
		, m_enabled{ rhs.isEnabled() }
	{
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > & MaybeOptional< Vec3T< ValueT > >::operator=( Vec3T< ValueT > const & rhs )
	{
		if ( isEnabled() )
		{
			Vec3T< ValueT >::operator=( rhs );
		}

		return *this;
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > & MaybeOptional< Vec3T< ValueT > >::operator=( Optional< Vec3T< ValueT > > const & rhs )
	{
		if ( isEnabled() && rhs.isEnabled() )
		{
			Vec3T< ValueT >::operator=( rhs );
		}

		return *this;
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > & MaybeOptional< Vec3T< ValueT > >::operator=( MaybeOptional< Vec3T< ValueT > > const & rhs )
	{
		if ( isEnabled() && rhs.isEnabled() )
		{
			Vec3T< ValueT >::operator=( rhs );
		}

		return *this;
	}

	template< typename ValueT >
	template< typename IndexT >
	inline MaybeOptional< ValueT > MaybeOptional< Vec3T< ValueT > >::operator[]( IndexT const & offset )const
	{
		return writeBinOperator< ValueT >( *this, offset, sdw::makeArrayAccess );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > >::operator Vec3T< ValueT >()const
	{
		return *this;
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > >::operator Optional< Vec3T< ValueT > >()const
	{
		return Optional< Vec3T< ValueT > >{ *this
			, m_enabled };
	}

	template< typename ValueT >
	inline bool MaybeOptional< Vec3T< ValueT > >::isOptional()const
	{
		return m_optional;
	}

	template< typename ValueT >
	inline bool MaybeOptional< Vec3T< ValueT > >::isEnabled()const
	{
		return m_enabled;
	}

	//*********************************************************************************************

	template< typename ValueT >
	inline Vec3T< ValueT > & Vec3T< ValueT >::operator=( MaybeOptional< Vec3T< ValueT > > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			if ( this->getContainer() )
			{
				writeAssignOperator< Vec3T< ValueT > >( *this, rhs, sdw::makeAssign );
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
	inline Optional< Vec3T< ValueT > > & Optional< Vec3T< ValueT > >::operator=( MaybeOptional< Vec3T< ValueT > > const & rhs )
	{
		if ( isEnabled() && rhs.isEnabled() )
		{
			Vec3T< ValueT >::operator=( rhs );
		}

		return *this;
	}

	//*********************************************************************************************

	template< typename ValueT >
	MaybeOptional< Vec3T< ValueT > > & MaybeOptional< Vec3T< ValueT > >::operator+=( Vec3T< ValueT > const & rhs )
	{
		writeAssignOperator< Vec3T< ValueT > >( *this, rhs, sdw::makeAddAssign );
		return *this;
	}

	template< typename ValueT >
	MaybeOptional< Vec3T< ValueT > > & MaybeOptional< Vec3T< ValueT > >::operator-=( Vec3T< ValueT > const & rhs )
	{
		writeAssignOperator< Vec3T< ValueT > >( *this, rhs, sdw::makeMinusAssign );
		return *this;
	}

	template< typename ValueT >
	MaybeOptional< Vec3T< ValueT > > & MaybeOptional< Vec3T< ValueT > >::operator*=( Vec3T< ValueT > const & rhs )
	{
		writeAssignOperator< Vec3T< ValueT > >( *this, rhs, sdw::makeTimesAssign );
		return *this;
	}

	template< typename ValueT >
	MaybeOptional< Vec3T< ValueT > > & MaybeOptional< Vec3T< ValueT > >::operator/=( Vec3T< ValueT > const & rhs )
	{
		writeAssignOperator< Vec3T< ValueT > >( *this, rhs, sdw::makeDivideAssign );
		return *this;
	}

	template< typename ValueT >
	MaybeOptional< Vec3T< ValueT > > & MaybeOptional< Vec3T< ValueT > >::operator+=( MaybeOptional< Vec3T< ValueT > > const & rhs )
	{
		writeAssignOperator< Vec3T< ValueT > >( *this, rhs, sdw::makeAddAssign );
		return *this;
	}

	template< typename ValueT >
	MaybeOptional< Vec3T< ValueT > > & MaybeOptional< Vec3T< ValueT > >::operator-=( MaybeOptional< Vec3T< ValueT > > const & rhs )
	{
		writeAssignOperator< Vec3T< ValueT > >( *this, rhs, sdw::makeMinusAssign );
		return *this;
	}

	template< typename ValueT >
	MaybeOptional< Vec3T< ValueT > > & MaybeOptional< Vec3T< ValueT > >::operator*=( MaybeOptional< Vec3T< ValueT > > const & rhs )
	{
		writeAssignOperator< Vec3T< ValueT > >( *this, rhs, sdw::makeTimesAssign );
		return *this;
	}

	template< typename ValueT >
	MaybeOptional< Vec3T< ValueT > > & MaybeOptional< Vec3T< ValueT > >::operator/=( MaybeOptional< Vec3T< ValueT > > const & rhs )
	{
		writeAssignOperator< Vec3T< ValueT > >( *this, rhs, sdw::makeDivideAssign );
		return *this;
	}

	template< typename ValueT >
	MaybeOptional< Vec3T< ValueT > > & MaybeOptional< Vec3T< ValueT > >::operator+=( ValueT const & rhs )
	{
		writeAssignOperator< Vec3T< ValueT > >( *this, rhs, sdw::makeAddAssign );
		return *this;
	}

	template< typename ValueT >
	MaybeOptional< Vec3T< ValueT > > & MaybeOptional< Vec3T< ValueT > >::operator-=( ValueT const & rhs )
	{
		writeAssignOperator< Vec3T< ValueT > >( *this, rhs, sdw::makeMinusAssign );
		return *this;
	}

	template< typename ValueT >
	MaybeOptional< Vec3T< ValueT > > & MaybeOptional< Vec3T< ValueT > >::operator*=( ValueT const & rhs )
	{
		writeAssignOperator< Vec3T< ValueT > >( *this, rhs, sdw::makeTimesAssign );
		return *this;
	}

	template< typename ValueT >
	MaybeOptional< Vec3T< ValueT > > & MaybeOptional< Vec3T< ValueT > >::operator/=( ValueT const & rhs )
	{
		writeAssignOperator< Vec3T< ValueT > >( *this, rhs, sdw::makeDivideAssign );
		return *this;
	}

	template< typename ValueT >
	MaybeOptional< Vec3T< ValueT > > & MaybeOptional< Vec3T< ValueT > >::operator+=( MaybeOptional< ValueT > const & rhs )
	{
		writeAssignOperator< Vec3T< ValueT > >( *this, rhs, sdw::makeAddAssign );
		return *this;
	}

	template< typename ValueT >
	MaybeOptional< Vec3T< ValueT > > & MaybeOptional< Vec3T< ValueT > >::operator-=( MaybeOptional< ValueT > const & rhs )
	{
		writeAssignOperator< Vec3T< ValueT > >( *this, rhs, sdw::makeMinusAssign );
		return *this;
	}

	template< typename ValueT >
	MaybeOptional< Vec3T< ValueT > > & MaybeOptional< Vec3T< ValueT > >::operator*=( MaybeOptional< ValueT > const & rhs )
	{
		writeAssignOperator< Vec3T< ValueT > >( *this, rhs, sdw::makeTimesAssign );
		return *this;
	}

	template< typename ValueT >
	MaybeOptional< Vec3T< ValueT > > & MaybeOptional< Vec3T< ValueT > >::operator/=( MaybeOptional< ValueT > const & rhs )
	{
		writeAssignOperator< Vec3T< ValueT > >( *this, rhs, sdw::makeDivideAssign );
		return *this;
	}

	template< typename ValueT >
	MaybeOptional< Vec3T< ValueT > > MaybeOptional< Vec3T< ValueT > >::operator-()const
	{
		return writeUnOperator< Vec3T< ValueT > >( *this, sdw::makeUnMinus );
	}

	template< typename ValueT >
	MaybeOptional< Vec3T< ValueT > > MaybeOptional< Vec3T< ValueT > >::operator+()const
	{
		return writeUnOperator< Vec3T< ValueT > >( *this, sdw::makeUnPlus );
	}

	//*************************************************************************

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator+( MaybeOptional< ValueT > const & lhs
		, Vec3T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec3T< ValueT > >( lhs, rhs, sdw::makeAdd );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator+( MaybeOptional< Vec3T< ValueT > > const & lhs
		, CppTypeT< ValueT > const & rhs )
	{
		return writeBinOperator< Vec3T< ValueT > >( lhs, rhs, sdw::makeAdd );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator+( MaybeOptional< Vec3T< ValueT > > const & lhs
		, ValueT const & rhs )
	{
		return writeBinOperator< Vec3T< ValueT > >( lhs, rhs, sdw::makeAdd );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator+( MaybeOptional< Vec3T< ValueT > > const & lhs
		, Vec3T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec3T< ValueT > >( lhs, rhs, sdw::makeAdd );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator+( CppTypeT< ValueT > const & lhs
		, MaybeOptional< Vec3T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec3T< ValueT > >( lhs, rhs, sdw::makeAdd );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator+( ValueT const & lhs
		, MaybeOptional< Vec3T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec3T< ValueT > >( lhs, rhs, sdw::makeAdd );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator+( Vec3T< ValueT > const & lhs
		, MaybeOptional< ValueT > const & rhs )
	{
		return writeBinOperator< Vec3T< ValueT > >( lhs, rhs, sdw::makeAdd );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator+( Vec3T< ValueT > const & lhs
		, MaybeOptional< Vec3T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec3T< ValueT > >( lhs, rhs, sdw::makeAdd );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator+( MaybeOptional< ValueT > const & lhs
		, MaybeOptional< Vec3T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec3T< ValueT > >( lhs, rhs, sdw::makeAdd );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator+( MaybeOptional< Vec3T< ValueT > > const & lhs
		, MaybeOptional< ValueT > const & rhs )
	{
		return writeBinOperator< Vec3T< ValueT > >( lhs, rhs, sdw::makeAdd );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator+( MaybeOptional< Vec3T< ValueT > > const & lhs
		, MaybeOptional< Vec3T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec3T< ValueT > >( lhs, rhs, sdw::makeAdd );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator-( MaybeOptional< ValueT > const & lhs
		, Vec3T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec3T< ValueT > >( lhs, rhs, sdw::makeMinus );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator-( MaybeOptional< Vec3T< ValueT > > const & lhs
		, CppTypeT< ValueT > const & rhs )
	{
		return writeBinOperator< Vec3T< ValueT > >( lhs, rhs, sdw::makeMinus );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator-( MaybeOptional< Vec3T< ValueT > > const & lhs
		, ValueT const & rhs )
	{
		return writeBinOperator< Vec3T< ValueT > >( lhs, rhs, sdw::makeMinus );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator-( MaybeOptional< Vec3T< ValueT > > const & lhs
		, Vec3T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec3T< ValueT > >( lhs, rhs, sdw::makeMinus );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator-( CppTypeT< ValueT > const & lhs
		, MaybeOptional< Vec3T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec3T< ValueT > >( lhs, rhs, sdw::makeMinus );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator-( ValueT const & lhs
		, MaybeOptional< Vec3T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec3T< ValueT > >( lhs, rhs, sdw::makeMinus );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator-( Vec3T< ValueT > const & lhs
		, MaybeOptional< ValueT > const & rhs )
	{
		return writeBinOperator< Vec3T< ValueT > >( lhs, rhs, sdw::makeMinus );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator-( Vec3T< ValueT > const & lhs
		, MaybeOptional< Vec3T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec3T< ValueT > >( lhs, rhs, sdw::makeMinus );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator-( MaybeOptional< ValueT > const & lhs
		, MaybeOptional< Vec3T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec3T< ValueT > >( lhs, rhs, sdw::makeMinus );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator-( MaybeOptional< Vec3T< ValueT > > const & lhs
		, MaybeOptional< ValueT > const & rhs )
	{
		return writeBinOperator< Vec3T< ValueT > >( lhs, rhs, sdw::makeMinus );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator-( MaybeOptional< Vec3T< ValueT > > const & lhs
		, MaybeOptional< Vec3T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec3T< ValueT > >( lhs, rhs, sdw::makeMinus );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator*( MaybeOptional< ValueT > const & lhs
		, Vec3T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec3T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator*( MaybeOptional< Vec3T< ValueT > > const & lhs
		, CppTypeT< ValueT > const & rhs )
	{
		return writeBinOperator< Vec3T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator*( MaybeOptional< Vec3T< ValueT > > const & lhs
		, ValueT const & rhs )
	{
		return writeBinOperator< Vec3T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator*( MaybeOptional< Vec3T< ValueT > > const & lhs
		, Vec3T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec3T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator*( CppTypeT< ValueT > const & lhs
		, MaybeOptional< Vec3T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec3T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator*( ValueT const & lhs
		, MaybeOptional< Vec3T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec3T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator*( Vec3T< ValueT > const & lhs
		, MaybeOptional< ValueT > const & rhs )
	{
		return writeBinOperator< Vec3T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator*( Vec3T< ValueT > const & lhs
		, MaybeOptional< Vec3T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec3T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator*( MaybeOptional< ValueT > const & lhs
		, MaybeOptional< Vec3T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec3T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator*( MaybeOptional< Vec3T< ValueT > > const & lhs
		, MaybeOptional< ValueT > const & rhs )
	{
		return writeBinOperator< Vec3T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator*( MaybeOptional< Vec3T< ValueT > > const & lhs
		, MaybeOptional< Vec3T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec3T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator/( MaybeOptional< Vec3T< ValueT > > const & lhs
		, CppTypeT< ValueT > const & rhs )
	{
		return writeBinOperator< Vec3T< ValueT > >( lhs, rhs, sdw::makeDivide );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator/( MaybeOptional< Vec3T< ValueT > > const & lhs
		, ValueT const & rhs )
	{
		return writeBinOperator< Vec3T< ValueT > >( lhs, rhs, sdw::makeDivide );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator/( MaybeOptional< Vec3T< ValueT > > const & lhs
		, Vec3T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec3T< ValueT > >( lhs, rhs, sdw::makeDivide );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator/( Vec3T< ValueT > const & lhs
		, MaybeOptional< ValueT > const & rhs )
	{
		return writeBinOperator< Vec3T< ValueT > >( lhs, rhs, sdw::makeDivide );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator/( Vec3T< ValueT > const & lhs
		, MaybeOptional< Vec3T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec3T< ValueT > >( lhs, rhs, sdw::makeDivide );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator/( MaybeOptional< Vec3T< ValueT > > const & lhs
		, MaybeOptional< ValueT > const & rhs )
	{
		return writeBinOperator< Vec3T< ValueT > >( lhs, rhs, sdw::makeDivide );
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator/( MaybeOptional< Vec3T< ValueT > > const & lhs
		, MaybeOptional< Vec3T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec3T< ValueT > >( lhs, rhs, sdw::makeDivide );
	}

	//*************************************************************************
}
