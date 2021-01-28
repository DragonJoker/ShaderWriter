/*
See LICENSE file in root folder
*/
#ifndef ___SDW_Array_H___
#define ___SDW_Array_H___
#pragma once

#include "Bool.hpp"

namespace sdw
{
	template< typename ValueT >
	struct Array
		: public Value
	{
		Array( ShaderWriter & writer
			, expr::ExprPtr expr
			, bool enabled );
		Array( Array const & rhs );
		template< typename IndexT >
		ValueT operator[]( IndexT const & offset )const;
		ValueT operator[]( int32_t offset )const;
		ValueT operator[]( uint32_t offset )const;

		static inline ast::type::ArrayPtr makeType( ast::type::TypesCache & cache
			, uint32_t arraySize = ast::type::UnknownArraySize );
	};

	template< typename ValueT >
	expr::ExprPtr makeExpr( Array< ValueT > const & value );
}

#include "Array.inl"

#endif
