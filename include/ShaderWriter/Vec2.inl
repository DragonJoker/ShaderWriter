/*
See LICENSE file in root folder
*/
namespace sdw
{
	//*************************************************************************

	template< typename ValueT >
	inline Vec2T< ValueT >::Vec2T( Shader * shader
		, expr::ExprPtr expr )
		: Value{ shader, std::move( expr ) }
	{
	}

	template< typename ValueT >
	inline Vec2T< ValueT > & Vec2T< ValueT >::operator=( Vec2T< ValueT > const & rhs )
	{
		if ( getContainer() )
		{
			addStmt( *findContainer( *this, rhs )
				, stmt::makeSimple( expr::makeAssign( getType()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}
		else
		{
			Value::operator=( rhs );
		}

		return *this;
	}

	template< typename ValueT >
	template< typename IndexT >
	inline ValueT Vec2T< ValueT >::operator[]( IndexT const & rhs )const
	{
		return ValueT{ findShader( *this, rhs )
			, expr::makeArrayAccess( makeType( TypeTraits< ValueT >::TypeEnum )
				, makeExpr( *this )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	Vec2T< ValueT > & Vec2T< ValueT >::operator+=( Vec2T< ValueT > const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeAddAssign( getType()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	template< typename ValueT >
	Vec2T< ValueT > & Vec2T< ValueT >::operator-=( Vec2T< ValueT > const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeMinusAssign( getType()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	template< typename ValueT >
	Vec2T< ValueT > & Vec2T< ValueT >::operator*=( Vec2T< ValueT > const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeTimesAssign( getType()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	template< typename ValueT >
	Vec2T< ValueT > & Vec2T< ValueT >::operator+=( Optional< Vec2T< ValueT > > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *findContainer( *this, rhs )
				, stmt::makeSimple( expr::makeAddAssign( getType()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}
		return *this;
	}

	template< typename ValueT >
	Vec2T< ValueT > & Vec2T< ValueT >::operator-=( Optional< Vec2T< ValueT > > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *findContainer( *this, rhs )
				, stmt::makeSimple( expr::makeMinusAssign( getType()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}
		return *this;
	}

	template< typename ValueT >
	Vec2T< ValueT > & Vec2T< ValueT >::operator*=( Optional< Vec2T< ValueT > > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *findContainer( *this, rhs )
				, stmt::makeSimple( expr::makeTimesAssign( getType()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}
		return *this;
	}

	template< typename ValueT >
	Vec2T< ValueT > & Vec2T< ValueT >::operator+=( ValueT const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeAddAssign( getType()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	template< typename ValueT >
	Vec2T< ValueT > & Vec2T< ValueT >::operator-=( ValueT const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeMinusAssign( getType()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	template< typename ValueT >
	Vec2T< ValueT > & Vec2T< ValueT >::operator*=( ValueT const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeTimesAssign( getType()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	template< typename ValueT >
	Vec2T< ValueT > & Vec2T< ValueT >::operator/=( ValueT const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeDivideAssign( getType()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	template< typename ValueT >
	Vec2T< ValueT > & Vec2T< ValueT >::operator+=( Optional< ValueT > const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeAddAssign( getType()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	template< typename ValueT >
	Vec2T< ValueT > & Vec2T< ValueT >::operator-=( Optional< ValueT > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *findContainer( *this, rhs )
				, stmt::makeSimple( expr::makeMinusAssign( getType()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}
		return *this;
	}

	template< typename ValueT >
	Vec2T< ValueT > & Vec2T< ValueT >::operator*=( Optional< ValueT > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *findContainer( *this, rhs )
				, stmt::makeSimple( expr::makeTimesAssign( getType()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}
		return *this;
	}

	template< typename ValueT >
	Vec2T< ValueT > & Vec2T< ValueT >::operator/=( Optional< ValueT > const & rhs )
	{
		if ( rhs.isEnabled() )
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
	inline Vec2T< ValueT > operator+( ValueT const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return Vec2T< ValueT >{ findShader( lhs, rhs )
			, expr::makeAdd( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline Vec2T< ValueT > operator+( Vec2T< ValueT > const & lhs
		, ValueT const & rhs )
	{
		return Vec2T< ValueT >{ findShader( lhs, rhs )
			, expr::makeAdd( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline Vec2T< ValueT > operator+( Vec2T< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return Vec2T< ValueT >{ findShader( lhs, rhs )
			, expr::makeAdd( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator+( Optional< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeAdd( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator+( Optional< Vec2T< ValueT > > const & lhs
		, ValueT const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeAdd( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator+( Optional< Vec2T< ValueT > > const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeAdd( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator+( ValueT const & lhs
		, Optional< Vec2T< ValueT > > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeAdd( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator+( Vec2T< ValueT > const & lhs
		, Optional< ValueT > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeAdd( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator+( Vec2T< ValueT > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeAdd( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator+( Optional< ValueT > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeAdd( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator+( Optional< Vec2T< ValueT > > const & lhs
		, Optional< ValueT > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeAdd( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator+( Optional< Vec2T< ValueT > > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeAdd( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Vec2T< ValueT > operator-( ValueT const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return Vec2T< ValueT >{ findShader( lhs, rhs )
			, expr::makeMinus( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline Vec2T< ValueT > operator-( Vec2T< ValueT > const & lhs
		, ValueT const & rhs )
	{
		return Vec2T< ValueT >{ findShader( lhs, rhs )
			, expr::makeMinus( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline Vec2T< ValueT > operator-( Vec2T< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return Vec2T< ValueT >{ findShader( lhs, rhs )
			, expr::makeMinus( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator-( Optional< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeMinus( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator-( Optional< Vec2T< ValueT > > const & lhs
		, ValueT const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeMinus( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator-( Optional< Vec2T< ValueT > > const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeMinus( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator-( ValueT const & lhs
		, Optional< Vec2T< ValueT > > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeMinus( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator-( Vec2T< ValueT > const & lhs
		, Optional< ValueT > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeMinus( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator-( Vec2T< ValueT > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeMinus( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator-( Optional< ValueT > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeMinus( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator-( Optional< Vec2T< ValueT > > const & lhs
		, Optional< ValueT > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeMinus( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator-( Optional< Vec2T< ValueT > > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeMinus( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}
	
	template< typename ValueT >
	inline Vec2T< ValueT > operator*( ValueT const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return Vec2T< ValueT >{ findShader( lhs, rhs )
			, expr::makeTimes( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline Vec2T< ValueT > operator*( Vec2T< ValueT > const & lhs
		, ValueT const & rhs )
	{
		return Vec2T< ValueT >{ findShader( lhs, rhs )
			, expr::makeTimes( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline Vec2T< ValueT > operator*( Vec2T< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return Vec2T< ValueT >{ findShader( lhs, rhs )
			, expr::makeTimes( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator*( Optional< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeTimes( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator*( Optional< Vec2T< ValueT > > const & lhs
		, ValueT const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeTimes( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator*( Optional< Vec2T< ValueT > > const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeTimes( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator*( ValueT const & lhs
		, Optional< Vec2T< ValueT > > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeTimes( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator*( Vec2T< ValueT > const & lhs
		, Optional< ValueT > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeTimes( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator*( Vec2T< ValueT > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeTimes( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator*( Optional< ValueT > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeTimes( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator*( Optional< Vec2T< ValueT > > const & lhs
		, Optional< ValueT > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeTimes( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator*( Optional< Vec2T< ValueT > > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeTimes( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Vec2T< ValueT > operator/( Vec2T< ValueT > const & lhs
		, ValueT const & rhs )
	{
		return Vec2T< ValueT >{ findShader( lhs, rhs )
			, expr::makeDivide( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator/( Optional< Vec2T< ValueT > > const & lhs
		, ValueT const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeDivide( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator/( Vec2T< ValueT > const & lhs
		, Optional< ValueT > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeDivide( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator/( Optional< Vec2T< ValueT > > const & lhs
		, Optional< ValueT > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeDivide( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	//*************************************************************************
}
