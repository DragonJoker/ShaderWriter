/*
See LICENSE file in root folder
*/
#ifndef ___Writer_Optional_H___
#define ___Writer_Optional_H___
#pragma once

#include "Value.hpp"

namespace sdw
{
	template< typename TypeT >
	struct Optional
		: public TypeT
	{
		Optional( Shader * shader
			, expr::ExprPtr expr
			, bool enabled );
		Optional( TypeT const & other
			, bool enabled );

		inline Optional< TypeT > operator=( Optional< TypeT > const & rhs );
		template< typename T >
		inline Optional< TypeT > operator=( T const & rhs );
		inline bool isEnabled()const;

		inline operator Optional< Value >()const;

	private:
		bool m_enabled;
	};

	template< typename T >
	struct IsOptional
		: public std::false_type
	{
	};

	template< typename T >
	struct IsOptional< Optional< T > >
		: public std::true_type
	{
	};

	template< typename T >
	expr::ExprPtr makeExpr( Optional< T > const & value );

	template< typename T >
	bool isOptionalEnabled( T const & value );

	template< typename ... ParamsT >
	bool areOptionalEnabled( ParamsT const & ... values );
}

#include "Optional.inl"

#endif
