/*
See LICENSE file in root folder
*/
#ifndef ___SDW_Mat4x2_H___
#define ___SDW_Mat4x2_H___
#pragma once

#include "ShaderWriter/VecTypes/Vec2.hpp"

namespace sdw
{
	template< typename ValueT >
	struct Mat4x2T
		: public Value
	{
		SDW_DeclValue( , Mat4x2T );

		using ValueType = ValueT;
		using my_vec = Vec2T< ValueT >;
		using my_mat = Mat4x2T< ValueT >;

		inline Mat4x2T( ShaderWriter & writer
			, expr::ExprPtr expr
			, bool enabled );

		template< typename RhsT >
		inline Mat4x2T< ValueT > & operator=( RhsT const & rhs );
		template< typename IndexT >
		inline Vec2T< ValueT > operator[]( IndexT const & rhs )const;
		inline Vec2T< ValueT > operator[]( int32_t offset )const;
		inline Vec2T< ValueT > operator[]( uint32_t offset )const;

		static inline ast::type::TypePtr makeType( ast::type::TypesCache & cache );
	};
}

#include "Mat4x2.inl"

#endif
