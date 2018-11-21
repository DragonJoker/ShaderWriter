/*
See LICENSE file in root folder
*/
#ifndef ___SDW_MaybeOptionalVec3_H___
#define ___SDW_MaybeOptionalVec3_H___
#pragma once

#include "ShaderWriter/Optional/OptionalVec3.hpp"

namespace sdw
{
	template< typename ValueT >
	struct MaybeOptional< Vec3T< ValueT > >
		: public Vec3T< ValueT >
	{
		using MyValue = Vec3T< ValueT >;

		using ValueType = MaybeOptional< ValueT >;
		using Vec3Type = MaybeOptional< Vec3T< ValueT > >;

		inline MaybeOptional( Shader * shader
			, expr::ExprPtr expr );
		inline MaybeOptional( Shader * shader
			, expr::ExprPtr expr
			, bool enabled );
		inline MaybeOptional( MyValue const & rhs );
		inline MaybeOptional( Optional< MyValue > const & rhs );
		inline MaybeOptional( MaybeOptional< MyValue > const & rhs );

		inline MaybeOptional< Vec3T< ValueT > > & operator=( MaybeOptional< Vec3T< ValueT > > const & rhs );
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

		Writer_FirstOptSwizzle( Vec3Type, ValueType, x );
		Writer_OptSwizzle( Vec3Type, ValueType, y );
		Writer_OptSwizzle( Vec3Type, ValueType, z );
		Writer_OptSwizzle( Vec3Type, ValueType, s );
		Writer_OptSwizzle( Vec3Type, ValueType, t );
		Writer_OptSwizzle( Vec3Type, ValueType, p );
		Writer_OptSwizzle( Vec3Type, ValueType, r );
		Writer_OptSwizzle( Vec3Type, ValueType, g );
		Writer_LastOptSwizzle( Vec3Type, ValueType, b );
		Writer_FirstOptSwizzle( Vec3Type, Vec2Type, xy );
		Writer_OptSwizzle( Vec3Type, Vec2Type, xz );
		Writer_OptSwizzle( Vec3Type, Vec2Type, yx );
		Writer_OptSwizzle( Vec3Type, Vec2Type, yz );
		Writer_OptSwizzle( Vec3Type, Vec2Type, zx );
		Writer_OptSwizzle( Vec3Type, Vec2Type, zy );
		Writer_OptSwizzle( Vec2Type, Vec2Type, xx );
		Writer_OptSwizzle( Vec2Type, Vec2Type, yy );
		Writer_OptSwizzle( Vec2Type, Vec2Type, zz );
		Writer_OptSwizzle( Vec3Type, Vec2Type, st );
		Writer_OptSwizzle( Vec3Type, Vec2Type, sp );
		Writer_OptSwizzle( Vec3Type, Vec2Type, ts );
		Writer_OptSwizzle( Vec3Type, Vec2Type, tp );
		Writer_OptSwizzle( Vec3Type, Vec2Type, ps );
		Writer_OptSwizzle( Vec3Type, Vec2Type, pt );
		Writer_OptSwizzle( Vec2Type, ValueType, ss );
		Writer_OptSwizzle( Vec2Type, ValueType, tt );
		Writer_OptSwizzle( Vec2Type, ValueType, pp );
		Writer_OptSwizzle( Vec3Type, Vec2Type, rg );
		Writer_OptSwizzle( Vec3Type, Vec2Type, rb );
		Writer_OptSwizzle( Vec3Type, Vec2Type, gr );
		Writer_OptSwizzle( Vec3Type, Vec2Type, gb );
		Writer_OptSwizzle( Vec3Type, Vec2Type, br );
		Writer_OptSwizzle( Vec2Type, Vec2Type, bg );
		Writer_OptSwizzle( Vec2Type, Vec2Type, rr );
		Writer_OptSwizzle( Vec2Type, Vec2Type, gg );
		Writer_LastOptSwizzle( Vec3Type, Vec2Type, bb );
		Writer_FirstOptSwizzle( Vec3Type, Vec3Type, xyz );
		Writer_OptSwizzle( Vec3Type, Vec3Type, xzy );
		Writer_OptSwizzle( Vec3Type, Vec3Type, yxz );
		Writer_OptSwizzle( Vec3Type, Vec3Type, yzx );
		Writer_OptSwizzle( Vec3Type, Vec3Type, zxy );
		Writer_OptSwizzle( Vec3Type, Vec3Type, zyx );
		Writer_OptSwizzle( Vec3Type, Vec3Type, stp );
		Writer_OptSwizzle( Vec3Type, Vec3Type, spt );
		Writer_OptSwizzle( Vec3Type, Vec3Type, tsp );
		Writer_OptSwizzle( Vec3Type, Vec3Type, tps );
		Writer_OptSwizzle( Vec3Type, Vec3Type, pst );
		Writer_OptSwizzle( Vec3Type, Vec3Type, pts );
		Writer_OptSwizzle( Vec3Type, Vec3Type, rgb );
		Writer_OptSwizzle( Vec3Type, Vec3Type, rbg );
		Writer_OptSwizzle( Vec3Type, Vec3Type, grb );
		Writer_OptSwizzle( Vec3Type, Vec3Type, gbr );
		Writer_OptSwizzle( Vec3Type, Vec3Type, brg );
		Writer_LastOptSwizzle( Vec3Type, Vec3Type, bgr );

	private:
		bool m_optional;
		bool m_enabled;
	};

	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator+( MaybeOptional< ValueT > const & lhs
		, Vec3T< ValueT > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator+( MaybeOptional< Vec3T< ValueT > > const & lhs
		, ValueT const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator+( MaybeOptional< Vec3T< ValueT > > const & lhs
		, Vec3T< ValueT > const & rhs );
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
		, ValueT const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator-( MaybeOptional< Vec3T< ValueT > > const & lhs
		, Vec3T< ValueT > const & rhs );
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
		, ValueT const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec3T< ValueT > > operator*( MaybeOptional< Vec3T< ValueT > > const & lhs
		, Vec3T< ValueT > const & rhs );
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
