/*
See LICENSE file in root folder
*/
namespace sdw
{
	template< typename ValueT >
	Optional< Mat3T< ValueT > >::Optional( Shader * shader
		, expr::ExprPtr expr
		, bool enabled )
		: Mat3T< ValueT >{ shader, std::move( expr ) }
		, m_enabled{ enabled }
	{
	}

	template< typename ValueT >
	Optional< Mat3T< ValueT > >::Optional( Mat3T< ValueT > const & rhs
		, bool enabled )
		: Mat3T< ValueT >{ rhs }
		, m_enabled{ enabled }
	{
	}

	template< typename ValueT >
	Optional< Mat3T< ValueT > >::Optional( Optional< Mat3T< ValueT > > const & rhs )
		: Mat3T< ValueT >{ rhs }
		, m_enabled{ rhs.m_enabled }
	{
	}

	template< typename ValueT >
	inline Optional< Mat3T< ValueT > > & Optional< Mat3T< ValueT > >::operator=( Mat3T< ValueT > const & rhs )
	{
		if ( isEnabled() )
		{
			Mat3T< ValueT >::operator=( rhs );
		}

		return *this;
	}

	template< typename ValueT >
	inline Optional< Mat3T< ValueT > > & Optional< Mat3T< ValueT > >::operator=( Optional< Mat3T< ValueT > > const & rhs )
	{
		if ( isEnabled() && rhs.isEnabled() )
		{
			Mat3T< ValueT >::operator=( rhs );
		}

		return *this;
	}

	template< typename ValueT >
	template< typename IndexT >
	Optional< Vec3T< ValueT > > Optional< Mat3T< ValueT > >::operator[]( IndexT const & offset )const
	{
		return writeBinOperator< Vec3T< ValueT > >( *this, offset, sdw::makeArrayAccess );
	}

	template< typename ValueT >
	inline bool Optional< Mat3T< ValueT > >::isEnabled()const
	{
		return m_enabled;
	}

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
}
