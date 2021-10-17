/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SpirvSerialize_H___
#define ___SDW_SpirvSerialize_H___
#pragma once

#include "SpirvModule.hpp"

#include <cstdint>
#include <vector>

namespace spirv
{
	std::vector< uint32_t > serialize( spirv::Module const & module );
}

#endif
