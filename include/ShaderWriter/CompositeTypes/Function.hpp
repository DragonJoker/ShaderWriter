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
	inline ReturnWrapperT< ReturnT > getCtorCall( ShaderWriter & writer
		, ParamsT && ... params );

	template< typename ReturnT, typename ... ParamsT >
	inline ReturnWrapperT< ReturnT > getFunctionCall( ShaderWriter & writer
		, ast::var::VariablePtr funcVar
		, ParamsT const & ... params );

	template< typename ReturnT, typename ... ParamsT >
	inline stmt::FunctionDeclPtr getFunctionHeader( ShaderWriter & writer
		, ast::var::VariableList & args
		, std::string name
		, stmt::FunctionFlag flag
		, ParamsT && ... params );

	//***********************************************************************************************

	template< typename ReturnT, typename ... ParamsT >
	struct Function
	{
	public:
		Function() = default;
		Function( ShaderWriter & writer
			, ast::var::VariablePtr funcVar );
		ReturnWrapperT< ReturnT > operator()( ParamsT && ... params )const;
		explicit operator bool()const;

	private:
		mutable ShaderWriter * m_writer{ nullptr };
		mutable ShaderBuilder * m_builder{ nullptr };
		ast::var::VariablePtr m_funcVar;
		ast::type::FunctionPtr m_type;
	};

	//***********************************************************************************************
}

#include "Function.inl"

#endif
