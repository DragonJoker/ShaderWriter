/*
See LICENSE file in root folder
*/
#ifndef ___SDW_Int_H___
#define ___SDW_Int_H___
#pragma once

#include "ShaderWriter/BaseTypes/IntegerValue.hpp"

inline sdw::Int32 operator "" _i( unsigned long long value )
{
	return sdw::Int32{ int( value ) };
}

inline sdw::Int64 operator "" _ill( unsigned long long value )
{
	return sdw::Int64{ int64_t( value ) };
}

#endif
