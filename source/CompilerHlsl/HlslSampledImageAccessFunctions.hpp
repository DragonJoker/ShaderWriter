/*
See LICENSE file in root folder
*/
#ifndef ___AST_HlslSampledImageAccessAccessFunctions_H___
#define ___AST_HlslSampledImageAccessAccessFunctions_H___
#pragma once

#include "HlslHelpers.hpp"

namespace hlsl
{
	void compileHlslSampledImageAccessAccessFunctions( ast::stmt::Container * container
		, IntrinsicsConfig const & config );
}

#endif
