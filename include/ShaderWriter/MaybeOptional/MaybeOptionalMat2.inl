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
	MaybeOptional< Mat2T< ValueT > > & MaybeOptional< Mat2T< ValueT > >::operator=( MaybeOptional< Mat2T< ValueT > > const & rhs )
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
	MaybeOptional< Vec2T< ValueT > > MaybeOptional< Mat2T< ValueT > >::operator[]( IndexT const & rhs )const
	{
		if ( isAnyOptional( *this, rhs ) )
		{
			return MaybeOptional< Vec2T< ValueT > >{ findShader( *this, rhs )
				, sdw::makeArrayAccess( Vec2T< ValueT >::makeType()
					, makeExpr( *this, true )
					, makeExpr( rhs ) )
				, areOptionalEnabled( *this, rhs ) };
		}

		return MaybeOptional< Vec2T< ValueT > >{ findShader( *this, rhs )
			, sdw::makeArrayAccess( Vec2T< ValueT >::makeType()
				, makeExpr( *this )
				, makeExpr( rhs ) ) };
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
	MaybeOptional< Vec2T< ValueT > > operator*( MaybeOptional< Vec2T< ValueT > > const & lhs,
		Mat2T< ValueT > const & rhs )
	{
		if ( isAnyOptional( lhs, rhs ) )
		{
			return MaybeOptional< Vec2T< ValueT > >{ findShader( lhs, rhs )
				, sdw::makeTimes( Vec2T< ValueT >::makeType()
					, makeExpr( lhs, true )
					, makeExpr( rhs ) )
				, areOptionalEnabled( lhs, rhs ) };
		}

		return MaybeOptional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeTimes( Vec2T< ValueT >::makeType()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	MaybeOptional< Vec2T< ValueT > > operator*( MaybeOptional< Mat2T< ValueT > > const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		if ( isAnyOptional( lhs, rhs ) )
		{
			return MaybeOptional< Vec2T< ValueT > >{ findShader( lhs, rhs )
				, sdw::makeTimes( Vec2T< ValueT >::makeType()
					, makeExpr( lhs, true )
					, makeExpr( rhs ) )
				, areOptionalEnabled( lhs, rhs ) };
		}

		return MaybeOptional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeTimes( Vec2T< ValueT >::makeType()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	MaybeOptional< Mat2T< ValueT > > operator*( MaybeOptional< Mat2T< ValueT > > const & lhs
		, Mat2T< ValueT > const & rhs )
	{
		if ( isAnyOptional( lhs, rhs ) )
		{
			return MaybeOptional< Mat2T< ValueT > >{ findShader( lhs, rhs )
				, sdw::makeTimes( Mat2T< ValueT >::makeType()
					, makeExpr( lhs, true )
					, makeExpr( rhs ) )
				, areOptionalEnabled( lhs, rhs ) };
		}

		return MaybeOptional< Mat2T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeTimes( Mat2T< ValueT >::makeType()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	MaybeOptional< Vec2T< ValueT > > operator*( Vec2T< ValueT > const & lhs
		, MaybeOptional< Mat2T< ValueT > > const & rhs )
	{
		if ( isAnyOptional( lhs, rhs ) )
		{
			return MaybeOptional< Vec2T< ValueT > >{ findShader( lhs, rhs )
				, sdw::makeTimes( Vec2T< ValueT >::makeType()
					, makeExpr( lhs, true )
					, makeExpr( rhs ) )
				, areOptionalEnabled( lhs, rhs ) };
		}

		return MaybeOptional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeTimes( Vec2T< ValueT >::makeType()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	MaybeOptional< Vec2T< ValueT > > operator*( Mat2T< ValueT > const & lhs
		, MaybeOptional< Vec2T< ValueT > > const & rhs )
	{
		if ( isAnyOptional( lhs, rhs ) )
		{
			return MaybeOptional< Vec2T< ValueT > >{ findShader( lhs, rhs )
				, sdw::makeTimes( Vec2T< ValueT >::makeType()
					, makeExpr( lhs, true )
					, makeExpr( rhs ) )
				, areOptionalEnabled( lhs, rhs ) };
		}

		return MaybeOptional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeTimes( Vec2T< ValueT >::makeType()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	MaybeOptional< Mat2T< ValueT > > operator*( Mat2T< ValueT > const & lhs
		, MaybeOptional< Mat2T< ValueT > > const & rhs )
	{
		if ( isAnyOptional( lhs, rhs ) )
		{
			return MaybeOptional< Mat2T< ValueT > >{ findShader( lhs, rhs )
				, sdw::makeTimes( Mat2T< ValueT >::makeType()
					, makeExpr( lhs, true )
					, makeExpr( rhs ) )
				, areOptionalEnabled( lhs, rhs ) };
		}

		return MaybeOptional< Mat2T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeTimes( Mat2T< ValueT >::makeType()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	MaybeOptional< Vec2T< ValueT > > operator*( MaybeOptional< Vec2T< ValueT > > const & lhs
		, MaybeOptional< Mat2T< ValueT > > const & rhs )
	{
		if ( isAnyOptional( lhs, rhs ) )
		{
			return MaybeOptional< Vec2T< ValueT > >{ findShader( lhs, rhs )
				, sdw::makeTimes( Vec2T< ValueT >::makeType()
					, makeExpr( lhs, true )
					, makeExpr( rhs ) )
				, areOptionalEnabled( lhs, rhs ) };
		}

		return MaybeOptional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeTimes( Vec2T< ValueT >::makeType()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	MaybeOptional< Vec2T< ValueT > > operator*( MaybeOptional< Mat2T< ValueT > > const & lhs
		, MaybeOptional< Vec2T< ValueT > > const & rhs )
	{
		if ( isAnyOptional( lhs, rhs ) )
		{
			return MaybeOptional< Vec2T< ValueT > >{ findShader( lhs, rhs )
				, sdw::makeTimes( Vec2T< ValueT >::makeType()
					, makeExpr( lhs, true )
					, makeExpr( rhs ) )
				, areOptionalEnabled( lhs, rhs ) };
		}

		return MaybeOptional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeTimes( Vec2T< ValueT >::makeType()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	MaybeOptional< Mat2T< ValueT > > operator*( MaybeOptional< Mat2T< ValueT > > const & lhs
		, MaybeOptional< Mat2T< ValueT > > const & rhs )
	{
		if ( isAnyOptional( lhs, rhs ) )
		{
			return MaybeOptional< Mat2T< ValueT > >{ findShader( lhs, rhs )
				, sdw::makeTimes( Mat2T< ValueT >::makeType()
					, makeExpr( lhs, true )
					, makeExpr( rhs ) )
				, areOptionalEnabled( lhs, rhs ) };
		}

		return MaybeOptional< Mat2T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeTimes( Mat2T< ValueT >::makeType()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	MaybeOptional< Mat2T< ValueT > > operator*( MaybeOptional< ValueT > const & lhs
		, Mat2T< ValueT > const & rhs )
	{
		if ( isAnyOptional( lhs, rhs ) )
		{
			return MaybeOptional< Mat2T< ValueT > >{ findShader( lhs, rhs )
				, sdw::makeTimes( Mat2T< ValueT >::makeType()
					, makeExpr( lhs, true )
					, makeExpr( rhs ) )
				, areOptionalEnabled( lhs, rhs ) };
		}

		return MaybeOptional< Mat2T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeTimes( Mat2T< ValueT >::makeType()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	MaybeOptional< Mat2T< ValueT > > operator*( MaybeOptional< Mat2T< ValueT > > const & lhs
		, ValueT const & rhs )
	{
		if ( isAnyOptional( lhs, rhs ) )
		{
			return MaybeOptional< Mat2T< ValueT > >{ findShader( lhs, rhs )
				, sdw::makeTimes( Mat2T< ValueT >::makeType()
					, makeExpr( lhs, true )
					, makeExpr( rhs ) )
				, areOptionalEnabled( lhs, rhs ) };
		}

		return MaybeOptional< Mat2T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeTimes( Mat2T< ValueT >::makeType()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	MaybeOptional< Mat2T< ValueT > > operator*( ValueT const & lhs
		, MaybeOptional< Mat2T< ValueT > > const & rhs )
	{
		if ( isAnyOptional( lhs, rhs ) )
		{
			return MaybeOptional< Mat2T< ValueT > >{ findShader( lhs, rhs )
				, sdw::makeTimes( Mat2T< ValueT >::makeType()
					, makeExpr( lhs )
					, makeExpr( rhs, true ) )
				, areOptionalEnabled( lhs, rhs ) };
		}

		return MaybeOptional< Mat2T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeTimes( Mat2T< ValueT >::makeType()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	MaybeOptional< Mat2T< ValueT > > operator*( Mat2T< ValueT > const & lhs
		, MaybeOptional< ValueT > const & rhs )
	{
		if ( isAnyOptional( lhs, rhs ) )
		{
			return MaybeOptional< Mat2T< ValueT > >{ findShader( lhs, rhs )
				, sdw::makeTimes( Mat2T< ValueT >::makeType()
					, makeExpr( lhs )
					, makeExpr( rhs, true ) )
				, areOptionalEnabled( lhs, rhs ) };
		}

		return MaybeOptional< Mat2T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeTimes( Mat2T< ValueT >::makeType()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	MaybeOptional< Mat2T< ValueT > > operator*( MaybeOptional< ValueT > const & lhs
		, MaybeOptional< Mat2T< ValueT > > const & rhs )
	{
		if ( isAnyOptional( lhs, rhs ) )
		{
			return MaybeOptional< Mat2T< ValueT > >{ findShader( lhs, rhs )
				, sdw::makeTimes( Mat2T< ValueT >::makeType()
					, makeExpr( lhs, true )
					, makeExpr( rhs, true ) )
				, areOptionalEnabled( lhs, rhs ) };
		}

		return MaybeOptional< Mat2T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeTimes( Mat2T< ValueT >::makeType()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	MaybeOptional< Mat2T< ValueT > > operator*( MaybeOptional< Mat2T< ValueT > > const & lhs
		, MaybeOptional< ValueT > const & rhs )
	{
		if ( isAnyOptional( lhs, rhs ) )
		{
			return MaybeOptional< Mat2T< ValueT > >{ findShader( lhs, rhs )
				, sdw::makeTimes( Mat2T< ValueT >::makeType()
					, makeExpr( lhs, true )
					, makeExpr( rhs, true ) )
				, areOptionalEnabled( lhs, rhs ) };
		}

		return MaybeOptional< Mat2T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeTimes( Mat2T< ValueT >::makeType()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	//*************************************************************************
}
