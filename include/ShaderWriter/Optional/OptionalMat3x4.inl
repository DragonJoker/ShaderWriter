/*
See LICENSE file in root folder
*/
namespace sdw
{
	template< typename ValueT >
	Optional< Mat3x4T< ValueT > >::Optional( Shader * shader
		, expr::ExprPtr expr
		, bool enabled )
		: Mat3x4T< ValueT >{ shader, std::move( expr ) }
		, m_enabled{ enabled }
	{
	}

	template< typename ValueT >
	Optional< Mat3x4T< ValueT > >::Optional( Mat3x4T< ValueT > const & rhs
		, bool enabled )
		: Mat3x4T< ValueT >{ rhs }
		, m_enabled{ enabled }
	{
	}

	template< typename ValueT >
	Optional< Mat3x4T< ValueT > >::Optional( Optional< Mat3x4T< ValueT > > const & rhs )
		: Mat3x4T< ValueT >{ rhs }
		, m_enabled{ rhs.m_enabled }
	{
	}

	template< typename ValueT >
	inline Optional< Mat3x4T< ValueT > > & Optional< Mat3x4T< ValueT > >::operator=( Mat3x4T< ValueT > const & rhs )
	{
		if ( isEnabled() )
		{
			Mat3x4T< ValueT >::operator=( rhs );
		}

		return *this;
	}

	template< typename ValueT >
	inline Optional< Mat3x4T< ValueT > > & Optional< Mat3x4T< ValueT > >::operator=( Optional< Mat3x4T< ValueT > > const & rhs )
	{
		if ( isEnabled() && rhs.isEnabled() )
		{
			Mat3x4T< ValueT >::operator=( rhs );
		}

		return *this;
	}

	template< typename ValueT >
	template< typename IndexT >
	Optional< Vec4T< ValueT > > Optional< Mat3x4T< ValueT > >::operator[]( IndexT const & offset )const
	{
		return writeBinOperator< Vec4T< ValueT > >( *this, offset, sdw::makeArrayAccess );
	}

	template< typename ValueT >
	inline bool Optional< Mat3x4T< ValueT > >::isEnabled()const
	{
		return m_enabled;
	}

	//*********************************************************************************************

	template< typename ValueT >
	inline Mat3x4T< ValueT > & Mat3x4T< ValueT >::operator=( Optional< Mat3x4T< ValueT > > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			if ( this->getContainer() )
			{
				writeAssignOperator< Mat3x4T< ValueT > >( *this, rhs, sdw::makeAssign );
			}
			else
			{
				Value::operator=( rhs );
			}
		}

		return *this;
	}

	//*********************************************************************************************
}
