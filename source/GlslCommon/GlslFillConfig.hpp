/*
See LICENSE file in root folder
*/
#ifndef ___SDW_GlslFillConfig_H___
#define ___SDW_GlslFillConfig_H___
#pragma once

#include "GlslCommon/GlslStatementsHelpers.hpp"

namespace glsl
{
	SDWGLC_API IntrinsicsConfig fillConfig( ast::ShaderStage stage
		, ast::stmt::Container const & container );
	SDWGLC_API void checkConfig( StmtConfig & writerConfig
		, IntrinsicsConfig & intrinsicsConfig );
}

#endif
