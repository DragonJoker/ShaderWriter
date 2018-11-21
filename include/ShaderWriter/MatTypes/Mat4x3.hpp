/*
See LICENSE file in root folder
*/
#ifndef ___SDW_Mat4x3_H___
#define ___SDW_Mat4x3_H___
#pragma once

#include "ShaderWriter/Optional/OptionalVec4.hpp"

namespace sdw
{
	template< typename ValueT >
	struct Mat4x3T
		: public Value
	{
		using ValueType = ValueT;
		using my_vec = Vec4T< ValueT >;
		using my_mat = Mat4x3T< ValueT >;

		inline Mat4x3T( Shader * shader
			, expr::ExprPtr expr );
		inline Mat4x3T( Mat4x3T const & rhs );
		inline Mat4x3T< ValueT > & operator=( Mat4x3T< ValueT > const & rhs );
		template< typename RhsT >
		inline Mat4x3T< ValueT > & operator=( RhsT const & rhs );
		template< typename IndexT >
		inline Vec4T< ValueT > operator[]( IndexT const & rhs )const;
	};
	template< typename ValueT >
	Vec4T< ValueT > operator*( Vec4T< ValueT > const & lhs,
		Mat4x3T< ValueT > const & rhs );
	template< typename ValueT >
	Vec4T< ValueT > operator*( Mat4x3T< ValueT > const & lhs
		, Vec4T< ValueT > const & rhs );
}

#include "Mat4x3.inl"

#endif
