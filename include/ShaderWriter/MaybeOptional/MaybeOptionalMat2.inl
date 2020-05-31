/*
See LICENSE file in root folder
*/
#include "MaybeOptionalMat2.hpp"

namespace sdw
{
	//*************************************************************************

	template< typename ValueT >
	MaybeOptional< Mat2T< ValueT > >::MaybeOptional( Shader * shader
		, expr::ExprPtr expr )
		: Mat2T< ValueT >{ shader, std::move( expr ) }
		, m_optional{ false }
		, m_enabled{ true }
	{
	}

	template< typename ValueT >
	MaybeOptional< Mat2T< ValueT > >::MaybeOptional( Shader * shader
		, expr::ExprPtr expr
		, bool enabled )
		: Mat2T< ValueT >{ shader, std::move( expr ) }
		, m_optional{ true }
		, m_enabled{ enabled }
	{
	}

	template< typename ValueT >
	inline MaybeOptional< Mat2T< ValueT > >::MaybeOptional( Mat2T< ValueT > const & rhs )
		: Mat2T< ValueT >{ rhs }
		, m_optional{ false }
		, m_enabled{ true }
	{
	}

	template< typename ValueT >
	inline MaybeOptional< Mat2T< ValueT > >::MaybeOptional( Optional< Mat2T< ValueT > > const & rhs )
		: Mat2T< ValueT >{ rhs }
		, m_optional{ true }
		, m_enabled{ rhs.isEnabled() }
	{
	}

	template< typename ValueT >
	MaybeOptional< Mat2T< ValueT > >::MaybeOptional( MaybeOptional< Mat2T< ValueT > > const & rhs )
		: Mat2T< ValueT >{ rhs }
		, m_optional{ rhs.isOptional() }
		, m_enabled{ rhs.isEnabled() }
	{
	}

	template< typename ValueT >
	inline MaybeOptional< Mat2T< ValueT > > & MaybeOptional< Mat2T< ValueT > >::operator=( Mat2T< ValueT > const & rhs )
	{
		if ( isEnabled() )
		{
			Mat2T< ValueT >::operator=( rhs );
		}

		return *this;
	}

	template< typename ValueT >
	inline MaybeOptional< Mat2T< ValueT > > & MaybeOptional< Mat2T< ValueT > >::operator=( Optional< Mat2T< ValueT > > const & rhs )
	{
		if ( isEnabled() && rhs.isEnabled() )
		{
			Mat2T< ValueT >::operator=( rhs );
		}

		return *this;
	}

	template< typename ValueT >
	inline MaybeOptional< Mat2T< ValueT > > & MaybeOptional< Mat2T< ValueT > >::operator=( MaybeOptional< Mat2T< ValueT > > const & rhs )
	{
		if ( isEnabled() && rhs.isEnabled() )
		{
			Mat2T< ValueT >::operator=( rhs );
		}

		return *this;
	}

	template< typename ValueT >
	template< typename IndexT >
	MaybeOptional< Vec2T< ValueT > > MaybeOptional< Mat2T< ValueT > >::operator[]( IndexT const & offset )const
	{
		return writeBinOperator< Vec2T< ValueT > >( *this, offset, sdw::makeArrayAccess );
	}

	template< typename ValueT >
	inline MaybeOptional< Mat2T< ValueT > >::operator Mat2T< ValueT >()const
	{
		return *this;
	}

	template< typename ValueT >
	inline MaybeOptional< Mat2T< ValueT > >::operator Optional< Mat2T< ValueT > >()const
	{
		return Optional< Mat2T< ValueT > >{ *this
			, m_enabled };
	}

	template< typename ValueT >
	inline bool MaybeOptional< Mat2T< ValueT > >::isOptional()const
	{
		return m_optional;
	}

	template< typename ValueT >
	inline bool MaybeOptional< Mat2T< ValueT > >::isEnabled()const
	{
		return m_enabled;
	}

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
	inline Optional< Mat2T< ValueT > > & Optional< Mat2T< ValueT > >::operator=( MaybeOptional< Mat2T< ValueT > > const & rhs )
	{
		if ( isEnabled() && rhs.isEnabled() )
		{
			Mat2T< ValueT >::operator=( rhs );
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
