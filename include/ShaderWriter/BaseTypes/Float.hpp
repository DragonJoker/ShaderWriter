/*
See LICENSE file in root folder
*/
#ifndef ___SDW_Float_H___
#define ___SDW_Float_H___
#pragma once

#include "ShaderWriter/MaybeOptional/MaybeOptional.hpp"

namespace sdw
{
	struct Float
		: public Value
	{
		Float( Shader * shader
			, expr::ExprPtr expr );
		Float( Float && rhs );
		Float( Float const & rhs );
		explicit Float( float rhs );
		explicit Float( double rhs );
		explicit Float( long double rhs );
		explicit Float( Value const & value );
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

	Boolean operator==( Float const & lhs, Float const & rhs );
	Boolean operator!=( Float const & lhs, Float const & rhs );
	Boolean operator<( Float const & lhs, Float const & rhs );
	Boolean operator<=( Float const & lhs, Float const & rhs );
	Boolean operator>( Float const & lhs, Float const & rhs );
	Boolean operator>=( Float const & lhs, Float const & rhs );
	Optional< Boolean > operator==( Optional< Float > const & lhs, Float const & rhs );
	Optional< Boolean > operator!=( Optional< Float > const & lhs, Float const & rhs );
	Optional< Boolean > operator<( Optional< Float > const & lhs, Float const & rhs );
	Optional< Boolean > operator<=( Optional< Float > const & lhs, Float const & rhs );
	Optional< Boolean > operator>( Optional< Float > const & lhs, Float const & rhs );
	Optional< Boolean > operator>=( Optional< Float > const & lhs, Float const & rhs );
	Optional< Boolean > operator==( Float const & lhs, Optional< Float > const & rhs );
	Optional< Boolean > operator!=( Float const & lhs, Optional< Float > const & rhs );
	Optional< Boolean > operator<( Float const & lhs, Optional< Float > const & rhs );
	Optional< Boolean > operator<=( Float const & lhs, Optional< Float > const & rhs );
	Optional< Boolean > operator>( Float const & lhs, Optional< Float > const & rhs );
	Optional< Boolean > operator>=( Float const & lhs, Optional< Float > const & rhs );
	Optional< Boolean > operator==( Optional< Float > const & lhs, Optional< Float > const & rhs );
	Optional< Boolean > operator!=( Optional< Float > const & lhs, Optional< Float > const & rhs );
	Optional< Boolean > operator<( Optional< Float > const & lhs, Optional< Float > const & rhs );
	Optional< Boolean > operator<=( Optional< Float > const & lhs, Optional< Float > const & rhs );
	Optional< Boolean > operator>( Optional< Float > const & lhs, Optional< Float > const & rhs );
	Optional< Boolean > operator>=( Optional< Float > const & lhs, Optional< Float > const & rhs );
	Boolean operator==( Float const & lhs, float const & rhs );
	Boolean operator!=( Float const & lhs, float const & rhs );
	Boolean operator<( Float const & lhs, float const & rhs );
	Boolean operator<=( Float const & lhs, float const & rhs );
	Boolean operator>( Float const & lhs, float const & rhs );
	Boolean operator>=( Float const & lhs, float const & rhs );
	Optional< Boolean > operator==( Optional< Float > const & lhs, float const & rhs );
	Optional< Boolean > operator!=( Optional< Float > const & lhs, float const & rhs );
	Optional< Boolean > operator<( Optional< Float > const & lhs, float const & rhs );
	Optional< Boolean > operator<=( Optional< Float > const & lhs, float const & rhs );
	Optional< Boolean > operator>( Optional< Float > const & lhs, float const & rhs );
	Optional< Boolean > operator>=( Optional< Float > const & lhs, float const & rhs );
	Optional< Boolean > operator==( float const & lhs, Optional< Float > const & rhs );
	Optional< Boolean > operator!=( float const & lhs, Optional< Float > const & rhs );
	Optional< Boolean > operator<( float const & lhs, Optional< Float > const & rhs );
	Optional< Boolean > operator<=( float const & lhs, Optional< Float > const & rhs );
	Optional< Boolean > operator>( float const & lhs, Optional< Float > const & rhs );
	Optional< Boolean > operator>=( float const & lhs, Optional< Float > const & rhs );
}

inline sdw::Float operator "" _f( long double value )
{
	return sdw::Float{ nullptr, sdw::makeExpr( float( value ) ) };
}

#include "Float.inl"

#endif
