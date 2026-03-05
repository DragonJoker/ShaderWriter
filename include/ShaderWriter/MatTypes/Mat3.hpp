/*
See LICENSE file in root folder
*/
#ifndef ___SDW_Mat3_H___
#define ___SDW_Mat3_H___
#pragma once

#include "ShaderWriter/VecTypes/Vec3.hpp"

namespace sdw
{
	template< typename ValueT >
	struct Mat3x3T
		: public Value
	{
		SDW_DeclValue( , Mat3x3T );

		using ValueType = ValueT;
		using my_vec = Vec3T< ValueT >;
		using my_mat = Mat3x3T< ValueT >;

		Mat3x3T( ShaderWriter & writer
			, expr::ExprPtr expr
			, bool enabled );

		template< typename RhsT >
		ReturnWrapperT< Mat3x3T< ValueT > > operator=( RhsT const & rhs );
		template< typename IndexT >
		ReturnWrapperT< Vec3T< ValueT > > operator[]( IndexT const & rhs )const;
		ReturnWrapperT< Vec3T< ValueT > > operator[]( int32_t offset )const;
		ReturnWrapperT< Vec3T< ValueT > > operator[]( uint32_t offset )const;
		Mat3x3T< ValueT > & operator+=( Mat3x3T< ValueT > const & rhs );

		static ast::type::TypePtr makeType( ast::type::TypesCache & cache );
	};
	template< typename ValueT >
	ReturnWrapperT< Vec3T< ValueT > > operator*( Vec3T< ValueT > const & lhs
		, Mat3x3T< ValueT > const & rhs );
	template< typename ValueT >
	ReturnWrapperT< Vec3T< ValueT > > operator*( Mat3x3T< ValueT > const & lhs
		, Vec3T< ValueT > const & rhs );
	template< typename ValueT >
	ReturnWrapperT< Mat3x3T< ValueT > > operator*( Mat3x3T< ValueT > const & lhs
		, Mat3x3T< ValueT > const & rhs );

	template< typename ValueT >
	ReturnWrapperT< Mat3x3T< ValueT > > operator*( ValueT const & lhs
		, Mat3x3T< ValueT > const & rhs );
	template< typename ValueT >
	ReturnWrapperT< Mat3x3T< ValueT > > operator*( Mat3x3T< ValueT > const & lhs
		, ValueT const & rhs );
}

#include "Mat3.inl"

#endif
