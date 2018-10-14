/*
See LICENSE file in root folder
*/
namespace sdw
{
	//*************************************************************************

	template< typename ValueT >
	inline Vec3T< ValueT >::Vec3T( Shader * shader
		, expr::ExprPtr expr )
		: Value{ shader, std::move( expr ) }
	{
	}

	template< typename ValueT >
	inline Vec3T< ValueT > & Vec3T< ValueT >::operator=( Vec3T< ValueT > const & rhs )
	{
		if ( getContainer() )
		{
			addStmt( *findContainer( *this, rhs )
				, stmt::makeSimple( expr::makeAssign( makeType( getType()->getKind() )
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
	inline ValueT Vec3T< ValueT >::operator[]( IndexT const & rhs )const
	{
		return ValueT{ findShader( *this, rhs )
			, expr::makeArrayAccess( makeType( TypeTraits< ValueT >::TypeEnum )
				, makeExpr( *this )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	Vec3T< ValueT > & Vec3T< ValueT >::operator+=( Vec3T< ValueT > const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeAddAssign( getType()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	template< typename ValueT >
	Vec3T< ValueT > & Vec3T< ValueT >::operator-=( Vec3T< ValueT > const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeMinusAssign( getType()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	template< typename ValueT >
	Vec3T< ValueT > & Vec3T< ValueT >::operator*=( Vec3T< ValueT > const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeTimesAssign( getType()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	template< typename ValueT >
	Vec3T< ValueT > & Vec3T< ValueT >::operator+=( Optional< Vec3T< ValueT > > const & rhs )
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
	Vec3T< ValueT > & Vec3T< ValueT >::operator-=( Optional< Vec3T< ValueT > > const & rhs )
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
	Vec3T< ValueT > & Vec3T< ValueT >::operator*=( Optional< Vec3T< ValueT > > const & rhs )
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
	Vec3T< ValueT > & Vec3T< ValueT >::operator+=( ValueT rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeAddAssign( getType()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	template< typename ValueT >
	Vec3T< ValueT > & Vec3T< ValueT >::operator-=( ValueT rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeMinusAssign( getType()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	template< typename ValueT >
	Vec3T< ValueT > & Vec3T< ValueT >::operator*=( ValueT rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeTimesAssign( getType()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	template< typename ValueT >
	Vec3T< ValueT > & Vec3T< ValueT >::operator/=( ValueT rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeDivideAssign( getType()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	//*************************************************************************

	template< typename ValueT >
	inline Vec3T< ValueT > operator+( ValueT const & lhs
		, Vec3T< ValueT > const & rhs )
	{
		return Vec3T< ValueT >{ findShader( lhs, rhs )
			, expr::makeAdd( makeType( TypeTraits< Vec3T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline Vec3T< ValueT > operator+( Vec3T< ValueT > const & lhs
		, ValueT const & rhs )
	{
		return Vec3T< ValueT >{ findShader( lhs, rhs )
			, expr::makeAdd( makeType( TypeTraits< Vec3T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline Vec3T< ValueT > operator+( Vec3T< ValueT > const & lhs
		, Vec3T< ValueT > const & rhs )
	{
		return Vec3T< ValueT >{ findShader( lhs, rhs )
			, expr::makeAdd( makeType( TypeTraits< Vec3T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator+( Optional< ValueT > const & lhs
		, Vec3T< ValueT > const & rhs )
	{
		return Optional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeAdd( makeType( TypeTraits< Vec3T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator+( Optional< Vec3T< ValueT > > const & lhs
		, ValueT const & rhs )
	{
		return Optional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeAdd( makeType( TypeTraits< Vec3T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator+( Optional< Vec3T< ValueT > > const & lhs
		, Vec3T< ValueT > const & rhs )
	{
		return Optional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeAdd( makeType( TypeTraits< Vec3T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator+( ValueT const & lhs
		, Optional< Vec3T< ValueT > > const & rhs )
	{
		return Optional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeAdd( makeType( TypeTraits< Vec3T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator+( Vec3T< ValueT > const & lhs
		, Optional< ValueT > const & rhs )
	{
		return Optional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeAdd( makeType( TypeTraits< Vec3T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator+( Vec3T< ValueT > const & lhs
		, Optional< Vec3T< ValueT > > const & rhs )
	{
		return Optional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeAdd( makeType( TypeTraits< Vec3T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator+( Optional< ValueT > const & lhs
		, Optional< Vec3T< ValueT > > const & rhs )
	{
		return Optional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeAdd( makeType( TypeTraits< Vec3T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator+( Optional< Vec3T< ValueT > > const & lhs
		, Optional< ValueT > const & rhs )
	{
		return Optional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeAdd( makeType( TypeTraits< Vec3T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator+( Optional< Vec3T< ValueT > > const & lhs
		, Optional< Vec3T< ValueT > > const & rhs )
	{
		return Optional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeAdd( makeType( TypeTraits< Vec3T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Vec3T< ValueT > operator-( ValueT const & lhs
		, Vec3T< ValueT > const & rhs )
	{
		return Vec3T< ValueT >{ findShader( lhs, rhs )
			, expr::makeMinus( makeType( TypeTraits< Vec3T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline Vec3T< ValueT > operator-( Vec3T< ValueT > const & lhs
		, ValueT const & rhs )
	{
		return Vec3T< ValueT >{ findShader( lhs, rhs )
			, expr::makeMinus( makeType( TypeTraits< Vec3T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline Vec3T< ValueT > operator-( Vec3T< ValueT > const & lhs
		, Vec3T< ValueT > const & rhs )
	{
		return Vec3T< ValueT >{ findShader( lhs, rhs )
			, expr::makeMinus( makeType( TypeTraits< Vec3T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator-( Optional< ValueT > const & lhs
		, Vec3T< ValueT > const & rhs )
	{
		return Optional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeMinus( makeType( TypeTraits< Vec3T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator-( Optional< Vec3T< ValueT > > const & lhs
		, ValueT const & rhs )
	{
		return Optional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeMinus( makeType( TypeTraits< Vec3T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator-( Optional< Vec3T< ValueT > > const & lhs
		, Vec3T< ValueT > const & rhs )
	{
		return Optional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeMinus( makeType( TypeTraits< Vec3T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator-( ValueT const & lhs
		, Optional< Vec3T< ValueT > > const & rhs )
	{
		return Optional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeMinus( makeType( TypeTraits< Vec3T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator-( Vec3T< ValueT > const & lhs
		, Optional< ValueT > const & rhs )
	{
		return Optional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeMinus( makeType( TypeTraits< Vec3T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator-( Vec3T< ValueT > const & lhs
		, Optional< Vec3T< ValueT > > const & rhs )
	{
		return Optional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeMinus( makeType( TypeTraits< Vec3T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator-( Optional< ValueT > const & lhs
		, Optional< Vec3T< ValueT > > const & rhs )
	{
		return Optional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeMinus( makeType( TypeTraits< Vec3T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator-( Optional< Vec3T< ValueT > > const & lhs
		, Optional< ValueT > const & rhs )
	{
		return Optional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeMinus( makeType( TypeTraits< Vec3T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator-( Optional< Vec3T< ValueT > > const & lhs
		, Optional< Vec3T< ValueT > > const & rhs )
	{
		return Optional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeMinus( makeType( TypeTraits< Vec3T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Vec3T< ValueT > operator*( ValueT const & lhs
		, Vec3T< ValueT > const & rhs )
	{
		return Vec3T< ValueT >{ findShader( lhs, rhs )
			, expr::makeTimes( makeType( TypeTraits< Vec3T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline Vec3T< ValueT > operator*( Vec3T< ValueT > const & lhs
		, ValueT const & rhs )
	{
		return Vec3T< ValueT >{ findShader( lhs, rhs )
			, expr::makeTimes( makeType( TypeTraits< Vec3T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline Vec3T< ValueT > operator*( Vec3T< ValueT > const & lhs
		, Vec3T< ValueT > const & rhs )
	{
		return Vec3T< ValueT >{ findShader( lhs, rhs )
			, expr::makeTimes( makeType( TypeTraits< Vec3T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator*( Optional< ValueT > const & lhs
		, Vec3T< ValueT > const & rhs )
	{
		return Optional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeTimes( makeType( TypeTraits< Vec3T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator*( Optional< Vec3T< ValueT > > const & lhs
		, ValueT const & rhs )
	{
		return Optional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeTimes( makeType( TypeTraits< Vec3T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator*( Optional< Vec3T< ValueT > > const & lhs
		, Vec3T< ValueT > const & rhs )
	{
		return Optional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeTimes( makeType( TypeTraits< Vec3T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator*( ValueT const & lhs
		, Optional< Vec3T< ValueT > > const & rhs )
	{
		return Optional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeTimes( makeType( TypeTraits< Vec3T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator*( Vec3T< ValueT > const & lhs
		, Optional< ValueT > const & rhs )
	{
		return Optional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeTimes( makeType( TypeTraits< Vec3T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator*( Vec3T< ValueT > const & lhs
		, Optional< Vec3T< ValueT > > const & rhs )
	{
		return Optional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeTimes( makeType( TypeTraits< Vec3T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator*( Optional< ValueT > const & lhs
		, Optional< Vec3T< ValueT > > const & rhs )
	{
		return Optional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeTimes( makeType( TypeTraits< Vec3T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator*( Optional< Vec3T< ValueT > > const & lhs
		, Optional< ValueT > const & rhs )
	{
		return Optional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeTimes( makeType( TypeTraits< Vec3T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator*( Optional< Vec3T< ValueT > > const & lhs
		, Optional< Vec3T< ValueT > > const & rhs )
	{
		return Optional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeTimes( makeType( TypeTraits< Vec3T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Vec3T< ValueT > operator/( Vec3T< ValueT > const & lhs
		, ValueT const & rhs )
	{
		return Vec3T< ValueT >{ findShader( lhs, rhs )
			, expr::makeDivide( makeType( TypeTraits< Vec3T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator/( Optional< Vec3T< ValueT > > const & lhs
		, ValueT const & rhs )
	{
		return Optional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeDivide( makeType( TypeTraits< Vec3T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator/( Vec3T< ValueT > const & lhs
		, Optional< ValueT > const & rhs )
	{
		return Optional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeDivide( makeType( TypeTraits< Vec3T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator/( Optional< Vec3T< ValueT > > const & lhs
		, Optional< ValueT > const & rhs )
	{
		return Optional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeDivide( makeType( TypeTraits< Vec3T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	//*************************************************************************
}
