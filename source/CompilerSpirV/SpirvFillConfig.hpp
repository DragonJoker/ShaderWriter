/*
See LICENSE file in root folder
*/
#ifndef ___SDW_HlslStmtConfigFiller_H___
#define ___SDW_HlslStmtConfigFiller_H___
#pragma once

#include "SpirvHelpers.hpp"

namespace spirv
{
	void fillConfig( ast::stmt::Container * cont
		, ModuleConfig & moduleConfig );
}

#endif
