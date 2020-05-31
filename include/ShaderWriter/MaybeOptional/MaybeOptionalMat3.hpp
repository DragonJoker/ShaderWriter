/*
See LICENSE file in root folder
*/
#ifndef ___SDW_MaybeOptionalMat3_H___
#define ___SDW_MaybeOptionalMat3_H___
#pragma once

#include "MaybeOptional.hpp"
#include "ShaderWriter/Optional/OptionalMat3.hpp"

namespace sdw
{
	template< typename ValueT >
	MaybeOptional< Vec3T< ValueT > > operator*( MaybeOptional< Vec3T< ValueT > > const & lhs,
		Mat3T< ValueT > const & rhs );
	template< typename ValueT >
	MaybeOptional< Vec3T< ValueT > > operator*( MaybeOptional< Mat3T< ValueT > > const & lhs
		, Vec3T< ValueT > const & rhs );
	template< typename ValueT >
	MaybeOptional< Mat3T< ValueT > > operator*( MaybeOptional< Mat3T< ValueT > > const & lhs
		, Mat3T< ValueT > const & rhs );
	template< typename ValueT >
	MaybeOptional< Vec3T< ValueT > > operator*( Vec3T< ValueT > const & lhs,
		MaybeOptional< Mat3T< ValueT > > const & rhs );
	template< typename ValueT >
	MaybeOptional< Vec3T< ValueT > > operator*( Mat3T< ValueT > const & lhs
		, MaybeOptional< Vec3T< ValueT > > const & rhs );
	template< typename ValueT >
	MaybeOptional< Mat3T< ValueT > > operator*( Mat3T< ValueT > const & lhs
		, MaybeOptional< Mat3T< ValueT > > const & rhs );
	template< typename ValueT >
	MaybeOptional< Vec3T< ValueT > > operator*( MaybeOptional< Vec3T< ValueT > > const & lhs,
		MaybeOptional< Mat3T< ValueT > > const & rhs );
	template< typename ValueT >
	MaybeOptional< Vec3T< ValueT > > operator*( MaybeOptional< Mat3T< ValueT > > const & lhs
		, MaybeOptional< Vec3T< ValueT > > const & rhs );
	template< typename ValueT >
	MaybeOptional< Mat3T< ValueT > > operator*( MaybeOptional< Mat3T< ValueT > > const & lhs
		, MaybeOptional< Mat3T< ValueT > > const & rhs );

	template< typename ValueT >
	MaybeOptional< Mat3T< ValueT > > operator*( MaybeOptional< ValueT > const & lhs
		, Mat3T< ValueT > const & rhs );
	template< typename ValueT >
	MaybeOptional< Mat3T< ValueT > > operator*( MaybeOptional< Mat3T< ValueT > > const & lhs
		, ValueT const & rhs );
	template< typename ValueT >
	MaybeOptional< Mat3T< ValueT > > operator*( ValueT const & lhs
		, MaybeOptional< Mat3T< ValueT > > const & rhs );
	template< typename ValueT >
	MaybeOptional< Mat3T< ValueT > > operator*( Mat3T< ValueT > const & lhs
		, MaybeOptional< ValueT > const & rhs );
	template< typename ValueT >
	MaybeOptional< Mat3T< ValueT > > operator*( MaybeOptional< ValueT > const & lhs
		, MaybeOptional< Mat3T< ValueT > > const & rhs );
	template< typename ValueT >
	MaybeOptional< Mat3T< ValueT > > operator*( MaybeOptional< Mat3T< ValueT > > const & lhs
		, MaybeOptional< ValueT > const & rhs );
}

#include "MaybeOptionalMat3.inl"

#endif
