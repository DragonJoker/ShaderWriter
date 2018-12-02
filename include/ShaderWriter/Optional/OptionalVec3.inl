/*
See LICENSE file in root folder
*/
namespace sdw
{
	//*************************************************************************

	template< typename ValueT >
	inline Optional< Vec3T< ValueT > >::Optional( Shader * shader
		, expr::ExprPtr expr
		, bool enabled )
		: Vec3T< ValueT >{ shader, std::move( expr ) }
		, m_enabled{ enabled }
	{
	}

	template< typename ValueT >
	Optional< Vec3T< ValueT > >::Optional( Vec3T< ValueT > const & rhs
		, bool enabled )
		: Vec3T< ValueT >{ rhs }
		, m_enabled{ enabled }
	{
	}

	template< typename ValueT >
	Optional< Vec3T< ValueT > >::Optional( Optional< Vec3T< ValueT > > const & rhs )
		: Vec3T< ValueT >{ rhs }
		, m_enabled{ rhs.m_enabled }
	{
	}

	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > & Optional< Vec3T< ValueT > >::operator=( Optional< Vec3T< ValueT > > const & rhs )
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
	bool Optional< Vec3T< ValueT > >::isEnabled()const
	{
		return m_enabled;
	}

	template< typename ValueT >
	Optional< Vec3T< ValueT > >::operator Optional< Value >()const
	{
		return Optional< Value >{ *this
			, makeExpr( this->getExpr() )
			, isEnabled() };
	}

	template< typename ValueT >
	template< typename IndexT >
	inline Optional< ValueT > Optional< Vec3T< ValueT > >::operator[]( IndexT const & rhs )const
	{
		return Optional< ValueT >{ findShader( *this, rhs )
			, sdw::makeArrayAccess( ValueT::makeType()
				, makeExpr( this->getExpr() )
				, makeExpr( rhs ) )
			, areOptionalEnabled( *this, rhs )};
	}

	template< typename ValueT >
	Optional< Vec3T< ValueT > > & Optional< Vec3T< ValueT > >::operator+=( Vec3T< ValueT > const & rhs )
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
	Optional< Vec3T< ValueT > > & Optional< Vec3T< ValueT > >::operator-=( Vec3T< ValueT > const & rhs )
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
	Optional< Vec3T< ValueT > > & Optional< Vec3T< ValueT > >::operator*=( Vec3T< ValueT > const & rhs )
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
	Optional< Vec3T< ValueT > > & Optional< Vec3T< ValueT > >::operator/=( Vec3T< ValueT > const & rhs )
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
	Optional< Vec3T< ValueT > > & Optional< Vec3T< ValueT > >::operator+=( Optional< Vec3T< ValueT > > const & rhs )
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
	Optional< Vec3T< ValueT > > & Optional< Vec3T< ValueT > >::operator-=( Optional< Vec3T< ValueT > > const & rhs )
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
	Optional< Vec3T< ValueT > > & Optional< Vec3T< ValueT > >::operator*=( Optional< Vec3T< ValueT > > const & rhs )
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
	Optional< Vec3T< ValueT > > & Optional< Vec3T< ValueT > >::operator/=( Optional< Vec3T< ValueT > > const & rhs )
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
	Optional< Vec3T< ValueT > > & Optional< Vec3T< ValueT > >::operator+=( ValueT const & rhs )
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
	Optional< Vec3T< ValueT > > & Optional< Vec3T< ValueT > >::operator-=( ValueT const & rhs )
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
	Optional< Vec3T< ValueT > > & Optional< Vec3T< ValueT > >::operator*=( ValueT const & rhs )
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
	Optional< Vec3T< ValueT > > & Optional< Vec3T< ValueT > >::operator/=( ValueT const & rhs )
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
	Optional< Vec3T< ValueT > > & Optional< Vec3T< ValueT > >::operator+=( Optional< ValueT > const & rhs )
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
	Optional< Vec3T< ValueT > > & Optional< Vec3T< ValueT > >::operator-=( Optional< ValueT > const & rhs )
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
	Optional< Vec3T< ValueT > > & Optional< Vec3T< ValueT > >::operator*=( Optional< ValueT > const & rhs )
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
	Optional< Vec3T< ValueT > > & Optional< Vec3T< ValueT > >::operator/=( Optional< ValueT > const & rhs )
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
	inline Vec3T< ValueT > operator+( ValueT const & lhs
		, Vec3T< ValueT > const & rhs )
	{
		return Vec3T< ValueT >{ findShader( lhs, rhs )
			, sdw::makeAdd( Vec3T< ValueT >::makeType()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline Vec3T< ValueT > operator+( Vec3T< ValueT > const & lhs
		, ValueT const & rhs )
	{
		return Vec3T< ValueT >{ findShader( lhs, rhs )
			, sdw::makeAdd( Vec3T< ValueT >::makeType()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline Vec3T< ValueT > operator+( Vec3T< ValueT > const & lhs
		, Vec3T< ValueT > const & rhs )
	{
		return Vec3T< ValueT >{ findShader( lhs, rhs )
			, sdw::makeAdd( Vec3T< ValueT >::makeType()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator+( Optional< ValueT > const & lhs
		, Vec3T< ValueT > const & rhs )
	{
		return Optional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeAdd( Vec3T< ValueT >::makeType()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator+( Optional< Vec3T< ValueT > > const & lhs
		, ValueT const & rhs )
	{
		return Optional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeAdd( Vec3T< ValueT >::makeType()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator+( Optional< Vec3T< ValueT > > const & lhs
		, Vec3T< ValueT > const & rhs )
	{
		return Optional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeAdd( Vec3T< ValueT >::makeType()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator+( ValueT const & lhs
		, Optional< Vec3T< ValueT > > const & rhs )
	{
		return Optional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeAdd( Vec3T< ValueT >::makeType()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator+( Vec3T< ValueT > const & lhs
		, Optional< ValueT > const & rhs )
	{
		return Optional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeAdd( Vec3T< ValueT >::makeType()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator+( Vec3T< ValueT > const & lhs
		, Optional< Vec3T< ValueT > > const & rhs )
	{
		return Optional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeAdd( Vec3T< ValueT >::makeType()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator+( Optional< ValueT > const & lhs
		, Optional< Vec3T< ValueT > > const & rhs )
	{
		return Optional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeAdd( Vec3T< ValueT >::makeType()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator+( Optional< Vec3T< ValueT > > const & lhs
		, Optional< ValueT > const & rhs )
	{
		return Optional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeAdd( Vec3T< ValueT >::makeType()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator+( Optional< Vec3T< ValueT > > const & lhs
		, Optional< Vec3T< ValueT > > const & rhs )
	{
		return Optional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeAdd( Vec3T< ValueT >::makeType()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Vec3T< ValueT > operator-( ValueT const & lhs
		, Vec3T< ValueT > const & rhs )
	{
		return Vec3T< ValueT >{ findShader( lhs, rhs )
			, sdw::makeMinus( Vec3T< ValueT >::makeType()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline Vec3T< ValueT > operator-( Vec3T< ValueT > const & lhs
		, ValueT const & rhs )
	{
		return Vec3T< ValueT >{ findShader( lhs, rhs )
			, sdw::makeMinus( Vec3T< ValueT >::makeType()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline Vec3T< ValueT > operator-( Vec3T< ValueT > const & lhs
		, Vec3T< ValueT > const & rhs )
	{
		return Vec3T< ValueT >{ findShader( lhs, rhs )
			, sdw::makeMinus( Vec3T< ValueT >::makeType()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator-( Optional< ValueT > const & lhs
		, Vec3T< ValueT > const & rhs )
	{
		return Optional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeMinus( Vec3T< ValueT >::makeType()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator-( Optional< Vec3T< ValueT > > const & lhs
		, ValueT const & rhs )
	{
		return Optional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeMinus( Vec3T< ValueT >::makeType()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator-( Optional< Vec3T< ValueT > > const & lhs
		, Vec3T< ValueT > const & rhs )
	{
		return Optional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeMinus( Vec3T< ValueT >::makeType()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator-( ValueT const & lhs
		, Optional< Vec3T< ValueT > > const & rhs )
	{
		return Optional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeMinus( Vec3T< ValueT >::makeType()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator-( Vec3T< ValueT > const & lhs
		, Optional< ValueT > const & rhs )
	{
		return Optional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeMinus( Vec3T< ValueT >::makeType()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator-( Vec3T< ValueT > const & lhs
		, Optional< Vec3T< ValueT > > const & rhs )
	{
		return Optional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeMinus( Vec3T< ValueT >::makeType()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator-( Optional< ValueT > const & lhs
		, Optional< Vec3T< ValueT > > const & rhs )
	{
		return Optional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeMinus( Vec3T< ValueT >::makeType()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator-( Optional< Vec3T< ValueT > > const & lhs
		, Optional< ValueT > const & rhs )
	{
		return Optional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeMinus( Vec3T< ValueT >::makeType()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator-( Optional< Vec3T< ValueT > > const & lhs
		, Optional< Vec3T< ValueT > > const & rhs )
	{
		return Optional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeMinus( Vec3T< ValueT >::makeType()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Vec3T< ValueT > operator*( ValueT const & lhs
		, Vec3T< ValueT > const & rhs )
	{
		return Vec3T< ValueT >{ findShader( lhs, rhs )
			, sdw::makeTimes( Vec3T< ValueT >::makeType()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline Vec3T< ValueT > operator*( Vec3T< ValueT > const & lhs
		, ValueT const & rhs )
	{
		return Vec3T< ValueT >{ findShader( lhs, rhs )
			, sdw::makeTimes( Vec3T< ValueT >::makeType()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline Vec3T< ValueT > operator*( Vec3T< ValueT > const & lhs
		, Vec3T< ValueT > const & rhs )
	{
		return Vec3T< ValueT >{ findShader( lhs, rhs )
			, sdw::makeTimes( Vec3T< ValueT >::makeType()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator*( Optional< ValueT > const & lhs
		, Vec3T< ValueT > const & rhs )
	{
		return Optional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeTimes( Vec3T< ValueT >::makeType()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator*( Optional< Vec3T< ValueT > > const & lhs
		, ValueT const & rhs )
	{
		return Optional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeTimes( Vec3T< ValueT >::makeType()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator*( Optional< Vec3T< ValueT > > const & lhs
		, Vec3T< ValueT > const & rhs )
	{
		return Optional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeTimes( Vec3T< ValueT >::makeType()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator*( ValueT const & lhs
		, Optional< Vec3T< ValueT > > const & rhs )
	{
		return Optional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeTimes( Vec3T< ValueT >::makeType()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator*( Vec3T< ValueT > const & lhs
		, Optional< ValueT > const & rhs )
	{
		return Optional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeTimes( Vec3T< ValueT >::makeType()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator*( Vec3T< ValueT > const & lhs
		, Optional< Vec3T< ValueT > > const & rhs )
	{
		return Optional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeTimes( Vec3T< ValueT >::makeType()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator*( Optional< ValueT > const & lhs
		, Optional< Vec3T< ValueT > > const & rhs )
	{
		return Optional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeTimes( Vec3T< ValueT >::makeType()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator*( Optional< Vec3T< ValueT > > const & lhs
		, Optional< ValueT > const & rhs )
	{
		return Optional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeTimes( Vec3T< ValueT >::makeType()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator*( Optional< Vec3T< ValueT > > const & lhs
		, Optional< Vec3T< ValueT > > const & rhs )
	{
		return Optional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeTimes( Vec3T< ValueT >::makeType()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Vec3T< ValueT > operator/( Vec3T< ValueT > const & lhs
		, Vec3T< ValueT > const & rhs )
	{
		return Vec3T< ValueT >{ findShader( lhs, rhs )
			, sdw::makeDivide( Vec3T< ValueT >::makeType()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline Vec3T< ValueT > operator/( Vec3T< ValueT > const & lhs
		, ValueT const & rhs )
	{
		return Vec3T< ValueT >{ findShader( lhs, rhs )
			, sdw::makeDivide( Vec3T< ValueT >::makeType()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator/( Optional< Vec3T< ValueT > > const & lhs
		, Vec3T< ValueT > const & rhs )
	{
		return Optional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeDivide( Vec3T< ValueT >::makeType()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator/( Optional< Vec3T< ValueT > > const & lhs
		, ValueT const & rhs )
	{
		return Optional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeDivide( Vec3T< ValueT >::makeType()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator/( Vec3T< ValueT > const & lhs
		, Optional< Vec3T< ValueT > > const & rhs )
	{
		return Optional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeDivide( Vec3T< ValueT >::makeType()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator/( Vec3T< ValueT > const & lhs
		, Optional< ValueT > const & rhs )
	{
		return Optional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeDivide( Vec3T< ValueT >::makeType()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator/( Optional< Vec3T< ValueT > > const & lhs
		, Optional< Vec3T< ValueT > > const & rhs )
	{
		return Optional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeDivide( Vec3T< ValueT >::makeType()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator/( Optional< Vec3T< ValueT > > const & lhs
		, Optional< ValueT > const & rhs )
	{
		return Optional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeDivide( Vec3T< ValueT >::makeType()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	//*************************************************************************
}
