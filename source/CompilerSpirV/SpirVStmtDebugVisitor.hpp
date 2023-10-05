/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SpirVStmtDebugVisitor_H___
#define ___SDW_SpirVStmtDebugVisitor_H___
#pragma once

#include "CompilerSpirV/compileSpirV.hpp"

#include <map>

namespace spirv
{
	struct DebugStatement
	{
		std::string text{};
		uint32_t lineBegin{};
		uint32_t lineEnd{};
		ast::stmt::Stmt const * stmt{};
	};
	using DebugStatements = Vector< DebugStatement >;

	DebugStatements addDebugData( ast::ShaderStage shaderStage
		, ast::stmt::Container * stmt );
}

#endif
