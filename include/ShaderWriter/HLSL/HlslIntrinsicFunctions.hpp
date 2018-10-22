/*
See LICENSE file in root folder
*/
#ifndef ___AST_HlslIntrinsicFunctions_H___
#define ___AST_HlslIntrinsicFunctions_H___
#pragma once

#include "HlslHelpers.hpp"

namespace sdw::hlsl
{
	void writeHlslFunctions( ast::stmt::Container * container
		, Config const & config );
}

#endif
