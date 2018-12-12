/*
See LICENSE file in root folder
*/
#ifndef ___SDW_OptionalVec2_H___
#define ___SDW_OptionalVec2_H___
#pragma once

#include "ShaderWriter/VecTypes/Vec2.hpp"

namespace sdw
{
	template< typename ValueT >
	struct Optional< Vec2T< ValueT > >
		: public Vec2T< ValueT >
	{
		using ValueType = Optional< ValueT >;
		using Vec2Type = Optional< Vec2T< ValueT > >;

		inline Optional( Shader * shader
			, expr::ExprPtr expr
			, bool enabled );
		inline Optional( Vec2T< ValueT > const & other
			, bool enabled );
		inline Optional( Optional< Vec2T< ValueT > > const & rhs );
		inline Optional< Vec2T< ValueT > > & operator=( Optional< Vec2T< ValueT > > const & rhs );
		template< typename IndexT >
		inline Optional< ValueT > operator[]( IndexT const & rhs )const;
		inline bool isEnabled()const;

		inline operator Optional< Value >()const;

		inline Optional< Vec2T< ValueT > > & operator+=( Vec2T< ValueT > const & rhs );
		inline Optional< Vec2T< ValueT > > & operator-=( Vec2T< ValueT > const & rhs );
		inline Optional< Vec2T< ValueT > > & operator*=( Vec2T< ValueT > const & rhs );
		inline Optional< Vec2T< ValueT > > & operator/=( Vec2T< ValueT > const & rhs );
		inline Optional< Vec2T< ValueT > > & operator+=( Optional< Vec2T< ValueT > > const & rhs );
		inline Optional< Vec2T< ValueT > > & operator-=( Optional< Vec2T< ValueT > > const & rhs );
		inline Optional< Vec2T< ValueT > > & operator*=( Optional< Vec2T< ValueT > > const & rhs );
		inline Optional< Vec2T< ValueT > > & operator/=( Optional< Vec2T< ValueT > > const & rhs );
		inline Optional< Vec2T< ValueT > > & operator+=( ValueT const & rhs );
		inline Optional< Vec2T< ValueT > > & operator-=( ValueT const & rhs );
		inline Optional< Vec2T< ValueT > > & operator*=( ValueT const & rhs );
		inline Optional< Vec2T< ValueT > > & operator/=( ValueT const & rhs );
		inline Optional< Vec2T< ValueT > > & operator+=( Optional< ValueT > const & rhs );
		inline Optional< Vec2T< ValueT > > & operator-=( Optional< ValueT > const & rhs );
		inline Optional< Vec2T< ValueT > > & operator*=( Optional< ValueT > const & rhs );
		inline Optional< Vec2T< ValueT > > & operator/=( Optional< ValueT > const & rhs );
		inline Optional< Vec2T< ValueT > > operator-()const;
		inline Optional< Vec2T< ValueT > > operator+()const;

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
		bool m_enabled;
	};

	template< typename ValueT >
	inline Vec2T< ValueT > operator+( CppTypeT< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs );
	template< typename ValueT >
	inline Vec2T< ValueT > operator+( ValueT const & lhs
		, Vec2T< ValueT > const & rhs );
	template< typename ValueT >
	inline Vec2T< ValueT > operator+( Vec2T< ValueT > const & lhs
		, ValueT const & rhs );
	template< typename ValueT >
	inline Vec2T< ValueT > operator+( Vec2T< ValueT > const & lhs
		, CppTypeT< ValueT > const & rhs );
	template< typename ValueT >
	inline Vec2T< ValueT > operator+( Vec2T< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs );
	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator+( Optional< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs );
	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator+( Optional< Vec2T< ValueT > > const & lhs
		, CppTypeT< ValueT > const & rhs );
	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator+( Optional< Vec2T< ValueT > > const & lhs
		, ValueT const & rhs );
	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator+( Optional< Vec2T< ValueT > > const & lhs
		, Vec2T< ValueT > const & rhs );
	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator+( CppTypeT< ValueT > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs );
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
	inline Vec2T< ValueT > operator-( CppTypeT< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs );
	template< typename ValueT >
	inline Vec2T< ValueT > operator-( ValueT const & lhs
		, Vec2T< ValueT > const & rhs );
	template< typename ValueT >
	inline Vec2T< ValueT > operator-( Vec2T< ValueT > const & lhs
		, ValueT const & rhs );
	template< typename ValueT >
	inline Vec2T< ValueT > operator-( Vec2T< ValueT > const & lhs
		, CppTypeT< ValueT > const & rhs );
	template< typename ValueT >
	inline Vec2T< ValueT > operator-( Vec2T< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs );
	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator-( Optional< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs );
	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator-( Optional< Vec2T< ValueT > > const & lhs
		, CppTypeT< ValueT > const & rhs );
	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator-( Optional< Vec2T< ValueT > > const & lhs
		, ValueT const & rhs );
	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator-( Optional< Vec2T< ValueT > > const & lhs
		, Vec2T< ValueT > const & rhs );
	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator-( CppTypeT< ValueT > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs );
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
	inline Vec2T< ValueT > operator*( CppTypeT< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs );
	template< typename ValueT >
	inline Vec2T< ValueT > operator*( ValueT const & lhs
		, Vec2T< ValueT > const & rhs );
	template< typename ValueT >
	inline Vec2T< ValueT > operator*( Vec2T< ValueT > const & lhs
		, ValueT const & rhs );
	template< typename ValueT >
	inline Vec2T< ValueT > operator*( Vec2T< ValueT > const & lhs
		, CppTypeT< ValueT > const & rhs );
	template< typename ValueT >
	inline Vec2T< ValueT > operator*( Vec2T< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs );
	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator*( Optional< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs );
	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator*( Optional< Vec2T< ValueT > > const & lhs
		, CppTypeT< ValueT > const & rhs );
	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator*( Optional< Vec2T< ValueT > > const & lhs
		, ValueT const & rhs );
	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator*( Optional< Vec2T< ValueT > > const & lhs
		, Vec2T< ValueT > const & rhs );
	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator*( CppTypeT< ValueT > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs );
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
	inline Vec2T< ValueT > operator/( Vec2T< ValueT > const & lhs
		, CppTypeT< ValueT > const & rhs );
	template< typename ValueT >
	inline Vec2T< ValueT > operator/( Vec2T< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs );
	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator/( Optional< Vec2T< ValueT > > const & lhs
		, CppTypeT< ValueT > const & rhs );
	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator/( Optional< Vec2T< ValueT > > const & lhs
		, ValueT const & rhs );
	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator/( Optional< Vec2T< ValueT > > const & lhs
		, Vec2T< ValueT > const & rhs );
	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator/( Vec2T< ValueT > const & lhs
		, Optional< ValueT > const & rhs );
	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator/( Vec2T< ValueT > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs );
	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator/( Optional< Vec2T< ValueT > > const & lhs
		, Optional< ValueT > const & rhs );
	template< typename ValueT >
	inline Optional< Vec2T< ValueT > > operator/( Optional< Vec2T< ValueT > > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs );
}

#include "OptionalVec2.inl"

#endif
