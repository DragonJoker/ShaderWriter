/*
See LICENSE file in root folder
*/
#ifndef ___SDW_Optional_H___
#define ___SDW_Optional_H___
#pragma once

#include "Value.hpp"

namespace sdw
{
	template< typename TypeT >
	struct Optional
		: public TypeT
	{
		inline Optional( Shader * shader
			, expr::ExprPtr expr
			, bool enabled );
		inline Optional( TypeT const & other
			, bool enabled );
		inline Optional( Optional const & rhs );

		inline Optional< TypeT > operator=( Optional< TypeT > const & rhs );
		template< typename T >
		inline Optional< TypeT > operator=( T const & rhs );
		inline bool isEnabled()const;

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
	static bool constexpr isOptional = IsOptional< T >::value;

	template< typename T >
	struct RealTypeOf
	{
		using Type = T;
	};

	template< typename T >
	struct RealTypeOf< Optional< T > >
	{
		using Type = T;
	};

	template< typename T >
	using RealTypeT = typename RealTypeOf< T >::Type;

	template< typename T >
	expr::ExprPtr makeExpr( Optional< T > const & value
		, bool force = false );

	template< typename T >
	bool isOptionalEnabled( T const & value );

	template< typename ... ParamsT >
	bool areOptionalEnabled( ParamsT const & ... values );
}

#include "Optional.inl"

#endif
