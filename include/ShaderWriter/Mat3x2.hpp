/*
See LICENSE file in root folder
*/
#ifndef ___Writer_Mat3x2_H___
#define ___Writer_Mat3x2_H___
#pragma once

#include "OptionalVec3.hpp"

namespace sdw
{
	template< typename ValueT >
	struct Mat3x2T
		: public Value
	{
		using ValueType = ValueT;
		using my_vec = Vec3T< ValueT >;
		using my_mat = Mat3x2T< ValueT >;

		inline Mat3x2T( Shader * shader
			, expr::ExprPtr expr );
		inline Mat3x2T< ValueT > & operator=( Mat3x2T< ValueT > const & rhs );
		template< typename RhsT >
		inline Mat3x2T< ValueT > & operator=( RhsT const & rhs );
		template< typename IndexT >
		inline Vec3T< ValueT > operator[]( IndexT const & rhs )const;
	};
}

#include "Mat3x2.inl"

#endif
