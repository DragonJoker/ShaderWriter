/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SpirVStmtDebugVisitor_H___
#define ___SDW_SpirVStmtDebugVisitor_H___
#pragma once

#include "CompilerSpirV/compileSpirV.hpp"
#include "CompilerSpirV/SpirVDebugHelpers.hpp"

namespace spirv
{
	debug::DebugStatements addDebugData( ast::ShaderStage shaderStage
		, ast::stmt::Container * stmt );
}

#endif
