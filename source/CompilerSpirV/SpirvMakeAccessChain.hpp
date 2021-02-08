/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SpirvMakeAccessChain_H___
#define ___SDW_SpirvMakeAccessChain_H___
#pragma once

#include "CompilerSpirV/SpirvModule.hpp"

#include <ShaderAST/Expr/SwizzleKind.hpp>

namespace spirv
{
	spv::Id writeShuffle( Module & module
		, Block & currentBlock
		, spv::Id typeId
		, spv::Id outerId
		, ast::expr::SwizzleKind swizzle );
	bool isAccessChain( ast::expr::Expr * expr );
	bool isPtrAccessChain( ast::expr::Expr * expr );
	spv::Id makeAccessChain( ast::expr::Expr * expr
		, Module & module
		, Block & currentBlock
		, LoadedVariableArray & loadedVariables );
}

#endif
