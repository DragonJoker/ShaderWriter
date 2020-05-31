/*
See LICENSE file in root folder
*/
#ifndef ___SDW_OptionalMat2x3_H___
#define ___SDW_OptionalMat2x3_H___
#pragma once

#include "Optional.hpp"
#include "ShaderWriter/MatTypes/Mat2x3.hpp"

namespace sdw
{
	template< typename ValueT >
	struct Optional< Mat2x3T< ValueT > >
		: public Mat2x3T< ValueT >
	{
		using MyValue = Mat2x3T< ValueT >;

		using ValueType = ValueT;
		using my_vec = Optional< Vec3T< ValueT > >;
		using my_mat = Optional< Mat2x3T< ValueT > >;

		inline Optional( Shader * shader
			, expr::ExprPtr expr
			, bool enabled );
		inline Optional( Mat2x3T< ValueT > const & other
			, bool enabled );
		inline Optional( Optional< Mat2x3T< ValueT > > const & rhs );

		inline Optional< MyValue > & operator=( MyValue const & rhs );
		inline Optional< MyValue > & operator=( Optional< MyValue > const & rhs );
		inline Optional< MyValue > & operator=( MaybeOptional< MyValue > const & rhs );

		template< typename IndexT >
		inline Optional< Vec3T< ValueT > > operator[]( IndexT const & rhs )const;
		inline bool isEnabled()const;

	private:
		bool m_enabled;
	};
}

#include "OptionalMat2x3.inl"

#endif
