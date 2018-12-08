/*
See LICENSE file in root folder
*/
#ifndef ___SDW_GlslImageAccessConfig_H___
#define ___SDW_GlslImageAccessConfig_H___
#pragma once

#include "SpirvHelpers.hpp"

#include <ShaderAST/Expr/EnumImageAccess.hpp>

namespace spirv
{
	inline void getSpirVConfig( ast::expr::ImageAccess value
		, IntrinsicConfig & config )
	{
		config.needsTexelPointer = ( value >= ast::expr::ImageAccess::eImageAtomicAdd1DU
			&& value <= ast::expr::ImageAccess::eImageAtomicCompSwap2DMSArrayI );
	}
}

#endif
