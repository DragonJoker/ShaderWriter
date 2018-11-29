/*
See LICENSE file in root folder
*/
#include "MaybeOptionalVec3.hpp"

namespace sdw
{
	//*************************************************************************

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > >::MaybeOptional( Shader * shader
		, expr::ExprPtr expr )
		: Vec3T< ValueT >{ shader, std::move( expr ) }
		, m_optional{ false }
		, m_enabled{ true }
	{
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > >::MaybeOptional( Shader * shader
		, expr::ExprPtr expr
		, bool enabled )
		: Vec3T< ValueT >{ shader, std::move( expr ) }
		, m_optional{ true }
		, m_enabled{ enabled }
	{
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > >::MaybeOptional( Vec3T< ValueT > const & rhs )
		: Vec3T< ValueT >{ rhs }
		, m_optional{ false }
		, m_enabled{ true }
	{
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > >::MaybeOptional( Optional< Vec3T< ValueT > > const & rhs )
		: Vec3T< ValueT >{ rhs }
		, m_optional{ true }
		, m_enabled{ rhs.isEnabled() }
	{
	}

	template< typename ValueT >
	MaybeOptional< Vec3T< ValueT > >::MaybeOptional( MaybeOptional< Vec3T< ValueT > > const & rhs )
		: Vec3T< ValueT >{ rhs }
		, m_optional{ other.isOptional() }
		, m_enabled{ other.isEnabled() }
	{
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > & MaybeOptional< Vec3T< ValueT > >::operator=( MaybeOptional< Vec3T< ValueT > > const & rhs )
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
	inline MaybeOptional< ValueT > MaybeOptional< Vec3T< ValueT > >::operator[]( IndexT const & rhs )const
	{
		if ( isAnyOptional( *this, rhs ) )
		{
			return MaybeOptional< ValueT >{ findShader( *this, rhs )
				, sdw::makeArrayAccess( makeType( typeEnum< ValueT > )
					, makeExpr( *this, true )
					, makeExpr( rhs ) )
				, areOptionalEnabled( *this, rhs ) };
		}

		return MaybeOptional< ValueT >{ findShader( *this, rhs )
			, sdw::makeArrayAccess( makeType( typeEnum< ValueT > )
				, makeExpr( this->getExpr() )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > >::operator Vec3T< ValueT >()const
	{
		return *this;
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > >::operator Optional< Vec3T< ValueT > >()const
	{
		return Optional< Vec3T< ValueT > >{ *this
			, m_enabled };
	}

	template< typename ValueT >
	inline bool MaybeOptional< Vec3T< ValueT > >::isOptional()const
	{
		return m_optional;
	}

	template< typename ValueT >
	inline bool MaybeOptional< Vec3T< ValueT > >::isEnabled()const
	{
		return m_enabled;
	}

	template< typename ValueT >
	MaybeOptional< Vec3T< ValueT > > & MaybeOptional< Vec3T< ValueT > >::operator+=( Vec3T< ValueT > const & rhs )
	{
		if ( areOptionalEnabled( *this, rhs ) )
		{
			addStmt( *findContainer( *this, rhs )
				, sdw::makeSimple( sdw::makeAddAssign( this->getType()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	template< typename ValueT >
	MaybeOptional< Vec3T< ValueT > > & MaybeOptional< Vec3T< ValueT > >::operator-=( Vec3T< ValueT > const & rhs )
	{
		if ( areOptionalEnabled( *this, rhs ) )
		{
			addStmt( *findContainer( *this, rhs )
				, sdw::makeSimple( sdw::makeMinusAssign( this->getType()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	template< typename ValueT >
	MaybeOptional< Vec3T< ValueT > > & MaybeOptional< Vec3T< ValueT > >::operator*=( Vec3T< ValueT > const & rhs )
	{
		if ( areOptionalEnabled( *this, rhs ) )
		{
			addStmt( *findContainer( *this, rhs )
				, sdw::makeSimple( sdw::makeTimesAssign( this->getType()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	template< typename ValueT >
	MaybeOptional< Vec3T< ValueT > > & MaybeOptional< Vec3T< ValueT > >::operator/=( Vec3T< ValueT > const & rhs )
	{
		if ( areOptionalEnabled( *this, rhs ) )
		{
			addStmt( *findContainer( *this, rhs )
				, sdw::makeSimple( sdw::makeDivideAssign( this->getType()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	template< typename ValueT >
	MaybeOptional< Vec3T< ValueT > > & MaybeOptional< Vec3T< ValueT > >::operator+=( MaybeOptional< Vec3T< ValueT > > const & rhs )
	{
		if ( areOptionalEnabled( *this, rhs ) )
		{
			addStmt( *findContainer( *this, rhs )
				, sdw::makeSimple( sdw::makeAddAssign( this->getType()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	template< typename ValueT >
	MaybeOptional< Vec3T< ValueT > > & MaybeOptional< Vec3T< ValueT > >::operator-=( MaybeOptional< Vec3T< ValueT > > const & rhs )
	{
		if ( areOptionalEnabled( *this, rhs ) )
		{
			addStmt( *findContainer( *this, rhs )
				, sdw::makeSimple( sdw::makeMinusAssign( this->getType()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	template< typename ValueT >
	MaybeOptional< Vec3T< ValueT > > & MaybeOptional< Vec3T< ValueT > >::operator*=( MaybeOptional< Vec3T< ValueT > > const & rhs )
	{
		if ( areOptionalEnabled( *this, rhs ) )
		{
			addStmt( *findContainer( *this, rhs )
				, sdw::makeSimple( sdw::makeTimesAssign( this->getType()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	template< typename ValueT >
	MaybeOptional< Vec3T< ValueT > > & MaybeOptional< Vec3T< ValueT > >::operator/=( MaybeOptional< Vec3T< ValueT > > const & rhs )
	{
		if ( areOptionalEnabled( *this, rhs ) )
		{
			addStmt( *findContainer( *this, rhs )
				, sdw::makeSimple( sdw::makeDivideAssign( this->getType()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	template< typename ValueT >
	MaybeOptional< Vec3T< ValueT > > & MaybeOptional< Vec3T< ValueT > >::operator+=( ValueT const & rhs )
	{
		if ( areOptionalEnabled( *this, rhs ) )
		{
			addStmt( *findContainer( *this, rhs )
				, sdw::makeSimple( sdw::makeAddAssign( this->getType()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	template< typename ValueT >
	MaybeOptional< Vec3T< ValueT > > & MaybeOptional< Vec3T< ValueT > >::operator-=( ValueT const & rhs )
	{
		if ( areOptionalEnabled( *this, rhs ) )
		{
			addStmt( *findContainer( *this, rhs )
				, sdw::makeSimple( sdw::makeMinusAssign( this->getType()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	template< typename ValueT >
	MaybeOptional< Vec3T< ValueT > > & MaybeOptional< Vec3T< ValueT > >::operator*=( ValueT const & rhs )
	{
		if ( areOptionalEnabled( *this, rhs ) )
		{
			addStmt( *findContainer( *this, rhs )
				, sdw::makeSimple( sdw::makeTimesAssign( this->getType()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	template< typename ValueT >
	MaybeOptional< Vec3T< ValueT > > & MaybeOptional< Vec3T< ValueT > >::operator/=( ValueT const & rhs )
	{
		if ( areOptionalEnabled( *this, rhs ) )
		{
			addStmt( *findContainer( *this, rhs )
				, sdw::makeSimple( sdw::makeDivideAssign( this->getType()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	template< typename ValueT >
	MaybeOptional< Vec3T< ValueT > > & MaybeOptional< Vec3T< ValueT > >::operator+=( MaybeOptional< ValueT > const & rhs )
	{
		if ( areOptionalEnabled( *this, rhs ) )
		{
			addStmt( *findContainer( *this, rhs )
				, sdw::makeSimple( sdw::makeAddAssign( this->getType()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	template< typename ValueT >
	MaybeOptional< Vec3T< ValueT > > & MaybeOptional< Vec3T< ValueT > >::operator-=( MaybeOptional< ValueT > const & rhs )
	{
		if ( areOptionalEnabled( *this, rhs ) )
		{
			addStmt( *findContainer( *this, rhs )
				, sdw::makeSimple( sdw::makeMinusAssign( this->getType()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	template< typename ValueT >
	MaybeOptional< Vec3T< ValueT > > & MaybeOptional< Vec3T< ValueT > >::operator*=( MaybeOptional< ValueT > const & rhs )
	{
		if ( areOptionalEnabled( *this, rhs ) )
		{
			addStmt( *findContainer( *this, rhs )
				, sdw::makeSimple( sdw::makeTimesAssign( this->getType()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	template< typename ValueT >
	MaybeOptional< Vec3T< ValueT > > & MaybeOptional< Vec3T< ValueT > >::operator/=( MaybeOptional< ValueT > const & rhs )
	{
		if ( areOptionalEnabled( *this, rhs ) )
		{
			addStmt( *findContainer( *this, rhs )
				, sdw::makeSimple( sdw::makeDivideAssign( this->getType()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	//*************************************************************************

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator+( MaybeOptional< ValueT > const & lhs
		, Vec3T< ValueT > const & rhs )
	{
		if ( isAnyOptional( lhs, rhs ) )
		{
			return MaybeOptional< Vec3T< ValueT > >{ findShader( lhs, rhs )
				, sdw::makeAdd( makeType( typeEnum< Vec3T< ValueT > > )
					, makeExpr( lhs, true )
					, makeExpr( rhs ) )
				, areOptionalEnabled( lhs, rhs ) };
		}

		return MaybeOptional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeAdd( makeType( typeEnum< Vec3T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator+( MaybeOptional< Vec3T< ValueT > > const & lhs
		, ValueT const & rhs )
	{
		if ( isAnyOptional( lhs, rhs ) )
		{
			return MaybeOptional< Vec3T< ValueT > >{ findShader( lhs, rhs )
				, sdw::makeAdd( makeType( typeEnum< Vec3T< ValueT > > )
					, makeExpr( lhs, true )
					, makeExpr( rhs ) )
				, areOptionalEnabled( lhs, rhs ) };
		}

		return MaybeOptional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeAdd( makeType( typeEnum< Vec3T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator+( MaybeOptional< Vec3T< ValueT > > const & lhs
		, Vec3T< ValueT > const & rhs )
	{
		if ( isAnyOptional( lhs, rhs ) )
		{
			return MaybeOptional< Vec3T< ValueT > >{ findShader( lhs, rhs )
				, sdw::makeAdd( makeType( typeEnum< Vec3T< ValueT > > )
					, makeExpr( lhs, true )
					, makeExpr( rhs ) )
				, areOptionalEnabled( lhs, rhs ) };
		}

		return MaybeOptional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeAdd( makeType( typeEnum< Vec3T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator+( ValueT const & lhs
		, MaybeOptional< Vec3T< ValueT > > const & rhs )
	{
		if ( isAnyOptional( lhs, rhs ) )
		{
			return MaybeOptional< Vec3T< ValueT > >{ findShader( lhs, rhs )
				, sdw::makeAdd( makeType( typeEnum< Vec3T< ValueT > > )
					, makeExpr( lhs )
					, makeExpr( rhs, true ) )
				, areOptionalEnabled( lhs, rhs ) };
		}

		return MaybeOptional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeAdd( makeType( typeEnum< Vec3T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator+( Vec3T< ValueT > const & lhs
		, MaybeOptional< ValueT > const & rhs )
	{
		if ( isAnyOptional( lhs, rhs ) )
		{
			return MaybeOptional< Vec3T< ValueT > >{ findShader( lhs, rhs )
				, sdw::makeAdd( makeType( typeEnum< Vec3T< ValueT > > )
					, makeExpr( lhs )
					, makeExpr( rhs, true ) )
				, areOptionalEnabled( lhs, rhs ) };
		}

		return MaybeOptional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeAdd( makeType( typeEnum< Vec3T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator+( Vec3T< ValueT > const & lhs
		, MaybeOptional< Vec3T< ValueT > > const & rhs )
	{
		if ( isAnyOptional( lhs, rhs ) )
		{
			return MaybeOptional< Vec3T< ValueT > >{ findShader( lhs, rhs )
				, sdw::makeAdd( makeType( typeEnum< Vec3T< ValueT > > )
					, makeExpr( lhs )
					, makeExpr( rhs, true ) )
				, areOptionalEnabled( lhs, rhs ) };
		}

		return MaybeOptional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeAdd( makeType( typeEnum< Vec3T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator+( MaybeOptional< ValueT > const & lhs
		, MaybeOptional< Vec3T< ValueT > > const & rhs )
	{
		if ( isAnyOptional( lhs, rhs ) )
		{
			return MaybeOptional< Vec3T< ValueT > >{ findShader( lhs, rhs )
				, sdw::makeAdd( makeType( typeEnum< Vec3T< ValueT > > )
					, makeExpr( lhs, true )
					, makeExpr( rhs ) )
				, areOptionalEnabled( lhs, rhs ) };
		}

		return MaybeOptional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeAdd( makeType( typeEnum< Vec3T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator+( MaybeOptional< Vec3T< ValueT > > const & lhs
		, MaybeOptional< ValueT > const & rhs )
	{
		if ( isAnyOptional( lhs, rhs ) )
		{
			return MaybeOptional< Vec3T< ValueT > >{ findShader( lhs, rhs )
				, sdw::makeAdd( makeType( typeEnum< Vec3T< ValueT > > )
					, makeExpr( lhs, true )
					, makeExpr( rhs, true ) )
				, areOptionalEnabled( lhs, rhs ) };
		}

		return MaybeOptional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeAdd( makeType( typeEnum< Vec3T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator+( MaybeOptional< Vec3T< ValueT > > const & lhs
		, MaybeOptional< Vec3T< ValueT > > const & rhs )
	{
		if ( isAnyOptional( lhs, rhs ) )
		{
			return MaybeOptional< Vec3T< ValueT > >{ findShader( lhs, rhs )
				, sdw::makeAdd( makeType( typeEnum< Vec3T< ValueT > > )
					, makeExpr( lhs, true )
					, makeExpr( rhs, true ) )
				, areOptionalEnabled( lhs, rhs ) };
		}

		return MaybeOptional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeAdd( makeType( typeEnum< Vec3T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator-( MaybeOptional< ValueT > const & lhs
		, Vec3T< ValueT > const & rhs )
	{
		if ( isAnyOptional( lhs, rhs ) )
		{
			return MaybeOptional< Vec3T< ValueT > >{ findShader( lhs, rhs )
				, sdw::makeMinus( makeType( typeEnum< Vec3T< ValueT > > )
					, makeExpr( lhs, true )
					, makeExpr( rhs ) )
				, areOptionalEnabled( lhs, rhs ) };
		}

		return MaybeOptional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeMinus( makeType( typeEnum< Vec3T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator-( MaybeOptional< Vec3T< ValueT > > const & lhs
		, ValueT const & rhs )
	{
		if ( isAnyOptional( lhs, rhs ) )
		{
			return MaybeOptional< Vec3T< ValueT > >{ findShader( lhs, rhs )
				, sdw::makeMinus( makeType( typeEnum< Vec3T< ValueT > > )
					, makeExpr( lhs, true )
					, makeExpr( rhs ) )
				, areOptionalEnabled( lhs, rhs ) };
		}

		return MaybeOptional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeMinus( makeType( typeEnum< Vec3T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator-( MaybeOptional< Vec3T< ValueT > > const & lhs
		, Vec3T< ValueT > const & rhs )
	{
		if ( isAnyOptional( lhs, rhs ) )
		{
			return MaybeOptional< Vec3T< ValueT > >{ findShader( lhs, rhs )
				, sdw::makeMinus( makeType( typeEnum< Vec3T< ValueT > > )
					, makeExpr( lhs, true )
					, makeExpr( rhs ) )
				, areOptionalEnabled( lhs, rhs ) };
		}

		return MaybeOptional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeMinus( makeType( typeEnum< Vec3T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator-( ValueT const & lhs
		, MaybeOptional< Vec3T< ValueT > > const & rhs )
	{
		if ( isAnyOptional( lhs, rhs ) )
		{
			return MaybeOptional< Vec3T< ValueT > >{ findShader( lhs, rhs )
				, sdw::makeMinus( makeType( typeEnum< Vec3T< ValueT > > )
					, makeExpr( lhs )
					, makeExpr( rhs, true ) )
				, areOptionalEnabled( lhs, rhs ) };
		}

		return MaybeOptional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeMinus( makeType( typeEnum< Vec3T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator-( Vec3T< ValueT > const & lhs
		, MaybeOptional< ValueT > const & rhs )
	{
		if ( isAnyOptional( lhs, rhs ) )
		{
			return MaybeOptional< Vec3T< ValueT > >{ findShader( lhs, rhs )
				, sdw::makeMinus( makeType( typeEnum< Vec3T< ValueT > > )
					, makeExpr( lhs )
					, makeExpr( rhs, true ) )
				, areOptionalEnabled( lhs, rhs ) };
		}

		return MaybeOptional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeMinus( makeType( typeEnum< Vec3T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator-( Vec3T< ValueT > const & lhs
		, MaybeOptional< Vec3T< ValueT > > const & rhs )
	{
		if ( isAnyOptional( lhs, rhs ) )
		{
			return MaybeOptional< Vec3T< ValueT > >{ findShader( lhs, rhs )
				, sdw::makeMinus( makeType( typeEnum< Vec3T< ValueT > > )
					, makeExpr( lhs )
					, makeExpr( rhs, true ) )
				, areOptionalEnabled( lhs, rhs ) };
		}

		return MaybeOptional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeMinus( makeType( typeEnum< Vec3T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator-( MaybeOptional< ValueT > const & lhs
		, MaybeOptional< Vec3T< ValueT > > const & rhs )
	{
		if ( isAnyOptional( lhs, rhs ) )
		{
			return MaybeOptional< Vec3T< ValueT > >{ findShader( lhs, rhs )
				, sdw::makeMinus( makeType( typeEnum< Vec3T< ValueT > > )
					, makeExpr( lhs, true )
					, makeExpr( rhs, true ) )
				, areOptionalEnabled( lhs, rhs ) };
		}

		return MaybeOptional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeMinus( makeType( typeEnum< Vec3T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator-( MaybeOptional< Vec3T< ValueT > > const & lhs
		, MaybeOptional< ValueT > const & rhs )
	{
		if ( isAnyOptional( lhs, rhs ) )
		{
			return MaybeOptional< Vec3T< ValueT > >{ findShader( lhs, rhs )
				, sdw::makeMinus( makeType( typeEnum< Vec3T< ValueT > > )
					, makeExpr( lhs, true )
					, makeExpr( rhs, true ) )
				, areOptionalEnabled( lhs, rhs ) };
		}

		return MaybeOptional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeMinus( makeType( typeEnum< Vec3T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator-( MaybeOptional< Vec3T< ValueT > > const & lhs
		, MaybeOptional< Vec3T< ValueT > > const & rhs )
	{
		if ( isAnyOptional( lhs, rhs ) )
		{
			return MaybeOptional< Vec3T< ValueT > >{ findShader( lhs, rhs )
				, sdw::makeMinus( makeType( typeEnum< Vec3T< ValueT > > )
					, makeExpr( lhs, true )
					, makeExpr( rhs, true ) )
				, areOptionalEnabled( lhs, rhs ) };
		}

		return MaybeOptional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeMinus( makeType( typeEnum< Vec3T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator*( MaybeOptional< ValueT > const & lhs
		, Vec3T< ValueT > const & rhs )
	{
		if ( isAnyOptional( lhs, rhs ) )
		{
			return MaybeOptional< Vec3T< ValueT > >{ findShader( lhs, rhs )
				, sdw::makeTimes( makeType( typeEnum< Vec3T< ValueT > > )
					, makeExpr( lhs, true )
					, makeExpr( rhs ) )
				, areOptionalEnabled( lhs, rhs ) };
		}

		return MaybeOptional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeTimes( makeType( typeEnum< Vec3T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator*( MaybeOptional< Vec3T< ValueT > > const & lhs
		, ValueT const & rhs )
	{
		if ( isAnyOptional( lhs, rhs ) )
		{
			return MaybeOptional< Vec3T< ValueT > >{ findShader( lhs, rhs )
				, sdw::makeTimes( makeType( typeEnum< Vec3T< ValueT > > )
					, makeExpr( lhs, true )
					, makeExpr( rhs ) )
				, areOptionalEnabled( lhs, rhs ) };
		}

		return MaybeOptional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeTimes( makeType( typeEnum< Vec3T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator*( MaybeOptional< Vec3T< ValueT > > const & lhs
		, Vec3T< ValueT > const & rhs )
	{
		if ( isAnyOptional( lhs, rhs ) )
		{
			return MaybeOptional< Vec3T< ValueT > >{ findShader( lhs, rhs )
				, sdw::makeTimes( makeType( typeEnum< Vec3T< ValueT > > )
					, makeExpr( lhs, true )
					, makeExpr( rhs ) )
				, areOptionalEnabled( lhs, rhs ) };
		}

		return MaybeOptional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeTimes( makeType( typeEnum< Vec3T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator*( ValueT const & lhs
		, MaybeOptional< Vec3T< ValueT > > const & rhs )
	{
		if ( isAnyOptional( lhs, rhs ) )
		{
			return MaybeOptional< Vec3T< ValueT > >{ findShader( lhs, rhs )
				, sdw::makeTimes( makeType( typeEnum< Vec3T< ValueT > > )
					, makeExpr( lhs )
					, makeExpr( rhs, true ) )
				, areOptionalEnabled( lhs, rhs ) };
		}

		return MaybeOptional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeTimes( makeType( typeEnum< Vec3T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator*( Vec3T< ValueT > const & lhs
		, MaybeOptional< ValueT > const & rhs )
	{
		if ( isAnyOptional( lhs, rhs ) )
		{
			return MaybeOptional< Vec3T< ValueT > >{ findShader( lhs, rhs )
				, sdw::makeTimes( makeType( typeEnum< Vec3T< ValueT > > )
					, makeExpr( lhs )
					, makeExpr( rhs, true ) )
				, areOptionalEnabled( lhs, rhs ) };
		}

		return MaybeOptional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeTimes( makeType( typeEnum< Vec3T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator*( Vec3T< ValueT > const & lhs
		, MaybeOptional< Vec3T< ValueT > > const & rhs )
	{
		if ( isAnyOptional( lhs, rhs ) )
		{
			return MaybeOptional< Vec3T< ValueT > >{ findShader( lhs, rhs )
				, sdw::makeTimes( makeType( typeEnum< Vec3T< ValueT > > )
					, makeExpr( lhs )
					, makeExpr( rhs, true ) )
				, areOptionalEnabled( lhs, rhs ) };
		}

		return MaybeOptional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeTimes( makeType( typeEnum< Vec3T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator*( MaybeOptional< ValueT > const & lhs
		, MaybeOptional< Vec3T< ValueT > > const & rhs )
	{
		if ( isAnyOptional( lhs, rhs ) )
		{
			return MaybeOptional< Vec3T< ValueT > >{ findShader( lhs, rhs )
				, sdw::makeTimes( makeType( typeEnum< Vec3T< ValueT > > )
					, makeExpr( lhs, true )
					, makeExpr( rhs, true ) )
				, areOptionalEnabled( lhs, rhs ) };
		}

		return MaybeOptional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeTimes( makeType( typeEnum< Vec3T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator*( MaybeOptional< Vec3T< ValueT > > const & lhs
		, MaybeOptional< ValueT > const & rhs )
	{
		if ( isAnyOptional( lhs, rhs ) )
		{
			return MaybeOptional< Vec3T< ValueT > >{ findShader( lhs, rhs )
				, sdw::makeTimes( makeType( typeEnum< Vec3T< ValueT > > )
					, makeExpr( lhs, true )
					, makeExpr( rhs, true ) )
				, areOptionalEnabled( lhs, rhs ) };
		}

		return MaybeOptional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeTimes( makeType( typeEnum< Vec3T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator*( MaybeOptional< Vec3T< ValueT > > const & lhs
		, MaybeOptional< Vec3T< ValueT > > const & rhs )
	{
		if ( isAnyOptional( lhs, rhs ) )
		{
			return MaybeOptional< Vec3T< ValueT > >{ findShader( lhs, rhs )
				, sdw::makeTimes( makeType( typeEnum< Vec3T< ValueT > > )
					, makeExpr( lhs, true )
					, makeExpr( rhs, true ) )
				, areOptionalEnabled( lhs, rhs ) };
		}

		return MaybeOptional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeTimes( makeType( typeEnum< Vec3T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator/( MaybeOptional< Vec3T< ValueT > > const & lhs
		, Vec3T< ValueT > const & rhs )
	{
		if ( isAnyOptional( lhs, rhs ) )
		{
			return MaybeOptional< Vec3T< ValueT > >{ findShader( lhs, rhs )
				, sdw::makeDivide( makeType( typeEnum< Vec3T< ValueT > > )
					, makeExpr( lhs, true )
					, makeExpr( rhs ) )
				, areOptionalEnabled( lhs, rhs ) };
		}

		return MaybeOptional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeDivide( makeType( typeEnum< Vec3T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator/( Vec3T< ValueT > const & lhs
		, MaybeOptional< ValueT > const & rhs )
	{
		if ( isAnyOptional( lhs, rhs ) )
		{
			return MaybeOptional< Vec3T< ValueT > >{ findShader( lhs, rhs )
				, sdw::makeDivide( makeType( typeEnum< Vec3T< ValueT > > )
					, makeExpr( lhs )
					, makeExpr( rhs, true ) )
				, areOptionalEnabled( lhs, rhs ) };
		}

		return MaybeOptional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeDivide( makeType( typeEnum< Vec3T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator/( Vec3T< ValueT > const & lhs
		, MaybeOptional< Vec3T< ValueT > > const & rhs )
	{
		if ( isAnyOptional( lhs, rhs ) )
		{
			return MaybeOptional< Vec3T< ValueT > >{ findShader( lhs, rhs )
				, sdw::makeDivide( makeType( typeEnum< Vec3T< ValueT > > )
					, makeExpr( lhs )
					, makeExpr( rhs, true ) )
				, areOptionalEnabled( lhs, rhs ) };
		}

		return MaybeOptional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeDivide( makeType( typeEnum< Vec3T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator/( MaybeOptional< Vec3T< ValueT > > const & lhs
		, MaybeOptional< ValueT > const & rhs )
	{
		if ( isAnyOptional( lhs, rhs ) )
		{
			return MaybeOptional< Vec3T< ValueT > >{ findShader( lhs, rhs )
				, sdw::makeDivide( makeType( typeEnum< Vec3T< ValueT > > )
					, makeExpr( lhs, true )
					, makeExpr( rhs, true ) )
				, areOptionalEnabled( lhs, rhs ) };
		}

		return MaybeOptional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeDivide( makeType( typeEnum< Vec3T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator/( MaybeOptional< Vec3T< ValueT > > const & lhs
		, MaybeOptional< Vec3T< ValueT > > const & rhs )
	{
		if ( isAnyOptional( lhs, rhs ) )
		{
			return MaybeOptional< Vec3T< ValueT > >{ findShader( lhs, rhs )
				, sdw::makeDivide( makeType( typeEnum< Vec3T< ValueT > > )
					, makeExpr( lhs, true )
					, makeExpr( rhs, true ) )
				, areOptionalEnabled( lhs, rhs ) };
		}

		return MaybeOptional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeDivide( makeType( typeEnum< Vec3T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	//*************************************************************************
}
