/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SpirvMakeAccessChain_H___
#define ___SDW_SpirvMakeAccessChain_H___
#pragma once

#include "CompilerSpirV/SpirVModule.hpp"

#include <ShaderAST/Expr/SwizzleKind.hpp>

namespace ast::expr
{
	class Swizzle;
}

namespace spirv
{
	struct PreprocContext;

	bool isAccessChain( ast::expr::Expr * expr );
	DebugId makeAccessChain( ast::expr::ExprCache & exprCache
		, ast::expr::Expr * expr
		, PreprocContext const & context
		, Module & shaderModule
		, Block & currentBlock
		, glsl::Statement * debugStatement );
	DebugId makeVectorShuffle( ast::expr::ExprCache & exprCache
		, ast::expr::Swizzle * expr
		, PreprocContext const & context
		, Module & shaderModule
		, Block & currentBlock
		, glsl::Statement * debugStatement );
}

#endif
