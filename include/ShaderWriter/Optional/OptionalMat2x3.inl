/*
See LICENSE file in root folder
*/
namespace sdw
{
	template< typename ValueT >
	Optional< Mat2x3T< ValueT > >::Optional( Shader * shader
		, expr::ExprPtr expr
		, bool enabled )
		: Mat2x3T< ValueT >{ shader, std::move( expr ) }
		, m_enabled{ enabled }
	{
	}

	template< typename ValueT >
	Optional< Mat2x3T< ValueT > >::Optional( Mat2x3T< ValueT > const & rhs
		, bool enabled )
		: Mat2x3T< ValueT >{ rhs }
		, m_enabled{ enabled }
	{
	}

	template< typename ValueT >
	Optional< Mat2x3T< ValueT > >::Optional( Optional< Mat2x3T< ValueT > > const & rhs )
		: Mat2x3T< ValueT >{ rhs }
		, m_enabled{ rhs.m_enabled }
	{
	}

	template< typename ValueT >
	inline Optional< Mat2x3T< ValueT > > & Optional< Mat2x3T< ValueT > >::operator=( Mat2x3T< ValueT > const & rhs )
	{
		if ( isEnabled() )
		{
			Mat2x3T< ValueT >::operator=( rhs );
		}

		return *this;
	}

	template< typename ValueT >
	inline Optional< Mat2x3T< ValueT > > & Optional< Mat2x3T< ValueT > >::operator=( Optional< Mat2x3T< ValueT > > const & rhs )
	{
		if ( isEnabled() && rhs.isEnabled() )
		{
			Mat2x3T< ValueT >::operator=( rhs );
		}

		return *this;
	}

	template< typename ValueT >
	template< typename IndexT >
	Optional< Vec3T< ValueT > > Optional< Mat2x3T< ValueT > >::operator[]( IndexT const & offset )const
	{
		return writeBinOperator< Vec3T< ValueT > >( *this, offset, sdw::makeArrayAccess );
	}

	template< typename ValueT >
	inline bool Optional< Mat2x3T< ValueT > >::isEnabled()const
	{
		return m_enabled;
	}

	//*********************************************************************************************

	template< typename ValueT >
	inline Mat2x3T< ValueT > & Mat2x3T< ValueT >::operator=( Optional< Mat2x3T< ValueT > > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			if ( this->getContainer() )
			{
				writeAssignOperator< Mat2x3T< ValueT > >( *this, rhs, sdw::makeAssign );
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
