/*
See LICENSE file in root folder
*/
#ifndef ___Writer_Int_H___
#define ___Writer_Int_H___
#pragma once

#include "Optional.hpp"

namespace sdw
{
	struct Int
		: public Value
	{
		Int( Shader * shader
			, expr::ExprPtr expr );
		Int( Int && rhs );
		Int( Int const & rhs );
		Int( Value const & rhs );
		Int & operator=( Int const & rhs );
		template< typename T >
		inline Int & operator=( T const & rhs );
		Int & operator=( int32_t const & rhs );
		Int & operator=( int64_t const & rhs );
		Int & operator=( uint32_t const & rhs );
		Int & operator=( uint64_t const & rhs );
		explicit operator uint32_t();
		Int & operator++();
		Int operator++( int );
		Int & operator--();
		Int operator--( int );
		Int & operator+=( UInt const & rhs );
		Int & operator-=( UInt const & rhs );
		Int & operator*=( UInt const & rhs );
		Int & operator/=( UInt const & rhs );
		Int & operator+=( Optional< UInt > const & rhs );
		Int & operator-=( Optional< UInt > const & rhs );
		Int & operator*=( Optional< UInt > const & rhs );
		Int & operator/=( Optional< UInt > const & rhs );
		Int & operator+=( Int const & rhs );
		Int & operator-=( Int const & rhs );
		Int & operator*=( Int const & rhs );
		Int & operator/=( Int const & rhs );
		Int & operator+=( Optional< Int > const & rhs );
		Int & operator-=( Optional< Int > const & rhs );
		Int & operator*=( Optional< Int > const & rhs );
		Int & operator/=( Optional< Int > const & rhs );
		Int & operator+=( uint32_t const & rhs );
		Int & operator-=( uint32_t const & rhs );
		Int & operator*=( uint32_t const & rhs );
		Int & operator/=( uint32_t const & rhs );
		Int & operator+=( int32_t const & rhs );
		Int & operator-=( int32_t const & rhs );
		Int & operator*=( int32_t const & rhs );
		Int & operator/=( int32_t const & rhs );
		Int & operator%=( int32_t const & rhs );
		Int & operator%=( uint32_t const & rhs );
		Int & operator%=( Int const & rhs );
		Int & operator%=( Optional< Int > const & rhs );
		Int & operator%=( UInt const & rhs );
		Int & operator%=( Optional< UInt > const & rhs );
		Int & operator<<=( int32_t const & rhs );
		Int & operator>>=( int32_t const & rhs );
		Int & operator<<=( uint32_t const & rhs );
		Int & operator>>=( uint32_t const & rhs );
		Int & operator<<=( Int const & rhs );
		Int & operator>>=( Int const & rhs );
		Int & operator<<=( Optional< Int > const & rhs );
		Int & operator>>=( Optional< Int > const & rhs );
		Int & operator<<=( UInt const & rhs );
		Int & operator>>=( UInt const & rhs );
		Int & operator<<=( Optional< UInt > const & rhs );
		Int & operator>>=( Optional< UInt > const & rhs );
		Int & operator&=( int32_t const & rhs );
		Int & operator|=( int32_t const & rhs );
		Int & operator&=( uint32_t const & rhs );
		Int & operator|=( uint32_t const & rhs );
		Int & operator&=( Int const & rhs );
		Int & operator|=( Int const & rhs );
		Int & operator&=( Optional< Int > const & rhs );
		Int & operator|=( Optional< Int > const & rhs );
		Int & operator&=( UInt const & rhs );
		Int & operator|=( UInt const & rhs );
		Int & operator&=( Optional< UInt > const & rhs );
		Int & operator|=( Optional< UInt > const & rhs );
	};

	Int operator+( Int const & lhs, uint32_t const & rhs );
	Int operator-( Int const & lhs, uint32_t const & rhs );
	Int operator*( Int const & lhs, uint32_t const & rhs );
	Int operator/( Int const & lhs, uint32_t const & rhs );
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
	Int operator%( Int const & lhs, uint32_t const & rhs );
	Int operator%( Int const & lhs, Int const & rhs );
	Int operator%( Int const & lhs, UInt const & rhs );

	Int operator<<( Int const & lhs, int32_t const & rhs );
	Int operator>>( Int const & lhs, int32_t const & rhs );
	Int operator<<( Int const & lhs, uint32_t const & rhs );
	Int operator>>( Int const & lhs, uint32_t const & rhs );
	Int operator<<( Int const & lhs, Int const & rhs );
	Int operator>>( Int const & lhs, Int const & rhs );
	Int operator<<( Int const & lhs, UInt const & rhs );
	Int operator>>( Int const & lhs, UInt const & rhs );
	Int operator&( Int const & lhs, int32_t const & rhs );
	Int operator|( Int const & lhs, int32_t const & rhs );
	Int operator&( Int const & lhs, uint32_t const & rhs );
	Int operator|( Int const & lhs, uint32_t const & rhs );
	Int operator&( Int const & lhs, Int const & rhs );
	Int operator|( Int const & lhs, Int const & rhs );
	Int operator&( Int const & lhs, UInt const & rhs );
	Int operator|( Int const & lhs, UInt const & rhs );
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
	Optional< Int > operator+( Optional< Int > const & lhs, uint32_t const & rhs );
	Optional< Int > operator-( Optional< Int > const & lhs, uint32_t const & rhs );
	Optional< Int > operator*( Optional< Int > const & lhs, uint32_t const & rhs );
	Optional< Int > operator/( Optional< Int > const & lhs, uint32_t const & rhs );
	Optional< Int > operator+( Optional< Int > const & lhs, int32_t const & rhs );
	Optional< Int > operator-( Optional< Int > const & lhs, int32_t const & rhs );
	Optional< Int > operator*( Optional< Int > const & lhs, int32_t const & rhs );
	Optional< Int > operator/( Optional< Int > const & lhs, int32_t const & rhs );
	Optional< Int > operator+( int32_t const & lhs, Optional< Int > const & rhs );
	Optional< Int > operator-( int32_t const & lhs, Optional< Int > const & rhs );
	Optional< Int > operator*( int32_t const & lhs, Optional< Int > const & rhs );
	Optional< Int > operator/( int32_t const & lhs, Optional< Int > const & rhs );
	Optional< Int > operator+( uint32_t const & lhs, Optional< Int > const & rhs );
	Optional< Int > operator-( uint32_t const & lhs, Optional< Int > const & rhs );
	Optional< Int > operator*( uint32_t const & lhs, Optional< Int > const & rhs );
	Optional< Int > operator/( uint32_t const & lhs, Optional< Int > const & rhs );
	Optional< Int > operator%( Optional< Int > const & lhs, int32_t const & rhs );
	Optional< Int > operator%( Optional< Int > const & lhs, uint32_t const & rhs );
	Optional< Int > operator%( Optional< Int > const & lhs, Int const & rhs );
	Optional< Int > operator%( Int const & lhs, Optional< Int > const & rhs );
	Optional< Int > operator%( Optional< Int > const & lhs, Optional< Int > const & rhs );
	Optional< Int > operator%( Optional< Int > const & lhs, UInt const & rhs );
	Optional< Int > operator%( Int const & lhs, Optional< UInt > const & rhs );
	Optional< Int > operator%( Optional< Int > const & lhs, Optional< UInt > const & rhs );

	Optional< Int > operator<<( Optional< Int > const & lhs, int32_t const & rhs );
	Optional< Int > operator>>( Optional< Int > const & lhs, int32_t const & rhs );
	Optional< Int > operator<<( Optional< Int > const & lhs, uint32_t const & rhs );
	Optional< Int > operator>>( Optional< Int > const & lhs, uint32_t const & rhs );
	Optional< Int > operator<<( Optional< Int > const & lhs, Int const & rhs );
	Optional< Int > operator>>( Optional< Int > const & lhs, Int const & rhs );
	Optional< Int > operator<<( Int const & lhs, Optional< Int > const & rhs );
	Optional< Int > operator>>( Int const & lhs, Optional< Int > const & rhs );
	Optional< Int > operator<<( Optional< Int > const & lhs, Optional< Int > const & rhs );
	Optional< Int > operator>>( Optional< Int > const & lhs, Optional< Int > const & rhs );
	Optional< Int > operator<<( Optional< Int > const & lhs, UInt const & rhs );
	Optional< Int > operator>>( Optional< Int > const & lhs, UInt const & rhs );
	Optional< Int > operator<<( Int const & lhs, Optional< UInt > const & rhs );
	Optional< Int > operator>>( Int const & lhs, Optional< UInt > const & rhs );
	Optional< Int > operator<<( Optional< Int > const & lhs, Optional< UInt > const & rhs );
	Optional< Int > operator>>( Optional< Int > const & lhs, Optional< UInt > const & rhs );
	Optional< Int > operator&( Optional< Int > const & lhs, int32_t const & rhs );
	Optional< Int > operator|( Optional< Int > const & lhs, int32_t const & rhs );
	Optional< Int > operator&( Optional< Int > const & lhs, uint32_t const & rhs );
	Optional< Int > operator|( Optional< Int > const & lhs, uint32_t const & rhs );
	Optional< Int > operator&( Optional< Int > const & lhs, Int const & rhs );
	Optional< Int > operator|( Optional< Int > const & lhs, Int const & rhs );
	Optional< Int > operator&( Int const & lhs, Optional< Int > const & rhs );
	Optional< Int > operator|( Int const & lhs, Optional< Int > const & rhs );
	Optional< Int > operator&( Optional< Int > const & lhs, Optional< Int > const & rhs );
	Optional< Int > operator|( Optional< Int > const & lhs, Optional< Int > const & rhs );
	Optional< Int > operator&( Optional< Int > const & lhs, UInt const & rhs );
	Optional< Int > operator|( Optional< Int > const & lhs, UInt const & rhs );
	Optional< Int > operator&( Int const & lhs, Optional< UInt > const & rhs );
	Optional< Int > operator|( Int const & lhs, Optional< UInt > const & rhs );
	Optional< Int > operator&( Optional< Int > const & lhs, Optional< UInt > const & rhs );
	Optional< Int > operator|( Optional< Int > const & lhs, Optional< UInt > const & rhs );
	Optional< Int > operator~( Optional< Int > const & value );
}

inline sdw::Int operator "" _i( unsigned long long value )
{
	return sdw::Int{ nullptr, sdw::makeExpr( int( value ) ) };
}

#include "Int.inl"

#endif
