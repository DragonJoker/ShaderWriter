/*
See LICENSE file in root folder
*/
#ifndef ___SDW_Function_H___
#define ___SDW_Function_H___
#pragma once

#include "ShaderWriter/Optional/OptionalArray.hpp"
#include "FunctionParam.hpp"

#include <functional>

namespace sdw
{
	//***********************************************************************************************

	template< typename T >
	struct ParamTranslater
	{
		using Type = T;
	};

	template< typename T >
	struct ParamTranslater< InParam< T > >
	{
		using Type = T const &;
	};

	template< typename T >
	struct ParamTranslater< OutParam< T > >
	{
		using Type = T;
	};

	template< typename T >
	struct ParamTranslater< InOutParam< T > >
	{
		using Type = T;
	};

	template< typename T >
	using ParamTranslaterT = typename ParamTranslater< T >::Type;

	//***********************************************************************************************

	template< typename ReturnT
		, typename ... ParamsT >
	ReturnT getCtorCall( ParamsT const & ... params );

	template< typename ReturnT
		, typename ... ParamsT >
	Optional< ReturnT > getOptCtorCall( ParamsT const & ... params );

	template< typename ReturnT
		, typename ... ParamsT >
	ReturnT getFunctionCall( std::string const & name
		, ParamsT const & ... params );

	template< typename ReturnT
		, typename ... ParamsT >
	Optional< ReturnT > getOptFunctionCall( std::string const & name
		, ParamsT const & ... params );

	template< typename ReturnT
		, typename ... ParamsT >
	inline stmt::FunctionDeclPtr getFunctionHeader( std::string const & name
		, ParamsT && ... params );

	//***********************************************************************************************

	template< typename ReturnT
		, typename ... ParamsT >
	struct Function
	{
	public:
		Function() = default;
		Function( Shader * shader
			, std::string const & name );
		ReturnT operator()( ParamsT && ... params )const;

	private:
		Shader * m_shader{ nullptr };
		std::string m_name;
	};

	//***********************************************************************************************
}

#include "Function.inl"

#endif
