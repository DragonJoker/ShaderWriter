/*
See LICENSE file in root folder
*/
#ifndef ___SDW_MaybeOptionalMat4_H___
#define ___SDW_MaybeOptionalMat4_H___
#pragma once

#include "MaybeOptional.hpp"
#include "ShaderWriter/Optional/OptionalMat4.hpp"

namespace sdw
{
	template< typename ValueT >
	MaybeOptional< Vec4T< ValueT > > operator*( MaybeOptional< Vec4T< ValueT > > const & lhs,
		Mat4T< ValueT > const & rhs );
	template< typename ValueT >
	MaybeOptional< Vec4T< ValueT > > operator*( MaybeOptional< Mat4T< ValueT > > const & lhs
		, Vec4T< ValueT > const & rhs );
	template< typename ValueT >
	MaybeOptional< Mat4T< ValueT > > operator*( MaybeOptional< Mat4T< ValueT > > const & lhs
		, Mat4T< ValueT > const & rhs );
	template< typename ValueT >
	MaybeOptional< Vec4T< ValueT > > operator*( Vec4T< ValueT > const & lhs,
		MaybeOptional< Mat4T< ValueT > > const & rhs );
	template< typename ValueT >
	MaybeOptional< Vec4T< ValueT > > operator*( Mat4T< ValueT > const & lhs
		, MaybeOptional< Vec4T< ValueT > > const & rhs );
	template< typename ValueT >
	MaybeOptional< Mat4T< ValueT > > operator*( Mat4T< ValueT > const & lhs
		, MaybeOptional< Mat4T< ValueT > > const & rhs );
	template< typename ValueT >
	MaybeOptional< Vec4T< ValueT > > operator*( MaybeOptional< Vec4T< ValueT > > const & lhs,
		MaybeOptional< Mat4T< ValueT > > const & rhs );
	template< typename ValueT >
	MaybeOptional< Vec4T< ValueT > > operator*( MaybeOptional< Mat4T< ValueT > > const & lhs
		, MaybeOptional< Vec4T< ValueT > > const & rhs );
	template< typename ValueT >
	MaybeOptional< Mat4T< ValueT > > operator*( MaybeOptional< Mat4T< ValueT > > const & lhs
		, MaybeOptional< Mat4T< ValueT > > const & rhs );

	template< typename ValueT >
	MaybeOptional< Mat4T< ValueT > > operator*( MaybeOptional< ValueT > const & lhs
		, Mat4T< ValueT > const & rhs );
	template< typename ValueT >
	MaybeOptional< Mat4T< ValueT > > operator*( MaybeOptional< Mat4T< ValueT > > const & lhs
		, ValueT const & rhs );
	template< typename ValueT >
	MaybeOptional< Mat4T< ValueT > > operator*( ValueT const & lhs
		, MaybeOptional< Mat4T< ValueT > > const & rhs );
	template< typename ValueT >
	MaybeOptional< Mat4T< ValueT > > operator*( Mat4T< ValueT > const & lhs
		, MaybeOptional< ValueT > const & rhs );
	template< typename ValueT >
	MaybeOptional< Mat4T< ValueT > > operator*( MaybeOptional< ValueT > const & lhs
		, MaybeOptional< Mat4T< ValueT > > const & rhs );
	template< typename ValueT >
	MaybeOptional< Mat4T< ValueT > > operator*( MaybeOptional< Mat4T< ValueT > > const & lhs
		, MaybeOptional< ValueT > const & rhs );
}

#include "MaybeOptionalMat4.inl"

#endif
