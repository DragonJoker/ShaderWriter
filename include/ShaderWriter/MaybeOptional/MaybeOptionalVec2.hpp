/*
See LICENSE file in root folder
*/
#ifndef ___SDW_MaybeOptionalVec2_H___
#define ___SDW_MaybeOptionalVec2_H___
#pragma once

#include "ShaderWriter/Optional/OptionalVec2.hpp"

namespace sdw
{
	template< typename ValueT >
	struct MaybeOptional< Vec2T< ValueT > >
		: public Vec2T< ValueT >
	{
		using MyValue = Vec2T< ValueT >;

		using ValueType = MaybeOptional< ValueT >;
		using Vec2Type = MaybeOptional< Vec2T< ValueT > >;

		inline MaybeOptional( Shader * shader
			, expr::ExprPtr expr );
		inline MaybeOptional( Shader * shader
			, expr::ExprPtr expr
			, bool enabled );
		inline MaybeOptional( MyValue const & rhs );
		inline MaybeOptional( Optional< MyValue > const & rhs );
		inline MaybeOptional( MaybeOptional< MyValue > const & rhs );

		inline MaybeOptional< Vec2T< ValueT > > & operator=( MaybeOptional< Vec2T< ValueT > > const & rhs );
		template< typename IndexT >
		inline MaybeOptional< ValueT > operator[]( IndexT const & rhs )const;

		inline operator MyValue()const;
		inline operator Optional< MyValue >()const;

		inline bool isOptional()const;
		inline bool isEnabled()const;

		inline MaybeOptional< Vec2T< ValueT > > & operator+=( Vec2T< ValueT > const & rhs );
		inline MaybeOptional< Vec2T< ValueT > > & operator-=( Vec2T< ValueT > const & rhs );
		inline MaybeOptional< Vec2T< ValueT > > & operator*=( Vec2T< ValueT > const & rhs );
		inline MaybeOptional< Vec2T< ValueT > > & operator/=( Vec2T< ValueT > const & rhs );
		inline MaybeOptional< Vec2T< ValueT > > & operator+=( MaybeOptional< Vec2T< ValueT > > const & rhs );
		inline MaybeOptional< Vec2T< ValueT > > & operator-=( MaybeOptional< Vec2T< ValueT > > const & rhs );
		inline MaybeOptional< Vec2T< ValueT > > & operator*=( MaybeOptional< Vec2T< ValueT > > const & rhs );
		inline MaybeOptional< Vec2T< ValueT > > & operator/=( MaybeOptional< Vec2T< ValueT > > const & rhs );
		inline MaybeOptional< Vec2T< ValueT > > & operator+=( ValueT const & rhs );
		inline MaybeOptional< Vec2T< ValueT > > & operator-=( ValueT const & rhs );
		inline MaybeOptional< Vec2T< ValueT > > & operator*=( ValueT const & rhs );
		inline MaybeOptional< Vec2T< ValueT > > & operator/=( ValueT const & rhs );
		inline MaybeOptional< Vec2T< ValueT > > & operator+=( MaybeOptional< ValueT > const & rhs );
		inline MaybeOptional< Vec2T< ValueT > > & operator-=( MaybeOptional< ValueT > const & rhs );
		inline MaybeOptional< Vec2T< ValueT > > & operator*=( MaybeOptional< ValueT > const & rhs );
		inline MaybeOptional< Vec2T< ValueT > > & operator/=( MaybeOptional< ValueT > const & rhs );

		Writer_FirstOptSwizzle( Vec2Type, ValueType, x );
		Writer_OptSwizzle( Vec2Type, ValueType, y );
		Writer_OptSwizzle( Vec2Type, ValueType, s );
		Writer_OptSwizzle( Vec2Type, ValueType, t );
		Writer_OptSwizzle( Vec2Type, ValueType, r );
		Writer_LastOptSwizzle( Vec2Type, ValueType, g );
		Writer_FirstOptSwizzle( Vec2Type, Vec2Type, xy );
		Writer_OptSwizzle( Vec2Type, Vec2Type, yx );
		Writer_OptSwizzle( Vec2Type, Vec2Type, xx );
		Writer_OptSwizzle( Vec2Type, Vec2Type, yy );
		Writer_OptSwizzle( Vec2Type, ValueType, st );
		Writer_OptSwizzle( Vec2Type, ValueType, ts );
		Writer_OptSwizzle( Vec2Type, ValueType, ss );
		Writer_OptSwizzle( Vec2Type, ValueType, tt );
		Writer_OptSwizzle( Vec2Type, Vec2Type, rg );
		Writer_OptSwizzle( Vec2Type, Vec2Type, gr );
		Writer_OptSwizzle( Vec2Type, Vec2Type, rr );
		Writer_LastOptSwizzle( Vec2Type, Vec2Type, gg );

	private:
		bool m_optional;
		bool m_enabled;
	};

	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator+( MaybeOptional< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator+( MaybeOptional< Vec2T< ValueT > > const & lhs
		, ValueT const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator+( MaybeOptional< Vec2T< ValueT > > const & lhs
		, Vec2T< ValueT > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator+( ValueT const & lhs
		, MaybeOptional< Vec2T< ValueT > > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator+( Vec2T< ValueT > const & lhs
		, MaybeOptional< ValueT > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator+( Vec2T< ValueT > const & lhs
		, MaybeOptional< Vec2T< ValueT > > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator+( MaybeOptional< ValueT > const & lhs
		, MaybeOptional< Vec2T< ValueT > > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator+( MaybeOptional< Vec2T< ValueT > > const & lhs
		, MaybeOptional< ValueT > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator+( MaybeOptional< Vec2T< ValueT > > const & lhs
		, MaybeOptional< Vec2T< ValueT > > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator-( MaybeOptional< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator-( MaybeOptional< Vec2T< ValueT > > const & lhs
		, ValueT const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator-( MaybeOptional< Vec2T< ValueT > > const & lhs
		, Vec2T< ValueT > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator-( ValueT const & lhs
		, MaybeOptional< Vec2T< ValueT > > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator-( Vec2T< ValueT > const & lhs
		, MaybeOptional< ValueT > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator-( Vec2T< ValueT > const & lhs
		, MaybeOptional< Vec2T< ValueT > > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator-( MaybeOptional< ValueT > const & lhs
		, MaybeOptional< Vec2T< ValueT > > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator-( MaybeOptional< Vec2T< ValueT > > const & lhs
		, MaybeOptional< ValueT > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator-( MaybeOptional< Vec2T< ValueT > > const & lhs
		, MaybeOptional< Vec2T< ValueT > > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator*( MaybeOptional< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator*( MaybeOptional< Vec2T< ValueT > > const & lhs
		, ValueT const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator*( MaybeOptional< Vec2T< ValueT > > const & lhs
		, Vec2T< ValueT > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator*( ValueT const & lhs
		, MaybeOptional< Vec2T< ValueT > > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator*( Vec2T< ValueT > const & lhs
		, MaybeOptional< ValueT > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator*( Vec2T< ValueT > const & lhs
		, MaybeOptional< Vec2T< ValueT > > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator*( MaybeOptional< ValueT > const & lhs
		, MaybeOptional< Vec2T< ValueT > > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator*( MaybeOptional< Vec2T< ValueT > > const & lhs
		, MaybeOptional< ValueT > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator*( MaybeOptional< Vec2T< ValueT > > const & lhs
		, MaybeOptional< Vec2T< ValueT > > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator/( MaybeOptional< Vec2T< ValueT > > const & lhs
		, ValueT const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator/( MaybeOptional< Vec2T< ValueT > > const & lhs
		, Vec2T< ValueT > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator/( Vec2T< ValueT > const & lhs
		, MaybeOptional< ValueT > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator/( Vec2T< ValueT > const & lhs
		, MaybeOptional< Vec2T< ValueT > > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator/( MaybeOptional< Vec2T< ValueT > > const & lhs
		, MaybeOptional< ValueT > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator/( MaybeOptional< Vec2T< ValueT > > const & lhs
		, MaybeOptional< Vec2T< ValueT > > const & rhs );
}

#include "MaybeOptionalVec2.inl"

#endif
