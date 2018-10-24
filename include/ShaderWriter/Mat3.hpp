/*
See LICENSE file in root folder
*/
#ifndef ___SDW_Mat3_H___
#define ___SDW_Mat3_H___
#pragma once

#include "OptionalVec3.hpp"

namespace sdw
{
	template< typename ValueT >
	struct Mat3T
		: public Value
	{
		using ValueType = ValueT;
		using my_vec = Vec3T< ValueT >;
		using my_mat = Mat3T< ValueT >;

		inline Mat3T( Shader * shader
			, expr::ExprPtr expr );
		inline Mat3T< ValueT > & operator=( Mat3T< ValueT > const & rhs );
		template< typename RhsT >
		inline Mat3T< ValueT > & operator=( RhsT const & rhs );
		template< typename IndexT >
		inline Vec3T< ValueT > operator[]( IndexT const & rhs )const;
	};
	template< typename ValueT >
	Vec3T< ValueT > operator*( Vec3T< ValueT > const & lhs,
		Mat3T< ValueT > const & rhs );
	template< typename ValueT >
	Vec3T< ValueT > operator*( Mat3T< ValueT > const & lhs
		, Vec3T< ValueT > const & rhs );
	template< typename ValueT >
	Mat3T< ValueT > operator*( Mat3T< ValueT > const & lhs
		, Mat3T< ValueT > const & rhs );
}

#include "Mat3.inl"

#endif
