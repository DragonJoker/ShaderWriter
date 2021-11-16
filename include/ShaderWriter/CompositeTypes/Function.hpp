/*
See LICENSE file in root folder
*/
#ifndef ___SDW_Function_H___
#define ___SDW_Function_H___
#pragma once

#include "ShaderWriter/BaseTypes/Array.hpp"
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

	template< typename ReturnT, typename ... ParamsT >
	inline ReturnT getCtorCall( ShaderWriter & writer
		, ParamsT const & ... params );

	template< typename ReturnT, typename ... ParamsT >
	inline ReturnT getFunctionCall( ShaderWriter & writer
		, ast::type::FunctionPtr type
		, std::string const & name
		, ParamsT const & ... params );

	template< typename ReturnT, typename ... ParamsT >
	inline stmt::FunctionDeclPtr getFunctionHeader( ShaderWriter & writer
		, ast::var::VariableList & args
		, std::string const & name
		, stmt::FunctionFlag flag
		, ParamsT && ... params );

	//***********************************************************************************************

	template< typename ReturnT, typename ... ParamsT >
	struct Function
	{
	public:
		inline Function() = default;
		inline Function( ShaderWriter & writer
			, ast::type::FunctionPtr type
			, std::string const & name );
		inline ReturnT operator()( ParamsT && ... params )const;
		inline operator bool()const;

	private:
		mutable ShaderWriter * m_writer{ nullptr };
		mutable Shader * m_shader{ nullptr };
		ast::type::FunctionPtr m_type;
		std::string m_name;
	};

	//***********************************************************************************************
}

#include "Function.inl"

#endif
