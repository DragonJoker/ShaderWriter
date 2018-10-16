/*
See LICENSE file in root folder
*/
namespace sdw
{
	template< typename ValueT >
	Optional< Mat3T< ValueT > >::Optional( Shader * shader
		, expr::ExprPtr expr
		, bool enabled )
		: Mat3T< ValueT >{ shader, std::move( expr ) }
		, m_enabled{ enabled }
	{
	}

	template< typename ValueT >
	Optional< Mat3T< ValueT > >::Optional( Mat3T< ValueT > const & other
		, bool enabled )
		: Mat3T< ValueT >{ other }
		, m_enabled{ enabled }
	{
	}

	template< typename ValueT >
	Optional< Mat3T< ValueT > > & Optional< Mat3T< ValueT > >::operator=( Optional< Mat3T< ValueT > > const & rhs )
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
	Optional< Vec3T< ValueT > > Optional< Mat3T< ValueT > >::operator[]( IndexT const & rhs )const
	{
		return Optional< Vec3T< ValueT > >{ findShader( *this, rhs )
			, expr::makeArrayAccess( makeType( typeEnum< Vec3T< ValueT > > )
				, makeExpr( *this )
				, makeExpr( rhs ) )
			, areOptionalEnabled( *this, rhs ) };
	}

	template< typename ValueT >
	inline bool Optional< Mat3T< ValueT > >::isEnabled()const
	{
		return m_enabled;
	}

	template< typename ValueT >
	Optional< Vec3T< ValueT > > operator*( Optional< Vec3T< ValueT > > const & lhs,
		Mat3T< ValueT > const & rhs )
	{
		return Optional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeTimes( makeType( typeEnum< Vec3T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Vec3T< ValueT > > operator*( Optional< Mat3T< ValueT > > const & lhs
		, Vec3T< ValueT > const & rhs )
	{
		return Optional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeTimes( makeType( typeEnum< Vec3T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Vec3T< ValueT > > operator*( Vec3T< ValueT > const & lhs
		, Optional< Mat3T< ValueT > > const & rhs )
	{
		return Optional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeTimes( makeType( typeEnum< Vec3T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Vec3T< ValueT > > operator*( Mat3T< ValueT > const & lhs
		, Optional< Vec3T< ValueT > > const & rhs )
	{
		return Optional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeTimes( makeType( typeEnum< Vec3T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Vec3T< ValueT > > operator*( Optional< Vec3T< ValueT > > const & lhs
		, Optional< Mat3T< ValueT > > const & rhs )
	{
		return Optional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeTimes( makeType( typeEnum< Vec3T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Vec3T< ValueT > > operator*( Optional< Mat3T< ValueT > > const & lhs
		, Optional< Vec3T< ValueT > > const & rhs )
	{
		return Optional< Vec3T< ValueT > >{ findShader( lhs, rhs )
			, expr::makeTimes( makeType( typeEnum< Vec3T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}
}
