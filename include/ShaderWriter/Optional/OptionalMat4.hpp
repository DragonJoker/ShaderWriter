/*
See LICENSE file in root folder
*/
#ifndef ___SDW_OptionalMat4_H___
#define ___SDW_OptionalMat4_H___
#pragma once

#include "Optional.hpp"
#include "ShaderWriter/MatTypes/Mat4.hpp"

namespace sdw
{
	template< typename ValueT >
	Optional< Vec4T< ValueT > > operator*( Optional< Vec4T< ValueT > > const & lhs,
		Mat4T< ValueT > const & rhs );
	template< typename ValueT >
	Optional< Vec4T< ValueT > > operator*( Optional< Mat4T< ValueT > > const & lhs
		, Vec4T< ValueT > const & rhs );
	template< typename ValueT >
	Optional< Mat4T< ValueT > > operator*( Optional< Mat4T< ValueT > > const & lhs
		, Mat4T< ValueT > const & rhs );
	template< typename ValueT >
	Optional< Vec4T< ValueT > > operator*( Vec4T< ValueT > const & lhs,
		Optional< Mat4T< ValueT > > const & rhs );
	template< typename ValueT >
	Optional< Vec4T< ValueT > > operator*( Mat4T< ValueT > const & lhs
		, Optional< Vec4T< ValueT > > const & rhs );
	template< typename ValueT >
	Optional< Mat4T< ValueT > > operator*( Mat4T< ValueT > const & lhs
		, Optional< Mat4T< ValueT > > const & rhs );
	template< typename ValueT >
	Optional< Vec4T< ValueT > > operator*( Optional< Vec4T< ValueT > > const & lhs,
		Optional< Mat4T< ValueT > > const & rhs );
	template< typename ValueT >
	Optional< Vec4T< ValueT > > operator*( Optional< Mat4T< ValueT > > const & lhs
		, Optional< Vec4T< ValueT > > const & rhs );
	template< typename ValueT >
	Optional< Mat4T< ValueT > > operator*( Optional< Mat4T< ValueT > > const & lhs
		, Optional< Mat4T< ValueT > > const & rhs );
}

#include "OptionalMat4.inl"

#endif
