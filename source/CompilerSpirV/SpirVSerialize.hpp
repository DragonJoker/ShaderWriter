/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SpirvSerialize_H___
#define ___SDW_SpirvSerialize_H___
#pragma once

#include "SpirVModule.hpp"

#include <cstdint>
#include <vector>

namespace spirv
{
	UInt32List serialize( spirv::Module const & shaderModule );
}

#endif
