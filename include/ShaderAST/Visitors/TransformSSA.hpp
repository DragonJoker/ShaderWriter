/*
See LICENSE file in root folder
*/
#ifndef ___SDW_TransformSSA_H___
#define ___SDW_TransformSSA_H___
#pragma once

#include "ShaderAST/Stmt/StmtContainer.hpp"

namespace ast
{
	struct SSAData
	{
		uint32_t nextVarId{};
		uint32_t aliasId{};
	};

	SDAST_API stmt::ContainerPtr transformSSA( stmt::StmtCache & stmtCache
		, expr::ExprCache & exprCache
		, type::TypesCache & typesCache
		, stmt::Container const & container
		, SSAData & ssaData
		, bool normaliseStructs );
}

#endif
