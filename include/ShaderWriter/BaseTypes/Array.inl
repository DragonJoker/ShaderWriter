/*
See LICENSE file in root folder
*/
namespace sdw
{
	//*********************************************************************************************

	template< typename ValueT >
	Array< ValueT >::Array( ShaderWriter & writer
		, expr::ExprPtr expr
		, bool enabled )
		: Value{ writer, std::move( expr ), enabled }
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
		return writeBinOperator< ValueT >( *this, offset, sdw::makeArrayAccess );
	}

	template< typename ValueT >
	ValueT Array< ValueT >::operator[]( int32_t offset )const
	{
		return writeBinOperator< ValueT >( *this, offset, sdw::makeArrayAccess );
	}

	template< typename ValueT >
	ValueT Array< ValueT >::operator[]( uint32_t offset )const
	{
		return writeBinOperator< ValueT >( *this, offset, sdw::makeArrayAccess );
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
		return makeExpr( *value.getWriter(), value.getExpr() );
	}

	//*********************************************************************************************
}
