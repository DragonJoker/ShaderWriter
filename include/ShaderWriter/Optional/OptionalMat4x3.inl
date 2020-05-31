/*
See LICENSE file in root folder
*/
namespace sdw
{
	template< typename ValueT >
	Optional< Mat4x3T< ValueT > >::Optional( Shader * shader
		, expr::ExprPtr expr
		, bool enabled )
		: Mat4x3T< ValueT >{ shader, std::move( expr ) }
		, m_enabled{ enabled }
	{
	}

	template< typename ValueT >
	Optional< Mat4x3T< ValueT > >::Optional( Mat4x3T< ValueT > const & rhs
		, bool enabled )
		: Mat4x3T< ValueT >{ rhs }
		, m_enabled{ enabled }
	{
	}

	template< typename ValueT >
	Optional< Mat4x3T< ValueT > >::Optional( Optional< Mat4x3T< ValueT > > const & rhs )
		: Mat4x3T< ValueT >{ rhs }
		, m_enabled{ rhs.m_enabled }
	{
	}

	template< typename ValueT >
	inline Optional< Mat4x3T< ValueT > > & Optional< Mat4x3T< ValueT > >::operator=( Mat4x3T< ValueT > const & rhs )
	{
		if ( isEnabled() )
		{
			Mat4x3T< ValueT >::operator=( rhs );
		}

		return *this;
	}

	template< typename ValueT >
	inline Optional< Mat4x3T< ValueT > > & Optional< Mat4x3T< ValueT > >::operator=( Optional< Mat4x3T< ValueT > > const & rhs )
	{
		if ( isEnabled() && rhs.isEnabled() )
		{
			Mat4x3T< ValueT >::operator=( rhs );
		}

		return *this;
	}

	template< typename ValueT >
	template< typename IndexT >
	Optional< Vec3T< ValueT > > Optional< Mat4x3T< ValueT > >::operator[]( IndexT const & offset )const
	{
		return writeBinOperator< Vec3T< ValueT > >( *this, offset, sdw::makeArrayAccess );
	}

	template< typename ValueT >
	inline bool Optional< Mat4x3T< ValueT > >::isEnabled()const
	{
		return m_enabled;
	}

	//*********************************************************************************************

	template< typename ValueT >
	inline Mat4x3T< ValueT > & Mat4x3T< ValueT >::operator=( Optional< Mat4x3T< ValueT > > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			if ( this->getContainer() )
			{
				writeAssignOperator< Mat4x3T< ValueT > >( *this, rhs, sdw::makeAssign );
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
