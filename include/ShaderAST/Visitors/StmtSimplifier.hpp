/*
See LICENSE file in root folder
*/
#ifndef ___SDW_StmtSimplifier_H___
#define ___SDW_StmtSimplifier_H___
#pragma once

#include "ShaderAST/Visitors/CloneStmt.hpp"

namespace ast
{
	SDAST_API stmt::ContainerPtr simplify( type::TypesCache & cache
		, stmt::Container * stmt );
}

#endif
