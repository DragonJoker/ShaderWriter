/*
See LICENSE file in root folder
*/
#ifndef ___SDW_OptionalVec4_H___
#define ___SDW_OptionalVec4_H___
#pragma once

#include "ShaderWriter/VecTypes/Vec4.hpp"

namespace sdw
{
	template< typename ValueT >
	struct Optional< Vec4T< ValueT > >
		: public Vec4T< ValueT >
	{
		using ValueType = Optional< ValueT >;
		using Vec2Type = Optional< Vec2T< ValueT > >;
		using Vec3Type = Optional< Vec3T< ValueT > >;
		using Vec4Type = Optional< Vec4T< ValueT > >;

		inline Optional( Shader * shader
			, expr::ExprPtr expr
			, bool enabled );
		inline Optional( Vec4T< ValueT > const & other
			, bool enabled );
		inline Optional( Optional< Vec4T< ValueT > > const & rhs );
		inline Optional< Vec4T< ValueT > > & operator=( Optional< Vec4T< ValueT > > const & rhs );
		template< typename IndexT >
		inline Optional< ValueT > operator[]( IndexT const & rhs )const;
		inline bool isEnabled()const;

		inline operator Optional< Value >()const;

		inline Optional< Vec4T< ValueT > > & operator+=( Vec4T< ValueT > const & rhs );
		inline Optional< Vec4T< ValueT > > & operator-=( Vec4T< ValueT > const & rhs );
		inline Optional< Vec4T< ValueT > > & operator*=( Vec4T< ValueT > const & rhs );
		inline Optional< Vec4T< ValueT > > & operator/=( Vec4T< ValueT > const & rhs );
		inline Optional< Vec4T< ValueT > > & operator+=( Optional< Vec4T< ValueT > > const & rhs );
		inline Optional< Vec4T< ValueT > > & operator-=( Optional< Vec4T< ValueT > > const & rhs );
		inline Optional< Vec4T< ValueT > > & operator*=( Optional< Vec4T< ValueT > > const & rhs );
		inline Optional< Vec4T< ValueT > > & operator/=( Optional< Vec4T< ValueT > > const & rhs );
		inline Optional< Vec4T< ValueT > > & operator+=( ValueT const & rhs );
		inline Optional< Vec4T< ValueT > > & operator-=( ValueT const & rhs );
		inline Optional< Vec4T< ValueT > > & operator*=( ValueT const & rhs );
		inline Optional< Vec4T< ValueT > > & operator/=( ValueT const & rhs );
		inline Optional< Vec4T< ValueT > > & operator+=( Optional< ValueT > const & rhs );
		inline Optional< Vec4T< ValueT > > & operator-=( Optional< ValueT > const & rhs );
		inline Optional< Vec4T< ValueT > > & operator*=( Optional< ValueT > const & rhs );
		inline Optional< Vec4T< ValueT > > & operator/=( Optional< ValueT > const & rhs );
		inline Optional< Vec4T< ValueT > > operator-()const;
		inline Optional< Vec4T< ValueT > > operator+()const;

		Writer_FirstOptSwizzle( Vec4Type, ValueType, x );
		Writer_OptSwizzle( Vec4Type, ValueType, y );
		Writer_OptSwizzle( Vec4Type, ValueType, z );
		Writer_OptSwizzle( Vec4Type, ValueType, w );
		Writer_OptSwizzle( Vec4Type, ValueType, s );
		Writer_OptSwizzle( Vec4Type, ValueType, t );
		Writer_OptSwizzle( Vec4Type, ValueType, p );
		Writer_OptSwizzle( Vec4Type, ValueType, q );
		Writer_OptSwizzle( Vec4Type, ValueType, r );
		Writer_OptSwizzle( Vec4Type, ValueType, g );
		Writer_OptSwizzle( Vec4Type, ValueType, b );
		Writer_LastOptSwizzle( Vec4Type, ValueType, a );
		Writer_FirstOptSwizzle( Vec4Type, Vec2Type, xy );
		Writer_OptSwizzle( Vec4Type, Vec2Type, xz );
		Writer_OptSwizzle( Vec4Type, Vec2Type, xw );
		Writer_OptSwizzle( Vec4Type, Vec2Type, yx );
		Writer_OptSwizzle( Vec4Type, Vec2Type, yz );
		Writer_OptSwizzle( Vec4Type, Vec2Type, yw );
		Writer_OptSwizzle( Vec4Type, Vec2Type, zx );
		Writer_OptSwizzle( Vec4Type, Vec2Type, zy );
		Writer_OptSwizzle( Vec4Type, Vec2Type, zw );
		Writer_OptSwizzle( Vec4Type, Vec2Type, wx );
		Writer_OptSwizzle( Vec4Type, Vec2Type, wy );
		Writer_OptSwizzle( Vec4Type, Vec2Type, wz );
		Writer_OptSwizzle( Vec2Type, Vec2Type, xx );
		Writer_OptSwizzle( Vec2Type, Vec2Type, yy );
		Writer_OptSwizzle( Vec2Type, Vec2Type, zz );
		Writer_OptSwizzle( Vec2Type, Vec2Type, ww );
		Writer_OptSwizzle( Vec4Type, Vec2Type, st );
		Writer_OptSwizzle( Vec4Type, Vec2Type, sp );
		Writer_OptSwizzle( Vec4Type, Vec2Type, sq );
		Writer_OptSwizzle( Vec4Type, Vec2Type, ts );
		Writer_OptSwizzle( Vec4Type, Vec2Type, tp );
		Writer_OptSwizzle( Vec4Type, Vec2Type, tq );
		Writer_OptSwizzle( Vec4Type, Vec2Type, ps );
		Writer_OptSwizzle( Vec4Type, Vec2Type, pt );
		Writer_OptSwizzle( Vec4Type, Vec2Type, pq );
		Writer_OptSwizzle( Vec4Type, Vec2Type, qs );
		Writer_OptSwizzle( Vec4Type, Vec2Type, qt );
		Writer_OptSwizzle( Vec4Type, Vec2Type, qp );
		Writer_OptSwizzle( Vec2Type, ValueType, ss );
		Writer_OptSwizzle( Vec2Type, ValueType, tt );
		Writer_OptSwizzle( Vec2Type, ValueType, pp );
		Writer_OptSwizzle( Vec2Type, ValueType, qq );
		Writer_OptSwizzle( Vec4Type, Vec2Type, rg );
		Writer_OptSwizzle( Vec4Type, Vec2Type, rb );
		Writer_OptSwizzle( Vec4Type, Vec2Type, ra );
		Writer_OptSwizzle( Vec4Type, Vec2Type, gr );
		Writer_OptSwizzle( Vec4Type, Vec2Type, gb );
		Writer_OptSwizzle( Vec4Type, Vec2Type, ga );
		Writer_OptSwizzle( Vec4Type, Vec2Type, br );
		Writer_OptSwizzle( Vec4Type, Vec2Type, bg );
		Writer_OptSwizzle( Vec4Type, Vec2Type, ba );
		Writer_OptSwizzle( Vec4Type, Vec2Type, ar );
		Writer_OptSwizzle( Vec4Type, Vec2Type, ag );
		Writer_OptSwizzle( Vec4Type, Vec2Type, ab );
		Writer_OptSwizzle( Vec2Type, Vec2Type, rr );
		Writer_OptSwizzle( Vec2Type, Vec2Type, gg );
		Writer_OptSwizzle( Vec2Type, Vec2Type, bb );
		Writer_LastOptSwizzle( Vec3Type, Vec2Type, aa );
		Writer_FirstOptSwizzle( Vec4Type, Vec3Type, xyz );
		Writer_OptSwizzle( Vec4Type, Vec3Type, xyw );
		Writer_OptSwizzle( Vec4Type, Vec3Type, xzy );
		Writer_OptSwizzle( Vec4Type, Vec3Type, xzw );
		Writer_OptSwizzle( Vec4Type, Vec3Type, xwy );
		Writer_OptSwizzle( Vec4Type, Vec3Type, xwz );
		Writer_OptSwizzle( Vec4Type, Vec3Type, yxz );
		Writer_OptSwizzle( Vec4Type, Vec3Type, yxw );
		Writer_OptSwizzle( Vec4Type, Vec3Type, yzx );
		Writer_OptSwizzle( Vec4Type, Vec3Type, yzw );
		Writer_OptSwizzle( Vec4Type, Vec3Type, ywx );
		Writer_OptSwizzle( Vec4Type, Vec3Type, ywz );
		Writer_OptSwizzle( Vec4Type, Vec3Type, zxy );
		Writer_OptSwizzle( Vec4Type, Vec3Type, zxw );
		Writer_OptSwizzle( Vec4Type, Vec3Type, zyx );
		Writer_OptSwizzle( Vec4Type, Vec3Type, zyw );
		Writer_OptSwizzle( Vec4Type, Vec3Type, zwx );
		Writer_OptSwizzle( Vec4Type, Vec3Type, zwy );
		Writer_OptSwizzle( Vec4Type, Vec3Type, wxy );
		Writer_OptSwizzle( Vec4Type, Vec3Type, wxz );
		Writer_OptSwizzle( Vec4Type, Vec3Type, wyx );
		Writer_OptSwizzle( Vec4Type, Vec3Type, wyz );
		Writer_OptSwizzle( Vec4Type, Vec3Type, wzx );
		Writer_OptSwizzle( Vec4Type, Vec3Type, wzy );
		Writer_OptSwizzle( Vec4Type, Vec3Type, xxx );
		Writer_OptSwizzle( Vec4Type, Vec3Type, yyy );
		Writer_OptSwizzle( Vec4Type, Vec3Type, zzz );
		Writer_OptSwizzle( Vec4Type, Vec3Type, www );
		Writer_OptSwizzle( Vec4Type, Vec3Type, stp );
		Writer_OptSwizzle( Vec4Type, Vec3Type, stq );
		Writer_OptSwizzle( Vec4Type, Vec3Type, spt );
		Writer_OptSwizzle( Vec4Type, Vec3Type, spq );
		Writer_OptSwizzle( Vec4Type, Vec3Type, sqt );
		Writer_OptSwizzle( Vec4Type, Vec3Type, sqp );
		Writer_OptSwizzle( Vec4Type, Vec3Type, tsp );
		Writer_OptSwizzle( Vec4Type, Vec3Type, tsq );
		Writer_OptSwizzle( Vec4Type, Vec3Type, tps );
		Writer_OptSwizzle( Vec4Type, Vec3Type, tpq );
		Writer_OptSwizzle( Vec4Type, Vec3Type, tqs );
		Writer_OptSwizzle( Vec4Type, Vec3Type, tqp );
		Writer_OptSwizzle( Vec4Type, Vec3Type, pst );
		Writer_OptSwizzle( Vec4Type, Vec3Type, psq );
		Writer_OptSwizzle( Vec4Type, Vec3Type, pts );
		Writer_OptSwizzle( Vec4Type, Vec3Type, ptq );
		Writer_OptSwizzle( Vec4Type, Vec3Type, pqs );
		Writer_OptSwizzle( Vec4Type, Vec3Type, pqt );
		Writer_OptSwizzle( Vec4Type, Vec3Type, qst );
		Writer_OptSwizzle( Vec4Type, Vec3Type, qsp );
		Writer_OptSwizzle( Vec4Type, Vec3Type, qts );
		Writer_OptSwizzle( Vec4Type, Vec3Type, qtp );
		Writer_OptSwizzle( Vec4Type, Vec3Type, qps );
		Writer_OptSwizzle( Vec4Type, Vec3Type, qpt );
		Writer_OptSwizzle( Vec4Type, Vec3Type, rgb );
		Writer_OptSwizzle( Vec4Type, Vec3Type, rga );
		Writer_OptSwizzle( Vec4Type, Vec3Type, rbg );
		Writer_OptSwizzle( Vec4Type, Vec3Type, rba );
		Writer_OptSwizzle( Vec4Type, Vec3Type, rag );
		Writer_OptSwizzle( Vec4Type, Vec3Type, rab );
		Writer_OptSwizzle( Vec4Type, Vec3Type, grb );
		Writer_OptSwizzle( Vec4Type, Vec3Type, gra );
		Writer_OptSwizzle( Vec4Type, Vec3Type, gbr );
		Writer_OptSwizzle( Vec4Type, Vec3Type, gba );
		Writer_OptSwizzle( Vec4Type, Vec3Type, gar );
		Writer_OptSwizzle( Vec4Type, Vec3Type, gab );
		Writer_OptSwizzle( Vec4Type, Vec3Type, brg );
		Writer_OptSwizzle( Vec4Type, Vec3Type, bra );
		Writer_OptSwizzle( Vec4Type, Vec3Type, bgr );
		Writer_OptSwizzle( Vec4Type, Vec3Type, bga );
		Writer_OptSwizzle( Vec4Type, Vec3Type, bar );
		Writer_OptSwizzle( Vec4Type, Vec3Type, bag );
		Writer_OptSwizzle( Vec4Type, Vec3Type, arg );
		Writer_OptSwizzle( Vec4Type, Vec3Type, arb );
		Writer_OptSwizzle( Vec4Type, Vec3Type, agr );
		Writer_OptSwizzle( Vec4Type, Vec3Type, agb );
		Writer_OptSwizzle( Vec4Type, Vec3Type, abr );
		Writer_LastOptSwizzle( Vec4Type, Vec3Type, abg );
		Writer_FirstOptSwizzle( Vec4Type, Vec4Type, xyzw );
		Writer_OptSwizzle( Vec4Type, Vec4Type, xyxy );
		Writer_OptSwizzle( Vec4Type, Vec4Type, xxzz );
		Writer_OptSwizzle( Vec4Type, Vec4Type, xyww );
		Writer_OptSwizzle( Vec4Type, Vec4Type, xywz );
		Writer_OptSwizzle( Vec4Type, Vec4Type, xzyw );
		Writer_OptSwizzle( Vec4Type, Vec4Type, xzwy );
		Writer_OptSwizzle( Vec4Type, Vec4Type, xwyz );
		Writer_OptSwizzle( Vec4Type, Vec4Type, xwzy );
		Writer_OptSwizzle( Vec4Type, Vec4Type, yxzw );
		Writer_OptSwizzle( Vec4Type, Vec4Type, yxwz );
		Writer_OptSwizzle( Vec4Type, Vec4Type, yzxw );
		Writer_OptSwizzle( Vec4Type, Vec4Type, yzwx );
		Writer_OptSwizzle( Vec4Type, Vec4Type, ywxz );
		Writer_OptSwizzle( Vec4Type, Vec4Type, ywzx );
		Writer_OptSwizzle( Vec4Type, Vec4Type, zxyw );
		Writer_OptSwizzle( Vec4Type, Vec4Type, zxwy );
		Writer_OptSwizzle( Vec4Type, Vec4Type, zyxw );
		Writer_OptSwizzle( Vec4Type, Vec4Type, zywx );
		Writer_OptSwizzle( Vec4Type, Vec4Type, zwxy );
		Writer_OptSwizzle( Vec4Type, Vec4Type, zwyx );
		Writer_OptSwizzle( Vec4Type, Vec4Type, wxyz );
		Writer_OptSwizzle( Vec4Type, Vec4Type, wxzy );
		Writer_OptSwizzle( Vec4Type, Vec4Type, wyxz );
		Writer_OptSwizzle( Vec4Type, Vec4Type, wyzx );
		Writer_OptSwizzle( Vec4Type, Vec4Type, wzxy );
		Writer_OptSwizzle( Vec4Type, Vec4Type, wzyx );
		Writer_OptSwizzle( Vec4Type, Vec4Type, stpq );
		Writer_OptSwizzle( Vec4Type, Vec4Type, stqq );
		Writer_OptSwizzle( Vec4Type, Vec4Type, stqp );
		Writer_OptSwizzle( Vec4Type, Vec4Type, sptq );
		Writer_OptSwizzle( Vec4Type, Vec4Type, spqt );
		Writer_OptSwizzle( Vec4Type, Vec4Type, sqtp );
		Writer_OptSwizzle( Vec4Type, Vec4Type, sqpt );
		Writer_OptSwizzle( Vec4Type, Vec4Type, tspq );
		Writer_OptSwizzle( Vec4Type, Vec4Type, tsqp );
		Writer_OptSwizzle( Vec4Type, Vec4Type, tpsq );
		Writer_OptSwizzle( Vec4Type, Vec4Type, tpqs );
		Writer_OptSwizzle( Vec4Type, Vec4Type, tqsp );
		Writer_OptSwizzle( Vec4Type, Vec4Type, tqps );
		Writer_OptSwizzle( Vec4Type, Vec4Type, pstq );
		Writer_OptSwizzle( Vec4Type, Vec4Type, psqt );
		Writer_OptSwizzle( Vec4Type, Vec4Type, ptsq );
		Writer_OptSwizzle( Vec4Type, Vec4Type, ptqs );
		Writer_OptSwizzle( Vec4Type, Vec4Type, pqst );
		Writer_OptSwizzle( Vec4Type, Vec4Type, pqts );
		Writer_OptSwizzle( Vec4Type, Vec4Type, qstp );
		Writer_OptSwizzle( Vec4Type, Vec4Type, qspt );
		Writer_OptSwizzle( Vec4Type, Vec4Type, qtsp );
		Writer_OptSwizzle( Vec4Type, Vec4Type, qtps );
		Writer_OptSwizzle( Vec4Type, Vec4Type, qpst );
		Writer_OptSwizzle( Vec4Type, Vec4Type, qpts );
		Writer_OptSwizzle( Vec4Type, Vec4Type, rgba );
		Writer_OptSwizzle( Vec4Type, Vec4Type, rgab );
		Writer_OptSwizzle( Vec4Type, Vec4Type, rbga );
		Writer_OptSwizzle( Vec4Type, Vec4Type, rbag );
		Writer_OptSwizzle( Vec4Type, Vec4Type, ragb );
		Writer_OptSwizzle( Vec4Type, Vec4Type, rabg );
		Writer_OptSwizzle( Vec4Type, Vec4Type, grba );
		Writer_OptSwizzle( Vec4Type, Vec4Type, grab );
		Writer_OptSwizzle( Vec4Type, Vec4Type, gbra );
		Writer_OptSwizzle( Vec4Type, Vec4Type, gbar );
		Writer_OptSwizzle( Vec4Type, Vec4Type, garb );
		Writer_OptSwizzle( Vec4Type, Vec4Type, gabr );
		Writer_OptSwizzle( Vec4Type, Vec4Type, brga );
		Writer_OptSwizzle( Vec4Type, Vec4Type, brag );
		Writer_OptSwizzle( Vec4Type, Vec4Type, bgra );
		Writer_OptSwizzle( Vec4Type, Vec4Type, bgar );
		Writer_OptSwizzle( Vec4Type, Vec4Type, barg );
		Writer_OptSwizzle( Vec4Type, Vec4Type, bagr );
		Writer_OptSwizzle( Vec4Type, Vec4Type, argb );
		Writer_OptSwizzle( Vec4Type, Vec4Type, arbg );
		Writer_OptSwizzle( Vec4Type, Vec4Type, agrb );
		Writer_OptSwizzle( Vec4Type, Vec4Type, agbr );
		Writer_OptSwizzle( Vec4Type, Vec4Type, abrg );
		Writer_LastOptSwizzle( Vec4Type, Vec4Type, abgr );

	private:
		bool m_enabled;
	};

	template< typename ValueT >
	inline Vec4T< ValueT > operator+( CppTypeT< ValueT > const & lhs
		, Vec4T< ValueT > const & rhs );
	template< typename ValueT >
	inline Vec4T< ValueT > operator+( ValueT const & lhs
		, Vec4T< ValueT > const & rhs );
	template< typename ValueT >
	inline Vec4T< ValueT > operator+( Vec4T< ValueT > const & lhs
		, ValueT const & rhs );
	template< typename ValueT >
	inline Vec4T< ValueT > operator+( Vec4T< ValueT > const & lhs
		, CppTypeT< ValueT > const & rhs );
	template< typename ValueT >
	inline Vec4T< ValueT > operator+( Vec4T< ValueT > const & lhs
		, Vec4T< ValueT > const & rhs );
	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator+( Optional< ValueT > const & lhs
		, Vec4T< ValueT > const & rhs );
	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator+( Optional< Vec4T< ValueT > > const & lhs
		, CppTypeT< ValueT > const & rhs );
	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator+( Optional< Vec4T< ValueT > > const & lhs
		, ValueT const & rhs );
	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator+( Optional< Vec4T< ValueT > > const & lhs
		, Vec4T< ValueT > const & rhs );
	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator+( CppTypeT< ValueT > const & lhs
		, Optional< Vec4T< ValueT > > const & rhs );
	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator+( ValueT const & lhs
		, Optional< Vec4T< ValueT > > const & rhs );
	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator+( Vec4T< ValueT > const & lhs
		, Optional< ValueT > const & rhs );
	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator+( Vec4T< ValueT > const & lhs
		, Optional< Vec4T< ValueT > > const & rhs );
	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator+( Optional< ValueT > const & lhs
		, Optional< Vec4T< ValueT > > const & rhs );
	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator+( Optional< Vec4T< ValueT > > const & lhs
		, Optional< ValueT > const & rhs );
	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator+( Optional< Vec4T< ValueT > > const & lhs
		, Optional< Vec4T< ValueT > > const & rhs );

	template< typename ValueT >
	inline Vec4T< ValueT > operator-( CppTypeT< ValueT > const & lhs
		, Vec4T< ValueT > const & rhs );
	template< typename ValueT >
	inline Vec4T< ValueT > operator-( ValueT const & lhs
		, Vec4T< ValueT > const & rhs );
	template< typename ValueT >
	inline Vec4T< ValueT > operator-( Vec4T< ValueT > const & lhs
		, ValueT const & rhs );
	template< typename ValueT >
	inline Vec4T< ValueT > operator-( Vec4T< ValueT > const & lhs
		, CppTypeT< ValueT > const & rhs );
	template< typename ValueT >
	inline Vec4T< ValueT > operator-( Vec4T< ValueT > const & lhs
		, Vec4T< ValueT > const & rhs );
	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator-( Optional< ValueT > const & lhs
		, Vec4T< ValueT > const & rhs );
	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator-( Optional< Vec4T< ValueT > > const & lhs
		, CppTypeT< ValueT > const & rhs );
	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator-( Optional< Vec4T< ValueT > > const & lhs
		, ValueT const & rhs );
	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator-( Optional< Vec4T< ValueT > > const & lhs
		, Vec4T< ValueT > const & rhs );
	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator-( CppTypeT< ValueT > const & lhs
		, Optional< Vec4T< ValueT > > const & rhs );
	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator-( ValueT const & lhs
		, Optional< Vec4T< ValueT > > const & rhs );
	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator-( Vec4T< ValueT > const & lhs
		, Optional< ValueT > const & rhs );
	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator-( Vec4T< ValueT > const & lhs
		, Optional< Vec4T< ValueT > > const & rhs );
	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator-( Optional< ValueT > const & lhs
		, Optional< Vec4T< ValueT > > const & rhs );
	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator-( Optional< Vec4T< ValueT > > const & lhs
		, Optional< ValueT > const & rhs );
	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator-( Optional< Vec4T< ValueT > > const & lhs
		, Optional< Vec4T< ValueT > > const & rhs );

	template< typename ValueT >
	inline Vec4T< ValueT > operator*( CppTypeT< ValueT > const & lhs
		, Vec4T< ValueT > const & rhs );
	template< typename ValueT >
	inline Vec4T< ValueT > operator*( ValueT const & lhs
		, Vec4T< ValueT > const & rhs );
	template< typename ValueT >
	inline Vec4T< ValueT > operator*( Vec4T< ValueT > const & lhs
		, ValueT const & rhs );
	template< typename ValueT >
	inline Vec4T< ValueT > operator*( Vec4T< ValueT > const & lhs
		, CppTypeT< ValueT > const & rhs );
	template< typename ValueT >
	inline Vec4T< ValueT > operator*( Vec4T< ValueT > const & lhs
		, Vec4T< ValueT > const & rhs );
	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator*( Optional< ValueT > const & lhs
		, Vec4T< ValueT > const & rhs );
	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator*( Optional< Vec4T< ValueT > > const & lhs
		, CppTypeT< ValueT > const & rhs );
	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator*( Optional< Vec4T< ValueT > > const & lhs
		, ValueT const & rhs );
	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator*( Optional< Vec4T< ValueT > > const & lhs
		, Vec4T< ValueT > const & rhs );
	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator*( CppTypeT< ValueT > const & lhs
		, Optional< Vec4T< ValueT > > const & rhs );
	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator*( ValueT const & lhs
		, Optional< Vec4T< ValueT > > const & rhs );
	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator*( Vec4T< ValueT > const & lhs
		, Optional< ValueT > const & rhs );
	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator*( Vec4T< ValueT > const & lhs
		, Optional< Vec4T< ValueT > > const & rhs );
	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator*( Optional< ValueT > const & lhs
		, Optional< Vec4T< ValueT > > const & rhs );
	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator*( Optional< Vec4T< ValueT > > const & lhs
		, Optional< ValueT > const & rhs );
	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator*( Optional< Vec4T< ValueT > > const & lhs
		, Optional< Vec4T< ValueT > > const & rhs );

	template< typename ValueT >
	inline Vec4T< ValueT > operator/( Vec4T< ValueT > const & lhs
		, ValueT const & rhs );
	template< typename ValueT >
	inline Vec4T< ValueT > operator/( Vec4T< ValueT > const & lhs
		, CppTypeT< ValueT > const & rhs );
	template< typename ValueT >
	inline Vec4T< ValueT > operator/( Vec4T< ValueT > const & lhs
		, Vec4T< ValueT > const & rhs );
	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator/( Optional< Vec4T< ValueT > > const & lhs
		, CppTypeT< ValueT > const & rhs );
	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator/( Optional< Vec4T< ValueT > > const & lhs
		, ValueT const & rhs );
	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator/( Optional< Vec4T< ValueT > > const & lhs
		, Vec4T< ValueT > const & rhs );
	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator/( Vec4T< ValueT > const & lhs
		, Optional< ValueT > const & rhs );
	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator/( Vec4T< ValueT > const & lhs
		, Optional< Vec4T< ValueT > > const & rhs );
	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator/( Optional< Vec4T< ValueT > > const & lhs
		, Optional< ValueT > const & rhs );
	template< typename ValueT >
	inline Optional< Vec4T< ValueT > > operator/( Optional< Vec4T< ValueT > > const & lhs
		, Optional< Vec4T< ValueT > > const & rhs );

	template< typename ValueT >
	Bool operator==( Vec4T< ValueT > const & lhs
		, Vec4T< ValueT > const & rhs );
	template< typename ValueT >
	Bool operator!=( Vec4T< ValueT > const & lhs
		, Vec4T< ValueT > const & rhs );
	template< typename ValueT >
	Bool operator<( Vec4T< ValueT > const & lhs
		, Vec4T< ValueT > const & rhs );
	template< typename ValueT >
	Bool operator<=( Vec4T< ValueT > const & lhs
		, Vec4T< ValueT > const & rhs );
	template< typename ValueT >
	Bool operator>( Vec4T< ValueT > const & lhs
		, Vec4T< ValueT > const & rhs );
	template< typename ValueT >
	Bool operator>=( Vec4T< ValueT > const & lhs
		, Vec4T< ValueT > const & rhs );
	template< typename ValueT >
	Optional< Bool > operator==( Optional< Vec4T< ValueT > > const & lhs
		, Vec4T< ValueT > const & rhs );
	template< typename ValueT >
	Optional< Bool > operator!=( Optional< Vec4T< ValueT > > const & lhs
		, Vec4T< ValueT > const & rhs );
	template< typename ValueT >
	Optional< Bool > operator<( Optional< Vec4T< ValueT > > const & lhs
		, Vec4T< ValueT > const & rhs );
	template< typename ValueT >
	Optional< Bool > operator<=( Optional< Vec4T< ValueT > > const & lhs
		, Vec4T< ValueT > const & rhs );
	template< typename ValueT >
	Optional< Bool > operator>( Optional< Vec4T< ValueT > > const & lhs
		, Vec4T< ValueT > const & rhs );
	template< typename ValueT >
	Optional< Bool > operator>=( Optional< Vec4T< ValueT > > const & lhs
		, Vec4T< ValueT > const & rhs );
	template< typename ValueT >
	Optional< Bool > operator==( Vec4T< ValueT > const & lhs
		, Optional< Vec4T< ValueT > > const & rhs );
	template< typename ValueT >
	Optional< Bool > operator!=( Vec4T< ValueT > const & lhs
		, Optional< Vec4T< ValueT > > const & rhs );
	template< typename ValueT >
	Optional< Bool > operator<( Vec4T< ValueT > const & lhs
		, Optional< Vec4T< ValueT > > const & rhs );
	template< typename ValueT >
	Optional< Bool > operator<=( Vec4T< ValueT > const & lhs
		, Optional< Vec4T< ValueT > > const & rhs );
	template< typename ValueT >
	Optional< Bool > operator>( Vec4T< ValueT > const & lhs
		, Optional< Vec4T< ValueT > > const & rhs );
	template< typename ValueT >
	Optional< Bool > operator>=( Vec4T< ValueT > const & lhs
		, Optional< Vec4T< ValueT > > const & rhs );
	template< typename ValueT >
	Optional< Bool > operator==( Optional< Vec4T< ValueT > > const & lhs
		, Optional< Vec4T< ValueT > > const & rhs );
	template< typename ValueT >
	Optional< Bool > operator!=( Optional< Vec4T< ValueT > > const & lhs
		, Optional< Vec4T< ValueT > > const & rhs );
	template< typename ValueT >
	Optional< Bool > operator<( Optional< Vec4T< ValueT > > const & lhs
		, Optional< Vec4T< ValueT > > const & rhs );
	template< typename ValueT >
	Optional< Bool > operator<=( Optional< Vec4T< ValueT > > const & lhs
		, Optional< Vec4T< ValueT > > const & rhs );
	template< typename ValueT >
	Optional< Bool > operator>( Optional< Vec4T< ValueT > > const & lhs
		, Optional< Vec4T< ValueT > > const & rhs );
	template< typename ValueT >
	Optional< Bool > operator>=( Optional< Vec4T< ValueT > > const & lhs
		, Optional< Vec4T< ValueT > > const & rhs );
}

#include "OptionalVec4.inl"

#endif
