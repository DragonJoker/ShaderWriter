/*
See LICENSE file in root folder
*/
#ifndef ___SDW_StmtSimplifier_H___
#define ___SDW_StmtSimplifier_H___
#pragma once

#include "ShaderAST/Visitors/CloneStmt.hpp"

namespace ast
{
	SDAST_API stmt::ContainerPtr simplify( expr::ExprCache & exprCache
		, type::TypesCache & typesCache
		, stmt::Container * stmt );
}

#endif
