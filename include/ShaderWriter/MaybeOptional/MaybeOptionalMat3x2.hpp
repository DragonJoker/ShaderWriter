/*
See LICENSE file in root folder
*/
#ifndef ___SDW_MaybeOptionalMat3x2_H___
#define ___SDW_MaybeOptionalMat3x2_H___
#pragma once

#include "MaybeOptional.hpp"
#include "ShaderWriter/Optional/OptionalMat3x2.hpp"

namespace sdw
{
	template< typename ValueT >
	struct MaybeOptional< Mat3x2T< ValueT > >
		: public Mat3x2T< ValueT >
	{
		using MyValue = Mat3x2T< ValueT >;

		using ValueType = ValueT;
		using my_vec = MaybeOptional< Vec2T< ValueT > >;
		using my_mat = MaybeOptional< Mat3x2T< ValueT > >;

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
		inline MaybeOptional< Vec2T< ValueT > > operator[]( IndexT const & rhs )const;

		inline operator MyValue()const;
		inline operator Optional< MyValue >()const;

		inline bool isOptional()const;
		inline bool isEnabled()const;

	private:
		bool m_optional;
		bool m_enabled;
	};
}

#include "MaybeOptionalMat3x2.inl"

#endif
