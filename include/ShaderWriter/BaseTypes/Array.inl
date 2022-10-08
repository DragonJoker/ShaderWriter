/*
See LICENSE file in root folder
*/
#include "ShaderWriter/Helpers.hpp"

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
	template< ast::type::Kind KindT >
	ValueT Array< ValueT >::operator[]( IntegerValue< KindT > const & offset )const
	{
		ShaderWriter & writer = sdw::findWriterMandat( *this, offset );
		return ValueT{ writer
			, sdw::makeArrayAccess( ast::type::getNonArrayType( this->getType() )
				, sdw::makeExpr( writer, *this )
				, sdw::makeExpr( writer, offset ) )
			, sdw::areOptionalEnabled( *this, offset ) };
	}

	template< typename ValueT >
	ValueT Array< ValueT >::operator[]( int32_t offset )const
	{
		ShaderWriter & writer = sdw::findWriterMandat( *this, offset );
		return ValueT{ writer
			, sdw::makeArrayAccess( ast::type::getNonArrayType( this->getType() )
				, sdw::makeExpr( writer, *this )
				, sdw::makeExpr( writer, offset ) )
			, sdw::areOptionalEnabled( *this, offset ) };
	}

	template< typename ValueT >
	ValueT Array< ValueT >::operator[]( uint32_t offset )const
	{
		ShaderWriter & writer = sdw::findWriterMandat( *this, offset );
		return ValueT{ writer
			, sdw::makeArrayAccess( ast::type::getNonArrayType( this->getType() )
				, sdw::makeExpr( writer, *this )
				, sdw::makeExpr( writer, offset ) )
			, sdw::areOptionalEnabled( *this, offset ) };
	}

	template< typename ValueT >
	template< typename ... ParamsT >
	inline ast::type::ArrayPtr Array< ValueT >::makeType( ast::type::TypesCache & cache
		, uint32_t arraySize
		, ParamsT && ... params )
	{
		return cache.getArray( ValueT::makeType( cache, std::forward< ParamsT >( params )... ), arraySize );
	}

	//*********************************************************************************************

	template< typename ValueT >
	expr::ExprPtr makeExpr( Array< ValueT > const & value )
	{
		return makeExpr( *value.getWriter(), value.getExpr() );
	}

	//*********************************************************************************************
}
