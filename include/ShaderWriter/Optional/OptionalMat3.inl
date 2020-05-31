/*
See LICENSE file in root folder
*/
namespace sdw
{
	//*********************************************************************************************

	template< typename ValueT >
	inline Mat3T< ValueT > & Mat3T< ValueT >::operator=( Optional< Mat3T< ValueT > > const & rhs )
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

	//*********************************************************************************************

	template< typename ValueT >
	Optional< Vec3T< ValueT > > operator*( Optional< Vec3T< ValueT > > const & lhs,
		Mat3T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec3T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	Optional< Vec3T< ValueT > > operator*( Optional< Mat3T< ValueT > > const & lhs
		, Vec3T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec3T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	Optional< Mat3T< ValueT > > operator*( Optional< Mat3T< ValueT > > const & lhs
		, Mat3T< ValueT > const & rhs )
	{
		return writeBinOperator< Mat3T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	Optional< Vec3T< ValueT > > operator*( Vec3T< ValueT > const & lhs
		, Optional< Mat3T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec3T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	Optional< Vec3T< ValueT > > operator*( Mat3T< ValueT > const & lhs
		, Optional< Vec3T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec3T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	Optional< Mat3T< ValueT > > operator*( Mat3T< ValueT > const & lhs
		, Optional< Mat3T< ValueT > > const & rhs )
	{
		return writeBinOperator< Mat3T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	Optional< Vec3T< ValueT > > operator*( Optional< Vec3T< ValueT > > const & lhs
		, Optional< Mat3T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec3T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	Optional< Vec3T< ValueT > > operator*( Optional< Mat3T< ValueT > > const & lhs
		, Optional< Vec3T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec3T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	Optional< Mat3T< ValueT > > operator*( Optional< Mat3T< ValueT > > const & lhs
		, Optional< Mat3T< ValueT > > const & rhs )
	{
		return writeBinOperator< Mat3T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	//*********************************************************************************************
}
