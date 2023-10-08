/*
See LICENSE file in root folder
*/
#ifndef ___SDW_GlslFillConfig_H___
#define ___SDW_GlslFillConfig_H___
#pragma once

#include "GlslHelpers.hpp"

namespace glsl
{
	IntrinsicsConfig fillConfig( ast::ShaderStage stage
		, ast::stmt::Container * container );
}

#endif
