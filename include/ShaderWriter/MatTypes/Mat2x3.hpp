/*
See LICENSE file in root folder
*/
#ifndef ___SDW_Mat2x3_H___
#define ___SDW_Mat2x3_H___
#pragma once

#include "ShaderWriter/VecTypes/Vec3.hpp"

namespace sdw
{
	template< typename ValueT >
	struct Mat2x3T
		: public Value
	{
		using ValueType = ValueT;
		using my_vec = Vec3T< ValueT >;
		using my_mat = Mat2x3T< ValueT >;

		inline Mat2x3T( Shader * shader
			, expr::ExprPtr expr );
		inline Mat2x3T( Mat2x3T const & rhs );

		inline Mat2x3T & operator=( Mat2x3T const & rhs );
		inline Mat2x3T & operator=( Optional< Mat2x3T > const & rhs );
		inline Mat2x3T & operator=( MaybeOptional< Mat2x3T > const & rhs );

		template< typename RhsT >
		inline Mat2x3T< ValueT > & operator=( RhsT const & rhs );
		template< typename IndexT >
		inline Vec3T< ValueT > operator[]( IndexT const & rhs )const;
		inline Vec3T< ValueT > operator[]( int32_t offset )const;
		inline Vec3T< ValueT > operator[]( uint32_t offset )const;

		static inline ast::type::TypePtr makeType( ast::type::TypesCache & cache );
	};
}

#include "Mat2x3.inl"

#endif
