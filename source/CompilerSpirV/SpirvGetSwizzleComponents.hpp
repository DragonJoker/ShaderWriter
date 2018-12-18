/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SpirvGetSwizzleComponents_H___
#define ___SDW_SpirvGetSwizzleComponents_H___
#pragma once

#include "SpirvHelpers.hpp"

#include <vector>

namespace spirv
{
	std::vector< uint32_t > getSwizzleComponents( ast::expr::SwizzleKind kind );
	IdList getSwizzleComponents( uint32_t totalComponents
		, ast::expr::SwizzleKind swizzle );
}

#endif
