/*
See LICENSE file in root folder
*/
#ifndef ___SDW_Mat2x3_H___
#define ___SDW_Mat2x3_H___
#pragma once

#include "OptionalVec2.hpp"

namespace sdw
{
	template< typename ValueT >
	struct Mat2x3T
		: public Value
	{
		using ValueType = ValueT;
		using my_vec = Vec2T< ValueT >;
		using my_mat = Mat2x3T< ValueT >;

		inline Mat2x3T( Shader * shader
			, expr::ExprPtr expr );
		inline Mat2x3T( Mat2x3T const & rhs );
		inline Mat2x3T< ValueT > & operator=( Mat2x3T< ValueT > const & rhs );
		template< typename RhsT >
		inline Mat2x3T< ValueT > & operator=( RhsT const & rhs );
		template< typename IndexT >
		inline Vec2T< ValueT > operator[]( IndexT const & rhs )const;
	};
}

#include "Mat2x3.inl"

#endif
