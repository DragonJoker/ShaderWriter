/*
See LICENSE file in root folder
*/
namespace sdw
{
	template< typename ValueT >
	Optional< Mat2x4T< ValueT > >::Optional( Shader * shader
		, expr::ExprPtr expr
		, bool enabled )
		: Mat2x4T< ValueT >{ shader, std::move( expr ) }
		, m_enabled{ enabled }
	{
	}

	template< typename ValueT >
	Optional< Mat2x4T< ValueT > >::Optional( Mat2x4T< ValueT > const & other
		, bool enabled )
		: Mat2x4T< ValueT >{ other }
		, m_enabled{ enabled }
	{
	}

	template< typename ValueT >
	Optional< Mat2x4T< ValueT > >::Optional( Optional< Mat2x4T< ValueT > > const & rhs )
		: Mat2x4T< ValueT >{ rhs }
		, m_enabled{ other.m_enabled }
	{
	}

	template< typename ValueT >
	Optional< Mat2x4T< ValueT > > & Optional< Mat2x4T< ValueT > >::operator=( Optional< Mat2x4T< ValueT > > const & rhs )
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
	Optional< Vec4T< ValueT > > Optional< Mat2x4T< ValueT > >::operator[]( IndexT const & rhs )const
	{
		return Optional< Vec4T< ValueT > >{ findShader( *this, rhs )
			, sdw::makeArrayAccess( makeType( typeEnum< Vec4T< ValueT > > )
				, makeExpr( *this )
				, makeExpr( rhs ) )
			, areOptionalEnabled( *this, rhs ) };
	}

	template< typename ValueT >
	inline bool Optional< Mat2x4T< ValueT > >::isEnabled()const
	{
		return m_enabled;
	}
}
