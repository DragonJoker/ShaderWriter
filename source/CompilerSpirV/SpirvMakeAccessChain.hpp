/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SpirvMakeAccessChain_H___
#define ___SDW_SpirvMakeAccessChain_H___
#pragma once

#include "CompilerSpirV/SpirvModule.hpp"

#include <ShaderAST/Expr/SwizzleKind.hpp>

namespace ast::expr
{
	class Swizzle;
}

namespace spirv
{
	struct PreprocContext;

	bool isAccessChain( ast::expr::Expr * expr );
	ValueId makeAccessChain( ast::expr::Expr * expr
		, PreprocContext const & context
		, Module & module
		, Block & currentBlock );
	ValueId makeVectorShuffle( ast::expr::Swizzle * expr
		, PreprocContext const & context
		, Module & module
		, Block & currentBlock );
}

#endif
