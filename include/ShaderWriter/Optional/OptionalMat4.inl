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
	Optional< Mat4T< ValueT > >::Optional( Mat4T< ValueT > const & rhs
		, bool enabled )
		: Mat4T< ValueT >{ rhs }
		, m_enabled{ enabled }
	{
	}

	template< typename ValueT >
	Optional< Mat4T< ValueT > >::Optional( Optional< Mat4T< ValueT > > const & rhs )
		: Mat4T< ValueT >{ rhs }
		, m_enabled{ rhs.m_enabled }
	{
	}

	template< typename ValueT >
	Optional< Mat4T< ValueT > > & Optional< Mat4T< ValueT > >::operator=( Optional< Mat4T< ValueT > > const & rhs )
	{
		if ( this->getContainer() )
		{
			addStmt( *findContainer( *this, rhs )
				, sdw::makeSimple( sdw::makeAssign( makeType( this->getType()->getKind() )
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
			, sdw::makeArrayAccess( makeType( typeEnum< Vec4T< ValueT > > )
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
			, sdw::makeTimes( makeType( typeEnum< Vec4T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Vec4T< ValueT > > operator*( Optional< Mat4T< ValueT > > const & lhs
		, Vec4T< ValueT > const & rhs )
	{
		return Optional< Vec4T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeTimes( makeType( typeEnum< Vec4T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Mat4T< ValueT > > operator*( Optional< Mat4T< ValueT > > const & lhs
		, Mat4T< ValueT > const & rhs )
	{
		return Optional< Mat4T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeTimes( makeType( typeEnum< Mat4T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Vec4T< ValueT > > operator*( Vec4T< ValueT > const & lhs
		, Optional< Mat4T< ValueT > > const & rhs )
	{
		return Optional< Vec4T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeTimes( makeType( typeEnum< Vec4T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Vec4T< ValueT > > operator*( Mat4T< ValueT > const & lhs
		, Optional< Vec4T< ValueT > > const & rhs )
	{
		return Optional< Vec4T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeTimes( makeType( typeEnum< Vec4T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Mat4T< ValueT > > operator*( Mat4T< ValueT > const & lhs
		, Optional< Mat4T< ValueT > > const & rhs )
	{
		return Optional< Mat4T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeTimes( makeType( typeEnum< Mat4T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Vec4T< ValueT > > operator*( Optional< Vec4T< ValueT > > const & lhs
		, Optional< Mat4T< ValueT > > const & rhs )
	{
		return Optional< Vec4T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeTimes( makeType( typeEnum< Vec4T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Vec4T< ValueT > > operator*( Optional< Mat4T< ValueT > > const & lhs
		, Optional< Vec4T< ValueT > > const & rhs )
	{
		return Optional< Vec4T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeTimes( makeType( typeEnum< Vec4T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Mat4T< ValueT > > operator*( Optional< Mat4T< ValueT > > const & lhs
		, Optional< Mat4T< ValueT > > const & rhs )
	{
		return Optional< Mat4T< ValueT > >{ findShader( lhs, rhs )
			, sdw::makeTimes( makeType( typeEnum< Mat4T< ValueT > > )
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}
}
