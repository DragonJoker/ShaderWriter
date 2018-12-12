/*
See LICENSE file in root folder
*/
namespace sdw
{
	template< typename ValueT >
	Optional< Mat4x2T< ValueT > >::Optional( Shader * shader
		, expr::ExprPtr expr
		, bool enabled )
		: Mat4x2T< ValueT >{ shader, std::move( expr ) }
		, m_enabled{ enabled }
	{
	}

	template< typename ValueT >
	Optional< Mat4x2T< ValueT > >::Optional( Mat4x2T< ValueT > const & rhs
		, bool enabled )
		: Mat4x2T< ValueT >{ rhs }
		, m_enabled{ enabled }
	{
	}

	template< typename ValueT >
	Optional< Mat4x2T< ValueT > >::Optional( Optional< Mat4x2T< ValueT > > const & rhs )
		: Mat4x2T< ValueT >{ rhs }
		, m_enabled{ rhs.m_enabled }
	{
	}

	template< typename ValueT >
	Optional< Mat4x2T< ValueT > > & Optional< Mat4x2T< ValueT > >::operator=( Optional< Mat4x2T< ValueT > > const & rhs )
	{
		if ( this->getContainer() )
		{
			writeAssignOperator< Mat4x2T< ValueT > >( *this, rhs, sdw::makeAssign );
		}
		else
		{
			Value::operator=( rhs );
		}

		return *this;
	}

	template< typename ValueT >
	template< typename IndexT >
	Optional< Vec2T< ValueT > > Optional< Mat4x2T< ValueT > >::operator[]( IndexT const & offset )const
	{
		return writeBinOperator< Vec2T< ValueT > >( *this, offset, sdw::makeArrayAccess );
	}

	template< typename ValueT >
	inline bool Optional< Mat4x2T< ValueT > >::isEnabled()const
	{
		return m_enabled;
	}
}
