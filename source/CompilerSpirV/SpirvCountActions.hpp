/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SpirvCountActions_H___
#define ___SDW_SpirvCountActions_H___
#pragma once

#include <ShaderAST/Stmt/StmtContainer.hpp>
#include <ShaderAST/Type/TypeCache.hpp>

#include <cstdint>
#include <vector>
#include <map>

namespace spirv
{
	struct VarActions
	{
		uint32_t uses{};
		uint32_t usesThroughMember{};
		uint32_t sets{};
		ast::type::TypePtr realType;
	};

	struct EntityNameLess
	{
		bool operator()( ast::EntityName const & lhs, ast::EntityName const & rhs )const
		{
			return lhs.id < rhs.id;
		}
	};

	using FunctionActions = std::map< ast::EntityName, VarActions, EntityNameLess >;
	using ShaderActions = std::map< std::string, FunctionActions >;

	ShaderActions listActions( ast::stmt::Container * container );
}

#endif
