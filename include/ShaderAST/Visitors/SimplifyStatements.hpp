/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SimplifyStatements_H___
#define ___SDW_SimplifyStatements_H___
#pragma once

#include "ShaderAST/Visitors/CloneStmt.hpp"

namespace ast
{
	SDAST_API stmt::ContainerPtr simplify( stmt::StmtCache & stmtCache
		, expr::ExprCache & exprCache
		, type::TypesCache & typesCache
		, stmt::Container * stmt );
}

#endif
