/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SpirvGetSwizzleComponents_H___
#define ___SDW_SpirvGetSwizzleComponents_H___
#pragma once

#include "SpirvHelpers.hpp"

#include <ShaderAST/Expr/SwizzleKind.hpp>

#include <vector>

namespace spirv
{
	std::vector< uint32_t > getSwizzleComponents( ast::expr::SwizzleKind kind );
	IdList getSwizzleComponents( ast::expr::SwizzleKind lhsSwizzle
		, ast::expr::SwizzleKind rhsSwizzle
		, uint32_t componentCount );
	ast::expr::SwizzleKind getSwizzleComponents( uint32_t count );
}

#endif
