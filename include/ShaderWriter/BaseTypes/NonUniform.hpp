/*
See LICENSE file in root folder
*/
#ifndef ___SDW_NonUniform_H___
#define ___SDW_NonUniform_H___
#pragma once

#include "ShaderWriter/BaseTypes/Bool.hpp"

namespace sdw
{
	template< typename ValueT >
	struct NonUniformT
		: public ValueT
	{
		NonUniformT( NonUniformT const & rhs ) = delete;
		NonUniformT & operator=( NonUniformT const & rhs ) = delete;
		NonUniformT & operator=( NonUniformT && rhs ) = delete;

		NonUniformT( ShaderWriter & writer
			, expr::ExprPtr expr
			, bool enabled );
		NonUniformT( ValueT const & rhs );
		NonUniformT( NonUniformT && rhs );

		static ast::type::TypePtr makeType( ast::type::TypesCache & cache );
	};

	template< typename ValueT >
	struct IsNonUniformT
		: std::false_type
	{
	};

	template< typename ValueT >
	struct IsNonUniformT< NonUniformT< ValueT > >
		: std::true_type
	{
	};

	template< typename ValueT >
	static bool constexpr isNonUniformV = IsNonUniformT< ValueT >::value;
}

#include "NonUniform.inl"

#endif
