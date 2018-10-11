/*
See LICENSE file in root folder
*/
#ifndef ___Writer_UInt_H___
#define ___Writer_UInt_H___
#pragma once

#include "Value.hpp"

namespace sdw
{
	struct UInt
		: public Value
	{
		UInt( stmt::Container * container
			, expr::ExprPtr expr );
		UInt( UInt && value );
		UInt( UInt const & value );
		UInt( Value const & value );
		inline UInt & operator=( UInt const & rhs );
		template< typename T >
		inline UInt & operator=( T const & rhs );
		UInt & operator=( int32_t rhs );
		UInt & operator=( int64_t rhs );
		UInt & operator=( uint32_t rhs );
		UInt & operator=( uint64_t rhs );
		explicit operator uint32_t();
		UInt & operator++();
		UInt operator++( int );
		UInt & operator--();
		UInt operator--( int );
		UInt & operator<<=( int rhs );
		UInt & operator>>=( int rhs );
		UInt & operator<<=( Int const & rhs );
		UInt & operator>>=( Int const & rhs );
		UInt & operator<<=( UInt const & rhs );
		UInt & operator>>=( UInt const & rhs );
		UInt & operator&=( int rhs );
		UInt & operator|=( int rhs );
		UInt & operator&=( Int const & rhs );
		UInt & operator|=( Int const & rhs );
		UInt & operator&=( UInt const & rhs );
		UInt & operator|=( UInt const & rhs );
	};

	UInt operator<<( UInt const & lhs, int rhs );
	UInt operator>>( UInt const & lhs, int rhs );
	UInt operator<<( UInt const & lhs, Int const & rhs );
	UInt operator>>( UInt const & lhs, Int const & rhs );
	UInt operator<<( UInt const & lhs, UInt const & rhs );
	UInt operator>>( UInt const & lhs, UInt const & rhs );
	UInt operator&( UInt const & lhs, int rhs );
	UInt operator|( UInt const & lhs, int rhs );
	UInt operator&( UInt const & lhs, Int const & rhs );
	UInt operator|( UInt const & lhs, Int const & rhs );
	UInt operator&( UInt const & lhs, UInt const & rhs );
	UInt operator|( UInt const & lhs, UInt const & rhs );
	UInt operator~( UInt const & value );

	inline UInt operator "" _u( unsigned long long value )
	{
		return UInt{ nullptr, make( uint32_t( value ) ) };
	}
}

#include "UInt.inl"

#endif
