/*
See LICENSE file in root folder
*/
#ifndef ___Writer_Float_H___
#define ___Writer_Float_H___
#pragma once

#include "Value.hpp"

namespace sdw
{
	struct Float
		: public Value
	{
		Float( stmt::Container * container
			, expr::ExprPtr expr );
		Float( Float && rhs );
		Float( Float const & rhs );
		Float( Value const & value );
		Float & operator=( Float const & rhs );
		template< typename T >
		inline Float & operator=( T const & rhs );
		Float & operator=( float rhs );
		Float & operator=( double rhs );
		Float & operator=( long double rhs );
		explicit operator float();
	};

	inline Float operator "" _f( long double value )
	{
		return Float{ nullptr, makeExpr( float( value ) ) };
	}
}

#include "Float.inl"

#endif
