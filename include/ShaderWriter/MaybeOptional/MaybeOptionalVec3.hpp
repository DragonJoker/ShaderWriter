/*
See LICENSE file in root folder
*/
#ifndef ___SDW_MaybeOptionalVec3_H___
#define ___SDW_MaybeOptionalVec3_H___
#pragma once

#include "MaybeOptional.hpp"
#include "ShaderWriter/Optional/OptionalVec3.hpp"

namespace sdw
{
	template< typename ValueT >
	struct MaybeOptional< Vec3T< ValueT > >
		: public Vec3T< ValueT >
	{
		using MyValue = Vec3T< ValueT >;

		using ValueType = MaybeOptional< ValueT >;
		using Vec2Type = MaybeOptional< Vec2T< ValueT > >;
		using Vec3Type = MaybeOptional< Vec3T< ValueT > >;

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

		inline MaybeOptional< Vec3T< ValueT > > & operator+=( Vec3T< ValueT > const & rhs );
		inline MaybeOptional< Vec3T< ValueT > > & operator-=( Vec3T< ValueT > const & rhs );
		inline MaybeOptional< Vec3T< ValueT > > & operator*=( Vec3T< ValueT > const & rhs );
		inline MaybeOptional< Vec3T< ValueT > > & operator/=( Vec3T< ValueT > const & rhs );
		inline MaybeOptional< Vec3T< ValueT > > & operator+=( MaybeOptional< Vec3T< ValueT > > const & rhs );
		inline MaybeOptional< Vec3T< ValueT > > & operator-=( MaybeOptional< Vec3T< ValueT > > const & rhs );
		inline MaybeOptional< Vec3T< ValueT > > & operator*=( MaybeOptional< Vec3T< ValueT > > const & rhs );
		inline MaybeOptional< Vec3T< ValueT > > & operator/=( MaybeOptional< Vec3T< ValueT > > const & rhs );
		inline MaybeOptional< Vec3T< ValueT > > & operator+=( ValueT const & rhs );
		inline MaybeOptional< Vec3T< ValueT > > & operator-=( ValueT const & rhs );
		inline MaybeOptional< Vec3T< ValueT > > & operator*=( ValueT const & rhs );
		inline MaybeOptional< Vec3T< ValueT > > & operator/=( ValueT const & rhs );
		inline MaybeOptional< Vec3T< ValueT > > & operator+=( MaybeOptional< ValueT > const & rhs );
		inline MaybeOptional< Vec3T< ValueT > > & operator-=( MaybeOptional< ValueT > const & rhs );
		inline MaybeOptional< Vec3T< ValueT > > & operator*=( MaybeOptional< ValueT > const & rhs );
		inline MaybeOptional< Vec3T< ValueT > > & operator/=( MaybeOptional< ValueT > const & rhs );
		inline MaybeOptional< Vec3T< ValueT > > operator-()const;
		inline MaybeOptional< Vec3T< ValueT > > operator+()const;

		Writer_FirstMayOptSwizzle( Vec3Type, ValueType, x );
		Writer_MayOptSwizzle( Vec3Type, ValueType, y );
		Writer_MayOptSwizzle( Vec3Type, ValueType, z );
		Writer_MayOptSwizzle( Vec3Type, ValueType, s );
		Writer_MayOptSwizzle( Vec3Type, ValueType, t );
		Writer_MayOptSwizzle( Vec3Type, ValueType, p );
		Writer_MayOptSwizzle( Vec3Type, ValueType, r );
		Writer_MayOptSwizzle( Vec3Type, ValueType, g );
		Writer_LastMayOptSwizzle( Vec3Type, ValueType, b );
		Writer_FirstMayOptSwizzle( Vec3Type, Vec2Type, xy );
		Writer_MayOptSwizzle( Vec3Type, Vec2Type, xz );
		Writer_MayOptSwizzle( Vec3Type, Vec2Type, yx );
		Writer_MayOptSwizzle( Vec3Type, Vec2Type, yz );
		Writer_MayOptSwizzle( Vec3Type, Vec2Type, zx );
		Writer_MayOptSwizzle( Vec3Type, Vec2Type, zy );
		Writer_MayOptSwizzle( Vec2Type, Vec2Type, xx );
		Writer_MayOptSwizzle( Vec2Type, Vec2Type, yy );
		Writer_MayOptSwizzle( Vec2Type, Vec2Type, zz );
		Writer_MayOptSwizzle( Vec3Type, Vec2Type, st );
		Writer_MayOptSwizzle( Vec3Type, Vec2Type, sp );
		Writer_MayOptSwizzle( Vec3Type, Vec2Type, ts );
		Writer_MayOptSwizzle( Vec3Type, Vec2Type, tp );
		Writer_MayOptSwizzle( Vec3Type, Vec2Type, ps );
		Writer_MayOptSwizzle( Vec3Type, Vec2Type, pt );
		Writer_MayOptSwizzle( Vec2Type, ValueType, ss );
		Writer_MayOptSwizzle( Vec2Type, ValueType, tt );
		Writer_MayOptSwizzle( Vec2Type, ValueType, pp );
		Writer_MayOptSwizzle( Vec3Type, Vec2Type, rg );
		Writer_MayOptSwizzle( Vec3Type, Vec2Type, rb );
		Writer_MayOptSwizzle( Vec3Type, Vec2Type, gr );
		Writer_MayOptSwizzle( Vec3Type, Vec2Type, gb );
		Writer_MayOptSwizzle( Vec3Type, Vec2Type, br );
		Writer_MayOptSwizzle( Vec2Type, Vec2Type, bg );
		Writer_MayOptSwizzle( Vec2Type, Vec2Type, rr );
		Writer_MayOptSwizzle( Vec2Type, Vec2Type, gg );
		Writer_LastMayOptSwizzle( Vec3Type, Vec2Type, bb );
		Writer_FirstMayOptSwizzle( Vec3Type, Vec3Type, xyz );
		Writer_MayOptSwizzle( Vec3Type, Vec3Type, xzy );
		Writer_MayOptSwizzle( Vec3Type, Vec3Type, yxz );
		Writer_MayOptSwizzle( Vec3Type, Vec3Type, yzx );
		Writer_MayOptSwizzle( Vec3Type, Vec3Type, zxy );
		Writer_MayOptSwizzle( Vec3Type, Vec3Type, zyx );
		Writer_MayOptSwizzle( Vec3Type, Vec3Type, stp );
		Writer_MayOptSwizzle( Vec3Type, Vec3Type, spt );
		Writer_MayOptSwizzle( Vec3Type, Vec3Type, tsp );
		Writer_MayOptSwizzle( Vec3Type, Vec3Type, tps );
		Writer_MayOptSwizzle( Vec3Type, Vec3Type, pst );
		Writer_MayOptSwizzle( Vec3Type, Vec3Type, pts );
		Writer_MayOptSwizzle( Vec3Type, Vec3Type, rgb );
		Writer_MayOptSwizzle( Vec3Type, Vec3Type, rbg );
		Writer_MayOptSwizzle( Vec3Type, Vec3Type, grb );
		Writer_MayOptSwizzle( Vec3Type, Vec3Type, gbr );
		Writer_MayOptSwizzle( Vec3Type, Vec3Type, brg );
		Writer_LastMayOptSwizzle( Vec3Type, Vec3Type, bgr );

	private:
		bool m_optional;
		bool m_enabled;
	};

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator+( MaybeOptional< ValueT > const & lhs
		, Vec3T< ValueT > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator+( MaybeOptional< Vec3T< ValueT > > const & lhs
		, CppTypeT< ValueT > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator+( MaybeOptional< Vec3T< ValueT > > const & lhs
		, ValueT const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator+( MaybeOptional< Vec3T< ValueT > > const & lhs
		, Vec3T< ValueT > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator+( CppTypeT< ValueT > const & lhs
		, MaybeOptional< Vec3T< ValueT > > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator+( ValueT const & lhs
		, MaybeOptional< Vec3T< ValueT > > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator+( Vec3T< ValueT > const & lhs
		, MaybeOptional< ValueT > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator+( Vec3T< ValueT > const & lhs
		, MaybeOptional< Vec3T< ValueT > > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator+( MaybeOptional< ValueT > const & lhs
		, MaybeOptional< Vec3T< ValueT > > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator+( MaybeOptional< Vec3T< ValueT > > const & lhs
		, MaybeOptional< ValueT > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator+( MaybeOptional< Vec3T< ValueT > > const & lhs
		, MaybeOptional< Vec3T< ValueT > > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator-( MaybeOptional< ValueT > const & lhs
		, Vec3T< ValueT > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator-( MaybeOptional< Vec3T< ValueT > > const & lhs
		, CppTypeT< ValueT > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator-( MaybeOptional< Vec3T< ValueT > > const & lhs
		, ValueT const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator-( MaybeOptional< Vec3T< ValueT > > const & lhs
		, Vec3T< ValueT > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator-( CppTypeT< ValueT > const & lhs
		, MaybeOptional< Vec3T< ValueT > > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator-( ValueT const & lhs
		, MaybeOptional< Vec3T< ValueT > > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator-( Vec3T< ValueT > const & lhs
		, MaybeOptional< ValueT > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator-( Vec3T< ValueT > const & lhs
		, MaybeOptional< Vec3T< ValueT > > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator-( MaybeOptional< ValueT > const & lhs
		, MaybeOptional< Vec3T< ValueT > > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator-( MaybeOptional< Vec3T< ValueT > > const & lhs
		, MaybeOptional< ValueT > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator-( MaybeOptional< Vec3T< ValueT > > const & lhs
		, MaybeOptional< Vec3T< ValueT > > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator*( MaybeOptional< ValueT > const & lhs
		, Vec3T< ValueT > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator*( MaybeOptional< Vec3T< ValueT > > const & lhs
		, CppTypeT< ValueT > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator*( MaybeOptional< Vec3T< ValueT > > const & lhs
		, ValueT const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator*( MaybeOptional< Vec3T< ValueT > > const & lhs
		, Vec3T< ValueT > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator*( CppTypeT< ValueT > const & lhs
		, MaybeOptional< Vec3T< ValueT > > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator*( ValueT const & lhs
		, MaybeOptional< Vec3T< ValueT > > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator*( Vec3T< ValueT > const & lhs
		, MaybeOptional< ValueT > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator*( Vec3T< ValueT > const & lhs
		, MaybeOptional< Vec3T< ValueT > > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator*( MaybeOptional< ValueT > const & lhs
		, MaybeOptional< Vec3T< ValueT > > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator*( MaybeOptional< Vec3T< ValueT > > const & lhs
		, MaybeOptional< ValueT > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator*( MaybeOptional< Vec3T< ValueT > > const & lhs
		, MaybeOptional< Vec3T< ValueT > > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator/( MaybeOptional< Vec3T< ValueT > > const & lhs
		, CppTypeT< ValueT > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator/( MaybeOptional< Vec3T< ValueT > > const & lhs
		, ValueT const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator/( MaybeOptional< Vec3T< ValueT > > const & lhs
		, Vec3T< ValueT > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator/( Vec3T< ValueT > const & lhs
		, MaybeOptional< ValueT > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator/( Vec3T< ValueT > const & lhs
		, MaybeOptional< Vec3T< ValueT > > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator/( MaybeOptional< Vec3T< ValueT > > const & lhs
		, MaybeOptional< ValueT > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator/( MaybeOptional< Vec3T< ValueT > > const & lhs
		, MaybeOptional< Vec3T< ValueT > > const & rhs );
}

#include "MaybeOptionalVec3.inl"

#endif
