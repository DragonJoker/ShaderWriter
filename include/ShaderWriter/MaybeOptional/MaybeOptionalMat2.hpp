/*
See LICENSE file in root folder
*/
#ifndef ___SDW_MaybeOptionalMat2_H___
#define ___SDW_MaybeOptionalMat2_H___
#pragma once

#include "MaybeOptional.hpp"
#include "ShaderWriter/Optional/OptionalMat2.hpp"

namespace sdw
{
	template< typename ValueT >
	MaybeOptional< Vec2T< ValueT > > operator*( MaybeOptional< Vec2T< ValueT > > const & lhs,
		Mat2T< ValueT > const & rhs );
	template< typename ValueT >
	MaybeOptional< Vec2T< ValueT > > operator*( MaybeOptional< Mat2T< ValueT > > const & lhs
		, Vec2T< ValueT > const & rhs );
	template< typename ValueT >
	MaybeOptional< Mat2T< ValueT > > operator*( MaybeOptional< Mat2T< ValueT > > const & lhs
		, Mat2T< ValueT > const & rhs );
	template< typename ValueT >
	MaybeOptional< Vec2T< ValueT > > operator*( Vec2T< ValueT > const & lhs,
		MaybeOptional< Mat2T< ValueT > > const & rhs );
	template< typename ValueT >
	MaybeOptional< Vec2T< ValueT > > operator*( Mat2T< ValueT > const & lhs
		, MaybeOptional< Vec2T< ValueT > > const & rhs );
	template< typename ValueT >
	MaybeOptional< Mat2T< ValueT > > operator*( Mat2T< ValueT > const & lhs
		, MaybeOptional< Mat2T< ValueT > > const & rhs );
	template< typename ValueT >
	MaybeOptional< Vec2T< ValueT > > operator*( MaybeOptional< Vec2T< ValueT > > const & lhs,
		MaybeOptional< Mat2T< ValueT > > const & rhs );
	template< typename ValueT >
	MaybeOptional< Vec2T< ValueT > > operator*( MaybeOptional< Mat2T< ValueT > > const & lhs
		, MaybeOptional< Vec2T< ValueT > > const & rhs );
	template< typename ValueT >
	MaybeOptional< Mat2T< ValueT > > operator*( MaybeOptional< Mat2T< ValueT > > const & lhs
		, MaybeOptional< Mat2T< ValueT > > const & rhs );

	template< typename ValueT >
	MaybeOptional< Mat2T< ValueT > > operator*( MaybeOptional< ValueT > const & lhs
		, Mat2T< ValueT > const & rhs );
	template< typename ValueT >
	MaybeOptional< Mat2T< ValueT > > operator*( MaybeOptional< Mat2T< ValueT > > const & lhs
		, ValueT const & rhs );
	template< typename ValueT >
	MaybeOptional< Mat2T< ValueT > > operator*( ValueT const & lhs
		, MaybeOptional< Mat2T< ValueT > > const & rhs );
	template< typename ValueT >
	MaybeOptional< Mat2T< ValueT > > operator*( Mat2T< ValueT > const & lhs
		, MaybeOptional< ValueT > const & rhs );
	template< typename ValueT >
	MaybeOptional< Mat2T< ValueT > > operator*( MaybeOptional< ValueT > const & lhs
		, MaybeOptional< Mat2T< ValueT > > const & rhs );
	template< typename ValueT >
	MaybeOptional< Mat2T< ValueT > > operator*( MaybeOptional< Mat2T< ValueT > > const & lhs
		, MaybeOptional< ValueT > const & rhs );
}

#include "MaybeOptionalMat2.inl"

#endif
