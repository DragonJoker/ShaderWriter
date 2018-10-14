/*
See LICENSE file in root folder
*/
#ifndef ___Writer_Vec3_H___
#define ___Writer_Vec3_H___
#pragma once

#include "Vec2.hpp"

namespace sdw
{
	template< typename ValueT >
	struct Vec3T
		: public Value
	{
		using ValueType = ValueT;
		using Vec2Type = Vec2T< ValueT >;
		using Vec3Type = Vec3T< ValueT >;

		inline Vec3T();
		inline Vec3T( Shader * shader
			, expr::ExprPtr expr );
		inline Vec3T< ValueT > & operator=( Vec3T< ValueT > const & rhs );
		template< typename IndexT >
		inline ValueT operator[]( IndexT const & rhs )const;
		inline Vec3T< ValueT > & operator+=( Vec3T< ValueT > const & rhs );
		inline Vec3T< ValueT > & operator-=( Vec3T< ValueT > const & rhs );
		inline Vec3T< ValueT > & operator*=( Vec3T< ValueT > const & rhs );
		inline Vec3T< ValueT > & operator+=( Optional< Vec3T< ValueT > > const & rhs );
		inline Vec3T< ValueT > & operator-=( Optional< Vec3T< ValueT > > const & rhs );
		inline Vec3T< ValueT > & operator*=( Optional< Vec3T< ValueT > > const & rhs );
		inline Vec3T< ValueT > & operator+=( ValueT rhs );
		inline Vec3T< ValueT > & operator-=( ValueT rhs );
		inline Vec3T< ValueT > & operator*=( ValueT rhs );
		inline Vec3T< ValueT > & operator/=( ValueT rhs );

		Writer_FirstSwizzle( Vec3Type, ValueType, x );
		Writer_Swizzle( Vec3Type, ValueType, y );
		Writer_Swizzle( Vec3Type, ValueType, z );
		Writer_Swizzle( Vec3Type, ValueType, s );
		Writer_Swizzle( Vec3Type, ValueType, t );
		Writer_Swizzle( Vec3Type, ValueType, p );
		Writer_Swizzle( Vec3Type, ValueType, r );
		Writer_Swizzle( Vec3Type, ValueType, g );
		Writer_LastSwizzle( Vec3Type, ValueType, b );
		Writer_FirstSwizzle( Vec3Type, Vec2Type, xy );
		Writer_Swizzle( Vec3Type, Vec2Type, xz );
		Writer_Swizzle( Vec3Type, Vec2Type, yx );
		Writer_Swizzle( Vec3Type, Vec2Type, yz );
		Writer_Swizzle( Vec3Type, Vec2Type, zx );
		Writer_Swizzle( Vec3Type, Vec2Type, zy );
		Writer_Swizzle( Vec2Type, Vec2Type, xx );
		Writer_Swizzle( Vec2Type, Vec2Type, yy );
		Writer_Swizzle( Vec2Type, Vec2Type, zz );
		Writer_Swizzle( Vec3Type, Vec2Type, st );
		Writer_Swizzle( Vec3Type, Vec2Type, sp );
		Writer_Swizzle( Vec3Type, Vec2Type, ts );
		Writer_Swizzle( Vec3Type, Vec2Type, tp );
		Writer_Swizzle( Vec3Type, Vec2Type, ps );
		Writer_Swizzle( Vec3Type, Vec2Type, pt );
		Writer_Swizzle( Vec2Type, ValueType, ss );
		Writer_Swizzle( Vec2Type, ValueType, tt );
		Writer_Swizzle( Vec2Type, ValueType, pp );
		Writer_Swizzle( Vec3Type, Vec2Type, rg );
		Writer_Swizzle( Vec3Type, Vec2Type, rb );
		Writer_Swizzle( Vec3Type, Vec2Type, gr );
		Writer_Swizzle( Vec3Type, Vec2Type, gb );
		Writer_Swizzle( Vec3Type, Vec2Type, br );
		Writer_Swizzle( Vec2Type, Vec2Type, bg );
		Writer_Swizzle( Vec2Type, Vec2Type, rr );
		Writer_Swizzle( Vec2Type, Vec2Type, gg );
		Writer_LastSwizzle( Vec3Type, Vec2Type, bb );
		Writer_FirstSwizzle( Vec3Type, Vec3Type, xyz );
		Writer_Swizzle( Vec3Type, Vec3Type, xzy );
		Writer_Swizzle( Vec3Type, Vec3Type, yxz );
		Writer_Swizzle( Vec3Type, Vec3Type, yzx );
		Writer_Swizzle( Vec3Type, Vec3Type, zxy );
		Writer_Swizzle( Vec3Type, Vec3Type, zyx );
		Writer_Swizzle( Vec3Type, Vec3Type, stp );
		Writer_Swizzle( Vec3Type, Vec3Type, spt );
		Writer_Swizzle( Vec3Type, Vec3Type, tsp );
		Writer_Swizzle( Vec3Type, Vec3Type, tps );
		Writer_Swizzle( Vec3Type, Vec3Type, pst );
		Writer_Swizzle( Vec3Type, Vec3Type, pts );
		Writer_Swizzle( Vec3Type, Vec3Type, rgb );
		Writer_Swizzle( Vec3Type, Vec3Type, rbg );
		Writer_Swizzle( Vec3Type, Vec3Type, grb );
		Writer_Swizzle( Vec3Type, Vec3Type, gbr );
		Writer_Swizzle( Vec3Type, Vec3Type, brg );
		Writer_LastSwizzle( Vec3Type, Vec3Type, bgr );
	};

	template< typename ValueT >
	inline Vec3T< ValueT > operator+( ValueT const & lhs
		, Vec3T< ValueT > const & rhs );
	template< typename ValueT >
	inline Vec3T< ValueT > operator+( Vec3T< ValueT > const & lhs
		, ValueT const & rhs );
	template< typename ValueT >
	inline Vec3T< ValueT > operator+( Vec3T< ValueT > const & lhs
		, Vec3T< ValueT > const & rhs );
	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator+( Optional< ValueT > const & lhs
		, Vec3T< ValueT > const & rhs );
	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator+( Optional< Vec3T< ValueT > > const & lhs
		, ValueT const & rhs );
	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator+( Optional< Vec3T< ValueT > > const & lhs
		, Vec3T< ValueT > const & rhs );
	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator+( ValueT const & lhs
		, Optional< Vec3T< ValueT > > const & rhs );
	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator+( Vec3T< ValueT > const & lhs
		, Optional< ValueT > const & rhs );
	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator+( Vec3T< ValueT > const & lhs
		, Optional< Vec3T< ValueT > > const & rhs );
	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator+( Optional< ValueT > const & lhs
		, Optional< Vec3T< ValueT > > const & rhs );
	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator+( Optional< Vec3T< ValueT > > const & lhs
		, Optional< ValueT > const & rhs );
	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator+( Optional< Vec3T< ValueT > > const & lhs
		, Optional< Vec3T< ValueT > > const & rhs );
	template< typename ValueT >
	inline Vec3T< ValueT > operator-( ValueT const & lhs
		, Vec3T< ValueT > const & rhs );
	template< typename ValueT >
	inline Vec3T< ValueT > operator-( Vec3T< ValueT > const & lhs
		, ValueT const & rhs );
	template< typename ValueT >
	inline Vec3T< ValueT > operator-( Vec3T< ValueT > const & lhs
		, Vec3T< ValueT > const & rhs );
	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator-( Optional< ValueT > const & lhs
		, Vec3T< ValueT > const & rhs );
	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator-( Optional< Vec3T< ValueT > > const & lhs
		, ValueT const & rhs );
	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator-( Optional< Vec3T< ValueT > > const & lhs
		, Vec3T< ValueT > const & rhs );
	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator-( ValueT const & lhs
		, Optional< Vec3T< ValueT > > const & rhs );
	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator-( Vec3T< ValueT > const & lhs
		, Optional< ValueT > const & rhs );
	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator-( Vec3T< ValueT > const & lhs
		, Optional< Vec3T< ValueT > > const & rhs );
	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator-( Optional< ValueT > const & lhs
		, Optional< Vec3T< ValueT > > const & rhs );
	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator-( Optional< Vec3T< ValueT > > const & lhs
		, Optional< ValueT > const & rhs );
	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator-( Optional< Vec3T< ValueT > > const & lhs
		, Optional< Vec3T< ValueT > > const & rhs );
	template< typename ValueT >
	inline Vec3T< ValueT > operator*( ValueT const & lhs
		, Vec3T< ValueT > const & rhs );
	template< typename ValueT >
	inline Vec3T< ValueT > operator*( Vec3T< ValueT > const & lhs
		, ValueT const & rhs );
	template< typename ValueT >
	inline Vec3T< ValueT > operator*( Vec3T< ValueT > const & lhs
		, Vec3T< ValueT > const & rhs );
	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator*( Optional< ValueT > const & lhs
		, Vec3T< ValueT > const & rhs );
	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator*( Optional< Vec3T< ValueT > > const & lhs
		, ValueT const & rhs );
	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator*( Optional< Vec3T< ValueT > > const & lhs
		, Vec3T< ValueT > const & rhs );
	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator*( ValueT const & lhs
		, Optional< Vec3T< ValueT > > const & rhs );
	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator*( Vec3T< ValueT > const & lhs
		, Optional< ValueT > const & rhs );
	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator*( Vec3T< ValueT > const & lhs
		, Optional< Vec3T< ValueT > > const & rhs );
	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator*( Optional< ValueT > const & lhs
		, Optional< Vec3T< ValueT > > const & rhs );
	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator*( Optional< Vec3T< ValueT > > const & lhs
		, Optional< ValueT > const & rhs );
	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator*( Optional< Vec3T< ValueT > > const & lhs
		, Optional< Vec3T< ValueT > > const & rhs );
	template< typename ValueT >
	inline Vec3T< ValueT > operator/( Vec3T< ValueT > const & lhs
		, ValueT const & rhs );
	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator/( Optional< Vec3T< ValueT > > const & lhs
		, ValueT const & rhs );
	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator/( Vec3T< ValueT > const & lhs
		, Optional< ValueT > const & rhs );
	template< typename ValueT >
	inline Optional< Vec3T< ValueT > > operator/( Optional< Vec3T< ValueT > > const & lhs
		, Optional< ValueT > const & rhs );
}

#include "Vec3.inl"

#endif
