/*
See LICENSE file in root folder
*/
#ifndef ___SDW_OptionalMat4x2_H___
#define ___SDW_OptionalMat4x2_H___
#pragma once

#include "ShaderWriter/MatTypes/Mat4x2.hpp"

namespace sdw
{
	template< typename ValueT >
	struct Optional< Mat4x2T< ValueT > >
		: public Mat4x2T< ValueT >
	{
		using ValueType = ValueT;
		using my_vec = Optional< Vec2T< ValueT > >;
		using my_mat = Optional< Mat4x2T< ValueT > >;

		inline Optional( Shader * shader
			, expr::ExprPtr expr
			, bool enabled );
		inline Optional( Mat4x2T< ValueT > const & other
			, bool enabled );
		inline Optional( Optional< Mat4x2T< ValueT > > const & rhs );
		inline Optional< Mat4x2T< ValueT > > & operator=( Optional< Mat4x2T< ValueT > > const & rhs );
		template< typename IndexT >
		inline Optional< Vec2T< ValueT > > operator[]( IndexT const & rhs )const;
		inline bool isEnabled()const;

	private:
		bool m_enabled;
	};
}

#include "OptionalMat4x2.inl"

#endif
