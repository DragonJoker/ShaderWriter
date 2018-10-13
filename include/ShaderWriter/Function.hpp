/*
See LICENSE file in root folder
*/
#ifndef ___Writer_Function_H___
#define ___Writer_Function_H___
#pragma once

#include "Array.hpp"
#include "Optional.hpp"

#include <ASTGenerator/Stmt/StmtFunctionDecl.hpp>

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

	//***********************************************************************************************

	template< typename ReturnT
		, typename ... ParamsT >
	ReturnT getFunctionCall( std::string const & name
		, ParamsT const & ... params );

	template< typename ReturnT
		, typename ... ParamsT >
	Optional< ReturnT > getOptFunctionCall( std::string const & name
		, ParamsT const & ... params );

	template< typename Return
		, typename ... Params >
	inline stmt::FunctionDeclPtr getFunctionHeader( std::string const & name
		, Params && ... params );

	//***********************************************************************************************

	template< typename RetT, typename ... ParamsT >
	struct Function
	{
	public:
		Function() = default;
		Function( stmt::Container * container
			, std::string const & name );
		expr::ExprPtr operator()( ParamsT && ... params )const;

	private:
		stmt::Container * m_container{ nullptr };
		std::string m_name;
	};

	//***********************************************************************************************
}

#include "Function.inl"

#endif
