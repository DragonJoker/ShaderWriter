/*
See LICENSE file in root folder
*/
#ifndef ___Writer_Array_H___
#define ___Writer_Array_H___
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
		template< typename IndexT >
		ValueT operator[]( IndexT const & offset )const;
	};

	template< typename ValueT >
	expr::ExprPtr makeExpr( Array< ValueT > const & value );
}

#include "Array.inl"

#endif
