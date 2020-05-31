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
