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
		Array( Shader * shader
			, expr::ExprPtr expr );
		Array( Array const & rhs );
		template< typename IndexT >
		ValueT operator[]( IndexT const & offset )const;
	};

	template< typename ValueT >
	expr::ExprPtr makeExpr( Array< ValueT > const & value );
}

#include "Array.inl"

#endif
