/*
See LICENSE file in root folder
*/
#ifndef ___SDW_Mat3x4_H___
#define ___SDW_Mat3x4_H___
#pragma once

#include "OptionalVec3.hpp"

namespace sdw
{
	template< typename ValueT >
	struct Mat3x4T
		: public Value
	{
		using ValueType = ValueT;
		using my_vec = Vec3T< ValueT >;
		using my_mat = Mat3x4T< ValueT >;

		inline Mat3x4T( Shader * shader
			, expr::ExprPtr expr );
		inline Mat3x4T( Mat3x4T const & rhs );
		inline Mat3x4T< ValueT > & operator=( Mat3x4T< ValueT > const & rhs );
		template< typename RhsT >
		inline Mat3x4T< ValueT > & operator=( RhsT const & rhs );
		template< typename IndexT >
		inline Vec3T< ValueT > operator[]( IndexT const & rhs )const;
	};
}

#include "Mat3x4.inl"

#endif
