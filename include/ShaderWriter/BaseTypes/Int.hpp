/*
See LICENSE file in root folder
*/
#ifndef ___SDW_Int_H___
#define ___SDW_Int_H___
#pragma once

#include "ShaderWriter/BaseTypes/IntegerValue.hpp"

inline sdw::Int operator "" _i( unsigned long long value )
{
	return sdw::Int{ int( value ) };
}

#endif
