/*
See LICENSE file in root folder
*/
#ifndef ___SDW_OptionalMat4_H___
#define ___SDW_OptionalMat4_H___
#pragma once

#include "ShaderWriter/MatTypes/Mat4.hpp"

namespace sdw
{
	template< typename ValueT >
	struct Optional< Mat4T< ValueT > >
		: public Mat4T< ValueT >
	{
		using MyValue = Mat4T< ValueT >;

		using ValueType = ValueT;
		using my_vec = Optional< Vec4T< ValueT > >;
		using my_mat = Optional< Mat4T< ValueT > >;

		inline Optional( Shader * shader
			, expr::ExprPtr expr
			, bool enabled );
		inline Optional( Mat4T< ValueT > const & other
			, bool enabled );
		inline Optional( Optional< Mat4T< ValueT > > const & rhs );

		inline Optional< MyValue > & operator=( MyValue const & rhs );
		inline Optional< MyValue > & operator=( Optional< MyValue > const & rhs );
		inline Optional< MyValue > & operator=( MaybeOptional< MyValue > const & rhs );

		template< typename IndexT >
		inline Optional< Vec4T< ValueT > > operator[]( IndexT const & rhs )const;
		inline bool isEnabled()const;

	private:
		bool m_enabled;
	};

	template< typename ValueT >
	Optional< Vec4T< ValueT > > operator*( Optional< Vec4T< ValueT > > const & lhs,
		Mat4T< ValueT > const & rhs );
	template< typename ValueT >
	Optional< Vec4T< ValueT > > operator*( Optional< Mat4T< ValueT > > const & lhs
		, Vec4T< ValueT > const & rhs );
	template< typename ValueT >
	Optional< Mat4T< ValueT > > operator*( Optional< Mat4T< ValueT > > const & lhs
		, Mat4T< ValueT > const & rhs );
	template< typename ValueT >
	Optional< Vec4T< ValueT > > operator*( Vec4T< ValueT > const & lhs,
		Optional< Mat4T< ValueT > > const & rhs );
	template< typename ValueT >
	Optional< Vec4T< ValueT > > operator*( Mat4T< ValueT > const & lhs
		, Optional< Vec4T< ValueT > > const & rhs );
	template< typename ValueT >
	Optional< Mat4T< ValueT > > operator*( Mat4T< ValueT > const & lhs
		, Optional< Mat4T< ValueT > > const & rhs );
	template< typename ValueT >
	Optional< Vec4T< ValueT > > operator*( Optional< Vec4T< ValueT > > const & lhs,
		Optional< Mat4T< ValueT > > const & rhs );
	template< typename ValueT >
	Optional< Vec4T< ValueT > > operator*( Optional< Mat4T< ValueT > > const & lhs
		, Optional< Vec4T< ValueT > > const & rhs );
	template< typename ValueT >
	Optional< Mat4T< ValueT > > operator*( Optional< Mat4T< ValueT > > const & lhs
		, Optional< Mat4T< ValueT > > const & rhs );
}

#include "OptionalMat4.inl"

#endif
