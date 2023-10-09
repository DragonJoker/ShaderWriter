/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SpirvStmtAdapter_H___
#define ___SDW_SpirvStmtAdapter_H___
#pragma once

#include "SpirvHelpers.hpp"

namespace spirv
{
	struct AdaptationData
	{
		AdaptationData( PreprocContext & pcontext
			, ModuleConfig pconfig )
			: context{ pcontext }
			, config{ std::move( pconfig ) }
		{
		}

		PreprocContext & context;
		ModuleConfig config;
	};

	ast::stmt::ContainerPtr adaptStatements( ast::stmt::StmtCache & stmtCache
		, ast::expr::ExprCache & exprCache
		, ast::type::TypesCache & typesCache
		, ast::stmt::Container * container
		, AdaptationData & adaptationData );
}

#endif
