/*
See LICENSE file in root folder
*/
#ifndef ___SDW_Float_H___
#define ___SDW_Float_H___
#pragma once

#include "ShaderWriter/BaseTypes/ArithmeticValue.hpp"

inline sdw::Float operator "" _f( long double value )
{
	return sdw::Float{ float( value ) };
}

#endif
