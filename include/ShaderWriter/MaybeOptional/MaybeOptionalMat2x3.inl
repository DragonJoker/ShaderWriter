/*
See LICENSE file in root folder
*/
#include "MaybeOptionalMat2x3.hpp"

namespace sdw
{
	template< typename ValueT >
	MaybeOptional< Mat2x3T< ValueT > >::MaybeOptional( Shader * shader
		, expr::ExprPtr expr )
		: Mat2x3T< ValueT >{ shader, std::move( expr ) }
		, m_optional{ false }
		, m_enabled{ true }
	{
	}

	template< typename ValueT >
	MaybeOptional< Mat2x3T< ValueT > >::MaybeOptional( Shader * shader
		, expr::ExprPtr expr
		, bool enabled )
		: Mat2x3T< ValueT >{ shader, std::move( expr ) }
		, m_optional{ true }
		, m_enabled{ enabled }
	{
	}

	template< typename ValueT >
	inline MaybeOptional< Mat2x3T< ValueT > >::MaybeOptional( Mat2x3T< ValueT > const & rhs )
		: Mat2x3T< ValueT >{ rhs }
		, m_optional{ false }
		, m_enabled{ true }
	{
	}

	template< typename ValueT >
	inline MaybeOptional< Mat2x3T< ValueT > >::MaybeOptional( Optional< Mat2x3T< ValueT > > const & rhs )
		: Mat2x3T< ValueT >{ rhs }
		, m_optional{ true }
		, m_enabled{ rhs.isEnabled() }
	{
	}

	template< typename ValueT >
	MaybeOptional< Mat2x3T< ValueT > >::MaybeOptional( MaybeOptional< Mat2x3T< ValueT > > const & rhs )
		: Mat2x3T< ValueT >{ rhs }
		, m_optional{ rhs.isOptional() }
		, m_enabled{ rhs.isEnabled() }
	{
	}

	template< typename ValueT >
	MaybeOptional< Mat2x3T< ValueT > > & MaybeOptional< Mat2x3T< ValueT > >::operator=( MaybeOptional< Mat2x3T< ValueT > > const & rhs )
	{
		if ( areOptionalEnabled( *this, rhs ) )
		{
			addStmt( *findShader( *this, rhs )
				, sdw::makeSimple( sdw::makeAssign( this->getType()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	template< typename ValueT >
	template< typename IndexT >
	MaybeOptional< Vec3T< ValueT > > MaybeOptional< Mat2x3T< ValueT > >::operator[]( IndexT const & rhs )const
	{
		if ( isAnyOptional( *this, rhs ) )
		{
			return MaybeOptional< Vec3T< ValueT > >{ findShader( *this, rhs )
				, sdw::makeArrayAccess( Vec3T< ValueT >::makeType( findTypesCache( *this, rhs ) )
					, makeExpr( *this, true )
					, makeExpr( rhs ) )
				, areOptionalEnabled( *this, rhs ) };
		}

		return MaybeOptional< Vec3T< ValueT > >{ findShader( *this, rhs )
			, sdw::makeArrayAccess( Vec3T< ValueT >::makeType( findTypesCache( *this, rhs ) )
				, makeExpr( *this )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline MaybeOptional< Mat2x3T< ValueT > >::operator Mat2x3T< ValueT >()const
	{
		return *this;
	}

	template< typename ValueT >
	inline MaybeOptional< Mat2x3T< ValueT > >::operator Optional< Mat2x3T< ValueT > >()const
	{
		return Optional< Mat2x3T< ValueT > >{ *this
			, m_enabled };
	}

	template< typename ValueT >
	inline bool MaybeOptional< Mat2x3T< ValueT > >::isOptional()const
	{
		return m_optional;
	}

	template< typename ValueT >
	inline bool MaybeOptional< Mat2x3T< ValueT > >::isEnabled()const
	{
		return m_enabled;
	}
}
