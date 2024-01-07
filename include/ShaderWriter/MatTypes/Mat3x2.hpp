/*
See LICENSE file in root folder
*/
#ifndef ___SDW_Mat3x2_H___
#define ___SDW_Mat3x2_H___
#pragma once

#include "ShaderWriter/VecTypes/Vec2.hpp"

namespace sdw
{
	template< typename ValueT >
	struct Mat3x2T
		: public Value
	{
		SDW_DeclValue( , Mat3x2T );

		using ValueType = ValueT;
		using my_vec = Vec2T< ValueT >;
		using my_mat = Mat3x2T< ValueT >;

		Mat3x2T( ShaderWriter & writer
			, expr::ExprPtr expr
			, bool enabled );

		template< typename RhsT >
		Mat3x2T< ValueT > & operator=( RhsT const & rhs );
		template< typename IndexT >
		Vec2T< ValueT > operator[]( IndexT const & rhs )const;
		Vec2T< ValueT > operator[]( int32_t offset )const;
		Vec2T< ValueT > operator[]( uint32_t offset )const;

		static ast::type::TypePtr makeType( ast::type::TypesCache & cache );
	};
}

#include "Mat3x2.inl"

#endif
