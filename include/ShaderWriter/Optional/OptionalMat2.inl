/*
See LICENSE file in root folder
*/
namespace sdw
{
	template< typename ValueT >
	Optional< Mat2T< ValueT > >::Optional( Shader * shader
		, expr::ExprPtr expr
		, bool enabled )
		: Mat2T< ValueT >{ shader, std::move( expr ) }
		, m_enabled{ enabled }
	{
	}

	template< typename ValueT >
	Optional< Mat2T< ValueT > >::Optional( Mat2T< ValueT > const & rhs
		, bool enabled )
		: Mat2T< ValueT >{ rhs }
		, m_enabled{ enabled }
	{
	}

	template< typename ValueT >
	Optional< Mat2T< ValueT > >::Optional( Optional< Mat2T< ValueT > > const & rhs )
		: Mat2T< ValueT >{ rhs }
		, m_enabled{ rhs.m_enabled }
	{
	}

	template< typename ValueT >
	Optional< Mat2T< ValueT > > & Optional< Mat2T< ValueT > >::operator=( Optional< Mat2T< ValueT > > const & rhs )
	{
		if ( this->getContainer() )
		{
			addStmt( *findContainer( *this, rhs )
				, sdw::makeSimple( sdw::makeAssign( Mat2T< ValueT >::makeType()
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
	Optional< Vec2T< ValueT > > Optional< Mat2T< ValueT > >::operator[]( IndexT const & rhs )const
	{
		return Optional< Vec2T< ValueT > >{ findShader( *this, rhs )
			, sdw::makeArrayAccess( Vec2T< ValueT >::makeType()
				, makeExpr( *this )
				, makeExpr( rhs ) )
			, areOptionalEnabled( *this, rhs ) };
	}

	template< typename ValueT >
	inline bool Optional< Mat2T< ValueT > >::isEnabled()const
	{
		return m_enabled;
	}

	template< typename ValueT >
	Optional< Vec2T< ValueT > > operator*( Optional< Vec2T< ValueT > > const & lhs,
		Mat2T< ValueT > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeTimes( Vec2T< ValueT >::makeType()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Vec2T< ValueT > > operator*( Optional< Mat2T< ValueT > > const & lhs
		, Vec2T< ValueT > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeTimes( Vec2T< ValueT >::makeType()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Mat2T< ValueT > > operator*( Optional< Mat2T< ValueT > > const & lhs
		, Mat2T< ValueT > const & rhs )
	{
		return Optional< Mat2T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeTimes( Mat2T< ValueT >::makeType()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Vec2T< ValueT > > operator*( Vec2T< ValueT > const & lhs
		, Optional< Mat2T< ValueT > > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeTimes( Vec2T< ValueT >::makeType()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Vec2T< ValueT > > operator*( Mat2T< ValueT > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeTimes( Vec2T< ValueT >::makeType()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Mat2T< ValueT > > operator*( Mat2T< ValueT > const & lhs
		, Optional< Mat2T< ValueT > > const & rhs )
	{
		return Optional< Mat2T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeTimes( Mat2T< ValueT >::makeType()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Vec2T< ValueT > > operator*( Optional< Vec2T< ValueT > > const & lhs
		, Optional< Mat2T< ValueT > > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeTimes( Vec2T< ValueT >::makeType()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Vec2T< ValueT > > operator*( Optional< Mat2T< ValueT > > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs )
	{
		return Optional< Vec2T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeTimes( Vec2T< ValueT >::makeType()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Mat2T< ValueT > > operator*( Optional< Mat2T< ValueT > > const & lhs
		, Optional< Mat2T< ValueT > > const & rhs )
	{
		return Optional< Mat2T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeTimes( Mat2T< ValueT >::makeType()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}
}
