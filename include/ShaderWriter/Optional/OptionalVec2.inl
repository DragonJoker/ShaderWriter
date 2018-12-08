/*
See LICENSE file in root folder
*/
namespace sdw
{
	//*************************************************************************

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > >::Optional( Shader * shader
		, expr::ExprPtr expr
		, bool enabled )
		: Vec2T< ValueT >{ shader, std::move( expr ) }
		, m_enabled{ enabled }
	{
	}

	template< typename ValueT >
	Optional< Vec2T< ValueT > >::Optional( Vec2T< ValueT > const & rhs
		, bool enabled )
		: Vec2T< ValueT >{ rhs }
		, m_enabled{ enabled }
	{
	}

	template< typename ValueT >
	Optional< Vec2T< ValueT > >::Optional( Optional< Vec2T< ValueT > > const & rhs )
		: Vec2T< ValueT >{ rhs }
		, m_enabled{ rhs.m_enabled }
	{
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > & Optional< Vec2T< ValueT > >::operator=( Optional< Vec2T< ValueT > > const & rhs )
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
	bool Optional< Vec2T< ValueT > >::isEnabled()const
	{
		return m_enabled;
	}

	template< typename ValueT >
	Optional< Vec2T< ValueT > >::operator Optional< Value >()const
	{
		return Optional< Value >{ *this
			, makeExpr( this->getExpr() )
			, isEnabled() };
	}

	template< typename ValueT >
	template< typename IndexT >
	inline Optional< ValueT > Optional< Vec2T< ValueT > >::operator[]( IndexT const & rhs )const
	{
		return Optional< ValueT >{ findShader( *this, rhs )
			, sdw::makeArrayAccess( ValueT::makeType( findTypesCache( *this, rhs ) )
				, makeExpr( this->getExpr() )
				, makeExpr( rhs ) )
			, areOptionalEnabled( *this, rhs )};
	}

	template< typename ValueT >
	Optional< Vec2T< ValueT > > & Optional< Vec2T< ValueT > >::operator+=( Vec2T< ValueT > const & rhs )
	{
		if ( areOptionalEnabled( *this, rhs ) )
		{
			addStmt( *findShader( *this, rhs )
				, sdw::makeSimple( sdw::makeAddAssign( this->getType()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	template< typename ValueT >
	Optional< Vec2T< ValueT > > & Optional< Vec2T< ValueT > >::operator-=( Vec2T< ValueT > const & rhs )
	{
		if ( areOptionalEnabled( *this, rhs ) )
		{
			addStmt( *findShader( *this, rhs )
				, sdw::makeSimple( sdw::makeMinusAssign( this->getType()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	template< typename ValueT >
	Optional< Vec2T< ValueT > > & Optional< Vec2T< ValueT > >::operator*=( Vec2T< ValueT > const & rhs )
	{
		if ( areOptionalEnabled( *this, rhs ) )
		{
			addStmt( *findShader( *this, rhs )
				, sdw::makeSimple( sdw::makeTimesAssign( this->getType()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	template< typename ValueT >
	Optional< Vec2T< ValueT > > & Optional< Vec2T< ValueT > >::operator/=( Vec2T< ValueT > const & rhs )
	{
		if ( areOptionalEnabled( *this, rhs ) )
		{
			addStmt( *findShader( *this, rhs )
				, sdw::makeSimple( sdw::makeDivideAssign( this->getType()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	template< typename ValueT >
	Optional< Vec2T< ValueT > > & Optional< Vec2T< ValueT > >::operator+=( Optional< Vec2T< ValueT > > const & rhs )
	{
		if ( areOptionalEnabled( *this, rhs ) )
		{
			addStmt( *findShader( *this, rhs )
				, sdw::makeSimple( sdw::makeAddAssign( this->getType()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	template< typename ValueT >
	Optional< Vec2T< ValueT > > & Optional< Vec2T< ValueT > >::operator-=( Optional< Vec2T< ValueT > > const & rhs )
	{
		if ( areOptionalEnabled( *this, rhs ) )
		{
			addStmt( *findShader( *this, rhs )
				, sdw::makeSimple( sdw::makeMinusAssign( this->getType()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	template< typename ValueT >
	Optional< Vec2T< ValueT > > & Optional< Vec2T< ValueT > >::operator*=( Optional< Vec2T< ValueT > > const & rhs )
	{
		if ( areOptionalEnabled( *this, rhs ) )
		{
			addStmt( *findShader( *this, rhs )
				, sdw::makeSimple( sdw::makeTimesAssign( this->getType()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	template< typename ValueT >
	Optional< Vec2T< ValueT > > & Optional< Vec2T< ValueT > >::operator/=( Optional< Vec2T< ValueT > > const & rhs )
	{
		if ( areOptionalEnabled( *this, rhs ) )
		{
			addStmt( *findShader( *this, rhs )
				, sdw::makeSimple( sdw::makeDivideAssign( this->getType()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	template< typename ValueT >
	Optional< Vec2T< ValueT > > & Optional< Vec2T< ValueT > >::operator+=( ValueT const & rhs )
	{
		if ( areOptionalEnabled( *this, rhs ) )
		{
			addStmt( *findShader( *this, rhs )
				, sdw::makeSimple( sdw::makeAddAssign( this->getType()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	template< typename ValueT >
	Optional< Vec2T< ValueT > > & Optional< Vec2T< ValueT > >::operator-=( ValueT const & rhs )
	{
		if ( areOptionalEnabled( *this, rhs ) )
		{
			addStmt( *findShader( *this, rhs )
				, sdw::makeSimple( sdw::makeMinusAssign( this->getType()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	template< typename ValueT >
	Optional< Vec2T< ValueT > > & Optional< Vec2T< ValueT > >::operator*=( ValueT const & rhs )
	{
		if ( areOptionalEnabled( *this, rhs ) )
		{
			addStmt( *findShader( *this, rhs )
				, sdw::makeSimple( sdw::makeTimesAssign( this->getType()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	template< typename ValueT >
	Optional< Vec2T< ValueT > > & Optional< Vec2T< ValueT > >::operator/=( ValueT const & rhs )
	{
		if ( areOptionalEnabled( *this, rhs ) )
		{
			addStmt( *findShader( *this, rhs )
				, sdw::makeSimple( sdw::makeDivideAssign( this->getType()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	template< typename ValueT >
	Optional< Vec2T< ValueT > > & Optional< Vec2T< ValueT > >::operator+=( Optional< ValueT > const & rhs )
	{
		if ( areOptionalEnabled( *this, rhs ) )
		{
			addStmt( *findShader( *this, rhs )
				, sdw::makeSimple( sdw::makeAddAssign( this->getType()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	template< typename ValueT >
	Optional< Vec2T< ValueT > > & Optional< Vec2T< ValueT > >::operator-=( Optional< ValueT > const & rhs )
	{
		if ( areOptionalEnabled( *this, rhs ) )
		{
			addStmt( *findShader( *this, rhs )
				, sdw::makeSimple( sdw::makeMinusAssign( this->getType()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	template< typename ValueT >
	Optional< Vec2T< ValueT > > & Optional< Vec2T< ValueT > >::operator*=( Optional< ValueT > const & rhs )
	{
		if ( areOptionalEnabled( *this, rhs ) )
		{
			addStmt( *findShader( *this, rhs )
				, sdw::makeSimple( sdw::makeTimesAssign( this->getType()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	template< typename ValueT >
	Optional< Vec2T< ValueT > > & Optional< Vec2T< ValueT > >::operator/=( Optional< ValueT > const & rhs )
	{
		if ( areOptionalEnabled( *this, rhs ) )
		{
			addStmt( *findShader( *this, rhs )
				, sdw::makeSimple( sdw::makeDivideAssign( this->getType()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	//*************************************************************************

	template< typename ValueT >
	inline Vec2T< ValueT > operator+( ValueT const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return Vec2T< ValueT >{ findShader( lhs, rhs )
			, sdw::makeAdd( Vec2T< ValueT >::makeType( findTypesCache( lhs, rhs ) )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline Vec2T< ValueT > operator+( Vec2T< ValueT > const & lhs
		, ValueT const & rhs )
	{
		return Vec2T< ValueT >{ findShader( lhs, rhs )
			, sdw::makeAdd( Vec2T< ValueT >::makeType( findTypesCache( lhs, rhs ) )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline Vec2T< ValueT > operator+( Vec2T< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return Vec2T< ValueT >{ findShader( lhs, rhs )
			, sdw::makeAdd( Vec2T< ValueT >::makeType( findTypesCache( lhs, rhs ) )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator+( Optional< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeAdd( Vec2T< ValueT >::makeType( findTypesCache( lhs, rhs ) )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator+( Optional< Vec2T< ValueT > > const & lhs
		, ValueT const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeAdd( Vec2T< ValueT >::makeType( findTypesCache( lhs, rhs ) )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator+( Optional< Vec2T< ValueT > > const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeAdd( Vec2T< ValueT >::makeType( findTypesCache( lhs, rhs ) )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator+( ValueT const & lhs
		, Optional< Vec2T< ValueT > > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeAdd( Vec2T< ValueT >::makeType( findTypesCache( lhs, rhs ) )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator+( Vec2T< ValueT > const & lhs
		, Optional< ValueT > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeAdd( Vec2T< ValueT >::makeType( findTypesCache( lhs, rhs ) )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator+( Vec2T< ValueT > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeAdd( Vec2T< ValueT >::makeType( findTypesCache( lhs, rhs ) )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator+( Optional< ValueT > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeAdd( Vec2T< ValueT >::makeType( findTypesCache( lhs, rhs ) )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator+( Optional< Vec2T< ValueT > > const & lhs
		, Optional< ValueT > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeAdd( Vec2T< ValueT >::makeType( findTypesCache( lhs, rhs ) )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator+( Optional< Vec2T< ValueT > > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeAdd( Vec2T< ValueT >::makeType( findTypesCache( lhs, rhs ) )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Vec2T< ValueT > operator-( ValueT const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return Vec2T< ValueT >{ findShader( lhs, rhs )
			, sdw::makeMinus( Vec2T< ValueT >::makeType( findTypesCache( lhs, rhs ) )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline Vec2T< ValueT > operator-( Vec2T< ValueT > const & lhs
		, ValueT const & rhs )
	{
		return Vec2T< ValueT >{ findShader( lhs, rhs )
			, sdw::makeMinus( Vec2T< ValueT >::makeType( findTypesCache( lhs, rhs ) )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline Vec2T< ValueT > operator-( Vec2T< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return Vec2T< ValueT >{ findShader( lhs, rhs )
			, sdw::makeMinus( Vec2T< ValueT >::makeType( findTypesCache( lhs, rhs ) )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator-( Optional< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeMinus( Vec2T< ValueT >::makeType( findTypesCache( lhs, rhs ) )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator-( Optional< Vec2T< ValueT > > const & lhs
		, ValueT const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeMinus( Vec2T< ValueT >::makeType( findTypesCache( lhs, rhs ) )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator-( Optional< Vec2T< ValueT > > const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeMinus( Vec2T< ValueT >::makeType( findTypesCache( lhs, rhs ) )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator-( ValueT const & lhs
		, Optional< Vec2T< ValueT > > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeMinus( Vec2T< ValueT >::makeType( findTypesCache( lhs, rhs ) )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator-( Vec2T< ValueT > const & lhs
		, Optional< ValueT > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeMinus( Vec2T< ValueT >::makeType( findTypesCache( lhs, rhs ) )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator-( Vec2T< ValueT > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeMinus( Vec2T< ValueT >::makeType( findTypesCache( lhs, rhs ) )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator-( Optional< ValueT > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeMinus( Vec2T< ValueT >::makeType( findTypesCache( lhs, rhs ) )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator-( Optional< Vec2T< ValueT > > const & lhs
		, Optional< ValueT > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeMinus( Vec2T< ValueT >::makeType( findTypesCache( lhs, rhs ) )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator-( Optional< Vec2T< ValueT > > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeMinus( Vec2T< ValueT >::makeType( findTypesCache( lhs, rhs ) )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Vec2T< ValueT > operator*( ValueT const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return Vec2T< ValueT >{ findShader( lhs, rhs )
			, sdw::makeTimes( Vec2T< ValueT >::makeType( findTypesCache( lhs, rhs ) )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline Vec2T< ValueT > operator*( Vec2T< ValueT > const & lhs
		, ValueT const & rhs )
	{
		return Vec2T< ValueT >{ findShader( lhs, rhs )
			, sdw::makeTimes( Vec2T< ValueT >::makeType( findTypesCache( lhs, rhs ) )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline Vec2T< ValueT > operator*( Vec2T< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return Vec2T< ValueT >{ findShader( lhs, rhs )
			, sdw::makeTimes( Vec2T< ValueT >::makeType( findTypesCache( lhs, rhs ) )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator*( Optional< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeTimes( Vec2T< ValueT >::makeType( findTypesCache( lhs, rhs ) )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator*( Optional< Vec2T< ValueT > > const & lhs
		, ValueT const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeTimes( Vec2T< ValueT >::makeType( findTypesCache( lhs, rhs ) )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator*( Optional< Vec2T< ValueT > > const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeTimes( Vec2T< ValueT >::makeType( findTypesCache( lhs, rhs ) )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator*( ValueT const & lhs
		, Optional< Vec2T< ValueT > > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeTimes( Vec2T< ValueT >::makeType( findTypesCache( lhs, rhs ) )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator*( Vec2T< ValueT > const & lhs
		, Optional< ValueT > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeTimes( Vec2T< ValueT >::makeType( findTypesCache( lhs, rhs ) )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator*( Vec2T< ValueT > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeTimes( Vec2T< ValueT >::makeType( findTypesCache( lhs, rhs ) )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator*( Optional< ValueT > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeTimes( Vec2T< ValueT >::makeType( findTypesCache( lhs, rhs ) )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator*( Optional< Vec2T< ValueT > > const & lhs
		, Optional< ValueT > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeTimes( Vec2T< ValueT >::makeType( findTypesCache( lhs, rhs ) )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator*( Optional< Vec2T< ValueT > > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeTimes( Vec2T< ValueT >::makeType( findTypesCache( lhs, rhs ) )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Vec2T< ValueT > operator/( Vec2T< ValueT > const & lhs
		, ValueT const & rhs )
	{
		return Vec2T< ValueT >{ findShader( lhs, rhs )
			, sdw::makeDivide( Vec2T< ValueT >::makeType( findTypesCache( lhs, rhs ) )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline Vec2T< ValueT > operator/( Vec2T< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return Vec2T< ValueT >{ findShader( lhs, rhs )
			, sdw::makeDivide( Vec2T< ValueT >::makeType( findTypesCache( lhs, rhs ) )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator/( Optional< Vec2T< ValueT > > const & lhs
		, ValueT const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeDivide( Vec2T< ValueT >::makeType( findTypesCache( lhs, rhs ) )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator/( Optional< Vec2T< ValueT > > const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeDivide( Vec2T< ValueT >::makeType( findTypesCache( lhs, rhs ) )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator/( Vec2T< ValueT > const & lhs
		, Optional< ValueT > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeDivide( Vec2T< ValueT >::makeType( findTypesCache( lhs, rhs ) )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator/( Vec2T< ValueT > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeDivide( Vec2T< ValueT >::makeType( findTypesCache( lhs, rhs ) )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator/( Optional< Vec2T< ValueT > > const & lhs
		, Optional< ValueT > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeDivide( Vec2T< ValueT >::makeType( findTypesCache( lhs, rhs ) )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator/( Optional< Vec2T< ValueT > > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeDivide( Vec2T< ValueT >::makeType( findTypesCache( lhs, rhs ) )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	//*************************************************************************
}
