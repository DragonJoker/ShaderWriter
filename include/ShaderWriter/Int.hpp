/*
See LICENSE file in root folder
*/
#ifndef ___Writer_Int_H___
#define ___Writer_Int_H___
#pragma once

#include "Value.hpp"

namespace sdw
{
	struct Int
		: public Value
	{
		Int( stmt::Container * container
			, expr::ExprPtr expr );
		Int( Int && rhs );
		Int( Int const & rhs );
		Int( Value const & rhs );
		Int & operator=( Int const & rhs );
		template< typename T >
		inline Int & operator=( T const & rhs );
		Int & operator=( int32_t rhs );
		Int & operator=( int64_t rhs );
		Int & operator=( uint32_t rhs );
		Int & operator=( uint64_t rhs );
		explicit operator uint32_t();
		Int & operator++();
		Int operator++( int );
		Int & operator--();
		Int operator--( int );
		Int & operator<<=( int rhs );
		Int & operator>>=( int rhs );
		Int & operator<<=( Int const & rhs );
		Int & operator>>=( Int const & rhs );
		Int & operator<<=( UInt const & rhs );
		Int & operator>>=( UInt const & rhs );
		Int & operator&=( int rhs );
		Int & operator|=( int rhs );
		Int & operator&=( Int const & rhs );
		Int & operator|=( Int const & rhs );
		Int & operator&=( UInt const & rhs );
		Int & operator|=( UInt const & rhs );
	};

	Int operator<<( Int const & lhs, int rhs );
	Int operator>>( Int const & lhs, int rhs );
	Int operator<<( Int const & lhs, Int const & rhs );
	Int operator>>( Int const & lhs, Int const & rhs );
	Int operator<<( Int const & lhs, UInt const & rhs );
	Int operator>>( Int const & lhs, UInt const & rhs );
	Int operator&( Int const & lhs, int rhs );
	Int operator|( Int const & lhs, int rhs );
	Int operator&( Int const & lhs, Int const & rhs );
	Int operator|( Int const & lhs, Int const & rhs );
	Int operator&( Int const & lhs, UInt const & rhs );
	Int operator|( Int const & lhs, UInt const & rhs );
	Int operator~( Int const & value );

	inline Int operator "" _i( unsigned long long value )
	{
		return Int{ nullptr, makeExpr( int( value ) ) };
	}
}

#include "Int.inl"

#endif
