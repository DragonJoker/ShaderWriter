/*
See LICENSE file in root folder
*/
namespace sdw
{
	//*************************************************************************

	template< typename ValueT >
	inline Vec4T< ValueT >::Vec4T( stmt::Container * container
		, expr::ExprPtr expr )
		: Value{ container, std::move( expr ) }
	{
	}

	template< typename ValueT >
	inline Vec4T< ValueT > & Vec4T< ValueT >::operator=( Vec4T< ValueT > const & rhs )
	{
		if ( m_container )
		{
			addStmt( *m_container
				, stmt::makeSimple( expr::makeAssign( makeType( m_expr->getType()->getKind() )
					, makeExpr( m_expr )
					, makeExpr( rhs ) ) ) );
		}
		else
		{
			Value::operator=( rhs );
			m_container = rhs.m_container;
		}

		return *this;
	}

	template< typename ValueT >
	template< typename IndexT >
	inline ValueT Vec4T< ValueT >::operator[]( IndexT const & rhs )const
	{
		return ValueT{ m_container
			, expr::makeArrayAccess( makeType( TypeTraits< ValueT >::TypeEnum )
				, makeExpr( m_expr )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	Vec4T< ValueT > & Vec4T< ValueT >::operator+=( Vec4T< ValueT > const & rhs )
	{
		addStmt( *m_container, stmt::makeSimple( expr::makeAddAssign( m_expr->getType()
			, makeExpr( m_expr )
			, makeExpr( rhs ) ) ) );
		return *this;
	}

	template< typename ValueT >
	Vec4T< ValueT > & Vec4T< ValueT >::operator-=( Vec4T< ValueT > const & rhs )
	{
		addStmt( *m_container, stmt::makeSimple( expr::makeMinusAssign( m_expr->getType()
			, makeExpr( m_expr )
			, makeExpr( rhs ) ) ) );
		return *this;
	}

	template< typename ValueT >
	Vec4T< ValueT > & Vec4T< ValueT >::operator*=( Vec4T< ValueT > const & rhs )
	{
		addStmt( *m_container, stmt::makeSimple( expr::makeTimesAssign( m_expr->getType()
			, makeExpr( m_expr )
			, makeExpr( rhs ) ) ) );
		return *this;
	}

	template< typename ValueT >
	Vec4T< ValueT > & Vec4T< ValueT >::operator+=( Optional< Vec4T< ValueT > > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *m_container, stmt::makeSimple( expr::makeAddAssign( m_expr->getType()
				, makeExpr( m_expr )
				, makeExpr( rhs ) ) ) );
		}
		return *this;
	}

	template< typename ValueT >
	Vec4T< ValueT > & Vec4T< ValueT >::operator-=( Optional< Vec4T< ValueT > > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *m_container, stmt::makeSimple( expr::makeMinusAssign( m_expr->getType()
				, makeExpr( m_expr )
				, makeExpr( rhs ) ) ) );
		}
		return *this;
	}

	template< typename ValueT >
	Vec4T< ValueT > & Vec4T< ValueT >::operator*=( Optional< Vec4T< ValueT > > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *m_container, stmt::makeSimple( expr::makeTimesAssign( m_expr->getType()
				, makeExpr( m_expr )
				, makeExpr( rhs ) ) ) );
		}
		return *this;
	}

	template< typename ValueT >
	Vec4T< ValueT > & Vec4T< ValueT >::operator+=( ValueT rhs )
	{
		addStmt( *m_container, stmt::makeSimple( expr::makeAddAssign( m_expr->getType()
			, makeExpr( m_expr )
			, makeExpr( rhs ) ) ) );
		return *this;
	}

	template< typename ValueT >
	Vec4T< ValueT > & Vec4T< ValueT >::operator-=( ValueT rhs )
	{
		addStmt( *m_container, stmt::makeSimple( expr::makeMinusAssign( m_expr->getType()
			, makeExpr( m_expr )
			, makeExpr( rhs ) ) ) );
		return *this;
	}

	template< typename ValueT >
	Vec4T< ValueT > & Vec4T< ValueT >::operator*=( ValueT rhs )
	{
		addStmt( *m_container, stmt::makeSimple( expr::makeTimesAssign( m_expr->getType()
			, makeExpr( m_expr )
			, makeExpr( rhs ) ) ) );
		return *this;
	}

	template< typename ValueT >
	Vec4T< ValueT > & Vec4T< ValueT >::operator/=( ValueT rhs )
	{
		addStmt( *m_container, stmt::makeSimple( expr::makeDivideAssign( m_expr->getType()
			, makeExpr( m_expr )
			, makeExpr( rhs ) ) ) );
		return *this;
	}

	//*************************************************************************

	template< typename ValueT >
	inline Vec4T< ValueT > operator+( ValueT const & lhs
		, Vec4T< ValueT > const & rhs )
	{
		return Vec4T< ValueT >{ findContainer( lhs, rhs )
			, expr::makeAdd( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline Vec4T< ValueT > operator+( Vec4T< ValueT > const & lhs
		, ValueT const & rhs )
	{
		return Vec4T< ValueT >{ findContainer( lhs, rhs )
			, expr::makeAdd( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline Vec4T< ValueT > operator+( Vec4T< ValueT > const & lhs
		, Vec4T< ValueT > const & rhs )
	{
		return Vec4T< ValueT >{ findContainer( lhs, rhs )
			, expr::makeAdd( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator+( Optional< ValueT > const & lhs
		, Vec4T< ValueT > const & rhs )
	{
		return Optional< Vec4T< ValueT > >{ findContainer( lhs, rhs )
			, expr::makeAdd( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, lhs.isEnabled() };
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator+( Optional< Vec4T< ValueT > > const & lhs
		, ValueT const & rhs )
	{
		return Optional< Vec4T< ValueT > >{ findContainer( lhs, rhs )
			, expr::makeAdd( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, lhs.isEnabled() };
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator+( Optional< Vec4T< ValueT > > const & lhs
		, Vec4T< ValueT > const & rhs )
	{
		return Optional< Vec4T< ValueT > >{ findContainer( lhs, rhs )
			, expr::makeAdd( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, lhs.isEnabled() };
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator+( ValueT const & lhs
		, Optional< Vec4T< ValueT > > const & rhs )
	{
		return Optional< Vec4T< ValueT > >{ findContainer( lhs, rhs )
			, expr::makeAdd( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, rhs.isEnabled() };
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator+( Vec4T< ValueT > const & lhs
		, Optional< ValueT > const & rhs )
	{
		return Optional< Vec4T< ValueT > >{ findContainer( lhs, rhs )
			, expr::makeAdd( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, rhs.isEnabled() };
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator+( Vec4T< ValueT > const & lhs
		, Optional< Vec4T< ValueT > > const & rhs )
	{
		return Optional< Vec4T< ValueT > >{ findContainer( lhs, rhs )
			, expr::makeAdd( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, rhs.isEnabled() };
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator+( Optional< ValueT > const & lhs
		, Optional< Vec4T< ValueT > > const & rhs )
	{
		return Optional< Vec4T< ValueT > >{ findContainer( lhs, rhs )
			, expr::makeAdd( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, lhs.isEnabled() && rhs.isEnabled() };
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator+( Optional< Vec4T< ValueT > > const & lhs
		, Optional< ValueT > const & rhs )
	{
		return Optional< Vec4T< ValueT > >{ findContainer( lhs, rhs )
			, expr::makeAdd( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, lhs.isEnabled() && rhs.isEnabled() };
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator+( Optional< Vec4T< ValueT > > const & lhs
		, Optional< Vec4T< ValueT > > const & rhs )
	{
		return Optional< Vec4T< ValueT > >{ findContainer( lhs, rhs )
			, expr::makeAdd( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, lhs.isEnabled() && rhs.isEnabled() };
	}

	template< typename ValueT >
	inline Vec4T< ValueT > operator-( ValueT const & lhs
		, Vec4T< ValueT > const & rhs )
	{
		return Vec4T< ValueT >{ findContainer( lhs, rhs )
			, expr::makeMinus( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline Vec4T< ValueT > operator-( Vec4T< ValueT > const & lhs
		, ValueT const & rhs )
	{
		return Vec4T< ValueT >{ findContainer( lhs, rhs )
			, expr::makeMinus( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline Vec4T< ValueT > operator-( Vec4T< ValueT > const & lhs
		, Vec4T< ValueT > const & rhs )
	{
		return Vec4T< ValueT >{ findContainer( lhs, rhs )
			, expr::makeMinus( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator-( Optional< ValueT > const & lhs
		, Vec4T< ValueT > const & rhs )
	{
		return Optional< Vec4T< ValueT > >{ findContainer( lhs, rhs )
			, expr::makeMinus( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, lhs.isEnabled() };
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator-( Optional< Vec4T< ValueT > > const & lhs
		, ValueT const & rhs )
	{
		return Optional< Vec4T< ValueT > >{ findContainer( lhs, rhs )
			, expr::makeMinus( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, lhs.isEnabled() };
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator-( Optional< Vec4T< ValueT > > const & lhs
		, Vec4T< ValueT > const & rhs )
	{
		return Optional< Vec4T< ValueT > >{ findContainer( lhs, rhs )
			, expr::makeMinus( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, lhs.isEnabled() };
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator-( ValueT const & lhs
		, Optional< Vec4T< ValueT > > const & rhs )
	{
		return Optional< Vec4T< ValueT > >{ findContainer( lhs, rhs )
			, expr::makeMinus( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, rhs.isEnabled() };
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator-( Vec4T< ValueT > const & lhs
		, Optional< ValueT > const & rhs )
	{
		return Optional< Vec4T< ValueT > >{ findContainer( lhs, rhs )
			, expr::makeMinus( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, rhs.isEnabled() };
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator-( Vec4T< ValueT > const & lhs
		, Optional< Vec4T< ValueT > > const & rhs )
	{
		return Optional< Vec4T< ValueT > >{ findContainer( lhs, rhs )
			, expr::makeMinus( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, rhs.isEnabled() };
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator-( Optional< ValueT > const & lhs
		, Optional< Vec4T< ValueT > > const & rhs )
	{
		return Optional< Vec4T< ValueT > >{ findContainer( lhs, rhs )
			, expr::makeMinus( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, lhs.isEnabled() && rhs.isEnabled() };
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator-( Optional< Vec4T< ValueT > > const & lhs
		, Optional< ValueT > const & rhs )
	{
		return Optional< Vec4T< ValueT > >{ findContainer( lhs, rhs )
			, expr::makeMinus( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, lhs.isEnabled() && rhs.isEnabled() };
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator-( Optional< Vec4T< ValueT > > const & lhs
		, Optional< Vec4T< ValueT > > const & rhs )
	{
		return Optional< Vec4T< ValueT > >{ findContainer( lhs, rhs )
			, expr::makeMinus( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, lhs.isEnabled() && rhs.isEnabled() };
	}

	template< typename ValueT >
	inline Vec4T< ValueT > operator*( ValueT const & lhs
		, Vec4T< ValueT > const & rhs )
	{
		return Vec4T< ValueT >{ findContainer( lhs, rhs )
			, expr::makeTimes( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline Vec4T< ValueT > operator*( Vec4T< ValueT > const & lhs
		, ValueT const & rhs )
	{
		return Vec4T< ValueT >{ findContainer( lhs, rhs )
			, expr::makeTimes( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline Vec4T< ValueT > operator*( Vec4T< ValueT > const & lhs
		, Vec4T< ValueT > const & rhs )
	{
		return Vec4T< ValueT >{ findContainer( lhs, rhs )
			, expr::makeTimes( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator*( Optional< ValueT > const & lhs
		, Vec4T< ValueT > const & rhs )
	{
		return Optional< Vec4T< ValueT > >{ findContainer( lhs, rhs )
			, expr::makeTimes( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, lhs.isEnabled() };
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator*( Optional< Vec4T< ValueT > > const & lhs
		, ValueT const & rhs )
	{
		return Optional< Vec4T< ValueT > >{ findContainer( lhs, rhs )
			, expr::makeTimes( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, lhs.isEnabled() };
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator*( Optional< Vec4T< ValueT > > const & lhs
		, Vec4T< ValueT > const & rhs )
	{
		return Optional< Vec4T< ValueT > >{ findContainer( lhs, rhs )
			, expr::makeTimes( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, lhs.isEnabled() };
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator*( ValueT const & lhs
		, Optional< Vec4T< ValueT > > const & rhs )
	{
		return Optional< Vec4T< ValueT > >{ findContainer( lhs, rhs )
			, expr::makeTimes( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, rhs.isEnabled() };
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator*( Vec4T< ValueT > const & lhs
		, Optional< ValueT > const & rhs )
	{
		return Optional< Vec4T< ValueT > >{ findContainer( lhs, rhs )
			, expr::makeTimes( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, rhs.isEnabled() };
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator*( Vec4T< ValueT > const & lhs
		, Optional< Vec4T< ValueT > > const & rhs )
	{
		return Optional< Vec4T< ValueT > >{ findContainer( lhs, rhs )
			, expr::makeTimes( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, rhs.isEnabled() };
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator*( Optional< ValueT > const & lhs
		, Optional< Vec4T< ValueT > > const & rhs )
	{
		return Optional< Vec4T< ValueT > >{ findContainer( lhs, rhs )
			, expr::makeTimes( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, lhs.isEnabled() && rhs.isEnabled() };
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator*( Optional< Vec4T< ValueT > > const & lhs
		, Optional< ValueT > const & rhs )
	{
		return Optional< Vec4T< ValueT > >{ findContainer( lhs, rhs )
			, expr::makeTimes( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, lhs.isEnabled() && rhs.isEnabled() };
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator*( Optional< Vec4T< ValueT > > const & lhs
		, Optional< Vec4T< ValueT > > const & rhs )
	{
		return Optional< Vec4T< ValueT > >{ findContainer( lhs, rhs )
			, expr::makeTimes( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, lhs.isEnabled() && rhs.isEnabled() };
	}

	template< typename ValueT >
	inline Vec4T< ValueT > operator/( Vec4T< ValueT > const & lhs
		, ValueT const & rhs )
	{
		return Vec4T< ValueT >{ findContainer( lhs, rhs )
			, expr::makeDivide( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator/( Optional< Vec4T< ValueT > > const & lhs
		, ValueT const & rhs )
	{
		return Optional< Vec4T< ValueT > >{ findContainer( lhs, rhs )
			, expr::makeDivide( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, lhs.isEnabled() };
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator/( Vec4T< ValueT > const & lhs
		, Optional< ValueT > const & rhs )
	{
		return Optional< Vec4T< ValueT > >{ findContainer( lhs, rhs )
			, expr::makeDivide( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, rhs.isEnabled() };
	}

	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator/( Optional< Vec4T< ValueT > > const & lhs
		, Optional< ValueT > const & rhs )
	{
		return Optional< Vec4T< ValueT > >{ findContainer( lhs, rhs )
			, expr::makeDivide( makeType( TypeTraits< Vec4T< ValueT > >::TypeEnum )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, lhs.isEnabled() && rhs.isEnabled() };
	}

	//*************************************************************************
}
