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
		inline MaybeOptional< Vec2T< ValueT > > operator-()const;
		inline MaybeOptional< Vec2T< ValueT > > operator+()const;

		Writer_FirstMayOptSwizzle( Vec2Type, ValueType, x );
		Writer_MayOptSwizzle( Vec2Type, ValueType, y );
		Writer_MayOptSwizzle( Vec2Type, ValueType, s );
		Writer_MayOptSwizzle( Vec2Type, ValueType, t );
		Writer_MayOptSwizzle( Vec2Type, ValueType, r );
		Writer_LastMayOptSwizzle( Vec2Type, ValueType, g );
		Writer_FirstMayOptSwizzle( Vec2Type, Vec2Type, xy );
		Writer_MayOptSwizzle( Vec2Type, Vec2Type, yx );
		Writer_MayOptSwizzle( Vec2Type, Vec2Type, xx );
		Writer_MayOptSwizzle( Vec2Type, Vec2Type, yy );
		Writer_MayOptSwizzle( Vec2Type, ValueType, st );
		Writer_MayOptSwizzle( Vec2Type, ValueType, ts );
		Writer_MayOptSwizzle( Vec2Type, ValueType, ss );
		Writer_MayOptSwizzle( Vec2Type, ValueType, tt );
		Writer_MayOptSwizzle( Vec2Type, Vec2Type, rg );
		Writer_MayOptSwizzle( Vec2Type, Vec2Type, gr );
		Writer_MayOptSwizzle( Vec2Type, Vec2Type, rr );
		Writer_LastMayOptSwizzle( Vec2Type, Vec2Type, gg );

	private:
		bool m_optional;
		bool m_enabled;
	};

	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator+( MaybeOptional< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator+( MaybeOptional< Vec2T< ValueT > > const & lhs
		, CppTypeT< ValueT > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator+( MaybeOptional< Vec2T< ValueT > > const & lhs
		, ValueT const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator+( MaybeOptional< Vec2T< ValueT > > const & lhs
		, Vec2T< ValueT > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator+( CppTypeT< ValueT > const & lhs
		, MaybeOptional< Vec2T< ValueT > > const & rhs );
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
		, CppTypeT< ValueT > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator-( MaybeOptional< Vec2T< ValueT > > const & lhs
		, ValueT const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator-( MaybeOptional< Vec2T< ValueT > > const & lhs
		, Vec2T< ValueT > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator-( CppTypeT< ValueT > const & lhs
		, MaybeOptional< Vec2T< ValueT > > const & rhs );
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
		, CppTypeT< ValueT > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator*( MaybeOptional< Vec2T< ValueT > > const & lhs
		, ValueT const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator*( MaybeOptional< Vec2T< ValueT > > const & lhs
		, Vec2T< ValueT > const & rhs );
	template< typename ValueT >
	inline MaybeOptional< Vec2T< ValueT > > operator*( CppTypeT< ValueT > const & lhs
		, MaybeOptional< Vec2T< ValueT > > const & rhs );
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
		, CppTypeT< ValueT > const & rhs );
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
