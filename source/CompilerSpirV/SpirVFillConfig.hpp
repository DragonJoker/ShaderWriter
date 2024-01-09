/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SpirVStmtConfigFiller_H___
#define ___SDW_SpirVStmtConfigFiller_H___
#pragma once

#include "SpirVHelpers.hpp"

namespace spirv
{
	void fillConfig( ast::stmt::Container const & cont
		, ModuleConfig & moduleConfig );
}

#endif
