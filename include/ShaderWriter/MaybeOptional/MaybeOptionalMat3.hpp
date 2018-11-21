/*
See LICENSE file in root folder
*/
#ifndef ___SDW_MaybeOptionalMat3_H___
#define ___SDW_MaybeOptionalMat3_H___
#pragma once

#include "ShaderWriter/Optional/OptionalMat3.hpp"

namespace sdw
{
	template< typename ValueT >
	struct MaybeOptional< Mat3T< ValueT > >
		: public Mat3T< ValueT >
	{
		using MyValue = Mat3T< ValueT >;

		using ValueType = ValueT;
		using my_vec = MaybeOptional< Vec3T< ValueT > >;
		using my_mat = MaybeOptional< Mat3T< ValueT > >;

		inline MaybeOptional( Shader * shader
			, expr::ExprPtr expr );
		inline MaybeOptional( Shader * shader
			, expr::ExprPtr expr
			, bool enabled );
		inline MaybeOptional( MyValue const & rhs );
		inline MaybeOptional( Optional< MyValue > const & rhs );
		inline MaybeOptional( MaybeOptional< MyValue > const & rhs );

		inline MaybeOptional< Mat3T< ValueT > > & operator=( MaybeOptional< Mat3T< ValueT > > const & rhs );
		template< typename IndexT >
		inline MaybeOptional< Vec3T< ValueT > > operator[]( IndexT const & rhs )const;

		inline operator MyValue()const;
		inline operator Optional< MyValue >()const;

		inline bool isOptional()const;
		inline bool isEnabled()const;

	private:
		bool m_optional;
		bool m_enabled;
	};

	template< typename ValueT >
	MaybeOptional< Vec3T< ValueT > > operator*( MaybeOptional< Vec3T< ValueT > > const & lhs,
		Mat3T< ValueT > const & rhs );
	template< typename ValueT >
	MaybeOptional< Vec3T< ValueT > > operator*( MaybeOptional< Mat3T< ValueT > > const & lhs
		, Vec3T< ValueT > const & rhs );
	template< typename ValueT >
	MaybeOptional< Mat3T< ValueT > > operator*( MaybeOptional< Mat3T< ValueT > > const & lhs
		, Mat3T< ValueT > const & rhs );
	template< typename ValueT >
	MaybeOptional< Vec3T< ValueT > > operator*( Vec3T< ValueT > const & lhs,
		MaybeOptional< Mat3T< ValueT > > const & rhs );
	template< typename ValueT >
	MaybeOptional< Vec3T< ValueT > > operator*( Mat3T< ValueT > const & lhs
		, MaybeOptional< Vec3T< ValueT > > const & rhs );
	template< typename ValueT >
	MaybeOptional< Mat3T< ValueT > > operator*( Mat3T< ValueT > const & lhs
		, MaybeOptional< Mat3T< ValueT > > const & rhs );
	template< typename ValueT >
	MaybeOptional< Vec3T< ValueT > > operator*( MaybeOptional< Vec3T< ValueT > > const & lhs,
		MaybeOptional< Mat3T< ValueT > > const & rhs );
	template< typename ValueT >
	MaybeOptional< Vec3T< ValueT > > operator*( MaybeOptional< Mat3T< ValueT > > const & lhs
		, MaybeOptional< Vec3T< ValueT > > const & rhs );
	template< typename ValueT >
	MaybeOptional< Mat3T< ValueT > > operator*( MaybeOptional< Mat3T< ValueT > > const & lhs
		, MaybeOptional< Mat3T< ValueT > > const & rhs );
}

#include "MaybeOptionalMat3.inl"

#endif
