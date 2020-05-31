/*
See LICENSE file in root folder
*/
#include "MaybeOptionalMat2.hpp"

namespace sdw
{
	//*************************************************************************

	template< typename ValueT >
	inline Mat2T< ValueT > & Mat2T< ValueT >::operator=( MaybeOptional< Mat2T< ValueT > > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			if ( this->getContainer() )
			{
				writeAssignOperator< Mat2T< ValueT > >( *this, rhs, sdw::makeAssign );
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
	MaybeOptional< Vec2T< ValueT > > operator*( MaybeOptional< Vec2T< ValueT > > const & lhs,
		Mat2T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Vec2T< ValueT > > operator*( MaybeOptional< Mat2T< ValueT > > const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Mat2T< ValueT > > operator*( MaybeOptional< Mat2T< ValueT > > const & lhs
		, Mat2T< ValueT > const & rhs )
	{
		return writeBinOperator< Mat2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Vec2T< ValueT > > operator*( Vec2T< ValueT > const & lhs
		, MaybeOptional< Mat2T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Vec2T< ValueT > > operator*( Mat2T< ValueT > const & lhs
		, MaybeOptional< Vec2T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Mat2T< ValueT > > operator*( Mat2T< ValueT > const & lhs
		, MaybeOptional< Mat2T< ValueT > > const & rhs )
	{
		return writeBinOperator< Mat2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Vec2T< ValueT > > operator*( MaybeOptional< Vec2T< ValueT > > const & lhs
		, MaybeOptional< Mat2T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Vec2T< ValueT > > operator*( MaybeOptional< Mat2T< ValueT > > const & lhs
		, MaybeOptional< Vec2T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Mat2T< ValueT > > operator*( MaybeOptional< Mat2T< ValueT > > const & lhs
		, MaybeOptional< Mat2T< ValueT > > const & rhs )
	{
		return writeBinOperator< Mat2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Mat2T< ValueT > > operator*( MaybeOptional< ValueT > const & lhs
		, Mat2T< ValueT > const & rhs )
	{
		return writeBinOperator< Mat2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Mat2T< ValueT > > operator*( MaybeOptional< Mat2T< ValueT > > const & lhs
		, ValueT const & rhs )
	{
		return writeBinOperator< Mat2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Mat2T< ValueT > > operator*( ValueT const & lhs
		, MaybeOptional< Mat2T< ValueT > > const & rhs )
	{
		return writeBinOperator< Mat2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Mat2T< ValueT > > operator*( Mat2T< ValueT > const & lhs
		, MaybeOptional< ValueT > const & rhs )
	{
		return writeBinOperator< Mat2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Mat2T< ValueT > > operator*( MaybeOptional< ValueT > const & lhs
		, MaybeOptional< Mat2T< ValueT > > const & rhs )
	{
		return writeBinOperator< Mat2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Mat2T< ValueT > > operator*( MaybeOptional< Mat2T< ValueT > > const & lhs
		, MaybeOptional< ValueT > const & rhs )
	{
		return writeBinOperator< Mat2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	//*************************************************************************
}
