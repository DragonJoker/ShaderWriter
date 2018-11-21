/*
See LICENSE file in root folder
*/
#ifndef ___SDW_Double_H___
#define ___SDW_Double_H___
#pragma once

#include "ShaderWriter/MaybeOptional/MaybeOptional.hpp"

namespace sdw
{
	struct Double
		: public Value
	{
		Double( Shader * shader
			, expr::ExprPtr expr );
		Double( Double && rhs );
		Double( Double const & rhs );
		explicit Double( float rhs );
		explicit Double( double rhs );
		explicit Double( long double rhs );
		explicit Double( Value const & value );
		Double & operator=( Double const & rhs );
		template< typename T >
		inline Double & operator=( T const & rhs );
		Double & operator=( float const & rhs );
		Double & operator=( double const & rhs );
		Double & operator=( long double const & rhs );
		explicit operator float();
		Double & operator+=( Double const & rhs );
		Double & operator-=( Double const & rhs );
		Double & operator*=( Double const & rhs );
		Double & operator/=( Double const & rhs );
		Double & operator+=( Optional< Double > const & rhs );
		Double & operator-=( Optional< Double > const & rhs );
		Double & operator*=( Optional< Double > const & rhs );
		Double & operator/=( Optional< Double > const & rhs );
		Double & operator+=( float const & rhs );
		Double & operator-=( float const & rhs );
		Double & operator*=( float const & rhs );
		Double & operator/=( float const & rhs );
	};

	Double operator+( Double const & lhs, Double const & rhs );
	Double operator-( Double const & lhs, Double const & rhs );
	Double operator*( Double const & lhs, Double const & rhs );
	Double operator/( Double const & lhs, Double const & rhs );
	Double operator+( Double const & lhs, float const & rhs );
	Double operator-( Double const & lhs, float const & rhs );
	Double operator*( Double const & lhs, float const & rhs );
	Double operator/( Double const & lhs, float const & rhs );
	Double operator+( float const & lhs, Double const & rhs );
	Double operator-( float const & lhs, Double const & rhs );
	Double operator*( float const & lhs, Double const & rhs );
	Double operator/( float const & lhs, Double const & rhs );

	Optional< Double > operator+( Optional< Double > const & lhs, Double const & rhs );
	Optional< Double > operator-( Optional< Double > const & lhs, Double const & rhs );
	Optional< Double > operator*( Optional< Double > const & lhs, Double const & rhs );
	Optional< Double > operator/( Optional< Double > const & lhs, Double const & rhs );
	Optional< Double > operator+( Double const & lhs, Optional< Double > const & rhs );
	Optional< Double > operator-( Double const & lhs, Optional< Double > const & rhs );
	Optional< Double > operator*( Double const & lhs, Optional< Double > const & rhs );
	Optional< Double > operator/( Double const & lhs, Optional< Double > const & rhs );
	Optional< Double > operator+( Optional< Double > const & lhs, Optional< Double > const & rhs );
	Optional< Double > operator-( Optional< Double > const & lhs, Optional< Double > const & rhs );
	Optional< Double > operator*( Optional< Double > const & lhs, Optional< Double > const & rhs );
	Optional< Double > operator/( Optional< Double > const & lhs, Optional< Double > const & rhs );
	Optional< Double > operator+( Optional< Double > const & lhs, float const & rhs );
	Optional< Double > operator-( Optional< Double > const & lhs, float const & rhs );
	Optional< Double > operator*( Optional< Double > const & lhs, float const & rhs );
	Optional< Double > operator/( Optional< Double > const & lhs, float const & rhs );
	Optional< Double > operator+( float const & lhs, Optional< Double > const & rhs );
	Optional< Double > operator-( float const & lhs, Optional< Double > const & rhs );
	Optional< Double > operator*( float const & lhs, Optional< Double > const & rhs );
	Optional< Double > operator/( float const & lhs, Optional< Double > const & rhs );

	Boolean operator==( Double const & lhs, Double const & rhs );
	Boolean operator!=( Double const & lhs, Double const & rhs );
	Boolean operator<( Double const & lhs, Double const & rhs );
	Boolean operator<=( Double const & lhs, Double const & rhs );
	Boolean operator>( Double const & lhs, Double const & rhs );
	Boolean operator>=( Double const & lhs, Double const & rhs );
	Optional< Boolean > operator==( Optional< Double > const & lhs, Double const & rhs );
	Optional< Boolean > operator!=( Optional< Double > const & lhs, Double const & rhs );
	Optional< Boolean > operator<( Optional< Double > const & lhs, Double const & rhs );
	Optional< Boolean > operator<=( Optional< Double > const & lhs, Double const & rhs );
	Optional< Boolean > operator>( Optional< Double > const & lhs, Double const & rhs );
	Optional< Boolean > operator>=( Optional< Double > const & lhs, Double const & rhs );
	Optional< Boolean > operator==( Double const & lhs, Optional< Double > const & rhs );
	Optional< Boolean > operator!=( Double const & lhs, Optional< Double > const & rhs );
	Optional< Boolean > operator<( Double const & lhs, Optional< Double > const & rhs );
	Optional< Boolean > operator<=( Double const & lhs, Optional< Double > const & rhs );
	Optional< Boolean > operator>( Double const & lhs, Optional< Double > const & rhs );
	Optional< Boolean > operator>=( Double const & lhs, Optional< Double > const & rhs );
	Optional< Boolean > operator==( Optional< Double > const & lhs, Optional< Double > const & rhs );
	Optional< Boolean > operator!=( Optional< Double > const & lhs, Optional< Double > const & rhs );
	Optional< Boolean > operator<( Optional< Double > const & lhs, Optional< Double > const & rhs );
	Optional< Boolean > operator<=( Optional< Double > const & lhs, Optional< Double > const & rhs );
	Optional< Boolean > operator>( Optional< Double > const & lhs, Optional< Double > const & rhs );
	Optional< Boolean > operator>=( Optional< Double > const & lhs, Optional< Double > const & rhs );
	Boolean operator==( Double const & lhs, double const & rhs );
	Boolean operator!=( Double const & lhs, double const & rhs );
	Boolean operator<( Double const & lhs, double const & rhs );
	Boolean operator<=( Double const & lhs, double const & rhs );
	Boolean operator>( Double const & lhs, double const & rhs );
	Boolean operator>=( Double const & lhs, double const & rhs );
	Optional< Boolean > operator==( Optional< Double > const & lhs, double const & rhs );
	Optional< Boolean > operator!=( Optional< Double > const & lhs, double const & rhs );
	Optional< Boolean > operator<( Optional< Double > const & lhs, double const & rhs );
	Optional< Boolean > operator<=( Optional< Double > const & lhs, double const & rhs );
	Optional< Boolean > operator>( Optional< Double > const & lhs, double const & rhs );
	Optional< Boolean > operator>=( Optional< Double > const & lhs, double const & rhs );
	Optional< Boolean > operator==( double const & lhs, Optional< Double > const & rhs );
	Optional< Boolean > operator!=( double const & lhs, Optional< Double > const & rhs );
	Optional< Boolean > operator<( double const & lhs, Optional< Double > const & rhs );
	Optional< Boolean > operator<=( double const & lhs, Optional< Double > const & rhs );
	Optional< Boolean > operator>( double const & lhs, Optional< Double > const & rhs );
	Optional< Boolean > operator>=( double const & lhs, Optional< Double > const & rhs );
}

inline sdw::Double operator "" _d( long double value )
{
	return sdw::Double{ nullptr, sdw::makeExpr( double( value ) ) };
}

#include "Double.inl"

#endif
