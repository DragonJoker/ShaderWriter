/*
See LICENSE file in root folder
*/
#ifndef ___Writer_Float_H___
#define ___Writer_Float_H___
#pragma once

#include "Optional.hpp"

namespace sdw
{
	struct Float
		: public Value
	{
		Float( Shader * shader
			, expr::ExprPtr expr );
		Float( Float && rhs );
		Float( Float const & rhs );
		Float( Value const & value );
		Float & operator=( Float const & rhs );
		template< typename T >
		inline Float & operator=( T const & rhs );
		Float & operator=( float const & rhs );
		Float & operator=( double const & rhs );
		Float & operator=( long double const & rhs );
		explicit operator float();
		Float & operator+=( Float const & rhs );
		Float & operator-=( Float const & rhs );
		Float & operator*=( Float const & rhs );
		Float & operator/=( Float const & rhs );
		Float & operator+=( Optional< Float > const & rhs );
		Float & operator-=( Optional< Float > const & rhs );
		Float & operator*=( Optional< Float > const & rhs );
		Float & operator/=( Optional< Float > const & rhs );
		Float & operator+=( float const & rhs );
		Float & operator-=( float const & rhs );
		Float & operator*=( float const & rhs );
		Float & operator/=( float const & rhs );
	};

	Float operator+( Float const & lhs, Float const & rhs );
	Float operator-( Float const & lhs, Float const & rhs );
	Float operator*( Float const & lhs, Float const & rhs );
	Float operator/( Float const & lhs, Float const & rhs );
	Float operator+( Float const & lhs, float const & rhs );
	Float operator-( Float const & lhs, float const & rhs );
	Float operator*( Float const & lhs, float const & rhs );
	Float operator/( Float const & lhs, float const & rhs );
	Float operator+( float const & lhs, Float const & rhs );
	Float operator-( float const & lhs, Float const & rhs );
	Float operator*( float const & lhs, Float const & rhs );
	Float operator/( float const & lhs, Float const & rhs );

	Optional< Float > operator+( Optional< Float > const & lhs, Float const & rhs );
	Optional< Float > operator-( Optional< Float > const & lhs, Float const & rhs );
	Optional< Float > operator*( Optional< Float > const & lhs, Float const & rhs );
	Optional< Float > operator/( Optional< Float > const & lhs, Float const & rhs );
	Optional< Float > operator+( Float const & lhs, Optional< Float > const & rhs );
	Optional< Float > operator-( Float const & lhs, Optional< Float > const & rhs );
	Optional< Float > operator*( Float const & lhs, Optional< Float > const & rhs );
	Optional< Float > operator/( Float const & lhs, Optional< Float > const & rhs );
	Optional< Float > operator+( Optional< Float > const & lhs, Optional< Float > const & rhs );
	Optional< Float > operator-( Optional< Float > const & lhs, Optional< Float > const & rhs );
	Optional< Float > operator*( Optional< Float > const & lhs, Optional< Float > const & rhs );
	Optional< Float > operator/( Optional< Float > const & lhs, Optional< Float > const & rhs );
	Optional< Float > operator+( Optional< Float > const & lhs, float const & rhs );
	Optional< Float > operator-( Optional< Float > const & lhs, float const & rhs );
	Optional< Float > operator*( Optional< Float > const & lhs, float const & rhs );
	Optional< Float > operator/( Optional< Float > const & lhs, float const & rhs );
	Optional< Float > operator+( float const & lhs, Optional< Float > const & rhs );
	Optional< Float > operator-( float const & lhs, Optional< Float > const & rhs );
	Optional< Float > operator*( float const & lhs, Optional< Float > const & rhs );
	Optional< Float > operator/( float const & lhs, Optional< Float > const & rhs );
}

inline sdw::Float operator "" _f( long double value )
{
	return sdw::Float{ nullptr, sdw::makeExpr( float( value ) ) };
}

#include "Float.inl"

#endif
