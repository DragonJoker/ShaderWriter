/*
See LICENSE file in root folder
*/
namespace sdw
{
	template< typename ValueT >
	Optional< Mat4T< ValueT > >::Optional( Shader * shader
		, expr::ExprPtr expr
		, bool enabled )
		: Mat4T< ValueT >{ shader, std::move( expr ) }
		, m_enabled{ enabled }
	{
	}

	template< typename ValueT >
	Optional< Mat4T< ValueT > >::Optional( Mat4T< ValueT > const & other
		, bool enabled )
		: Mat4T< ValueT >{ other }
		, m_enabled{ enabled }
	{
	}

	template< typename ValueT >
	Optional< Mat4T< ValueT > > & Optional< Mat4T< ValueT > >::operator=( Optional< Mat4T< ValueT > > const & rhs )
	{
		if ( this->getContainer() )
		{
			addStmt( *findContainer( *this, rhs )
				, stmt::makeSimple( expr::makeAssign( makeType( this->getType()->getKind() )
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
	Optional< Vec4T< ValueT > > Optional< Mat4T< ValueT > >::operator[]( IndexT const & rhs )const
	{
		return Optional< Vec4T< ValueT > >{ findShader( *this, rhs )
			, expr::makeArrayAccess( makeType( typeEnum< Vec4T< ValueT > > )
				, makeExpr( *this )
				, makeExpr( rhs ) )
			, areOptionalEnabled( *this, rhs ) };
	}

	template< typename ValueT >
	inline bool Optional< Mat4T< ValueT > >::isEnabled()const
	{
		return m_enabled;
	}

	template< typename ValueT >
	Optional< Vec4T< ValueT > > operator*( Optional< Vec4T< ValueT > > const & lhs,
		Mat4T< ValueT > const & rhs )
	{
		return Optional< Vec4T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeTimes( makeType( typeEnum< Vec4T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Vec4T< ValueT > > operator*( Optional< Mat4T< ValueT > > const & lhs
		, Vec4T< ValueT > const & rhs )
	{
		return Optional< Vec4T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeTimes( makeType( typeEnum< Vec4T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Vec4T< ValueT > > operator*( Vec4T< ValueT > const & lhs
		, Optional< Mat4T< ValueT > > const & rhs )
	{
		return Optional< Vec4T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeTimes( makeType( typeEnum< Vec4T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Vec4T< ValueT > > operator*( Mat4T< ValueT > const & lhs
		, Optional< Vec4T< ValueT > > const & rhs )
	{
		return Optional< Vec4T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeTimes( makeType( typeEnum< Vec4T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Vec4T< ValueT > > operator*( Optional< Vec4T< ValueT > > const & lhs
		, Optional< Mat4T< ValueT > > const & rhs )
	{
		return Optional< Vec4T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeTimes( makeType( typeEnum< Vec4T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Vec4T< ValueT > > operator*( Optional< Mat4T< ValueT > > const & lhs
		, Optional< Vec4T< ValueT > > const & rhs )
	{
		return Optional< Vec4T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeTimes( makeType( typeEnum< Vec4T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}
}
