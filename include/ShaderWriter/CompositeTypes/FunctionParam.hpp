/*
See LICENSE file in root folder
*/
#ifndef ___SDW_FunctionParam_H___
#define ___SDW_FunctionParam_H___
#pragma once

#include "ShaderWriter/Value.hpp"

namespace sdw
{
	template< typename ValueT >
	struct InParam
		: public ValueT
	{
		InParam( ShaderWriter & writer
			, std::string name );
		InParam( ValueT const & other );
		template< typename T >
		inline InParam< ValueT > operator=( T const & rhs );
	};

	template< typename ValueT >
	InParam< ValueT > makeInParam( ValueT const & other )
	{
		return InParam< ValueT >( other );
	}

	template< typename ValueT >
	struct OutParam
		: public ValueT
	{
		OutParam( ShaderWriter & writer
			, std::string name );
		OutParam( ValueT const & other );
		template< typename T >
		inline OutParam< ValueT > operator=( T const & rhs );
	};

	template< typename ValueT >
	OutParam< ValueT > makeOutParam( ValueT const & other )
	{
		return OutParam< ValueT >( other );
	}

	template< typename ValueT >
	struct InOutParam
		: public ValueT
	{
		InOutParam( ShaderWriter & writer
			, std::string name );
		InOutParam( ValueT const & other );
		template< typename T >
		inline InOutParam< ValueT > operator=( T const & rhs );
	};

	template< typename ValueT >
	InOutParam< ValueT > makeInOutParam( ValueT const & other )
	{
		return InOutParam< ValueT >( other );
	}
}

#include "FunctionParam.inl"

#endif
