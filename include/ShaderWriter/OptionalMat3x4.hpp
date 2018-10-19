/*
See LICENSE file in root folder
*/
#ifndef ___Writer_OptionalMat3x4_H___
#define ___Writer_OptionalMat3x4_H___
#pragma once

#include "Mat3x4.hpp"

namespace sdw
{
	template< typename ValueT >
	struct Optional< Mat3x4T< ValueT > >
		: public Mat3x4T< ValueT >
	{
		using ValueType = ValueT;
		using my_vec = Optional< Vec3T< ValueT > >;
		using my_mat = Optional< Mat3x4T< ValueT > >;

		inline Optional( Shader * shader
			, expr::ExprPtr expr
			, bool enabled );
		inline Optional( Mat3x4T< ValueT > const & other
			, bool enabled );
		inline Optional< Mat3x4T< ValueT > > & operator=( Optional< Mat3x4T< ValueT > > const & rhs );
		template< typename IndexT >
		inline Optional< Vec3T< ValueT > > operator[]( IndexT const & rhs )const;
		inline bool isEnabled()const;

	private:
		bool m_enabled;
	};
}

#include "OptionalMat3x4.inl"

#endif
