/*
See LICENSE file in root folder
*/
#ifndef ___Writer_FunctionParam_H___
#define ___Writer_FunctionParam_H___
#pragma once

#include "Value.hpp"

#include <ASTGenerator/Stmt/StmtVariableDecl.hpp>

namespace sdw
{
	template< typename TypeT >
	struct InParam
		: public TypeT
	{
		InParam( Shader * shader
			, expr::ExprPtr expr );
		InParam( TypeT const & other );
		template< typename T >
		inline InParam< TypeT > operator=( T const & rhs );
	};

	template< typename TypeT >
	struct OutParam
		: public TypeT
	{
		OutParam( Shader * shader
			, expr::ExprPtr expr );
		OutParam( TypeT const & other );
		template< typename T >
		inline OutParam< TypeT > operator=( T const & rhs );
	};

	template< typename TypeT >
	struct InOutParam
		: public TypeT
	{
		InOutParam( Shader * shader
			, expr::ExprPtr expr );
		InOutParam( TypeT const & other );
		template< typename T >
		inline InOutParam< TypeT > operator=( T const & rhs );
	};

	template< typename TypeT >
	stmt::VariableDeclPtr makeVarDecl( InParam< TypeT > const & value );
	template< typename TypeT >
	stmt::VariableDeclPtr makeVarDecl( OutParam< TypeT > const & value );
	template< typename TypeT >
	stmt::VariableDeclPtr makeVarDecl( InOutParam< TypeT > const & value );
}

#include "FunctionParam.inl"

#endif
