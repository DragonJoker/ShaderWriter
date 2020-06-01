/*
See LICENSE file in root folder
*/
#ifndef ___SDW_Mat4x3_H___
#define ___SDW_Mat4x3_H___
#pragma once

#include "ShaderWriter/VecTypes/Vec3.hpp"

namespace sdw
{
	template< typename ValueT >
	struct Mat4x3T
		: public Value
	{
		using ValueType = ValueT;
		using my_vec = Vec3T< ValueT >;
		using my_mat = Mat4x3T< ValueT >;

		inline Mat4x3T( Shader * shader
			, expr::ExprPtr expr );
		inline Mat4x3T( Mat4x3T const & rhs );

		inline Mat4x3T & operator=( Mat4x3T const & rhs );
		inline Mat4x3T & operator=( Optional< Mat4x3T > const & rhs );
		inline Mat4x3T & operator=( MaybeOptional< Mat4x3T > const & rhs );

		template< typename RhsT >
		inline Mat4x3T< ValueT > & operator=( RhsT const & rhs );
		template< typename IndexT >
		inline Vec3T< ValueT > operator[]( IndexT const & rhs )const;
		inline Vec3T< ValueT > operator[]( int32_t offset )const;
		inline Vec3T< ValueT > operator[]( uint32_t offset )const;

		static inline ast::type::TypePtr makeType( ast::type::TypesCache & cache );
	};
}

#include "Mat4x3.inl"

#endif
