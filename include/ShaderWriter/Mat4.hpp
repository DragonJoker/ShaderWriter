/*
See LICENSE file in root folder
*/
#ifndef ___Writer_Mat4_H___
#define ___Writer_Mat4_H___
#pragma once

#include "OptionalVec4.hpp"

namespace sdw
{
	template< typename ValueT >
	struct Mat4T
		: public Value
	{
		using ValueType = ValueT;
		using my_vec = Vec4T< ValueT >;
		using my_mat = Mat4T< ValueT >;

		inline Mat4T( Shader * shader
			, expr::ExprPtr expr );
		inline Mat4T< ValueT > & operator=( Mat4T< ValueT > const & rhs );
		template< typename RhsT >
		inline Mat4T< ValueT > & operator=( RhsT const & rhs );
		template< typename IndexT >
		inline Vec4T< ValueT > operator[]( IndexT const & rhs )const;
	};
	template< typename ValueT >
	Vec4T< ValueT > operator*( Vec4T< ValueT > const & lhs,
		Mat4T< ValueT > const & rhs );
	template< typename ValueT >
	Vec4T< ValueT > operator*( Mat4T< ValueT > const & lhs
		, Vec4T< ValueT > const & rhs );
}

#include "Mat4.inl"

#endif
