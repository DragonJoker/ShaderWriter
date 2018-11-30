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
	MaybeOptional< Mat4T< ValueT > > & MaybeOptional< Mat4T< ValueT > >::operator=( MaybeOptional< Mat4T< ValueT > > const & rhs )
	{
		if ( areOptionalEnabled( *this, rhs ) )
		{
			addStmt( *findContainer( *this, rhs )
				, sdw::makeSimple( sdw::makeAssign( this->getType()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	template< typename ValueT >
	template< typename IndexT >
	MaybeOptional< Vec4T< ValueT > > MaybeOptional< Mat4T< ValueT > >::operator[]( IndexT const & rhs )const
	{
		if ( isAnyOptional( *this, rhs ) )
		{
			return MaybeOptional< Vec4T< ValueT > >{ findShader( *this, rhs )
				, sdw::makeArrayAccess( makeType( typeEnum< Vec4T< ValueT > > )
					, makeExpr( *this, true )
					, makeExpr( rhs ) )
				, areOptionalEnabled( *this, rhs ) };
		}

		return MaybeOptional< Vec4T< ValueT > >{ findShader( *this, rhs )
			, sdw::makeArrayAccess( makeType( typeEnum< Vec4T< ValueT > > )
				, makeExpr( *this )
				, makeExpr( rhs ) ) };
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
	MaybeOptional< Vec4T< ValueT > > operator*( MaybeOptional< Vec4T< ValueT > > const & lhs,
		Mat4T< ValueT > const & rhs )
	{
		if ( isAnyOptional( lhs, rhs ) )
		{
			return MaybeOptional< Vec4T< ValueT > >{ findShader( lhs, rhs )
				, sdw::makeTimes( makeType( typeEnum< Vec4T< ValueT > > )
					, makeExpr( lhs, true )
					, makeExpr( rhs ) )
				, areOptionalEnabled( lhs, rhs ) };
		}

		return MaybeOptional< Vec4T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeTimes( makeType( typeEnum< Vec4T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	MaybeOptional< Vec4T< ValueT > > operator*( MaybeOptional< Mat4T< ValueT > > const & lhs
		, Vec4T< ValueT > const & rhs )
	{
		if ( isAnyOptional( lhs, rhs ) )
		{
			return MaybeOptional< Vec4T< ValueT > >{ findShader( lhs, rhs )
				, sdw::makeTimes( makeType( typeEnum< Vec4T< ValueT > > )
					, makeExpr( lhs, true )
					, makeExpr( rhs ) )
				, areOptionalEnabled( lhs, rhs ) };
		}

		return MaybeOptional< Vec4T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeTimes( makeType( typeEnum< Vec4T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	MaybeOptional< Mat4T< ValueT > > operator*( MaybeOptional< Mat4T< ValueT > > const & lhs
		, Mat4T< ValueT > const & rhs )
	{
		if ( isAnyOptional( lhs, rhs ) )
		{
			return MaybeOptional< Mat4T< ValueT > >{ findShader( lhs, rhs )
				, sdw::makeTimes( makeType( typeEnum< Mat4T< ValueT > > )
					, makeExpr( lhs, true )
					, makeExpr( rhs ) )
				, areOptionalEnabled( lhs, rhs ) };
		}

		return MaybeOptional< Mat4T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeTimes( makeType( typeEnum< Mat4T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	MaybeOptional< Vec4T< ValueT > > operator*( Vec4T< ValueT > const & lhs
		, MaybeOptional< Mat4T< ValueT > > const & rhs )
	{
		if ( isAnyOptional( lhs, rhs ) )
		{
			return MaybeOptional< Vec4T< ValueT > >{ findShader( lhs, rhs )
				, sdw::makeTimes( makeType( typeEnum< Vec4T< ValueT > > )
					, makeExpr( lhs, true )
					, makeExpr( rhs ) )
				, areOptionalEnabled( lhs, rhs ) };
		}

		return MaybeOptional< Vec4T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeTimes( makeType( typeEnum< Vec4T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	MaybeOptional< Vec4T< ValueT > > operator*( Mat4T< ValueT > const & lhs
		, MaybeOptional< Vec4T< ValueT > > const & rhs )
	{
		if ( isAnyOptional( lhs, rhs ) )
		{
			return MaybeOptional< Vec4T< ValueT > >{ findShader( lhs, rhs )
				, sdw::makeTimes( makeType( typeEnum< Vec4T< ValueT > > )
					, makeExpr( lhs, true )
					, makeExpr( rhs ) )
				, areOptionalEnabled( lhs, rhs ) };
		}

		return MaybeOptional< Vec4T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeTimes( makeType( typeEnum< Vec4T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	MaybeOptional< Mat4T< ValueT > > operator*( Mat4T< ValueT > const & lhs
		, MaybeOptional< Mat4T< ValueT > > const & rhs )
	{
		if ( isAnyOptional( lhs, rhs ) )
		{
			return MaybeOptional< Mat4T< ValueT > >{ findShader( lhs, rhs )
				, sdw::makeTimes( makeType( typeEnum< Mat4T< ValueT > > )
					, makeExpr( lhs, true )
					, makeExpr( rhs ) )
				, areOptionalEnabled( lhs, rhs ) };
		}

		return MaybeOptional< Mat4T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeTimes( makeType( typeEnum< Mat4T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	MaybeOptional< Vec4T< ValueT > > operator*( MaybeOptional< Vec4T< ValueT > > const & lhs
		, MaybeOptional< Mat4T< ValueT > > const & rhs )
	{
		if ( isAnyOptional( lhs, rhs ) )
		{
			return MaybeOptional< Vec4T< ValueT > >{ findShader( lhs, rhs )
				, sdw::makeTimes( makeType( typeEnum< Vec4T< ValueT > > )
					, makeExpr( lhs, true )
					, makeExpr( rhs ) )
				, areOptionalEnabled( lhs, rhs ) };
		}

		return MaybeOptional< Vec4T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeTimes( makeType( typeEnum< Vec4T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	MaybeOptional< Vec4T< ValueT > > operator*( MaybeOptional< Mat4T< ValueT > > const & lhs
		, MaybeOptional< Vec4T< ValueT > > const & rhs )
	{
		if ( isAnyOptional( lhs, rhs ) )
		{
			return MaybeOptional< Vec4T< ValueT > >{ findShader( lhs, rhs )
				, sdw::makeTimes( makeType( typeEnum< Vec4T< ValueT > > )
					, makeExpr( lhs, true )
					, makeExpr( rhs ) )
				, areOptionalEnabled( lhs, rhs ) };
		}

		return MaybeOptional< Vec4T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeTimes( makeType( typeEnum< Vec4T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	MaybeOptional< Mat4T< ValueT > > operator*( MaybeOptional< Mat4T< ValueT > > const & lhs
		, MaybeOptional< Mat4T< ValueT > > const & rhs )
	{
		if ( isAnyOptional( lhs, rhs ) )
		{
			return MaybeOptional< Mat4T< ValueT > >{ findShader( lhs, rhs )
				, sdw::makeTimes( makeType( typeEnum< Mat4T< ValueT > > )
					, makeExpr( lhs, true )
					, makeExpr( rhs ) )
				, areOptionalEnabled( lhs, rhs ) };
		}

		return MaybeOptional< Mat4T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeTimes( makeType( typeEnum< Mat4T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	MaybeOptional< Mat4T< ValueT > > operator*( MaybeOptional< ValueT > const & lhs
		, Mat4T< ValueT > const & rhs )
	{
		if ( isAnyOptional( lhs, rhs ) )
		{
			return MaybeOptional< Mat4T< ValueT > >{ findShader( lhs, rhs )
				, sdw::makeTimes( makeType( typeEnum< Mat4T< ValueT > > )
					, makeExpr( lhs, true )
					, makeExpr( rhs ) )
				, areOptionalEnabled( lhs, rhs ) };
		}

		return MaybeOptional< Mat4T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeTimes( makeType( typeEnum< Mat4T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	MaybeOptional< Mat4T< ValueT > > operator*( MaybeOptional< Mat4T< ValueT > > const & lhs
		, ValueT const & rhs )
	{
		if ( isAnyOptional( lhs, rhs ) )
		{
			return MaybeOptional< Mat4T< ValueT > >{ findShader( lhs, rhs )
				, sdw::makeTimes( makeType( typeEnum< Mat4T< ValueT > > )
					, makeExpr( lhs, true )
					, makeExpr( rhs ) )
				, areOptionalEnabled( lhs, rhs ) };
		}

		return MaybeOptional< Mat4T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeTimes( makeType( typeEnum< Mat4T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	MaybeOptional< Mat4T< ValueT > > operator*( ValueT const & lhs
		, MaybeOptional< Mat4T< ValueT > > const & rhs )
	{
		if ( isAnyOptional( lhs, rhs ) )
		{
			return MaybeOptional< Mat4T< ValueT > >{ findShader( lhs, rhs )
				, sdw::makeTimes( makeType( typeEnum< Mat4T< ValueT > > )
					, makeExpr( lhs )
					, makeExpr( rhs, true ) )
				, areOptionalEnabled( lhs, rhs ) };
		}

		return MaybeOptional< Mat4T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeTimes( makeType( typeEnum< Mat4T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	MaybeOptional< Mat4T< ValueT > > operator*( Mat4T< ValueT > const & lhs
		, MaybeOptional< ValueT > const & rhs )
	{
		if ( isAnyOptional( lhs, rhs ) )
		{
			return MaybeOptional< Mat4T< ValueT > >{ findShader( lhs, rhs )
				, sdw::makeTimes( makeType( typeEnum< Mat4T< ValueT > > )
					, makeExpr( lhs )
					, makeExpr( rhs, true ) )
				, areOptionalEnabled( lhs, rhs ) };
		}

		return MaybeOptional< Mat4T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeTimes( makeType( typeEnum< Mat4T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	MaybeOptional< Mat4T< ValueT > > operator*( MaybeOptional< ValueT > const & lhs
		, MaybeOptional< Mat4T< ValueT > > const & rhs )
	{
		if ( isAnyOptional( lhs, rhs ) )
		{
			return MaybeOptional< Mat4T< ValueT > >{ findShader( lhs, rhs )
				, sdw::makeTimes( makeType( typeEnum< Mat4T< ValueT > > )
					, makeExpr( lhs, true )
					, makeExpr( rhs, true ) )
				, areOptionalEnabled( lhs, rhs ) };
		}

		return MaybeOptional< Mat4T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeTimes( makeType( typeEnum< Mat4T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	MaybeOptional< Mat4T< ValueT > > operator*( MaybeOptional< Mat4T< ValueT > > const & lhs
		, MaybeOptional< ValueT > const & rhs )
	{
		if ( isAnyOptional( lhs, rhs ) )
		{
			return MaybeOptional< Mat4T< ValueT > >{ findShader( lhs, rhs )
				, sdw::makeTimes( makeType( typeEnum< Mat4T< ValueT > > )
					, makeExpr( lhs, true )
					, makeExpr( rhs, true ) )
				, areOptionalEnabled( lhs, rhs ) };
		}

		return MaybeOptional< Mat4T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeTimes( makeType( typeEnum< Mat4T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	//*************************************************************************
}
