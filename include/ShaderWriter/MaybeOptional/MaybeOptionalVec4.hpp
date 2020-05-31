/*
See LICENSE file in root folder
*/
#ifndef ___SDW_MaybeOptionalVec4_H___
#define ___SDW_MaybeOptionalVec4_H___
#pragma once

#include "MaybeOptional.hpp"
#include "ShaderWriter/Optional/OptionalVec4.hpp"

namespace sdw
{
	template< typename ValueT >
	struct MaybeOptional< Vec4T< ValueT > >
		: public Vec4T< ValueT >
	{
		using MyValue = Vec4T< ValueT >;

		using ValueType = MaybeOptional< ValueT >;
		using Vec2Type = MaybeOptional< Vec2T< ValueT > >;
		using Vec3Type = MaybeOptional< Vec3T< ValueT > >;
		using Vec4Type = MaybeOptional< Vec4T< ValueT > >;

		inline MaybeOptional( Shader * shader
			, expr::ExprPtr expr );
		inline MaybeOptional( Shader * shader
			, expr::ExprPtr expr
			, bool enabled );
		inline MaybeOptional( MyValue const & rhs );
		inline MaybeOptional( Optional< MyValue > const & rhs );
		inline MaybeOptional( MaybeOptional< MyValue > const & rhs );

		inline MaybeOptional< MyValue > & operator=( MyValue const & rhs );
		inline MaybeOptional< MyValue > & operator=( Optional< MyValue > const & rhs );
		inline MaybeOptional< MyValue > & operator=( MaybeOptional< MyValue > const & rhs );

		template< typename IndexT >
		inline MaybeOptional< ValueT > operator[]( IndexT const & rhs )const;

		inline operator MyValue()const;
		inline operator Optional< MyValue >()const;

		inline bool isOptional()const;
		inline bool isEnabled()const;

		inline MaybeOptional< Vec4T< ValueT > > & operator+=( Vec4T< ValueT > const & rhs );
		inline MaybeOptional< Vec4T< ValueT > > & operator-=( Vec4T< ValueT > const & rhs );
		inline MaybeOptional< Vec4T< ValueT > > & operator*=( Vec4T< ValueT > const & rhs );
		inline MaybeOptional< Vec4T< ValueT > > & operator/=( Vec4T< ValueT > const & rhs );
		inline MaybeOptional< Vec4T< ValueT > > & operator+=( MaybeOptional< Vec4T< ValueT > > const & rhs );
		inline MaybeOptional< Vec4T< ValueT > > & operator-=( MaybeOptional< Vec4T< ValueT > > const & rhs );
		inline MaybeOptional< Vec4T< ValueT > > & operator*=( MaybeOptional< Vec4T< ValueT > > const & rhs );
		inline MaybeOptional< Vec4T< ValueT > > & operator/=( MaybeOptional< Vec4T< ValueT > > const & rhs );
		inline MaybeOptional< Vec4T< ValueT > > & operator+=( ValueT const & rhs );
		inline MaybeOptional< Vec4T< ValueT > > & operator-=( ValueT const & rhs );
		inline MaybeOptional< Vec4T< ValueT > > & operator*=( ValueT const & rhs );
		inline MaybeOptional< Vec4T< ValueT > > & operator/=( ValueT const & rhs );
		inline MaybeOptional< Vec4T< ValueT > > & operator+=( MaybeOptional< ValueT > const & rhs );
		inline MaybeOptional< Vec4T< ValueT > > & operator-=( MaybeOptional< ValueT > const & rhs );
		inline MaybeOptional< Vec4T< ValueT > > & operator*=( MaybeOptional< ValueT > const & rhs );
		inline MaybeOptional< Vec4T< ValueT > > & operator/=( MaybeOptional< ValueT > const & rhs );
		inline MaybeOptional< Vec4T< ValueT > > operator-()const;
		inline MaybeOptional< Vec4T< ValueT > > operator+()const;

		Writer_FirstMayOptSwizzle( Vec4Type, ValueType, x );
		Writer_MayOptSwizzle( Vec4Type, ValueType, y );
		Writer_MayOptSwizzle( Vec4Type, ValueType, z );
		Writer_MayOptSwizzle( Vec4Type, ValueType, w );
		Writer_MayOptSwizzle( Vec4Type, ValueType, s );
		Writer_MayOptSwizzle( Vec4Type, ValueType, t );
		Writer_MayOptSwizzle( Vec4Type, ValueType, p );
		Writer_MayOptSwizzle( Vec4Type, ValueType, q );
		Writer_MayOptSwizzle( Vec4Type, ValueType, r );
		Writer_MayOptSwizzle( Vec4Type, ValueType, g );
		Writer_MayOptSwizzle( Vec4Type, ValueType, b );
		Writer_LastMayOptSwizzle( Vec4Type, ValueType, a );
		Writer_FirstMayOptSwizzle( Vec4Type, Vec2Type, xy );
		Writer_MayOptSwizzle( Vec4Type, Vec2Type, xz );
		Writer_MayOptSwizzle( Vec4Type, Vec2Type, xw );
		Writer_MayOptSwizzle( Vec4Type, Vec2Type, yx );
		Writer_MayOptSwizzle( Vec4Type, Vec2Type, yz );
		Writer_MayOptSwizzle( Vec4Type, Vec2Type, yw );
		Writer_MayOptSwizzle( Vec4Type, Vec2Type, zx );
		Writer_MayOptSwizzle( Vec4Type, Vec2Type, zy );
		Writer_MayOptSwizzle( Vec4Type, Vec2Type, zw );
		Writer_MayOptSwizzle( Vec4Type, Vec2Type, wx );
		Writer_MayOptSwizzle( Vec4Type, Vec2Type, wy );
		Writer_MayOptSwizzle( Vec4Type, Vec2Type, wz );
		Writer_MayOptSwizzle( Vec2Type, Vec2Type, xx );
		Writer_MayOptSwizzle( Vec2Type, Vec2Type, yy );
		Writer_MayOptSwizzle( Vec2Type, Vec2Type, zz );
		Writer_MayOptSwizzle( Vec2Type, Vec2Type, ww );
		Writer_MayOptSwizzle( Vec4Type, Vec2Type, st );
		Writer_MayOptSwizzle( Vec4Type, Vec2Type, sp );
		Writer_MayOptSwizzle( Vec4Type, Vec2Type, sq );
		Writer_MayOptSwizzle( Vec4Type, Vec2Type, ts );
		Writer_MayOptSwizzle( Vec4Type, Vec2Type, tp );
		Writer_MayOptSwizzle( Vec4Type, Vec2Type, tq );
		Writer_MayOptSwizzle( Vec4Type, Vec2Type, ps );
		Writer_MayOptSwizzle( Vec4Type, Vec2Type, pt );
		Writer_MayOptSwizzle( Vec4Type, Vec2Type, pq );
		Writer_MayOptSwizzle( Vec4Type, Vec2Type, qs );
		Writer_MayOptSwizzle( Vec4Type, Vec2Type, qt );
		Writer_MayOptSwizzle( Vec4Type, Vec2Type, qp );
		Writer_MayOptSwizzle( Vec2Type, ValueType, ss );
		Writer_MayOptSwizzle( Vec2Type, ValueType, tt );
		Writer_MayOptSwizzle( Vec2Type, ValueType, pp );
		Writer_MayOptSwizzle( Vec2Type, ValueType, qq );
		Writer_MayOptSwizzle( Vec4Type, Vec2Type, rg );
		Writer_MayOptSwizzle( Vec4Type, Vec2Type, rb );
		Writer_MayOptSwizzle( Vec4Type, Vec2Type, ra );
		Writer_MayOptSwizzle( Vec4Type, Vec2Type, gr );
		Writer_MayOptSwizzle( Vec4Type, Vec2Type, gb );
		Writer_MayOptSwizzle( Vec4Type, Vec2Type, ga );
		Writer_MayOptSwizzle( Vec4Type, Vec2Type, br );
		Writer_MayOptSwizzle( Vec4Type, Vec2Type, bg );
		Writer_MayOptSwizzle( Vec4Type, Vec2Type, ba );
		Writer_MayOptSwizzle( Vec4Type, Vec2Type, ar );
		Writer_MayOptSwizzle( Vec4Type, Vec2Type, ag );
		Writer_MayOptSwizzle( Vec4Type, Vec2Type, ab );
		Writer_MayOptSwizzle( Vec2Type, Vec2Type, rr );
		Writer_MayOptSwizzle( Vec2Type, Vec2Type, gg );
		Writer_MayOptSwizzle( Vec2Type, Vec2Type, bb );
		Writer_LastMayOptSwizzle( Vec3Type, Vec2Type, aa );
		Writer_FirstMayOptSwizzle( Vec4Type, Vec3Type, xyz );
		Writer_MayOptSwizzle( Vec4Type, Vec3Type, xyw );
		Writer_MayOptSwizzle( Vec4Type, Vec3Type, xzy );
		Writer_MayOptSwizzle( Vec4Type, Vec3Type, xzw );
		Writer_MayOptSwizzle( Vec4Type, Vec3Type, xwy );
		Writer_MayOptSwizzle( Vec4Type, Vec3Type, xwz );
		Writer_MayOptSwizzle( Vec4Type, Vec3Type, yxz );
		Writer_MayOptSwizzle( Vec4Type, Vec3Type, yxw );
		Writer_MayOptSwizzle( Vec4Type, Vec3Type, yzx );
		Writer_MayOptSwizzle( Vec4Type, Vec3Type, yzw );
		Writer_MayOptSwizzle( Vec4Type, Vec3Type, ywx );
		Writer_MayOptSwizzle( Vec4Type, Vec3Type, ywz );
		Writer_MayOptSwizzle( Vec4Type, Vec3Type, zxy );
		Writer_MayOptSwizzle( Vec4Type, Vec3Type, zxw );
		Writer_MayOptSwizzle( Vec4Type, Vec3Type, zyx );
		Writer_MayOptSwizzle( Vec4Type, Vec3Type, zyw );
		Writer_MayOptSwizzle( Vec4Type, Vec3Type, zwx );
		Writer_MayOptSwizzle( Vec4Type, Vec3Type, zwy );
		Writer_MayOptSwizzle( Vec4Type, Vec3Type, wxy );
		Writer_MayOptSwizzle( Vec4Type, Vec3Type, wxz );
		Writer_MayOptSwizzle( Vec4Type, Vec3Type, wyx );
		Writer_MayOptSwizzle( Vec4Type, Vec3Type, wyz );
		Writer_MayOptSwizzle( Vec4Type, Vec3Type, wzx );
		Writer_MayOptSwizzle( Vec4Type, Vec3Type, wzy );
		Writer_MayOptSwizzle( Vec4Type, Vec3Type, xxx );
		Writer_MayOptSwizzle( Vec4Type, Vec3Type, yyy );
		Writer_MayOptSwizzle( Vec4Type, Vec3Type, zzz );
		Writer_MayOptSwizzle( Vec4Type, Vec3Type, www );
		Writer_MayOptSwizzle( Vec4Type, Vec3Type, stp );
		Writer_MayOptSwizzle( Vec4Type, Vec3Type, stq );
		Writer_MayOptSwizzle( Vec4Type, Vec3Type, spt );
		Writer_MayOptSwizzle( Vec4Type, Vec3Type, spq );
		Writer_MayOptSwizzle( Vec4Type, Vec3Type, sqt );
		Writer_MayOptSwizzle( Vec4Type, Vec3Type, sqp );
		Writer_MayOptSwizzle( Vec4Type, Vec3Type, tsp );
		Writer_MayOptSwizzle( Vec4Type, Vec3Type, tsq );
		Writer_MayOptSwizzle( Vec4Type, Vec3Type, tps );
		Writer_MayOptSwizzle( Vec4Type, Vec3Type, tpq );
		Writer_MayOptSwizzle( Vec4Type, Vec3Type, tqs );
		Writer_MayOptSwizzle( Vec4Type, Vec3Type, tqp );
		Writer_MayOptSwizzle( Vec4Type, Vec3Type, pst );
		Writer_MayOptSwizzle( Vec4Type, Vec3Type, psq );
		Writer_MayOptSwizzle( Vec4Type, Vec3Type, pts );
		Writer_MayOptSwizzle( Vec4Type, Vec3Type, ptq );
		Writer_MayOptSwizzle( Vec4Type, Vec3Type, pqs );
		Writer_MayOptSwizzle( Vec4Type, Vec3Type, pqt );
		Writer_MayOptSwizzle( Vec4Type, Vec3Type, qst );
		Writer_MayOptSwizzle( Vec4Type, Vec3Type, qsp );
		Writer_MayOptSwizzle( Vec4Type, Vec3Type, qts );
		Writer_MayOptSwizzle( Vec4Type, Vec3Type, qtp );
		Writer_MayOptSwizzle( Vec4Type, Vec3Type, qps );
		Writer_MayOptSwizzle( Vec4Type, Vec3Type, qpt );
		Writer_MayOptSwizzle( Vec4Type, Vec3Type, rgb );
		Writer_MayOptSwizzle( Vec4Type, Vec3Type, rga );
		Writer_MayOptSwizzle( Vec4Type, Vec3Type, rbg );
		Writer_MayOptSwizzle( Vec4Type, Vec3Type, rba );
		Writer_MayOptSwizzle( Vec4Type, Vec3Type, rag );
		Writer_MayOptSwizzle( Vec4Type, Vec3Type, rab );
		Writer_MayOptSwizzle( Vec4Type, Vec3Type, grb );
		Writer_MayOptSwizzle( Vec4Type, Vec3Type, gra );
		Writer_MayOptSwizzle( Vec4Type, Vec3Type, gbr );
		Writer_MayOptSwizzle( Vec4Type, Vec3Type, gba );
		Writer_MayOptSwizzle( Vec4Type, Vec3Type, gar );
		Writer_MayOptSwizzle( Vec4Type, Vec3Type, gab );
		Writer_MayOptSwizzle( Vec4Type, Vec3Type, brg );
		Writer_MayOptSwizzle( Vec4Type, Vec3Type, bra );
		Writer_MayOptSwizzle( Vec4Type, Vec3Type, bgr );
		Writer_MayOptSwizzle( Vec4Type, Vec3Type, bga );
		Writer_MayOptSwizzle( Vec4Type, Vec3Type, bar );
		Writer_MayOptSwizzle( Vec4Type, Vec3Type, bag );
		Writer_MayOptSwizzle( Vec4Type, Vec3Type, arg );
		Writer_MayOptSwizzle( Vec4Type, Vec3Type, arb );
		Writer_MayOptSwizzle( Vec4Type, Vec3Type, agr );
		Writer_MayOptSwizzle( Vec4Type, Vec3Type, agb );
		Writer_MayOptSwizzle( Vec4Type, Vec3Type, abr );
		Writer_LastMayOptSwizzle( Vec4Type, Vec3Type, abg );
		Writer_FirstMayOptSwizzle( Vec4Type, Vec4Type, xyzw );
		Writer_MayOptSwizzle( Vec4Type, Vec4Type, xyxy );
		Writer_MayOptSwizzle( Vec4Type, Vec4Type, xxzz );
		Writer_MayOptSwizzle( Vec4Type, Vec4Type, xyww );
		Writer_MayOptSwizzle( Vec4Type, Vec4Type, xywz );
		Writer_MayOptSwizzle( Vec4Type, Vec4Type, xzyw );
		Writer_MayOptSwizzle( Vec4Type, Vec4Type, xzwy );
		Writer_MayOptSwizzle( Vec4Type, Vec4Type, xwyz );
		Writer_MayOptSwizzle( Vec4Type, Vec4Type, xwzy );
		Writer_MayOptSwizzle( Vec4Type, Vec4Type, yxzw );
		Writer_MayOptSwizzle( Vec4Type, Vec4Type, yxwz );
		Writer_MayOptSwizzle( Vec4Type, Vec4Type, yzxw );
		Writer_MayOptSwizzle( Vec4Type, Vec4Type, yzwx );
		Writer_MayOptSwizzle( Vec4Type, Vec4Type, ywxz );
		Writer_MayOptSwizzle( Vec4Type, Vec4Type, ywzx );
		Writer_MayOptSwizzle( Vec4Type, Vec4Type, zxyw );
		Writer_MayOptSwizzle( Vec4Type, Vec4Type, zxwy );
		Writer_MayOptSwizzle( Vec4Type, Vec4Type, zyxw );
		Writer_MayOptSwizzle( Vec4Type, Vec4Type, zywx );
		Writer_MayOptSwizzle( Vec4Type, Vec4Type, zwxy );
		Writer_MayOptSwizzle( Vec4Type, Vec4Type, zwyx );
		Writer_MayOptSwizzle( Vec4Type, Vec4Type, wxyz );
		Writer_MayOptSwizzle( Vec4Type, Vec4Type, wxzy );
		Writer_MayOptSwizzle( Vec4Type, Vec4Type, wyxz );
		Writer_MayOptSwizzle( Vec4Type, Vec4Type, wyzx );
		Writer_MayOptSwizzle( Vec4Type, Vec4Type, wzxy );
		Writer_MayOptSwizzle( Vec4Type, Vec4Type, wzyx );
		Writer_MayOptSwizzle( Vec4Type, Vec4Type, stpq );
		Writer_MayOptSwizzle( Vec4Type, Vec4Type, stqq );
		Writer_MayOptSwizzle( Vec4Type, Vec4Type, stqp );
		Writer_MayOptSwizzle( Vec4Type, Vec4Type, sptq );
		Writer_MayOptSwizzle( Vec4Type, Vec4Type, spqt );
		Writer_MayOptSwizzle( Vec4Type, Vec4Type, sqtp );
		Writer_MayOptSwizzle( Vec4Type, Vec4Type, sqpt );
		Writer_MayOptSwizzle( Vec4Type, Vec4Type, tspq );
		Writer_MayOptSwizzle( Vec4Type, Vec4Type, tsqp );
		Writer_MayOptSwizzle( Vec4Type, Vec4Type, tpsq );
		Writer_MayOptSwizzle( Vec4Type, Vec4Type, tpqs );
		Writer_MayOptSwizzle( Vec4Type, Vec4Type, tqsp );
		Writer_MayOptSwizzle( Vec4Type, Vec4Type, tqps );
		Writer_MayOptSwizzle( Vec4Type, Vec4Type, pstq );
		Writer_MayOptSwizzle( Vec4Type, Vec4Type, psqt );
		Writer_MayOptSwizzle( Vec4Type, Vec4Type, ptsq );
		Writer_MayOptSwizzle( Vec4Type, Vec4Type, ptqs );
		Writer_MayOptSwizzle( Vec4Type, Vec4Type, pqst );
		Writer_MayOptSwizzle( Vec4Type, Vec4Type, pqts );
		Writer_MayOptSwizzle( Vec4Type, Vec4Type, qstp );
		Writer_MayOptSwizzle( Vec4Type, Vec4Type, qspt );
		Writer_MayOptSwizzle( Vec4Type, Vec4Type, qtsp );
		Writer_MayOptSwizzle( Vec4Type, Vec4Type, qtps );
		Writer_MayOptSwizzle( Vec4Type, Vec4Type, qpst );
		Writer_MayOptSwizzle( Vec4Type, Vec4Type, qpts );
		Writer_MayOptSwizzle( Vec4Type, Vec4Type, rgba );
		Writer_MayOptSwizzle( Vec4Type, Vec4Type, rgab );
		Writer_MayOptSwizzle( Vec4Type, Vec4Type, rbga );
		Writer_MayOptSwizzle( Vec4Type, Vec4Type, rbag );
		Writer_MayOptSwizzle( Vec4Type, Vec4Type, ragb );
		Writer_MayOptSwizzle( Vec4Type, Vec4Type, rabg );
		Writer_MayOptSwizzle( Vec4Type, Vec4Type, grba );
		Writer_MayOptSwizzle( Vec4Type, Vec4Type, grab );
		Writer_MayOptSwizzle( Vec4Type, Vec4Type, gbra );
		Writer_MayOptSwizzle( Vec4Type, Vec4Type, gbar );
		Writer_MayOptSwizzle( Vec4Type, Vec4Type, garb );
		Writer_MayOptSwizzle( Vec4Type, Vec4Type, gabr );
		Writer_MayOptSwizzle( Vec4Type, Vec4Type, brga );
		Writer_MayOptSwizzle( Vec4Type, Vec4Type, brag );
		Writer_MayOptSwizzle( Vec4Type, Vec4Type, bgra );
		Writer_MayOptSwizzle( Vec4Type, Vec4Type, bgar );
		Writer_MayOptSwizzle( Vec4Type, Vec4Type, barg );
		Writer_MayOptSwizzle( Vec4Type, Vec4Type, bagr );
		Writer_MayOptSwizzle( Vec4Type, Vec4Type, argb );
		Writer_MayOptSwizzle( Vec4Type, Vec4Type, arbg );
		Writer_MayOptSwizzle( Vec4Type, Vec4Type, agrb );
		Writer_MayOptSwizzle( Vec4Type, Vec4Type, agbr );
		Writer_MayOptSwizzle( Vec4Type, Vec4Type, abrg );
		Writer_LastMayOptSwizzle( Vec4Type, Vec4Type, abgr );

	private:
		bool m_optional;
		bool m_enabled;
	};

	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > > operator+( MaybeOptional< ValueT > const & lhs
		, Vec4T< ValueT > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > > operator+( MaybeOptional< Vec4T< ValueT > > const & lhs
		, CppTypeT< ValueT > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > > operator+( MaybeOptional< Vec4T< ValueT > > const & lhs
		, ValueT const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > > operator+( MaybeOptional< Vec4T< ValueT > > const & lhs
		, Vec4T< ValueT > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > > operator+( CppTypeT< ValueT > const & lhs
		, MaybeOptional< Vec4T< ValueT > > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > > operator+( ValueT const & lhs
		, MaybeOptional< Vec4T< ValueT > > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > > operator+( Vec4T< ValueT > const & lhs
		, MaybeOptional< ValueT > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > > operator+( Vec4T< ValueT > const & lhs
		, MaybeOptional< Vec4T< ValueT > > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > > operator+( MaybeOptional< ValueT > const & lhs
		, MaybeOptional< Vec4T< ValueT > > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > > operator+( MaybeOptional< Vec4T< ValueT > > const & lhs
		, MaybeOptional< ValueT > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > > operator+( MaybeOptional< Vec4T< ValueT > > const & lhs
		, MaybeOptional< Vec4T< ValueT > > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > > operator-( MaybeOptional< ValueT > const & lhs
		, Vec4T< ValueT > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > > operator-( MaybeOptional< Vec4T< ValueT > > const & lhs
		, CppTypeT< ValueT > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > > operator-( MaybeOptional< Vec4T< ValueT > > const & lhs
		, ValueT const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > > operator-( MaybeOptional< Vec4T< ValueT > > const & lhs
		, Vec4T< ValueT > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > > operator-( CppTypeT< ValueT > const & lhs
		, MaybeOptional< Vec4T< ValueT > > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > > operator-( ValueT const & lhs
		, MaybeOptional< Vec4T< ValueT > > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > > operator-( Vec4T< ValueT > const & lhs
		, MaybeOptional< ValueT > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > > operator-( Vec4T< ValueT > const & lhs
		, MaybeOptional< Vec4T< ValueT > > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > > operator-( MaybeOptional< ValueT > const & lhs
		, MaybeOptional< Vec4T< ValueT > > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > > operator-( MaybeOptional< Vec4T< ValueT > > const & lhs
		, MaybeOptional< ValueT > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > > operator-( MaybeOptional< Vec4T< ValueT > > const & lhs
		, MaybeOptional< Vec4T< ValueT > > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > > operator*( MaybeOptional< ValueT > const & lhs
		, Vec4T< ValueT > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > > operator*( MaybeOptional< Vec4T< ValueT > > const & lhs
		, CppTypeT< ValueT > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > > operator*( MaybeOptional< Vec4T< ValueT > > const & lhs
		, ValueT const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > > operator*( MaybeOptional< Vec4T< ValueT > > const & lhs
		, Vec4T< ValueT > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > > operator*( CppTypeT< ValueT > const & lhs
		, MaybeOptional< Vec4T< ValueT > > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > > operator*( ValueT const & lhs
		, MaybeOptional< Vec4T< ValueT > > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > > operator*( Vec4T< ValueT > const & lhs
		, MaybeOptional< ValueT > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > > operator*( Vec4T< ValueT > const & lhs
		, MaybeOptional< Vec4T< ValueT > > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > > operator*( MaybeOptional< ValueT > const & lhs
		, MaybeOptional< Vec4T< ValueT > > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > > operator*( MaybeOptional< Vec4T< ValueT > > const & lhs
		, MaybeOptional< ValueT > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > > operator*( MaybeOptional< Vec4T< ValueT > > const & lhs
		, MaybeOptional< Vec4T< ValueT > > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > > operator/( MaybeOptional< Vec4T< ValueT > > const & lhs
		, CppTypeT< ValueT > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > > operator/( MaybeOptional< Vec4T< ValueT > > const & lhs
		, ValueT const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > > operator/( MaybeOptional< Vec4T< ValueT > > const & lhs
		, Vec4T< ValueT > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > > operator/( Vec4T< ValueT > const & lhs
		, MaybeOptional< ValueT > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > > operator/( Vec4T< ValueT > const & lhs
		, MaybeOptional< Vec4T< ValueT > > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > > operator/( MaybeOptional< Vec4T< ValueT > > const & lhs
		, MaybeOptional< ValueT > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec4T< ValueT > > operator/( MaybeOptional< Vec4T< ValueT > > const & lhs
		, MaybeOptional< Vec4T< ValueT > > const & rhs );
}

#include "MaybeOptionalVec4.inl"

#endif
