/*
See LICENSE file in root folder
*/
#ifndef ___Writer_UInt_H___
#define ___Writer_UInt_H___
#pragma once

#include "Optional.hpp"

namespace sdw
{
	struct Int;
	struct UInt
		: public Value
	{
		UInt( Shader * shader
			, expr::ExprPtr expr );
		UInt( UInt && value );
		UInt( UInt const & value );
		explicit UInt( uint16_t rhs );
		explicit UInt( uint32_t rhs );
		explicit UInt( uint64_t rhs );
		UInt( Value const & value );
		UInt & operator=( UInt const & rhs );
		template< typename T >
		inline UInt & operator=( T const & rhs );
		UInt & operator=( int32_t const & rhs );
		UInt & operator=( int64_t const & rhs );
		UInt & operator=( uint32_t const & rhs );
		UInt & operator=( uint64_t const & rhs );
		explicit operator uint32_t();
		UInt & operator++();
		UInt operator++( int );
		UInt & operator--();
		UInt operator--( int );
		UInt & operator+=( UInt const & rhs );
		UInt & operator-=( UInt const & rhs );
		UInt & operator*=( UInt const & rhs );
		UInt & operator/=( UInt const & rhs );
		UInt & operator+=( Optional< UInt > const & rhs );
		UInt & operator-=( Optional< UInt > const & rhs );
		UInt & operator*=( Optional< UInt > const & rhs );
		UInt & operator/=( Optional< UInt > const & rhs );
		UInt & operator+=( Int const & rhs );
		UInt & operator-=( Int const & rhs );
		UInt & operator*=( Int const & rhs );
		UInt & operator/=( Int const & rhs );
		UInt & operator+=( Optional< Int > const & rhs );
		UInt & operator-=( Optional< Int > const & rhs );
		UInt & operator*=( Optional< Int > const & rhs );
		UInt & operator/=( Optional< Int > const & rhs );
		UInt & operator+=( uint32_t const & rhs );
		UInt & operator-=( uint32_t const & rhs );
		UInt & operator*=( uint32_t const & rhs );
		UInt & operator/=( uint32_t const & rhs );
		UInt & operator+=( int32_t const & rhs );
		UInt & operator-=( int32_t const & rhs );
		UInt & operator*=( int32_t const & rhs );
		UInt & operator/=( int32_t const & rhs );
		UInt & operator%=( int32_t const & rhs );
		UInt & operator%=( Int const & rhs );
		UInt & operator%=( Optional< Int > const & rhs );
		UInt & operator%=( UInt const & rhs );
		UInt & operator%=( Optional< UInt > const & rhs );
		UInt & operator<<=( int32_t const & rhs );
		UInt & operator>>=( int32_t const & rhs );
		UInt & operator<<=( uint32_t const & rhs );
		UInt & operator>>=( uint32_t const & rhs );
		UInt & operator<<=( Int const & rhs );
		UInt & operator>>=( Int const & rhs );
		UInt & operator<<=( Optional< Int > const & rhs );
		UInt & operator>>=( Optional< Int > const & rhs );
		UInt & operator<<=( UInt const & rhs );
		UInt & operator>>=( UInt const & rhs );
		UInt & operator<<=( Optional< UInt > const & rhs );
		UInt & operator>>=( Optional< UInt > const & rhs );
		UInt & operator&=( int32_t const & rhs );
		UInt & operator|=( int32_t const & rhs );
		UInt & operator&=( uint32_t const & rhs );
		UInt & operator|=( uint32_t const & rhs );
		UInt & operator&=( Int const & rhs );
		UInt & operator|=( Int const & rhs );
		UInt & operator&=( Optional< Int > const & rhs );
		UInt & operator|=( Optional< Int > const & rhs );
		UInt & operator&=( UInt const & rhs );
		UInt & operator|=( UInt const & rhs );
		UInt & operator&=( Optional< UInt > const & rhs );
		UInt & operator|=( Optional< UInt > const & rhs );
	};

	UInt operator+( UInt const & rhs, Int const & lhs );
	UInt operator-( UInt const & rhs, Int const & lhs );
	UInt operator*( UInt const & rhs, Int const & lhs );
	UInt operator/( UInt const & rhs, Int const & lhs );
	UInt operator+( UInt const & rhs, UInt const & lhs );
	UInt operator-( UInt const & rhs, UInt const & lhs );
	UInt operator*( UInt const & rhs, UInt const & lhs );
	UInt operator/( UInt const & rhs, UInt const & lhs );
	UInt operator+( UInt const & rhs, uint32_t const & lhs );
	UInt operator-( UInt const & rhs, uint32_t const & lhs );
	UInt operator*( UInt const & rhs, uint32_t const & lhs );
	UInt operator/( UInt const & rhs, uint32_t const & lhs );
	UInt operator+( UInt const & rhs, int32_t const & lhs );
	UInt operator-( UInt const & rhs, int32_t const & lhs );
	UInt operator*( UInt const & rhs, int32_t const & lhs );
	UInt operator/( UInt const & rhs, int32_t const & lhs );
	UInt operator+( int32_t const & lhs, UInt const & rhs );
	UInt operator-( int32_t const & lhs, UInt const & rhs );
	UInt operator*( int32_t const & lhs, UInt const & rhs );
	UInt operator/( int32_t const & lhs, UInt const & rhs );
	UInt operator+( uint32_t const & lhs, UInt const & rhs );
	UInt operator-( uint32_t const & lhs, UInt const & rhs );
	UInt operator*( uint32_t const & lhs, UInt const & rhs );
	UInt operator/( uint32_t const & lhs, UInt const & rhs );
	UInt operator%( UInt const & lhs, int32_t const & rhs );
	UInt operator%( UInt const & lhs, uint32_t const & rhs );
	UInt operator%( UInt const & lhs, Int const & rhs );
	UInt operator%( UInt const & lhs, UInt const & rhs );

	UInt operator<<( UInt const & lhs, int32_t const & rhs );
	UInt operator>>( UInt const & lhs, int32_t const & rhs );
	UInt operator<<( UInt const & lhs, uint32_t const & rhs );
	UInt operator>>( UInt const & lhs, uint32_t const & rhs );
	UInt operator<<( UInt const & lhs, Int const & rhs );
	UInt operator>>( UInt const & lhs, Int const & rhs );
	UInt operator<<( UInt const & lhs, UInt const & rhs );
	UInt operator>>( UInt const & lhs, UInt const & rhs );
	UInt operator&( UInt const & lhs, int32_t const & rhs );
	UInt operator|( UInt const & lhs, int32_t const & rhs );
	UInt operator&( UInt const & lhs, uint32_t const & rhs );
	UInt operator|( UInt const & lhs, uint32_t const & rhs );
	UInt operator&( UInt const & lhs, Int const & rhs );
	UInt operator|( UInt const & lhs, Int const & rhs );
	UInt operator&( UInt const & lhs, UInt const & rhs );
	UInt operator|( UInt const & lhs, UInt const & rhs );
	UInt operator~( UInt const & value );

	Optional< UInt > operator+( Optional< UInt > const & lhs, UInt const & rhs );
	Optional< UInt > operator-( Optional< UInt > const & lhs, UInt const & rhs );
	Optional< UInt > operator*( Optional< UInt > const & lhs, UInt const & rhs );
	Optional< UInt > operator/( Optional< UInt > const & lhs, UInt const & rhs );
	Optional< UInt > operator+( UInt const & lhs, Optional< UInt > const & rhs );
	Optional< UInt > operator-( UInt const & lhs, Optional< UInt > const & rhs );
	Optional< UInt > operator*( UInt const & lhs, Optional< UInt > const & rhs );
	Optional< UInt > operator/( UInt const & lhs, Optional< UInt > const & rhs );
	Optional< UInt > operator+( Optional< UInt > const & lhs, Optional< UInt > const & rhs );
	Optional< UInt > operator-( Optional< UInt > const & lhs, Optional< UInt > const & rhs );
	Optional< UInt > operator*( Optional< UInt > const & lhs, Optional< UInt > const & rhs );
	Optional< UInt > operator/( Optional< UInt > const & lhs, Optional< UInt > const & rhs );
	Optional< UInt > operator+( Optional< UInt > const & lhs, Int const & rhs );
	Optional< UInt > operator-( Optional< UInt > const & lhs, Int const & rhs );
	Optional< UInt > operator*( Optional< UInt > const & lhs, Int const & rhs );
	Optional< UInt > operator/( Optional< UInt > const & lhs, Int const & rhs );
	Optional< UInt > operator+( UInt const & lhs, Optional< Int > const & rhs );
	Optional< UInt > operator-( UInt const & lhs, Optional< Int > const & rhs );
	Optional< UInt > operator*( UInt const & lhs, Optional< Int > const & rhs );
	Optional< UInt > operator/( UInt const & lhs, Optional< Int > const & rhs );
	Optional< UInt > operator+( Optional< UInt > const & lhs, Optional< Int > const & rhs );
	Optional< UInt > operator-( Optional< UInt > const & lhs, Optional< Int > const & rhs );
	Optional< UInt > operator*( Optional< UInt > const & lhs, Optional< Int > const & rhs );
	Optional< UInt > operator/( Optional< UInt > const & lhs, Optional< Int > const & rhs );
	Optional< UInt > operator+( Optional< UInt > const & lhs, uint32_t const & rhs );
	Optional< UInt > operator-( Optional< UInt > const & lhs, uint32_t const & rhs );
	Optional< UInt > operator*( Optional< UInt > const & lhs, uint32_t const & rhs );
	Optional< UInt > operator/( Optional< UInt > const & lhs, uint32_t const & rhs );
	Optional< UInt > operator+( Optional< UInt > const & lhs, int32_t const & rhs );
	Optional< UInt > operator-( Optional< UInt > const & lhs, int32_t const & rhs );
	Optional< UInt > operator*( Optional< UInt > const & lhs, int32_t const & rhs );
	Optional< UInt > operator/( Optional< UInt > const & lhs, int32_t const & rhs );
	Optional< UInt > operator+( int32_t const & lhs, Optional< UInt > const & rhs );
	Optional< UInt > operator-( int32_t const & lhs, Optional< UInt > const & rhs );
	Optional< UInt > operator*( int32_t const & lhs, Optional< UInt > const & rhs );
	Optional< UInt > operator/( int32_t const & lhs, Optional< UInt > const & rhs );
	Optional< UInt > operator+( uint32_t const & lhs, Optional< UInt > const & rhs );
	Optional< UInt > operator-( uint32_t const & lhs, Optional< UInt > const & rhs );
	Optional< UInt > operator*( uint32_t const & lhs, Optional< UInt > const & rhs );
	Optional< UInt > operator/( uint32_t const & lhs, Optional< UInt > const & rhs );
	Optional< UInt > operator%( Optional< UInt > const & lhs, int32_t const & rhs );
	Optional< UInt > operator%( Optional< UInt > const & lhs, uint32_t const & rhs );
	Optional< UInt > operator%( Optional< UInt > const & lhs, Int const & rhs );
	Optional< UInt > operator%( UInt const & lhs, Optional< Int > const & rhs );
	Optional< UInt > operator%( Optional< UInt > const & lhs, Optional< Int > const & rhs );
	Optional< UInt > operator%( Optional< UInt > const & lhs, UInt const & rhs );
	Optional< UInt > operator%( UInt const & lhs, Optional< UInt > const & rhs );
	Optional< UInt > operator%( Optional< UInt > const & lhs, Optional< UInt > const & rhs );

	Optional< UInt > operator<<( Optional< UInt > const & lhs, int32_t const & rhs );
	Optional< UInt > operator>>( Optional< UInt > const & lhs, int32_t const & rhs );
	Optional< UInt > operator<<( Optional< UInt > const & lhs, uint32_t const & rhs );
	Optional< UInt > operator>>( Optional< UInt > const & lhs, uint32_t const & rhs );
	Optional< UInt > operator<<( Optional< UInt > const & lhs, Int const & rhs );
	Optional< UInt > operator>>( Optional< UInt > const & lhs, Int const & rhs );
	Optional< UInt > operator<<( UInt const & lhs, Optional< Int > const & rhs );
	Optional< UInt > operator>>( UInt const & lhs, Optional< Int > const & rhs );
	Optional< UInt > operator<<( Optional< UInt > const & lhs, Optional< Int > const & rhs );
	Optional< UInt > operator>>( Optional< UInt > const & lhs, Optional< Int > const & rhs );
	Optional< UInt > operator<<( Optional< UInt > const & lhs, UInt const & rhs );
	Optional< UInt > operator>>( Optional< UInt > const & lhs, UInt const & rhs );
	Optional< UInt > operator<<( UInt const & lhs, Optional< UInt > const & rhs );
	Optional< UInt > operator>>( UInt const & lhs, Optional< UInt > const & rhs );
	Optional< UInt > operator<<( Optional< UInt > const & lhs, Optional< UInt > const & rhs );
	Optional< UInt > operator>>( Optional< UInt > const & lhs, Optional< UInt > const & rhs );
	Optional< UInt > operator&( Optional< UInt > const & lhs, int32_t const & rhs );
	Optional< UInt > operator|( Optional< UInt > const & lhs, int32_t const & rhs );
	Optional< UInt > operator&( Optional< UInt > const & lhs, uint32_t const & rhs );
	Optional< UInt > operator|( Optional< UInt > const & lhs, uint32_t const & rhs );
	Optional< UInt > operator&( Optional< UInt > const & lhs, Int const & rhs );
	Optional< UInt > operator|( Optional< UInt > const & lhs, Int const & rhs );
	Optional< UInt > operator&( UInt const & lhs, Optional< Int > const & rhs );
	Optional< UInt > operator|( UInt const & lhs, Optional< Int > const & rhs );
	Optional< UInt > operator&( Optional< UInt > const & lhs, Optional< Int > const & rhs );
	Optional< UInt > operator|( Optional< UInt > const & lhs, Optional< Int > const & rhs );
	Optional< UInt > operator&( Optional< UInt > const & lhs, UInt const & rhs );
	Optional< UInt > operator|( Optional< UInt > const & lhs, UInt const & rhs );
	Optional< UInt > operator&( UInt const & lhs, Optional< UInt > const & rhs );
	Optional< UInt > operator|( UInt const & lhs, Optional< UInt > const & rhs );
	Optional< UInt > operator&( Optional< UInt > const & lhs, Optional< UInt > const & rhs );
	Optional< UInt > operator|( Optional< UInt > const & lhs, Optional< UInt > const & rhs );
	Optional< UInt > operator~( Optional< UInt > const & value );
}

inline sdw::UInt operator "" _u( unsigned long long value )
{
	return sdw::UInt{ nullptr, sdw::makeExpr( uint32_t( value ) ) };
}

#include "UInt.inl"

#endif
