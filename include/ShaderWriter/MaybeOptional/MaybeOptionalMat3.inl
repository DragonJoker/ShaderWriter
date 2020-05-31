/*
See LICENSE file in root folder
*/
#include "MaybeOptionalMat3.hpp"

namespace sdw
{
	//*************************************************************************

	template< typename ValueT >
	inline Mat3T< ValueT > & Mat3T< ValueT >::operator=( MaybeOptional< Mat3T< ValueT > > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			if ( this->getContainer() )
			{
				writeAssignOperator< Mat3T< ValueT > >( *this, rhs, sdw::makeAssign );
			}
			else
			{
				Value::operator=( rhs );
			}
		}

		return *this;
	}

	//*************************************************************************

	template< typename ValueT >
	MaybeOptional< Vec3T< ValueT > > operator*( MaybeOptional< Vec3T< ValueT > > const & lhs,
		Mat3T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec3T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Vec3T< ValueT > > operator*( MaybeOptional< Mat3T< ValueT > > const & lhs
		, Vec3T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec3T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Mat3T< ValueT > > operator*( MaybeOptional< Mat3T< ValueT > > const & lhs
		, Mat3T< ValueT > const & rhs )
	{
		return writeBinOperator< Mat3T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Vec3T< ValueT > > operator*( Vec3T< ValueT > const & lhs
		, MaybeOptional< Mat3T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec3T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Vec3T< ValueT > > operator*( Mat3T< ValueT > const & lhs
		, MaybeOptional< Vec3T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec3T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Mat3T< ValueT > > operator*( Mat3T< ValueT > const & lhs
		, MaybeOptional< Mat3T< ValueT > > const & rhs )
	{
		return writeBinOperator< Mat3T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Vec3T< ValueT > > operator*( MaybeOptional< Vec3T< ValueT > > const & lhs
		, MaybeOptional< Mat3T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec3T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Vec3T< ValueT > > operator*( MaybeOptional< Mat3T< ValueT > > const & lhs
		, MaybeOptional< Vec3T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec3T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Mat3T< ValueT > > operator*( MaybeOptional< Mat3T< ValueT > > const & lhs
		, MaybeOptional< Mat3T< ValueT > > const & rhs )
	{
		return writeBinOperator< Mat3T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Mat3T< ValueT > > operator*( MaybeOptional< ValueT > const & lhs
		, Mat3T< ValueT > const & rhs )
	{
		return writeBinOperator< Mat3T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Mat3T< ValueT > > operator*( MaybeOptional< Mat3T< ValueT > > const & lhs
		, ValueT const & rhs )
	{
		return writeBinOperator< Mat3T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Mat3T< ValueT > > operator*( ValueT const & lhs
		, MaybeOptional< Mat3T< ValueT > > const & rhs )
	{
		return writeBinOperator< Mat3T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Mat3T< ValueT > > operator*( Mat3T< ValueT > const & lhs
		, MaybeOptional< ValueT > const & rhs )
	{
		return writeBinOperator< Mat3T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Mat3T< ValueT > > operator*( MaybeOptional< ValueT > const & lhs
		, MaybeOptional< Mat3T< ValueT > > const & rhs )
	{
		return writeBinOperator< Mat3T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Mat3T< ValueT > > operator*( MaybeOptional< Mat3T< ValueT > > const & lhs
		, MaybeOptional< ValueT > const & rhs )
	{
		return writeBinOperator< Mat3T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	//*************************************************************************
}
