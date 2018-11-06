/*
See LICENSE file in root folder
*/
#ifndef ___SDW_OptionalMat4x3_H___
#define ___SDW_OptionalMat4x3_H___
#pragma once

#include "Mat4x3.hpp"

namespace sdw
{
	template< typename ValueT >
	struct Optional< Mat4x3T< ValueT > >
		: public Mat4x3T< ValueT >
	{
		using ValueType = ValueT;
		using my_vec = Optional< Vec4T< ValueT > >;
		using my_mat = Optional< Mat4x3T< ValueT > >;

		inline Optional( Shader * shader
			, expr::ExprPtr expr
			, bool enabled );
		inline Optional( Mat4x3T< ValueT > const & other
			, bool enabled );
		inline Optional( Optional< Mat4x3T< ValueT > > const & rhs );
		inline Optional< Mat4x3T< ValueT > > & operator=( Optional< Mat4x3T< ValueT > > const & rhs );
		template< typename IndexT >
		inline Optional< Vec4T< ValueT > > operator[]( IndexT const & rhs )const;
		inline bool isEnabled()const;

	private:
		bool m_enabled;
	};
}

#include "OptionalMat4x3.inl"

#endif
