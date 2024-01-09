/*
See LICENSE file in root folder
*/
#ifndef ___SDW_HlslFillConfig_H___
#define ___SDW_HlslFillConfig_H___
#pragma once

#include "HlslHelpers.hpp"
#include "HlslShader.hpp"

namespace hlsl
{
	IntrinsicsConfig fillConfig( HlslShader & shader
		, AdaptationData & adaptationData
		, ast::stmt::Container const & container );
}

#endif
