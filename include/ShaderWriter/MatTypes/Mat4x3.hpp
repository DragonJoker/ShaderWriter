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
		SDW_DeclValue( , Mat4x3T );

		using ValueType = ValueT;
		using my_vec = Vec3T< ValueT >;
		using my_mat = Mat4x3T< ValueT >;

		Mat4x3T( ShaderWriter & writer
			, expr::ExprPtr expr
			, bool enabled );

		template< typename RhsT >
		Mat4x3T< ValueT > & operator=( RhsT const & rhs );
		template< typename IndexT >
		Vec3T< ValueT > operator[]( IndexT const & rhs )const;
		Vec3T< ValueT > operator[]( int32_t offset )const;
		Vec3T< ValueT > operator[]( uint32_t offset )const;

		static ast::type::TypePtr makeType( ast::type::TypesCache & cache );
	};
	template< typename ValueT >
	Vec3T< ValueT > operator*( Mat4x3T< ValueT > const & lhs
		, Vec4T< ValueT > const & rhs );
	template< typename ValueT >
	Vec4T< ValueT > operator*( Vec3T< ValueT > const & lhs
		, Mat4x3T< ValueT > const & rhs );
}

#include "Mat4x3.inl"

#endif
