/*
See LICENSE file in root folder
*/
#ifndef ___AST_HlslIntrinsicFunctions_H___
#define ___AST_HlslIntrinsicFunctions_H___
#pragma once

#include "HlslHelpers.hpp"

namespace sdw::hlsl
{
	void writeHlslIntrinsicFunctions( ast::stmt::Container * container
		, IntrinsicsConfig const & config );
}

#endif
