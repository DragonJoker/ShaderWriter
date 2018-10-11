/*
See LICENSE file in root folder
*/
#ifndef ___Writer_Vec2_H___
#define ___Writer_Vec2_H___
#pragma once

#include "Bool.hpp"
#include "Float.hpp"
#include "Int.hpp"
#include "UInt.hpp"
#include "Swizzle.hpp"

namespace sdw
{
	template< typename ValueT >
	struct Vec2T
		: public Value
	{
		using ValueType = ValueT;
		using Vec2Type = Vec2T< ValueT >;

		inline Vec2T( stmt::Container * container
			, expr::ExprPtr expr );
		inline Vec2T< ValueT > & operator=( Vec2T< ValueT > const & rhs );
		template< typename IndexT >
		inline ValueT operator[]( IndexT const & rhs )const;

		inline Vec2T< ValueT > & operator+=( Vec2T< ValueT > const & rhs );
		inline Vec2T< ValueT > & operator-=( Vec2T< ValueT > const & rhs );
		inline Vec2T< ValueT > & operator*=( Vec2T< ValueT > const & rhs );
		inline Vec2T< ValueT > & operator+=( Optional< Vec2T< ValueT > > const & rhs );
		inline Vec2T< ValueT > & operator-=( Optional< Vec2T< ValueT > > const & rhs );
		inline Vec2T< ValueT > & operator*=( Optional< Vec2T< ValueT > > const & rhs );
		inline Vec2T< ValueT > & operator+=( ValueT rhs );
		inline Vec2T< ValueT > & operator-=( ValueT rhs );
		inline Vec2T< ValueT > & operator*=( ValueT rhs );
		inline Vec2T< ValueT > & operator/=( ValueT rhs );
		inline Vec2T< ValueT > & operator+=( Optional< ValueT > rhs );
		inline Vec2T< ValueT > & operator-=( Optional< ValueT > rhs );
		inline Vec2T< ValueT > & operator*=( Optional< ValueT > rhs );
		inline Vec2T< ValueT > & operator/=( Optional< ValueT > rhs );

		Writer_FirstSwizzle( Vec2Type, ValueType, x );
		Writer_Swizzle( Vec2Type, ValueType, y );
		Writer_Swizzle( Vec2Type, ValueType, s );
		Writer_Swizzle( Vec2Type, ValueType, t );
		Writer_Swizzle( Vec2Type, ValueType, r );
		Writer_LastSwizzle( Vec2Type, ValueType, g );
		Writer_FirstSwizzle( Vec2Type, Vec2Type, xy );
		Writer_Swizzle( Vec2Type, Vec2Type, yx );
		Writer_Swizzle( Vec2Type, Vec2Type, xx );
		Writer_Swizzle( Vec2Type, Vec2Type, yy );
		Writer_Swizzle( Vec2Type, ValueType, st );
		Writer_Swizzle( Vec2Type, ValueType, ts );
		Writer_Swizzle( Vec2Type, ValueType, ss );
		Writer_Swizzle( Vec2Type, ValueType, tt );
		Writer_Swizzle( Vec2Type, Vec2Type, rg );
		Writer_Swizzle( Vec2Type, Vec2Type, gr );
		Writer_Swizzle( Vec2Type, Vec2Type, rr );
		Writer_LastSwizzle( Vec2Type, Vec2Type, gg );
	};

	template< typename ValueT >
	inline Vec2T< ValueT > operator+( ValueT const & lhs
		, Vec2T< ValueT > const & rhs );
	template< typename ValueT >
	inline Vec2T< ValueT > operator+( Vec2T< ValueT > const & lhs
		, ValueT const & rhs );
	template< typename ValueT >
	inline Vec2T< ValueT > operator+( Vec2T< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs );
	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator+( Optional< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs );
	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator+( Optional< Vec2T< ValueT > > const & lhs
		, ValueT const & rhs );
	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator+( Optional< Vec2T< ValueT > > const & lhs
		, Vec2T< ValueT > const & rhs );
	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator+( ValueT const & lhs
		, Optional< Vec2T< ValueT > > const & rhs );
	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator+( Vec2T< ValueT > const & lhs
		, Optional< ValueT > const & rhs );
	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator+( Vec2T< ValueT > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs );
	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator+( Optional< ValueT > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs );
	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator+( Optional< Vec2T< ValueT > > const & lhs
		, Optional< ValueT > const & rhs );
	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator+( Optional< Vec2T< ValueT > > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs );
	template< typename ValueT >
	inline Vec2T< ValueT > operator-( ValueT const & lhs
		, Vec2T< ValueT > const & rhs );
	template< typename ValueT >
	inline Vec2T< ValueT > operator-( Vec2T< ValueT > const & lhs
		, ValueT const & rhs );
	template< typename ValueT >
	inline Vec2T< ValueT > operator-( Vec2T< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs );
	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator-( Optional< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs );
	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator-( Optional< Vec2T< ValueT > > const & lhs
		, ValueT const & rhs );
	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator-( Optional< Vec2T< ValueT > > const & lhs
		, Vec2T< ValueT > const & rhs );
	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator-( ValueT const & lhs
		, Optional< Vec2T< ValueT > > const & rhs );
	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator-( Vec2T< ValueT > const & lhs
		, Optional< ValueT > const & rhs );
	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator-( Vec2T< ValueT > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs );
	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator-( Optional< ValueT > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs );
	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator-( Optional< Vec2T< ValueT > > const & lhs
		, Optional< ValueT > const & rhs );
	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator-( Optional< Vec2T< ValueT > > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs );
	template< typename ValueT >
	inline Vec2T< ValueT > operator*( ValueT const & lhs
		, Vec2T< ValueT > const & rhs );
	template< typename ValueT >
	inline Vec2T< ValueT > operator*( Vec2T< ValueT > const & lhs
		, ValueT const & rhs );
	template< typename ValueT >
	inline Vec2T< ValueT > operator*( Vec2T< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs );
	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator*( Optional< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs );
	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator*( Optional< Vec2T< ValueT > > const & lhs
		, ValueT const & rhs );
	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator*( Optional< Vec2T< ValueT > > const & lhs
		, Vec2T< ValueT > const & rhs );
	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator*( ValueT const & lhs
		, Optional< Vec2T< ValueT > > const & rhs );
	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator*( Vec2T< ValueT > const & lhs
		, Optional< ValueT > const & rhs );
	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator*( Vec2T< ValueT > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs );
	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator*( Optional< ValueT > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs );
	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator*( Optional< Vec2T< ValueT > > const & lhs
		, Optional< ValueT > const & rhs );
	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator*( Optional< Vec2T< ValueT > > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs );
	template< typename ValueT >
	inline Vec2T< ValueT > operator/( Vec2T< ValueT > const & lhs
		, ValueT const & rhs );
	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator/( Optional< Vec2T< ValueT > > const & lhs
		, ValueT const & rhs );
	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator/( Vec2T< ValueT > const & lhs
		, Optional< ValueT > const & rhs );
	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator/( Optional< Vec2T< ValueT > > const & lhs
		, Optional< ValueT > const & rhs );
}

#include "Vec2.inl"

#endif
