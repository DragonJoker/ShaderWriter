/*
See LICENSE file in root folder
*/
#ifndef ___SDW_OptionalMat2x4_H___
#define ___SDW_OptionalMat2x4_H___
#pragma once

#include "Mat2x4.hpp"

namespace sdw
{
	template< typename ValueT >
	struct Optional< Mat2x4T< ValueT > >
		: public Mat2x4T< ValueT >
	{
		using ValueType = ValueT;
		using my_vec = Optional< Vec2T< ValueT > >;
		using my_mat = Optional< Mat2x4T< ValueT > >;

		inline Optional( Shader * shader
			, expr::ExprPtr expr
			, bool enabled );
		inline Optional( Mat2x4T< ValueT > const & other
			, bool enabled );
		inline Optional< Mat2x4T< ValueT > > & operator=( Optional< Mat2x4T< ValueT > > const & rhs );
		template< typename IndexT >
		inline Optional< Vec2T< ValueT > > operator[]( IndexT const & rhs )const;
		inline bool isEnabled()const;

	private:
		bool m_enabled;
	};
}

#include "OptionalMat2x4.inl"

#endif
