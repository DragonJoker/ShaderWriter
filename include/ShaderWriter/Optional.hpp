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
		Optional( stmt::Container * container
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

	template< typename ... ParamsT >
	struct Or;

	template< typename ParamT >
	struct Or< ParamT >
	{
		static bool constexpr value = ParamT::value;
	};

	template< typename ParamT, typename ... ParamsT >
	struct Or< ParamT, ParamsT... >
	{
		static bool constexpr value = ParamT::value || Or< ParamsT... >::value;
	};

	template< typename ... ParamsT >
	struct HasOptional
		: public Or< IsOptional< ParamsT >... >
	{
	};
	template< typename ... ParamsT >
	bool constexpr HasOptionalT = HasOptional< ParamsT... >::value;

	template< typename ReturnT
		, bool IsOptional >
		struct GetOptionalRet;

	template< typename ReturnT >
		struct GetOptionalRet< ReturnT, false >
	{
		using type = ReturnT;
	};

	template< typename ReturnT >
		struct GetOptionalRet< ReturnT, true >
	{
		using type = Optional< ReturnT >;
	};

	template< typename ReturnT
		, typename ... ParamsT >
	using GetOptionalRetT = typename GetOptionalRet< ReturnT
		, HasOptionalT< ParamsT... >  >::type;

	template< typename T >
	expr::ExprPtr makeExpr( Optional< T > const & value );

	template< typename T >
	bool isOptionalEnabled( T const & value );
}

#include "Optional.inl"

#endif
