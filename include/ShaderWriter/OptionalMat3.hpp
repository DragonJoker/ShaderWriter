/*
See LICENSE file in root folder
*/
#ifndef ___Writer_OptionalMat3_H___
#define ___Writer_OptionalMat3_H___
#pragma once

#include "Mat3.hpp"
#include "Optional.hpp"

namespace sdw
{
	template< typename ValueT >
	struct Optional< Mat3T< ValueT > >
		: public Mat3T< ValueT >
	{
		using ValueType = ValueT;
		using my_vec = Optional< Vec3T< ValueT > >;
		using my_mat = Optional< Mat3T< ValueT > >;

		inline Optional( Shader * shader
			, expr::ExprPtr expr
			, bool enabled );
		inline Optional( Mat3T< ValueT > const & other
			, bool enabled );
		inline Optional< Mat3T< ValueT > > & operator=( Optional< Mat3T< ValueT > > const & rhs );
		template< typename IndexT >
		inline Optional< Vec3T< ValueT > > operator[]( IndexT const & rhs )const;
		inline bool isEnabled()const;

	private:
		bool m_enabled;
	};

	template< typename ValueT >
	Optional< Vec3T< ValueT > > operator*( Optional< Vec3T< ValueT > > const & lhs,
		Mat3T< ValueT > const & rhs );
	template< typename ValueT >
	Optional< Vec3T< ValueT > > operator*( Optional< Mat3T< ValueT > > const & lhs
		, Vec3T< ValueT > const & rhs );
	template< typename ValueT >
	Optional< Vec3T< ValueT > > operator*( Vec3T< ValueT > const & lhs,
		Optional< Mat3T< ValueT > > const & rhs );
	template< typename ValueT >
	Optional< Vec3T< ValueT > > operator*( Mat3T< ValueT > const & lhs
		, Optional< Vec3T< ValueT > > const & rhs );
	template< typename ValueT >
	Optional< Vec3T< ValueT > > operator*( Optional< Vec3T< ValueT > > const & lhs,
		Optional< Mat3T< ValueT > > const & rhs );
	template< typename ValueT >
	Optional< Vec3T< ValueT > > operator*( Optional< Mat3T< ValueT > > const & lhs
		, Optional< Vec3T< ValueT > > const & rhs );
}

#include "OptionalMat3.inl"

#endif
