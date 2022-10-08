/*
See LICENSE file in root folder
*/
#ifndef ___SDW_Int_H___
#define ___SDW_Int_H___
#pragma once

#include "ShaderWriter/BaseTypes/IntegerValue.hpp"

inline sdw::Int8 operator "" _i8( unsigned long long value )
{
	return sdw::Int8{ int8_t( value ) };
}

inline sdw::Int16 operator "" _i16( unsigned long long value )
{
	return sdw::Int16{ int16_t( value ) };
}

inline sdw::Int32 operator "" _i32( unsigned long long value )
{
	return sdw::Int32{ int32_t( value ) };
}

inline sdw::Int64 operator "" _i64( unsigned long long value )
{
	return sdw::Int64{ int64_t( value ) };
}

inline sdw::Int32 operator "" _i( unsigned long long value )
{
	return sdw::Int32{ int32_t( value ) };
}

inline sdw::Int64 operator "" _ill( unsigned long long value )
{
	return sdw::Int64{ int64_t( value ) };
}

#endif
