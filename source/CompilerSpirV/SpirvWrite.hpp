/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SpirvWrite_H___
#define ___SDW_SpirvWrite_H___
#pragma once

#include "SpirvModule.hpp"

#include <ostream>

namespace spirv
{
	std::string write( spirv::Module const & module
		, bool doWriteHeader );
}

#endif
