/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SpirvGetSwizzleComponents_H___
#define ___SDW_SpirvGetSwizzleComponents_H___
#pragma once

#include "SpirVHelpers.hpp"

#include <ShaderAST/Expr/SwizzleKind.hpp>

#include <vector>

namespace spirv
{
	UInt32List getSwizzleComponents( ast::ShaderAllocatorBlock * allocator
		, ast::expr::SwizzleKind kind );
	IdList getSwizzleComponents( ast::ShaderAllocatorBlock * allocator
		, ast::expr::SwizzleKind lhsSwizzle
		, ast::expr::SwizzleKind rhsSwizzle
		, uint32_t componentCount );
	ast::expr::SwizzleKind getSwizzleComponents( uint32_t count );
}

#endif
