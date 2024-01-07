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
	struct Mat2x2T
		: public Value
	{
		SDW_DeclValue( , Mat2x2T );

		using ValueType = ValueT;
		using my_vec = Vec2T< ValueT >;
		using my_mat = Mat2x2T< ValueT >;

		Mat2x2T( ShaderWriter & writer
			, expr::ExprPtr expr
			, bool enabled );

		template< typename RhsT >
		Mat2x2T< ValueT > & operator=( RhsT const & rhs );
		template< typename IndexT >
		Vec2T< ValueT > operator[]( IndexT const & rhs )const;
		Vec2T< ValueT > operator[]( int32_t offset )const;
		Vec2T< ValueT > operator[]( uint32_t offset )const;
		Mat2x2T< ValueT > & operator+=( Mat2x2T< ValueT > const & rhs );

		static ast::type::TypePtr makeType( ast::type::TypesCache & cache );
	};
	template< typename ValueT >
	Vec2T< ValueT > operator*( Vec2T< ValueT > const & lhs
		, Mat2x2T< ValueT > const & rhs );
	template< typename ValueT >
	Vec2T< ValueT > operator*( Mat2x2T< ValueT > const & lhs
		, Vec2T< ValueT > const & rhs );
	template< typename ValueT >
	Mat2x2T< ValueT > operator*( Mat2x2T< ValueT > const & lhs
		, Mat2x2T< ValueT > const & rhs );

	template< typename ValueT >
	Mat2x2T< ValueT > operator*( ValueT const & lhs
		, Mat2x2T< ValueT > const & rhs );
	template< typename ValueT >
	Mat2x2T< ValueT > operator*( Mat2x2T< ValueT > const & lhs
		, ValueT const & rhs );
}

#include "Mat2.inl"

#endif
