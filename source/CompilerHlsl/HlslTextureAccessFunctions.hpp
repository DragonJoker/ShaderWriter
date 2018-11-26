/*
See LICENSE file in root folder
*/
#ifndef ___AST_HlslTextureAccessFunctions_H___
#define ___AST_HlslTextureAccessFunctions_H___
#pragma once

#include "HlslHelpers.hpp"

namespace hlsl
{
	void compileHlslTextureAccessFunctions( ast::stmt::Container * container
		, IntrinsicsConfig const & config );
}

#endif
