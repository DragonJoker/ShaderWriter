/*
See LICENSE file in root folder
*/
#include "MaybeOptionalMat3.hpp"

namespace sdw
{
	//*************************************************************************

	template< typename ValueT >
	MaybeOptional< Mat3T< ValueT > >::MaybeOptional( Shader * shader
		, expr::ExprPtr expr )
		: Mat3T< ValueT >{ shader, std::move( expr ) }
		, m_optional{ false }
		, m_enabled{ true }
	{
	}

	template< typename ValueT >
	MaybeOptional< Mat3T< ValueT > >::MaybeOptional( Shader * shader
		, expr::ExprPtr expr
		, bool enabled )
		: Mat3T< ValueT >{ shader, std::move( expr ) }
		, m_optional{ true }
		, m_enabled{ enabled }
	{
	}

	template< typename ValueT >
	inline MaybeOptional< Mat3T< ValueT > >::MaybeOptional( Mat3T< ValueT > const & rhs )
		: Mat3T< ValueT >{ rhs }
		, m_optional{ false }
		, m_enabled{ true }
	{
	}

	template< typename ValueT >
	inline MaybeOptional< Mat3T< ValueT > >::MaybeOptional( Optional< Mat3T< ValueT > > const & rhs )
		: Mat3T< ValueT >{ rhs }
		, m_optional{ true }
		, m_enabled{ rhs.isEnabled() }
	{
	}

	template< typename ValueT >
	MaybeOptional< Mat3T< ValueT > >::MaybeOptional( MaybeOptional< Mat3T< ValueT > > const & rhs )
		: Mat3T< ValueT >{ rhs }
		, m_optional{ rhs.isOptional() }
		, m_enabled{ rhs.isEnabled() }
	{
	}

	template< typename ValueT >
	MaybeOptional< Mat3T< ValueT > > & MaybeOptional< Mat3T< ValueT > >::operator=( MaybeOptional< Mat3T< ValueT > > const & rhs )
	{
		writeAssignOperator< Mat3T< ValueT > >( *this, rhs, sdw::makeAssign );
		return *this;
	}

	template< typename ValueT >
	template< typename IndexT >
	MaybeOptional< Vec3T< ValueT > > MaybeOptional< Mat3T< ValueT > >::operator[]( IndexT const & offset )const
	{
		return writeBinOperator< Vec3T< ValueT > >( *this, offset, sdw::makeArrayAccess );
	}

	template< typename ValueT >
	inline MaybeOptional< Mat3T< ValueT > >::operator Mat3T< ValueT >()const
	{
		return *this;
	}

	template< typename ValueT >
	inline MaybeOptional< Mat3T< ValueT > >::operator Optional< Mat3T< ValueT > >()const
	{
		return Optional< Mat3T< ValueT > >{ *this
			, m_enabled };
	}

	template< typename ValueT >
	inline bool MaybeOptional< Mat3T< ValueT > >::isOptional()const
	{
		return m_optional;
	}

	template< typename ValueT >
	inline bool MaybeOptional< Mat3T< ValueT > >::isEnabled()const
	{
		return m_enabled;
	}

	//*************************************************************************

	template< typename ValueT >
	MaybeOptional< Vec3T< ValueT > > operator*( MaybeOptional< Vec3T< ValueT > > const & lhs,
		Mat3T< ValueT > const & rhs )
	{
		writeAssignOperator< Vec3T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Vec3T< ValueT > > operator*( MaybeOptional< Mat3T< ValueT > > const & lhs
		, Vec3T< ValueT > const & rhs )
	{
		writeAssignOperator< Vec3T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Mat3T< ValueT > > operator*( MaybeOptional< Mat3T< ValueT > > const & lhs
		, Mat3T< ValueT > const & rhs )
	{
		writeAssignOperator< Mat3T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Vec3T< ValueT > > operator*( Vec3T< ValueT > const & lhs
		, MaybeOptional< Mat3T< ValueT > > const & rhs )
	{
		writeAssignOperator< Vec3T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Vec3T< ValueT > > operator*( Mat3T< ValueT > const & lhs
		, MaybeOptional< Vec3T< ValueT > > const & rhs )
	{
		writeAssignOperator< Vec3T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Mat3T< ValueT > > operator*( Mat3T< ValueT > const & lhs
		, MaybeOptional< Mat3T< ValueT > > const & rhs )
	{
		writeAssignOperator< Mat3T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Vec3T< ValueT > > operator*( MaybeOptional< Vec3T< ValueT > > const & lhs
		, MaybeOptional< Mat3T< ValueT > > const & rhs )
	{
		writeAssignOperator< Vec3T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Vec3T< ValueT > > operator*( MaybeOptional< Mat3T< ValueT > > const & lhs
		, MaybeOptional< Vec3T< ValueT > > const & rhs )
	{
		writeAssignOperator< Vec3T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Mat3T< ValueT > > operator*( MaybeOptional< Mat3T< ValueT > > const & lhs
		, MaybeOptional< Mat3T< ValueT > > const & rhs )
	{
		writeAssignOperator< Mat3T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Mat3T< ValueT > > operator*( MaybeOptional< ValueT > const & lhs
		, Mat3T< ValueT > const & rhs )
	{
		writeAssignOperator< Mat3T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Mat3T< ValueT > > operator*( MaybeOptional< Mat3T< ValueT > > const & lhs
		, ValueT const & rhs )
	{
		writeAssignOperator< Mat3T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Mat3T< ValueT > > operator*( ValueT const & lhs
		, MaybeOptional< Mat3T< ValueT > > const & rhs )
	{
		writeAssignOperator< Mat3T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Mat3T< ValueT > > operator*( Mat3T< ValueT > const & lhs
		, MaybeOptional< ValueT > const & rhs )
	{
		writeAssignOperator< Mat3T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Mat3T< ValueT > > operator*( MaybeOptional< ValueT > const & lhs
		, MaybeOptional< Mat3T< ValueT > > const & rhs )
	{
		writeAssignOperator< Mat3T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Mat3T< ValueT > > operator*( MaybeOptional< Mat3T< ValueT > > const & lhs
		, MaybeOptional< ValueT > const & rhs )
	{
		writeAssignOperator< Mat3T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	//*************************************************************************
}
