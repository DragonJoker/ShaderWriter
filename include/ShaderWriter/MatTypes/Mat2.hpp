/*
See LICENSE file in root folder
*/
#ifndef ___SDW_Mat2_H___
#define ___SDW_Mat2_H___
#pragma once

#include "ShaderWriter/VecTypes/Vec2.hpp"

namespace sdw
{
	template< typename ValueT >
	struct Mat2T
		: public Value
	{
		using ValueType = ValueT;
		using my_vec = Vec2T< ValueT >;
		using my_mat = Mat2T< ValueT >;

		inline Mat2T( ShaderWriter & writer
			, expr::ExprPtr expr
			, bool enabled );
		inline Mat2T( Mat2T const & rhs );

		inline Mat2T & operator=( Mat2T const & rhs );

		template< typename RhsT >
		inline Mat2T< ValueT > & operator=( RhsT const & rhs );
		template< typename IndexT >
		inline Vec2T< ValueT > operator[]( IndexT const & rhs )const;
		inline Vec2T< ValueT > operator[]( int32_t offset )const;
		inline Vec2T< ValueT > operator[]( uint32_t offset )const;
		inline Mat2T< ValueT > & operator+=( Mat2T< ValueT > const & rhs );

		static inline ast::type::TypePtr makeType( ast::type::TypesCache & cache );
	};
	template< typename ValueT >
	Vec2T< ValueT > operator*( Vec2T< ValueT > const & lhs
		, Mat2T< ValueT > const & rhs );
	template< typename ValueT >
	Vec2T< ValueT > operator*( Mat2T< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs );
	template< typename ValueT >
	Mat2T< ValueT > operator*( Mat2T< ValueT > const & lhs
		, Mat2T< ValueT > const & rhs );

	template< typename ValueT >
	Mat2T< ValueT > operator*( ValueT const & lhs
		, Mat2T< ValueT > const & rhs );
	template< typename ValueT >
	Mat2T< ValueT > operator*( Mat2T< ValueT > const & lhs
		, ValueT const & rhs );
}

#include "Mat2.inl"

#endif
