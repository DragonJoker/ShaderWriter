/*
See LICENSE file in root folder
*/
namespace sdw
{
	//*************************************************************************

	template< typename ValueT >
	inline Vec2T< ValueT >::Vec2T( stmt::Container * container
		, expr::ExprPtr expr )
		: Value{ container, std::move( expr ) }
	{
	}

	template< typename ValueT >
	inline Vec2T< ValueT > & Vec2T< ValueT >::operator=( Vec2T< ValueT > const & rhs )
	{
		if ( m_container )
		{
			addStmt( *m_container
				, stmt::makeSimple( expr::makeAssign( makeType( m_expr->get()->getKind() )
					, make( m_expr )
					, make( rhs ) ) ) );
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
	inline ValueT Vec2T< ValueT >::operator[]( IndexT const & rhs )const
	{
		return ValueT{ m_container
			, expr::makeArrayAccess( makeType( TypeTraits< ValueT >::TypeEnum )
				, make( m_expr )
				, make( rhs ) ) };
	}

	template< typename ValueT >
	Vec2T< ValueT > & Vec2T< ValueT >::operator+=( Vec2T< ValueT > const & rhs )
	{
		addStmt( *m_container, stmt::makeSimple( expr::makeAddAssign( m_expr->get()
			, make( m_expr )
			, make( rhs ) ) ) );
		return *this;
	}

	template< typename ValueT >
	Vec2T< ValueT > & Vec2T< ValueT >::operator-=( Vec2T< ValueT > const & rhs )
	{
		addStmt( *m_container, stmt::makeSimple( expr::makeMinusAssign( m_expr->get()
			, make( m_expr )
			, make( rhs ) ) ) );
		return *this;
	}

	template< typename ValueT >
	Vec2T< ValueT > & Vec2T< ValueT >::operator*=( Vec2T< ValueT > const & rhs )
	{
		addStmt( *m_container, stmt::makeSimple( expr::makeTimesAssign( m_expr->get()
			, make( m_expr )
			, make( rhs ) ) ) );
		return *this;
	}

	template< typename ValueT >
	Vec2T< ValueT > & Vec2T< ValueT >::operator+=( Optional< Vec2T< ValueT > > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *m_container, stmt::makeSimple( expr::makeAddAssign( m_expr->get()
				, make( m_expr )
				, make( rhs ) ) ) );
		}
		return *this;
	}

	template< typename ValueT >
	Vec2T< ValueT > & Vec2T< ValueT >::operator-=( Optional< Vec2T< ValueT > > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *m_container, stmt::makeSimple( expr::makeMinusAssign( m_expr->get()
				, make( m_expr )
				, make( rhs ) ) ) );
		}
		return *this;
	}

	template< typename ValueT >
	Vec2T< ValueT > & Vec2T< ValueT >::operator*=( Optional< Vec2T< ValueT > > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *m_container, stmt::makeSimple( expr::makeTimesAssign( m_expr->get()
				, make( m_expr )
				, make( rhs ) ) ) );
		}
		return *this;
	}

	template< typename ValueT >
	Vec2T< ValueT > & Vec2T< ValueT >::operator+=( ValueT rhs )
	{
		addStmt( *m_container, stmt::makeSimple( expr::makeAddAssign( m_expr->get()
			, make( m_expr )
			, make( rhs ) ) ) );
		return *this;
	}

	template< typename ValueT >
	Vec2T< ValueT > & Vec2T< ValueT >::operator-=( ValueT rhs )
	{
		addStmt( *m_container, stmt::makeSimple( expr::makeMinusAssign( m_expr->get()
			, make( m_expr )
			, make( rhs ) ) ) );
		return *this;
	}

	template< typename ValueT >
	Vec2T< ValueT > & Vec2T< ValueT >::operator*=( ValueT rhs )
	{
		addStmt( *m_container, stmt::makeSimple( expr::makeTimesAssign( m_expr->get()
			, make( m_expr )
			, make( rhs ) ) ) );
		return *this;
	}

	template< typename ValueT >
	Vec2T< ValueT > & Vec2T< ValueT >::operator/=( ValueT rhs )
	{
		addStmt( *m_container, stmt::makeSimple( expr::makeDivideAssign( m_expr->get()
			, make( m_expr )
			, make( rhs ) ) ) );
		return *this;
	}

	//*************************************************************************

	template< typename ValueT >
	inline Vec2T< ValueT > operator+( ValueT const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return Vec2T< ValueT >{ findContainer( lhs, rhs )
			, expr::makeAdd( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, make( lhs )
				, make( rhs ) ) };
	}

	template< typename ValueT >
	inline Vec2T< ValueT > operator+( Vec2T< ValueT > const & lhs
		, ValueT const & rhs )
	{
		return Vec2T< ValueT >{ findContainer( lhs, rhs )
			, expr::makeAdd( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, make( lhs )
				, make( rhs ) ) };
	}

	template< typename ValueT >
	inline Vec2T< ValueT > operator+( Vec2T< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return Vec2T< ValueT >{ findContainer( lhs, rhs )
			, expr::makeAdd( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, make( lhs )
				, make( rhs ) ) };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator+( Optional< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findContainer( lhs, rhs )
			, expr::makeAdd( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, make( lhs )
				, make( rhs ) )
			, lhs.isEnabled() };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator+( Optional< Vec2T< ValueT > > const & lhs
		, ValueT const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findContainer( lhs, rhs )
			, expr::makeAdd( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, make( lhs )
				, make( rhs ) )
			, lhs.isEnabled() };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator+( Optional< Vec2T< ValueT > > const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findContainer( lhs, rhs )
			, expr::makeAdd( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, make( lhs )
				, make( rhs ) )
			, lhs.isEnabled() };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator+( ValueT const & lhs
		, Optional< Vec2T< ValueT > > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findContainer( lhs, rhs )
			, expr::makeAdd( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, make( lhs )
				, make( rhs ) )
			, rhs.isEnabled() };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator+( Vec2T< ValueT > const & lhs
		, Optional< ValueT > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findContainer( lhs, rhs )
			, expr::makeAdd( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, make( lhs )
				, make( rhs ) )
			, rhs.isEnabled() };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator+( Vec2T< ValueT > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findContainer( lhs, rhs )
			, expr::makeAdd( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, make( lhs )
				, make( rhs ) )
			, rhs.isEnabled() };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator+( Optional< ValueT > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findContainer( lhs, rhs )
			, expr::makeAdd( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, make( lhs )
				, make( rhs ) )
			, lhs.isEnabled() && rhs.isEnabled() };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator+( Optional< Vec2T< ValueT > > const & lhs
		, Optional< ValueT > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findContainer( lhs, rhs )
			, expr::makeAdd( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, make( lhs )
				, make( rhs ) )
			, lhs.isEnabled() && rhs.isEnabled() };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator+( Optional< Vec2T< ValueT > > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findContainer( lhs, rhs )
			, expr::makeAdd( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, make( lhs )
				, make( rhs ) )
			, lhs.isEnabled() && rhs.isEnabled() };
	}

	template< typename ValueT >
	inline Vec2T< ValueT > operator-( ValueT const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return Vec2T< ValueT >{ findContainer( lhs, rhs )
			, expr::makeMinus( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, make( lhs )
				, make( rhs ) ) };
	}

	template< typename ValueT >
	inline Vec2T< ValueT > operator-( Vec2T< ValueT > const & lhs
		, ValueT const & rhs )
	{
		return Vec2T< ValueT >{ findContainer( lhs, rhs )
			, expr::makeMinus( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, make( lhs )
				, make( rhs ) ) };
	}

	template< typename ValueT >
	inline Vec2T< ValueT > operator-( Vec2T< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return Vec2T< ValueT >{ findContainer( lhs, rhs )
			, expr::makeMinus( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, make( lhs )
				, make( rhs ) ) };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator-( Optional< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findContainer( lhs, rhs )
			, expr::makeMinus( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, make( lhs )
				, make( rhs ) )
			, lhs.isEnabled() };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator-( Optional< Vec2T< ValueT > > const & lhs
		, ValueT const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findContainer( lhs, rhs )
			, expr::makeMinus( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, make( lhs )
				, make( rhs ) )
			, lhs.isEnabled() };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator-( Optional< Vec2T< ValueT > > const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findContainer( lhs, rhs )
			, expr::makeMinus( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, make( lhs )
				, make( rhs ) )
			, lhs.isEnabled() };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator-( ValueT const & lhs
		, Optional< Vec2T< ValueT > > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findContainer( lhs, rhs )
			, expr::makeMinus( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, make( lhs )
				, make( rhs ) )
			, rhs.isEnabled() };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator-( Vec2T< ValueT > const & lhs
		, Optional< ValueT > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findContainer( lhs, rhs )
			, expr::makeMinus( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, make( lhs )
				, make( rhs ) )
			, rhs.isEnabled() };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator-( Vec2T< ValueT > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findContainer( lhs, rhs )
			, expr::makeMinus( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, make( lhs )
				, make( rhs ) )
			, rhs.isEnabled() };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator-( Optional< ValueT > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findContainer( lhs, rhs )
			, expr::makeMinus( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, make( lhs )
				, make( rhs ) )
			, lhs.isEnabled() && rhs.isEnabled() };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator-( Optional< Vec2T< ValueT > > const & lhs
		, Optional< ValueT > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findContainer( lhs, rhs )
			, expr::makeMinus( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, make( lhs )
				, make( rhs ) )
			, lhs.isEnabled() && rhs.isEnabled() };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator-( Optional< Vec2T< ValueT > > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findContainer( lhs, rhs )
			, expr::makeMinus( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, make( lhs )
				, make( rhs ) )
			, lhs.isEnabled() && rhs.isEnabled() };
	}
	
	template< typename ValueT >
	inline Vec2T< ValueT > operator*( ValueT const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return Vec2T< ValueT >{ findContainer( lhs, rhs )
			, expr::makeTimes( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, make( lhs )
				, make( rhs ) ) };
	}

	template< typename ValueT >
	inline Vec2T< ValueT > operator*( Vec2T< ValueT > const & lhs
		, ValueT const & rhs )
	{
		return Vec2T< ValueT >{ findContainer( lhs, rhs )
			, expr::makeTimes( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, make( lhs )
				, make( rhs ) ) };
	}

	template< typename ValueT >
	inline Vec2T< ValueT > operator*( Vec2T< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return Vec2T< ValueT >{ findContainer( lhs, rhs )
			, expr::makeTimes( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, make( lhs )
				, make( rhs ) ) };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator*( Optional< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findContainer( lhs, rhs )
			, expr::makeTimes( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, make( lhs )
				, make( rhs ) )
			, lhs.isEnabled() };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator*( Optional< Vec2T< ValueT > > const & lhs
		, ValueT const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findContainer( lhs, rhs )
			, expr::makeTimes( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, make( lhs )
				, make( rhs ) )
			, lhs.isEnabled() };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator*( Optional< Vec2T< ValueT > > const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findContainer( lhs, rhs )
			, expr::makeTimes( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, make( lhs )
				, make( rhs ) )
			, lhs.isEnabled() };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator*( ValueT const & lhs
		, Optional< Vec2T< ValueT > > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findContainer( lhs, rhs )
			, expr::makeTimes( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, make( lhs )
				, make( rhs ) )
			, rhs.isEnabled() };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator*( Vec2T< ValueT > const & lhs
		, Optional< ValueT > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findContainer( lhs, rhs )
			, expr::makeTimes( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, make( lhs )
				, make( rhs ) )
			, rhs.isEnabled() };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator*( Vec2T< ValueT > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findContainer( lhs, rhs )
			, expr::makeTimes( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, make( lhs )
				, make( rhs ) )
			, rhs.isEnabled() };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator*( Optional< ValueT > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findContainer( lhs, rhs )
			, expr::makeTimes( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, make( lhs )
				, make( rhs ) )
			, lhs.isEnabled() && rhs.isEnabled() };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator*( Optional< Vec2T< ValueT > > const & lhs
		, Optional< ValueT > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findContainer( lhs, rhs )
			, expr::makeTimes( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, make( lhs )
				, make( rhs ) )
			, lhs.isEnabled() && rhs.isEnabled() };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator*( Optional< Vec2T< ValueT > > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findContainer( lhs, rhs )
			, expr::makeTimes( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, make( lhs )
				, make( rhs ) )
			, lhs.isEnabled() && rhs.isEnabled() };
	}

	template< typename ValueT >
	inline Vec2T< ValueT > operator/( Vec2T< ValueT > const & lhs
		, ValueT const & rhs )
	{
		return Vec2T< ValueT >{ findContainer( lhs, rhs )
			, expr::makeDivide( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, make( lhs )
				, make( rhs ) ) };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator/( Optional< Vec2T< ValueT > > const & lhs
		, ValueT const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findContainer( lhs, rhs )
			, expr::makeDivide( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, make( lhs )
				, make( rhs ) )
			, lhs.isEnabled() };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator/( Vec2T< ValueT > const & lhs
		, Optional< ValueT > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findContainer( lhs, rhs )
			, expr::makeDivide( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, make( lhs )
				, make( rhs ) )
			, rhs.isEnabled() };
	}

	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator/( Optional< Vec2T< ValueT > > const & lhs
		, Optional< ValueT > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findContainer( lhs, rhs )
			, expr::makeDivide( makeType( TypeTraits< Vec2T< ValueT > >::TypeEnum )
				, make( lhs )
				, make( rhs ) )
			, lhs.isEnabled() && rhs.isEnabled() };
	}

	//*************************************************************************
}
