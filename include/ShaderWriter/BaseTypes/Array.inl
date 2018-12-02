/*
See LICENSE file in root folder
*/
namespace sdw
{
	//*********************************************************************************************

	template< typename ValueT >
	Array< ValueT >::Array( Shader * shader
		, expr::ExprPtr expr )
		: Value{ shader, std::move( expr ) }
	{
	}

	template< typename ValueT >
	Array< ValueT >::Array( Array const & rhs )
		: Value{ rhs }
	{
	}

	template< typename ValueT >
	template< typename IndexT >
	ValueT Array< ValueT >::operator[]( IndexT const & offset )const
	{
		return ValueT{ findShader( *this, offset )
			, sdw::makeArrayAccess( getNonArrayType( this->getType() )
				, makeExpr( *this )
				, makeExpr( offset ) ) };
	}

	template< typename ValueT >
	inline ast::type::ArrayPtr Array< ValueT >::makeType( uint32_t arraySize )
	{
		return ast::type::makeArrayType( ValueT::makeType(), arraySize );
	}

	//*********************************************************************************************

	template< typename ValueT >
	expr::ExprPtr makeExpr( Array< ValueT > const & value )
	{
		return makeExpr( value.getExpr() );
	}

	//*********************************************************************************************
}
