/*
See LICENSE file in root folder
*/
#ifndef ___SDW_MaybeOptionalVec2_H___
#define ___SDW_MaybeOptionalVec2_H___
#pragma once

#include "MaybeOptional.hpp"
#include "ShaderWriter/Optional/OptionalVec2.hpp"

namespace sdw
{
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
