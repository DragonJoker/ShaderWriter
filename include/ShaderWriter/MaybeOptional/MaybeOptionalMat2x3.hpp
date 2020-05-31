/*
See LICENSE file in root folder
*/
#ifndef ___SDW_MaybeOptionalMat2x3_H___
#define ___SDW_MaybeOptionalMat2x3_H___
#pragma once

#include "MaybeOptional.hpp"
#include "ShaderWriter/Optional/OptionalMat2x3.hpp"

namespace sdw
{
	template< typename ValueT >
	struct MaybeOptional< Mat2x3T< ValueT > >
		: public Mat2x3T< ValueT >
	{
		using MyValue = Mat2x3T< ValueT >;

		using ValueType = ValueT;
		using my_vec = MaybeOptional< Vec3T< ValueT > >;
		using my_mat = MaybeOptional< Mat2x3T< ValueT > >;

		inline MaybeOptional( Shader * shader
			, expr::ExprPtr expr );
		inline MaybeOptional( Shader * shader
			, expr::ExprPtr expr
			, bool enabled );
		inline MaybeOptional( MyValue const & rhs );
		inline MaybeOptional( Optional< MyValue > const & rhs );
		inline MaybeOptional( MaybeOptional< MyValue > const & rhs );

		inline MaybeOptional< MyValue > & operator=( MyValue const & rhs );
		inline MaybeOptional< MyValue > & operator=( Optional< MyValue > const & rhs );
		inline MaybeOptional< MyValue > & operator=( MaybeOptional< MyValue > const & rhs );

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
}

#include "MaybeOptionalMat2x3.inl"

#endif
