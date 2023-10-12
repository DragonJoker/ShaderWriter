/*
See LICENSE file in root folder
*/
#ifndef ___SDW_GlslImageAccessConfig_H___
#define ___SDW_GlslImageAccessConfig_H___
#pragma once

#include "SpirVHelpers.hpp"

#include <ShaderAST/Expr/EnumStorageImageAccess.hpp>

namespace spirv
{
	inline void getSpirVConfig( ast::expr::StorageImageAccess value
		, IntrinsicConfig & config )
	{
		config.needsTexelPointer = ( value >= ast::expr::StorageImageAccess::eImageAtomicAdd1DU
			&& value <= ast::expr::StorageImageAccess::eImageAtomicCompSwap2DMSArrayI );
	}
}

#endif
