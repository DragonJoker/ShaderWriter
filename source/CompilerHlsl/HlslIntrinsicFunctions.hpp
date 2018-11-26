/*
See LICENSE file in root folder
*/
#ifndef ___AST_HlslIntrinsicFunctions_H___
#define ___AST_HlslIntrinsicFunctions_H___
#pragma once

#include "HlslHelpers.hpp"

namespace hlsl
{
	void compileHlslIntrinsicFunctions( ast::stmt::Container * container
		, IntrinsicsConfig const & config );
}

#endif
