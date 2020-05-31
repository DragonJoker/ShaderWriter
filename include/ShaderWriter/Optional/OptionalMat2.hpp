/*
See LICENSE file in root folder
*/
#ifndef ___SDW_OptionalMat2_H___
#define ___SDW_OptionalMat2_H___
#pragma once

#include "Optional.hpp"
#include "ShaderWriter/MatTypes/Mat2.hpp"

namespace sdw
{
	template< typename ValueT >
	Optional< Vec2T< ValueT > > operator*( Optional< Vec2T< ValueT > > const & lhs,
		Mat2T< ValueT > const & rhs );
	template< typename ValueT >
	Optional< Vec2T< ValueT > > operator*( Optional< Mat2T< ValueT > > const & lhs
		, Vec2T< ValueT > const & rhs );
	template< typename ValueT >
	Optional< Mat2T< ValueT > > operator*( Optional< Mat2T< ValueT > > const & lhs
		, Mat2T< ValueT > const & rhs );
	template< typename ValueT >
	Optional< Vec2T< ValueT > > operator*( Vec2T< ValueT > const & lhs,
		Optional< Mat2T< ValueT > > const & rhs );
	template< typename ValueT >
	Optional< Vec2T< ValueT > > operator*( Mat2T< ValueT > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs );
	template< typename ValueT >
	Optional< Mat2T< ValueT > > operator*( Mat2T< ValueT > const & lhs
		, Optional< Mat2T< ValueT > > const & rhs );
	template< typename ValueT >
	Optional< Vec2T< ValueT > > operator*( Optional< Vec2T< ValueT > > const & lhs,
		Optional< Mat2T< ValueT > > const & rhs );
	template< typename ValueT >
	Optional< Vec2T< ValueT > > operator*( Optional< Mat2T< ValueT > > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs );
	template< typename ValueT >
	Optional< Mat2T< ValueT > > operator*( Optional< Mat2T< ValueT > > const & lhs
		, Optional< Mat2T< ValueT > > const & rhs );
}

#include "OptionalMat2.inl"

#endif
