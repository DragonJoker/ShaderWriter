/*
See LICENSE file in root folder
*/
#ifndef ___SDW_UInt_H___
#define ___SDW_UInt_H___
#pragma once

#include "ShaderWriter/BaseTypes/IntegerValue.hpp"

inline sdw::UInt operator "" _u( unsigned long long value )
{
	return sdw::UInt{ uint32_t( value ) };
}

#endif
