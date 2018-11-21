/*
See LICENSE file in root folder
*/
#ifndef ___SDW_Mat3x2_H___
#define ___SDW_Mat3x2_H___
#pragma once

#include "ShaderWriter/Optional/OptionalVec3.hpp"

namespace sdw
{
	template< typename ValueT >
	struct Mat3x2T
		: public Value
	{
		using ValueType = ValueT;
		using my_vec = Vec2T< ValueT >;
		using my_mat = Mat3x2T< ValueT >;

		inline Mat3x2T( Shader * shader
			, expr::ExprPtr expr );
		inline Mat3x2T( Mat3x2T const & rhs );
		inline Mat3x2T< ValueT > & operator=( Mat3x2T< ValueT > const & rhs );
		template< typename RhsT >
		inline Mat3x2T< ValueT > & operator=( RhsT const & rhs );
		template< typename IndexT >
		inline Vec2T< ValueT > operator[]( IndexT const & rhs )const;
	};
}

#include "Mat3x2.inl"

#endif
