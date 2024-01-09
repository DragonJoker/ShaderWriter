/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SelectEntryPoint_H___
#define ___SDW_SelectEntryPoint_H___
#pragma once

#include "ShaderAST/ShaderStlTypes.hpp"
#include "ShaderAST/Stmt/StmtFunctionDecl.hpp"

namespace ast
{
	struct EntryPointConfig
	{
		explicit EntryPointConfig( ShaderStage pstage
			, std::string pname = {} )
			: stage{ pstage }
			, name{ std::move( pname ) }
		{
		}

		ShaderStage stage;
		std::string name;
	};
	using EntryPointConfigArray = Vector< EntryPointConfig >;

	SDAST_API stmt::ContainerPtr selectEntryPoint( stmt::StmtCache & stmtCache
		, expr::ExprCache & exprCache
		, EntryPointConfig const & config
		, stmt::Container const & stmt );
	SDAST_API EntryPointConfigArray listEntryPoints( stmt::Container const & stmt );
}

#endif
