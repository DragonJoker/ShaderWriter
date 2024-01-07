/*
See LICENSE file in root folder
*/
#ifndef ___SDW_Array_H___
#define ___SDW_Array_H___
#pragma once

#include "Boolean.hpp"

namespace sdw
{
	template< typename ValueT >
	struct Array
		: public Value
	{
		SDW_DeclValue( , Array );

		Array( ShaderWriter & writer
			, expr::ExprPtr expr
			, bool enabled );

		template< ast::type::Kind KindT >
		ValueT operator[]( IntegerValue< KindT > const & offset )const;
		ValueT operator[]( int32_t offset )const;
		ValueT operator[]( uint32_t offset )const;

		template< typename ... ParamsT >
		static ast::type::ArrayPtr makeType( ast::type::TypesCache & cache
			, uint32_t arraySize = ast::type::UnknownArraySize
			, ParamsT && ... params );
	};

	template< typename ValueT >
	expr::ExprPtr makeExpr( Array< ValueT > const & value );
}

#include "Array.inl"

#endif
