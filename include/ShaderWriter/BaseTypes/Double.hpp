/*
See LICENSE file in root folder
*/
#ifndef ___SDW_Double_H___
#define ___SDW_Double_H___
#pragma once

#include "ShaderWriter/BaseTypes/ArithmeticValue.hpp"

inline sdw::Double operator "" _d( long double value )
{
	return sdw::Double{ double( value ) };
}

#endif
