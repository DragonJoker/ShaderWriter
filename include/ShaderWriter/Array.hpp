/*
See LICENSE file in root folder
*/
#ifndef ___Writer_Array_H___
#define ___Writer_Array_H___
#pragma once

#include "Bool.hpp"

namespace sdw
{
	template< typename T >
	struct Array
		: public T
	{
		Array( stmt::Container * container
			, expr::ExprPtr expr );
		template< typename U > T operator[]( U const & offset );
		template< typename U > T operator[]( U const & offset )const;
	};

	template< typename TypeT >
	expr::ExprPtr makeExpr( Array< TypeT > const & value );
}

#include "Array.inl"

#endif
