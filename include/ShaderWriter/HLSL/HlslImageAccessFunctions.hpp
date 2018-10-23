/*
See LICENSE file in root folder
*/
#ifndef ___AST_HlslImageAccessFunctions_H___
#define ___AST_HlslImageAccessFunctions_H___
#pragma once

#include "HlslHelpers.hpp"

namespace sdw::hlsl
{
	void writeHlslImageAccessFunctions( ast::stmt::Container * container
		, IntrinsicsConfig const & config );
}

#endif
