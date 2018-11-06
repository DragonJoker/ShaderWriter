/*
See LICENSE file in root folder
*/
#ifndef ___SDW_Mat4x2_H___
#define ___SDW_Mat4x2_H___
#pragma once

#include "OptionalVec4.hpp"

namespace sdw
{
	template< typename ValueT >
	struct Mat4x2T
		: public Value
	{
		using ValueType = ValueT;
		using my_vec = Vec4T< ValueT >;
		using my_mat = Mat4x2T< ValueT >;

		inline Mat4x2T( Shader * shader
			, expr::ExprPtr expr );
		inline Mat4x2T( Mat4x2T const & rhs );
		inline Mat4x2T< ValueT > & operator=( Mat4x2T< ValueT > const & rhs );
		template< typename RhsT >
		inline Mat4x2T< ValueT > & operator=( RhsT const & rhs );
		template< typename IndexT >
		inline Vec4T< ValueT > operator[]( IndexT const & rhs )const;
	};
}

#include "Mat4x2.inl"

#endif
