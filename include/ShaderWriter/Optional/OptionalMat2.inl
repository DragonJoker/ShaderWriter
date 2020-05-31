/*
See LICENSE file in root folder
*/
namespace sdw
{
	//*********************************************************************************************

	template< typename ValueT >
	inline Mat2T< ValueT > & Mat2T< ValueT >::operator=( Optional< Mat2T< ValueT > > const & rhs )
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

	//*********************************************************************************************

	template< typename ValueT >
	Optional< Vec2T< ValueT > > operator*( Optional< Vec2T< ValueT > > const & lhs,
		Mat2T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	Optional< Vec2T< ValueT > > operator*( Optional< Mat2T< ValueT > > const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	Optional< Mat2T< ValueT > > operator*( Optional< Mat2T< ValueT > > const & lhs
		, Mat2T< ValueT > const & rhs )
	{
		return writeBinOperator< Mat2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	Optional< Vec2T< ValueT > > operator*( Vec2T< ValueT > const & lhs
		, Optional< Mat2T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	Optional< Vec2T< ValueT > > operator*( Mat2T< ValueT > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	Optional< Mat2T< ValueT > > operator*( Mat2T< ValueT > const & lhs
		, Optional< Mat2T< ValueT > > const & rhs )
	{
		return writeBinOperator< Mat2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	Optional< Vec2T< ValueT > > operator*( Optional< Vec2T< ValueT > > const & lhs
		, Optional< Mat2T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	Optional< Vec2T< ValueT > > operator*( Optional< Mat2T< ValueT > > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	Optional< Mat2T< ValueT > > operator*( Optional< Mat2T< ValueT > > const & lhs
		, Optional< Mat2T< ValueT > > const & rhs )
	{
		return writeBinOperator< Mat2T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	//*********************************************************************************************
}
