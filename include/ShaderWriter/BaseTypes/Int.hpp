/*
See LICENSE file in root folder
*/
#ifndef ___SDW_Int_H___
#define ___SDW_Int_H___
#pragma once

#include "ShaderWriter/Optional/Optional.hpp"

namespace sdw
{
	struct Int
		: public Value
	{
		Int( Shader * shader
			, expr::ExprPtr expr );
		Int( Int && rhs );
		Int( Int const & rhs );
		explicit Int( int16_t rhs );
		explicit Int( int32_t rhs );
		explicit Int( int64_t rhs );
		explicit Int( Value const & rhs );
		Int & operator=( Int const & rhs );
		template< typename T >
		inline Int & operator=( T const & rhs );
		Int & operator=( int32_t const & rhs );
		Int & operator=( int64_t const & rhs );
		Int & operator++();
		Int operator++( int );
		Int & operator--();
		Int operator--( int );
		Int & operator+=( Int const & rhs );
		Int & operator-=( Int const & rhs );
		Int & operator*=( Int const & rhs );
		Int & operator/=( Int const & rhs );
		Int & operator+=( Optional< Int > const & rhs );
		Int & operator-=( Optional< Int > const & rhs );
		Int & operator*=( Optional< Int > const & rhs );
		Int & operator/=( Optional< Int > const & rhs );
		Int & operator+=( int32_t const & rhs );
		Int & operator-=( int32_t const & rhs );
		Int & operator*=( int32_t const & rhs );
		Int & operator/=( int32_t const & rhs );
		Int & operator%=( int32_t const & rhs );
		Int & operator%=( Int const & rhs );
		Int & operator%=( Optional< Int > const & rhs );
		Int & operator<<=( int32_t const & rhs );
		Int & operator>>=( int32_t const & rhs );
		Int & operator<<=( Int const & rhs );
		Int & operator>>=( Int const & rhs );
		Int & operator<<=( Optional< Int > const & rhs );
		Int & operator>>=( Optional< Int > const & rhs );
		Int & operator&=( int32_t const & rhs );
		Int & operator|=( int32_t const & rhs );
		Int & operator&=( Int const & rhs );
		Int & operator|=( Int const & rhs );
		Int & operator&=( Optional< Int > const & rhs );
		Int & operator|=( Optional< Int > const & rhs );
	};

	Int operator+( Int const & lhs, Int const & rhs );
	Int operator-( Int const & lhs, Int const & rhs );
	Int operator*( Int const & lhs, Int const & rhs );
	Int operator/( Int const & lhs, Int const & rhs );
	Int operator+( Int const & lhs, int32_t const & rhs );
	Int operator-( Int const & lhs, int32_t const & rhs );
	Int operator*( Int const & lhs, int32_t const & rhs );
	Int operator/( Int const & lhs, int32_t const & rhs );
	Int operator+( int32_t const & lhs, Int const & rhs );
	Int operator-( int32_t const & lhs, Int const & rhs );
	Int operator*( int32_t const & lhs, Int const & rhs );
	Int operator/( int32_t const & lhs, Int const & rhs );
	Int operator+( uint32_t const & lhs, Int const & rhs );
	Int operator-( uint32_t const & lhs, Int const & rhs );
	Int operator*( uint32_t const & lhs, Int const & rhs );
	Int operator/( uint32_t const & lhs, Int const & rhs );
	Int operator%( Int const & lhs, int32_t const & rhs );
	Int operator%( Int const & lhs, Int const & rhs );

	Int operator<<( Int const & lhs, int32_t const & rhs );
	Int operator>>( Int const & lhs, int32_t const & rhs );
	Int operator<<( Int const & lhs, Int const & rhs );
	Int operator>>( Int const & lhs, Int const & rhs );
	Int operator&( Int const & lhs, int32_t const & rhs );
	Int operator|( Int const & lhs, int32_t const & rhs );
	Int operator&( Int const & lhs, Int const & rhs );
	Int operator|( Int const & lhs, Int const & rhs );
	Int operator~( Int const & value );

	Optional< Int > operator+( Optional< Int > const & lhs, Int const & rhs );
	Optional< Int > operator-( Optional< Int > const & lhs, Int const & rhs );
	Optional< Int > operator*( Optional< Int > const & lhs, Int const & rhs );
	Optional< Int > operator/( Optional< Int > const & lhs, Int const & rhs );
	Optional< Int > operator+( Int const & lhs, Optional< Int > const & rhs );
	Optional< Int > operator-( Int const & lhs, Optional< Int > const & rhs );
	Optional< Int > operator*( Int const & lhs, Optional< Int > const & rhs );
	Optional< Int > operator/( Int const & lhs, Optional< Int > const & rhs );
	Optional< Int > operator+( Optional< Int > const & lhs, Optional< Int > const & rhs );
	Optional< Int > operator-( Optional< Int > const & lhs, Optional< Int > const & rhs );
	Optional< Int > operator*( Optional< Int > const & lhs, Optional< Int > const & rhs );
	Optional< Int > operator/( Optional< Int > const & lhs, Optional< Int > const & rhs );
	Optional< Int > operator+( Optional< Int > const & lhs, int32_t const & rhs );
	Optional< Int > operator-( Optional< Int > const & lhs, int32_t const & rhs );
	Optional< Int > operator*( Optional< Int > const & lhs, int32_t const & rhs );
	Optional< Int > operator/( Optional< Int > const & lhs, int32_t const & rhs );
	Optional< Int > operator+( int32_t const & lhs, Optional< Int > const & rhs );
	Optional< Int > operator-( int32_t const & lhs, Optional< Int > const & rhs );
	Optional< Int > operator*( int32_t const & lhs, Optional< Int > const & rhs );
	Optional< Int > operator/( int32_t const & lhs, Optional< Int > const & rhs );
	Optional< Int > operator%( Optional< Int > const & lhs, int32_t const & rhs );
	Optional< Int > operator%( Optional< Int > const & lhs, Int const & rhs );
	Optional< Int > operator%( Int const & lhs, Optional< Int > const & rhs );
	Optional< Int > operator%( Optional< Int > const & lhs, Optional< Int > const & rhs );

	Optional< Int > operator<<( Optional< Int > const & lhs, int32_t const & rhs );
	Optional< Int > operator>>( Optional< Int > const & lhs, int32_t const & rhs );
	Optional< Int > operator<<( Optional< Int > const & lhs, Int const & rhs );
	Optional< Int > operator>>( Optional< Int > const & lhs, Int const & rhs );
	Optional< Int > operator<<( Int const & lhs, Optional< Int > const & rhs );
	Optional< Int > operator>>( Int const & lhs, Optional< Int > const & rhs );
	Optional< Int > operator<<( Optional< Int > const & lhs, Optional< Int > const & rhs );
	Optional< Int > operator>>( Optional< Int > const & lhs, Optional< Int > const & rhs );
	Optional< Int > operator&( Optional< Int > const & lhs, int32_t const & rhs );
	Optional< Int > operator|( Optional< Int > const & lhs, int32_t const & rhs );
	Optional< Int > operator&( Optional< Int > const & lhs, Int const & rhs );
	Optional< Int > operator|( Optional< Int > const & lhs, Int const & rhs );
	Optional< Int > operator&( Int const & lhs, Optional< Int > const & rhs );
	Optional< Int > operator|( Int const & lhs, Optional< Int > const & rhs );
	Optional< Int > operator&( Optional< Int > const & lhs, Optional< Int > const & rhs );
	Optional< Int > operator|( Optional< Int > const & lhs, Optional< Int > const & rhs );
	Optional< Int > operator~( Optional< Int > const & value );

	Boolean operator==( Int const & lhs, Int const & rhs );
	Boolean operator!=( Int const & lhs, Int const & rhs );
	Boolean operator<( Int const & lhs, Int const & rhs );
	Boolean operator<=( Int const & lhs, Int const & rhs );
	Boolean operator>( Int const & lhs, Int const & rhs );
	Boolean operator>=( Int const & lhs, Int const & rhs );
	Optional< Boolean > operator==( Optional< Int > const & lhs, Int const & rhs );
	Optional< Boolean > operator!=( Optional< Int > const & lhs, Int const & rhs );
	Optional< Boolean > operator<( Optional< Int > const & lhs, Int const & rhs );
	Optional< Boolean > operator<=( Optional< Int > const & lhs, Int const & rhs );
	Optional< Boolean > operator>( Optional< Int > const & lhs, Int const & rhs );
	Optional< Boolean > operator>=( Optional< Int > const & lhs, Int const & rhs );
	Optional< Boolean > operator==( Int const & lhs, Optional< Int > const & rhs );
	Optional< Boolean > operator!=( Int const & lhs, Optional< Int > const & rhs );
	Optional< Boolean > operator<( Int const & lhs, Optional< Int > const & rhs );
	Optional< Boolean > operator<=( Int const & lhs, Optional< Int > const & rhs );
	Optional< Boolean > operator>( Int const & lhs, Optional< Int > const & rhs );
	Optional< Boolean > operator>=( Int const & lhs, Optional< Int > const & rhs );
	Optional< Boolean > operator==( Optional< Int > const & lhs, Optional< Int > const & rhs );
	Optional< Boolean > operator!=( Optional< Int > const & lhs, Optional< Int > const & rhs );
	Optional< Boolean > operator<( Optional< Int > const & lhs, Optional< Int > const & rhs );
	Optional< Boolean > operator<=( Optional< Int > const & lhs, Optional< Int > const & rhs );
	Optional< Boolean > operator>( Optional< Int > const & lhs, Optional< Int > const & rhs );
	Optional< Boolean > operator>=( Optional< Int > const & lhs, Optional< Int > const & rhs );
	Boolean operator==( Int const & lhs, int32_t const & rhs );
	Boolean operator!=( Int const & lhs, int32_t const & rhs );
	Boolean operator<( Int const & lhs, int32_t const & rhs );
	Boolean operator<=( Int const & lhs, int32_t const & rhs );
	Boolean operator>( Int const & lhs, int32_t const & rhs );
	Boolean operator>=( Int const & lhs, int32_t const & rhs );
	Optional< Boolean > operator==( Optional< Int > const & lhs, int32_t const & rhs );
	Optional< Boolean > operator!=( Optional< Int > const & lhs, int32_t const & rhs );
	Optional< Boolean > operator<( Optional< Int > const & lhs, int32_t const & rhs );
	Optional< Boolean > operator<=( Optional< Int > const & lhs, int32_t const & rhs );
	Optional< Boolean > operator>( Optional< Int > const & lhs, int32_t const & rhs );
	Optional< Boolean > operator>=( Optional< Int > const & lhs, int32_t const & rhs );
	Optional< Boolean > operator==( int32_t const & lhs, Optional< Int > const & rhs );
	Optional< Boolean > operator!=( int32_t const & lhs, Optional< Int > const & rhs );
	Optional< Boolean > operator<( int32_t const & lhs, Optional< Int > const & rhs );
	Optional< Boolean > operator<=( int32_t const & lhs, Optional< Int > const & rhs );
	Optional< Boolean > operator>( int32_t const & lhs, Optional< Int > const & rhs );
	Optional< Boolean > operator>=( int32_t const & lhs, Optional< Int > const & rhs );
}

inline sdw::Int operator "" _i( unsigned long long value )
{
	return sdw::Int{ nullptr, sdw::makeExpr( int( value ) ) };
}

#include "Int.inl"

#endif
