/*
See LICENSE file in root folder
*/
namespace sdw
{
	//*************************************************************************

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > >::Optional( Shader * shader
		, expr::ExprPtr expr
		, bool enabled )
		: Vec4T< ValueT >{ shader, std::move( expr ) }
		, m_enabled{ enabled }
	{
	}

	template< typename ValueT >
	Optional< Vec4T< ValueT > >::Optional( Vec4T< ValueT > const & other
		, bool enabled )
		: Vec4T< ValueT >{ other }
		, m_enabled{ enabled }
	{
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > & Optional< Vec4T< ValueT > >::operator=( Optional< Vec4T< ValueT > > const & rhs )
	{
		if ( areOptionalEnabled( *this, rhs ) )
		{
			addStmt( *findContainer( *this, rhs )
				, stmt::makeSimple( expr::makeAssign( getType()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	template< typename ValueT >
	bool Optional< Vec4T< ValueT > >::isEnabled()const
	{
		return m_enabled;
	}

	template< typename ValueT >
	Optional< Vec4T< ValueT > >::operator Optional< Value >()const
	{
		return Optional< Value >{ *this
			, makeExpr( getExpr() )
			, isEnabled() };
	}

	template< typename ValueT >
	template< typename IndexT >
	inline Optional< ValueT > Optional< Vec4T< ValueT > >::operator[]( IndexT const & rhs )const
	{
		return Optional< ValueT >{ findShader( *this, rhs )
			, expr::makeArrayAccess( makeType( TypeTraits< ValueT >::TypeEnum )
				, makeExpr( getExpr() )
				, makeExpr( rhs ) )
			, areOptionalEnabled( *this, rhs )};
	}

	template< typename ValueT >
	Optional< Vec4T< ValueT > > & Optional< Vec4T< ValueT > >::operator+=( Vec4T< ValueT > const & rhs )
	{
		if ( areOptionalEnabled( *this, rhs ) )
		{
			addStmt( *findContainer( *this, rhs )
				, stmt::makeSimple( expr::makeAddAssign( getType()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	template< typename ValueT >
	Optional< Vec4T< ValueT > > & Optional< Vec4T< ValueT > >::operator-=( Vec4T< ValueT > const & rhs )
	{
		if ( areOptionalEnabled( *this, rhs ) )
		{
			addStmt( *findContainer( *this, rhs )
				, stmt::makeSimple( expr::makeMinusAssign( getType()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	template< typename ValueT >
	Optional< Vec4T< ValueT > > & Optional< Vec4T< ValueT > >::operator*=( Vec4T< ValueT > const & rhs )
	{
		if ( areOptionalEnabled( *this, rhs ) )
		{
			addStmt( *findContainer( *this, rhs )
				, stmt::makeSimple( expr::makeTimesAssign( getType()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	template< typename ValueT >
	Optional< Vec4T< ValueT > > & Optional< Vec4T< ValueT > >::operator/=( Vec4T< ValueT > const & rhs )
	{
		if ( areOptionalEnabled( *this, rhs ) )
		{
			addStmt( *findContainer( *this, rhs )
				, stmt::makeSimple( expr::makeDivideAssign( getType()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	template< typename ValueT >
	Optional< Vec4T< ValueT > > & Optional< Vec4T< ValueT > >::operator+=( Optional< Vec4T< ValueT > > const & rhs )
	{
		if ( areOptionalEnabled( *this, rhs ) )
		{
			addStmt( *findContainer( *this, rhs )
				, stmt::makeSimple( expr::makeAddAssign( getType()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	template< typename ValueT >
	Optional< Vec4T< ValueT > > & Optional< Vec4T< ValueT > >::operator-=( Optional< Vec4T< ValueT > > const & rhs )
	{
		if ( areOptionalEnabled( *this, rhs ) )
		{
			addStmt( *findContainer( *this, rhs )
				, stmt::makeSimple( expr::makeMinusAssign( getType()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	template< typename ValueT >
	Optional< Vec4T< ValueT > > & Optional< Vec4T< ValueT > >::operator*=( Optional< Vec4T< ValueT > > const & rhs )
	{
		if ( areOptionalEnabled( *this, rhs ) )
		{
			addStmt( *findContainer( *this, rhs )
				, stmt::makeSimple( expr::makeTimesAssign( getType()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	template< typename ValueT >
	Optional< Vec4T< ValueT > > & Optional< Vec4T< ValueT > >::operator/=( Optional< Vec4T< ValueT > > const & rhs )
	{
		if ( areOptionalEnabled( *this, rhs ) )
		{
			addStmt( *findContainer( *this, rhs )
				, stmt::makeSimple( expr::makeDivideAssign( getType()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	template< typename ValueT >
	Optional< Vec4T< ValueT > > & Optional< Vec4T< ValueT > >::operator+=( ValueT const & rhs )
	{
		if ( areOptionalEnabled( *this, rhs ) )
		{
			addStmt( *findContainer( *this, rhs )
				, stmt::makeSimple( expr::makeAddAssign( getType()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	template< typename ValueT >
	Optional< Vec4T< ValueT > > & Optional< Vec4T< ValueT > >::operator-=( ValueT const & rhs )
	{
		if ( areOptionalEnabled( *this, rhs ) )
		{
			addStmt( *findContainer( *this, rhs )
				, stmt::makeSimple( expr::makeMinusAssign( getType()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	template< typename ValueT >
	Optional< Vec4T< ValueT > > & Optional< Vec4T< ValueT > >::operator*=( ValueT const & rhs )
	{
		if ( areOptionalEnabled( *this, rhs ) )
		{
			addStmt( *findContainer( *this, rhs )
				, stmt::makeSimple( expr::makeTimesAssign( getType()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	template< typename ValueT >
	Optional< Vec4T< ValueT > > & Optional< Vec4T< ValueT > >::operator/=( ValueT const & rhs )
	{
		if ( areOptionalEnabled( *this, rhs ) )
		{
			addStmt( *findContainer( *this, rhs )
				, stmt::makeSimple( expr::makeDivideAssign( getType()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	template< typename ValueT >
	Optional< Vec4T< ValueT > > & Optional< Vec4T< ValueT > >::operator+=( Optional< ValueT > const & rhs )
	{
		if ( areOptionalEnabled( *this, rhs ) )
		{
			addStmt( *findContainer( *this, rhs )
				, stmt::makeSimple( expr::makeAddAssign( getType()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	template< typename ValueT >
	Optional< Vec4T< ValueT > > & Optional< Vec4T< ValueT > >::operator-=( Optional< ValueT > const & rhs )
	{
		if ( areOptionalEnabled( *this, rhs ) )
		{
			addStmt( *findContainer( *this, rhs )
				, stmt::makeSimple( expr::makeMinusAssign( getType()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	template< typename ValueT >
	Optional< Vec4T< ValueT > > & Optional< Vec4T< ValueT > >::operator*=( Optional< ValueT > const & rhs )
	{
		if ( areOptionalEnabled( *this, rhs ) )
		{
			addStmt( *findContainer( *this, rhs )
				, stmt::makeSimple( expr::makeTimesAssign( getType()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	template< typename ValueT >
	Optional< Vec4T< ValueT > > & Optional< Vec4T< ValueT > >::operator/=( Optional< ValueT > const & rhs )
	{
		if ( areOptionalEnabled( *this, rhs ) )
		{
			addStmt( *findContainer( *this, rhs )
				, stmt::makeSimple( expr::makeDivideAssign( getType()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	//*************************************************************************

	template< typename ValueT >
	inline Vec4T< ValueT > operator+( ValueT const & lhs
		, Vec4T< ValueT > const & rhs )
	{
		return Vec4T< ValueT >{ findShader( lhs, rhs )
			, expr::makeAdd( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline Vec4T< ValueT > operator+( Vec4T< ValueT > const & lhs
		, ValueT const & rhs )
	{
		return Vec4T< ValueT >{ findShader( lhs, rhs )
			, expr::makeAdd( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline Vec4T< ValueT > operator+( Vec4T< ValueT > const & lhs
		, Vec4T< ValueT > const & rhs )
	{
		return Vec4T< ValueT >{ findShader( lhs, rhs )
			, expr::makeAdd( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator+( Optional< ValueT > const & lhs
		, Vec4T< ValueT > const & rhs )
	{
		return Optional< Vec4T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeAdd( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator+( Optional< Vec4T< ValueT > > const & lhs
		, ValueT const & rhs )
	{
		return Optional< Vec4T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeAdd( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator+( Optional< Vec4T< ValueT > > const & lhs
		, Vec4T< ValueT > const & rhs )
	{
		return Optional< Vec4T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeAdd( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator+( ValueT const & lhs
		, Optional< Vec4T< ValueT > > const & rhs )
	{
		return Optional< Vec4T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeAdd( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator+( Vec4T< ValueT > const & lhs
		, Optional< ValueT > const & rhs )
	{
		return Optional< Vec4T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeAdd( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator+( Vec4T< ValueT > const & lhs
		, Optional< Vec4T< ValueT > > const & rhs )
	{
		return Optional< Vec4T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeAdd( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator+( Optional< ValueT > const & lhs
		, Optional< Vec4T< ValueT > > const & rhs )
	{
		return Optional< Vec4T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeAdd( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator+( Optional< Vec4T< ValueT > > const & lhs
		, Optional< ValueT > const & rhs )
	{
		return Optional< Vec4T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeAdd( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator+( Optional< Vec4T< ValueT > > const & lhs
		, Optional< Vec4T< ValueT > > const & rhs )
	{
		return Optional< Vec4T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeAdd( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Vec4T< ValueT > operator-( ValueT const & lhs
		, Vec4T< ValueT > const & rhs )
	{
		return Vec4T< ValueT >{ findShader( lhs, rhs )
			, expr::makeMinus( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline Vec4T< ValueT > operator-( Vec4T< ValueT > const & lhs
		, ValueT const & rhs )
	{
		return Vec4T< ValueT >{ findShader( lhs, rhs )
			, expr::makeMinus( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline Vec4T< ValueT > operator-( Vec4T< ValueT > const & lhs
		, Vec4T< ValueT > const & rhs )
	{
		return Vec4T< ValueT >{ findShader( lhs, rhs )
			, expr::makeMinus( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator-( Optional< ValueT > const & lhs
		, Vec4T< ValueT > const & rhs )
	{
		return Optional< Vec4T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeMinus( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator-( Optional< Vec4T< ValueT > > const & lhs
		, ValueT const & rhs )
	{
		return Optional< Vec4T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeMinus( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator-( Optional< Vec4T< ValueT > > const & lhs
		, Vec4T< ValueT > const & rhs )
	{
		return Optional< Vec4T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeMinus( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator-( ValueT const & lhs
		, Optional< Vec4T< ValueT > > const & rhs )
	{
		return Optional< Vec4T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeMinus( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator-( Vec4T< ValueT > const & lhs
		, Optional< ValueT > const & rhs )
	{
		return Optional< Vec4T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeMinus( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator-( Vec4T< ValueT > const & lhs
		, Optional< Vec4T< ValueT > > const & rhs )
	{
		return Optional< Vec4T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeMinus( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator-( Optional< ValueT > const & lhs
		, Optional< Vec4T< ValueT > > const & rhs )
	{
		return Optional< Vec4T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeMinus( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator-( Optional< Vec4T< ValueT > > const & lhs
		, Optional< ValueT > const & rhs )
	{
		return Optional< Vec4T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeMinus( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator-( Optional< Vec4T< ValueT > > const & lhs
		, Optional< Vec4T< ValueT > > const & rhs )
	{
		return Optional< Vec4T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeMinus( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Vec4T< ValueT > operator*( ValueT const & lhs
		, Vec4T< ValueT > const & rhs )
	{
		return Vec4T< ValueT >{ findShader( lhs, rhs )
			, expr::makeTimes( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline Vec4T< ValueT > operator*( Vec4T< ValueT > const & lhs
		, ValueT const & rhs )
	{
		return Vec4T< ValueT >{ findShader( lhs, rhs )
			, expr::makeTimes( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline Vec4T< ValueT > operator*( Vec4T< ValueT > const & lhs
		, Vec4T< ValueT > const & rhs )
	{
		return Vec4T< ValueT >{ findShader( lhs, rhs )
			, expr::makeTimes( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator*( Optional< ValueT > const & lhs
		, Vec4T< ValueT > const & rhs )
	{
		return Optional< Vec4T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeTimes( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator*( Optional< Vec4T< ValueT > > const & lhs
		, ValueT const & rhs )
	{
		return Optional< Vec4T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeTimes( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator*( Optional< Vec4T< ValueT > > const & lhs
		, Vec4T< ValueT > const & rhs )
	{
		return Optional< Vec4T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeTimes( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator*( ValueT const & lhs
		, Optional< Vec4T< ValueT > > const & rhs )
	{
		return Optional< Vec4T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeTimes( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator*( Vec4T< ValueT > const & lhs
		, Optional< ValueT > const & rhs )
	{
		return Optional< Vec4T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeTimes( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator*( Vec4T< ValueT > const & lhs
		, Optional< Vec4T< ValueT > > const & rhs )
	{
		return Optional< Vec4T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeTimes( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator*( Optional< ValueT > const & lhs
		, Optional< Vec4T< ValueT > > const & rhs )
	{
		return Optional< Vec4T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeTimes( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator*( Optional< Vec4T< ValueT > > const & lhs
		, Optional< ValueT > const & rhs )
	{
		return Optional< Vec4T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeTimes( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator*( Optional< Vec4T< ValueT > > const & lhs
		, Optional< Vec4T< ValueT > > const & rhs )
	{
		return Optional< Vec4T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeTimes( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Vec4T< ValueT > operator/( Vec4T< ValueT > const & lhs
		, Vec4T< ValueT > const & rhs )
	{
		return Vec4T< ValueT >{ findShader( lhs, rhs )
			, expr::makeDivide( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline Vec4T< ValueT > operator/( Vec4T< ValueT > const & lhs
		, ValueT const & rhs )
	{
		return Vec4T< ValueT >{ findShader( lhs, rhs )
			, expr::makeDivide( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator/( Optional< Vec4T< ValueT > > const & lhs
		, Vec4T< ValueT > const & rhs )
	{
		return Optional< Vec4T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeDivide( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator/( Optional< Vec4T< ValueT > > const & lhs
		, ValueT const & rhs )
	{
		return Optional< Vec4T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeDivide( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator/( Vec4T< ValueT > const & lhs
		, Optional< Vec4T< ValueT > > const & rhs )
	{
		return Optional< Vec4T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeDivide( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator/( Vec4T< ValueT > const & lhs
		, Optional< ValueT > const & rhs )
	{
		return Optional< Vec4T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeDivide( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator/( Optional< Vec4T< ValueT > > const & lhs
		, Optional< Vec4T< ValueT > > const & rhs )
	{
		return Optional< Vec4T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeDivide( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator/( Optional< Vec4T< ValueT > > const & lhs
		, Optional< ValueT > const & rhs )
	{
		return Optional< Vec4T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeDivide( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	//*************************************************************************
}
