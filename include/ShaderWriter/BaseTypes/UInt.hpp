/*
See LICENSE file in root folder
*/
#ifndef ___SDW_UInt_H___
#define ___SDW_UInt_H___
#pragma once

#include "ShaderWriter/BaseTypes/IntegerValue.hpp"

inline sdw::UInt32 operator "" _u( unsigned long long value )
{
	return sdw::UInt32{ uint32_t( value ) };
}

inline sdw::UInt64 operator "" _ull( unsigned long long value )
{
	return sdw::UInt64{ uint64_t( value ) };
}

#endif
