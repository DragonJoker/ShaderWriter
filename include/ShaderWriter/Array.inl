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
	template< typename IndexT >
	ValueT Array< ValueT >::operator[]( IndexT const & offset )const
	{
		return ValueT{ findShader( *this, offset )
			, makeArrayAccess( makeType( this->getType()->getKind() )
				, makeExpr( *this )
				, makeExpr( offset ) ) };
	}

	template< typename ValueT >
	expr::ExprPtr makeExpr( Array< ValueT > const & value )
	{
		return makeExpr( value.getExpr() );
	}

	//*********************************************************************************************
}
