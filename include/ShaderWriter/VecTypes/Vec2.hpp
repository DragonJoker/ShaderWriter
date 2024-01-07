/*
See LICENSE file in root folder
*/
#ifndef ___SDW_Vec2_H___
#define ___SDW_Vec2_H___
#pragma once

#include "ShaderWriter/BaseTypes/Boolean.hpp"
#include "Swizzle.hpp"

namespace sdw
{
	template< typename ValueT >
	struct Vec2T
		: public Value
	{
		SDW_DeclValue( , Vec2T );

		using ValueType = ValueT;
		using Vec2Type = Vec2T< ValueT >;

		Vec2T( ShaderWriter & writer
			, expr::ExprPtr expr
			, bool enabled );

		template< typename IndexT >
		ValueT operator[]( IndexT const & rhs )const;
		ValueT operator[]( int32_t offset )const;
		ValueT operator[]( uint32_t offset )const;

		Vec2T< ValueT > & operator+=( Vec2T< ValueT > const & rhs );
		Vec2T< ValueT > & operator-=( Vec2T< ValueT > const & rhs );
		Vec2T< ValueT > & operator*=( Vec2T< ValueT > const & rhs );
		Vec2T< ValueT > & operator/=( Vec2T< ValueT > const & rhs );
		Vec2T< ValueT > & operator+=( ValueT const & rhs );
		Vec2T< ValueT > & operator-=( ValueT const & rhs );
		Vec2T< ValueT > & operator*=( ValueT const & rhs );
		Vec2T< ValueT > & operator/=( ValueT const & rhs );
		Vec2T< ValueT > operator-()const;
		Vec2T< ValueT > operator+()const;

		static ast::type::TypePtr makeType( ast::type::TypesCache & cache );

		Writer_FirstSwizzle( Vec2Type, ValueType, x )
		Writer_Swizzle( Vec2Type, ValueType, y )
		Writer_Swizzle( Vec2Type, ValueType, s )
		Writer_Swizzle( Vec2Type, ValueType, t )
		Writer_Swizzle( Vec2Type, ValueType, r )
		Writer_LastSwizzle( Vec2Type, ValueType, g )
		Writer_FirstSwizzle( Vec2Type, Vec2Type, xy )
		Writer_Swizzle( Vec2Type, Vec2Type, yx )
		Writer_Swizzle( Vec2Type, Vec2Type, xx )
		Writer_Swizzle( Vec2Type, Vec2Type, yy )
		Writer_Swizzle( Vec2Type, ValueType, st )
		Writer_Swizzle( Vec2Type, ValueType, ts )
		Writer_Swizzle( Vec2Type, ValueType, ss )
		Writer_Swizzle( Vec2Type, ValueType, tt )
		Writer_Swizzle( Vec2Type, Vec2Type, rg )
		Writer_Swizzle( Vec2Type, Vec2Type, gr )
		Writer_Swizzle( Vec2Type, Vec2Type, rr )
		Writer_LastSwizzle( Vec2Type, Vec2Type, gg )
	};

	template< typename ValueT >
	Vec2T< Boolean > operator==( Vec2T< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs );
	template< typename ValueT >
	Vec2T< Boolean > operator!=( Vec2T< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs );
	template< typename ValueT >
	Vec2T< Boolean > operator<( Vec2T< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs );
	template< typename ValueT >
	Vec2T< Boolean > operator<=( Vec2T< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs );
	template< typename ValueT >
	Vec2T< Boolean > operator>( Vec2T< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs );
	template< typename ValueT >
	Vec2T< Boolean > operator>=( Vec2T< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs );

	template< typename ValueT >
	Vec2T< Boolean > operator==( Vec2T< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs );
	template< typename ValueT >
	Vec2T< Boolean > operator!=( Vec2T< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs );
	template< typename ValueT >
	Vec2T< Boolean > operator<( Vec2T< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs );
	template< typename ValueT >
	Vec2T< Boolean > operator<=( Vec2T< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs );
	template< typename ValueT >
	Vec2T< Boolean > operator>( Vec2T< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs );
	template< typename ValueT >
	Vec2T< Boolean > operator>=( Vec2T< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs );

	template< typename ValueT, VecCompatibleT< ValueT > LhsT >
	inline Vec2T< ValueT > operator+( LhsT const & lhs
		, Vec2T< ValueT > const & rhs );
	template< typename ValueT, VecCompatibleT< ValueT > RhsT >
	inline Vec2T< ValueT > operator+( Vec2T< ValueT > const & lhs
		, RhsT const & rhs );
	template< typename ValueT >
	inline Vec2T< ValueT > operator+( Vec2T< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs );

	template< typename ValueT, VecCompatibleT< ValueT > LhsT >
	inline Vec2T< ValueT > operator-( LhsT const & lhs
		, Vec2T< ValueT > const & rhs );
	template< typename ValueT, VecCompatibleT< ValueT > RhsT >
	inline Vec2T< ValueT > operator-( Vec2T< ValueT > const & lhs
		, RhsT const & rhs );
	template< typename ValueT >
	inline Vec2T< ValueT > operator-( Vec2T< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs );

	template< typename ValueT, VecCompatibleT< ValueT > LhsT >
	inline Vec2T< ValueT > operator*( LhsT const & lhs
		, Vec2T< ValueT > const & rhs );
	template< typename ValueT, VecCompatibleT< ValueT > RhsT >
	inline Vec2T< ValueT > operator*( Vec2T< ValueT > const & lhs
		, RhsT const & rhs );
	template< typename ValueT >
	inline Vec2T< ValueT > operator*( Vec2T< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs );

	template< typename ValueT, VecCompatibleT< ValueT > RhsT >
	inline Vec2T< ValueT > operator/( Vec2T< ValueT > const & lhs
		, RhsT const & rhs );
	template< typename ValueT >
	inline Vec2T< ValueT > operator/( Vec2T< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs );
}

#include "Vec2.inl"

#endif
