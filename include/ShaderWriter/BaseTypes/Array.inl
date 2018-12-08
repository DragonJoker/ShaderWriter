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
	ValueT Array< ValueT >::operator[]( int32_t offset )const
	{
		return ValueT{ findShader( *this, offset )
			, sdw::makeArrayAccess( getNonArrayType( this->getType() )
				, makeExpr( *this )
				, makeExpr( offset ) ) };
	}

	template< typename ValueT >
	ValueT Array< ValueT >::operator[]( uint32_t offset )const
	{
		return ValueT{ findShader( *this, offset )
			, sdw::makeArrayAccess( getNonArrayType( this->getType() )
				, makeExpr( *this )
				, makeExpr( offset ) ) };
	}

	template< typename ValueT >
	inline ast::type::ArrayPtr Array< ValueT >::makeType( ast::type::TypesCache & cache, uint32_t arraySize )
	{
		return cache.getArray( ValueT::makeType( cache ), arraySize );
	}

	//*********************************************************************************************

	template< typename ValueT >
	expr::ExprPtr makeExpr( Array< ValueT > const & value )
	{
		return makeExpr( value.getExpr() );
	}

	//*********************************************************************************************
}
