/*
See LICENSE file in root folder
*/
#ifndef ___SDW_Mat3x4_H___
#define ___SDW_Mat3x4_H___
#pragma once

#include "ShaderWriter/Optional/OptionalVec4.hpp"

namespace sdw
{
	template< typename ValueT >
	struct Mat3x4T
		: public Value
	{
		using ValueType = ValueT;
		using my_vec = Vec4T< ValueT >;
		using my_mat = Mat3x4T< ValueT >;

		inline Mat3x4T( Shader * shader
			, expr::ExprPtr expr );
		inline Mat3x4T( Mat3x4T const & rhs );
		inline Mat3x4T< ValueT > & operator=( Mat3x4T< ValueT > const & rhs );
		template< typename RhsT >
		inline Mat3x4T< ValueT > & operator=( RhsT const & rhs );
		template< typename IndexT >
		inline Vec4T< ValueT > operator[]( IndexT const & rhs )const;
		inline Vec4T< ValueT > operator[]( int32_t offset )const;
		inline Vec4T< ValueT > operator[]( uint32_t offset )const;

		static inline ast::type::TypePtr makeType( ast::type::TypesCache & cache );
	};
}

#include "Mat3x4.inl"

#endif
