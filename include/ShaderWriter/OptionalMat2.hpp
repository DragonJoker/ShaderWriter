/*
See LICENSE file in root folder
*/
#ifndef ___Writer_OptionalMat2_H___
#define ___Writer_OptionalMat2_H___
#pragma once

#include "Mat2.hpp"
#include "Optional.hpp"

namespace sdw
{
	template< typename ValueT >
	struct Optional< Mat2T< ValueT > >
		: public Mat2T< ValueT >
	{
		using ValueType = ValueT;
		using my_vec = Optional< Vec2T< ValueT > >;
		using my_mat = Optional< Mat2T< ValueT > >;

		inline Optional( Shader * shader
			, expr::ExprPtr expr
			, bool enabled );
		inline Optional( Mat2T< ValueT > const & other
			, bool enabled );
		inline Optional< Mat2T< ValueT > > & operator=( Optional< Mat2T< ValueT > > const & rhs );
		template< typename IndexT >
		inline Optional< Vec2T< ValueT > > operator[]( IndexT const & rhs )const;
		inline bool isEnabled()const;

	private:
		bool m_enabled;
	};

	template< typename ValueT >
	Optional< Vec2T< ValueT > > operator*( Optional< Vec2T< ValueT > > const & lhs,
		Mat2T< ValueT > const & rhs );
	template< typename ValueT >
	Optional< Vec2T< ValueT > > operator*( Optional< Mat2T< ValueT > > const & lhs
		, Vec2T< ValueT > const & rhs );
	template< typename ValueT >
	Optional< Vec2T< ValueT > > operator*( Vec2T< ValueT > const & lhs,
		Optional< Mat2T< ValueT > > const & rhs );
	template< typename ValueT >
	Optional< Vec2T< ValueT > > operator*( Mat2T< ValueT > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs );
	template< typename ValueT >
	Optional< Vec2T< ValueT > > operator*( Optional< Vec2T< ValueT > > const & lhs,
		Optional< Mat2T< ValueT > > const & rhs );
	template< typename ValueT >
	Optional< Vec2T< ValueT > > operator*( Optional< Mat2T< ValueT > > const & lhs
		, Optional< Vec2T< ValueT > > const & rhs );
}

#include "OptionalMat2.inl"

#endif
