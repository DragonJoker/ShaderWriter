/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtLoop_H___
#define ___AST_StmtLoop_H___
#pragma once

#include "StmtCompound.hpp"

namespace ast::stmt
{
	class Loop
		: public Compound
	{
	public:
		SDAST_API explicit Loop( StmtCache & stmtCache
			, size_t size
			, Kind kind );
	};
}

#endif
