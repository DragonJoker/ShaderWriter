/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SpirvStmtAdapter_H___
#define ___SDW_SpirvStmtAdapter_H___
#pragma once

#include "SpirVHelpers.hpp"

namespace spirv
{
	struct AdaptationData
	{
		AdaptationData( ast::ShaderAllocatorBlock * alloc
			, PreprocContext & pcontext
			, ModuleConfig pconfig )
			: context{ pcontext }
			, config{ std::move( pconfig ) }
			, funcVarReplacements{ alloc }
		{
		}

		uint32_t getNextVarId()
		{
			return config.getNextVarId();
		}

		uint32_t getNextAliasId()
		{
			return config.getNextAliasId();
		}

		PreprocContext & context;
		ModuleConfig config;
		ast::Map< uint32_t, ast::var::VariablePtr > funcVarReplacements;
	};

	ast::stmt::ContainerPtr adaptStatements( ast::stmt::StmtCache & stmtCache
		, ast::expr::ExprCache & exprCache
		, ast::type::TypesCache & typesCache
		, ast::stmt::Container const & container
		, AdaptationData & adaptationData );
}

#endif
