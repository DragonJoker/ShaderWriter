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
	struct Param
		: public ValueT
	{
		Param( ShaderWriter & writer
			, std::string name );
		Param( ValueT const & other );
		template< typename T >
		inline Param< ValueT > operator=( T const & rhs );
	};

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
	struct Param< Array< ValueT > >
		: public Array< ValueT >
	{
		Param( ShaderWriter & writer
			, std::string name
			, uint32_t arraySize );
		Param( Array< ValueT > const & other );
		template< typename T >
		inline Param< Array< ValueT > > operator=( T const & rhs );
	};

	template< typename ValueT >
	struct InParam< Array< ValueT > >
		: public Array< ValueT >
	{
		InParam( ShaderWriter & writer
			, std::string name
			, uint32_t arraySize );
		InParam( Array< ValueT > const & other );
		template< typename T >
		inline InParam< Array< ValueT > > operator=( T const & rhs );
	};

	template< typename ValueT >
	struct OutParam< Array< ValueT > >
		: public Array< ValueT >
	{
		OutParam( ShaderWriter & writer
			, std::string name
			, uint32_t arraySize );
		OutParam( Array< ValueT > const & other );
		template< typename T >
		inline OutParam< Array< ValueT > > operator=( T const & rhs );
	};

	template< typename ValueT >
	struct InOutParam< Array< ValueT > >
		: public Array< ValueT >
	{
		InOutParam( ShaderWriter & writer
			, std::string name
			, uint32_t arraySize );
		InOutParam( Array< ValueT > const & other );
		template< typename T >
		inline InOutParam< Array< ValueT > > operator=( T const & rhs );
	};

	template< typename ValueT >
	Param< ValueT > makeParam( ValueT const & other )
	{
		return Param< ValueT >( other );
	}

	template< typename ValueT >
	InParam< ValueT > makeInParam( ValueT const & other )
	{
		return InParam< ValueT >( other );
	}

	template< typename ValueT >
	OutParam< ValueT > makeOutParam( ValueT const & other )
	{
		return OutParam< ValueT >( other );
	}

	template< typename ValueT >
	InOutParam< ValueT > makeInOutParam( ValueT const & other )
	{
		return InOutParam< ValueT >( other );
	}
}

#include "FunctionParam.inl"

#endif
