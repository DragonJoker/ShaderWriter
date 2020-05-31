/*
See LICENSE file in root folder
*/
#ifndef ___SDW_OptionalMat2x4_H___
#define ___SDW_OptionalMat2x4_H___
#pragma once

#include "ShaderWriter/MatTypes/Mat2x4.hpp"

namespace sdw
{
	template< typename ValueT >
	struct Optional< Mat2x4T< ValueT > >
		: public Mat2x4T< ValueT >
	{
		using MyValue = Mat2x4T< ValueT >;

		using ValueType = ValueT;
		using my_vec = Optional< Vec4T< ValueT > >;
		using my_mat = Optional< Mat2x4T< ValueT > >;

		inline Optional( Shader * shader
			, expr::ExprPtr expr
			, bool enabled );
		inline Optional( Mat2x4T< ValueT > const & other
			, bool enabled );
		inline Optional( Optional< Mat2x4T< ValueT > > const & rhs );

		inline Optional< MyValue > & operator=( MyValue const & rhs );
		inline Optional< MyValue > & operator=( Optional< MyValue > const & rhs );
		inline Optional< MyValue > & operator=( MaybeOptional< MyValue > const & rhs );

		template< typename IndexT >
		inline Optional< Vec4T< ValueT > > operator[]( IndexT const & rhs )const;
		inline bool isEnabled()const;

	private:
		bool m_enabled;
	};
}

#include "OptionalMat2x4.inl"

#endif
