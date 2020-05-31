/*
See LICENSE file in root folder
*/
#include "MaybeOptionalMat4.hpp"

namespace sdw
{
	//*************************************************************************

	template< typename ValueT >
	MaybeOptional< Mat4T< ValueT > >::MaybeOptional( Shader * shader
		, expr::ExprPtr expr )
		: Mat4T< ValueT >{ shader, std::move( expr ) }
		, m_optional{ false }
		, m_enabled{ true }
	{
	}

	template< typename ValueT >
	MaybeOptional< Mat4T< ValueT > >::MaybeOptional( Shader * shader
		, expr::ExprPtr expr
		, bool enabled )
		: Mat4T< ValueT >{ shader, std::move( expr ) }
		, m_optional{ true }
		, m_enabled{ enabled }
	{
	}

	template< typename ValueT >
	inline MaybeOptional< Mat4T< ValueT > >::MaybeOptional( Mat4T< ValueT > const & rhs )
		: Mat4T< ValueT >{ rhs }
		, m_optional{ false }
		, m_enabled{ true }
	{
	}

	template< typename ValueT >
	inline MaybeOptional< Mat4T< ValueT > >::MaybeOptional( Optional< Mat4T< ValueT > > const & rhs )
		: Mat4T< ValueT >{ rhs }
		, m_optional{ true }
		, m_enabled{ rhs.isEnabled() }
	{
	}

	template< typename ValueT >
	MaybeOptional< Mat4T< ValueT > >::MaybeOptional( MaybeOptional< Mat4T< ValueT > > const & rhs )
		: Mat4T< ValueT >{ rhs }
		, m_optional{ rhs.isOptional() }
		, m_enabled{ rhs.isEnabled() }
	{
	}

	template< typename ValueT >
	inline MaybeOptional< Mat4T< ValueT > > & MaybeOptional< Mat4T< ValueT > >::operator=( Mat4T< ValueT > const & rhs )
	{
		if ( isEnabled() )
		{
			Mat4T< ValueT >::operator=( rhs );
		}

		return *this;
	}

	template< typename ValueT >
	inline MaybeOptional< Mat4T< ValueT > > & MaybeOptional< Mat4T< ValueT > >::operator=( Optional< Mat4T< ValueT > > const & rhs )
	{
		if ( isEnabled() && rhs.isEnabled() )
		{
			Mat4T< ValueT >::operator=( rhs );
		}

		return *this;
	}

	template< typename ValueT >
	inline MaybeOptional< Mat4T< ValueT > > & MaybeOptional< Mat4T< ValueT > >::operator=( MaybeOptional< Mat4T< ValueT > > const & rhs )
	{
		if ( isEnabled() && rhs.isEnabled() )
		{
			Mat4T< ValueT >::operator=( rhs );
		}

		return *this;
	}

	template< typename ValueT >
	template< typename IndexT >
	MaybeOptional< Vec4T< ValueT > > MaybeOptional< Mat4T< ValueT > >::operator[]( IndexT const & offset )const
	{
		return writeBinOperator< Vec4T< ValueT > >( *this, offset, sdw::makeArrayAccess );
	}

	template< typename ValueT >
	inline MaybeOptional< Mat4T< ValueT > >::operator Mat4T< ValueT >()const
	{
		return *this;
	}

	template< typename ValueT >
	inline MaybeOptional< Mat4T< ValueT > >::operator Optional< Mat4T< ValueT > >()const
	{
		return Optional< Mat4T< ValueT > >{ *this
			, m_enabled };
	}

	template< typename ValueT >
	inline bool MaybeOptional< Mat4T< ValueT > >::isOptional()const
	{
		return m_optional;
	}

	template< typename ValueT >
	inline bool MaybeOptional< Mat4T< ValueT > >::isEnabled()const
	{
		return m_enabled;
	}

	//*************************************************************************

	template< typename ValueT >
	inline Mat4T< ValueT > & Mat4T< ValueT >::operator=( MaybeOptional< Mat4T< ValueT > > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			if ( this->getContainer() )
			{
				writeAssignOperator< Mat4T< ValueT > >( *this, rhs, sdw::makeAssign );
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
	inline Optional< Mat4T< ValueT > > & Optional< Mat4T< ValueT > >::operator=( MaybeOptional< Mat4T< ValueT > > const & rhs )
	{
		if ( isEnabled() && rhs.isEnabled() )
		{
			Mat4T< ValueT >::operator=( rhs );
		}

		return *this;
	}

	//*************************************************************************

	template< typename ValueT >
	MaybeOptional< Vec4T< ValueT > > operator*( MaybeOptional< Vec4T< ValueT > > const & lhs,
		Mat4T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Vec4T< ValueT > > operator*( MaybeOptional< Mat4T< ValueT > > const & lhs
		, Vec4T< ValueT > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Mat4T< ValueT > > operator*( MaybeOptional< Mat4T< ValueT > > const & lhs
		, Mat4T< ValueT > const & rhs )
	{
		return writeBinOperator< Mat4T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Vec4T< ValueT > > operator*( Vec4T< ValueT > const & lhs
		, MaybeOptional< Mat4T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Vec4T< ValueT > > operator*( Mat4T< ValueT > const & lhs
		, MaybeOptional< Vec4T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Mat4T< ValueT > > operator*( Mat4T< ValueT > const & lhs
		, MaybeOptional< Mat4T< ValueT > > const & rhs )
	{
		return writeBinOperator< Mat4T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Vec4T< ValueT > > operator*( MaybeOptional< Vec4T< ValueT > > const & lhs
		, MaybeOptional< Mat4T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Vec4T< ValueT > > operator*( MaybeOptional< Mat4T< ValueT > > const & lhs
		, MaybeOptional< Vec4T< ValueT > > const & rhs )
	{
		return writeBinOperator< Vec4T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Mat4T< ValueT > > operator*( MaybeOptional< Mat4T< ValueT > > const & lhs
		, MaybeOptional< Mat4T< ValueT > > const & rhs )
	{
		return writeBinOperator< Mat4T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Mat4T< ValueT > > operator*( MaybeOptional< ValueT > const & lhs
		, Mat4T< ValueT > const & rhs )
	{
		return writeBinOperator< Mat4T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Mat4T< ValueT > > operator*( MaybeOptional< Mat4T< ValueT > > const & lhs
		, ValueT const & rhs )
	{
		return writeBinOperator< Mat4T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Mat4T< ValueT > > operator*( ValueT const & lhs
		, MaybeOptional< Mat4T< ValueT > > const & rhs )
	{
		return writeBinOperator< Mat4T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Mat4T< ValueT > > operator*( Mat4T< ValueT > const & lhs
		, MaybeOptional< ValueT > const & rhs )
	{
		return writeBinOperator< Mat4T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Mat4T< ValueT > > operator*( MaybeOptional< ValueT > const & lhs
		, MaybeOptional< Mat4T< ValueT > > const & rhs )
	{
		return writeBinOperator< Mat4T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	template< typename ValueT >
	MaybeOptional< Mat4T< ValueT > > operator*( MaybeOptional< Mat4T< ValueT > > const & lhs
		, MaybeOptional< ValueT > const & rhs )
	{
		return writeBinOperator< Mat4T< ValueT > >( lhs, rhs, sdw::makeTimes );
	}

	//*************************************************************************
}
