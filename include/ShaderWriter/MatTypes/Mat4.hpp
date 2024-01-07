/*
See LICENSE file in root folder
*/
#ifndef ___SDW_Mat4_H___
#define ___SDW_Mat4_H___
#pragma once

#include "ShaderWriter/VecTypes/Vec4.hpp"

namespace sdw
{
	template< typename ValueT >
	struct Mat4x4T
		: public Value
	{
		SDW_DeclValue( , Mat4x4T );

		using ValueType = ValueT;
		using my_vec = Vec4T< ValueT >;
		using my_mat = Mat4x4T< ValueT >;

		Mat4x4T( ShaderWriter & writer
			, expr::ExprPtr expr
			, bool enabled );

		template< typename RhsT >
		Mat4x4T< ValueT > & operator=( RhsT const & rhs );
		template< typename IndexT >
		Vec4T< ValueT > operator[]( IndexT const & rhs )const;
		Vec4T< ValueT > operator[]( int32_t offset )const;
		Vec4T< ValueT > operator[]( uint32_t offset )const;
		Mat4x4T< ValueT > & operator+=( Mat4x4T< ValueT > const & rhs );

		static ast::type::TypePtr makeType( ast::type::TypesCache & cache );
	};

	template< typename ValueT >
	Vec4T< ValueT > operator*( Vec4T< ValueT > const & lhs
		, Mat4x4T< ValueT > const & rhs );
	template< typename ValueT >
	Vec4T< ValueT > operator*( Mat4x4T< ValueT > const & lhs
		, Vec4T< ValueT > const & rhs );
	template< typename ValueT >
	Mat4x4T< ValueT > operator*( Mat4x4T< ValueT > const & lhs
		, Mat4x4T< ValueT > const & rhs );

	template< typename ValueT >
	Mat4x4T< ValueT > operator*( ValueT const & lhs
		, Mat4x4T< ValueT > const & rhs );
	template< typename ValueT >
	Mat4x4T< ValueT > operator*( Mat4x4T< ValueT > const & lhs
		, ValueT const & rhs );
}

#include "Mat4.inl"

#endif
