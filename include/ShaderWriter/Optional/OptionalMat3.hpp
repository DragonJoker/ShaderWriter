/*
See LICENSE file in root folder
*/
#ifndef ___SDW_OptionalMat3_H___
#define ___SDW_OptionalMat3_H___
#pragma once

#include "Optional.hpp"
#include "ShaderWriter/MatTypes/Mat3.hpp"

namespace sdw
{
	template< typename ValueT >
	Optional< Vec3T< ValueT > > operator*( Optional< Vec3T< ValueT > > const & lhs,
		Mat3T< ValueT > const & rhs );
	template< typename ValueT >
	Optional< Vec3T< ValueT > > operator*( Optional< Mat3T< ValueT > > const & lhs
		, Vec3T< ValueT > const & rhs );
	template< typename ValueT >
	Optional< Mat3T< ValueT > > operator*( Optional< Mat3T< ValueT > > const & lhs
		, Mat3T< ValueT > const & rhs );
	template< typename ValueT >
	Optional< Vec3T< ValueT > > operator*( Vec3T< ValueT > const & lhs,
		Optional< Mat3T< ValueT > > const & rhs );
	template< typename ValueT >
	Optional< Vec3T< ValueT > > operator*( Mat3T< ValueT > const & lhs
		, Optional< Vec3T< ValueT > > const & rhs );
	template< typename ValueT >
	Optional< Mat3T< ValueT > > operator*( Mat3T< ValueT > const & lhs
		, Optional< Mat3T< ValueT > > const & rhs );
	template< typename ValueT >
	Optional< Vec3T< ValueT > > operator*( Optional< Vec3T< ValueT > > const & lhs,
		Optional< Mat3T< ValueT > > const & rhs );
	template< typename ValueT >
	Optional< Vec3T< ValueT > > operator*( Optional< Mat3T< ValueT > > const & lhs
		, Optional< Vec3T< ValueT > > const & rhs );
	template< typename ValueT >
	Optional< Mat3T< ValueT > > operator*( Optional< Mat3T< ValueT > > const & lhs
		, Optional< Mat3T< ValueT > > const & rhs );
}

#include "OptionalMat3.inl"

#endif
