/*
See LICENSE file in root folder
*/
#ifndef ___SDW_Vec4_H___
#define ___SDW_Vec4_H___
#pragma once

#include "ShaderWriter/VecTypes/Vec3.hpp"

namespace sdw
{
	template< typename ValueT >
	struct Vec4T
		: public Value
	{
		SDW_DeclValue( , Vec4T );

		using ValueType = ValueT;
		using Vec2Type = Vec2T< ValueT >;
		using Vec3Type = Vec3T< ValueT >;
		using Vec4Type = Vec4T< ValueT >;

		Vec4T( ShaderWriter & writer
			, expr::ExprPtr expr
			, bool enabled );

		template< typename IndexT >
		ValueT operator[]( IndexT const & rhs )const;
		ValueT operator[]( int32_t offset )const;
		ValueT operator[]( uint32_t offset )const;
		Vec4T< ValueT > & operator+=( Vec4T< ValueT > const & rhs );
		Vec4T< ValueT > & operator-=( Vec4T< ValueT > const & rhs );
		Vec4T< ValueT > & operator*=( Vec4T< ValueT > const & rhs );
		Vec4T< ValueT > & operator/=( Vec4T< ValueT > const & rhs );
		Vec4T< ValueT > & operator+=( ValueT const & rhs );
		Vec4T< ValueT > & operator-=( ValueT const & rhs );
		Vec4T< ValueT > & operator*=( ValueT const & rhs );
		Vec4T< ValueT > & operator/=( ValueT const & rhs );
		Vec4T< ValueT > operator-()const;
		Vec4T< ValueT > operator+()const;

		static ast::type::TypePtr makeType( ast::type::TypesCache & cache );

		Writer_FirstSwizzle( Vec4Type, ValueType, x )
		Writer_Swizzle( Vec4Type, ValueType, y )
		Writer_Swizzle( Vec4Type, ValueType, z )
		Writer_Swizzle( Vec4Type, ValueType, w )
		Writer_Swizzle( Vec4Type, ValueType, s )
		Writer_Swizzle( Vec4Type, ValueType, t )
		Writer_Swizzle( Vec4Type, ValueType, p )
		Writer_Swizzle( Vec4Type, ValueType, q )
		Writer_Swizzle( Vec4Type, ValueType, r )
		Writer_Swizzle( Vec4Type, ValueType, g )
		Writer_Swizzle( Vec4Type, ValueType, b )
		Writer_LastSwizzle( Vec4Type, ValueType, a )
		Writer_FirstSwizzle( Vec4Type, Vec2Type, xy )
		Writer_Swizzle( Vec4Type, Vec2Type, xz )
		Writer_Swizzle( Vec4Type, Vec2Type, xw )
		Writer_Swizzle( Vec4Type, Vec2Type, yx )
		Writer_Swizzle( Vec4Type, Vec2Type, yz )
		Writer_Swizzle( Vec4Type, Vec2Type, yw )
		Writer_Swizzle( Vec4Type, Vec2Type, zx )
		Writer_Swizzle( Vec4Type, Vec2Type, zy )
		Writer_Swizzle( Vec4Type, Vec2Type, zw )
		Writer_Swizzle( Vec4Type, Vec2Type, wx )
		Writer_Swizzle( Vec4Type, Vec2Type, wy )
		Writer_Swizzle( Vec4Type, Vec2Type, wz )
		Writer_Swizzle( Vec2Type, Vec2Type, xx )
		Writer_Swizzle( Vec2Type, Vec2Type, yy )
		Writer_Swizzle( Vec2Type, Vec2Type, zz )
		Writer_Swizzle( Vec2Type, Vec2Type, ww )
		Writer_Swizzle( Vec4Type, Vec2Type, st )
		Writer_Swizzle( Vec4Type, Vec2Type, sp )
		Writer_Swizzle( Vec4Type, Vec2Type, sq )
		Writer_Swizzle( Vec4Type, Vec2Type, ts )
		Writer_Swizzle( Vec4Type, Vec2Type, tp )
		Writer_Swizzle( Vec4Type, Vec2Type, tq )
		Writer_Swizzle( Vec4Type, Vec2Type, ps )
		Writer_Swizzle( Vec4Type, Vec2Type, pt )
		Writer_Swizzle( Vec4Type, Vec2Type, pq )
		Writer_Swizzle( Vec4Type, Vec2Type, qs )
		Writer_Swizzle( Vec4Type, Vec2Type, qt )
		Writer_Swizzle( Vec4Type, Vec2Type, qp )
		Writer_Swizzle( Vec2Type, ValueType, ss )
		Writer_Swizzle( Vec2Type, ValueType, tt )
		Writer_Swizzle( Vec2Type, ValueType, pp )
		Writer_Swizzle( Vec2Type, ValueType, qq )
		Writer_Swizzle( Vec4Type, Vec2Type, rg )
		Writer_Swizzle( Vec4Type, Vec2Type, rb )
		Writer_Swizzle( Vec4Type, Vec2Type, ra )
		Writer_Swizzle( Vec4Type, Vec2Type, gr )
		Writer_Swizzle( Vec4Type, Vec2Type, gb )
		Writer_Swizzle( Vec4Type, Vec2Type, ga )
		Writer_Swizzle( Vec4Type, Vec2Type, br )
		Writer_Swizzle( Vec4Type, Vec2Type, bg )
		Writer_Swizzle( Vec4Type, Vec2Type, ba )
		Writer_Swizzle( Vec4Type, Vec2Type, ar )
		Writer_Swizzle( Vec4Type, Vec2Type, ag )
		Writer_Swizzle( Vec4Type, Vec2Type, ab )
		Writer_Swizzle( Vec2Type, Vec2Type, rr )
		Writer_Swizzle( Vec2Type, Vec2Type, gg )
		Writer_Swizzle( Vec2Type, Vec2Type, bb )
		Writer_LastSwizzle( Vec3Type, Vec2Type, aa )
		Writer_FirstSwizzle( Vec4Type, Vec3Type, xyz )
		Writer_Swizzle( Vec4Type, Vec3Type, xyw )
		Writer_Swizzle( Vec4Type, Vec3Type, xzy )
		Writer_Swizzle( Vec4Type, Vec3Type, xzw )
		Writer_Swizzle( Vec4Type, Vec3Type, xwy )
		Writer_Swizzle( Vec4Type, Vec3Type, xwz )
		Writer_Swizzle( Vec4Type, Vec3Type, yxz )
		Writer_Swizzle( Vec4Type, Vec3Type, yxw )
		Writer_Swizzle( Vec4Type, Vec3Type, yzx )
		Writer_Swizzle( Vec4Type, Vec3Type, yzw )
		Writer_Swizzle( Vec4Type, Vec3Type, ywx )
		Writer_Swizzle( Vec4Type, Vec3Type, ywz )
		Writer_Swizzle( Vec4Type, Vec3Type, zxy )
		Writer_Swizzle( Vec4Type, Vec3Type, zxw )
		Writer_Swizzle( Vec4Type, Vec3Type, zyx )
		Writer_Swizzle( Vec4Type, Vec3Type, zyw )
		Writer_Swizzle( Vec4Type, Vec3Type, zwx )
		Writer_Swizzle( Vec4Type, Vec3Type, zwy )
		Writer_Swizzle( Vec4Type, Vec3Type, wxy )
		Writer_Swizzle( Vec4Type, Vec3Type, wxz )
		Writer_Swizzle( Vec4Type, Vec3Type, wyx )
		Writer_Swizzle( Vec4Type, Vec3Type, wyz )
		Writer_Swizzle( Vec4Type, Vec3Type, wzx )
		Writer_Swizzle( Vec4Type, Vec3Type, wzy )
		Writer_Swizzle( Vec4Type, Vec3Type, xxx )
		Writer_Swizzle( Vec4Type, Vec3Type, yyy )
		Writer_Swizzle( Vec4Type, Vec3Type, zzz )
		Writer_Swizzle( Vec4Type, Vec3Type, www )
		Writer_Swizzle( Vec4Type, Vec3Type, stp )
		Writer_Swizzle( Vec4Type, Vec3Type, stq )
		Writer_Swizzle( Vec4Type, Vec3Type, spt )
		Writer_Swizzle( Vec4Type, Vec3Type, spq )
		Writer_Swizzle( Vec4Type, Vec3Type, sqt )
		Writer_Swizzle( Vec4Type, Vec3Type, sqp )
		Writer_Swizzle( Vec4Type, Vec3Type, tsp )
		Writer_Swizzle( Vec4Type, Vec3Type, tsq )
		Writer_Swizzle( Vec4Type, Vec3Type, tps )
		Writer_Swizzle( Vec4Type, Vec3Type, tpq )
		Writer_Swizzle( Vec4Type, Vec3Type, tqs )
		Writer_Swizzle( Vec4Type, Vec3Type, tqp )
		Writer_Swizzle( Vec4Type, Vec3Type, pst )
		Writer_Swizzle( Vec4Type, Vec3Type, psq )
		Writer_Swizzle( Vec4Type, Vec3Type, pts )
		Writer_Swizzle( Vec4Type, Vec3Type, ptq )
		Writer_Swizzle( Vec4Type, Vec3Type, pqs )
		Writer_Swizzle( Vec4Type, Vec3Type, pqt )
		Writer_Swizzle( Vec4Type, Vec3Type, qst )
		Writer_Swizzle( Vec4Type, Vec3Type, qsp )
		Writer_Swizzle( Vec4Type, Vec3Type, qts )
		Writer_Swizzle( Vec4Type, Vec3Type, qtp )
		Writer_Swizzle( Vec4Type, Vec3Type, qps )
		Writer_Swizzle( Vec4Type, Vec3Type, qpt )
		Writer_Swizzle( Vec4Type, Vec3Type, rgb )
		Writer_Swizzle( Vec4Type, Vec3Type, rga )
		Writer_Swizzle( Vec4Type, Vec3Type, rbg )
		Writer_Swizzle( Vec4Type, Vec3Type, rba )
		Writer_Swizzle( Vec4Type, Vec3Type, rag )
		Writer_Swizzle( Vec4Type, Vec3Type, rab )
		Writer_Swizzle( Vec4Type, Vec3Type, grb )
		Writer_Swizzle( Vec4Type, Vec3Type, gra )
		Writer_Swizzle( Vec4Type, Vec3Type, gbr )
		Writer_Swizzle( Vec4Type, Vec3Type, gba )
		Writer_Swizzle( Vec4Type, Vec3Type, gar )
		Writer_Swizzle( Vec4Type, Vec3Type, gab )
		Writer_Swizzle( Vec4Type, Vec3Type, brg )
		Writer_Swizzle( Vec4Type, Vec3Type, bra )
		Writer_Swizzle( Vec4Type, Vec3Type, bgr )
		Writer_Swizzle( Vec4Type, Vec3Type, bga )
		Writer_Swizzle( Vec4Type, Vec3Type, bar )
		Writer_Swizzle( Vec4Type, Vec3Type, bag )
		Writer_Swizzle( Vec4Type, Vec3Type, arg )
		Writer_Swizzle( Vec4Type, Vec3Type, arb )
		Writer_Swizzle( Vec4Type, Vec3Type, agr )
		Writer_Swizzle( Vec4Type, Vec3Type, agb )
		Writer_Swizzle( Vec4Type, Vec3Type, abr )
		Writer_LastSwizzle( Vec4Type, Vec3Type, abg )
		Writer_FirstSwizzle( Vec4Type, Vec4Type, xyzw )
		Writer_Swizzle( Vec4Type, Vec4Type, xyxy )
		Writer_Swizzle( Vec4Type, Vec4Type, xxyy )
		Writer_Swizzle( Vec4Type, Vec4Type, xxzz )
		Writer_Swizzle( Vec4Type, Vec4Type, xyww )
		Writer_Swizzle( Vec4Type, Vec4Type, xywz )
		Writer_Swizzle( Vec4Type, Vec4Type, xzyw )
		Writer_Swizzle( Vec4Type, Vec4Type, xzwy )
		Writer_Swizzle( Vec4Type, Vec4Type, xwyz )
		Writer_Swizzle( Vec4Type, Vec4Type, xwzy )
		Writer_Swizzle( Vec4Type, Vec4Type, yxzw )
		Writer_Swizzle( Vec4Type, Vec4Type, yxwz )
		Writer_Swizzle( Vec4Type, Vec4Type, yzxw )
		Writer_Swizzle( Vec4Type, Vec4Type, yzwx )
		Writer_Swizzle( Vec4Type, Vec4Type, ywxz )
		Writer_Swizzle( Vec4Type, Vec4Type, ywzx )
		Writer_Swizzle( Vec4Type, Vec4Type, zxyw )
		Writer_Swizzle( Vec4Type, Vec4Type, zxwy )
		Writer_Swizzle( Vec4Type, Vec4Type, zyxw )
		Writer_Swizzle( Vec4Type, Vec4Type, zywx )
		Writer_Swizzle( Vec4Type, Vec4Type, zwxy )
		Writer_Swizzle( Vec4Type, Vec4Type, zwyx )
		Writer_Swizzle( Vec4Type, Vec4Type, wxyz )
		Writer_Swizzle( Vec4Type, Vec4Type, wxzy )
		Writer_Swizzle( Vec4Type, Vec4Type, wyxz )
		Writer_Swizzle( Vec4Type, Vec4Type, wyzx )
		Writer_Swizzle( Vec4Type, Vec4Type, wzxy )
		Writer_Swizzle( Vec4Type, Vec4Type, wzyx )
		Writer_Swizzle( Vec4Type, Vec4Type, stpq )
		Writer_Swizzle( Vec4Type, Vec4Type, stqq )
		Writer_Swizzle( Vec4Type, Vec4Type, stqp )
		Writer_Swizzle( Vec4Type, Vec4Type, sptq )
		Writer_Swizzle( Vec4Type, Vec4Type, spqt )
		Writer_Swizzle( Vec4Type, Vec4Type, sqtp )
		Writer_Swizzle( Vec4Type, Vec4Type, sqpt )
		Writer_Swizzle( Vec4Type, Vec4Type, tspq )
		Writer_Swizzle( Vec4Type, Vec4Type, tsqp )
		Writer_Swizzle( Vec4Type, Vec4Type, tpsq )
		Writer_Swizzle( Vec4Type, Vec4Type, tpqs )
		Writer_Swizzle( Vec4Type, Vec4Type, tqsp )
		Writer_Swizzle( Vec4Type, Vec4Type, tqps )
		Writer_Swizzle( Vec4Type, Vec4Type, pstq )
		Writer_Swizzle( Vec4Type, Vec4Type, psqt )
		Writer_Swizzle( Vec4Type, Vec4Type, ptsq )
		Writer_Swizzle( Vec4Type, Vec4Type, ptqs )
		Writer_Swizzle( Vec4Type, Vec4Type, pqst )
		Writer_Swizzle( Vec4Type, Vec4Type, pqts )
		Writer_Swizzle( Vec4Type, Vec4Type, qstp )
		Writer_Swizzle( Vec4Type, Vec4Type, qspt )
		Writer_Swizzle( Vec4Type, Vec4Type, qtsp )
		Writer_Swizzle( Vec4Type, Vec4Type, qtps )
		Writer_Swizzle( Vec4Type, Vec4Type, qpst )
		Writer_Swizzle( Vec4Type, Vec4Type, qpts )
		Writer_Swizzle( Vec4Type, Vec4Type, rgba )
		Writer_Swizzle( Vec4Type, Vec4Type, rgab )
		Writer_Swizzle( Vec4Type, Vec4Type, rbga )
		Writer_Swizzle( Vec4Type, Vec4Type, rbag )
		Writer_Swizzle( Vec4Type, Vec4Type, ragb )
		Writer_Swizzle( Vec4Type, Vec4Type, rabg )
		Writer_Swizzle( Vec4Type, Vec4Type, grba )
		Writer_Swizzle( Vec4Type, Vec4Type, grab )
		Writer_Swizzle( Vec4Type, Vec4Type, gbra )
		Writer_Swizzle( Vec4Type, Vec4Type, gbar )
		Writer_Swizzle( Vec4Type, Vec4Type, garb )
		Writer_Swizzle( Vec4Type, Vec4Type, gabr )
		Writer_Swizzle( Vec4Type, Vec4Type, brga )
		Writer_Swizzle( Vec4Type, Vec4Type, brag )
		Writer_Swizzle( Vec4Type, Vec4Type, bgra )
		Writer_Swizzle( Vec4Type, Vec4Type, bgar )
		Writer_Swizzle( Vec4Type, Vec4Type, barg )
		Writer_Swizzle( Vec4Type, Vec4Type, bagr )
		Writer_Swizzle( Vec4Type, Vec4Type, argb )
		Writer_Swizzle( Vec4Type, Vec4Type, arbg )
		Writer_Swizzle( Vec4Type, Vec4Type, agrb )
		Writer_Swizzle( Vec4Type, Vec4Type, agbr )
		Writer_Swizzle( Vec4Type, Vec4Type, abrg )
		Writer_LastSwizzle( Vec4Type, Vec4Type, abgr )
	};

	template< typename ValueT >
	Vec4T< Boolean > operator==( Vec4T< ValueT > const & lhs
		, Vec4T< ValueT > const & rhs );
	template< typename ValueT >
	Vec4T< Boolean > operator!=( Vec4T< ValueT > const & lhs
		, Vec4T< ValueT > const & rhs );
	template< typename ValueT >
	Vec4T< Boolean > operator<( Vec4T< ValueT > const & lhs
		, Vec4T< ValueT > const & rhs );
	template< typename ValueT >
	Vec4T< Boolean > operator<=( Vec4T< ValueT > const & lhs
		, Vec4T< ValueT > const & rhs );
	template< typename ValueT >
	Vec4T< Boolean > operator>( Vec4T< ValueT > const & lhs
		, Vec4T< ValueT > const & rhs );
	template< typename ValueT >
	Vec4T< Boolean > operator>=( Vec4T< ValueT > const & lhs
		, Vec4T< ValueT > const & rhs );

	template< typename ValueT, VecCompatibleT< ValueT > LhsT >
	inline Vec4T< ValueT > operator+( LhsT const & lhs
		, Vec4T< ValueT > const & rhs );
	template< typename ValueT, VecCompatibleT< ValueT > RhsT >
	inline Vec4T< ValueT > operator+( Vec4T< ValueT > const & lhs
		, RhsT const & rhs );
	template< typename ValueT >
	inline Vec4T< ValueT > operator+( Vec4T< ValueT > const & lhs
		, Vec4T< ValueT > const & rhs );

	template< typename ValueT, VecCompatibleT< ValueT > LhsT >
	inline Vec4T< ValueT > operator-( LhsT const & lhs
		, Vec4T< ValueT > const & rhs );
	template< typename ValueT, VecCompatibleT< ValueT > RhsT >
	inline Vec4T< ValueT > operator-( Vec4T< ValueT > const & lhs
		, RhsT const & rhs );
	template< typename ValueT >
	inline Vec4T< ValueT > operator-( Vec4T< ValueT > const & lhs
		, Vec4T< ValueT > const & rhs );

	template< typename ValueT, VecCompatibleT< ValueT > LhsT >
	inline Vec4T< ValueT > operator*( LhsT const & lhs
		, Vec4T< ValueT > const & rhs );
	template< typename ValueT, VecCompatibleT< ValueT > RhsT >
	inline Vec4T< ValueT > operator*( Vec4T< ValueT > const & lhs
		, RhsT const & rhs );
	template< typename ValueT >
	inline Vec4T< ValueT > operator*( Vec4T< ValueT > const & lhs
		, Vec4T< ValueT > const & rhs );

	template< typename ValueT, VecCompatibleT< ValueT > RhsT >
	inline Vec4T< ValueT > operator/( Vec4T< ValueT > const & lhs
		, RhsT const & rhs );
	template< typename ValueT >
	inline Vec4T< ValueT > operator/( Vec4T< ValueT > const & lhs
		, Vec4T< ValueT > const & rhs );
}

#include "Vec4.inl"

#endif
