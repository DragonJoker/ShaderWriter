/*
See LICENSE file in root folder
*/
#ifndef ___SDW_MaybeOptionalMat4_H___
#define ___SDW_MaybeOptionalMat4_H___
#pragma once

#include "ShaderWriter/Optional/OptionalMat4.hpp"

namespace sdw
{
	template< typename ValueT >
	struct MaybeOptional< Mat4T< ValueT > >
		: public Mat4T< ValueT >
	{
		using MyValue = Mat4T< ValueT >;

		using ValueType = ValueT;
		using my_vec = MaybeOptional< Vec4T< ValueT > >;
		using my_mat = MaybeOptional< Mat4T< ValueT > >;

		inline MaybeOptional( Shader * shader
			, expr::ExprPtr expr );
		inline MaybeOptional( Shader * shader
			, expr::ExprPtr expr
			, bool enabled );
		inline MaybeOptional( MyValue const & rhs );
		inline MaybeOptional( Optional< MyValue > const & rhs );
		inline MaybeOptional( MaybeOptional< MyValue > const & rhs );

		inline MaybeOptional< Mat4T< ValueT > > & operator=( MaybeOptional< Mat4T< ValueT > > const & rhs );
		template< typename IndexT >
		inline MaybeOptional< Vec4T< ValueT > > operator[]( IndexT const & rhs )const;

		inline operator MyValue()const;
		inline operator Optional< MyValue >()const;

		inline bool isOptional()const;
		inline bool isEnabled()const;

	private:
		bool m_optional;
		bool m_enabled;
	};

	template< typename ValueT >
	MaybeOptional< Vec4T< ValueT > > operator*( MaybeOptional< Vec4T< ValueT > > const & lhs,
		Mat4T< ValueT > const & rhs );
	template< typename ValueT >
	MaybeOptional< Vec4T< ValueT > > operator*( MaybeOptional< Mat4T< ValueT > > const & lhs
		, Vec4T< ValueT > const & rhs );
	template< typename ValueT >
	MaybeOptional< Mat4T< ValueT > > operator*( MaybeOptional< Mat4T< ValueT > > const & lhs
		, Mat4T< ValueT > const & rhs );
	template< typename ValueT >
	MaybeOptional< Vec4T< ValueT > > operator*( Vec4T< ValueT > const & lhs,
		MaybeOptional< Mat4T< ValueT > > const & rhs );
	template< typename ValueT >
	MaybeOptional< Vec4T< ValueT > > operator*( Mat4T< ValueT > const & lhs
		, MaybeOptional< Vec4T< ValueT > > const & rhs );
	template< typename ValueT >
	MaybeOptional< Mat4T< ValueT > > operator*( Mat4T< ValueT > const & lhs
		, MaybeOptional< Mat4T< ValueT > > const & rhs );
	template< typename ValueT >
	MaybeOptional< Vec4T< ValueT > > operator*( MaybeOptional< Vec4T< ValueT > > const & lhs,
		MaybeOptional< Mat4T< ValueT > > const & rhs );
	template< typename ValueT >
	MaybeOptional< Vec4T< ValueT > > operator*( MaybeOptional< Mat4T< ValueT > > const & lhs
		, MaybeOptional< Vec4T< ValueT > > const & rhs );
	template< typename ValueT >
	MaybeOptional< Mat4T< ValueT > > operator*( MaybeOptional< Mat4T< ValueT > > const & lhs
		, MaybeOptional< Mat4T< ValueT > > const & rhs );
}

#include "MaybeOptionalMat4.inl"

#endif
